/********************************************************************************
** Form generated from reading UI file 'minorwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINORWINDOW_H
#define UI_MINORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MinorWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuMinorWindow;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MinorWindow)
    {
        if (MinorWindow->objectName().isEmpty())
            MinorWindow->setObjectName(QString::fromUtf8("MinorWindow"));
        MinorWindow->resize(800, 600);
        centralwidget = new QWidget(MinorWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MinorWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MinorWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menuMinorWindow = new QMenu(menubar);
        menuMinorWindow->setObjectName(QString::fromUtf8("menuMinorWindow"));
        MinorWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MinorWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MinorWindow->setStatusBar(statusbar);

        menubar->addAction(menuMinorWindow->menuAction());

        retranslateUi(MinorWindow);

        QMetaObject::connectSlotsByName(MinorWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MinorWindow)
    {
        MinorWindow->setWindowTitle(QApplication::translate("MinorWindow", "MainWindow", nullptr));
        menuMinorWindow->setTitle(QApplication::translate("MinorWindow", "MinorWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MinorWindow: public Ui_MinorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINORWINDOW_H
