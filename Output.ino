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