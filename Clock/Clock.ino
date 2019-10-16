#include <LiquidCrystal.h>
#include <Wire.h>
#include "RTClib.h"

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
//LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
RTC_DS1307 rtc;

void setup() {
  // set up the LCD's number of columns and rows:
  Wire.begin();
  rtc.begin();
  lcd.begin(16, 2);
  if (!rtc.isrunning()) {
    rtc.adjust(DateTime(2019, 10, 15, 23, 59, 30));
  }
}

void loop() {
  DateTime now = rtc.now();
  lcd.setCursor(0,0);
  lcd.print("Date: ");
  lcd.print(now.year(), DEC);
  lcd.print('/');
  lcd.print(now.month(), DEC);
  lcd.print('/');
  lcd.print(now.day(), DEC);

  //second line
  lcd.setCursor(0, 1);
  lcd.print("Time: ");
  int hour = now.hour();
  String ampm = "";
  if (hour > 12) {
    hour -= 12;
    ampm = "PM";
  }
  else {
    ampm = "AM";
  }
  lcd.print(hour, DEC);
  lcd.print(':');
  lcd.print(now.minute(), DEC);
  lcd.print(':');
  lcd.print(now.second(), DEC);
  lcd.setCursor(14, 1);
  lcd.print(ampm);
  delay(1000);
  lcd.clear();
}
