#ifndef PR_FSM_H
#define PR_FSM_H
#include<iostream>
#include"thread.h"
#include"pr_fsmitem.h"

//extern int free_time;   //�޲���ʱ�䣬����������

class PR_FsmItem;   //���ǰ������

class PR_Fsm:public Thread
{

public:
    int m_curState;                         /* ��ǰ״̬ */


private:
    std::vector<PR_FsmItem*> m_fsmTable;    /* ״̬Ǩ�Ʊ� */
    static PR_Fsm* m_instance;              /* ����ʵ�� */

public:
    ~PR_Fsm();

    //״̬Ǩ�ƺ���
    void transerState(int nextState);

    //�¼�������
    void handleEvent(int event);

    //ʵ������
    static PR_Fsm* instance();

    //�̳еĴ��麯��
    void run();

    int free_time() const;

private:
    PR_Fsm(int curState = 0);
    int m_free_time;
};




#endif // PR_FSM_H
