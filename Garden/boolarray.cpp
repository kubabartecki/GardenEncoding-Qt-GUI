#include "boolarray.h"

BoolArray::BoolArray(int p):Array(p)
{
    barray = new bool*[side];
    for(int i = 0; i < side; i++){
        barray[i] = new bool[side];
        for(int j = 0; j < side; j++){
            barray[i][j] = true;
        }
    }
}

BoolArray::~BoolArray()
{
    for(int i = 0; i < side; i++){
            delete [] barray[i];
        }
    delete [] barray;
    barray = nullptr;
}

bool BoolArray::get_bool_value(int i, int j)
{
    if(correctIndex(i, j)){
        return barray[i][j];
    }
    return 0;
}

void BoolArray::set_value(int i, int j, bool val)
{
    if(correctIndex(i, j)){
        barray[i][j] = val;
    }
}
