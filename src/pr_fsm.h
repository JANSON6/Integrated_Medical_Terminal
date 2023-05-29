#ifndef PR_FSM_H
#define PR_FSM_H
#include<iostream>
#include"thread.h"
#include"pr_fsmitem.h"

//extern int free_time;   //无操作时间，返回主界面

class PR_FsmItem;   //类的前置声明

class PR_Fsm:public Thread
{

public:
    int m_curState;                         /* 当前状态 */


private:
    std::vector<PR_FsmItem*> m_fsmTable;    /* 状态迁移表 */
    static PR_Fsm* m_instance;              /* 单例实例 */

public:
    ~PR_Fsm();

    //状态迁移函数
    void transerState(int nextState);

    //事件管理函数
    void handleEvent(int event);

    //实例对象
    static PR_Fsm* instance();

    //继承的纯虚函数
    void run();

    int free_time() const;

private:
    PR_Fsm(int curState = 0);
    int m_free_time;
};




#endif // PR_FSM_H
