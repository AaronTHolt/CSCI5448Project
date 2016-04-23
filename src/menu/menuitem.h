#ifndef MENUITEM_H
#define MENUITEM_H

#include <QtOpenGL>

class MenuItem
{
public:
    MenuItem();
    void setPosition(double x, double y, double z);
    void setDimension(double width, double height);
    void setTexture(unsigned int texture);
    void display();

    double getPositionX();
    double getPositionY();
    double getPositionZ();
    double getWidth();
    double getHeight();

private:
    double m_x;
    double m_y;
    double m_z;
    double m_width;
    double m_height;
    unsigned int m_texture;
};

#endif // MENUITEM_H
