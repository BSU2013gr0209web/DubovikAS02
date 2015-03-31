#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPoint>
#include <QMouseEvent>
#include <QImage>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>

#include <QPushButton>

#include <QSlider>
#include <QSpinBox>
#include <QLabel>
#include <QPixmap>

class QImage;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

protected:
    QImage* img;
    QPoint point; //локальная глобальная перемнная
    int width;
    int r;
    int g;
    int b;
    void paintEvent(QPaintEvent *);//переопределение методов
    void mouseMoveEvent(QMouseEvent *e); //переопределение методов


private:

    QGridLayout* gridLayout;
    QHBoxLayout* layout_picture;
    QHBoxLayout* layout_color;
    QHBoxLayout* layout_color2;
    QHBoxLayout* layout_size;

    QPushButton* black;
    QPushButton* white;
    QPushButton* grey;
    QPushButton* blue;
    QPushButton* light_blue;
    QPushButton* green;
    QPushButton* light_green;
    QPushButton* orange;
    QPushButton* yellow;
    QPushButton* red;
    QPushButton* pink;
    QPushButton* purple;

    QPushButton* light_black;
    QPushButton* dark_white;
    QPushButton* light_grey;
    QPushButton* dark_blue;
    QPushButton* light_blue2;
    QPushButton* dark_green;
    QPushButton* light_green2;
    QPushButton* light_orange;
    QPushButton* light_yellow;
    QPushButton* light_red;
    QPushButton* light_pink;
    QPushButton* dark_purple;

    QPushButton* circle1;
    QPushButton* circle2;
    QPushButton* circle3;

    QSlider* slider_size;
    QSpinBox* spinbox_size;

    QLabel* label_picture;


private slots:
    void selectBlack();
    void selectWhite();
    void selectGrey();
    void selectBlue();
    void selectLight_blue2();
    void selectDark_green();
    void selectLight_green2();
    void selectLight_orange();
    void selectLight_yellow();
    void selectLight_red();
    void selectLight_pink();
    void selectDark_purple();

    void selectLight_black();
    void selectDark_white();
    void selectLight_grey();
    void selectDark_blue();
    void selectLight_blue();
    void selectGreen();
    void selectLight_green();
    void selectOrange();
    void selectYellow();
    void selectRed();
    void selectPink();
    void selectPurple();

    void selectCircle1();
    void selectCircle2();
    void selectCircle3();

    void setSizeSlider();
    void setSizeSpinBox();

    void savePicture();
};

#endif // WIDGET_H

