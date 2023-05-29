#include "personalinfo.h"

PersonalInfo* PersonalInfo::m_instance = NULL;

PersonalInfo::PersonalInfo()
{

}

std::string PersonalInfo::date() const
{
    return m_date;
}

void PersonalInfo::setDate(const std::string &date)
{
    m_date = date;
}

std::string PersonalInfo::doctor() const
{
    return m_doctor;
}

void PersonalInfo::setDoctor(const std::string &doctor)
{
    m_doctor = doctor;
}

std::string PersonalInfo::department_2() const
{
    return m_department_2;
}

void PersonalInfo::setDepartment_2(const std::string &department_2)
{
    m_department_2 = department_2;
}


std::string PersonalInfo::time() const
{
    return m_time;
}

void PersonalInfo::setTime(const std::string &time)
{
    m_time = time;
}

std::string PersonalInfo::clinic() const
{
    return m_clinic;
}

void PersonalInfo::setClinic(const std::string &clinic)
{
    m_clinic = clinic;
}

std::string PersonalInfo::department_1() const
{
    return m_department_1;
}

void PersonalInfo::setDepartment_1(const std::string &department)
{
    m_department_1 = department;
}

int PersonalInfo::insurance_type() const
{
    return m_insurance_type;
}

void PersonalInfo::setInsurance_type(int insurance_type)
{
    m_insurance_type = insurance_type;
}

std::string PersonalInfo::icrad() const
{
    return m_icrad;
}

void PersonalInfo::setIcrad(const std::string &icrad)
{
    m_icrad = icrad;
}

std::string PersonalInfo::phone() const
{
    return m_phone;
}

void PersonalInfo::setPhone(const std::string &phone)
{
    m_phone = phone;
}

std::string PersonalInfo::id() const
{
    return m_id;
}

void PersonalInfo::setId(const std::string &id)
{
    m_id = id;
}



PersonalInfo::~PersonalInfo()
{

}

int PersonalInfo::saveInfoToText()
{
    std::fstream fs;
    fs.open("./resource/data/record.txt", std::ios_base::out | std::ios_base::app);
    if(!fs.is_open())
    {
        std::cout<<"open faild!"<<std::endl;
        return -1;
    }
    fs<<this->m_phone<<'\t'<<this->m_department_1<<'\t'<<this->m_department_2<<'\t'<<this->m_clinic<<'\t'<<this->m_doctor<<'\t'<<this->m_date<<'\t'<<m_time<<'\n';

    fs.close();
    return 0;
}

PersonalInfo *PersonalInfo::instance()
{
    if(m_instance == NULL)
    {
        m_instance = new PersonalInfo();
    }
    return m_instance;
}

void PersonalInfo::del_instance()
{
    delete m_instance;
    m_instance = NULL;
}

std::string PersonalInfo::name() const
{
    return m_name;
}

void PersonalInfo::setName(const std::string &name)
{
    m_name = name;
}
