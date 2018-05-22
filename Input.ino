const byte ROWS = 4, COLS = 4;
const byte colPins[COLS] = {A4, A5, 2, 3};
const byte rowPins[ROWS] = {A0, A1, A2, A3};

const char hexaKeys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

Keypad myKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

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
      if (i < 20)
      {
        clientOrder += tarrif[(pressedKey - 0) - 49][0] + ", ";
        Total += tarrif[(pressedKey - 0) - 49][1].toInt();
        lcd.setCursor(0, 0), lcd.print("YOU'VE CHOSEN:"), lcd.setCursor(i, j);

        if (i == 14 && j == 0)
        {
          lcd.print(pressedKey), i++;
        }
        else
        {
          lcd.print(","), lcd.print(pressedKey), i += 2;
        }
        clearRow(lcdSize, 3), lcd.print("Total:"), lcd.print(Total);
        lcd.print("RWF");
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
        lcd.clear(), lcd.setCursor(1, 2), lcd.print("SENDING RERQUEST...");
        lcd.setCursor(5, 3);
        lcd.print(sendOrder(clientOrder + "The Total payment is: " + Total) ? "SENT!" : "NOT SENT");
        delay(2000), lcd.clear();
        break;
      }
      else
      {
        clientOrder.trim(), clientOrder.remove(clientOrder.length() - 1);
        if (Total != 0)
        {
          Confirmed = true, lcd.setCursor(0, 0), lcd.print("CONFIRM REQST:");
          lcd.setCursor(0, 2);
          lcd.print("YES [#]       NO [*]");
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