#include "homeshow.h"
#include "ui_homeshow.h"

HomeShow::HomeShow(const QList<HomeElement *> &elements, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomeShow)
{
    ui->setupUi(this);
}

HomeShow::~HomeShow()
{
    delete ui;
}
