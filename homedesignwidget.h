#ifndef HOMEDESIGNWIDGET_H
#define HOMEDESIGNWIDGET_H

#include <QGraphicsScene>
#include "homeelement.h"

class HomeDesignWidget : public QGraphicsScene
{
    Q_OBJECT

public:
    HomeDesignWidget(QObject *parent = 0);
    void setCurrentDrawType(HomeElementType type);
    void startDraw(const QPointF &point);
    void drawing(const QPointF &point);
    void finishDraw(const QPointF &point);

    QList <HomeElement *> getElements()const;

protected:
    virtual void wheelEvent(QGraphicsSceneMouseEvent *event);
    virtual void drawBackground(QPainter *painter, const QRectF &rect);

private:
    QPointF fixPoint(const QPointF &point);
    QPointF fixPointSelf(const QPointF &point);
    QPointF fixPointToLine(const QPointF &point, const QLineF *line);

    QGraphicsItem *selectedItem;

    QList <QLineF *> lines;

    bool mousePressed;
    QPointF mousePressedPoint;

    int halfWidth;
    int halfHeight;

    HomeElementType currentElementType;
    HomeElement *currentElement;
};

#endif // HOMEDESIGNWIDGET_H
