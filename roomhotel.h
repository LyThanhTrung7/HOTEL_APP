#ifndef ROOMHOTEL_H
#define ROOMHOTEL_H

#include <QString>

class RoomHotel
{
public:
    RoomHotel(int number, const QString &name, const QString &checkIn, const QString &checkOut, int type, int numberOfGuests, int status);

    RoomHotel(const RoomHotel &other)
        : Room_number(other.Room_number), Cus_name(other.Cus_name),
        Time_checkin(other.Time_checkin), Time_checkout(other.Time_checkout),
        type_room(other.type_room), cus_number(other.cus_number), status(other.status) {}

    int get_number_room()const{return Room_number;}
    int get_cus_number()const{return cus_number;}
    QString get_cus_name()const{return Cus_name;}
    QString get_time_checkin()const{return Time_checkin;}
    QString get_time_checkout()const{return Time_checkout;}
    int get_type_room()const{return type_room;}
    int status;

    void update_data(int room_number,const QString &name,const QString &time_checkin,const QString &time_checkout,int Status,int Cus_number,int type){
        Room_number = room_number;
        if(Time_checkin!=" ")Time_checkin = time_checkin;
        Time_checkout = time_checkout;
        status = Status;
        cus_number = Cus_number;
        type_room = type;
        Cus_name = name;
    }

private:
    int Room_number;
    QString Cus_name;
    QString Time_checkin;
    QString Time_checkout;
    int type_room;
    int cus_number;
};
#endif // ROOMHOTEL_H
