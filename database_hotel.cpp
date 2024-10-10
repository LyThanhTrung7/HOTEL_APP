#include "database_hotel.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDateTime>
Database_Hotel::Database_Hotel(QObject *parent)
 : QObject(parent)
{

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("ROOM.db");

    if (!db.open()) {
        qDebug() << "Không thể mở cơ sở dữ liệu: " << db.lastError().text();
    } else {
        QSqlQuery query;
         if (!query.exec("CREATE TABLE IF NOT EXISTS ROOM \
                        (ROOM_NUMBER INTEGER, CUS_NAME TEXT, \
                        TIME_CHECKIN TEXT, TIME_CHECKOUT TEXT, \
                        TYPE_ROOM INTEGER, CUS_NUMBER,STATUS)")) {
            qDebug() << "Lỗi khi tạo bảng: " << query.lastError().text();
        }
    }
}
bool Database_Hotel::updateSQL(int room_number, const QString &cus_name, const QString &time_checkin, const QString &time_checkout, int type_room, int cus_number, int status) {
    QSqlQuery query;
    query.prepare("UPDATE ROOM SET CUS_NAME = :cus_name, TIME_CHECKIN = :time_checkin, TIME_CHECKOUT = :time_checkout, TYPE_ROOM = :type_room, CUS_NUMBER = :cus_number, STATUS = :status WHERE ROOM_NUMBER = :room_number");

    query.bindValue(":cus_name", cus_name);
    if(time_checkin!=" ")query.bindValue(":time_checkin", time_checkin);
    query.bindValue(":type_room", type_room);
    query.bindValue(":time_checkout", time_checkout);
    query.bindValue(":cus_number", cus_number);
    query.bindValue(":status", status);
    query.bindValue(":room_number", room_number);

    if (!query.exec()) {
        qDebug() << "Update failed: " << query.lastError().text();
        return false;
    } else {
        qDebug() << "Update succeeded!";
        return true;
    }
}

bool Database_Hotel::addHistory(int room_number, const QString &cus_name, int type_room, int cus_number,const QString &time_checkin, const QString &time_checkout)
{
    QSqlQuery query;

    query.prepare("INSERT INTO HISTORY (ROOM_NUMBER, CUS_NAME, TYPE_ROOM, CUS_NUMBER,TIME_CHECKIN,TIME_CHECKOUT) "
                  "VALUES (:room_number, :cus_name, :type_room, :cus_number,:time_checkin,:time_checkout)");
    query.bindValue(":room_number", room_number);
    query.bindValue(":cus_name", cus_name);
    query.bindValue(":type_room", type_room);
    query.bindValue(":cus_number", cus_number);
    query.bindValue(":time_checkin", time_checkin);
    query.bindValue(":time_checkout", time_checkout);
    if (!query.exec()) {
        qDebug() << "add failed: " << query.lastError().text();
        return false;
    } else {
        qDebug() << "add succeeded!";
        return true;
    }
}

QVariantList Database_Hotel::getData()
{
    QSqlQuery query;
    bool success = query.exec("SELECT ROOM_NUMBER, CUS_NAME, TIME_CHECKIN, TIME_CHECKOUT, TYPE_ROOM, CUS_NUMBER, STATUS FROM ROOM");

    if (!success) {
        qDebug() << "Query failed: " << query.lastError().text();
        return QVariantList();
    } else {
        qDebug() << "Query succeeded!";
    }

    QVariantList rooms;

    while (query.next()) {
        int room_number = query.value(0).toInt();
        QString cus_name = query.value(1).toString();
        QString time_checkin = query.value(2).toString();
        QString time_checkout = query.value(3).toString();
        int type_room = query.value(4).toInt();
        int cus_number = query.value(5).toInt();
        int status = query.value(6).toInt();

        RoomHotel room(room_number, cus_name, time_checkin, time_checkout, type_room, cus_number, status);
        Room.push_back(room);

        // QVariantMap roomData;
        // roomData["ROOM_NUMBER"] = room_number;
        // roomData["CUS_NAME"] = cus_name;
        // roomData["TIME_CHECKIN"] = time_checkin;
        // roomData["TIME_CHECKOUT"] = time_checkout;
        // roomData["TYPE_ROOM"] = type_room;
        // roomData["CUS_NUMBER"] = cus_number;
        // rooms.append(roomData);
    }

    return rooms;
}

bool Database_Hotel::checkRoom(int room_number)
{
    for(auto &room: Room){
        if(room.get_number_room() == room_number && room.status != 3 ){
            return true;
        }
    }
    return false;
}


QString Database_Hotel::dataRoom() const
{
    return m_dataRoom;
}

void Database_Hotel::setDataRoom(const QString &newDataRoom)
{
    if (m_dataRoom == newDataRoom)
        return;
    m_dataRoom = newDataRoom;
    emit dataRoomChanged();
}

