#include "minorwindow.h"


MinorWindow::MinorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MinorWindow)
{
    this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint&~Qt::WindowMinimizeButtonHint);
    mplaywindow = new showImage(this);
    ui->setupUi(this);
    this->setCentralWidget(mplaywindow);
    connect(videoSurface,SIGNAL(showImage(QImage)),this,SLOT(onShowImage(QImage)));
   // player->setVideoOutput(videoWidget_m);

}

MinorWindow::~MinorWindow()
{
    delete ui;
    delete mplaywindow;
}

void MinorWindow::onShowImage(QImage image)
{
    mplaywindow->loadimage(&image);
    mplaywindow->repaint();
    mplaywindow->show();

}
