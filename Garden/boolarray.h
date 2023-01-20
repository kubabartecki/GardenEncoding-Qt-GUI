#ifndef BOOLARRAY_H
#define BOOLARRAY_H

#include"array.h"
///
/// \brief The BoolArray class
///
class BoolArray : public Array
{
private:
    ///
    /// \brief barray
    ///
    bool **barray;
public:
    ///
    /// \brief BoolArray
    /// \param p
    ///
    BoolArray(int p);
    ///
    ///
    ///
    ~BoolArray();
    //virtuals
    ///
    /// \brief get_bool_value
    /// \param i
    /// \param j
    /// \return
    ///
    bool get_bool_value(int i, int j);
    ///
    /// \brief set_value
    /// \param i
    /// \param j
    /// \param val
    ///
    void set_value(int i, int j, bool val);
};

#endif // BOOLARRAY_H
