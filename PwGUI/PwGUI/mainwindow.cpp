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


    ui->label->setText(dir);





}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateLabelText(const QString& newText)
{
    ui->label->setText(newText);
}

void MainWindow::displayDirectory(const QString& newText)
{
    QDir dir(newText);

    QStringList files = directory.entryList(QDir::Files);
    qDebug() << "Files:";
    for (const QString& file : files) {
        qDebug() << file;
}

