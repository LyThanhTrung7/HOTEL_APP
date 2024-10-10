#include "roomhotel.h"
#include <QDebug>

RoomHotel::RoomHotel(int number, const QString &name, const QString &checkIn, const QString &checkOut, int type, int numberOfGuests,int tt)
    : Room_number(number), Cus_name(name), Time_checkin(checkIn), Time_checkout(checkOut), type_room(type), cus_number(numberOfGuests), status(tt) {}
