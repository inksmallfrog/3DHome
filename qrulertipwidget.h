#ifndef QRULERTIPWIDGET_H
#define QRULERTIPWIDGET_H

#include <QWidget>

class QRulerTipWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QRulerTipWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);

signals:

public slots:
};

#endif // QRULERTIPWIDGET_H
