#include "showimage.h"
#include"global.h"

int iw;
int ih;
showImage::showImage(QWidget *parent):QWidget(parent)
{
    showi=new QImage;
    showi->load("D:/Users/caixin/Documents/videoplayer/cover.png");
    iw = showi->width();
    ih = showi->height();
}
showImage::~showImage(){
    delete showi;
}

void showImage::paintEvent(QPaintEvent *e)
{
    static QPainter p(this);
    rw = this->width();
    rh = this->height();
    int w=0,h=0;
    if(iw<=rw && ih<=rh)
    {
        w=iw;
        h=ih;
    }
    else{
        if(iw*rh==rw*ih)
        {
            w=rw;
            h=rh;
        }

        else if(iw*rh>rw*ih)
        {
            w=rw;
            h=rw*ih/iw;
        }
        else
        {
            w=rh *iw/ih;
            h=rh;
        }
    }
    QRect Temp(0,0,w,h);
    p.begin(this);
    p.drawImage(Temp,*showi);
    p.end();
}

void showImage::loadimage(QImage* image)
{
    if(showi==NULL){
        qDebug()<<"error2!";
        return;
    }
    showi=image;
}

void showImage::onShowImage(QImage image)
{

    iw = image.width();
    ih = image.height();
    this->loadimage(&image);
    this->repaint();
    this->show();

}
