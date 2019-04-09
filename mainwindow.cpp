#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customslider.h"
#include<cstring>
#include<iostream>
using namespace  std;

QMediaPlayer *player;
QVideoWidget* videoWidget;
QMediaPlaylist *medialist;
QString buffer =VIDEO_PATH;
bool play_state;
QTimer * timer;
VideoSurface *videoSurface;
showImage * playwindow;
MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this, QMediaPlayer::VideoSurface);
    player->setAudioRole(QAudio::VideoRole);
    videoWidget = new QVideoWidget;
    playwindow = new showImage(this);
    videoSurface = new VideoSurface;
    //this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint&~Qt::WindowMinimizeButtonHint);
    //this->setFixedSize(this->width(),this->height());
    //videoWidget->setGeometry(50,100,720,480);
    //player->setVideoOutput(videoWidget);
    playwindow->setGeometry(50,100,720,480);
    player->setVideoOutput(videoSurface);
    medialist=new QMediaPlaylist;
    medialist->addMedia(QMediaContent(QUrl(buffer+"SampleVideo.mp4")));
    medialist->addMedia(QMediaContent(QUrl(buffer+"SampleVideo2.mp4")));
    //medialist->addMedia(QMediaContent(QUrl(buffer+"SampleVideo3.mp4")));
    medialist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    player->setPlaylist(medialist);
    player->setVolume(ui->volumeSlider->value());
    ui->volumeSlider->setValue(50);
    ui->horizontalSlider->setRange(0,maxValue);
    timer = new QTimer();
    timer->setInterval(1000);
    connect(ui->horizontalSlider,&customSlider::costomSliderClicked ,this,&MainWindow::slider_progress_clicked);
    connect(videoSurface,SIGNAL(showImage(QImage)),playwindow,SLOT(onShowImage(QImage)));
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerOut()));
    connect(player, QOverload<QMediaPlayer::Error>::of(&QMediaPlayer::error),
            this, &MainWindow::handleError);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete player;
    delete videoWidget;
    delete videoSurface;
    delete timer;
    delete medialist;
    delete playwindow;
}

void MainWindow::onTimerOut()
{
    ui->horizontalSlider->setValue(player->position()*maxValue/player->duration());
}



void MainWindow::on_playButton_clicked()
{

    int index=ui->playlist->currentIndex();
    play_state = true;
    medialist->setCurrentIndex(index-1);
    //videoWidget->show();
    ui->pauseButton->setText("暂停");
    timer->start();
    player->play();


}

void MainWindow::on_pauseButton_clicked()
{
    if(play_state)
       {
           player->pause();
           ui->pauseButton->setText("播放");
       }
       else
       {
           player->play();
           ui->pauseButton->setText("暂停");
       }

       play_state = !play_state;

}

void MainWindow::on_closeButton_clicked()
{
    player->stop();
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    timer->stop();
    player->setPosition(ui->horizontalSlider->value()*player->duration()/maxValue);
}

void MainWindow::on_horizontalSlider_sliderReleased()
{
    timer->start();
}

void MainWindow::slider_progress_clicked()
{
    player->setPosition(ui->horizontalSlider->value()*player->duration()/maxValue);
}

void MainWindow::on_volumeSlider_valueChanged(int value)
{
    player->setVolume(value);
}

void MainWindow::handleError()
{
    qDebug()<<player->errorString();
}
