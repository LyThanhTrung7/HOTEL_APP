#ifndef DATABASE_HOTEL_H
#define DATABASE_HOTEL_H

#include <QObject>
#include <QSqlDatabase>
#include <QStringList>
#include <QVariantList>
#include "roomhotel.h"
#include <vector>

class Database_Hotel: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString dataRoom READ dataRoom WRITE setDataRoom NOTIFY dataRoomChanged FINAL)
    Q_PROPERTY(QString checkIn READ checkIn WRITE setCheckIn NOTIFY checkInChanged FINAL)
    Q_PROPERTY(QString booking READ booking WRITE setBooking NOTIFY bookingChanged FINAL)
    Q_PROPERTY(QVariantList History READ History WRITE setHistory NOTIFY HistoryChanged FINAL)

public:
    explicit Database_Hotel(QObject *parent = nullptr);

    QString dataRoom() const;

     void addcustomer(const QString &name);
     void deleteNumber(int id);
     bool updateSQL(int room_number, const QString &cus_name, const QString &time_checkin, const QString &time_checkout, int type_room, int cus_number, int status);
     bool addHistory(int room_number, const QString &cus_name, int type_room, int cus_number,const QString &time_checkin, const QString &time_checkout);
     bool updateHistory(int room_number, const QString &cus_name,const QString &time_checkin, const QString &time_checkout);
     QString checkIn() const;
     QString get_current_time();
     QString booking() const;

     QVariantList History() const;

     bool check_room() const;

 public slots:
     QVariantList getData();

     bool checkRoom(int room_number);
     void setDataRoom(const QString &newDataRoom);
     void printDataRoom(int room_number);
     void setCheckIn(const QString &newCheckIn);
     void checkInOut(int room, const QString name, int type, int phone, int select);
     void setBooking(const QString &newBooking);
     void Booking(int room, const QString name, const QString timecheckin, int type, int phone);
     void setHistory(const QVariantList &newHistory);
     QVariantList getHistory();
 signals:

     void dataRoomChanged();

     void checkInChanged();

     void bookingChanged();

     void HistoryChanged();


 private:
    QSqlDatabase db;
    std::vector<RoomHotel> Room;
    QString m_dataRoom;
    QString m_checkIn;
    QString m_booking;
    QVariantList m_History;
};

#endif // DATABASE_HOTEL_H







