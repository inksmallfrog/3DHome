#ifndef QHORIZENTALRULER_H
#define QHORIZENTALRULER_H

#include "ruler.h"

class RulerHorizental : public Ruler
{
    Q_OBJECT
public:
    explicit RulerHorizental(QWidget *parent = 0);

protected:
    virtual void paintEvent(QPaintEvent *event);

signals:

public slots:
};

#endif // QHORIZENTALRULER_H
