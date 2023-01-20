#ifndef MYLABELARRAY_H
#define MYLABELARRAY_H

#include"array.h"
///
/// \brief The MyLabelArray class
///
class MyLabelArray : public Array
{
protected:
    ///
    /// \brief labels
    ///
    MyLabel ***labels;
public:
    ///
    /// \brief MyLabelArray
    /// \param p
    ///
    MyLabelArray(int p);
    ///
    ///
    ///
    ~MyLabelArray();

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

    ///
    /// \brief get_pMyLabel
    /// \param i
    /// \param j
    /// \return
    ///
    MyLabel* get_pMyLabel(int i, int j) override;
};

#endif // MYLABELARRAY_H
