#include "rulervertical.h"
#include <QPainter>

RulerVertical::RulerVertical(QWidget *parent) : Ruler(parent)
{

}

void RulerVertical::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setFont(QFont("Helvetica [Cronyx]", 7));
    int currentNumber = 0;
    for(int i = 0; i < (rect().height()); i += 20){
        painter.drawText(QRectF(13, i, rect().width(), 19), QString::number(currentNumber));
        currentNumber += m_step;
    }
    painter.setPen(Qt::white);
    painter.drawLine(31, 0, 31, rect().height());
}
