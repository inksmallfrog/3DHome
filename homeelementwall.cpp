#include "homeelementwall.h"
#include <QPen>
#include <QBrush>
#include <QGraphicsSceneDragDropEvent>
#include <QList>

HomeElementWall::HomeElementWall() :
    QGraphicsLineItem(),
    HomeElement()
{
    setPen(QPen(QBrush(Qt::DiagCrossPattern), 10));
}

void HomeElementWall::startDraw(QPointF &point){
    setLine(QLineF(point, point));
}

void HomeElementWall::drawing(QPointF &point){
    setLine(QLineF(line().p1(), point));
}

void HomeElementWall::finishDraw(QPointF &point){
    setLine(QLineF(line().p1(), point));
}

QList<QLineF *> HomeElementWall::getLines()const{
    QList <QLineF *> list;
    list.append(new QLineF(line()));
    return list;
}
