#include "homeelementdoor.h"
#include <QPen>
#include <QBrush>
#include <QList>
#include <QGraphicsSceneDragDropEvent>

HomeElementDoor::HomeElementDoor() :
    QGraphicsLineItem(),
    HomeElement()
{
    setPen(QPen(QBrush(Qt::CrossPattern), 13));
}

void HomeElementDoor::startDraw(QPointF &point){
    setLine(QLineF(point, point));
}

void HomeElementDoor::drawing(QPointF &point){
    setLine(QLineF(line().p1(), point));
}

void HomeElementDoor::finishDraw(QPointF &point){
    setLine(QLineF(line().p1(), point));
}

QList<QLineF *> HomeElementDoor::getLines()const{
    QList <QLineF *> list;
    list.append(new QLineF(line()));
    return list;
}
