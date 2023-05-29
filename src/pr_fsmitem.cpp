#include "pr_fsmitem.h"


PR_FsmItem::PR_FsmItem(PR_FsmItem::State curState, PR_FsmItem::Events event, void (*action)(), PR_FsmItem::State nextState)
    :m_curState(curState), m_event(event), m_action(action), m_nextState(nextState)
{

}

void PR_FsmItem::initFsmTable(std::vector<PR_FsmItem*> &_vector)
{

    //----1
    PR_FsmItem *object_1 = new PR_FsmItem(PR_FsmItem::STATUS_0_WAITING_SELECTION_SERVICE,
                                          PR_FsmItem::EVENT_1_CLICK_CLINIC_REGISTRATION_BUTTON,
                                          &PR_FsmItem::Show_1_Login_Window,
                                          PR_FsmItem::STATUS_1_WAITING_SELECT_LOGIN_MODE);
    _vector.push_back(object_1);

    //----2
    PR_FsmItem *object_2 = new PR_FsmItem(PR_FsmItem::STATUS_1_WAITING_SELECT_LOGIN_MODE,
                                          PR_FsmItem::EVENT_2_CLICK_ID_CARD_LOGIN_BUTTON,
                                          &PR_FsmItem::Show_2_Authentication_Window,
                                          PR_FsmItem::STATUS_2_WAITING_ID_VERIFICATION);
    _vector.push_back(object_2);

    //----3
    PR_FsmItem *object_3 = new PR_FsmItem(PR_FsmItem::STATUS_2_WAITING_ID_VERIFICATION,
                                          PR_FsmItem::EVENT_3_ID_CARD_RECOGNITION_COMPLETED,
                                          &PR_FsmItem::Show_3_Insurance_Window,
                                          PR_FsmItem::STATUS_3_CHOOSE_MEDICAL_INSURANCE);
    _vector.push_back(object_3);

    //----4
    PR_FsmItem *object_4 = new PR_FsmItem(PR_FsmItem::STATUS_3_CHOOSE_MEDICAL_INSURANCE,
                                          PR_FsmItem::EVENT_4_CLICK_INSURANCE_BUTTON,
                                          &PR_FsmItem::Show_4_Personal_Details_Window,
                                          PR_FsmItem::STATUS_4_CONFIRM_PERSONAL_INFORMATION);
    _vector.push_back(object_4);

    //----5
    PR_FsmItem *object_5 = new PR_FsmItem(PR_FsmItem::STATUS_4_CONFIRM_PERSONAL_INFORMATION,
                                          PR_FsmItem::EVENT_5_CLICK_CONFIRM_BUTTON,
                                          &PR_FsmItem::Show_5_Registration_Service_Window,
                                          PR_FsmItem::STATUS_5_CHOOSE_REGISTRATION_SERVICE);
    _vector.push_back(object_5);

    //----6
    PR_FsmItem *object_6 = new PR_FsmItem(PR_FsmItem::STATUS_5_CHOOSE_REGISTRATION_SERVICE,
                                          PR_FsmItem::EVENT_6_CLICK_REGISTRATION_BUTTON,
                                          &PR_FsmItem::Show_6_Departments_Window,
                                          PR_FsmItem::STATUS_6_WAITING_SELECT_DEPARTMENT);
    _vector.push_back(object_6);

    //----7
    PR_FsmItem *object_7 = new PR_FsmItem(PR_FsmItem::STATUS_6_WAITING_SELECT_DEPARTMENT,
                                          PR_FsmItem::EVENT_7_CLICK_DEPARTMENT_BUTTON,
                                          &PR_FsmItem::Show_7_Clinic_Window,
                                          PR_FsmItem::STATUS_7_WAITING_SELECT_CLINIC);
    _vector.push_back(object_7);

    //----8
    PR_FsmItem *object_8 = new PR_FsmItem(PR_FsmItem::STATUS_7_WAITING_SELECT_CLINIC,
                                          PR_FsmItem::EVENT_8_CLICK_CLINIC_BUTTON,
                                          &PR_FsmItem::Show_8_Doctor_Window,
                                          PR_FsmItem::STATUS_8_CHOOSE_CLINIC_DOCTOR);
    _vector.push_back(object_8);

    //----9
    PR_FsmItem *object_9 = new PR_FsmItem(PR_FsmItem::STATUS_8_CHOOSE_CLINIC_DOCTOR,
                                          PR_FsmItem::EVENT_9_CLICK_DOCTOR_BUTTON,
                                          &PR_FsmItem::Show_9_Time_Window,
                                          PR_FsmItem::STATUS_9_CHOOSE_CLINIC_TIME);
    _vector.push_back(object_9);

    //----10
    PR_FsmItem *object_10 = new PR_FsmItem(PR_FsmItem::STATUS_9_CHOOSE_CLINIC_TIME,
                                           PR_FsmItem::EVENT_10_CLICK_TIME_BUTTON,
                                           &PR_FsmItem::Show_0_Main_Window,
                                           PR_FsmItem::STATUS_0_WAITING_SELECTION_SERVICE);
    _vector.push_back(object_10);

    //----11
    PR_FsmItem *object_11 = new PR_FsmItem(PR_FsmItem::STATUS_1_WAITING_SELECT_LOGIN_MODE,
                                           PR_FsmItem::EVENT_11_CLICK_BACK_BUTTON,
                                           &PR_FsmItem::Show_0_Main_Window,
                                           PR_FsmItem::STATUS_0_WAITING_SELECTION_SERVICE);
    _vector.push_back(object_11);

    //----12
    PR_FsmItem *object_12 = new PR_FsmItem(PR_FsmItem::STATUS_2_WAITING_ID_VERIFICATION,
                                           PR_FsmItem::EVENT_11_CLICK_BACK_BUTTON,
                                           &PR_FsmItem::Show_1_Login_Window,
                                           PR_FsmItem::STATUS_1_WAITING_SELECT_LOGIN_MODE);
    _vector.push_back(object_12);

    //----13
    PR_FsmItem *object_13 = new PR_FsmItem(PR_FsmItem::STATUS_3_CHOOSE_MEDICAL_INSURANCE,
                                           PR_FsmItem::EVENT_11_CLICK_BACK_BUTTON,
                                           &PR_FsmItem::Show_1_Login_Window,
                                           PR_FsmItem::STATUS_1_WAITING_SELECT_LOGIN_MODE);
    _vector.push_back(object_13);

    //----14
    PR_FsmItem *object_14 = new PR_FsmItem(PR_FsmItem::STATUS_4_CONFIRM_PERSONAL_INFORMATION,
                                           PR_FsmItem::EVENT_11_CLICK_BACK_BUTTON,
                                           &PR_FsmItem::Show_3_Insurance_Window,
                                           PR_FsmItem::STATUS_3_CHOOSE_MEDICAL_INSURANCE);
    _vector.push_back(object_14);

    //----15
    PR_FsmItem *object_15 = new PR_FsmItem(PR_FsmItem::STATUS_5_CHOOSE_REGISTRATION_SERVICE,
                                           PR_FsmItem::EVENT_11_CLICK_BACK_BUTTON,
                                           &PR_FsmItem::Show_4_Personal_Details_Window,
                                           PR_FsmItem::STATUS_4_CONFIRM_PERSONAL_INFORMATION);
     _vector.push_back(object_15);

    //----16
    PR_FsmItem *object_16 = new PR_FsmItem(PR_FsmItem::STATUS_6_WAITING_SELECT_DEPARTMENT,
                                           PR_FsmItem::EVENT_11_CLICK_BACK_BUTTON,
                                           &PR_FsmItem::Show_5_Registration_Service_Window,
                                           PR_FsmItem::STATUS_5_CHOOSE_REGISTRATION_SERVICE);
     _vector.push_back(object_16);

    //----17
    PR_FsmItem *object_17 = new PR_FsmItem(PR_FsmItem::STATUS_7_WAITING_SELECT_CLINIC,
                                           PR_FsmItem::EVENT_11_CLICK_BACK_BUTTON,
                                           &PR_FsmItem::Show_6_Departments_Window,
                                           PR_FsmItem::STATUS_6_WAITING_SELECT_DEPARTMENT);
     _vector.push_back(object_17);

    //----18
    PR_FsmItem *object_18 = new PR_FsmItem(PR_FsmItem::STATUS_8_CHOOSE_CLINIC_DOCTOR,
                                           PR_FsmItem::EVENT_11_CLICK_BACK_BUTTON,
                                           &PR_FsmItem::Show_7_Clinic_Window,
                                           PR_FsmItem::STATUS_7_WAITING_SELECT_CLINIC);
     _vector.push_back(object_18);

    //----19
    PR_FsmItem *object_19 = new PR_FsmItem(PR_FsmItem::STATUS_9_CHOOSE_CLINIC_TIME,
                                           PR_FsmItem::EVENT_11_CLICK_BACK_BUTTON,
                                           &PR_FsmItem::Show_8_Doctor_Window,
                                           PR_FsmItem::STATUS_8_CHOOSE_CLINIC_DOCTOR);
     _vector.push_back(object_19);

    //----20
    PR_FsmItem *object_20 = new PR_FsmItem(PR_FsmItem::STATUS_1_WAITING_SELECT_LOGIN_MODE,
                                           PR_FsmItem::EVENT_12_CLICK_EXIT_BUTTON,
                                           &PR_FsmItem::Show_0_Main_Window,
                                           PR_FsmItem::STATUS_0_WAITING_SELECTION_SERVICE);
     _vector.push_back(object_20);

    //----21
    PR_FsmItem *object_21 = new PR_FsmItem(PR_FsmItem::STATUS_2_WAITING_ID_VERIFICATION,
                                           PR_FsmItem::EVENT_12_CLICK_EXIT_BUTTON,
                                           &PR_FsmItem::Show_0_Main_Window,
                                           PR_FsmItem::STATUS_0_WAITING_SELECTION_SERVICE);
     _vector.push_back(object_21);

    //----22
    PR_FsmItem *object_22 = new PR_FsmItem(PR_FsmItem::STATUS_3_CHOOSE_MEDICAL_INSURANCE,
                                           PR_FsmItem::EVENT_12_CLICK_EXIT_BUTTON,
                                           &PR_FsmItem::Show_0_Main_Window,
                                           PR_FsmItem::STATUS_0_WAITING_SELECTION_SERVICE);
     _vector.push_back(object_22);

    //----23
    PR_FsmItem *object_23 = new PR_FsmItem(PR_FsmItem::STATUS_4_CONFIRM_PERSONAL_INFORMATION,
                                           PR_FsmItem::EVENT_12_CLICK_EXIT_BUTTON,
                                           &PR_FsmItem::Show_0_Main_Window,
                                           PR_FsmItem::STATUS_0_WAITING_SELECTION_SERVICE);
     _vector.push_back(object_23);

    //----24
    PR_FsmItem *object_24 = new PR_FsmItem(PR_FsmItem::STATUS_5_CHOOSE_REGISTRATION_SERVICE,
                                           PR_FsmItem::EVENT_12_CLICK_EXIT_BUTTON,
                                           &PR_FsmItem::Show_0_Main_Window,
                                           PR_FsmItem::STATUS_0_WAITING_SELECTION_SERVICE);
     _vector.push_back(object_24);

    //----25
    PR_FsmItem *object_25 = new PR_FsmItem(PR_FsmItem::STATUS_6_WAITING_SELECT_DEPARTMENT,
                                           PR_FsmItem::EVENT_12_CLICK_EXIT_BUTTON,
                                           &PR_FsmItem::Show_0_Main_Window,
                                           PR_FsmItem::STATUS_0_WAITING_SELECTION_SERVICE);
     _vector.push_back(object_25);
    //----26
    PR_FsmItem *object_26 = new PR_FsmItem(PR_FsmItem::STATUS_7_WAITING_SELECT_CLINIC,
                                           PR_FsmItem::EVENT_12_CLICK_EXIT_BUTTON,
                                           &PR_FsmItem::Show_0_Main_Window,
                                           PR_FsmItem::STATUS_0_WAITING_SELECTION_SERVICE);
     _vector.push_back(object_26);

    //----27
    PR_FsmItem *object_27 = new PR_FsmItem(PR_FsmItem::STATUS_8_CHOOSE_CLINIC_DOCTOR,
                                           PR_FsmItem::EVENT_12_CLICK_EXIT_BUTTON,
                                           &PR_FsmItem::Show_0_Main_Window,
                                           PR_FsmItem::STATUS_0_WAITING_SELECTION_SERVICE);
     _vector.push_back(object_27);

    //----28
    PR_FsmItem *object_28 = new PR_FsmItem(PR_FsmItem::STATUS_9_CHOOSE_CLINIC_TIME,
                                           PR_FsmItem::EVENT_12_CLICK_EXIT_BUTTON,
                                           &PR_FsmItem::Show_0_Main_Window,
                                           PR_FsmItem::STATUS_0_WAITING_SELECTION_SERVICE);
     _vector.push_back(object_28);

     //³õÊ¼½çÃæ
     PR_FsmItem::Show_0_Main_Window();
}

