#ifndef ARRAY_H
#define ARRAY_H

#include"mylabel.h"

/// Abstract class which is inherited by an array classes BoolArray and MyLabelArray
///
/// Array should always be a square with side equals 2 to the passed power
class Array
{
protected:
    /// Array object has a power, necessary to calculate size of array
    int power;

    /// Determines array size
    int side;

    /// Variable contains current number of radishes on the field
    ///
    /// Now this is used only with decoding, according to guidelines
    int number_of_radishes;
public:
    /// Gets side of the array
    /// \return Array's side (ex. number of rows)
    int get_side();

    /// Gets power
    /// \return power
    int get_power();

    /// Gets number_of_radishes
    /// \return number_of_radishes
    int get_number_of_radishes();

    /// Increments by 1 number_of_radishes
    /// \brief increment_1_number_of_radishes
    ///
    void increment_1_number_of_radishes();

    /// Sets number_of_radishes with passed argument
    /// \param num Is new value for number_of_radishes
    ///
    void set_number_of_radishes(int num);

    /// Checks if passed index is in array
    /// \return true - if index is correct, false if not
    bool correctIndex(int, int);

    /// Gets bool value from certain index of array
    /// \param i row
    /// \param j column
    /// \return bool value from certain index of array
    virtual bool get_bool_value(int i, int j) = 0;

    /// Sets bool value on certain index of array
    /// \param i row
    /// \param j column
    /// \param val bool value to set on given index
    ///
    virtual void set_value(int i, int j, bool val) = 0;

    /// Gets pointer to certain Mylabel object
    /// \return Mylabel's pointer
    ///
    virtual MyLabel* get_pMyLabel(int, int){return nullptr;}


    /// Sets initial values for the atributes, calculates side from the power
    /// \param p power
    ///
    Array(int p);

    /// Sets end values for the atributes
    ///
    virtual ~Array();
};

#endif // ARRAY_H
