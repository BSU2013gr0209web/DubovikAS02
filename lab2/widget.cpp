#include "widget.h"
#include <QtCore>
#include <QtGui>
#include <QImage>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(800, 480);
    this->setSizePolicy(QSizePolicy::Policy(800), QSizePolicy::Policy(480));

    layout_color = new QHBoxLayout;
    layout_color2 = new QHBoxLayout;
    layout_size = new QHBoxLayout;
    layout_picture = new QHBoxLayout;
    gridLayout = new QGridLayout;

    //addWidget(*Widget, row, column, rowspan, colspan)
    gridLayout->addLayout(layout_size, 0, 0);
    gridLayout->addLayout(layout_color, 0, 2);
    gridLayout->addLayout(layout_color2, 1, 2);
    gridLayout->addLayout(layout_picture, 2, 0, 5, 3);
    setLayout(gridLayout);

    circle1 = new QPushButton(this);
    layout_size->addWidget(circle1);
    circle1->setText("Big Brush");
    connect(circle1, SIGNAL(clicked()), this, SLOT(selectCircle1()));

    circle2 = new QPushButton(this);
    layout_size->addWidget(circle2);
    circle2->setText("Mid Brush");
    connect(circle2, SIGNAL(clicked()), this, SLOT(selectCircle2()));

    circle3 = new QPushButton(this);
    layout_size->addWidget(circle3);
    circle3->setText("Small Brush");
    connect(circle3, SIGNAL(clicked()), this, SLOT(selectCircle3()));

    slider_size = new QSlider(Qt::Horizontal);
    slider_size->setRange(1, 30);
    slider_size->setValue(5);
    gridLayout->addWidget(slider_size, 1, 0);
    connect(slider_size, SIGNAL(valueChanged(int)), this, SLOT(setSizeSlider()));

    spinbox_size = new QSpinBox();
    spinbox_size->setRange(1,30);
    spinbox_size->setValue(5);
    gridLayout->addWidget(spinbox_size, 1, 1);
    connect(spinbox_size, SIGNAL(valueChanged(int)), this, SLOT(setSizeSpinBox()));



    black = new QPushButton(this);
    layout_color->addWidget(black);
    black->setStyleSheet("background-color: #000000;");
    connect(black, SIGNAL(clicked()), this, SLOT(selectBlack()));

    white = new QPushButton(this);
    layout_color->addWidget(white);
    white->setStyleSheet("background-color: #FFFFFF;");
    connect(white, SIGNAL(clicked()), this, SLOT(selectWhite()));

    grey = new QPushButton(this);
    layout_color->addWidget(grey);
    grey->setStyleSheet("background-color: #9F9F9F;");
    connect(grey, SIGNAL(clicked()), this, SLOT(selectGrey()));

    blue = new QPushButton(this);
    layout_color->addWidget(blue);
    blue->setStyleSheet("background-color: #0B2EDE;");
    connect(blue, SIGNAL(clicked()), this, SLOT(selectBlue()));

    light_blue = new QPushButton(this);
    layout_color->addWidget(light_blue);
    light_blue->setStyleSheet("background-color: #4FAEE5;");
    connect(light_blue, SIGNAL(clicked()), this, SLOT(selectLight_blue()));

    green = new QPushButton(this);
    layout_color->addWidget(green);
    green->setStyleSheet("background-color: #138B00;");
    connect(green, SIGNAL(clicked()), this, SLOT(selectGreen()));

    light_green = new QPushButton(this);
    layout_color->addWidget(light_green);
    light_green->setStyleSheet("background-color: #78EC2A;");
    connect(light_green, SIGNAL(clicked()), this, SLOT(selectLight_green()));

    orange = new QPushButton(this);
    layout_color->addWidget(orange);
    orange->setStyleSheet("background-color: #FF8E1E;");
    connect(orange, SIGNAL(clicked()), this, SLOT(selectOrange()));

    yellow = new QPushButton(this);
    layout_color->addWidget(yellow);
    yellow->setStyleSheet("background-color: #FFEA26;");
    connect(yellow, SIGNAL(clicked()), this, SLOT(selectYellow()));

    red = new QPushButton(this);
    layout_color->addWidget(red);
    red->setStyleSheet("background-color: #FF0B0B;");
    connect(red, SIGNAL(clicked()), this, SLOT(selectRed()));

    pink = new QPushButton(this);
    layout_color->addWidget(pink);
    pink->setStyleSheet("background-color: #FF99FF;");
    connect(pink, SIGNAL(clicked()), this, SLOT(selectPink()));

    purple = new QPushButton(this);
    layout_color->addWidget(purple);
    purple->setStyleSheet("background-color: #990099;");
    connect(purple, SIGNAL(clicked()), this, SLOT(selectPurple()));

