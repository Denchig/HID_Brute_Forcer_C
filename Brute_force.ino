#include "Adafruit_TinyUSB.h"

uint8_t const desc_hid_report[] =
{
  TUD_HID_REPORT_DESC_KEYBOARD()
};

Adafruit_USBD_HID usb_hid(desc_hid_report, sizeof(desc_hid_report), HID_ITF_PROTOCOL_KEYBOARD, 2, false);

void setup()
{
  usb_hid.begin();
}

void loop()
{
  if ( usb_hid.ready() ){
    usb_hid.keyboardPress(0, 49);
    usb_hid.keyboardRelease(0);
    delay(1000);
  }
}
