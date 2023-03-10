#include "mylabelarray.h"

MyLabelArray::MyLabelArray(int p):Array(p)
{    
    labels = new MyLabel**[side];
    for(int i = 0; i < side; i++){
        labels[i] = new MyLabel*[side];
        for(int j = 0; j < side; j++){
            labels[i][j] = new MyLabel(true);
        }
    }
}

MyLabelArray::~MyLabelArray(){    
    for(int i = 0; i < side; i++){
        for(int j = 0; j < side; j++){
            delete labels[i][j];
        }
        delete [] labels[i];
    }
    delete [] labels;
    labels = nullptr;
}

bool MyLabelArray::get_bool_value(int i, int j)
{
    if(correctIndex(i, j)){
        return labels[i][j]->get_click();
    }
    return 0;
}

void MyLabelArray::set_value(int i, int j, bool val)
{
    if(correctIndex(i, j)){
        labels[i][j]->setPicAndClick(val);
    }
}

MyLabel* MyLabelArray::get_pMyLabel(int i, int j)
{
    if(correctIndex(i, j)){
        return labels[i][j];
    }
    return nullptr;
}
