#include"lcd.h"

Lcd* Lcd::m_instance = NULL;

Lcd::Lcd()
{
    init(LCD_PATH);
}

Lcd::~Lcd()
{
    //�ر��豸�ļ�
    ::close(this->fd);
    //���ӳ��
    int ret = munmap(this->mp, 800*480*4);
    if(ret)
    {
        perror("[error] lcd munmap");
    }
    //�ͷ�ʵ���ռ�
    delete [] this->m_instance;
    this->m_instance = NULL;
}

void Lcd::init(const char* dev_path)
{
    //���豸�ļ�
    this->fd = open(dev_path, O_RDWR);
    if(this->fd == -1)
    {
        perror("[error] lcd open");
    }

    //����ӳ��
    this->mp = (int*)mmap(NULL, 800*480*4, PROT_READ|PROT_WRITE, MAP_SHARED, this->fd, 0);
    if(this->mp == MAP_FAILED)
    {
        perror("[error] lcd mmap");
    }


}


Lcd *Lcd::instance()
{
    //���û��ʵ���򴴽�ʵ��
    if(m_instance == NULL)
    {
        m_instance = new Lcd();
    }
    return m_instance;
}


void Lcd::delInstance()
{
    //�ر��豸�ļ�
    ::close(m_instance->fd);
    //���ӳ��
    int ret = munmap(m_instance->mp, 800*480*4);
    if(ret)
    {
        perror("[error] lcd munmap");
    }
    //�ͷ�ʵ���ռ�
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
