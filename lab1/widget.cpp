#include "widget.h"
#include "time.h"

#include <QSignalMapper>
#include <QtWidgets>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    srand(time(NULL));
    this->resize(400, 350);
    this->setWindowTitle("Funny Balls");
    this->setStyleSheet("background: white;");

    sound = new QSound(".//sound.wav");

    layout = new QHBoxLayout;
    this->setLayout(layout);

    layout_right = new QVBoxLayout;
    layout_central = new QVBoxLayout;
    layout_left = new QVBoxLayout;

    layout->addLayout(layout_left);
    layout->addLayout(layout_central);
    layout->addLayout(layout_right);

    fast = new QCheckBox(this);
    fast->setText("Fast");
    layout_left->addWidget(fast);
    connect(fast, SIGNAL(clicked()), this, SLOT(fast_checked()));
    fast->setStyleSheet("font : 22px;"
                        "color: #473C8B;");

    slow = new QCheckBox(this);
    slow->setText("Slow");
    layout_left->addWidget(slow);
    connect(slow, SIGNAL(clicked()), this, SLOT(slow_checked()));
    slow->setStyleSheet("font : 22px;"
                        "color: #473C8B;");

    two = new QCheckBox(this);
    two->setText("Two balls");
    layout_right->addWidget(two);
    two->setStyleSheet("margin-left: 50px;");
    connect(two, SIGNAL(clicked()), this, SLOT(two_checked()));
    two->setStyleSheet("font : 22px;"
                        "color: #008B8B;");

    one = new QCheckBox(this);
    one->setText("One ball");
    layout_right->addWidget(one);
    one->setStyleSheet("margin-left: 50px;");
    connect(one, SIGNAL(clicked()), this, SLOT(one_checked()));
    one->setStyleSheet("font : 22px;"
                        "color: #008B8B;");


    button_start = new QPushButton(this);
    layout_central->addWidget(button_start);
    button_start->resize(30,30);
    button_start->setText("START");
    button_start->setStyleSheet( "background-color: #2E8B57;"
                                 "border-radius: 15px;"
                                 "width: 30px;"
                                 "color : white;"
                                 "font: bold 25px;"
                           );


    connect(button_start, SIGNAL(clicked()), this, SLOT(start()));

    label = new QLabel;
    label->setText("0");
    label->resize(70,40);
    label->setStyleSheet( "background: white;"
                          "font: bold 45px;"
                          "color : #5F9EA0;"
                          "margin-top: 270px;"
                          "margin-left: 150px;"
                          );
    layout_central->addWidget(label);
    label->setVisible(false);
}

Widget::~Widget()
{
}

void Widget::fast_checked()
{
    if(slow->isChecked()) slow->setChecked(false);
}

void Widget::slow_checked()
{
    if(fast->isChecked()) fast->setChecked(false);
}

void Widget::two_checked()
{
    if(one->isChecked()) one->setChecked(false);
}

void Widget::one_checked()
{
    if(two->isChecked()) two->setChecked(false);
}

void Widget::start()
{
    slow->setVisible(false);
    fast->setVisible(false);
    two->setVisible(false);
    one->setVisible(false);
    if(slow->isChecked())
    {
        time_for_timer=1800;
    } else
        if(fast->isChecked())
        {
            time_for_timer=1000;
        } else
        {
            err = new QMessageBox();
            err->information(this, "Error", "You should choose speed.");
            this->close();
        }

    if(one->isChecked())
    {

        button = new QPushButton(this);
        button->resize(30,30);
        button->setStyleSheet( "background-color: red;"
                "border-style: outset;"
                "border-width: 3px;"
                "border-radius: 15px;"
                "border-color: #FA8072;"
                               );

        timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(timer_slot()));
        timer->start(time_for_timer);

        connect(button, SIGNAL(clicked()), this, SLOT(score()));
    } else
        if (two->isChecked())
        {
            button = new QPushButton(this);
            button->resize(30,30);
            button->setStyleSheet( "background-color: red;"
                    "border-style: outset;"
                    "border-width: 3px;"
                    "border-radius: 15px;"
                    "border-color: #FA8072;"
                                   );
            button_two = new QPushButton(this);
            button_two->resize(30,30);
            button_two->setStyleSheet( "background-color: #8B7D6B;"
                    "border-style: outset;"
                    "border-width: 3px;"
                    "border-radius: 15px;"
                    "border-color: #FFDAB9;"
                                   );

            timer = new QTimer();
            connect(timer, SIGNAL(timeout()), this, SLOT(timer_slot_two()));
            timer->start(time_for_timer);

            connect(button, SIGNAL(clicked()), this, SLOT(score()));
            connect(button_two, SIGNAL(clicked()), this, SLOT(score_two()));
        } else
        {
            errb = new QMessageBox();
            errb->information(this, "Error", "You should choose amount of balls.");
            this->close();
        }
    button_start->setVisible(false);
    label->setVisible(true);

}

void Widget::score()
{
    schet++;
    if(schet == 1)
    {
        sound->play();
        QString value = label->text();
        int valueInt = value.toInt()+1;
        label->setText(QString("%1").arg(valueInt));
    }
}

void Widget::score_two()
{
    schet_two++;
    if(schet_two ==1)
    {
        sound->play();
        QString value = label->text();
        int valueInt = value.toInt()+1;
        label->setText(QString("%1").arg(valueInt));
    }
}

void Widget::timer_slot()
{
    int x = rand()%321+30;
    int y = rand()%201+30;
    button->setGeometry(x,y, 30,30);
    button->show();

    if(schet!=0){
        schet=0;
    } else {
        timer->stop();
        QString value = label->text();
        int valueInt = value.toInt();
        mess = new QMessageBox();
        mess->information(this, "Fail", "You score is "+QString("%1").arg(valueInt));
        this->close();
    }
}

void Widget::timer_slot_two()
{
    int x1 = rand()%321+30;
    int y1 = rand()%181+30;
    int x2 = rand()%311+30;
    int y2 = rand()%201+30;
    button->setGeometry(x1,y1, 30,30);
    button->show();
    button_two->setGeometry(x2,y2, 30,30);
    button_two->show();
    if(schet!=0 && schet_two!=0){
        schet=0;
        schet_two=0;
    } else {
        timer->stop();
        QString value = label->text();
        int valueInt = value.toInt();
        mess = new QMessageBox();
        mess->information(this, "Fail", "You score is "+QString("%1").arg(valueInt));
        this->close();
    }


}
