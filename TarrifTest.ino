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
const byte lcdSize[2] = {20, 4};
const String tarrif[9][9] = {
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
LiquidLine line1(0, 0, "1.", tarrif[0][0], "=", tarrif[0][1]);
LiquidLine line2(0, 1, "2.", tarrif[1][0], "=", tarrif[1][1]);
LiquidLine line3(0, 2, "3.", tarrif[2][0], "=", tarrif[2][1]);
LiquidLine line4(0, 3, "4.", tarrif[3][0], "=", tarrif[3][1]);
LiquidLine line5(0, 0, "5.", tarrif[4][0], "=", tarrif[4][1]);
LiquidLine line6(0, 1, "6.", tarrif[5][0], "=", tarrif[5][1]);
LiquidLine line7(0, 2, "7.", tarrif[6][0], "=", tarrif[6][1]);
LiquidLine line8(0, 3, "8.", tarrif[7][0], "=", tarrif[7][1]);

LiquidScreen firstScrn(line1, line2, line3, line4);
LiquidScreen secondScrn(line5, line6, line7, line8);
LiquidMenu menu(lcd);

void setup()
{
  lcdsetup(), lcd.setCursor(0, 0), lcd.print("WELCOME IN OUR HOTEL"), SIM800L.begin(BAUD);
  lcd.setCursor(0, 1), lcd.print("CHECKING THE GSM..."), lcd.setCursor(3, 2);
  lcd.print(isGsmReady() ? "GSM IS READY!" : "NOT CONNECTED!"), delay(2000), lcd.clear();
  menu.add_screen(firstScrn);
  menu.add_screen(secondScrn);
};

void loop()
{
  if (millis() - oldTime > nextTimeout)
  {
    oldTime = millis();
    menu.next_screen();
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