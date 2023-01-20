#ifndef FILE_H
#define FILE_H

#include<QFile>
#include<QFileDialog>
#include<QMessageBox>
#include<QTextStream>
#include <QDir>

#include"boolarray.h"

/// Abstract class for file handling
///
class File
{
public:
    /// Defines sample_path as string
    ///
    File();
    /// Sets path to current file
    ///
    void set_current_file(QString);
    /// Gets path to current file
    /// \return path
    ///
    QString get_current_file();
    /// Chooses a file with Dialog Window
    /// \param parent used just for MessageBox placement
    ///
    virtual void getName(QWidget *parent) = 0;

protected:
    ///
    /// \brief
    /// Path in which should be stored sample files
    QString sample_path;
    ///
    /// \brief
    /// Direction that creates sample_path
    /// and sample files
    QDir dir;
    ///
    /// \brief
    /// Path to current file
    QString current_file;
};

#endif // FILE_H
