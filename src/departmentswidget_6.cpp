#include "departmentswidget_6.h"

DepartmentsWidget::DepartmentsWidget()
{

}

//-----cur-6 next-7
int DepartmentsWidget::exec()
{
    //һ������
    std::string department;

    while(1)
    {
        //��ʾ�ֻ���
        ShowFont::instance()->display((char*)(PersonalInfo::instance()->phone().c_str()), 32, 150, 32, 0x00ffffff, 0x00000000, 320, 74);

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


        //����

        if(touch_coord.x() > 158 && touch_coord.y() > 192 && touch_coord.x() < 241 && touch_coord.y() < 237)
        {//1�ڿ�
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
        {//2���
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
        {//3��ٿ�
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
        {//4����
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
        {//5����
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
        {//6������
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
        {//7��Ⱦ��
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
        {//8�п�
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
        {//9��ҽ��
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
        {//10Ƥ����
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
        {//11�����
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
        {//12�񾭿�
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
