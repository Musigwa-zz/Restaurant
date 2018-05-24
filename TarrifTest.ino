#include <LiquidCrystal.h>
#include <LiquidMenu.h>
#include <Keypad.h>
#include <SoftwareSerial.h>

#define RX 10
#define TX 11
#define BAUD 9600

unsigned int period_nextScreen = 2000;
unsigned long lastMs_nextScreen = 0;

const String number = "+250788228892";
const byte lcdSize[2] = {20, 4};

SoftwareSerial SIM800L(TX, RX);
LiquidCrystal lcd(11, 8, 4, 5, 6, 7);
LiquidLine line1(3, 0, "LiquidMenu 1");
LiquidLine line2(3, 1, "LiquidMenu 2");
LiquidLine line3(3, 2, "LiquidMenu 3");
LiquidLine line4(3, 3, "LiquidMenu 4");

LiquidLine line5(3, 0, "LiquidMenu 5");
LiquidLine line6(3, 1, "LiquidMenu 6");
LiquidLine line7(3, 2, "LiquidMenu 7");
LiquidLine line8(3, 3, "LiquidMenu 8");

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
  if (millis() - lastMs_nextScreen > period_nextScreen)
  {
    lastMs_nextScreen = millis();
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
  while (!SIM800L.available() && !(millis() > timeOld + timeout))
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