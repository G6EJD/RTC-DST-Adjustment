#include <EEPROM.h>

void Adjust_RTC_For_DST(){
  int DST = EEPROM.read(0);
  if (now.dayOfTheWeek() == 0 && now.month() == 3 && now.day() >= 25 && now.day() <= 31 && now.hour() == 2 && now.minute() >= 0 && now.second() >= 0 && DST == 0) {  
    rtc.adjust(DateTime(now.year(), now.month(), now.day(), now.hour()+1, now.minute(), now.second()));      
    DST = 1;      
    EEPROM.write(0, DST);  
   }    
   else 
   if(now.dayOfTheWeek() == 0 && now.month() == 10 && now.day() >= 25 && now.day() <= 31 && now.hour() == 3 && now.minute() >= 0 && now.second() >= 0 && DST == 1){      
     rtc.adjust(DateTime(now.year(), now.month(), now.day(), now.hour()-1, now.minute(), now.second()));      
     DST = 0;
     EEPROM.write(0, DST);    
   }
}
