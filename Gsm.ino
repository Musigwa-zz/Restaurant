// char *number = "+905123456789";
// char *message = "Hi my friend. How are you?";

// void gsmSetup()
// {
//   gsm.start(BAUD);
//   // Serial.println("Changing to text mode.");
//   gsm.smsTextMode(true);
// }

// bool sendOrder(char *Order)
// {
//   Serial.println("Sending order...");
//   gsm.smsSend(number, Order);
//   delay(2000);
// }

// String showResponse()
// {
//   Serial.println("Reading response...");
//   Serial.println(gsm.smsRead(1));
//   gsm.smsDeleteAll();
// }