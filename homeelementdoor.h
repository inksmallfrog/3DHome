#ifndef HOMEELEMENTDOOR_H
#define HOMEELEMENTDOOR_H

#include <QGraphicsLineItem>
#include <homeelement.h>

class HomeElementDoor : public QGraphicsLineItem, public HomeElement
{
public:
    HomeElementDoor();

    virtual void startDraw(QPointF &point);
    virtual void drawing(QPointF &point);
    virtual void finishDraw(QPointF &point);

    virtual QList<QLineF *> getLines()const;
};

#endif // HOMEELEMENTDOOR_H
