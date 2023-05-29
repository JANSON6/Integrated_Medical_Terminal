#include "clinicwidget_7.h"

ClinicWidget::ClinicWidget()
{

}

//-----cur-7 next-8
int ClinicWidget::exec()
{


    Departments dm;
    //�Ѷ�Ӧһ�����ҵĶ�������vector������ֵ������book��
    std::vector<std::string> book = dm.departments().find(PersonalInfo::instance()->department_1())->second;

    //�����߽�
    int maxIndex = book.size() - 1;
    int minIndex = 0;
    int chooseIndex = -1;

    while(1)
    {
        //��ʾ�ֻ���
        ShowFont::instance()->display((char*)(PersonalInfo::instance()->phone().c_str()), 32, 150, 32, 0x00ffffff, 0x00000000, 320, 74);
        ShowFont::instance()->display((char*)(PersonalInfo::instance()->department_1().c_str()), 32, 150, 32, 0x00ffffff, 0x00000000, 350, 10);

        for(int i = minIndex, n=0; i < minIndex+5; i++,n++)
        {

            if(i > maxIndex)   //�����Ⱦ�����i���������������������˳�
            {
                ShowFont::instance()->display((char*)" ", 24, 115, 24, 0x00ffffff, 0x00000000, 112, 171+(n*36));
            }
            else
            {
                //ѡ�еĿ�����Ⱦ�ɺ�ɫ����
                if(chooseIndex == i)
                {
                    ShowFont::instance()->display((char*)(book.at(i).c_str()), 24, 115, 24, 0x00ffffff, 0x000000ff, 112, 171+(n*36));
                    PersonalInfo::instance()->setDepartment_2(book.at(chooseIndex));
                }
                else
                {
                    ShowFont::instance()->display((char*)(book.at(i).c_str()), 24, 115, 24, 0x00ffffff, 0x00000000, 112, 171+(n*36));
                }
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

        //���ﰴť
        if(touch_coord.x() > 309 && touch_coord.y() > 162 && touch_coord.x() < 429 && touch_coord.y() < 222)
        {//���ﰴť 1
            PersonalInfo::instance()->setClinic("ROOM-1");

            PR_Fsm::instance()->handleEvent(8);
            DoctorWidget dw;

            if(dw.exec())
            {
                return 1;
            }
        }
        else if(touch_coord.x() > 451 && touch_coord.y() > 162 && touch_coord.x() < 571 && touch_coord.y() < 222)
        {//���ﰴť 2
            PersonalInfo::instance()->setClinic("ROOM-2");

            PR_Fsm::instance()->handleEvent(8);
            DoctorWidget dw;

            if(dw.exec())
            {
                return 1;
            }

        }
        else if(touch_coord.x() > 309 && touch_coord.y() > 247 && touch_coord.x() < 429 && touch_coord.y() < 308)
        {//���ﰴť 3
            PersonalInfo::instance()->setClinic("ROOM-3");

            PR_Fsm::instance()->handleEvent(8);
            DoctorWidget dw;

            if(dw.exec())
            {
                return 1;
            }

        }
        else if(touch_coord.x() > 451 && touch_coord.y() > 247 && touch_coord.x() < 571 && touch_coord.y() < 307)
        {//���ﰴť 4
            PersonalInfo::instance()->setClinic("ROOM-4");

            PR_Fsm::instance()->handleEvent(8);
            DoctorWidget dw;

            if(dw.exec())
            {
                return 1;
            }

        }

        //��������Ŀ¼��ť
        if(touch_coord.x() > 111 && touch_coord.y() > 125 && touch_coord.x() < 230 && touch_coord.y() < 161)
        {//��һҳ
            if(minIndex - 5 < 0)
            {
                minIndex = 0;
            }
            else
            {
                minIndex -= 5;
            }
            std::cout<<"-min = "<<minIndex<<std::endl;
        }
        else if(touch_coord.x() > 110 && touch_coord.y() > 346 && touch_coord.x() < 229 && touch_coord.y() < 382)
        {//��һҳ
            if(minIndex + 5 > maxIndex)
            {

            }
            else
            {
                minIndex += 5;
            }
            std::cout<<"+min = "<<minIndex<<std::endl;
        }
        else if(touch_coord.x() > 110 && touch_coord.y() > 164 && touch_coord.x() < 229 && touch_coord.y() < 200)
        {//Ŀ¼��һ��
            chooseIndex = minIndex;
        }
        else if(touch_coord.x() > 110 && touch_coord.y() > 201 && touch_coord.x() < 229 && touch_coord.y() < 235)
        {//Ŀ¼�ڶ���
            chooseIndex = minIndex+1;
        }
        else if(touch_coord.x() > 110 && touch_coord.y() > 236 && touch_coord.x() < 229 && touch_coord.y() < 270)
        {//Ŀ¼������
            chooseIndex = minIndex+2;
        }
        else if(touch_coord.x() > 110 && touch_coord.y() > 271 && touch_coord.x() < 229 && touch_coord.y() < 306)
        {//Ŀ¼���ĸ�
            chooseIndex = minIndex+3;
        }
        else if(touch_coord.x() > 110 && touch_coord.y() > 307 && touch_coord.x() < 229 && touch_coord.y() < 343)
        {//Ŀ¼�����
            chooseIndex = minIndex+4;
        }


    }
}
