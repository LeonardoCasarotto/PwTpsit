#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./dependencies/code/searchinputdialog.h"
#include "./dependencies/code/organize.h"
#include "./dependencies/code/search.h"


QDir current;



MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    on_actionScegli_nuova_directory_triggered();

}

MainWindow::~MainWindow()
{
    delete ui;
}



//aggiorna con i risultati ottenuti
void MainWindow::updateDirectory(const QVector<QString>&files)
{
    ui->listWidget->clear();

    for(const QString& fPath : files)
    {
        QFileInfo qi(fPath);

        QPixmap img;
        if(qi.suffix() =="txt"||qi.suffix()=="rtf"||qi.suffix()=="docx"||qi.suffix()=="doc"||qi.suffix()=="log"||qi.suffix()=="odt"||qi.suffix()=="csv"||qi.suffix()=="tsv"||qi.suffix()=="md"||qi.suffix()=="json"){

            img.load("../PwGUI/dependencies/icons/documentFile.png");
        }

        else if(qi.suffix()=="png"||qi.suffix()=="ico"||qi.suffix()=="svg"||qi.suffix()=="raw"||qi.suffix()=="gif"||qi.suffix()=="jpg"||qi.suffix()=="jpeg"||qi.suffix()=="heic"||qi.suffix()=="heif"||qi.suffix()=="webp"){
            img.load("../PwGUI/dependencies/icons/image.png");
        }
        else if(qi.suffix()=="cpp"||qi.suffix()=="h"||qi.suffix()=="hpp"||qi.suffix()=="c"||qi.suffix()=="js"||qi.suffix()=="html"||qi.suffix()=="rb"||qi.suffix()=="css"||qi.suffix()=="cs"||qi.suffix()=="php"||qi.suffix()=="java"||qi.suffix()=="asm"||qi.suffix()=="sh"||qi.suffix()=="bat"){
            img.load("../PwGUI/dependencies/icons/codeFile.png");
        }
        else if(qi.suffix()=="zip"||qi.suffix()=="tar"||qi.suffix()=="gz"||qi.suffix()=="7z"){
            img.load("../PwGUI/dependencies/icons/compressedFolder.png");
        }
        else if(qi.suffix()=="pdf"){
            img.load("../PwGUI/dependencies/icons/pdfFile.png");
        }
        else if(qi.isDir()){
            QDir folderDir(qi.absoluteFilePath());
            if(folderDir.isEmpty()){
                img.load("../PwGUI/dependencies/icons/emptyFolder.png");
            }
            else{
                img.load("../PwGUI/dependencies/icons/fullFolder.png");
            }
        }
        else{
            img.load("../PwGUI/dependencies/icons/genericFile.png");
        }

        QIcon icon(img);
        //here
        QListWidgetItem* item = new QListWidgetItem(icon,qi.filePath());

        if (qi.fileName() != "." && qi.fileName() != "..") {
            ui->listWidget->addItem(item);
        }
    }

}

//funzione iniziale

