#ifndef MYLABELARRAY_H
#define MYLABELARRAY_H

#include"array.h"

class MyLabelArray : public Array
{
protected:
    MyLabel ***labels;
public:
    MyLabelArray(int p);
    ~MyLabelArray();

    bool get_bool_value(int i, int j);
    void set_value(int i, int j, bool val);

    MyLabel*** get_array_pointer() override;
};

#endif // MYLABELARRAY_H
