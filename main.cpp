#include "mainwindow.h"
#include "minorwindow.h"
#include <QApplication>
#include<QTextCodec>
#include <QDesktopWidget>
#include <stdio.h>
#include <stdlib.h>
#include<QFile>
#include<QTextStream>

void myMessageOutput(QtMsgType type,const QMessageLogContext &context, const QString &msg)
{
    QString txt;
          switch (type) {
          //调试信息提示
          case QtDebugMsg:
                  txt = QString("Debug: %1 from %2,%3,%4").arg(msg).arg(context.file).arg(context.function).arg(context.line);
                  break;

          //一般的warning提示
          case QtWarningMsg:
                  txt = QString("Warning: %1 from %2,%3,%4").arg(msg).arg(context.file).arg(context.function).arg(context.line);
          break;
          //严重错误提示
          case QtCriticalMsg:
                  txt = QString("Critical: %1 from %2,%3,%4").arg(msg).arg(context.file).arg(context.function).arg(context.line);
          break;
          //致命错误提示
          case QtFatalMsg:
                  txt = QString("Fatal: %1 from %2,%3,%4").arg(msg).arg(context.file).arg(context.function).arg(context.line);
                  abort();
          }
     qDebug()<<txt;
    QFile outFile("debuglog.txt");
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream ts(&outFile);
    ts << endl<< txt << endl;
}

int main(int argc, char *argv[])
{
    qInstallMessageHandler(myMessageOutput);
    QApplication a(argc, argv);
    QDesktopWidget *desktop = QApplication::desktop();
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    MainWindow w ;
    //MinorWindow m;
    //w->showMaximized();
    w.show();
    //m.setGeometry(desktop->screenGeometry(1));
    //m.show();

    return a.exec();
}
