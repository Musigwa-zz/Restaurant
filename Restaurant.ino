#include <LiquidCrystal.h>
#include <Keypad.h>
#include <GSMSim.h>

#define RX 12
#define TX 10
#define RESET 13
#define BAUD 115200

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
const byte lcdSize[2] = {20, 4};

LiquidCrystal lcd(11, 8, 4, 5, 6, 7);
GSMSim gsm(RX, TX, RESET);

void setup()
{
  // Serial.begin(BAUD);
  lcdsetup(), lcd.setCursor(0, 0), lcd.print("Wecome To Restaurant");
  delay(2000), lcd.clear();
};

void loop()
{
  proccessOrder();
}