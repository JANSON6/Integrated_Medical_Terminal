#include "thread.h"

Thread::Thread()
{

}

Thread::~Thread()
{

}

void Thread::start()
{
    pthread_create(&this->tid, NULL, task, this);   //���̵߳��õľ�����������д��run����
    pthread_detach(this->tid);                      //�����̷߳���
}

void Thread::stop()
{
    pthread_cancel(this->tid);
}

void *task(void *arg)
{
    //��̬
    Thread* th = (Thread*) arg;
    th->run();

    return NULL;
}
