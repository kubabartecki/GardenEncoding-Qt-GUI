#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
///
/// \brief The MyLabel class
///
class MyLabel : public QLabel
{
    Q_OBJECT
public:
    ///
    /// \brief MyLabel
    /// \param click
    ///
    MyLabel(bool click);
    ///
    /// \brief get_click
    /// \return
    ///
    bool get_click();
    ///
    /// \brief set_click
    /// \param click
    ///
    void set_click(bool click);

    ///
    /// \brief setPicAndClick
    /// \param clk
    ///
    void setPicAndClick(bool clk);
    ///
    /// \brief changePicAndClick
    ///
    void changePicAndClick();
signals:
    ///
    /// \brief clicked
    ///
    void clicked();

protected:
    ///
    /// \brief click
    ///
    bool click;
    ///
    /// \brief mousePressEvent
    /// \param event
    ///
    void mousePressEvent(QMouseEvent* event);

};


#endif // MYLABEL_H
