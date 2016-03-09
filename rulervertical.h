#ifndef QVERTICALRULER_H
#define QVERTICALRULER_H

#include "ruler.h"

class RulerVertical : public Ruler
{
    Q_OBJECT
public:
    explicit RulerVertical(QWidget *parent = 0);

protected:
    virtual void paintEvent(QPaintEvent *event);

signals:

public slots:
};

#endif // QVERTICALRULER_H
