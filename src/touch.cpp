#include "touch.h"

Touch* Touch::m_instance = NULL;
int Touch::fd = -1;

Touch::Touch()
{
    this->fd = open(TOUCH_PATH, O_RDONLY);
    if(this->fd == -1)
    {
        perror("[error] touch open");
    }
}

Touch::~Touch()
{

}

Touch *Touch::instance()
{
    if(m_instance == NULL)
    {
        m_instance = new Touch();
    }
    return m_instance;
}

void Touch::del_instance()
{
    ::close(Touch::fd);
    delete m_instance;
}

void Touch::wait(Point& p)
{

    while(1)
    {
        struct input_event info;
        //读取触摸事件坐标
        read(this->fd, &info, sizeof(struct input_event));
        //判断当前发生的是触摸屏事件,接着判断触发的是X轴事件
        if(info.type == EV_ABS && info.code == ABS_X)
        {
            p.setX(info.value*800/1024);
        }
        //判断当前发生的是触摸屏事件,接着判断触发的是Y轴事件
        if(info.type == EV_ABS && info.code == ABS_Y)
        {
            p.setY(info.value*480/600);
        }
        //松开的时候退出循环
        if(info.type == EV_KEY && info.code == BTN_TOUCH &&  info.value == 0)
        {

            break;
        }
    }
}
