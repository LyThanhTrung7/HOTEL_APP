#include "databasehotel.h"
#include "tripleroom.h"
#include "twinroom.h"
#include "viproom.h"
#include <QSqlQuery>
#include <QSqlError>
#include <memory>
#include <QLocale>
#include <QDateTime>
#include <QDebug>
#include <vector>
DataBaseHotel::DataBaseHotel() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("ROOM.db");

    if (!db.open()) {
        qDebug() << "Không thể mở cơ sở dữ liệu: " << db.lastError().text();
    }
}

void DataBaseHotel::loadRoomsFromDatabase()
{
    QSqlQuery query;

    bool success = query.exec("SELECT ROOM_NUMBER,TYPE_ROOM,CUS_NAME,PHONE, TIME_CHECKIN, TIME_CHECKOUT, STATUS,TIME_BOOKING_ON,TIME_BOOKING_OFF FROM room");

    if (!success) {
        qDebug() << "Query failed: " << query.lastError().text();
    } else {
        qDebug() << "Query succeeded!";
    }
    while (query.next()) {
        int roomId = query.value(0).toInt();
        QString roomType = query.value(1).toString();
        QString name = query.value(2).toString();
        int phone = query.value(3).toInt();
        QString timeCheckin  = query.value(4).toString();
        QString timeCheckout  = query.value(5).toString();
        QString roomStatus = query.value(6).toString();
        QString timeon = query.value(7).toString();
        QString timeoff = query.value(8).toString();

        qDebug() << roomType;

        if(roomType == "Twin Room"){
            std::unique_ptr<TwinRoom> twinroom(new TwinRoom(roomId,name,phone, roomStatus,timeCheckin,timeCheckout,timeon,timeoff));
            //  auto twinroom = std::make_unique<TwinRoom>(roomId, roomStatus);
            rooms.push_back(std::move(twinroom));
            qDebug() << "Added Twin Room with ID:" ;
        }else if(roomType == "Triple Room"){
            std::unique_ptr<TripleRoom> tripleroom(new TripleRoom(roomId,name,phone, roomStatus, timeCheckin,timeCheckout,timeon,timeoff));
            //auto tripleroom = std::make_unique<TripleRoom>(roomId, roomStatus);
            rooms.push_back(std::move(tripleroom));
            qDebug() << "Added Triple Room with ID:" ;
        }else if(roomType == "Vip Room"){
            std::unique_ptr<VipRoom> viproom(new VipRoom(roomId,name,phone,roomStatus,timeCheckin,timeCheckout,timeon,timeoff));
            // auto viproom = std::make_unique<VipRoom>(roomId, roomStatus);
            rooms.push_back(std::move(viproom));
            qDebug() << "Added Vip Room with ID:" ;
        }
    }
}

void DataBaseHotel::addRoomForDatabase(int num, const QString &name, int phone, const QString &status, const QString &type, const QString &timeon, const QString &timeoff)
{
    QSqlQuery query;
    query.prepare("INSERT INTO room (ROOM_NUMBER,TYPE_ROOM, CUS_NAME, PHONE,STATUS,TIME_BOOKING_ON,TIME_BOOKING_OFF)"
                  "VALUES (:room_number,:type_room, :cus_name,:cus_number,:status,:timeon,:timeoff)");

    query.bindValue(":room_number", num);
    query.bindValue(":type_room", type);
    query.bindValue(":cus_name", name);
    query.bindValue(":cus_number", phone);
    query.bindValue(":timeon", timeon);
    query.bindValue(":timeoff", timeoff);
    query.bindValue(":status", status);

    if (!query.exec()) {
        qDebug() << "add failed: " << query.lastError().text();

    } else {
        qDebug() << "add succeeded!";
    }
}

QString DataBaseHotel::Booking(int number_room, const QString &name, int phone,const QString &type, const QString &date, const QString &dateout)
{

    for(auto& Room: rooms){
        if(number_room == Room->getRoomNumber() && type == Room->getRoomType()){
            if(Room->getRoomStatus() == "CHECKED-OUT"){
                Room->setTimeBookingOn(date);
                Room->setTimeBookingOff(dateout);
                Room->setTimeCheckin("");
                Room->setTimeCheckout("");
                Room->setStatus("BOOKED");
                Room->setName(name);
                Room->setPhone(phone);
                updateData(number_room,name,phone,"","","BOOKED",type,date,dateout);
                return "BOOKING SUCCESSFUL";
            }else{
                for (const auto& r : rooms) {
                    if (number_room == r->getRoomNumber() && type == r->getRoomType()) {
                        if (!(date < r->getBookingOn() || date > r->getBookingOff())) {
                            return "ROOM NOT AVAILABLE";
                        }
                    }
                }
                if(type == "Twin Room"){
                    std::unique_ptr<TwinRoom> twinroom(new TwinRoom(number_room,name,phone, "BOOKED","","",date,dateout));
                    rooms.push_back(std::move(twinroom));
                    qDebug() << "Added Twin Room with ID:" ;
                }else if(type == "Triple Room"){
                    std::unique_ptr<TripleRoom> tripleroom(new TripleRoom(number_room,name,phone, "BOOKED","","",date,dateout));
                    rooms.push_back(std::move(tripleroom));
                    qDebug() << "Added Triple Room with ID:" ;
                }else if(type == "Vip Room"){
                    std::unique_ptr<VipRoom> viproom(new VipRoom(number_room,name,phone, "BOOKED","","",date,dateout));
                    rooms.push_back(std::move(viproom));
                    qDebug() << "Added Vip Room with ID:" ;
                }
                addRoomForDatabase(number_room,name,phone,"BOOKED",type,date,dateout);
            }

            return "BOOKING SUCCESSFUL";
        }
    }

    return "BOOKING FAIL";
}

