#ifndef FILESAVE_H
#define FILESAVE_H

#include "file.h"

class FileSave : public File
{
public:
    FileSave();
    virtual void getName(QWidget *parent);
    void saveCode(QString code);
    void saveField(Array *array);

    void saveMultiCode(QString code);
    void saveMultiField(Array *array);
    void cleanFile();
};

#endif // FILESAVE_H
