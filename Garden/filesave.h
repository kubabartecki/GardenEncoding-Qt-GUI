#ifndef FILESAVE_H
#define FILESAVE_H

#include "file.h"

/// Class services saving data to files
class FileSave : public File
{
public:
    ///
    /// \brief Creates file: sample_output.txt
    ///
    FileSave();
    /// Chooses a file with Dialog Window
    /// \param parent used just for MessageBox placement
    ///
    void getName(QWidget *parent) override;
    ///
    /// \brief Saves final code to files
    /// \param code final code
    ///
    void saveCode(QString code);
    ///
    /// \brief Saves decoded field to file
    /// \param array Array from which we should take values
    ///
    void saveField(Array *array);

    /// \brief Handles saving code in multifield mode
    /// \param code Current code to save
    ///
    /// Appends code
    void saveMultiCode(QString code);
    /// \brief Handles saving fields in multifield mode
    /// \param array Current array to save
    ///
    /// Appends fields
    void saveMultiField(Array *array);
    ///
    /// \brief Cleans the file
    ///
    /// This should be done before appending
    void cleanFile();
};

#endif // FILESAVE_H