void PR_FsmItem::Show_0_Main_Window()
{
    //»ñÈ¡Í¼Æ¬
    BMP main_window("./resource/bmp/main_window.bmp");

    //ÏÔÊ¾Í¼Æ¬
    int*tmp = Lcd::instance()->addr();
    main_window.show(tmp, 0, 0);
}

void PR_FsmItem::Show_1_Login_Window()
{
    //»ñÈ¡Í¼Æ¬
    BMP loginWindow("./resource/bmp/loginWindow.bmp");

    //ÏÔÊ¾Í¼Æ¬
    int*tmp = Lcd::instance()->addr();
    loginWindow.show(tmp, 0, 0);
}

void PR_FsmItem::Show_2_Authentication_Window()
{
    //»ñÈ¡Í¼Æ¬
    BMP authenticationWindow("./resource/bmp/authenticationWindow.bmp");
    BMP interPhoneNumber("./resource/bmp/interPhoneNumber.bmp");
    //ÏÔÊ¾Í¼Æ¬
    int*tmp = Lcd::instance()->addr();
    authenticationWindow.show(tmp, 0, 0);

    sleep(2);
    interPhoneNumber.show(tmp, 0, 0);


}

void PR_FsmItem::Show_3_Insurance_Window()
{
    //»ñÈ¡Í¼Æ¬
    BMP insuranceWindow("./resource/bmp/insuranceWindow.bmp");

    //ÏÔÊ¾Í¼Æ¬
    int*tmp = Lcd::instance()->addr();
    insuranceWindow.show(tmp, 0, 0);
}

