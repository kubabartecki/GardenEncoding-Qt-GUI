#ifndef FILESAVE_H
#define FILESAVE_H

#include "file.h"
///
/// \brief The FileSave class
///
class FileSave : public File
{
public:
    FileSave();
    ///
    /// \brief getName
    /// \param parent
    ///
    void getName(QWidget *parent) override;
    ///
    /// \brief saveCode
    /// \param code
    ///
    void saveCode(QString code);
    ///
    /// \brief saveField
    /// \param array
    ///
    void saveField(Array *array);

    ///
    /// \brief saveMultiCode
    /// \param code
    ///
    void saveMultiCode(QString code);
    ///
    /// \brief saveMultiField
    /// \param array
    ///
    void saveMultiField(Array *array);
    ///
    /// \brief cleanFile
    ///
    void cleanFile();
};

#endif // FILESAVE_H
