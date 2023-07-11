#include <Keyboard.h>

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Keyboard.begin();
  delay(2000);
}

void loop() {
  int dig1, dig2, dig3, dig4, dig5, dig6;

  for(dig1=0; dig1<10; dig1++)
  {
    for(dig2=0; dig2<10; dig2++)
    {
      for(dig3=0; dig3<10; dig3++)
      {
        for(dig4=0; dig4<10; dig4++)
        {
          for(dig5=0; dig5<10; dig5++)
          {
            for(dig6=0; dig6<10; dig6++) 
            {
            digitalWrite(LED_BUILTIN, HIGH);
            Keyboard.press(dig1);
            Keyboard.releaseAll();
            delay(50);
            Keyboard.press(dig2);
            Keyboard.releaseAll();
            delay(50);
            Keyboard.press(dig3);
            Keyboard.releaseAll();
            delay(50);
            Keyboard.press(dig4);
            Keyboard.releaseAll();
            delay(50);
            Keyboard.press(dig5);
            Keyboard.releaseAll();
            delay(50);
            Keyboard.press(dig6);
            Keyboard.releaseAll();
            delay(50);
            Keyboard.press(KEY_RETURN);
            Keyboard.releaseAll();
            digitalWrite(LED_BUILTIN, LOW);
            delay(1000);
            }
          }
        }
      }
    }
  }
}
