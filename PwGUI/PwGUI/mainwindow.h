#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFileDialog>
#include <QLabel>
#include <QPixmap>
#include <QListWidgetItem>
#include <QDesktopServices>
#include "searchinputdialog.h"
#include <QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void displayDirectory(const QString& newText);
    void updateDirectory(const QVector<QString>&files);


private slots:
    void on_actionWiki_triggered();

    void on_actionper_nome_triggered();

    void on_actionPer_Estensione_triggered();

    void on_actionScegli_nuova_directory_triggered();

    void on_actionPer_contenuto_triggered();

    void on_actionOrdine_Alfabetico_triggered();

    void on_actionEstensione_triggered();

    void on_actionProprietario_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

