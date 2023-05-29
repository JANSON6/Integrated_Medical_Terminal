#include "bmp.h"

BMP::BMP(const char *bmp_path)
{
   //打开图片
   this->fd = open(bmp_path, O_RDONLY);
   if(this->fd == -1)
   {
       perror("[error] bmp open");
   }

   //获取图片宽度和高度
   lseek(this->fd, 18, SEEK_SET);
   read(this->fd, &this->m_width, sizeof(int));
   read(this->fd, &this->m_height, sizeof(int));

   //std::cout<<"w ="<<this->m_width<<"h ="<<this->m_height<<std::endl;

   //获取图片数据大小
   this->m_size = this->m_width * this->m_height *3;

   //申请空间存放图片数据，不读取补齐的字节
   this->m_buf = new char[this->m_size];

   //计算补齐字节数
   int skip_byte = 0;
   if( this->m_width* 3 % 4  != 0)
   {
       skip_byte = 4 - (this->m_width * 3 % 4);
   }

   //读取图片数据
   lseek(this->fd, 54, SEEK_SET);

   //倒置存放图片数据
   char* tmp_ptr = this->m_buf;
   tmp_ptr += this->m_size;

   for(int i = 0; i < this->m_height; i++)
   {
       tmp_ptr -= this->m_width*3;              //要先减是因为读取是向后保存的，如果没有先减就越界了哦！
       read(this->fd, tmp_ptr, this->m_width*3);
       lseek(this->fd, skip_byte, SEEK_CUR);    //跳过每行的补齐字节，不读取他们
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
