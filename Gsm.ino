char *number = "+250785782928";

void gsmSetup()
{
  gsm.start(BAUD);
  gsm.smsTextMode(true);
  delay(3000);
};

bool sendOrder(String Order)
{
  return gsm.smsSend(number, Order);
};

void showResponse()
{
  Serial.println(gsm.smsRead(1));
  gsm.smsDeleteAll();
};