#ifndef BOOLARRAY_H
#define BOOLARRAY_H

#include"array.h"
/// Represents the field as bool array
///
/// This class is used with larger fields/codes and multifields/multicodes
class BoolArray : public Array
{
protected:
    /// Pointer to main bool array
    ///
    /// Includes bool representants of field elements
    bool **barray;
public:
    /// Allocates the bool array
    ///
    /// \param p power
    ///
    BoolArray(int p);

    /// Cleans memory
    ///
    ~BoolArray();

    //virtuals
    /// Gets bool value from certain index of array
    /// \param i row
    /// \param j column
    /// \return bool value from certain index of array
    bool get_bool_value(int i, int j);

    /// Sets bool value on certain index of array
    /// \brief set_value
    /// \param i row
    /// \param j column
    /// \param val bool value to set on given index
    void set_value(int i, int j, bool val);
};

#endif // BOOLARRAY_H
