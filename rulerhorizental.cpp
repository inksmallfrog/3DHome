#include "rulerhorizental.h"
#include <QPainter>

RulerHorizental::RulerHorizental(QWidget *parent) : Ruler(parent)
{

}

void RulerHorizental::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setFont(QFont("Helvetica [Cronyx]", 7));
    int currentNumber = 0;
    for(int i = 0; i < (rect().width()); i += 20){
        painter.drawText(QRectF(i, 13, 19, rect().height()), QString::number(currentNumber));
        currentNumber += m_step;
    }
    painter.setPen(Qt::white);
    painter.drawLine(0, 31, rect().width(), 31);
}


