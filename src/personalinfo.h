#ifndef PERSONALINFO_H
#define PERSONALINFO_H

#include<iostream>
#include<fstream>


class PersonalInfo
{

public:
    ~PersonalInfo();

    int sendInfoToServer(); //把信息发送至服务器
    int saveInfoToText();   //把数据保存到本地文件

    static PersonalInfo* instance();
    static void del_instance();

    //名字
    std::string name() const;
    void setName(const std::string &name);

    //身份证
    std::string id() const;
    void setId(const std::string &id);

    //手机号
    std::string phone() const;
    void setPhone(const std::string &phone);

    //社保卡号
    std::string icrad() const;
    void setIcrad(const std::string &icrad);

    //医保类型
    int insurance_type() const;
    void setInsurance_type(int insurance_type);

    //一级科室
    std::string department_1() const;
    void setDepartment_1(const std::string &department);

    //二级科室
    std::string department_2() const;
    void setDepartment_2(const std::string &department_2);

    //门诊
    std::string clinic() const;
    void setClinic(const std::string &clinic);

    //医生
    std::string doctor() const;
    void setDoctor(const std::string &doctor);

    //就诊日期
    std::string date() const;
    void setDate(const std::string &date);

    //就诊时间
    std::string time() const;
    void setTime(const std::string &time);


private:
    PersonalInfo();

private:

    std::string m_name;         /* 名字 */
    std::string m_id;           /* 身份证 */
    std::string m_phone;        /* 手机号 */
    std::string m_icrad;        /* 社保卡号 */
    int m_insurance_type;       /* 医保类型 */
    std::string m_department_1;   /* 一级科室 */
    std::string m_department_2; /* 二级科室*/
    std::string m_clinic;       /* 选择门诊 */
    std::string m_doctor;       /*选择医生*/
    std::string m_date;         /*就诊日期*/
    std::string m_time;         /* 就诊时间 */

    static PersonalInfo* m_instance;

};

#endif // PERSONALINFO_H
