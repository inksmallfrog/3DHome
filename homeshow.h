#ifndef HOMESHOW_H
#define HOMESHOW_H

#include <QMainWindow>
#include "homeelement.h"

namespace Ui {
class HomeShow;
}

class HomeShow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomeShow(const QList <HomeElement *> &lines, QWidget *parent = 0);
    ~HomeShow();

private:
    Ui::HomeShow *ui;
};

#endif // HOMESHOW_H
