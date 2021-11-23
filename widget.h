#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QPropertyAnimation;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);

    ~Widget();

protected:
    const QString popImage();

    void takeAnimation();

    void timerEvent( QTimerEvent *event );

private:
    void onAnimation0Finished();

    void onAnimation1Finished();

signals:
    void TakeAnimation();

private:
    QVector<QString>    aryImage;

    QWidget             *widget0;

    QWidget             *widget1;

    QPropertyAnimation  *animation0;

    QPropertyAnimation  *animation1;

    Ui::Widget          *ui;
};
#endif // WIDGET_H
