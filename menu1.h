#ifndef MENU1_H
#define MENU1_H

#include <QObject>
#include <QTimer>
class menu1: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString currentTime READ currentTime WRITE setCurrentTime NOTIFY currentTimeChanged FINAL)
public:
    explicit menu1(QObject *parent = nullptr);
    QString currentTime() const;

public slots:
    void setCurrentTime(const QString &newCurrentTime);
    void current_timer_timeout();
signals:
    void currentTimeChanged();
private:
    QString m_currentTime;
    QTimer* m_current_timer;
};

#endif // MENU1_H
