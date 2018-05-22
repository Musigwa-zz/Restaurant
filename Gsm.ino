char *number = "+905123456789";
char *message = "Hi my friend. How are you?";

void gsmSetup()
{
  gsm.start(BAUD);
  gsm.smsTextMode(true);
  delay(3000);
};

bool sendOrder(char *Order)
{
  Serial.println("Sending order...");
  gsm.smsSend(number, Order);
  delay(2000);
};

void showResponse()
{
  Serial.println(gsm.smsRead(1));
  gsm.smsDeleteAll();
};