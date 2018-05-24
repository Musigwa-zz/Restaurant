// #include <LiquidCrystal.h>
// #include <Keypad.h>
// #include <SoftwareSerial.h>

// #define RX 10
// #define TX 11
// #define BAUD 9600

// const String number = "+250788228892";
// SoftwareSerial SIM800L(TX, RX);
// const byte lcdSize[2] = {20, 4};
// LiquidCrystal lcd(11, 8, 4, 5, 6, 7);

// void setup()
// {
//   lcdsetup(), lcd.setCursor(0, 0), lcd.print("WELCOME IN OUR HOTEL"), SIM800L.begin(BAUD);
//   lcd.setCursor(0, 1), lcd.print("CHECKING THE GSM..."), lcd.setCursor(3, 2);
//   lcd.print(isGsmReady() ? "GSM IS READY!" : "NOT CONNECTED!"), delay(2000), lcd.clear();
//   lcd.clear(), lcd.setCursor(2, 2), lcd.print("SENDING REQUEST...");
//   lcd.setCursor(5, 3);
//   lcd.print(sendOrder("WELCOME TO KANKATO!") ? "SENT!" : "NOT SENT");
//   delay(2000), lcd.clear();
// };

// void loop(){};

// bool isGsmReady()
// {
//   SIM800L.println("AT");
//   if (_readSerial(2000).indexOf("OK") != -1)
//   {
//     return true;
//   }
//   else
//   {
//     return false;
//   }
// };

// bool sendOrder(String Order)
// {
//   if (isGsmReady())
//   {
//     String _buffer;
//     SIM800L.println("AT+CMGF=1");
//     SIM800L.println("AT+CMGS=\"" + number + "\"\r");
//     _buffer = _readSerial(5000);
//     SIM800L.print(Order);
//     _buffer += _readSerial(5000);
//     SIM800L.println((char)26);
//     _buffer += _readSerial(5000);
//     if (((_buffer.indexOf("AT+CMGS")) != -1))
//     {
//       return true;
//     }
//     else
//     {
//       return false;
//     }
//   }
//   else
//   {
//     return false;
//   }
// };

// String _readSerial(uint32_t timeout)
// {
//   uint64_t timeOld = millis();
//   while (!SIM800L.available() && !(millis() > timeOld + timeout))
//   {
//     delay(13);
//   }
//   String str = "";
//   while (SIM800L.available())
//   {
//     if (SIM800L.available())
//     {
//       str += (char)SIM800L.read();
//     }
//   }
//   return str;
// };

// void lcdsetup()
// {
//   lcd.begin(lcdSize[0], lcdSize[1]), delay(50), lcd.clear();
// };

// bool clearRow(const byte scrnSize[2], const byte R2Del)
// {
//   if (R2Del >= 0 && R2Del < scrnSize[1])
//   {
//     lcd.setCursor(0, R2Del);
//     for (byte i = 0; i <= (scrnSize[0] - 1); i++)
//     {
//       lcd.print(" ");
//     }
//     lcd.setCursor(0, R2Del);
//     return true;
//   }
// };