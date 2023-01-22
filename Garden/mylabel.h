#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>


/// \brief Class represents QLabel,
/// but with some new features.
///
/// Each MyLabel indicates one radish or one empty place on the field
///
/// It has mousePressEvent, and bool click
///
/// This make QLabel more interactive
class MyLabel : public QLabel
{
    Q_OBJECT
public:
    /// Sets up MyLabel
    /// \param click This value decides if on this certain place
    /// radish is located: true - is located, false - not
    ///
    /// Sets cick value and based on this information sets picture,
    /// sets picture properties
    MyLabel(bool click);
    ///
    /// \brief Gets click
    /// \return true if object is radish, false if is empty
    ///
    bool get_click();
    ///
    /// \brief Sets click
    /// \param click This value decides if on this certain place
    /// radish is located: true - is located, false - not
    ///
    void set_click(bool click);

    /// Sets picture and click at one time
    /// \param clk click
    void setPicAndClick(bool clk);

    /// Sets picture and click on the opposite values
    void changePicAndClick();
signals:
    ///
    /// \brief clicked Signal
    ///
    void clicked();

protected:
    //for pixmaps
    ///
    /// \brief Path to emppty place picture
    ///
    static QString empty;
    ///
    /// \brief Path to radish picture
    ///
    static QString radish;

    /// \brief This value decides if on this certain place
    /// radish is located: true - is located, false - not
    bool click;

    /// \brief Emits clicked and changes photo and click of MyLabel
    /// on the opposite values
    /// \param event
    void mousePressEvent(QMouseEvent* event);
};

#endif // MYLABEL_H
