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

bool sendOrder(String Order)
{
  if (isGsmReady())
  {
    SIM800L.println("AT+CMGF=1");
    delay(10);
    SIM800L.println("AT+CMGS=\"" + number + "\"");
    delay(10);
    SIM800L.println(Order);
    delay(10);
    SIM800L.write(26);
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