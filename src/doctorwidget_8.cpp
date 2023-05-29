#include "doctorwidget_8.h"

DoctorWidget::DoctorWidget()
{

}

int DoctorWidget::exec()
{
    time_t timep;
    struct tm *p;

    time(&timep);   //��ȡ����
    p = localtime(&timep);

    int month = p->tm_mon + 1;
    int day   = p->tm_mday;

    char the_day[20];
    int page = 0;       //ҳ��
    int choose_index = -1;

    while(1)
    {

        //��ʾѡ����Ϣ
        ShowFont::instance()->display((char*)(PersonalInfo::instance()->phone().c_str()), 32, 150, 32, 0x00ffffff, 0x00000000, 320, 74);
        ShowFont::instance()->display((char*)(PersonalInfo::instance()->department_1().c_str()), 32, 150, 32, 0x00ffffff, 0x00000000, 200, 10);
        ShowFont::instance()->display((char*)(PersonalInfo::instance()->department_2().c_str()), 32, 150, 32, 0x00ffffff, 0x00000000, 300, 10);
        ShowFont::instance()->display((char*)(PersonalInfo::instance()->clinic().c_str()), 32, 150, 32, 0x00ffffff, 0x00000000, 450, 10);

        //��ʾҽ����Ϣ
        ShowFont::instance()->display((char*)(doc_5.c_str()), 32, 70, 32, 0x00ffffff, 0x00000000, 360, 160);
        ShowFont::instance()->display((char*)(doc_4.c_str()), 32, 70, 32, 0x00ffffff, 0x00000000, 560, 160);
        ShowFont::instance()->display((char*)(doc_3.c_str()), 32, 70, 32, 0x00ffffff, 0x00000000, 360, 300);
        ShowFont::instance()->display((char*)(doc_6.c_str()), 32, 70, 32, 0x00ffffff, 0x00000000, 560, 300);

        //��ʾ�����ʱ����Ϣ
        for(int i = 0; i < 5; i++)
        {
            sprintf(the_day, "%d%s %d%s", month , _month, day+5*page +i, _day);

            if(i == choose_index)
            {
                ShowFont::instance()->display(the_day, 32, 100, 32, 0x00ffffff, 0x000000ff, 112, 167+i*36);
            }
            else
            {
                ShowFont::instance()->display(the_day, 32, 100, 32, 0x00ffffff, 0x00000000, 112, 167+i*36);
            }


        }


        Point touch_coord(-1, -1);  /* �������� */
        Touch::instance()->wait(touch_coord);


        if(touch_coord.x() > 10 && touch_coord.y() >423 && touch_coord.x() < 110 && touch_coord.y() < 474)
        {//���ذ�ť

            //ǨԽ-event-11
            PR_Fsm::instance()->handleEvent(11);
            return 0;
        }
        else if(touch_coord.x() > 120 && touch_coord.y() > 423 && touch_coord.x() < 219 && touch_coord.y() < 474)
        {//�˳���ť

            //ǨԽ-event-12
            PR_Fsm::instance()->handleEvent(12);
            return 1;

        }

        //ҽ����ť
        if(touch_coord.x() > 280 && touch_coord.y() > 130 && touch_coord.x() < 439 && touch_coord.y() < 239)
        {//ҽ����ť -1
            PersonalInfo::instance()->setDoctor(doc_5);
            //ǨԽ-event-9
            PR_Fsm::instance()->handleEvent(9);
            TimeWidget tw;

            if(tw.exec())
            {
                return 1;
            }
        }
        else if(touch_coord.x() > 482 && touch_coord.y() > 130 && touch_coord.x() < 642 && touch_coord.y() < 239)
        {//ҽ����ť -2
            PersonalInfo::instance()->setDoctor(doc_4);
            //ǨԽ-event-9
            PR_Fsm::instance()->handleEvent(9);
            TimeWidget tw;

            if(tw.exec())
            {
                return 1;
            }
        }
        else if(touch_coord.x() > 280 && touch_coord.y() > 269 && touch_coord.x() < 439 && touch_coord.y() < 379)
        {//ҽ����ť -3
            PersonalInfo::instance()->setDoctor(doc_3);
            //ǨԽ-event-9
            PR_Fsm::instance()->handleEvent(9);
            TimeWidget tw;

            if(tw.exec())
            {
                return 1;
            }

        }
        else if(touch_coord.x() > 482 && touch_coord.y() > 269 && touch_coord.x() < 642 && touch_coord.y() < 379)
        {//ҽ����ť -4
            PersonalInfo::instance()->setDoctor(doc_6);
            //ǨԽ-event-9
            PR_Fsm::instance()->handleEvent(9);
            TimeWidget tw;

            if(tw.exec())
            {
                return 1;
            }

        }

        //������ڰ�ť
        if(touch_coord.x() > 109 && touch_coord.y() > 165 && touch_coord.x() < 231 && touch_coord.y() < 200)
        {//-1

            sprintf(the_day, "%d %s %d %s", month, _month, day+ 0+5*page, _day);
            std::string tmp = the_day;
            PersonalInfo::instance()->setDate(tmp);
            choose_index = 0;
        }
        else if(touch_coord.x() > 109 && touch_coord.y() > 201 && touch_coord.x() < 231 && touch_coord.y() < 236)
        {//-2

            sprintf(the_day, "%d %s %d %s", month, _month, day+ 1+5*page, _day);
            std::string tmp = the_day;
            PersonalInfo::instance()->setDate(tmp);
            choose_index = 1;
        }
        else if(touch_coord.x() > 109 && touch_coord.y() > 236 && touch_coord.x() < 231 && touch_coord.y() < 271)
        {//-3

            sprintf(the_day, "%d %s %d %s", month, _month, day+ 2+5*page, _day);
            std::string tmp = the_day;
            PersonalInfo::instance()->setDate(tmp);
            choose_index = 2;
        }
        else if(touch_coord.x() > 109 && touch_coord.y() > 273 && touch_coord.x() < 231 && touch_coord.y() < 309)
        {//-4

            sprintf(the_day, "%d %s %d %s", month, _month, day+ 3+5*page, _day);
            std::string tmp = the_day;
            PersonalInfo::instance()->setDate(tmp);
            choose_index = 3;
        }
        else if(touch_coord.x() > 109 && touch_coord.y() > 309 && touch_coord.x() < 231 && touch_coord.y() < 344)
        {//-5

            sprintf(the_day, "%d %s %d %s", month, _month, day+ 4+5*page, _day);
            std::string tmp = the_day;
            PersonalInfo::instance()->setDate(tmp);
            choose_index = 4;
        }

        //��ҳ��ť
        if(touch_coord.x() > 111 && touch_coord.y() > 125 && touch_coord.x() < 230 && touch_coord.y() < 161)
        {//��һҳ
            if(page == 0)
            {
                continue;
            }
            else
            {
                page -= 1;
            }

            choose_index = -1;

        }
        else if(touch_coord.x() > 110 && touch_coord.y() > 346 && touch_coord.x() < 229 && touch_coord.y() < 382)
        {//��һҳ
            if(page == 2)
            {
                continue;
            }
            else
            {
                page += 1;
            }

            choose_index = -1;
        }









    }
}
