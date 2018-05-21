
const byte ROWS = 4, COLS = 4;
const char hexaKeys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};
const byte rowPins[ROWS] = {9, 8, 7, 6};
const byte colPins[COLS] = {5, 4, 3, 2};

Keypad myKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

const String proccessOrder()
{
  String clientOrder = "";
  unsigned int Total = 0;
  bool Confirmed = false;
  for (;;)
  {
    char pressedKey = myKeypad.getKey();
    if (isDigit(pressedKey) && pressedKey != '0')
    {
      clientOrder += tarrif[(pressedKey - 0) - 49][0] + ", ";
      Total += tarrif[(pressedKey - 0) - 49][1].toInt();
      Serial.println(clientOrder);
      Serial.println(Total);
    }
    else if (pressedKey == 'C')
    {
      if (Confirmed)
      {
        // sendOrder(clientOrder);
        break;
      }
      else
      {
        clientOrder.trim();
        clientOrder.remove(clientOrder.length() - 1);
        Serial.println("You ordered: " + clientOrder + ". You\'ll pay: " + Total + "Rwf.");
        Serial.print("Press again to confirm or [D] to cancel the order!");
        Confirmed = true;
      }
    }
    else if (pressedKey == 'D' && Confirmed)
    {
      Serial.print("Order canceled!");
      clientOrder = "";
      break;
    }
  }
  Confirmed = false;
}
