#include <LiquidCrystal.h>
#include <Keypad.h>
#include <SoftwareSerial.h>

#define RX 10
#define TX 12
#define BAUD 9600

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

const String number = "+250784896859";
const byte lcdSize[2] = {20, 4};
LiquidCrystal lcd(11, 8, 4, 5, 6, 7);
SoftwareSerial SIM800L(RX, TX);

void setup()
{
  lcdsetup(), lcd.setCursor(0, 0), lcd.print("WELCOME IN OUR HOTEL"), SIM800L.begin(BAUD);
  lcd.setCursor(0, 1), lcd.print("CHECKING THE GSM..."), lcd.setCursor(3, 2);
  lcd.print(isGsmReady() ? "GSM IS READY!" : "NOT CONNECTED!"), delay(2000), lcd.clear();
};

void loop()
{
  proccessOrder();
};