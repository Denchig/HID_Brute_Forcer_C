#include "Adafruit_TinyUSB.h"

uint8_t const desc_hid_report[] =
{
  TUD_HID_REPORT_DESC_KEYBOARD()
};

Adafruit_USBD_HID usb_hid(desc_hid_report, sizeof(desc_hid_report), HID_ITF_PROTOCOL_KEYBOARD, 2, false);

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  usb_hid.begin();
  delay(1000);
}

void loop()
{
  int dig1, dig2, dig3, dig4, dig5, dig6;
  int keys[10] = { 48, 49, 50, 51, 52, 53, 54, 55, 56, 57  };

  if ( usb_hid.ready() )
  {
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
                usb_hid.keyboardPress(0, keys[dig1]);
                delay(10);
                usb_hid.keyboardRelease(0);
                delay(10);
                usb_hid.keyboardPress(0, keys[dig2]);
                delay(10);
                usb_hid.keyboardRelease(0);
                delay(10);
                usb_hid.keyboardPress(0, keys[dig3]);
                delay(10);
                usb_hid.keyboardRelease(0);
                delay(10);
                usb_hid.keyboardPress(0, keys[dig4]);
                delay(10);
                usb_hid.keyboardRelease(0);
                delay(10);
                usb_hid.keyboardPress(0, keys[dig5]);
                delay(10);
                usb_hid.keyboardRelease(0);
                delay(10);
                usb_hid.keyboardPress(0, keys[dig6]);
                delay(10);
                usb_hid.keyboardRelease(0);
                delay(10);
                usb_hid.keyboardPress(0, 13);
                delay(10);
                usb_hid.keyboardRelease(0);
                digitalWrite(LED_BUILTIN, LOW);
                delay(12000);
              }
            }
          }
        }
      }
    }
  }
}
