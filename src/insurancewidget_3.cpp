#include "insurancewidget_3.h"

InsuranceWidget::InsuranceWidget()
{

}

//-----------cue-3 next-4
int InsuranceWidget::exec()
{
    while(1)
    {
        Point touch_coord(-1, -1);  /* 触摸坐标 */

        Touch::instance()->wait(touch_coord);


        if(touch_coord.x() > 110 && touch_coord.y() >120 && touch_coord.x() < 209 && touch_coord.y() < 170)
        {//医保自费按钮

            PR_Fsm::instance()->handleEvent(4);
            PersonalDetailsWidget pdw;
            if(pdw.exec())
            {
                return 1;
            }
        }
        else if(touch_coord.x() > 230 && touch_coord.y() >120 && touch_coord.x() < 329 && touch_coord.y() < 170)
        {//医保统筹按钮

            PR_Fsm::instance()->handleEvent(4);
            PersonalDetailsWidget pdw;
            if(pdw.exec())
            {
                return 1;
            }
        }
        else if(touch_coord.x() > 349 && touch_coord.y() >120 && touch_coord.x() < 449 && touch_coord.y() < 170)
        {//医保门慢按钮

            PR_Fsm::instance()->handleEvent(4);
            PersonalDetailsWidget pdw;
            if(pdw.exec())
            {
                return 1;
            }
        }
        else if(touch_coord.x() > 469 && touch_coord.y() >120 && touch_coord.x() < 568 && touch_coord.y() < 170)
        {//医保门特按钮

            PR_Fsm::instance()->handleEvent(4);
            PersonalDetailsWidget pdw;
            if(pdw.exec())
            {
                return 1;
            }
        }
        else if(touch_coord.x() > 589 && touch_coord.y() >120 && touch_coord.x() < 688 && touch_coord.y() < 170)
        {//医保公医按钮

            PR_Fsm::instance()->handleEvent(4);
            PersonalDetailsWidget pdw;
            if(pdw.exec())
            {
                return 1;
            }
        }
        else if(touch_coord.x() > 10 && touch_coord.y() >423 && touch_coord.x() < 110 && touch_coord.y() < 474)
        {//返回按钮

            PR_Fsm::instance()->handleEvent(11);
            return 2;
        }
        else if(touch_coord.x() > 119 && touch_coord.y() >423 && touch_coord.x() < 220 && touch_coord.y() < 475)
        {//退出按钮

            //迁越-event-12
            PR_Fsm::instance()->handleEvent(12);
            return 1;
        }
    }

}
