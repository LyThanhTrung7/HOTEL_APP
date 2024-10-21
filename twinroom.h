#ifndef TWINROOM_H
#define TWINROOM_H

#include "room.h"

class TwinRoom : public Room{

public:
    TwinRoom(int numberroom,const QString & name, int phone, const QString & status,const QString & timecheckin,const QString&timecheckout,const QString&timeon,const QString&timeoff);

    double  calu_revenue() override {
        auto checkIn = parseDateTime(CheckInTime);
        auto checkOut = parseDateTime(CheckOutTime);

        auto duration = std::chrono::duration_cast<std::chrono::hours>(checkOut - checkIn);
        int nights = std::ceil(duration.count() / 24.0);
        return rateRoom*nights;
    }

private:
    double rateRoom = 500000;

};

#endif // TWINROOM_H
