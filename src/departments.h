#ifndef DEPARTMENTS_H
#define DEPARTMENTS_H
#include<fstream>
#include<string.h>
#include"text.h"
#include<unistd.h>

class Departments
{
public:
    Departments();
    ~Departments();
    void show();
    std::map<std::string, std::vector<std::string> > departments() const;

private:
    std::map<std::string, std::vector<std::string>> m_departments;
};

#endif // DEPARTMENTS_H
