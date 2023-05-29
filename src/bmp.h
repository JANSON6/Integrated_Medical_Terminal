//BMPͼƬ��
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

    //������������ͼƬ��������
    char operator[](int index);

    //����ͼƬ���ݵ��׵�ַ
    char *addr()const;

    //���������ͼƬ����д�絽һ��ӳ���ڴ���
    int show(int* mp, int x = 0, int y = 0);

    //��ȡͼƬ���
    int width() const;
    int height() const;

private:
    int fd;         /* ͼƬ������ */
    int m_width;    /* ͼƬ��� */
    int m_height;   /* ͼƬ�߶� */
    int m_size;     /* ͼƬ��С */
    char* m_buf;    /* ͼƬ����ָ�� */
};

#endif // BMP_H
