#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    MyLabel(bool click);
    bool get_click();
    void set_click(bool click);

    void setPicAndClick(bool clk);
    void changePicAndClick();
signals:
    void clicked();

protected:
    bool click;

    void mousePressEvent(QMouseEvent* event);

};


#endif // MYLABEL_H
