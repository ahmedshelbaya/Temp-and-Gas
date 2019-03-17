/*
   This Code written by Ahmed Shelbaya
   Founder of A.Shelbaya inc
   Main Code Function is read Temperature and hunidity using DHT11
   Display readings on LCD and Sense if any hurmfull gases on air and alarm us
*/
#include <SimpleDHT.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd (2, 3, 4, 5, 6, 7);
SimpleDHT11 dht11(9); //DHTPin
int GasValue;
byte temperature = 0;
byte humidity = 0;
void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
}
void loop()
{


  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess)
  {
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("DHT Error");
  }
  PrintTemp();
  GasValue = analogRead(A0);
  Serial.println(GasValue);

  if (GasValue > 500)
  {
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("Gas Leakage");
    delay(500);
    PrintTemp();
  }
  else
  {
    delay(10);
    lcd.clear();
    PrintTemp();
  }
}
void PrintTemp()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp is ");
  lcd.setCursor(9, 0);
  lcd.print(temperature);
  lcd.setCursor(0, 1);
  lcd.print("Humidity is ");
  lcd.setCursor(12, 1);
  lcd.print(humidity);
  Serial.println(temperature);
}
