#include "qrulertipwidget.h"
#include <QPainter>

QRulerTipWidget::QRulerTipWidget(QWidget *parent) : QWidget(parent)
{

}

void QRulerTipWidget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setPen(QPen(Qt::white));
    QRect widgetRect(rect());
    painter.drawLine(0, 0, widgetRect.width(), widgetRect.height());
    painter.drawLine(0, widgetRect.height()-1, widgetRect.width(), widgetRect.height()-1);
    painter.drawLine(widgetRect.width() - 1, 0, widgetRect.width()-1, widgetRect.height());
    painter.drawText(QRectF(16, 0, 16, 16), "x");
    painter.drawText(QRectF(6, 10, 16, 16), "y");
}


