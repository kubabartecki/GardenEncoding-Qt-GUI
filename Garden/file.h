#ifndef FILE_H
#define FILE_H

#include<QFile>
#include<QFileDialog>
#include<QMessageBox>
#include<QTextStream>

#include"boolarray.h"

class File
{
public:
    File();
    void set_current_file(QString);
    QString get_current_file();

    virtual void getName(QWidget *parent) = 0;

protected:
    QString current_file;
};

#endif // FILE_H
