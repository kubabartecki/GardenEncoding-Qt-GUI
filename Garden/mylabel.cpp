#include "mylabel.h"

//for pixmaps
QString empty = "://img/img/empty-cut-frame.png";
QString radish = "://img/img/rad-cut-frame.png";

MyLabel::MyLabel(bool clk)
{
    setScaledContents(true);
    setPicAndClick(clk);
}
bool MyLabel::get_click(){
    return click;
}
void MyLabel::set_click(bool clk){
    this->click = clk;
}

void MyLabel::setPicAndClick(bool clk){
    if(clk){
        click = true;
        QPixmap pix(radish);
        setPixmap(pix);
    }
    else{
        click = false;
        QPixmap pix(empty);
        setPixmap(pix);
    }
}

void MyLabel::changePicAndClick(){
    setPicAndClick(!click);
}

void MyLabel::mousePressEvent(QMouseEvent* event) {
    emit clicked();
    changePicAndClick();
}
