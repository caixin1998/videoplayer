#ifndef VIDEOSURFACE_H
#define VIDEOSURFACE_H

#include <QObject>
#include<QAbstractVideoSurface>
#include <qdebug.h>
class VideoSurface : public QAbstractVideoSurface
{
    Q_OBJECT
public:
    explicit VideoSurface(QObject *parent = 0);
signals:
    void showImage(QImage img);

protected:
        bool present(const QVideoFrame &frame);
    QList<QVideoFrame::PixelFormat> supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType = QAbstractVideoBuffer::NoHandle) const;
};



#endif // VIDEOSURFACE_H
