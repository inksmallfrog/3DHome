#include "homedesign.h"
#include "ui_homedesign.h"
#include <QAction>
#include <QToolBar>
#include "homedesignwidget.h"
#include "homeelement.h"
#include "homeshow.h"

HomeDesign::HomeDesign(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomeDesign)
{
    ui->setupUi(this);

    initToolBar();
    ui->designView->setScene(new HomeDesignWidget(this));
}

HomeDesign::~HomeDesign()
{
    delete ui;
}

void HomeDesign::initToolBar(){
    QActionGroup *toolBarActionGroup = new QActionGroup(ui->toolBar);
    QAction *dragAction = new QAction("Drag", toolBarActionGroup);
    QAction *createWallAction = new QAction("Wall", toolBarActionGroup);
    QAction *createRoomAction = new QAction("Room", toolBarActionGroup);
    QAction *createDoorAction = new QAction("Door", toolBarActionGroup);
    QAction *createWindowAction = new QAction("Window", toolBarActionGroup);
    QAction *build3D = new QAction("Build", toolBarActionGroup);
    dragAction->setCheckable(true);
    createWallAction->setCheckable(true);
    createRoomAction->setCheckable(true);
    createDoorAction->setCheckable(true);
    createWindowAction->setCheckable(true);
    build3D->setCheckable(true);

    connect(createWallAction, SIGNAL(triggered()), this, SLOT(onCreateWall()));
    connect(createDoorAction, SIGNAL(triggered()), this, SLOT(onCreateDoor()));
    connect(build3D, SIGNAL(triggered()), this, SLOT(build3DHome()));

   ui->toolBar->addActions(toolBarActionGroup->actions());
   dragAction->setChecked(true);
}

void HomeDesign::onCreateWall(){
    ((HomeDesignWidget *)(ui->designView->scene()))->setCurrentDrawType(HomeElementType_Wall);
}

void HomeDesign::onCreateDoor(){
    ((HomeDesignWidget *)(ui->designView->scene()))->setCurrentDrawType(HomeElementType_Door);
}

void HomeDesign::build3DHome(){
    this->hide();
    HomeShow *homeShow = new HomeShow(((HomeDesignWidget *)ui->designView->scene())->getElements());
    homeShow->show();
}
