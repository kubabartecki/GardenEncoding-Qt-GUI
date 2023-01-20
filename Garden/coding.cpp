#include "coding.h"

Coding::Coding(Array *array, QString c): code_d(c)
{
    this->array = array;
    array->set_number_of_radishes(0);
    position_initial = {0, 0};
    boolToStr = {{true, "1"}, {false, "0"}};
    strToBool = {{"1", true}, {"0", false}};
    place = 0;
}

Coding::~Coding()
{
    array = nullptr;
}

QString Coding::startCoding(){
    //dodaj potege
    QString str_power = QString::number(array->get_power());
    return str_power + " " + recursionCoding(array->get_side(), position_initial);
}

QString Coding::cuting(QString code){
    if("1111" == code) code = "1";
    else if("0000" == code) code = "0";
    else code.insert(0, "#");

    return code;
}

QString Coding::recursionCoding(int side, QVector<int> position){
    if(side == 2){
            QString code = "";
            for(int i = position[1]; i < position[1] + 2; i++){
                for(int j = position[0]; j < position[0] + 2; j++){
                    bool arr = array->get_bool_value(i, j);
                    code += boolToStr[arr];
                }
            }
            return cuting(code);
        }

        return cuting( recursionCoding(side / 2, position)
                    + recursionCoding(side / 2, {position[0] + side / 2, position[1]})
                    + recursionCoding(side / 2, {position[0], position[1] + side / 2})
                    + recursionCoding(side / 2, {position[0] + side / 2, position[1] + side / 2}));
}

//decoding part

void Coding::startDecoding(QWidget *parent){
    recursionDecoding(array->get_side(), {0, 0}, parent);
}

void Coding::recursionDecoding(int side, QVector<int> position, QWidget *parent){
    if('#' == code_d[place]){
        place++;

        if(side < 2){
            QMessageBox::warning(parent, "Ostrzeżenie", "Za dużo znaków: '#'");
            throw std::exception();
        }

        recursionDecoding(side / 2, position, parent);
        recursionDecoding(side / 2, {position[0] + side / 2, position[1]}, parent);
        recursionDecoding(side / 2, {position[0], position[1] + side / 2}, parent);
        recursionDecoding(side / 2, {position[0] + side / 2, position[1] + side / 2}, parent);
    }
    else if ('1' == code_d[place] || '0' == code_d[place]){
        for(int i = 0; i < side; i++){
            for(int j = 0; j < side; j++){
                array->set_value(position[1] + i, position[0] + j, strToBool[code_d[place]]);
                if('1' == code_d[place])array->increment_1_number_of_radishes();
            }
        }
        place++;
    }
    else{
        QMessageBox::warning(parent, "Ostrzeżenie", "Kod zawiera niedopowiednie znaki");
        throw std::exception();
    }
}
