#include "viproom.h"

VipRoom::VipRoom(int numberroom, const QString & name, int phone, const QString & status,const QString & timecheckin,const QString&timecheckout,const QString&timeon,const QString&timeoff):
    Room(numberroom,name,phone,"Vip Room",status,timecheckin,timecheckout,timeon,timeoff){}


