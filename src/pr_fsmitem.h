#ifndef PR_FSMITEM_H
#define PR_FSMITEM_H
#include<iostream>
#include<vector>
#include"lcd.h"
#include"bmp.h"
#include"pr_fsm.h"
#include"mainwidget_0.h"

class PR_FsmItem /*PERSON REGISTRATION*/
{
    //状态机模板 友元声明
    friend class PR_Fsm;
public:
    //状态枚举
    typedef enum
    {
        STATUS_0_WAITING_SELECTION_SERVICE      = 0,
        STATUS_1_WAITING_SELECT_LOGIN_MODE      = 1,
        STATUS_2_WAITING_ID_VERIFICATION        = 2,
        STATUS_3_CHOOSE_MEDICAL_INSURANCE       = 3,
        STATUS_4_CONFIRM_PERSONAL_INFORMATION   = 4,
        STATUS_5_CHOOSE_REGISTRATION_SERVICE    = 5,
        STATUS_6_WAITING_SELECT_DEPARTMENT      = 6,
        STATUS_7_WAITING_SELECT_CLINIC          = 7,
        STATUS_8_CHOOSE_CLINIC_DOCTOR           = 8,
        STATUS_9_CHOOSE_CLINIC_TIME             = 9

    }State;

    //事件枚举
    typedef enum
    {
        EVENT_0_INITIALIZATION_COMPLETE          = 0,
        EVENT_1_CLICK_CLINIC_REGISTRATION_BUTTON = 1,
        EVENT_2_CLICK_ID_CARD_LOGIN_BUTTON       = 2,
        EVENT_3_ID_CARD_RECOGNITION_COMPLETED    = 3,
        EVENT_4_CLICK_INSURANCE_BUTTON           = 4,
        EVENT_5_CLICK_CONFIRM_BUTTON             = 5,
        EVENT_6_CLICK_REGISTRATION_BUTTON        = 6,
        EVENT_7_CLICK_DEPARTMENT_BUTTON          = 7,
        EVENT_8_CLICK_CLINIC_BUTTON              = 8,
        EVENT_9_CLICK_DOCTOR_BUTTON              = 9,
        EVENT_10_CLICK_TIME_BUTTON               = 10,
        EVENT_11_CLICK_BACK_BUTTON               = 11,
        EVENT_12_CLICK_EXIT_BUTTON               = 12

    }Events;

private:
    State  m_curState;   /* 当前状态 */
    Events m_event;      /* 状态迁越事件 */
    void (*m_action)();  /* 动作函数指针 */
    State  m_nextState;  /* 迁越状态 */



public:
    PR_FsmItem(State curState, Events event, void (*action)(), State nextState);
private:

    //初始化状态机
    static void initFsmTable(std::vector<PR_FsmItem*> &vector);

    static void Show_0_Main_Window();                   /*0 ：显示主窗口*/
    static void Show_1_Login_Window();                  /*1 ：显示登录窗口*/
    static void Show_2_Authentication_Window();         /*2 ：显示身份证验证窗口*/
    static void Show_3_Insurance_Window();              /*3 ：显示医保选择窗口*/
    static void Show_4_Personal_Details_Window();       /*4 ：显示个人信息窗口*/
    static void Show_5_Registration_Service_Window();   /*5 ：显示选择挂号业务窗口*/
    static void Show_6_Departments_Window();            /*6 ：显示选择科室窗口*/
    static void Show_7_Clinic_Window();                 /*7 ：显示选择门诊窗口*/
    static void Show_8_Doctor_Window();                 /*8 ：显示选择医生窗口*/
    static void Show_9_Time_Window();                   /*9 ：显示选择时间窗口*/




};

#endif // PR_FSMITEM_H
