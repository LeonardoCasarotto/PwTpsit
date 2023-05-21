#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString dir = QFileDialog::getExistingDirectory(nullptr,
                                                    QObject::tr("Selezionare la cartella iniziale"),
                                                    "/home",
                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    displayDirectory(dir);






}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::displayDirectory(const QString& newText)
{
    QDir dir(newText);

    foreach (QFileInfo v, dir.entryInfoList()) {


        QMimeDatabase mimeDatabase;
        QMimeType mimeType = mimeDatabase.mimeTypeForFile(v.filePath());

        if (v.fileName() != "." && v.fileName() != "..") {
            ui->listWidget->addItem(v.fileName()+"\t"+"MIME type:"+mimeType.comment());
        }
    }

}

