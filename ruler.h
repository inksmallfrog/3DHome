#ifndef RULER_H
#define RULER_H

#include <QWidget>

class Ruler : public QWidget
{
    Q_OBJECT
public:
    explicit Ruler(QWidget *parent = 0);
    void scaleStep(float scale){ m_step *= scale; update(); }

protected:
    virtual void paintEvent(QEvent *event){}
    int m_step;

signals:

public slots:
};

#endif // RULER_H
