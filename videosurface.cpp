#include "videosurface.h"
#include<QPixmap>
VideoSurface::VideoSurface(QObject *parent) : QAbstractVideoSurface(parent)
{

}

QList<QVideoFrame::PixelFormat> VideoSurface::supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType) const
{
    Q_UNUSED(handleType);
    QList<QVideoFrame::PixelFormat> listPixelFormats;
    listPixelFormats << QVideoFrame::Format_RGB32;
        return listPixelFormats;

}

 bool VideoSurface::present(const QVideoFrame &frame)
 {



     if (frame.isValid())
         {
             QVideoFrame cloneFrame(frame);
             if(!cloneFrame.map(QAbstractVideoBuffer::ReadOnly))
             {
                qDebug()<<"error0!";
                setError(ResourceError);
                return false;
             }
             //qDebug() << "pixelFormat :" << frame.pixelFormat();
             QImage recvImage(frame.bits(), frame.width(), frame.height(), QVideoFrame::imageFormatFromPixelFormat(frame.pixelFormat()));
             //qDebug() << "frame data size :" << frame.mappedBytes();
             cloneFrame.unmap();
             emit showImage(recvImage);
             return true;
         }

         return false;

 }

