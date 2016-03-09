#include <QApplication>
#include "homedesign.h"

int main(int argc, char **argv){
    QApplication a(argc, argv);
    HomeDesign windowDesign;
    windowDesign.show();
    return a.exec();
}
