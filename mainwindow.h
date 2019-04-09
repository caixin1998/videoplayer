#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"global.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_playButton_clicked();

    void on_pauseButton_clicked();

    void on_closeButton_clicked();

    void on_horizontalSlider_sliderMoved(int position);

    void onTimerOut();

    void on_horizontalSlider_sliderReleased();

    void slider_progress_clicked();

    void on_volumeSlider_valueChanged(int value);

    void handleError();

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
