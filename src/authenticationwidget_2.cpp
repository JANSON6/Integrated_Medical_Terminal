#include "authenticationwidget_2.h"

AuthenticationWidget::AuthenticationWidget()
{

}
//---------cur-2 next-3
int AuthenticationWidget::exec()
{
    /* �ֻ����� */
    std::string phone(11,' ');
    int pos = 0;
    char ch[2] = "!";



    while(1)
    {
        ShowFont::instance()->display((char*)(phone.c_str()), 32, 280, 34, ShowFont::white, ShowFont::black, 280, 115);

        if(phone.at(10) == ' ')
        {
            ShowFont::instance()->display(ch, 32, 8, 32, ShowFont::white, 0x000000ff, 547, 115);
        }

        Point touch_coord(-1, -1);  /* �������� */

        Touch::instance()->wait(touch_coord);


        if(touch_coord.x() > 10 && touch_coord.y() >423 && touch_coord.x() < 110 && touch_coord.y() < 474)
        {//���ذ�ť

            //ǨԽ-event-11
            PR_Fsm::instance()->handleEvent(11);
            return 0;
        }
        else if(touch_coord.x() > 119 && touch_coord.y() >423 && touch_coord.x() < 220 && touch_coord.y() < 475)
        {//�˳���ť

            //ǨԽ-event-12
            PR_Fsm::instance()->handleEvent(12);
            return 1;
        }
        else if(touch_coord.x() > 688 && touch_coord.y() >423 && touch_coord.x() < 788 && touch_coord.y() < 474)
        {//ȷ�ϰ�ť

            //û�������ֻ��Ų����Խ�����һ��
            if(phone.at(10) == ' ')
            {
                continue;
            }
            PR_Fsm::instance()->handleEvent(3);
            InsuranceWidget iw;

            //�����ֻ���
            PersonalInfo::instance()->setPhone(phone);

            int ret = iw.exec();
            if(ret == 2)
            {
                return 0;
            }
            else if(ret == 1)
            {
                return 1;
            }

        }

        //���ּ�
        if(touch_coord.x() > 264 && touch_coord.y() >288 && touch_coord.x() < 344 && touch_coord.y() < 334)
        {//1

            if(pos == 11)
            {
                continue;
            }
            else if(pos == -1)
            {
                pos = 0;
                phone.at(pos) = '1';
                pos++;
            }
            else if(pos <= 10)
            {
                phone.at(pos) = '1';
                pos++;
            }

        }
        else if(touch_coord.x() > 259 && touch_coord.y() >288 && touch_coord.x() < 439 && touch_coord.y() < 334)
        {//2

            if(pos == 11)
            {
                continue;
            }
            else if(pos == -1)
            {
                pos = 0;
                phone.at(pos) = '2';
                pos++;
            }
            else if(pos <= 10)
            {
                phone.at(pos) = '2';
                pos++;
            }


        }
        else if(touch_coord.x() > 454 && touch_coord.y() >288 && touch_coord.x() < 535 && touch_coord.y() < 334)
        {//3

            if(pos == 11)
            {

                continue;
            }
            else if(pos == -1)
            {
                pos = 0;
                phone.at(pos) = '3';
                pos++;
            }
            else if(pos <= 10)
            {
                phone.at(pos) = '3';
                pos++;
            }

        }
        else if(touch_coord.x() > 264 && touch_coord.y() >235 && touch_coord.x() < 344 && touch_coord.y() < 280)
        {//4

            if(pos == 11)
            {

                continue;
            }
            else if(pos == -1)
            {
                pos = 0;
                phone.at(pos) = '4';
                pos++;
            }
            else if(pos <= 10)
            {
                phone.at(pos) = '4';
                pos++;
            }

        }
        else if(touch_coord.x() > 359 && touch_coord.y() >235 && touch_coord.x() < 439 && touch_coord.y() < 280)
        {//5

            if(pos == 11)
            {

                continue;
            }
            else if(pos == -1)
            {
                pos = 0;
                phone.at(pos) = '5';
                pos++;
            }
            else if(pos <= 10)
            {
                phone.at(pos) = '5';
                pos++;
            }

        }
        else if(touch_coord.x() > 454 && touch_coord.y() >235 && touch_coord.x() < 534 && touch_coord.y() < 280)
        {//6

            if(pos == 11)
            {

                continue;
            }
            else if(pos == -1)
            {
                pos = 0;
                phone.at(pos) = '6';
                pos++;
            }
            else if(pos <= 10)
            {
                phone.at(pos) = '6';
                pos++;
            }

        }
        else if(touch_coord.x() > 264 && touch_coord.y() >180 && touch_coord.x() < 344 && touch_coord.y() < 225)
        {//7

            if(pos == 11)
            {

                continue;
            }
            else if(pos == -1)
            {
                pos = 0;
                phone.at(pos) = '7';
                pos++;
            }
            else if(pos <= 10)
            {
                phone.at(pos) = '7';
                pos++;
            }

        }
        else if(touch_coord.x() > 359 && touch_coord.y() >180 && touch_coord.x() < 439 && touch_coord.y() < 225)
        {//8

            if(pos == 11)
            {

                continue;
            }
            else if(pos == -1)
            {
                pos = 0;
                phone.at(pos) = '8';
                pos++;
            }
            else if(pos <= 10)
            {
                phone.at(pos) = '8';
                pos++;
            }

        }
        else if(touch_coord.x() > 454 && touch_coord.y() >180 && touch_coord.x() < 534 && touch_coord.y() < 225)
        {//9

            if(pos == 11)
            {

                continue;
            }
            else if(pos == -1)
            {
                pos = 0;
                phone.at(pos) = '9';
                pos++;
            }
            else if(pos <= 10)
            {
                phone.at(pos) = '9';
                pos++;
            }

        }
        else if(touch_coord.x() > 359 && touch_coord.y() >342 && touch_coord.x() < 439 && touch_coord.y() < 388)
        {//0

            if(pos == 11)
            {

                continue;
            }
            else if(pos == -1)
            {
                pos = 0;
                phone.at(pos) = '0';
                pos++;
            }
            else if(pos <= 10)
            {
                phone.at(pos) = '0';
                pos++;
            }
        }
        else if(touch_coord.x() > 454 && touch_coord.y() >342 && touch_coord.x() < 534 && touch_coord.y() < 388)
        {//�˸�

            if(pos == -1)
            {
                continue;
            }
            if(pos == 11)
            {
                pos = 10;
                phone.at(pos) = ' ';

            }
            else if(pos >= 0)
            {
                pos--;
                if(pos == -1)
                {
                    continue;
                }
                else
                {
                    phone.at(pos) = ' ';
                }


            }

        }
        else if(touch_coord.x() > 263 && touch_coord.y() >342 && touch_coord.x() < 344 && touch_coord.y() < 388)
        {//���
            pos = 0;
            phone.replace(0, 11, "           ");
        }


    }

}
