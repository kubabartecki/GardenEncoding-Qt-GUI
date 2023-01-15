#ifndef CODING_H
#define CODING_H

#include<QMessageBox>
#include"mylabelarray.h"

class Coding
{
private:
    Array *array;
    QVector<int> position_initial;

    //for encoding
    QMap<bool, QString> boolToStr;

    //for decoding
    QMap<QString, bool> strToBool;
    QString code_d;
    int place;
public:
    Coding(Array *array, QString c = "");
    ~Coding();

    //initialize encoding alg
    QString startCoding();
    //function to turn "1111" -> "1"
    QString cuting(QString code);
    //main recursion alg
    QString recursionCoding(int side, QVector<int> position);

    //initialize decoding alg
    void startDecoding(QWidget *parent);
    void recursionDecoding(int side, QVector<int> position, QWidget *parent);
};

#endif // CODING_H
