# RTC-DST-Adjustment
Adjusting a RTC (hardware) For DST

Just call the Function Adjust_RTC_For_DST();

before you read the time.

You have to adjust the rule to suite your region!

This rules checks for the last Sunday in March to move the clock forward and then the last Sundayin October to move the time back again.

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
