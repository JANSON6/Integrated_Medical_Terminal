#ifndef TOUCH_H
#define TOUCH_H
#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<linux/input.h>
#include"point.h"

#define TOUCH_PATH "/dev/input/event0"

class Touch
{
    Touch();
public:
    ~Touch();

    //创建实例
    static Touch* instance();
    static void del_instance();

    //获取触摸事件坐标
    void wait(Point& p);

    static Touch* m_instance;
    static int fd;
private:

};

#endif // TOUCH_H