//NUN
    light_black = new QPushButton(this);
    layout_color2->addWidget(light_black);
    light_black->setStyleSheet("background-color: #4B4B4B;");
    connect(light_black, SIGNAL(clicked()), this, SLOT(selectLight_black()));

    dark_white = new QPushButton(this);
    layout_color2->addWidget(dark_white);
    dark_white->setStyleSheet("background-color: #FFF5F5;");
    connect(dark_white, SIGNAL(clicked()), this, SLOT(selectDark_white()));

    light_grey = new QPushButton(this);
    layout_color2->addWidget(light_grey);
    light_grey->setStyleSheet("background-color: #E5E5E5;");
    connect(light_grey, SIGNAL(clicked()), this, SLOT(selectLight_grey()));

    dark_blue = new QPushButton(this);
    layout_color2->addWidget(dark_blue);
    dark_blue->setStyleSheet("background-color: #08007F;");
    connect(dark_blue, SIGNAL(clicked()), this, SLOT(selectDark_blue()));

    light_blue2 = new QPushButton(this);
    layout_color2->addWidget(light_blue2);
    light_blue2->setStyleSheet("background-color: #C3F2FF;");
    connect(light_blue2, SIGNAL(clicked()), this, SLOT(selectLight_blue2()));

    dark_green = new QPushButton(this);
    layout_color2->addWidget(dark_green);
    dark_green->setStyleSheet("background-color: #0B4405;");
    connect(dark_green, SIGNAL(clicked()), this, SLOT(selectDark_green()));

    light_green2 = new QPushButton(this);
    layout_color2->addWidget(light_green2);
    light_green2->setStyleSheet("background-color: #BAFFB2;");
    connect(light_green2, SIGNAL(clicked()), this, SLOT(selectLight_green2()));

    light_orange = new QPushButton(this);
    layout_color2->addWidget(light_orange);
    light_orange->setStyleSheet("background-color: #F57200;");
    connect(light_orange, SIGNAL(clicked()), this, SLOT(selectLight_orange()));

    light_yellow = new QPushButton(this);
    layout_color2->addWidget(light_yellow);
    light_yellow->setStyleSheet("background-color: #FFFAAC;");
    connect(light_yellow, SIGNAL(clicked()), this, SLOT(selectLight_yellow()));

    light_red = new QPushButton(this);
    layout_color2->addWidget(light_red);
    light_red->setStyleSheet("background-color: #FF4D4D;");
    connect(light_red, SIGNAL(clicked()), this, SLOT(selectLight_red()));

    light_pink = new QPushButton(this);
    layout_color2->addWidget(light_pink);
    light_pink->setStyleSheet("background-color: #FF94DC;");
    connect(light_pink, SIGNAL(clicked()), this, SLOT(selectLight_pink()));

    dark_purple = new QPushButton(this);
    layout_color2->addWidget(dark_purple);
    dark_purple->setStyleSheet("background-color: #58033C;");
    connect(dark_purple, SIGNAL(clicked()), this, SLOT(selectDark_purple()));



    this->setWindowTitle("Painter");
    img = new QImage(size(), QImage::Format_ARGB32_Premultiplied);
    width = 3;
    r=0;
    g=0;
    b=0;

    label_picture = new QLabel;
    label_picture->setStyleSheet("background-color: white;");
    //label_picture->setPicture(".//picture.png");

    //picture = new QPixmap("picture.jpg");
    //label_picture->setPixmap(picture);
    //label_picture->setStyleSheet("background-image: url('picture.jpg');");
    layout_picture->addWidget(label_picture);

}

