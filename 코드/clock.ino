#include <RtcDS1302.h>
#include <RtcDateTime.h>
#include <RtcTimeZone.h>
#include <RtcUtility.h>
#include <ThreeWire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C 주소와 LCD의 행 및 열 수에 맞게 수정하세요.
ThreeWire mywire(7, 6, 8);
RtcDS1302<ThreeWire> Rtc(mywire);

void printDigits(int digits) {
  // utility function for digital clock display
  if (digits < 10)
    lcd.print('0');
  lcd.print(digits);
}

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  Rtc.Begin();
  RtcDateTime currentTime = RtcDateTime(__DATE__, __TIME__);
  Rtc.SetDateTime(currentTime);
}

void loop() {
  RtcDateTime now = Rtc.GetDateTime();

  // 업데이트 필요 시간 확인 및 업데이트
  RtcDateTime currentTime = RtcDateTime(__DATE__, __TIME__);
  if (now < currentTime) {
    Rtc.SetDateTime(currentTime);
    now = currentTime;
  }

  lcd.setCursor(0, 0);
  lcd.print("Date: ");
  lcd.print(now.Year());
  lcd.print("/");
  lcd.print(now.Month());
  lcd.print("/");
  lcd.print(now.Day());

  lcd.setCursor(0, 1);
  lcd.print("Time: ");
  int hour = now.Hour();
  if (hour > 12) {
    hour -= 12; // 12시간 형식으로 변환
    printDigits(hour);
    lcd.print(":");
    printDigits(now.Minute());
    lcd.print(":");
    printDigits(now.Second());
    lcd.print(" PM");
  } else {
    printDigits(hour);
    lcd.print(":");
    printDigits(now.Minute());
    lcd.print(":");
    printDigits(now.Second());
    lcd.print(" AM");
  }

  delay(500);
}
