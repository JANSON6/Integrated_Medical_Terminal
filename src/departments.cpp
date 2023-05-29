#include "departments.h"

Departments::Departments()
{
    //һ����������
    std::string n[20];

    //����������������
    std::vector<std::string> d[20];

    std::fstream fs;
    fs.open("./resource/data/department.txt", std::ios_base::in);
    if( !fs.is_open())
    {
        std::cout<<"�����ļ���ʧ��!"<<std::endl;
    }

    char buf[1024];
    int  index = 0; //��������
    int  start = 0; //�����ִ���ʼλ��

    while(!fs.eof())
    {
        memset(buf, 0, 1024);
        start = 0;
        fs.getline(buf, 1024, '\n');
        std::string tmp(buf);

        //i ������������ j ���ִ���ʼ����
        for(size_t i=0; i<tmp.size(); i++)
        {

            //��ȡһ������
            if(tmp.at(i) == '=')
            {
                n[index] = tmp.substr(start, i);
                start = i+1;    //�ִ���ʼλ�øĵ�=�ź���
            }
            //��ȡ��������
            if(tmp.at(i) == '/')
            {
                d[index].push_back(std::string(tmp.substr(start, i-start)));  //������������������������ѿռ��Ÿö���
                start = i+1;
            }

            if(tmp.at(i) == '|')
            {
                d[index].push_back(std::string(tmp.substr(start, i-start)));
                index++;    //����һ�л�һ������
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


