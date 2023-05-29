#ifndef LCD_H
#define LCD_H

#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<fcntl.h>

#define LCD_PATH "/dev/fb0"

class Lcd
{
    Lcd();
public:

    ~Lcd();

    //初始化
    void init(const char* dev_path = "/dev/fb0");

    int* addr();
    int getFd() const;

    //创建和删除实例
    static Lcd* instance();
    static void delInstance();





private:
    int  fd;    /* 文件描述符 */
    int* mp;    /* 屏幕内存映射 */
    static Lcd* m_instance; /* 单例实例对象空间指针 */

};

#endif // LCD_H
