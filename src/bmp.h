//BMP图片类
#ifndef BMP_H
#define BMP_H

#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include"lcd.h"

class BMP
{
public:
    BMP(const char* bmp_path);
    ~BMP();

    //根据索引返回图片像素数据
    char operator[](int index);

    //返回图片数据的首地址
    char *addr()const;

    //根据坐标把图片数据写如到一个映射内存中
    int show(int* mp, int x = 0, int y = 0);

    //提取图片宽高
    int width() const;
    int height() const;

private:
    int fd;         /* 图片描述符 */
    int m_width;    /* 图片宽度 */
    int m_height;   /* 图片高度 */
    int m_size;     /* 图片大小 */
    char* m_buf;    /* 图片数据指针 */
};

#endif // BMP_H
