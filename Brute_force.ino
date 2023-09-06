#include "Adafruit_TinyUSB.h"

uint8_t const desc_hid_report[] = { TUD_HID_REPORT_DESC_KEYBOARD() };

Adafruit_USBD_HID usb_hid(desc_hid_report, sizeof(desc_hid_report), HID_ITF_PROTOCOL_KEYBOARD, 2, false);

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  usb_hid.begin();
  delay(1000);
}

int start = 0;
int finish = 10000;
char result[6];

void typer(char * number)
{
  for(int i=6; i>strlen(number); i--)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    usb_hid.keyboardPress(0,48);
    delay(10);
    usb_hid.keyboardRelease(0);
    delay(10);
    digitalWrite(LED_BUILTIN, LOW);   
  }
  char symbol;
  for(int j=0; j<=strlen(number); j++)
  {
    symbol=number[j];
    digitalWrite(LED_BUILTIN, HIGH);
    usb_hid.keyboardPress(0,symbol);
    delay(10);
    usb_hid.keyboardRelease(0);
    delay(10);   
  }
  usb_hid.keyboardPress(0, 13);
  delay(10);
  usb_hid.keyboardRelease(0);
  delay(10);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop()
{
  for(start; start <= finish; start++)
  {
    sprintf(result,"%ld", start);
    typer(result);
  }
}
