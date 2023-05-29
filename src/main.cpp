#include <iostream>
#include"pr_fsm.h"
#include"mainwidget_0.h"
using namespace std;

int main()
{
    PR_Fsm::instance();
    MainWidget widget;
    widget.exec();
}
