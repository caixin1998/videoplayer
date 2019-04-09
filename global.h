#ifndef GLOBAL_H
#define GLOBAL_H

#define MAX_PATH 100
#define VIDEO_PATH  "D:/chrome_download/"
#define maxValue  1000
#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMediaPlaylist>
#include <QTimer>
#include "videosurface.h"
#include "showimage.h"
#include <qdebug.h>

extern QMediaPlayer *player;
extern QVideoWidget* videoWidget;
extern QMediaPlaylist *medialist;
extern QString buffer;
extern bool play_state;
extern QTimer * timer;
extern VideoSurface *videoSurface;
extern showImage * playwindow;
extern int iw ;
extern int ih ;
#endif // GLOBAL_H
