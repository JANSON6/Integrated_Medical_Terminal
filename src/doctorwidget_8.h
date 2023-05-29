#ifndef DOCTORWIDGET_H
#define DOCTORWIDGET_H

#include<time.h>
#include<vector>

#include"point.h"
#include"touch.h"
#include"pr_fsm.h"
#include"timewidget_9.h"
#include"text.h"

class DoctorWidget
{
public:
    DoctorWidget();

    int exec();
};

#endif // DOCTORWIDGET_H
