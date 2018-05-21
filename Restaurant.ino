#include <LiquidCrystal.h>
#include <Keypad.h>
#include <GSMSim.h>

#define RX 7
#define TX 8
#define RESET 2
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
const byte lcdSize[2] = {20, 4};

LiquidCrystal lcd(11, 8, 4, 5, 6, 7);
GSMSim gsm(RX, TX, RESET);

void setup()
{
  Serial.begin(BAUD);
  lcdsetup();
};

void loop()
{
  proccessOrder();
  Serial.println("Sent");
};