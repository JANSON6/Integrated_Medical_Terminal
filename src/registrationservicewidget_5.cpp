#include "registrationservicewidget_5.h"

RegistrationServiceWidget::RegistrationServiceWidget()
{

}

//-----cur-5 next-6
int RegistrationServiceWidget::exec()
{
    while(1)
    {
        Point touch_coord(-1, -1);  /* �������� */
        Touch::instance()->wait(touch_coord);

        if(touch_coord.x() > 10 && touch_coord.y() >423 && touch_coord.x() < 110 && touch_coord.y() < 474)
        {//���ذ�ť

            //ǨԽ-event-11
            PR_Fsm::instance()->handleEvent(11);
            return 0;
        }
        else if(touch_coord.x() > 150 && touch_coord.y() > 164 && touch_coord.x() < 300 && touch_coord.y() < 316)
        {//�ҺŰ�ť

            //ǨԽ-event-6
            PR_Fsm::instance()->handleEvent(6);
            DepartmentsWidget dw;

            if(dw.exec())
            {
                return 1;
            }
        }
    }
}
