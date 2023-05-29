#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include"point.h"
#include"touch.h"
#include"pr_fsm.h"
#include"loginwidget_1.h"
#include"thread.h"
#include"showfont.h"

class MainWidget:public Thread
{
public:
    MainWidget();

    ~MainWidget();

    int exec();

    void run() override;

};

#endif // MAINWIDGET_H
