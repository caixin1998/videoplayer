#ifndef MINORWINDOW_H
#define MINORWINDOW_H

#include "ui_minorwindow.h"
#include "global.h"
namespace Ui {
class MinorWindow;
}

class MinorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MinorWindow(QWidget *parent = nullptr);
    ~MinorWindow();

private:
    Ui::MinorWindow *ui;
    showImage * mplaywindow;
private slots:
    void onShowImage(QImage);
};

#endif // MINORWINDOW_H