void MainWindow::displayDirectory(const QString& newText)
{
    QDir dir(newText);

    //read directory
    ui->listWidget->clear();
    foreach (QFileInfo v, dir.entryInfoList()) {


        //file extension
        QPixmap img;
        if(v.suffix() =="txt"||v.suffix()=="rtf"||v.suffix()=="docx"||v.suffix()=="doc"||v.suffix()=="log"||v.suffix()=="odt"||v.suffix()=="csv"||v.suffix()=="tsv"||v.suffix()=="md"||v.suffix()=="json"){

           img.load("../PwGUI/dependencies/icons/documentFile.png");
        }

        else if(v.suffix()=="png"||v.suffix()=="ico"||v.suffix()=="svg"||v.suffix()=="raw"||v.suffix()=="gif"||v.suffix()=="jpg"||v.suffix()=="jpeg"||v.suffix()=="heic"||v.suffix()=="heif"||v.suffix()=="webp"){
           img.load("../PwGUI/dependencies/icons/image.png");
        }
        else if(v.suffix()=="cpp"||v.suffix()=="h"||v.suffix()=="hpp"||v.suffix()=="c"||v.suffix()=="js"||v.suffix()=="html"||v.suffix()=="rb"||v.suffix()=="css"||v.suffix()=="cs"||v.suffix()=="php"||v.suffix()=="java"||v.suffix()=="asm"||v.suffix()=="sh"||v.suffix()=="bat"){
           img.load("../PwGUI/dependencies/icons/codeFile.png");
        }
        else if(v.suffix()=="zip"||v.suffix()=="tar"||v.suffix()=="gz"||v.suffix()=="7z"){
           img.load("../PwGUI/dependencies/icons/compressedFolder.png");
        }
        else if(v.suffix()=="pdf"){
           img.load("../PwGUI/dependencies/icons/pdfFile.png");
        }
        else if(v.isDir()){
            QDir folderDir(v.absoluteFilePath());
            if(folderDir.isEmpty()){
                img.load("../PwGUI/dependencies/icons/emptyFolder.png");
            }
            else{
                img.load("../PwGUI/dependencies/icons/fullFolder.png");
            }
        }
        else{
            img.load("../PwGUI/dependencies/icons/genericFile.png");
        }



        QIcon icon(img);

        QListWidgetItem* item = new QListWidgetItem(icon,v.fileName());

        if (v.fileName() != "." && v.fileName() != "..") {
            ui->listWidget->addItem(item);
        }
    }

}




//open wiki
void MainWindow::on_actionWiki_triggered()
{
    QDesktopServices::openUrl(QUrl("https://github.com/LeonardoCasarotto/PwTpsit/wiki"));
}


//searchbyname
void MainWindow::on_actionper_nome_triggered()
{
    QString fileName;
    bool includeSubfolders;

    SearchInputDialog::getCheckboxValue(nullptr, 0, fileName, includeSubfolders);


    QMessageBox test;
    QVector<QString> result;

    if(fileName==""||fileName==" ")
    {
        return;
    }
    else if(!includeSubfolders)
    {
       result = simpleSearchByName(current,fileName);

    }
    else if(includeSubfolders)
    {

       result = dfsFileSearchByName(current, fileName);

    }
        updateDirectory(result);

    return;


}





//search by extension
void MainWindow::on_actionPer_Estensione_triggered()
{
    QString fileExtension;
    bool includeSubfolders;
    QVector<QString> result;

    SearchInputDialog::getCheckboxValue(nullptr, 1, fileExtension, includeSubfolders);

    if(fileExtension=="" || fileExtension.contains(" ")||fileExtension.contains(".")){
       return;
    }
    else if(!includeSubfolders) result = simpleSearchByExtension(current,fileExtension);
    else if(includeSubfolders) result = dfsFileSearchByExtension(current,fileExtension);

    updateDirectory(result);

    return;

}




void MainWindow::on_actionScegli_nuova_directory_triggered()
{
    ui->listWidget->clear();
    QString dir = QFileDialog::getExistingDirectory(nullptr,
                                                    QObject::tr("Selezionare la cartella iniziale"),
                                                    "/home",
                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    current = dir;
    ui->lineEdit->setText(current.absolutePath());
    displayDirectory(dir);

}


void MainWindow::on_actionPer_contenuto_triggered()
{
    QString word;
    bool includeSubfolders;
    QVector<QString> result;

    SearchInputDialog::getCheckboxValue(nullptr, 2, word, includeSubfolders);

    if(word=="" || word == " "){
       return;
    }
    else if(!includeSubfolders) result = simpleSearchByContent(current,word);
    else if(includeSubfolders) result = dfsFileSearchByContent(current,word);

    updateDirectory(result);

    return;
}


void MainWindow::on_actionOrdine_Alfabetico_triggered()
{
    organizeFilesByAlphabet(current);
    displayDirectory(current.absolutePath());
}


void MainWindow::on_actionEstensione_triggered()
{
    organizeFilesByType(current);
    displayDirectory(current.absolutePath());
}




void MainWindow::on_actionProprietario_triggered()
{
    organizeFilesByOwner(current);
    displayDirectory(current.absolutePath());
}


void MainWindow::on_actionDimensione_triggered()
{
    organizeFilesBySize(current);
    displayDirectory(current.absolutePath());
}

