#include "loginwidget_1.h"

LoginWidget::LoginWidget()
{

}

//----------cur-1 next-2
int LoginWidget::exec()
{
    while(1)
    {
        Point touch_coord(-1, -1);  /* �������� */

        Touch::instance()->wait(touch_coord);

        if(touch_coord.x() > 236 && touch_coord.y() >98 && touch_coord.x() < 377 && touch_coord.y() < 241)
        {//���֤��¼��ť

            //ǨԽ-event-2
            PR_Fsm::instance()->handleEvent(2);
            AuthenticationWidget aw;

            //�������ֵΪ1��������أ�Ϊ0�����ڵ�ǰҳ
            if(aw.exec())
            {
                return 1;
            }
        }
        else if(touch_coord.x() > 14 && touch_coord.y() >417 && touch_coord.x() < 115 && touch_coord.y() < 469)
        {//���ذ�ť

            //ǨԽ-event-11
            PR_Fsm::instance()->handleEvent(11);
            return 0;
        }
    }
}
