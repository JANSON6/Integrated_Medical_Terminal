#include "mainwidget_0.h"

MainWidget::MainWidget()
{

}

MainWidget::~MainWidget()
{
    this->stop();
}

//-----cur-0 next-1
int MainWidget::exec()
{
    //显示系统时间
    this->start();

    while(1)
    {
        Point touch_coord(-1, -1);  /* 触摸坐标 */

        Touch::instance()->wait(touch_coord);


        if(touch_coord.x() > 62 && touch_coord.y() >87 && touch_coord.x() < 265 && touch_coord.y() < 190)
        {//门诊挂号按钮

            PR_Fsm::instance()->handleEvent(1);

            //登录界面
            LoginWidget lw;
            lw.exec();
        }

    }

}

void MainWidget::run()
{
    time_t timep;
    struct tm *p;

    int year  ;
    int month ;
    int day  ;

    int hour;
    int min;
    int sec;

    char _date[20];
    char _time[20];


    while(1)
    {
        time(&timep);
        p = localtime(&timep);

        year  = p->tm_year + 1900;
        month = p->tm_mon + 1;
        day   = p->tm_mday;

        hour = p->tm_hour;
        min  = p->tm_min;
        sec  = p->tm_sec;

        sprintf(_date, "%d - %d - %d", year, month, day);

        sprintf(_time, "%d : %d : %d", hour, min, sec);

        ShowFont::instance()->display(_date, 20, 80, 22, 0x00FFFFFF, 0x00000000,720, 5);

        ShowFont::instance()->display(_time, 20, 70, 22, 0x00FFFFFF, 0x00000000,725, 25);
        usleep(200000);
    }

}
