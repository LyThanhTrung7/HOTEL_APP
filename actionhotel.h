#ifndef ACTIONHOTEL_H
#define ACTIONHOTEL_H

#include <QObject>
#include <QQmlEngine>
#include "databasehotel.h"
#include "tripleroom.h"
#include "twinroom.h"
#include "viproom.h"
#include <vector>

class ActionHotel: public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString room READ room WRITE setRoom NOTIFY roomChanged FINAL)
    Q_PROPERTY(QString book READ book WRITE setBook NOTIFY bookChanged FINAL)
    Q_PROPERTY(QString status READ status WRITE setStatus NOTIFY statusChanged FINAL)
    Q_PROPERTY(QVariantList  his READ his WRITE setHis NOTIFY hisChanged FINAL)
public:
    explicit ActionHotel(DataBaseHotel &dbHotel, QObject *parent = nullptr);
    ~ActionHotel();

    QString room() const;
    void setRoom(const QString &newRoom);

    QString book() const;
    void setBook(const QString &newBook);


    QString status() const;
    void setStatus(const QString &newStatus);

    QVariantList his() const;
    void setHis(const QVariantList &newHis);

public slots:
    bool inforRoom(const QString& data,int number_room);
    void bookingRoom(int number_room, const QString &name, int phone, const QString &type, const QString &date, const QString &dateout);
    void checkin(int number_room, const QString &type);
    void checkout(int number_room, const QString &type);
    void history(int number_room, const QString &type);
signals:
    void roomChanged();

    void bookChanged();

    void statusChanged();

    void hisChanged();

private:
    DataBaseHotel &hotel;
    QString m_room;
    QString m_book;
    QString m_status;
    QVariantList m_his;
};

#endif // ACTIONHOTEL_H
