#include "departmentswidget_6.h"

DepartmentsWidget::DepartmentsWidget()
{

}

//-----cur-6 next-7
int DepartmentsWidget::exec()
{
    //一级科室
    std::string department;

    while(1)
    {
        //显示手机号
        ShowFont::instance()->display((char*)(PersonalInfo::instance()->phone().c_str()), 32, 150, 32, 0x00ffffff, 0x00000000, 320, 74);

        Point touch_coord(-1, -1);  /* 触摸坐标 */
        Touch::instance()->wait(touch_coord);


        if(touch_coord.x() > 10 && touch_coord.y() >423 && touch_coord.x() < 110 && touch_coord.y() < 474)
        {//返回按钮

            //迁越-event-11
            PR_Fsm::instance()->handleEvent(11);
            return 0;
        }
        else if(touch_coord.x() > 120 && touch_coord.y() > 423 && touch_coord.x() < 219 && touch_coord.y() < 474)
        {//退出按钮

            //迁越-event-12
            PR_Fsm::instance()->handleEvent(12);
            return 1;

        }


        //科室

        if(touch_coord.x() > 158 && touch_coord.y() > 192 && touch_coord.x() < 241 && touch_coord.y() < 237)
        {//1内科
            department = depart_1;
            PersonalInfo::instance()->setDepartment_1(department);

            PR_Fsm::instance()->handleEvent(7);
            ClinicWidget cw;

            if(cw.exec())
            {
                return 1;
            }
        }
        else if(touch_coord.x() > 257 && touch_coord.y() > 192 && touch_coord.x() < 341 && touch_coord.y() < 237)
        {//2外科
            department = depart_2;
            PersonalInfo::instance()->setDepartment_1(department);

            PR_Fsm::instance()->handleEvent(7);
            ClinicWidget cw;

            if(cw.exec())
            {
                return 1;
            }
        }
        else if(touch_coord.x() > 357 && touch_coord.y() > 192 && touch_coord.x() < 441 && touch_coord.y() < 237)
        {//3五官科
            department = depart_3;
            PersonalInfo::instance()->setDepartment_1(department);

            PR_Fsm::instance()->handleEvent(7);
            ClinicWidget cw;

            if(cw.exec())
            {
                return 1;
            }
        }
        else if(touch_coord.x() > 457 && touch_coord.y() > 192 && touch_coord.x() < 540 && touch_coord.y() < 237)
        {//4儿科
            department = depart_4;
            PersonalInfo::instance()->setDepartment_1(department);

            PR_Fsm::instance()->handleEvent(7);
            ClinicWidget cw;

            if(cw.exec())
            {
                return 1;
            }
        }
        else if(touch_coord.x() > 556 && touch_coord.y() > 192 && touch_coord.x() < 640 && touch_coord.y() < 237)
        {//5妇科
            department = depart_5;
            PersonalInfo::instance()->setDepartment_1(department);

            PR_Fsm::instance()->handleEvent(7);
            ClinicWidget cw;

            if(cw.exec())
            {
                return 1;
            }
        }
        else if(touch_coord.x() > 158 && touch_coord.y() > 261 && touch_coord.x() < 241 && touch_coord.y() < 306)
        {//6肿瘤科
            department = depart_6;
            PersonalInfo::instance()->setDepartment_1(department);

            PR_Fsm::instance()->handleEvent(7);
            ClinicWidget cw;

            if(cw.exec())
            {
                return 1;
            }
        }
        else if(touch_coord.x() > 258 && touch_coord.y() > 262 && touch_coord.x() < 341 && touch_coord.y() < 306)
        {//7传染科
            department = depart_7;
            PersonalInfo::instance()->setDepartment_1(department);

            PR_Fsm::instance()->handleEvent(7);
            ClinicWidget cw;

            if(cw.exec())
            {
                return 1;
            }
        }

        else if(touch_coord.x() > 357 && touch_coord.y() > 262 && touch_coord.x() < 440 && touch_coord.y() < 306)
        {//8男科
            department = depart_8;
            PersonalInfo::instance()->setDepartment_1(department);

            PR_Fsm::instance()->handleEvent(7);
            ClinicWidget cw;

            if(cw.exec())
            {
                return 1;
            }
        }
        else if(touch_coord.x() > 457 && touch_coord.y() > 262 && touch_coord.x() < 540 && touch_coord.y() < 306)
        {//9中医科
            department = depart_9;
            PersonalInfo::instance()->setDepartment_1(department);

            PR_Fsm::instance()->handleEvent(7);
            ClinicWidget cw;

            if(cw.exec())
            {
                return 1;
            }
        }
        else if(touch_coord.x() > 556 && touch_coord.y() > 262 && touch_coord.x() < 640 && touch_coord.y() < 306)
        {//10皮肤科
            department = depart_10;
            PersonalInfo::instance()->setDepartment_1(department);

            PR_Fsm::instance()->handleEvent(7);
            ClinicWidget cw;

            if(cw.exec())
            {
                return 1;
            }
        }

        else if(touch_coord.x() > 158 && touch_coord.y() > 331 && touch_coord.x() < 241 && touch_coord.y() < 376)
        {//11心理科
            department = depart_11;
            PersonalInfo::instance()->setDepartment_1(department);

            PR_Fsm::instance()->handleEvent(7);
            ClinicWidget cw;

            if(cw.exec())
            {
                return 1;
            }
        }
        else if(touch_coord.x() > 258 && touch_coord.y() > 331 && touch_coord.x() < 341 && touch_coord.y() < 376)
        {//12神经科
            department = depart_12;
            PersonalInfo::instance()->setDepartment_1(department);

            PR_Fsm::instance()->handleEvent(7);
            ClinicWidget cw;

            if(cw.exec())
            {
                return 1;
            }
        }

    }
}
