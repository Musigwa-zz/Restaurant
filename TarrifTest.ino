#include <LiquidCrystal.h>
#include <LiquidMenu.h>
#include <Keypad.h>
#include <SoftwareSerial.h>

#define nextTimeout 2000
#define RX 10
#define TX 11
#define BAUD 9600

unsigned long oldTime = 0;
const String number = "+250788228892";
byte index = 0;
bool c = false;
const byte lcdSize[2] = {20, 4};
char *tarrif[9][9] = {
    {"Umugati", "200"},
    {"Icyayi", "200"},
    {"Umureti", "1500"},
    {"Special", "2000"},
    {"Ibishyimbo", "400"},
    {"Ifiriti", "1000"},
    {"Inyama", "1500"},
    {"Umuceri", "500"},
    {"Isosi", "200"}};

SoftwareSerial SIM800L(TX, RX);
LiquidCrystal lcd(13, 12, 9, 8, 7, 6);
LiquidLine line1(0, 0, "1.", tarrif[index][0], "=", tarrif[index][1]);
LiquidLine line2(0, 1, "2.", tarrif[index + 1][0], "=", tarrif[index + 1][1]);
LiquidLine line3(0, 2, "3.", tarrif[index + 2][0], "=", tarrif[index + 2][1]);
LiquidLine line4(0, 3, "4.", tarrif[index + 3][0], "=", tarrif[index + 3][1]);

LiquidScreen firstScrn(line1, line2, line3, line4);
LiquidMenu menu(lcd);

void setup()
{
  lcdsetup(), lcd.setCursor(0, 0), lcd.print("WELCOME IN OUR HOTEL"), SIM800L.begin(BAUD);
  lcd.setCursor(0, 1), lcd.print("CHECKING THE GSM..."), lcd.setCursor(3, 2);
  lcd.print(isGsmReady() ? "GSM IS READY!" : "NOT CONNECTED!"), delay(2000), lcd.clear();
  menu.add_screen(firstScrn);
};

void loop()
{
  if (millis() - oldTime > nextTimeout)
  {
    if (c)
    {
      index = 0;
      c = !c;
    }
    else
    {
      index = 4;
      c = !c;
    }
    oldTime = millis();
    menu.update();
  }
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

void showTarrif() {}