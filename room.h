#ifndef ROOM_H
#define ROOM_H

#include <QString>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

class Room
{
public:
    Room(int roomnumber,const QString &name, int phone, const QString &type,const QString & status,const QString&timecheckin,const QString&timecheckout,const QString&timeon,const QString&timeoff);

    virtual ~Room() = default;

    virtual double calu_revenue() = 0;
    void update_status(const QString & status){
        RoomStatus = status;
    }
    QString display_infor() {
            QString number = QString::number(RoomNumber);
            QString phone = QString::number(Phone);
            QString room = "Number room: " + number
                           +"\nType room: " + RoomType
                           +"\nName: " + Name
                           +"\nPhone: " + phone
                           +"\nStatus: " + RoomStatus
                           +"\nTime Booking: "+TimeBookingOn+" -> "+TimeBookingOFF
                           +"\nTime Check-in: "+ CheckInTime
                           +"\nTime Check-Out: "+CheckOutTime;
            return room;
    }

     void setTimeCheckin(const QString & data) {
         CheckInTime = data;
     }
     void setTimeCheckout(const QString & data) {
         CheckOutTime = data;
     }
     void setName(const QString & data) {
         Name = data;
     }
     void setPhone(int data) {
         Phone = data;
     }
     void setStatus(const QString & data) {
         RoomStatus = data;
     }

     void setTimeBookingOn(const QString &data){
         TimeBookingOn = data;
     }
     void setTimeBookingOff(const QString &data){
         TimeBookingOFF = data;
     }

    int getRoomNumber() const { return RoomNumber;}
    QString getRoomType()const{return RoomType;}
    QString getRoomStatus() const{return RoomStatus;}
    QString getCheckintime() const {return CheckInTime;}
    QString getCheckoutime()const {return CheckOutTime;}
    QString getName()const {return Name;}
    int getPhone()const {return Phone;}

    QString getBookingOn() {return TimeBookingOn;}
    QString getBookingOff(){return TimeBookingOFF;}

    std::chrono::system_clock::time_point parseDateTime(const QString& dateTimeStr) {
        std::string dateTimeStdStr = dateTimeStr.toStdString();
        std::tm tm = {};
        std::istringstream ss(dateTimeStdStr);
        ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
        return std::chrono::system_clock::from_time_t(std::mktime(&tm));
    }

protected:
    int RoomNumber;
    QString RoomType;
    QString RoomStatus;
    QString CheckInTime;
    QString CheckOutTime;
    QString TimeBookingOn;
    QString TimeBookingOFF;
    QString Name;
    int Phone;
};


#endif // ROOM_H
