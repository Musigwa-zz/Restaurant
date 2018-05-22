void lcdsetup()
{
  lcd.begin(lcdSize[0], lcdSize[1]), delay(50), lcd.clear();
};

bool clearRow(const byte scrnSize[2], const byte R2Del)
{
  if (R2Del >= 0 && R2Del < scrnSize[1])
  {
    lcd.setCursor(0, R2Del);
    for (byte i = 0; i <= (scrnSize[0] - 1); i++)
    {
      lcd.print(" ");
    }
    lcd.setCursor(0, R2Del);
    return true;
  }
};

void scroll(String Text, byte Delay)
{
  String pri = Text.substring(0, lcdSize[0]);
  Text.remove(0, pri.length());
  Serial.println(pri);
  for (;;)
  {
    lcd.print(Text.substring(0, lcdSize[0])), delay(Delay);
    lcd.setCursor(0, 0);
  }
};