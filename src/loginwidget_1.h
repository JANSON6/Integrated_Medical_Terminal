#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include"point.h"
#include"touch.h"
#include"pr_fsm.h"
#include"authenticationwidget_2.h"
class LoginWidget
{
public:
    LoginWidget();

    int exec();
};

#endif // LOGINWIDGET_H
