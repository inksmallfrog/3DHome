#ifndef HOMEELEMENT_H
#define HOMEELEMENT_H

#include <QGraphicsItem>

enum HomeElementType{
    HomeElementType_Wall,
    HomeElementType_Room,
    HomeElementType_Door,
    HomeElementType_Window,
    HomeElementType_Null
};

class HomeElement
{
public:
    HomeElement();
    static int s_id;

public:
    virtual void startDraw(QPointF &point) = 0;
    virtual void drawing(QPointF &point) = 0;
    virtual void finishDraw(QPointF &point) = 0;
    virtual QList<QLineF *> getLines()const = 0;

protected:
    int m_id;
};

#endif // HOMEELEMENT_H
