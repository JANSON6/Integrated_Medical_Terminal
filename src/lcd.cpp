#include"lcd.h"

Lcd* Lcd::m_instance = NULL;

Lcd::Lcd()
{
    init(LCD_PATH);
}

Lcd::~Lcd()
{
    //关闭设备文件
    ::close(this->fd);
    //解除映射
    int ret = munmap(this->mp, 800*480*4);
    if(ret)
    {
        perror("[error] lcd munmap");
    }
    //释放实例空间
    delete [] this->m_instance;
    this->m_instance = NULL;
}

void Lcd::init(const char* dev_path)
{
    //打开设备文件
    this->fd = open(dev_path, O_RDWR);
    if(this->fd == -1)
    {
        perror("[error] lcd open");
    }

    //创建映射
    this->mp = (int*)mmap(NULL, 800*480*4, PROT_READ|PROT_WRITE, MAP_SHARED, this->fd, 0);
    if(this->mp == MAP_FAILED)
    {
        perror("[error] lcd mmap");
    }


}


Lcd *Lcd::instance()
{
    //如果没有实例则创建实例
    if(m_instance == NULL)
    {
        m_instance = new Lcd();
    }
    return m_instance;
}


void Lcd::delInstance()
{
    //关闭设备文件
    ::close(m_instance->fd);
    //解除映射
    int ret = munmap(m_instance->mp, 800*480*4);
    if(ret)
    {
        perror("[error] lcd munmap");
    }
    //释放实例空间
    delete [] m_instance;
    m_instance = NULL;
}

int Lcd::getFd() const
{
    return fd;
}


int *Lcd::addr()
{
    return this->mp;
}
