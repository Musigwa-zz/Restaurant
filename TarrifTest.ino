#include <LiquidCrystal.h>
#include <Keypad.h>
#include <SoftwareSerial.h>

#define nextTimeout 2000
#define RX 10
#define TX 11
#define BAUD 9600

unsigned long oldTime = 0;
const String number = "+250788228892";
byte qin = 0;
bool c = false;
const byte lcdSize[2] = {20, 4};
const char *tarrif[8][8] = {
    {"Umugati", "200"},
    {"Icyayi", "200"},
    {"Umureti", "1500"},
    {"Special", "2000"},
    {"Ibishyimbo", "400"},
    {"Ifiriti", "1000"},
    {"Inyama", "1500"},
    {"Umuceri", "500"}};

SoftwareSerial SIM800L(TX, RX);
LiquidCrystal lcd(13, 12, 9, 8, 7, 6);

void setup()
{
  lcdsetup(), lcd.setCursor(0, 0), lcd.print("WELCOME IN OUR HOTEL"), SIM800L.begin(BAUD);
  lcd.setCursor(0, 1), lcd.print("CHECKING THE GSM..."), lcd.setCursor(3, 2);
  lcd.print(isGsmReady() ? "GSM IS READY!" : "NOT CONNECTED!"), delay(2000), lcd.clear();
};

void loop()
{
  if (millis() - oldTime > nextTimeout)
  {
    lcd.clear();
    if (c)
    {
      qin = 0;
      c = !c;
    }
    else
    {
      qin = 4;
      c = !c;
    }
    oldTime = millis();
  }
  showTarrif(qin);
};

bool isGsmReady()
{
  SIM800L.println("AT");
  if (_readSerial(2000).indexOf("OK") != -1)
  {
    return true;
  }
  else
  {
    return false;
  }
};

String _readSerial(uint32_t timeout)
{
  uint64_t timeOld = millis();
  while (!SIM800L.available() && !(millis() > timeOld + nextTimeout))
  {
    delay(13);
  }
  String str = "";
  while (SIM800L.available())
  {
    if (SIM800L.available())
    {
      str += (char)SIM800L.read();
    }
  }
  return str;
};

void lcdsetup()
{
  lcd.begin(lcdSize[0], lcdSize[1]), delay(50), lcd.clear();
};

bool clearRow(const byte scrnSize[2], const byte R2Del)
{
  if (R2Del >= 0 && R2Del < scrnSize[1])
  {
    lcd.setCursor(0, R2Del);
    for (byte i = 0; i <= (scrnSize[0] - 1); i++)
    {
      lcd.print(" ");
    }
    lcd.setCursor(0, R2Del);
    return true;
  }
};

void showTarrif(byte ind)
{
  lcd.setCursor(0, 0), lcd.print(ind + 1), lcd.print("."), lcd.print(tarrif[ind][0]);
  lcd.print("="), lcd.print(tarrif[ind + 0][1]), lcd.print("RWF");
  lcd.setCursor(0, 1), lcd.print(ind + 2), lcd.print("."), lcd.print(tarrif[ind + 1][0]);
  lcd.print("="), lcd.print(tarrif[ind + 1][1]), lcd.print("RWF");
  lcd.setCursor(0, 2), lcd.print(ind + 3), lcd.print("."), lcd.print(tarrif[ind + 2][0]);
  lcd.print("="), lcd.print(tarrif[ind + 2][1]), lcd.print("RWF");
  lcd.setCursor(0, 3), lcd.print(ind + 4), lcd.print("."), lcd.print(tarrif[ind + 3][0]);
  lcd.print("="), lcd.print(tarrif[ind + 3][1]), lcd.print("RWF");
};