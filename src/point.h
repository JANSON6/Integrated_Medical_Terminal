/*
 * ������
*/
#ifndef POINT_H
#define POINT_H

class Point
{

public:
    Point(int x, int y);
    ~Point();

    //�Ƚ�����
    bool operator==(const Point p);

    int x() const;
    int y() const;

    void setX(int x);
    void setY(int y);

private:
    int m_x;    /* x���� */
    int m_y;    /* y���� */
};


#endif // POINT_H
