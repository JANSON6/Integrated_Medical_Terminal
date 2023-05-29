#include "personaldetailswidget_4.h"

PersonalDetailsWidget::PersonalDetailsWidget()
{

}

//--------cur-4 next-5
int PersonalDetailsWidget::exec()
{

    while(1)
    {
        //显示手机号
        ShowFont::instance()->display((char*)(PersonalInfo::instance()->phone().c_str()), 32, 150, 32, 0x00ffffff, 0x00000000, 260, 253);

        Point touch_coord(-1, -1);  /* 触摸坐标 */
        Touch::instance()->wait(touch_coord);

        if(touch_coord.x() > 10 && touch_coord.y() >423 && touch_coord.x() < 110 && touch_coord.y() < 474)
        {//返回按钮

            //迁越-event-11
            PR_Fsm::instance()->handleEvent(11);
            return 0;
        }
        else if(touch_coord.x() > 119 && touch_coord.y() >423 && touch_coord.x() < 220 && touch_coord.y() < 475)
        {//退出按钮

            //迁越-event-12
            PR_Fsm::instance()->handleEvent(12);
            return 1;
        }
        else if(touch_coord.x() > 688 && touch_coord.y() >423 && touch_coord.x() < 788 && touch_coord.y() < 474)
        {//确认按钮

            PR_Fsm::instance()->handleEvent(5);
            RegistrationServiceWidget rsw;

            if(rsw.exec())
            {
                return 1;
            }

        }
    }
}
