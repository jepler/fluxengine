#ifndef USBSERIAL_H
#define USBSERIAL_H

class libusb_device_descriptor;

extern int openUsbSerialDevice(libusb_device_descriptor* descriptor);

#endif
