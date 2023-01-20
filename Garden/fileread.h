#ifndef FILEREAD_H
#define FILEREAD_H

#include "file.h"
#include"filesave.h"
#include"coding.h"
///
/// \brief
/// Class services reading data from files
class FileRead : public File
{
public:
    ///
    /// \brief
    /// Creates samle_path if it does not exist
    /// and sample files: sample_code.txt and sample_field.txt
    FileRead();
    /// Reads values from file's field and saves it in array
    /// \param array pointer to array in which we should save data
    /// \param parent used just for MessageBox placement
    ///
    /// Also checks if field contains correct signs
    void readField(Array *array, QWidget *parent);
    /// Reads code from file
    /// \return code in string
    ///
    QString readCode();
    /// Chooses a file with Dialog Window
    /// \param parent used just for MessageBox placement
    ///
    void getName(QWidget *parent) override;
    /// Reads only power from file
    /// \param parent
    /// \return power
    ///
    int powerRead(QWidget *parent);
    /// \brief Reads values from file, uses other classes' functions
    /// to encode and save result
    /// \param dest_file file to save result codes in it
    /// \param parent used just for MessageBox placement
    ///
    /// Uses BoolArray, because this function handle multifield file
    void readMultiField(QString dest_file, QWidget *parent);

    /// \brief Reads codes from file, uses other classes' functions
    /// to decode and save result
    /// \param dest_file file to save reesult fields in it
    /// \param parent used just for MessageBox placement
    ///
    void readMultiCode(QString dest_file, QWidget *parent);
};

#endif // FILEREAD_H
