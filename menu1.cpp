#include "menu1.h"
#include<QDateTime>

menu1::menu1(QObject *parent) : QObject{parent}
    , m_currentTime("00:00AM")
{    m_current_timer = new QTimer(this);
    m_current_timer->setInterval(500);
    m_current_timer->setSingleShot(false);
    connect(m_current_timer,&QTimer::timeout, this, &menu1 :: current_timer_timeout);
    current_timer_timeout();
    m_current_timer->start();
}

QString menu1::currentTime() const
{
    return m_currentTime;
}

void menu1::setCurrentTime(const QString &newCurrentTime)
{
    if (m_currentTime == newCurrentTime)
        return;
    m_currentTime = newCurrentTime;
    emit currentTimeChanged();
}

void menu1::current_timer_timeout()
{
    QDateTime dateTime;
    QString current_time = dateTime.currentDateTime().toString("hh:mm AP");
    setCurrentTime(current_time);
}


