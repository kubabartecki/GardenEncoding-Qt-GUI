#ifndef CODING_H
#define CODING_H

#include<QMessageBox>
#include"mylabelarray.h"
///
/// \brief The Coding class
///
class Coding
{
private:
    ///
    /// \brief array
    ///
    Array *array;
    ///
    /// \brief position_initial
    ///
    QVector<int> position_initial;

    //for encoding
    ///
    /// \brief boolToStr
    ///
    QMap<bool, QString> boolToStr;

    //for decoding
    ///
    /// \brief strToBool
    ///
    QMap<QString, bool> strToBool;
    ///
    /// \brief code_d
    ///
    QString code_d;
    ///
    /// \brief place
    ///
    int place;
public:
    ///
    /// \brief Coding
    /// \param array
    /// \param c
    ///
    Coding(Array *array, QString c = "");
    ///
    ///
    ///
    ~Coding();

    ///
    /// \brief startCoding initialize encoding alg
    /// \return
    ///
    QString startCoding();

    ///
    /// \brief cuting function to turn "1111" -> "1"
    /// \param code
    /// \return
    ///
    QString cuting(QString code);

    ///
    /// \brief recursionCoding main recursion alg
    /// \param side
    /// \param position
    /// \return
    ///
    QString recursionCoding(int side, QVector<int> position);


    ///
    /// \brief startDecoding initialize decoding alg
    /// \param parent
    ///
    void startDecoding(QWidget *parent);
    ///
    /// \brief recursionDecoding
    /// \param side
    /// \param position
    /// \param parent
    ///
    void recursionDecoding(int side, QVector<int> position, QWidget *parent);
};

#endif // CODING_H
