#include "array.h"

Array::Array(int p)
{
    number_of_radishes = 0;
    power = p;
    side = pow(2, p);
}

Array::~Array()
{
    side = 0;
    number_of_radishes = 0;
    power = 0;
}

int Array::get_side(){
    return side;
}
int Array::get_power(){
    return power;
}

int Array::get_number_of_radishes()
{
    return number_of_radishes;
}

void Array::increment_1_number_of_radishes()
{
    number_of_radishes++;
}

void Array::set_number_of_radishes(int num)
{
    number_of_radishes = num;
}
