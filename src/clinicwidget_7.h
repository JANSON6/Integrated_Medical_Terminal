#ifndef CLINICWIDGET_H
#define CLINICWIDGET_H

#include<map>

#include"point.h"
#include"touch.h"
#include"pr_fsm.h"
#include"doctorwidget_8.h"
#include"departments.h"
class ClinicWidget
{
public:
    ClinicWidget();

    int exec();
};

#endif // CLINICWIDGET_H
