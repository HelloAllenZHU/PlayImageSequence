#include <QPropertyAnimation>
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
            QWidget(parent),
            ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);

    // image
    aryImage << "c:/1.jpg"
             << "c:/2.jpg"
             << "c:/3.jpg";

    // widget
    widget0 = new QWidget( this );
    widget0->setFixedSize( 375, 200 );

    widget1 = new QWidget( this );
    widget1->setFixedSize( 375, 200 );

    // animation
    animation0 = new QPropertyAnimation();
    animation1 = new QPropertyAnimation();

    takeAnimation();

    startTimer( 4000 );
}

Widget::~Widget()
{
    delete animation0;
    delete animation1;
    delete ui;
}

const QString Widget::popImage()
{
    auto img = aryImage.first();
    aryImage.pop_front();
    aryImage.push_back( img );
    return img;
}

void Widget::takeAnimation()
{
    if ( animation0->targetObject() == nullptr ) {
        widget0->setStyleSheet( QString( "border-image: url(%1);" ).arg( popImage() ) );
        animation0->setTargetObject( widget0 );
    } else if ( animation0->targetObject() == widget1 ) {
        animation0->setTargetObject( widget0 );
    } else if ( animation0->targetObject() == widget0 ) {
        animation0->setTargetObject( widget1 );
    }

    animation0->setPropertyName( "geometry" );
    animation0->setDuration( 1500 );
    animation0->setStartValue( QRect( 0, 0, 375, 200 ) );
    animation0->setEndValue( QRect( -375, 0, 0, 200 ) );
    animation0->start();

    if ( animation1->targetObject() == nullptr ) {
        widget1->setStyleSheet( QString( "border-image: url(%1);" ).arg( popImage() ) );
        animation1->setTargetObject( widget1 );
    } else if ( animation1->targetObject() == widget0 ) {
        widget1->setStyleSheet( QString( "border-image: url(%1);" ).arg( popImage() ) );
        animation1->setTargetObject( widget1 );
    } else if ( animation1->targetObject() == widget1 ) {
        widget0->setStyleSheet( QString( "border-image: url(%1);" ).arg( popImage() ) );
        animation1->setTargetObject( widget0 );
    }

    animation1->setPropertyName( "geometry" );
    animation1->setDuration( 1500 );
    animation1->setStartValue( QRect( 375, 0, 750, 200 ) );
    animation1->setEndValue( QRect( 0, 0, 375, 200 ) );
    animation1->start();
}

void Widget::timerEvent( QTimerEvent *event )
{
    takeAnimation();
}
