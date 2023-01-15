#ifndef FILEREAD_H
#define FILEREAD_H

#include "file.h"
#include"filesave.h"
#include"coding.h"

class FileRead : public File
{
public:
    FileRead();
    void readField(Array *array, QWidget *parent);
    QString readCode();

    virtual void getName(QWidget *parent);
    int powerRead(QWidget *parent);
    void readMultiField(QString dest_file, QWidget *parent);
    void readMultiCode(QString dest_file, QWidget *parent);
};

#endif // FILEREAD_H
