// #include <GSMSim.h>

// #define RX 10
// #define TX 12
// #define BAUD 115200

// GSMSim gsm(RX, TX);

// void setup()
// {
//   Serial.begin(115200);
//   Serial.println("GSMSim Library - SMS Example");
//   Serial.println("");
//   delay(1000);

//   gsm.start(BAUD);
//   Serial.println("Changing to text mode.");
//   gsm.smsTextMode(true);

//   char *number = "+905123456789";
//   String message = "Hi my friend. How are you?";
//   Serial.println("Sending Message --->");
//   Serial.println(gsm.smsSend(number, message));
//   delay(2000);

//   Serial.println("Listing unread message(s).");
//   Serial.println(gsm.smsListUnread());
//   Serial.println("Read SMS on index no = 1");
//   Serial.println(gsm.smsRead(1));
// }

// void loop()
// {
// }