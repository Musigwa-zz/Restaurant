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
  // String _buffer;
  SIM800L.println("AT");
  SIM800L.println("AT+CMGF=1");
  delay(10);
  SIM800L.println("AT+CMGS=\"" + number + "\"");
  // _buffer = _readSerial(5000);
  delay(10);
  SIM800L.print(Order);
  delay(10);
  // _buffer += _readSerial(5000);
  SIM800L.write(26);
  // _buffer += _readSerial(5000);
  // if (((_buffer.indexOf("AT+CMGS")) != -1))
  // {
  //   return true;
  // }
  // else
  // {
  //   return false;
  // }
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