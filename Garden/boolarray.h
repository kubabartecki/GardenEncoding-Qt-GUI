#ifndef BOOLARRAY_H
#define BOOLARRAY_H

#include"array.h"

class BoolArray : public Array
{
private:
    bool **barray;
    MyLabel ***labels;
public:
    BoolArray(int p);
    ~BoolArray();
    //virtuals
    bool get_bool_value(int i, int j);
    void set_value(int i, int j, bool val);
};

#endif // BOOLARRAY_H
