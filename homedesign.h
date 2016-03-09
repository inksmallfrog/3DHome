#ifndef HOMEDESIGN_H
#define HOMEDESIGN_H

#include <QMainWindow>

namespace Ui {
class HomeDesign;
}

class HomeDesign : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomeDesign(QWidget *parent = 0);
    ~HomeDesign();

public slots:
    void onCreateWall();
    void onCreateDoor();
    void build3DHome();

private:
    void initToolBar();
    void initRuler();
    void initVerticalRuler();
    void initHorizentalRuler();
    Ui::HomeDesign *ui;
};

#endif // HOMEDESIGN_H