Widget::~Widget()
{
}

void Widget::mouseMoveEvent(QMouseEvent *e){
    point=e->pos();
    update();
}

void Widget::paintEvent(QPaintEvent *) { //Qunuse - помещаем туда неиспользуемые перемнные
    QPixmap pixmap(790, 400);
    pixmap.fill(QColor("transparent"));
    QPainter p1(img);
    p1.setPen(QPen(QColor(r,g,b), width, Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin));
    p1.drawPoint(point);
    QPainter p2(&pixmap);
    p2.drawImage(-10,-70, *img);
    label_picture->setPixmap(pixmap);

}

void Widget::selectCircle1(){
    width = 30;
    slider_size->setValue(width);
    spinbox_size->setValue(width);
}
void Widget::selectCircle2(){
    width = 16;
    slider_size->setValue(width);
    spinbox_size->setValue(width);
}
void Widget::selectCircle3(){
    width = 3;
    slider_size->setValue(width);
    spinbox_size->setValue(width);
}


void Widget::selectBlack(){
    r=0;
    g=0;
    b=0;
}
void Widget::selectWhite(){
    r=255;
    g=255;
    b=255;
}
void Widget::selectGrey(){
    r=159;
    g=159;
    b=159;
}
void Widget::selectBlue(){
    r=11;
    g=46;
    b=222;
}
void Widget::selectLight_blue(){
    r=79;
    g=174;
    b=229;
}
void Widget::selectGreen(){
    r=19;
    g=139;
    b=0;
}
void Widget::selectLight_green(){
    r=120;
    g=236;
    b=42;
}
void Widget::selectOrange(){
    r=255;
    g=142;
    b=30;
}
void Widget::selectYellow(){
    r=255;
    g=234;
    b=38;
}
void Widget::selectRed(){
    r=255;
    g=11;
    b=11;
}
void Widget::selectPink(){
    r=255;
    g=153;
    b=255;
}
void Widget::selectPurple(){
    r=153;
    g=0;
    b=153;
}
void Widget::selectLight_black(){
    r=75;
    g=75;
    b=75;
}
void Widget::selectDark_white(){
    r=255;
    g=245;
    b=245;
}
void Widget::selectLight_grey(){
    r=229;
    g=229;
    b=229;
}
void Widget::selectDark_blue(){
    r=8;
    g=0;
    b=127;
}
void Widget::selectLight_blue2(){
    r=195;
    g=242;
    b=255;
}
void Widget::selectDark_green(){
    r=11;
    g=68;
    b=5;
}
void Widget::selectLight_green2(){
    r=186;
    g=255;
    b=178;
}
void Widget::selectLight_orange(){
    r=245;
    g=114;
    b=0;
}
void Widget::selectLight_yellow(){
    r=255;
    g=250;
    b=172;
}
void Widget::selectLight_red(){
    r=255;
    g=77;
    b=77;
}
void Widget::selectLight_pink(){
    r=255;
    g=148;
    b=220;
}
void Widget::selectDark_purple(){
    r=88;
    g=3;
    b=60;
}

void Widget::setSizeSlider(){
    width = slider_size->value();
    spinbox_size->setValue(width);
}
void Widget::setSizeSpinBox(){
    width = spinbox_size->value();
    slider_size->setValue(width);
}
void Widget::savePicture(){
    //pixmap.save("file","PNG",0);
}

