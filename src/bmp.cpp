#include "bmp.h"

BMP::BMP(const char *bmp_path)
{
   //��ͼƬ
   this->fd = open(bmp_path, O_RDONLY);
   if(this->fd == -1)
   {
       perror("[error] bmp open");
   }

   //��ȡͼƬ��Ⱥ͸߶�
   lseek(this->fd, 18, SEEK_SET);
   read(this->fd, &this->m_width, sizeof(int));
   read(this->fd, &this->m_height, sizeof(int));

   //std::cout<<"w ="<<this->m_width<<"h ="<<this->m_height<<std::endl;

   //��ȡͼƬ���ݴ�С
   this->m_size = this->m_width * this->m_height *3;

   //����ռ���ͼƬ���ݣ�����ȡ������ֽ�
   this->m_buf = new char[this->m_size];

   //���㲹���ֽ���
   int skip_byte = 0;
   if( this->m_width* 3 % 4  != 0)
   {
       skip_byte = 4 - (this->m_width * 3 % 4);
   }

   //��ȡͼƬ����
   lseek(this->fd, 54, SEEK_SET);

   //���ô��ͼƬ����
   char* tmp_ptr = this->m_buf;
   tmp_ptr += this->m_size;

   for(int i = 0; i < this->m_height; i++)
   {
       tmp_ptr -= this->m_width*3;              //Ҫ�ȼ�����Ϊ��ȡ����󱣴�ģ����û���ȼ���Խ����Ŷ��
       read(this->fd, tmp_ptr, this->m_width*3);
       lseek(this->fd, skip_byte, SEEK_CUR);    //����ÿ�еĲ����ֽڣ�����ȡ����
   }
   ::close(this->fd);
}

BMP::~BMP()
{
    delete[] this->m_buf;
}

char BMP::operator[](int index)
{
    return this->m_buf[index];
}

char* BMP::addr() const
{
    return this->m_buf;
}

int BMP::show(int *mp, int x, int y)
{

    for(int i=0,n=0; i<this->m_height; i++)
    {
        for(int j=0; j<this->m_width; j++,n+=3)
        {
            *(mp + 800*(i+y) + j+x) = this->m_buf[n]<<0|this->m_buf[n+1]<<8|this->m_buf[n+2]<<16;
        }
    }

}

int BMP::width() const
{
    return m_width;
}

int BMP::height() const
{
    return m_height;
}
