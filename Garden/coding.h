#ifndef CODING_H
#define CODING_H

#include<QMessageBox>
#include"mylabelarray.h"

/// Handle encoding and decoding algorithms
class Coding
{
protected:

    /// Pointer to BoolArray or MyLabelArray
    ///
    /// Polymorphic pointer
    Array *array;
    /// Initial position
    ///
    /// This position points at top left corner of the square,
    /// This coordinate tells us where we should take values from
    /// or where divide square into 4 smaller parts(according to side)
    QVector<int> position_initial;

    //for encoding
    /// Map that turns bool value into string
    QMap<bool, QString> boolToStr;

    //for decoding
    /// Map that turns string into bool value
    ///
    ///
    QMap<QString, bool> strToBool;
    /// Code that we should decode to get a field
    ///
    /// Used only with decoding
    QString code_d;
    /// Current index to service in code_d
    ///
    /// Used only with decoding
    int place;
public:
    /// Prepares for coding or decoding
    /// \param array pointer to BoolArray or MyLabelArray
    /// \param c code_d code for decoding, if we want to encode it has default value
    ///
    /// Sets array pointer, number_of_radishes to 0,
    /// position_initial, palce to initial values,
    /// defines maps
    Coding(Array *array, QString c = "");

    /// Sets array pointer to nullptr
    ///
    ~Coding();

    /// Prepares for encoding
    /// \return Final, encoded code
    ///
    /// Starts recursive algorithm
    QString startCoding();

    /// Function that helps reduce code
    /// \param code
    /// \return Reduced code
    ///
    /// Turns "1111" -> "1"
    QString cuting(QString code);

    /// Main recursive algorithm
    /// \param side side of the square
    /// \param position position of square's top left corner
    /// \return Encoded string from certain part of field
    ///
    /// Divides all field into 4 smaller squares, that also are divided and so on
    QString recursionCoding(int side, QVector<int> position);

    /// Prepares for decoding
    /// \param parent used just for MessageBox placement
    ///
    void startDecoding(QWidget *parent);
    /// Main recursive algorithm
    /// \param side side of the square
    /// \param position position of square's top left corner
    /// \param parent used just for MessageBox placement
    ///
    /// Uses recursion when encounter #
    void recursionDecoding(int side, QVector<int> position, QWidget *parent);
};

#endif // CODING_H
