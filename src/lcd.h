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

    //��ʼ��
    void init(const char* dev_path = "/dev/fb0");

    int* addr();
    int getFd() const;

    //������ɾ��ʵ��
    static Lcd* instance();
    static void delInstance();





private:
    int  fd;    /* �ļ������� */
    int* mp;    /* ��Ļ�ڴ�ӳ�� */
    static Lcd* m_instance; /* ����ʵ������ռ�ָ�� */

};

#endif // LCD_H
