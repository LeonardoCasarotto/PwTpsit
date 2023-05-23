/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionWiki;
    QAction *actionper_nome;
    QAction *actionPer_Estensione;
    QAction *actionPer_contenuto;
    QWidget *centralwidget;
    QListWidget *listWidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuCerca;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(870, 619);
        actionWiki = new QAction(MainWindow);
        actionWiki->setObjectName("actionWiki");
        actionper_nome = new QAction(MainWindow);
        actionper_nome->setObjectName("actionper_nome");
        actionPer_Estensione = new QAction(MainWindow);
        actionPer_Estensione->setObjectName("actionPer_Estensione");
        actionPer_contenuto = new QAction(MainWindow);
        actionPer_contenuto->setObjectName("actionPer_contenuto");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(0, 0, 861, 571));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 870, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName("menuEdit");
        menuCerca = new QMenu(menuEdit);
        menuCerca->setObjectName("menuCerca");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuEdit->addAction(menuCerca->menuAction());
        menuCerca->addSeparator();
        menuCerca->addSeparator();
        menuCerca->addAction(actionper_nome);
        menuCerca->addAction(actionPer_Estensione);
        menuCerca->addAction(actionPer_contenuto);
        menuHelp->addAction(actionWiki);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionWiki->setText(QCoreApplication::translate("MainWindow", "Wiki", nullptr));
        actionper_nome->setText(QCoreApplication::translate("MainWindow", "Per Nome", nullptr));
        actionPer_Estensione->setText(QCoreApplication::translate("MainWindow", "Per Estensione", nullptr));
        actionPer_contenuto->setText(QCoreApplication::translate("MainWindow", "Per Contenuto", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuCerca->setTitle(QCoreApplication::translate("MainWindow", "Cerca", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
