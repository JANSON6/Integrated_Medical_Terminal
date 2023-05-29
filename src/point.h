/*
 * 坐标类
*/
#ifndef POINT_H
#define POINT_H

class Point
{

public:
    Point(int x, int y);
    ~Point();

    //比较坐标
    bool operator==(const Point p);

    int x() const;
    int y() const;

    void setX(int x);
    void setY(int y);

private:
    int m_x;    /* x坐标 */
    int m_y;    /* y坐标 */
};


#endif // POINT_H
