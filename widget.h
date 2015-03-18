#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QSignalMapper>
#include <QMessageBox>
#include <QTimer>
#include <QCheckBox>
#include <QtMultimedia/QSound>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    QHBoxLayout *layout;
    QVBoxLayout *layout_right;
    QVBoxLayout *layout_central;
    QVBoxLayout *layout_left;
    QLabel *label;
    QPushButton *button_start;
    QCheckBox *slow;
    QCheckBox *fast;
    QCheckBox *one;
    QCheckBox *two;
    QPushButton *button;
    QPushButton *button_two;
    QMessageBox *mess;
    QMessageBox *err;
    QMessageBox *errb;
    QTimer *timer;
    QSound *sound;
    int schet=1;
    int schet_two=1;
    int time_for_timer;

public slots:
    void score();
    void score_two();
    void timer_slot();
    void timer_slot_two();
    void start();
    void fast_checked();
    void slow_checked();
    void one_checked();
    void two_checked();
};

#endif // WIDGET_H