void PR_FsmItem::Show_4_Personal_Details_Window()
{
    //»ñÈ¡Í¼Æ¬
    BMP personal_Details_Window("./resource/bmp/personal_Details_Window.bmp");

    //ÏÔÊ¾Í¼Æ¬
    int*tmp = Lcd::instance()->addr();
    personal_Details_Window.show(tmp, 0, 0);
}

void PR_FsmItem::Show_5_Registration_Service_Window()
{
    //»ñÈ¡Í¼Æ¬
    BMP registrationServiceWindow("./resource/bmp/registrationServiceWindow.bmp");

    //ÏÔÊ¾Í¼Æ¬
    int*tmp = Lcd::instance()->addr();
    registrationServiceWindow.show(tmp, 0, 0);
}

void PR_FsmItem::Show_6_Departments_Window()
{
    //»ñÈ¡Í¼Æ¬
    BMP departments_Window("./resource/bmp/departments_Window.bmp");

    //ÏÔÊ¾Í¼Æ¬
    int*tmp = Lcd::instance()->addr();
    departments_Window.show(tmp, 0, 0);
}

void PR_FsmItem::Show_7_Clinic_Window()
{
    //»ñÈ¡Í¼Æ¬
    BMP clinic_Window("./resource/bmp/clinic_Window.bmp");

    //ÏÔÊ¾Í¼Æ¬
    int*tmp = Lcd::instance()->addr();
    clinic_Window.show(tmp, 0, 0);
}

void PR_FsmItem::Show_8_Doctor_Window()
{
    //»ñÈ¡Í¼Æ¬
    BMP doctor_Window("./resource/bmp/doctor_Window.bmp");

    //ÏÔÊ¾Í¼Æ¬
    int*tmp = Lcd::instance()->addr();
    doctor_Window.show(tmp, 0, 0);
}

void PR_FsmItem::Show_9_Time_Window()
{
    //»ñÈ¡Í¼Æ¬
    BMP time_Window("./resource/bmp/time_Window.bmp");

    //ÏÔÊ¾Í¼Æ¬
    int*tmp = Lcd::instance()->addr();
    time_Window.show(tmp, 0, 0);
}
