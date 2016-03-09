#include "homedesignwidget.h"
#include <QPainter>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsLineItem>
#include <iostream>
#include "homeelementwall.h"
#include "homeelementdoor.h"

HomeDesignWidget::HomeDesignWidget(QObject *parent) :
    QGraphicsScene(parent),
    mousePressed(false),
    mousePressedPoint(0, 0),
    selectedItem(NULL),
    currentElementType(HomeElementType_Null),
    currentElement(NULL),
    halfWidth(0),
    halfHeight(0)
{

}

void HomeDesignWidget::setCurrentDrawType(HomeElementType type){
    currentElementType = type;
}

QList <HomeElement *> HomeDesignWidget::getElements()const{
    QList<HomeElement *> elements;
    QListIterator <QGraphicsItem *> i(items());
    while(i.hasNext()){
        elements.append((HomeElement *)i.next());
    }
    return elements;
}

void	HomeDesignWidget::startDraw(const QPointF &point){
    QPointF eventPos = fixPoint(point);

    switch(currentElementType){
    case HomeElementType_Null:
        break;

    case HomeElementType_Wall:
    {
        HomeElementWall *wall = new HomeElementWall();
        addItem(wall);
        currentElement = wall;
        wall->startDraw(eventPos);
        break;
    }

    case HomeElementType_Door:
    {
        HomeElementDoor *door = new HomeElementDoor();
        addItem(door);
        currentElement = door;
        door->startDraw(eventPos);
        break;
    }
    }
    update();
}

void	HomeDesignWidget::	drawing(const QPointF &point){
    QPointF eventPos = fixPoint(point);

    switch (currentElementType) {
    case HomeElementType_Null:
        break;

    default:
        currentElement->finishDraw(eventPos);
        break;
    }
    update();
}

void HomeDesignWidget::finishDraw(const QPointF &point){
    QPointF eventPos = fixPoint(point);

    switch (currentElementType) {
    case HomeElementType_Null:
        break;

    default:
        QListIterator <QLineF *> i(currentElement->getLines());
        while(i.hasNext()){
            lines.append(i.next());
        }
        break;
    }
    update();
}

void HomeDesignWidget::wheelEvent(QGraphicsSceneMouseEvent *event){

}

void HomeDesignWidget::drawBackground(QPainter *painter, const QRectF &rect){
    QPen pen(Qt::black);
    pen.setWidth(1);
    pen.setStyle(Qt::DotLine);
    painter->setPen(pen);
    halfWidth = rect.width() / 2;
    halfHeight = 340;
    for(int i = -halfWidth; i < halfWidth; i += 20){
        painter->drawLine(i, -halfHeight, i, halfHeight);
    }
    for(int i = -halfHeight; i < halfHeight; i += 20){
        painter->drawLine(-halfWidth, i, halfWidth, i);
    }
}

QPointF HomeDesignWidget::fixPoint(const QPointF &point){
    QPointF eventPos = point;

    int x = eventPos.x();
    int y = eventPos.y();
    int dirtaX = x % 20;
    int dirtaY = y % 20;
    if(dirtaX < 6){
        eventPos.setX(eventPos.x() - dirtaX);
    }
    else if(dirtaX > 14){
        eventPos.setX(eventPos.x() + 20 - dirtaX);
    }
    if(dirtaY < 6){
        eventPos.setY(eventPos.y() - dirtaY);
    }
    else if(dirtaY > 14){
        eventPos.setY(eventPos.y() + 20 - dirtaY);
    }
    eventPos.setX(eventPos.x() - halfWidth);
    eventPos.setY(eventPos.y() - halfHeight);

    eventPos = fixPointSelf(eventPos);

    QListIterator <QLineF *> i(lines);
    while(i.hasNext()){
        eventPos = fixPointToLine(eventPos, i.next());
    }

    return eventPos;
}

QPointF HomeDesignWidget::fixPointSelf(const QPointF &point){
    if(currentElement == NULL){
        return point;
    }
    QLineF currentLine(currentElement->getLines()[0]->p1(), point);
    if(currentLine.dx() < 6 && currentLine.dx() > -6){
        return QPointF(currentLine.p1().x(), point.y());
    }
    if(currentLine.dy() < 6 && currentLine.dy() > -6){
        return QPointF(point.x(), currentLine.p1().y());
    }
    return point;
}

QPointF HomeDesignWidget::fixPointToLine(const QPointF &point, const QLineF *line){
    QPointF p0 = line->p1();
    if((p0 - point).manhattanLength() < 10){
        return p0;
    }
    QPointF p1 = line->p2();
    if((p1 - point).manhattanLength() < 10){
        return p1;
    }
    return point;
}

