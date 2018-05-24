void proccessOrder()
{
  String clientOrder = "";
  unsigned int Total = 0;
  bool Confirmed = false;
  byte i = 14, j = 0;
  for (;;)
  {
    char pressedKey = myKeypad.waitForKey();
    if (isDigit(pressedKey) && pressedKey != '0')
    {
      clientOrder += pressedKey;
      Total += atoi(tarrif[(pressedKey - 0) - 49][1]), lcd.setCursor(0, 0);
      if (i < 20)
      {
        lcd.print("YOU'VE CHOSEN:"), lcd.setCursor(i, j);
        if (i == 14 && j == 0)
        {
          lcd.print(pressedKey), i++;
        }
        else
        {
          lcd.print(","), lcd.print(pressedKey), i += 2;
        }
        clearRow(lcdSize, 3), lcd.print("Total:"), lcd.print(Total), lcd.print("RWF");
      }
      if (j < 1 && i == 19)
      {
        i = 0, j++;
      }
    }
    else if (pressedKey == '#')
    {
      if (Confirmed)
      {
        lcd.clear(), lcd.setCursor(2, 2), lcd.print("SENDING REQUEST...");
        if (isGsmReady())
        {
          String _buffer;
          SIM800L.println("AT+CMGF=1");
          SIM800L.println("AT+CMGS=\"" + number + "\"\r");
          _buffer = _readSerial(5000);
          while (clientOrder.length() > 0)
          {
            SIM800L.print(tarrif[clientOrder.substring(0, 1).toInt() - 1][0]);
            SIM800L.print("(");
            SIM800L.print(tarrif[clientOrder.substring(0, 1).toInt() - 1][1]);
            SIM800L.print("RWF)");
            clientOrder.remove(0, 1);
            if (clientOrder.length() == 0)
            {
              SIM800L.print(". Total payment: " + String(Total) + "RWF");
              break;
            }
            else
            {
              SIM800L.print(", ");
            }
          }
          _buffer += _readSerial(5000);
          SIM800L.println((char)26);
          _buffer += _readSerial(5000);
          if (((_buffer.indexOf("AT+CMGS")) != -1))
          {
            lcd.print("SENT!");
          }
          else
          {
            lcd.print("NOT SENT");
          }
        }
        else
        {
          lcd.print("NOT SENT");
        }
        delay(2000), lcd.clear();
        break;
      }
      else
      {
        if (Total != 0)
        {
          Confirmed = true, lcd.setCursor(0, 0), lcd.print("CONFIRM REQST:");
          lcd.setCursor(0, 2), lcd.print("YES [#]       NO [*]");
        }
        else
        {
          clearRow(lcdSize, 2), lcd.print("CAN'T SEND EMPTY REQ"), delay(2000);
          lcd.clear();
          break;
        }
      }
    }
    else if (pressedKey == '*' && Total != 0)
    {
      Confirmed = false, clearRow(lcdSize, 2), lcd.print("ORDER CANCELED!");
      delay(2000), lcd.clear(), Total = 0, clientOrder = "";
      break;
    }
  }
};