#include <QMainWindow>
#include <QDebug>
#include <QFileDialog>
#include <QLabel>
#include <QPixmap>
#include <QListWidgetItem>
#include <QDesktopServices>
#include "searchinputdialog.h"
#include <QMessageBox>

#ifndef SEARCH_H
#define SEARCH_H


//by name
//ricerca files per nome punto 1
QVector<QString> dfsFileSearchByName(const QDir& dir, const QString& filename)
{
    QVector<QString> toReturn;

    // Check if the current file name matches the searched name
    QStringList files = dir.entryList(QStringList() << "*", QDir::Files);

    foreach (const QString& file, files) {
        if (file.contains(filename)) {



            toReturn.append(dir.absoluteFilePath(file));

        }
    }

    // Perform DFS search in subdirectories
    QStringList subdirectories = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    foreach (const QString& subdirectory, subdirectories) {
        QDir newPath = dir;
        newPath.cd(subdirectory);
        QVector<QString> filePaths = dfsFileSearchByName(newPath, filename);
        if (!filePaths.isEmpty()) {
            toReturn += filePaths;
        }
    }

    // Return the found file paths
    return toReturn;
}

QVector<QString> simpleSearchByName(const QDir& dir, const QString& filename)
{
    QVector<QString> toReturn;
    foreach (QFileInfo v, dir.entryInfoList())
    {
        if(v.fileName().contains(filename))
        {
            toReturn.append(v.absoluteFilePath());

        }

    }
    return toReturn;

}

//by extension
QVector<QString> dfsFileSearchByExtension(const QDir& dir, const QString& extension)
{
    QVector<QString> toReturn;


    QStringList files = dir.entryList(QStringList() << "*", QDir::Files);

    foreach (const QString& file, files) {
        QFileInfo fileInfo(dir.absoluteFilePath(file));
        if (fileInfo.suffix() == extension) {
            toReturn.append(fileInfo.absoluteFilePath());
        }
    }


    QStringList subdirectories = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    foreach (const QString& subdirectory, subdirectories) {
        QDir newPath = dir;
        newPath.cd(subdirectory);
        QVector<QString> filePaths = dfsFileSearchByExtension(newPath, extension);
        if (!filePaths.isEmpty()) {
            toReturn += filePaths;
        }
    }

    return toReturn;
}

QVector<QString> simpleSearchByExtension(const QDir& dir, const QString& extension)
{
    QVector<QString> toReturn;
    foreach (QFileInfo v, dir.entryInfoList())
    {
        if(v.suffix()==extension)
        {
            toReturn.append(v.absoluteFilePath());

        }

    }
    return toReturn;

}

//by content in .txt
QVector<QString> dfsFileSearchByContent(const QDir& dir, const QString& word)
{
    QVector<QString> toReturn;


    QStringList files = dir.entryList(QStringList() << "*.txt", QDir::Files);  // Only search for .txt files

    foreach (const QString& file, files) {
        QString filePath = dir.filePath(file);
        QFile inputFile(filePath);
        if (inputFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&inputFile);
            QString fileContents = in.readAll();
            if (fileContents.contains(word)) {
                toReturn.append(filePath);
            }
            inputFile.close();
        }
    }


    QStringList subdirectories = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    foreach (const QString& subdirectory, subdirectories) {
        QDir newPath = dir;
        newPath.cd(subdirectory);
        QVector<QString> filePaths = dfsFileSearchByContent(newPath, word);
        if (!filePaths.isEmpty()) {
            toReturn += filePaths;
        }
    }


    return toReturn;
}


QVector<QString> simpleSearchByContent(const QDir& dir, const QString& word){

    QStringList files = dir.entryList(QStringList() << "*.txt", QDir::Files);  // Only search for .txt files
    QVector<QString> toReturn;

    foreach (const QString& file, files) {
        QString filePath = dir.filePath(file);
        QFile inputFile(filePath);
        if (inputFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&inputFile);
            QString fileContents = in.readAll();
            if (fileContents.contains(word)) {
                toReturn.append(filePath);
            }
            inputFile.close();
        }
    }

    return toReturn;

}



#endif // SEARCH_H
