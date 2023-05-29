#ifndef PERSONALINFO_H
#define PERSONALINFO_H

#include<iostream>
#include<fstream>


class PersonalInfo
{

public:
    ~PersonalInfo();

    int sendInfoToServer(); //����Ϣ������������
    int saveInfoToText();   //�����ݱ��浽�����ļ�

    static PersonalInfo* instance();
    static void del_instance();

    //����
    std::string name() const;
    void setName(const std::string &name);

    //���֤
    std::string id() const;
    void setId(const std::string &id);

    //�ֻ���
    std::string phone() const;
    void setPhone(const std::string &phone);

    //�籣����
    std::string icrad() const;
    void setIcrad(const std::string &icrad);

    //ҽ������
    int insurance_type() const;
    void setInsurance_type(int insurance_type);

    //һ������
    std::string department_1() const;
    void setDepartment_1(const std::string &department);

    //��������
    std::string department_2() const;
    void setDepartment_2(const std::string &department_2);

    //����
    std::string clinic() const;
    void setClinic(const std::string &clinic);

    //ҽ��
    std::string doctor() const;
    void setDoctor(const std::string &doctor);

    //��������
    std::string date() const;
    void setDate(const std::string &date);

    //����ʱ��
    std::string time() const;
    void setTime(const std::string &time);


private:
    PersonalInfo();

private:

    std::string m_name;         /* ���� */
    std::string m_id;           /* ���֤ */
    std::string m_phone;        /* �ֻ��� */
    std::string m_icrad;        /* �籣���� */
    int m_insurance_type;       /* ҽ������ */
    std::string m_department_1;   /* һ������ */
    std::string m_department_2; /* ��������*/
    std::string m_clinic;       /* ѡ������ */
    std::string m_doctor;       /*ѡ��ҽ��*/
    std::string m_date;         /*��������*/
    std::string m_time;         /* ����ʱ�� */

    static PersonalInfo* m_instance;

};

#endif // PERSONALINFO_H
