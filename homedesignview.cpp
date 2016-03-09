#include "homedesignview.h"
#include "homedesignwidget.h"
#include <QMouseEvent>

HomeDesignView::HomeDesignView(QWidget *parent) :
    QGraphicsView(parent)
{

}

void	HomeDesignView::mousePressEvent(QMouseEvent * mouseEvent){
    ((HomeDesignWidget *)scene())->startDraw(mouseEvent->pos());
}

void	HomeDesignView::mouseReleaseEvent(QMouseEvent * mouseEvent){
    ((HomeDesignWidget *)scene())->finishDraw(mouseEvent->pos());
}

void	HomeDesignView::mouseMoveEvent(QMouseEvent * mouseEvent){
    ((HomeDesignWidget *)scene())->drawing(mouseEvent->pos());
}

void HomeDesignView::resizeEvent(QResizeEvent *) {
    fitInView();
}

void HomeDesignView::showEvent(QShowEvent *) {
    fitInView();
}

void HomeDesignView::fitInView() {
    const QRectF rect = QRectF(-0.5,-0.5, 1, 1);
    setSceneRect(rect);
}
