#include "actionhotel.h"

ActionHotel::ActionHotel(DataBaseHotel &dbHotel, QObject *parent):
    QObject(parent), hotel(dbHotel)
{

}

ActionHotel::~ActionHotel()
{

}

QString ActionHotel::room() const
{
    return m_room;
}

void ActionHotel::setRoom(const QString &newRoom)
{
    if (m_room == newRoom)
        return;
    m_room = newRoom;
    emit roomChanged();
}


bool ActionHotel::inforRoom(const QString& data, int number_room)
{
    const auto& rooms = hotel.getRooms();
    for(auto &room: rooms){
        if(data == room->getBookingOn()){
            if(number_room == room->getRoomNumber() && (room->getRoomStatus() == "CHECKED-IN"||room->getRoomStatus() == "BOOKED")){
                QString Room = room->display_infor();
                setRoom(Room);
                return true;
            }
        }
    }
    setRoom("Vacant room");
    return false;
}

void ActionHotel::bookingRoom(int number_room, const QString &name, int phone, const QString& type, const QString &date,const QString &dateout )
{
    setBook(hotel.Booking(number_room,name,phone,type, date,dateout));
}

void ActionHotel::checkin(int number_room, const QString &type)
{
    setStatus(hotel.checkIn(number_room,type));
}

void ActionHotel::checkout(int number_room, const QString &type)
{
    setStatus(hotel.checkOut(number_room,type));
}

void ActionHotel::history(int number_room, const QString &type)
{
    setHis(hotel.readHistory());
}

QString ActionHotel::book() const
{
    return m_book;
}

void ActionHotel::setBook(const QString &newBook)
{
    if (m_book == newBook)
        return;
    m_book = newBook;
    emit bookChanged();
}

QString ActionHotel::status() const
{
    return m_status;
}

void ActionHotel::setStatus(const QString &newStatus)
{
    if (m_status == newStatus)
        return;
    m_status = newStatus;
    emit statusChanged();
}

QVariantList ActionHotel::his() const
{
    return m_his;
}

void ActionHotel::setHis(const QVariantList &newHis)
{
    if (m_his == newHis)
        return;
    m_his = newHis;
    emit hisChanged();
}
