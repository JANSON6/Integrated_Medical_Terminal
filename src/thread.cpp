#include "thread.h"

Thread::Thread()
{

}

Thread::~Thread()
{

}

void Thread::start()
{
    pthread_create(&this->tid, NULL, task, this);   //新线程调用的就是派生类重写的run函数
    pthread_detach(this->tid);                      //设置线程分离
}

void Thread::stop()
{
    pthread_cancel(this->tid);
}

void *task(void *arg)
{
    //多态
    Thread* th = (Thread*) arg;
    th->run();

    return NULL;
}
