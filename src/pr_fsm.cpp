#include "pr_fsm.h"

//int free_time = 60;
PR_Fsm* PR_Fsm::m_instance = NULL;

PR_Fsm::PR_Fsm(int curState)
    :m_curState(curState)
{

    PR_FsmItem::initFsmTable(this->m_fsmTable);
}

int PR_Fsm::free_time() const
{
    return m_free_time;
}



PR_Fsm::~PR_Fsm()
{
    for(size_t i=0; i<this->m_fsmTable.size(); i++)
    {
        delete[] this->m_fsmTable[i];
    }
}

void PR_Fsm::transerState(int nextState)
{
    this->m_curState = nextState;
}

void PR_Fsm::handleEvent(int event)
{
    void (*action)() = NULL;

    //std::cout<<"-------- cur_state = "<<this->m_curState<<" --------"<<std::endl;
    for(size_t i=0; i<this->m_fsmTable.size(); i++)
    {
        if(event == this->m_fsmTable[i]->m_event && this->m_curState == this->m_fsmTable[i]->m_curState)
        {

            //获取动作函数
            action = this->m_fsmTable[i]->m_action;
            //迁越状态
            transerState(this->m_fsmTable[i]->m_nextState);
            //action();
            break;
        }
    }
    //std::cout<<"-------- cur_state = "<<this->m_curState<<" --------"<<std::endl;
    action();
}

PR_Fsm *PR_Fsm::instance()
{
    if(m_instance == NULL)
    {
        m_instance = new PR_Fsm();
    }
    return m_instance;
}

void PR_Fsm::run()
{
    this->m_free_time = 60;

    while(1)
    {
        std::string tmp = std::to_string(m_free_time);
        ShowFont::instance()->display((char*)tmp.c_str(), 32,32, 32, 0x00ffffff, 0x000000ff, 740, 55);
        this->m_free_time -= 1;
        sleep(1);

        if(this->m_free_time < 0)
        {
            PR_Fsm::instance()->stop();
        }
    }


}



















