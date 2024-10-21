#include "twinroom.h"

TwinRoom::TwinRoom(int numberroom, const QString & name, int phone, const QString & status,const QString & timecheckin,const QString&timecheckout,const QString&timeon,const QString&timeoff):
    Room(numberroom,name,phone,"Twin Room",status,timecheckin,timecheckout,timeon,timeoff){}


