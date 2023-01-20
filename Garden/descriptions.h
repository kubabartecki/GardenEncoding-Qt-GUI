#ifndef DESCRIPTIONS_H
#define DESCRIPTIONS_H
#include<QString>

/// Class keeps insctructions how to use application
class Descriptions
{
private:
    QString file_tab_desc;
    QString manual_tab_desc;

    QString single_field_desc;
    QString multi_field_desc;
public:
    ///Defines all descriptions
    Descriptions();

    /// Gets instructions how to use app with files
    /// \return string in markdown style
    ///
    QString get_file_tab_desc();
    /// Gets instructions how to use app in manual mode
    /// \return string in markdown style
    ///
    QString get_manual_tab_desc();

    /// Gets instructions how to use app with single file
    /// \return string in markdown style
    ///
    /// Appended at the end of tab description
    QString get_single_field_desc();
    /// Gets instructions how to use app with multifile
    /// \return string in markdown style
    ///
    /// Appended at the end of tab description
    QString get_multi_field_desc();
};

#endif // DESCRIPTIONS_H
