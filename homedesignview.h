#ifndef HOMEDESIGNVIEW_H
#define HOMEDESIGNVIEW_H

#include <QGraphicsView>

class HomeDesignView : public QGraphicsView
{
public:
    HomeDesignView(QWidget *parent = 0);

    virtual void fitInView();

protected:
    virtual void	mouseMoveEvent(QMouseEvent * mouseEvent);
    virtual void	mousePressEvent(QMouseEvent * mouseEvent);
    virtual void	mouseReleaseEvent(QMouseEvent * mouseEvent);

    virtual void resizeEvent(QResizeEvent *event);
    virtual void showEvent(QShowEvent *event);

};

#endif // HOMEDESIGNVIEW_H
