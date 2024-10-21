#ifndef DATABASEHOTEL_H
#define DATABASEHOTEL_H

#include "room.h"
#include <vector>
#include <QSqlDatabase>

class DataBaseHotel
{
public:
    DataBaseHotel();

    void loadRoomsFromDatabase();
    void addRoomForDatabase(int num,const QString& name, int phone,const QString& status,const QString& type,const QString& timeon ,const QString& timeoff);

    QString Booking(int number_room,const QString &name, int phone,const QString& type, const QString &datein,const QString &dateout );

    QString checkIn(int numberroom,const QString& type);
    QString checkOut(int numberroom,const QString& type);
    void addHistory(int numerroom,const QString& type, const QString& name, int phone,const QString& timecheckin,const QString& timecheckout,const QString& price);
    QVariantList readHistory();

    const std::vector<std::unique_ptr<Room>>& getRooms() const {
        return rooms;
    }

    void updateData(int num,const QString& name, int phone, const QString& checkin,const QString& checkout,const QString& status,const QString& type,const QString& timeon ,const QString& timeoff);

private:
     std::vector<std::unique_ptr<Room>> rooms;
     QSqlDatabase db;
};

#endif // DATABASEHOTEL_H
