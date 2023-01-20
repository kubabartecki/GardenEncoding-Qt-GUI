#ifndef FILE_H
#define FILE_H

#include<QFile>
#include<QFileDialog>
#include<QMessageBox>
#include<QTextStream>
#include <QDir>

#include"boolarray.h"
///
/// \brief The File class
///
class File
{
public:
    ///
    /// \brief File
    ///
    File();
    ///
    /// \brief set_current_file
    ///
    void set_current_file(QString);
    ///
    /// \brief get_current_file
    /// \return
    ///
    QString get_current_file();
    ///
    /// \brief getName
    /// \param parent
    ///
    virtual void getName(QWidget *parent) = 0;

protected:
    QString sample_path;
    QDir dir;
    ///
    /// \brief current_file
    ///
    QString current_file;
};

#endif // FILE_H
