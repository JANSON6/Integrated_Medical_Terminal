/*
 * 抽象类：线程类
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

    //线程控制
    void start();
    void stop();

    //任务执行
    virtual void run()=0;


private:
    pthread_t tid; /* 线程号 */
};

#endif // THREAD_H
