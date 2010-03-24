/*****************************************************************************
** USBPortWin.h - USB driver for Windows based on FTD2XX library
** Author: Kraku
*****************************************************************************/
#ifndef _USBPORTWIN_H_
#define _USBPORTWIN_H_
#include <windows.h>
#include "AbstractPort.h"
#include <ftd2xx.h>
#include <time.h>

 
class USBPortWin
{
	FT_HANDLE ftHandle;
	FT_STATUS ftStatus; 
	bool opened;
public:
	USBPortWin();
	bool open_port (std::string port_name);
	bool close_port ();
	int receive_char ();
	bool send_char (unsigned char character);
	int receive_packet (unsigned char *packet);
	int send_packet (unsigned char *packet);
	bool isOpen()
	{
		return opened;
	}
	void error(int err);
};

#endif
