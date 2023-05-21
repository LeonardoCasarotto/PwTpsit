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

    //read directory
    foreach (QFileInfo v, dir.entryInfoList()) {


        //file extension
        QPixmap img;
        if(v.suffix() =="txt"||v.suffix()=="rtf"||v.suffix()=="docx"||v.suffix()=="doc"||v.suffix()=="log"||v.suffix()=="odt"||v.suffix()=="csv"||v.suffix()=="tsv"||v.suffix()=="md"||v.suffix()=="json"){

           img.load("../dependencies/icons/documentFile.png");
        }

        else if(v.suffix()=="png"||v.suffix()=="ico"||v.suffix()=="svg"||v.suffix()=="raw"||v.suffix()=="gif"||v.suffix()=="jpg"||v.suffix()=="jpeg"||v.suffix()=="heic"||v.suffix()=="heif"||v.suffix()=="webp"){
           img.load("../dependencies/icons/image.png");
        }
        else if(v.suffix()=="cpp"||v.suffix()=="h"||v.suffix()=="hpp"||v.suffix()=="c"||v.suffix()==".js"||v.suffix()=="html"||v.suffix()=="rb"||v.suffix()=="css"||v.suffix()=="cs"||v.suffix()=="php"||v.suffix()=="java"||v.suffix()=="asm"||v.suffix()=="sh"||v.suffix()=="bat"){
           img.load("../dependencies/icons/codeFile.png");
        }
        else if(v.suffix()=="zip"||v.suffix()=="tar"||v.suffix()=="gz"||v.suffix()=="7z"){
           img.load("../dependencies/icons/compressedFolder.png");
        }
        else if(v.suffix()=="pdf"){
           img.load("../dependencies/icons/pdfFile.png");
        }
        else if(v.isDir()){
            QDir folderDir(v.absoluteFilePath());
            if(folderDir.isEmpty()){
                img.load("../dependencies/icons/emptyFolder.png");
            }
            else{
                img.load("../dependencies/icons/fullFolder.png");
            }
        }
        else{
            img.load("../dependencies/icons/genericFile.png");
        }



        QIcon icon(img);

        QListWidgetItem* item = new QListWidgetItem(icon,v.fileName());

        if (v.fileName() != "." && v.fileName() != "..") {
            ui->listWidget->addItem(item);
        }
    }

}



