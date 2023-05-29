#include "timewidget_9.h"

TimeWidget::TimeWidget()
{

}

int TimeWidget::exec()
{
    while(1)
    {
        //显示信息栏
        ShowFont::instance()->display((char*)(PersonalInfo::instance()->phone().c_str()), 32, 150, 32, 0x00ffffff, 0x00000000, 320, 74);
        ShowFont::instance()->display((char*)(PersonalInfo::instance()->department_1().c_str()), 32, 150, 32, 0x00ffffff, 0x00000000, 200, 10);
        ShowFont::instance()->display((char*)(PersonalInfo::instance()->department_2().c_str()), 32, 150, 32, 0x00ffffff, 0x00000000, 300, 10);
        ShowFont::instance()->display((char*)(PersonalInfo::instance()->clinic().c_str()), 32, 150, 32, 0x00ffffff, 0x00000000, 450, 10);
        ShowFont::instance()->display((char*)(PersonalInfo::instance()->doctor().c_str()), 32, 70, 32, 0x00ffffff, 0x00000000, 170, 143);
        ShowFont::instance()->display((char*)(PersonalInfo::instance()->date().c_str()), 32, 100, 32, 0x00ffffff, 0x00000000, 600, 10);


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
            PersonalInfo::del_instance();
            return 1;

        }

        if(touch_coord.x() > 132 && touch_coord.y() > 217 && touch_coord.x() < 252 && touch_coord.y() < 277)
        {//时间按钮 -1

            std::string tmp("9:00-10:00");
            PersonalInfo::instance()->setTime(tmp);

            PersonalInfo::instance()->saveInfoToText();
            //迁越-event-12
            PR_Fsm::instance()->handleEvent(12);

            return 1;
        }
        else if(touch_coord.x() > 270 && touch_coord.y() > 217 && touch_coord.x() < 390 && touch_coord.y() < 277)
        {//时间按钮 -2

            std::string tmp("10:30-11:30");
            PersonalInfo::instance()->setTime(tmp);

            PersonalInfo::instance()->saveInfoToText();
            //迁越-event-12
            PR_Fsm::instance()->handleEvent(12);

            return 1;
        }
        else if(touch_coord.x() > 409 && touch_coord.y() > 217 && touch_coord.x() < 529 && touch_coord.y() < 277)
        {//时间按钮 -3

            std::string tmp("13:00-14:00");
            PersonalInfo::instance()->setTime(tmp);

            PersonalInfo::instance()->saveInfoToText();
            //迁越-event-12
            PR_Fsm::instance()->handleEvent(12);

            return 1;
        }
        else if(touch_coord.x() > 547 && touch_coord.y() > 217 && touch_coord.x() < 667 && touch_coord.y() < 277)
        {//时间按钮 -4

            std::string tmp("14:30-15:30");
            PersonalInfo::instance()->setTime(tmp);

            PersonalInfo::instance()->saveInfoToText();
            //迁越-event-12
            PR_Fsm::instance()->handleEvent(12);

            return 1;
        }
    }
}