QString DataBaseHotel::checkIn(int numberroom, const QString &type)
{
    QDateTime current = QDateTime::currentDateTime();
    QString currentDateTime = current.toString("yyyy-MM-dd HH:mm:ss");

    for(auto& Room: rooms){
        if(numberroom == Room->getRoomNumber() && type == Room->getRoomType()){
            Room->setTimeCheckin(currentDateTime);
            Room->setStatus("CHECKED-IN");
            updateData(numberroom,Room->getName(),Room->getPhone(),currentDateTime,"",Room->getRoomStatus(),type,Room->getBookingOn(),Room->getBookingOff());
            return "CHECKIN SUCCESSFUL";
        }
    }
    return "CHECK-IN FAIL";
}

QString DataBaseHotel::checkOut(int numberroom, const QString &type)
{
    QDateTime current = QDateTime::currentDateTime();
    QString currentDateTime = current.toString("yyyy-MM-dd HH:mm:ss");

    for(auto& Room: rooms){
        if(numberroom == Room->getRoomNumber() && type == Room->getRoomType() && Room->getRoomStatus() == "CHECKED-IN"){
            Room->setTimeCheckout(currentDateTime);
            Room->setStatus("CHECKED-OUT");
            updateData(numberroom,Room->getName(),Room->getPhone(),Room->getCheckintime(),currentDateTime,Room->getRoomStatus(),type,"","");


            QString number = QString::number(Room->getRoomNumber());

            QLocale locale = QLocale::system();
            QString formattedMoney = locale.toString(Room->calu_revenue(), 'f', 2);
            QString status = "CHECKED-OUT SUCCESSFUL"
                             "\nRoom: "+ number +
                             "\nType: "+ Room->getRoomType()+
                             "\nName: "+ Room->getName()+
                             "\nTime check-in: "+Room->getCheckintime()+
                             "\nTime check-out: "+Room->getCheckoutime()+
                             "\nPrice: "+formattedMoney+" VND";

            addHistory(Room->getRoomNumber(),Room->getRoomType(),Room->getName(),Room->getPhone(),Room->getCheckintime(),Room->getCheckoutime(),formattedMoney);

            return status;
        }
    }
    return "CHECK-OUT FAIL";
}

void DataBaseHotel::addHistory(int numerroom, const QString &type, const QString &name, int phone, const QString &timecheckin, const QString &timecheckout, const QString &price)
{
    QSqlQuery query;
    query.prepare("INSERT INTO HISTORY (ROOM_NUMBER,TYPE_ROOM, CUS_NAME, CUS_NUMBER,TIME_CHECKIN,TIME_CHECKOUT,REVENUE) "
                  "VALUES (:room_number,:type_room, :cus_name, :cus_number,:time_checkin,:time_checkout,:revenue)");

    query.bindValue(":room_number", numerroom);
    query.bindValue(":type_room", type);
    query.bindValue(":cus_name", name);
    query.bindValue(":cus_number", phone);
    query.bindValue(":time_checkin", timecheckin);
    query.bindValue(":time_checkout", timecheckout);
    query.bindValue(":revenue", price);

    if (!query.exec()) {
        qDebug() << "add failed: " << query.lastError().text();

    } else {
        qDebug() << "add succeeded!";
    }
}

QVariantList DataBaseHotel::readHistory()
{
    QSqlQuery query;
    bool success = query.exec("SELECT ROOM_NUMBER,TYPE_ROOM, CUS_NAME,CUS_NUMBER, TIME_CHECKIN, TIME_CHECKOUT,REVENUE FROM HISTORY");
    if (!success) {
        qDebug() << "Query HISTORY failed: " << query.lastError().text();
    } else {
        qDebug() << "Query HISTORY succeeded!";
    }
    QVariantList his;

    while (query.next()) {
        QVariantMap user;
        user["ROOM_NUMBER"] = query.value(0).toInt();
        user["TYPE_ROOM"] = query.value(1).toString();
        user["CUS_NAME"] = query.value(2).toString();
        user["CUS_NUMBER"] = query.value(3).toInt();
        user["TIME_CHECKIN"] = query.value(4).toString();
        user["TIME_CHECKOUT"] = query.value(5).toString();
        user["REVENUE"] = query.value(6).toString();
        his.append(user);
    }
    return his;
}

void DataBaseHotel::updateData(int num,const QString& name, int phone, const QString& checkin,const QString& checkout,const QString& status,const QString& type,const QString& timeon,const QString& timeoff)
{
    QSqlQuery query;
    query.prepare("UPDATE room SET TIME_CHECKIN = :time_checkin, TIME_CHECKOUT = :time_checkout, STATUS = :status, TYPE_ROOM =:type_room, CUS_NAME=:name, Phone=:phone,TIME_BOOKING_ON=:timeon,TIME_BOOKING_OFF=:timeoff WHERE ROOM_NUMBER = :room_number");
    query.bindValue(":room_number", num);

    query.bindValue(":time_checkin", checkin);

    query.bindValue(":time_checkout", checkout);

    query.bindValue(":status", status);

    query.bindValue(":type_room", type);

    query.bindValue(":name", name);

    query.bindValue(":timeon", timeon);

    query.bindValue(":timeoff", timeoff);

    query.bindValue(":phone", phone);

    if (!query.exec()) {
        qDebug() << "Failed to update data: " << query.lastError().text();
    }
}


