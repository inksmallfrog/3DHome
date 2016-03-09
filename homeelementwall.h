#ifndef HOMEELEMENTWALL_H
#define HOMEELEMENTWALL_H

#include <QGraphicsLineItem>
#include "homeelement.h"

class HomeElementWall : public HomeElement, public QGraphicsLineItem
{
public:
    HomeElementWall();

    virtual void startDraw(QPointF &point);
    virtual void drawing(QPointF &point);
    virtual void finishDraw(QPointF &point);

    virtual QList<QLineF *> getLines()const;
};

#endif // HOMEELEMENTWALL_H
