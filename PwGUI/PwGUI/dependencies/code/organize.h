#include <QMainWindow>
#include <QDebug>
#include <QFileDialog>
#include <QLabel>
#include <QPixmap>
#include <QListWidgetItem>
#include <QDesktopServices>
#include "qthread.h"
#include "searchinputdialog.h"
#include <QMessageBox>
#ifndef ORGANIZE_H
#define ORGANIZE_H


//organize by alphabeth order

void err(){
    QMessageBox err;
    err.setText("trasferimento non riuscito");
    err.exec();
}

void createFolders(const QDir& baseDir, char startLetter, char endLetter)
{
    for (char letter = startLetter; letter <= endLetter; ++letter) {
        QString letterFolderName = QString(letter);
        baseDir.mkdir(letterFolderName);
    }
}

void organizeFilesByAlphabet(const QDir& baseDir)
{
    if (!baseDir.exists()) {
        return;
    }

    QStringList fileNames = baseDir.entryList(QDir::Files);

    QThread thread1;
    QThread thread2;
    thread1.start();
    thread2.start();

    QObject::connect(&thread1, &QThread::started, [&]() {
        createFolders(baseDir, 'A', 'M');
    });

    QObject::connect(&thread2, &QThread::started, [&]() {
        createFolders(baseDir, 'N', 'Z');
    });

    thread1.wait();
    thread2.wait();

    foreach (const QString& fileName, fileNames) {
        QFileInfo fileInfo(baseDir.filePath(fileName));
        QString letterFolderName = fileInfo.fileName().at(0).toUpper();
        QString destinationFolder = baseDir.filePath(letterFolderName);

        if (!QFile::rename(fileInfo.absoluteFilePath(), destinationFolder + "/" + fileInfo.fileName())) {
            QMessageBox err;
            err.setText("Trasferimento non riuscito");
            err.exec();
        }
    }
}


//organize files by type (extension)
void organizeFilesByType(const QDir& baseDir)
{
    QVector<QString> extensions;


    foreach (QFileInfo fileInfo, baseDir.entryInfoList(QDir::Files)) {
        QString extension = fileInfo.suffix();
        if (!extensions.contains(extension)) {
            extensions.append(extension);
            baseDir.mkdir(extension);
        }
    }

    foreach (QFileInfo fileInfo, baseDir.entryInfoList(QDir::Files)) {
        QString extension = fileInfo.suffix();
        QString destinationFolder = baseDir.filePath(extension);

        if (!QFile::rename(fileInfo.absoluteFilePath(), destinationFolder + "/" + fileInfo.fileName())) {

            err();
        }
    }
}

//organize files by owner
void organizeFilesByOwner(const QDir& baseDir)
{
    QVector<QString> owners;

    foreach (QFileInfo fileInfo, baseDir.entryInfoList(QDir::Files)) {

        if (!owners.contains(fileInfo.owner())) {
            owners.append(fileInfo.owner());
            baseDir.mkdir(fileInfo.owner());
        }
    }

    foreach (QFileInfo fileInfo, baseDir.entryInfoList(QDir::Files)) {

        QString destinationFolder = baseDir.filePath(fileInfo.owner());

        if (!QFile::rename(fileInfo.absoluteFilePath(), destinationFolder + "/" + fileInfo.fileName())) {

            err();
        }
    }

}


//organize files by size
void organizeFilesBySize(const QDir& baseDir)
{
    QString dir10MB = baseDir.filePath("<10MB");
    QString dir100MB = baseDir.filePath("<100MB");
    QString dir1GB = baseDir.filePath("<1GB");
    QString dir1GBPlus = baseDir.filePath(">1GB");

    if (!baseDir.exists(dir10MB))
        baseDir.mkdir(dir10MB);
    if (!baseDir.exists(dir100MB))
        baseDir.mkdir(dir100MB);
    if (!baseDir.exists(dir1GB))
        baseDir.mkdir(dir1GB);
    if (!baseDir.exists(dir1GBPlus))
        baseDir.mkdir(dir1GBPlus);

    foreach (QFileInfo fileInfo, baseDir.entryInfoList(QDir::Files)) {
        qint64 size = fileInfo.size();

        if (size >= 0 && size < 10000000) {  // < 10MB
            QFile::rename(fileInfo.absoluteFilePath(), dir10MB + "/" + fileInfo.fileName());
        } else if (size >= 10000000 && size < 100000000) {  // < 100MB
            QFile::rename(fileInfo.absoluteFilePath(), dir100MB + "/" + fileInfo.fileName());
        } else if (size >= 100000000 && size < 1000000000) {  // < 1GB
            QFile::rename(fileInfo.absoluteFilePath(), dir1GB + "/" + fileInfo.fileName());
        } else if (size >= 1000000000) {  // >= 1GB
            QFile::rename(fileInfo.absoluteFilePath(), dir1GBPlus + "/" + fileInfo.fileName());
        }
    }
}



void renameFilesByAlphabeth( QDir& baseDir)
{


    QStringList fileNames = baseDir.entryList(QDir::Files, QDir::Name);
    int numero=001;
    foreach (const QString& fileName, fileNames)
    {
        QString newName = QString("%1_%2").arg(numero, 3, 10, QLatin1Char('0')).arg(fileName);
        QString newPath = baseDir.absoluteFilePath(newName);

        if (!baseDir.rename(fileName, newPath)) {

            err();
        }
        else{
             numero++;
        }

    }
}

void renameFilesByLastModified( QDir& baseDir)
{


    QStringList fileNames = baseDir.entryList(QDir::Files, QDir::Time);
    int numero=001;
    foreach (const QString& fileName, fileNames)
    {
        QString newName = QString("%1_%2").arg(numero, 3, 10, QLatin1Char('0')).arg(fileName);
        QString newPath = baseDir.absoluteFilePath(newName);

        if (!baseDir.rename(fileName, newPath)) {

             err();
        }
        else{
             numero++;
        }

    }
}



#endif // ORGANIZE_H
