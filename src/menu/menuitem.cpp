#include "menuitem.h"

MenuItem::MenuItem()
{

}

void MenuItem::setPosition(double x, double y, double z)
{
    m_x = x;
    m_y = y;
    m_z = z;
}

void MenuItem::setDimension(double width, double height)
{
    m_width = width / 2.0;
    m_height = height / 2.0;
}

void MenuItem::setTexture(unsigned int texture)
{
    m_texture = texture;
}

double MenuItem::getPositionX()
{
    return m_x;
}

double MenuItem::getPositionY()
{
    return m_y;
}

double MenuItem::getPositionZ()
{
    return m_z;
}

double MenuItem::getWidth()
{
    return m_width * 2.0;
}

double MenuItem::getHeight()
{
    return m_height * 2.0;
}

void MenuItem::display()
{
    glPushMatrix();

    glColor3f(1,1,1);
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, m_texture);

    glBegin(GL_QUADS);
    glNormal3f(0, 0, -1);
    glTexCoord2f(0.0, 0.0); glVertex3f(m_x + -m_width, m_y + -m_height, m_z);
    glTexCoord2f(1.0, 0.0); glVertex3f(m_x + m_width, m_y + -m_height, m_z);
    glTexCoord2f(1.0, 1.0); glVertex3f(m_x + m_width, m_y + m_height, m_z);
    glTexCoord2f(0.0, 1.0); glVertex3f(m_x + -m_width, m_y + m_height, m_z);
    glEnd();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}
