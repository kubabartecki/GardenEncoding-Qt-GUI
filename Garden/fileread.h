#ifndef FILEREAD_H
#define FILEREAD_H

#include "file.h"
#include"filesave.h"
#include"coding.h"
///
/// \brief The FileRead class
///
class FileRead : public File
{
public:
    FileRead();
    ///
    /// \brief readField
    /// \param array
    /// \param parent
    ///
    void readField(Array *array, QWidget *parent);
    ///
    /// \brief readCode
    /// \return
    ///
    QString readCode();
    ///
    /// \brief getName
    /// \param parent
    ///
    void getName(QWidget *parent) override;
    ///
    /// \brief powerRead
    /// \param parent
    /// \return
    ///
    int powerRead(QWidget *parent);
    ///
    /// \brief readMultiField
    /// \param dest_file
    /// \param parent
    ///
    void readMultiField(QString dest_file, QWidget *parent);
    ///
    /// \brief readMultiCode
    /// \param dest_file
    /// \param parent
    ///
    void readMultiCode(QString dest_file, QWidget *parent);
};

#endif // FILEREAD_H
