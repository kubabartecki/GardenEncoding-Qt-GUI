#ifndef ARRAY_H
#define ARRAY_H

#include"mylabel.h"

class Array
{
protected:
    int power;
    int side;
    int number_of_radishes;
public:
    int get_side();
    int get_power();
    int get_number_of_radishes();
    void increment_1_number_of_radishes();
    void set_number_of_radishes(int );
    virtual bool get_bool_value(int i, int j) = 0;
    virtual void set_value(int i, int j, bool val) = 0;
    virtual MyLabel ***get_array_pointer(){return nullptr;}

    Array(int p);
    virtual ~Array();
};

#endif // ARRAY_H
