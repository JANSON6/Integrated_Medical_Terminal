/*
 * �����ࣺ�߳���
*/

#ifndef THREAD_H
#define THREAD_H
#include<pthread.h>

void* task(void* arg);

class Thread
{
public:

    Thread();
    virtual ~Thread();

    //�߳̿���
    void start();
    void stop();

    //����ִ��
    virtual void run()=0;


private:
    pthread_t tid; /* �̺߳� */
};

#endif // THREAD_H
