String number = "+250785782928";

bool isGsmReady()
{
  GSM.println("AT");
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
  // return gsm.smsSend(number, Order);
  String _buffer;
  if (isGsmReady())
  {
    GSM.println("AT+CMGF=1");
    delay(10);
    GSM.println("AT+CMGS=\"" + number + "\"");
    _buffer = _readSerial(5000);
    delay(10);
    GSM.println(Order);
    _buffer += _readSerial(5000);
    GSM.write(26);
    _buffer += _readSerial(5000);
    if (((_buffer.indexOf("AT+CMGS")) != -1))
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }
};

// void showResponse()
// {
//   Serial.println(gsm.smsRead(1));
//   gsm.smsDeleteAll();
// };

String _readSerial(uint32_t timeout)
{
  uint64_t timeOld = millis();
  while (!GSM.available() && !(millis() > timeOld + timeout))
  {
    delay(13);
  }
  String str = "";
  while (GSM.available())
  {
    if (GSM.available())
    {
      str += (char)GSM.read();
    }
  }
  return str;
}
