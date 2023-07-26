#include "Adafruit_TinyUSB.h"

// HID report descriptor using TinyUSB's template
// Single Report (no ID) descriptor
uint8_t const desc_hid_report[] =
{
  TUD_HID_REPORT_DESC_KEYBOARD()
};

// USB HID object. For ESP32 these values cannot be changed after this declaration
// desc report, desc len, protocol, interval, use out endpoint
Adafruit_USBD_HID usb_hid(desc_hid_report, sizeof(desc_hid_report), HID_ITF_PROTOCOL_KEYBOARD, 2, false);

// For keycode definition check out https://github.com/hathach/tinyusb/blob/master/src/class/hid/hid.h
uint8_t hidcode[] = { HID_KEY_ARROW_RIGHT, HID_KEY_ARROW_LEFT, HID_KEY_ARROW_DOWN, HID_KEY_ARROW_UP };

// the setup function runs once when you press reset or power the board
void setup()
{
#if defined(ARDUINO_ARCH_MBED) && defined(ARDUINO_ARCH_RP2040)
  // Manual begin() is required on core without built-in support for TinyUSB such as mbed rp2040
  TinyUSB_Device_Init(0);
#endif

  // Notes: following commented-out functions has no affect on ESP32
  //usb_hid.setBootProtocol(HID_ITF_PROTOCOL_KEYBOARD);
  //usb_hid.setPollInterval(2);
  //usb_hid.setReportDescriptor(desc_hid_report, sizeof(desc_hid_report));
  //usb_hid.setStringDescriptor("TinyUSB Keyboard");

  // Set up output report (on control endpoint) for Capslock indicator
  //usb_hid.setReportCallback(NULL, hid_report_callback);

  usb_hid.begin();

  // wait until device mounted
  while( !TinyUSBDevice.mounted() ) delay(1);
}

void loop()
{
  // poll gpio once each 2 ms
  delay(2);

  // used to avoid send multiple consecutive zero report for keyboard
  static bool keyPressedPreviously = false;

  uint8_t count=0;
  uint8_t keycode[6] = { 0 };

  if ( TinyUSBDevice.suspended() && count )
  {
    // Wake up host if we are in suspend mode
    // and REMOTE_WAKEUP feature is enabled by host
    TinyUSBDevice.remoteWakeup();
  }

  // skip if hid is not ready e.g still transferring previous report
  if ( !usb_hid.ready() ) return;

  if ( count )
  {
    // Send report if there is key pressed
    uint8_t const report_id = 0;
    uint8_t const modifier = 0;

    keyPressedPreviously = true;
    usb_hid.keyboardReport(report_id, modifier, keycode);
  }else
  {
    // Send All-zero report to indicate there is no keys pressed
    // Most of the time, it is, though we don't need to send zero report
    // every loop(), only a key is pressed in previous loop()
    if ( keyPressedPreviously )
    {
      keyPressedPreviously = false;
      usb_hid.keyboardRelease(0);
    }
  }
  int dig1, dig2, dig3, dig4, dig5, dig6;
  uint8_t test[6] = { 0 };
  test[0] = HID_KEY_1;

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
              usb_hid.keyboardReport(1, 1, test);
              usb_hid.keyboardRelease(1);
              delay(1000);
            //digitalWrite(LED_BUILTIN, HIGH);
            //Keyboard.press(dig1);
            //Keyboard.releaseAll();
            //delay(50);
            //Keyboard.press(dig2);
            //Keyboard.releaseAll();
            //delay(50);
            //Keyboard.press(dig3);
            //Keyboard.releaseAll();
            //delay(50);
            //Keyboard.press(dig4);
            //Keyboard.releaseAll();
            //delay(50);
            //Keyboard.press(dig5);
            //Keyboard.releaseAll();
            //delay(50);
            //Keyboard.press(dig6);
            //Keyboard.releaseAll();
            //delay(50);
            //Keyboard.press(HID_KEY_RETURN);
            //Keyboard.releaseAll();
            //digitalWrite(LED_BUILTIN, LOW);
            //delay(1000);
            }
          }
        }
      }
    }
  }
}
