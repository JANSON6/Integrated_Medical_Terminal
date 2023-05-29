#include "departments.h"

Departments::Departments()
{
    //一级科室数组
    std::string n[20];

    //二级科室容器数组
    std::vector<std::string> d[20];

    std::fstream fs;
    fs.open("./resource/data/department.txt", std::ios_base::in);
    if( !fs.is_open())
    {
        std::cout<<"数据文件打开失败!"<<std::endl;
    }

    char buf[1024];
    int  index = 0; //科室索引
    int  start = 0; //单个字串起始位置

    while(!fs.eof())
    {
        memset(buf, 0, 1024);
        start = 0;
        fs.getline(buf, 1024, '\n');
        std::string tmp(buf);

        //i 作遍历索引， j 作字串起始索引
        for(size_t i=0; i<tmp.size(); i++)
        {

            //读取一级科室
            if(tmp.at(i) == '=')
            {
                n[index] = tmp.substr(start, i);
                start = i+1;    //字串起始位置改到=号后面
            }
            //读取二级科室
            if(tmp.at(i) == '/')
            {
                d[index].push_back(std::string(tmp.substr(start, i-start)));  //传递匿名对象，容器主动申请堆空间存放该对象
                start = i+1;
            }

            if(tmp.at(i) == '|')
            {
                d[index].push_back(std::string(tmp.substr(start, i-start)));
                index++;    //读完一行换一个容器
                break;
            }
        }

    }

    while(index >=0)
    {
        this->m_departments[n[index]] = d[index];
        index--;
    }
}

Departments::~Departments()
{

}

void Departments::show()
{
    std::vector<std::string>::iterator vit;
    std::map<std::string, std::vector<std::string>>::iterator mit;

    for(mit = this->m_departments.begin(); mit != this->m_departments.end(); mit++)
    {
        std::cout<<mit->first<<": ";
        for(vit = mit->second.begin(); vit != mit->second.end(); vit++)
        {
            std::cout<<*vit<<"   ";
        }
        std::cout<<std::endl;
    }
}

std::map<std::string, std::vector<std::string> > Departments::departments() const
{
    return m_departments;
}


