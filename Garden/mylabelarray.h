#ifndef MYLABELARRAY_H
#define MYLABELARRAY_H

#include"array.h"

/// Represents the field as MyLabel array
///
/// This class is used with smaller fields/codes (power < 7)
/// Contains array that is visible on the screen
class MyLabelArray : public Array
{
protected:
    /// Pointer to 2D array of pointers
    MyLabel ***labels;
public:
    /// \brief Allocates memory for the array, assumes that
    /// default value of MyLabel should be true(radish picture)
    /// \param p power
    ///
    MyLabelArray(int p);

    /// Cleans memory
    ~MyLabelArray();

    /// Gets bool value from certain index of MyLabel array
    /// \brief get_bool_value
    /// \param i row
    /// \param j column
    /// \return bool value from certain index of array
    bool get_bool_value(int i, int j);

    /// Sets bool value and image on certain index of MyLabel array
    /// \brief set_value
    /// \param i row
    /// \param j column
    /// \param val bool value to set on given index
    ///
    /// It also sets appropriate image
    /// \see setPicAndClick
    void set_value(int i, int j, bool val);

    /// Gets pointer to MyLabel certain object
    /// \brief get_pMyLabel
    /// \param i row
    /// \param j column
    /// \return Pointer to MyLabel certain object
    ///
    /// Used to add widget(MyLabel) to the grid
    MyLabel* get_pMyLabel(int i, int j) override;
};

#endif // MYLABELARRAY_H
