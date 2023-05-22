#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "searchinputdialog.h"

QDir current;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString dir = QFileDialog::getExistingDirectory(nullptr,
                                                    QObject::tr("Selezionare la cartella iniziale"),
                                                    "/home",
                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    current = dir;
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




void MainWindow::on_actionWiki_triggered()
{
    QDesktopServices::openUrl(QUrl("https://github.com/LeonardoCasarotto/PwTpsit/wiki"));
}


void MainWindow::on_actionper_nome_triggered()
{
    QString fileName;
    bool includeSubfolders;

    bool ok = SearchInputDialog::getCheckboxValue(nullptr, 0, fileName, includeSubfolders);

    if(fileName==""||fileName==" ")
    {
        return;
    }
    else if(!includeSubfolders)
    {
        simpleSearchByName(current,fileName)
    }


}

//search methods

//search by name

QString dfsFileSearchByName(const QDir& dir, const QString& filename)
{


    // Controlla se il nome del file corrente corrisponde al nome cercato
    QStringList files = dir.entryList(QStringList() << "*", QDir::Files);
    foreach (const QString& file, files) {
        if (file == filename) {
            return dir.absoluteFilePath(file);
        }
    }

    // Esegui la ricerca DFS nelle sottodirectory
    QStringList subdirectories = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    foreach (const QString& subdirectory, subdirectories) {
        QString newPath = dir.absoluteFilePath(subdirectory);
        QString filePath = dfsFileSearchByName(newPath, filename);
        if (!filePath.isEmpty()) {
            return filePath;
        }
    }

    // Il file non è stato trovato
    return QString();
}

QString simpleSearchByName(const QDir& dir, const QString& filename)
{

    foreach (QFileInfo v, dir.entryInfoList())
    {
        if(v.fileName() == filename)
        {
            return v.absoluteFilePath();
        }

    }
    return nullptr;

}