int number_room;
QString cus_name;
QString time_checkout;
QString time_checkin;
int type_room;
int cus_phone;
int status;

void Database_Hotel::printDataRoom(int room_number)
 {
    for(auto &room: Room){
        if(room.get_number_room() == room_number && room.status!= 3){
            number_room = room.get_number_room();
            cus_name = room.get_cus_name();
            time_checkin = room.get_time_checkin();
            time_checkout = room.get_time_checkout();
            type_room = room.get_type_room();
            cus_phone = room.get_cus_number();
            status = room.status;
            QString Status;
            if(status == 0) Status = "OFF";
            if(status == 1) Status = "ON";
            if(status == 3) Status = "OUT";
            QString number = QString::number(number_room);
            QString type = QString::number(type_room);
            QString phone = QString::number(cus_phone);
            QString data_room = "Number: " + number +
                                "\nName: "+cus_name+
                                "\nType Room: "+type+
                                "\nPhone Number: "+phone+
                                "\nTime check-out: "+time_checkout+
                                "\nTime check-in: "+time_checkin +
                                "\nStatus: "+Status;
            setDataRoom(data_room);
            break;
        }else{
            setDataRoom("VACANCY");
        }
    }
 }

 QString Database_Hotel::checkIn() const
 {
     return m_checkIn;
 }

 QString Database_Hotel::get_current_time()
 {
    QDateTime current = QDateTime::currentDateTime();
    return current.toString("yyyy-MM-dd HH:mm:ss");
 }

 void Database_Hotel::setCheckIn(const QString &newCheckIn)
 {
     if (m_checkIn == newCheckIn)
         return;
     m_checkIn = newCheckIn;
     emit checkInChanged();
 }

 void Database_Hotel::checkInOut(int num_room, const QString name, int type, int phone,int select)
 {
     bool k = false;
     bool i = false;

     for(auto&room: Room){
        if(num_room == room.get_number_room() && name == room.get_cus_name()){
            if(select == 0){
            QString timecheckin;
             timecheckin = get_current_time();
             updateSQL(num_room,name,timecheckin,"none",type,phone,1);
             room.update_data(num_room,name,timecheckin,"none",1,phone,type);
             setCheckIn("Check-In successful");
             k = true;
            }else{
                 QString timecheckout;
                 timecheckout = get_current_time();
                 updateSQL(num_room,name,room.get_time_checkin(),timecheckout,type,phone,3);
                 room.update_data(num_room,name,room.get_time_checkin(),timecheckout,3,room.get_cus_number(),type);
                 setCheckIn("Check-Out successful");
                 i = true;
            }
          }
        }
     if(k == false && i == false) setCheckIn("No information!!!");
 }

 QString Database_Hotel::booking() const
 {
     return m_booking;
 }

 void Database_Hotel::setBooking(const QString &newBooking)
 {
     if (m_booking == newBooking)
         return;
     m_booking = newBooking;
     emit bookingChanged();
 }

 void Database_Hotel::Booking(int room_number, const QString name, const QString timecheckin, int type, int phone)
 {
     bool book = false;
     for(auto &room: Room){
         if(room_number == room.get_number_room() && room.status == 3)
         {
                 addHistory(room_number,room.get_cus_name(),room.get_type_room(),room.get_cus_number(),room.get_time_checkin(),room.get_time_checkout());
                 updateSQL(room_number,name,timecheckin,"none",type,phone,0);
                 room.update_data(room_number,name,timecheckin,"",0, phone,type);
                 setBooking("Booking successful");
                 book = true;
             break;
        }
     }
     if(book == false) setBooking("Booking false!!!");
 }

 QVariantList Database_Hotel::getHistory()
 {
     QSqlQuery query;
     bool success = query.exec("SELECT ROOM_NUMBER, CUS_NAME, TIME_CHECKIN, TIME_CHECKOUT, TYPE_ROOM,CUS_NUMBER FROM HISTORY");
     if (!success) {
         qDebug() << "Query HISTORY failed: " << query.lastError().text();
     } else {
         qDebug() << "Query HISTORY succeeded!";
     }
     QVariantList his;

     while (query.next()) {
         QVariantMap user;
         user["ROOM_NUMBER"] = query.value(0).toInt();
         user["CUS_NAME"] = query.value(1).toString();
         user["TIME_CHECKIN"] = query.value(2).toString();
         user["TIME_CHECKOUT"] = query.value(3).toString();
         user["TYPE_ROOM"] = query.value(4).toInt();
         user["CUS_NUMBER"] = query.value(5).toInt();
         his.append(user);
     }
     setHistory(his);
     return his;
 }

 QVariantList Database_Hotel::History() const
 {
     return m_History;
 }

 void Database_Hotel::setHistory(const QVariantList &newHistory)
 {
     if (m_History == newHistory)
         return;
     m_History = newHistory;
     emit HistoryChanged();
 }


