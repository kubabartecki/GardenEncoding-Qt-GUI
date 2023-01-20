#ifndef ARRAY_H
#define ARRAY_H

#include"mylabel.h"

///  Abstract class which is inherited by an array classes BoolArray and MyLabelArray
///
/// Array should always be a square with side equals 2 to the passed power
class Array
{
protected:
    /// Array object has a power, necessary to calculate size of array
    ///
    ///
    int power;

    /// Determine array size
    /// \brief side
    ///
    int side;

    /// Variable contains current number of radishes on the field
    ///
    /// Now this is used only with decoding, according to guidelines
    int number_of_radishes;
public:

    /// Gets side of the array
    ///
    /// \return Array's side (ex. number of rows)
    int get_side();

    /// Gets power
    ///
    /// \return power
    int get_power();

    /// Gets number_of_radishes
    ///
    /// \return number_of_radishes
    int get_number_of_radishes();

    /// increments by 1 number_of_radishes
    /// \brief increment_1_number_of_radishes
    ///
    void increment_1_number_of_radishes();

    /// sets number_of_radishes with passed argument
    /// \brief set_number_of_radishes
    /// \param num is new value for number_of_radishes
    ///
    void set_number_of_radishes(int num);

    ///
    /// \brief correctIndex
    /// \return
    ///
    bool correctIndex(int, int);
    /// gets bool value from certain index of array
    /// \brief get_bool_value
    /// \param i row
    /// \param j column
    /// \return bool value from certain index of array
    ///
    virtual bool get_bool_value(int i, int j) = 0;

    /// sets bool value on certain index of array
    /// \brief set_value
    /// \param i row
    /// \param j column
    /// \param val bool value to set on given index
    ///
    virtual void set_value(int i, int j, bool val) = 0;

    ///
    /// \brief get_pMyLabel
    /// \return
    ///
    virtual MyLabel* get_pMyLabel(int, int){return nullptr;}


    /// sets initial values for the atributes, calculates side from the power
    /// \brief Array
    /// \param p power
    ///
    Array(int p);

    /// sets end values for the atributes
    /// \brief ~Array
    ///
    virtual ~Array();
};

#endif // ARRAY_H
