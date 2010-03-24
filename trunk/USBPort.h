/*****************************************************************************
** USBPort.h - USB driver for Linux based on libftdi
** Author: Kraku
*****************************************************************************/
#ifndef _USBPORT_H_
#define _USBPORT_H_
#include "AbstractPort.h"
#include <ftdi.h>
#include <time.h>
#include <string>


class USBPort:public AbstractPort
{	
  struct ftdi_context ftdic;
  FILE *file;

  bool opened;
public:
  USBPort ();
  bool open_port (std::string port_name);
  bool close_port ();
  int receive_char ();
  bool send_char (unsigned char character);
  int receive_packet (unsigned char *packet);
  int send_packet (unsigned char *packet);
  bool isOpen ()
  {
    return opened;
  }
  void error (int err);
};

#endif
