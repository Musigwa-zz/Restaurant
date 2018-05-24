// const byte ROWS = 4, COLS = 4;
// const byte colPins[COLS] = {A4, A5, 2, 3};
// const byte rowPins[ROWS] = {A0, A1, A2, A3};

// const char hexaKeys[ROWS][COLS] = {
//     {'1', '2', '3', 'A'},
//     {'4', '5', '6', 'B'},
//     {'7', '8', '9', 'C'},
//     {'*', '0', '#', 'D'}};

// Keypad myKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

// void proccessOrder()
// {
//   String clientOrder = "";
//   unsigned int Total = 0;
//   bool Confirmed = false;
//   byte i = 14, j = 0;
//   for (;;)
//   {
//     char pressedKey = myKeypad.waitForKey();
//     if (isDigit(pressedKey) && pressedKey != '0')
//     {
//       clientOrder += pressedKey;
//       Total += tarrif[(pressedKey - 0) - 49][1].toInt(), lcd.setCursor(0, 0);
//       if (i < 20)
//       {
//         lcd.print("YOU'VE CHOSEN:"), lcd.setCursor(i, j);
//         if (i == 14 && j == 0)
//         {
//           lcd.print(pressedKey), i++;
//         }
//         else
//         {
//           lcd.print(","), lcd.print(pressedKey), i += 2;
//         }
//         clearRow(lcdSize, 3), lcd.print("Total:"), lcd.print(Total), lcd.print("RWF");
//       }
//       if (j < 1 && i == 19)
//       {
//         i = 0, j++;
//       }
//     }
//     else if (pressedKey == '#')
//     {
//       if (Confirmed)
//       {
//         while (clientOrder.length() > 0)
//         {
//           Serial.print(tarrif[clientOrder.substring(0, 1).toInt() - 1][0] + "(");
//           Serial.print(tarrif[clientOrder.substring(0, 1).toInt() - 1][1] + "RWF)");
//           clientOrder.remove(0, 1);
//           if (clientOrder.length() == 0)
//           {
//             Serial.print(". Total payment: " + String(Total) + "RWF\r");
//             break;
//           }
//           else
//           {
//             Serial.print(", ");
//           }
//         }

//         lcd.clear(), lcd.setCursor(2, 2), lcd.print("SENDING REQUEST...");
//         lcd.setCursor(5, 3);
//         lcd.print(sendOrder(clientOrder) ? "SENT!" : "NOT SENT");
//         delay(2000), lcd.clear();
//         break;
//       }
//       else
//       {
//         if (Total != 0)
//         {
//           Confirmed = true, lcd.setCursor(0, 0), lcd.print("CONFIRM REQST:");
//           lcd.setCursor(0, 2), lcd.print("YES [#]       NO [*]");
//         }
//         else
//         {
//           clearRow(lcdSize, 2), lcd.print("CAN'T SEND EMPTY REQ"), delay(2000);
//           lcd.clear();
//           break;
//         }
//       }
//     }
//     else if (pressedKey == '*' && Total != 0)
//     {
//       Confirmed = false, clearRow(lcdSize, 2), lcd.print("ORDER CANCELED!");
//       delay(2000), lcd.clear(), Total = 0, clientOrder = "";
//       break;
//     }
//     Serial.println(clientOrder);
//     Serial.println(Total);
//   }
// };