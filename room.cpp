#include "room.h"


Room::Room(int roomnumber,const QString & name, int phone, const QString &type,const QString & status,const QString & timecheckin,const QString&timecheckout,const QString&timeon,const QString&timeoff)
    :RoomNumber(roomnumber),Name(name),Phone(phone),RoomType(type),RoomStatus(status),CheckInTime(timecheckin),CheckOutTime(timecheckout),TimeBookingOn(timeon),TimeBookingOFF(timeoff) {}
