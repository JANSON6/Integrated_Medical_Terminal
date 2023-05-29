#include "clinicwidget_7.h"

ClinicWidget::ClinicWidget()
{

}

//-----cur-7 next-8
int ClinicWidget::exec()
{


    Departments dm;
    //把对应一级科室的二级科室vector容器赋值给容器book。
    std::vector<std::string> book = dm.departments().find(PersonalInfo::instance()->department_1())->second;

    //索引边界
    int maxIndex = book.size() - 1;
    int minIndex = 0;
    int chooseIndex = -1;

    while(1)
    {
        //显示手机号
        ShowFont::instance()->display((char*)(PersonalInfo::instance()->phone().c_str()), 32, 150, 32, 0x00ffffff, 0x00000000, 320, 74);
        ShowFont::instance()->display((char*)(PersonalInfo::instance()->department_1().c_str()), 32, 150, 32, 0x00ffffff, 0x00000000, 350, 10);

        for(int i = minIndex, n=0; i < minIndex+5; i++,n++)
        {

            if(i > maxIndex)   //这次渲染字体的i索引如果等于最大索引则退出
            {
                ShowFont::instance()->display((char*)" ", 24, 115, 24, 0x00ffffff, 0x00000000, 112, 171+(n*36));
            }
            else
            {
                //选中的科室渲染成红色字体
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

        //门诊按钮
        if(touch_coord.x() > 309 && touch_coord.y() > 162 && touch_coord.x() < 429 && touch_coord.y() < 222)
        {//门诊按钮 1
            PersonalInfo::instance()->setClinic("ROOM-1");

            PR_Fsm::instance()->handleEvent(8);
            DoctorWidget dw;

            if(dw.exec())
            {
                return 1;
            }
        }
        else if(touch_coord.x() > 451 && touch_coord.y() > 162 && touch_coord.x() < 571 && touch_coord.y() < 222)
        {//门诊按钮 2
            PersonalInfo::instance()->setClinic("ROOM-2");

            PR_Fsm::instance()->handleEvent(8);
            DoctorWidget dw;

            if(dw.exec())
            {
                return 1;
            }

        }
        else if(touch_coord.x() > 309 && touch_coord.y() > 247 && touch_coord.x() < 429 && touch_coord.y() < 308)
        {//门诊按钮 3
            PersonalInfo::instance()->setClinic("ROOM-3");

            PR_Fsm::instance()->handleEvent(8);
            DoctorWidget dw;

            if(dw.exec())
            {
                return 1;
            }

        }
        else if(touch_coord.x() > 451 && touch_coord.y() > 247 && touch_coord.x() < 571 && touch_coord.y() < 307)
        {//门诊按钮 4
            PersonalInfo::instance()->setClinic("ROOM-4");

            PR_Fsm::instance()->handleEvent(8);
            DoctorWidget dw;

            if(dw.exec())
            {
                return 1;
            }

        }

        //二级科室目录按钮
        if(touch_coord.x() > 111 && touch_coord.y() > 125 && touch_coord.x() < 230 && touch_coord.y() < 161)
        {//上一页
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
        {//下一页
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
        {//目录第一个
            chooseIndex = minIndex;
        }
        else if(touch_coord.x() > 110 && touch_coord.y() > 201 && touch_coord.x() < 229 && touch_coord.y() < 235)
        {//目录第二个
            chooseIndex = minIndex+1;
        }
        else if(touch_coord.x() > 110 && touch_coord.y() > 236 && touch_coord.x() < 229 && touch_coord.y() < 270)
        {//目录第三个
            chooseIndex = minIndex+2;
        }
        else if(touch_coord.x() > 110 && touch_coord.y() > 271 && touch_coord.x() < 229 && touch_coord.y() < 306)
        {//目录第四个
            chooseIndex = minIndex+3;
        }
        else if(touch_coord.x() > 110 && touch_coord.y() > 307 && touch_coord.x() < 229 && touch_coord.y() < 343)
        {//目录第五个
            chooseIndex = minIndex+4;
        }


    }
}
