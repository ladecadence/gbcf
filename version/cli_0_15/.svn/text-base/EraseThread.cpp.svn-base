/*****************************************************************************
** EraseThread.cpp
** Author: Kraku, CLI Version: David Pello
*****************************************************************************/
#include "EraseThread.h"
#include "Logic.h"
#include "const.h"
#include "Settings.h"
#include <iostream>

void
EraseThread::run ()
{
  time_t tp, t0;		/* time for erase */
  unsigned short crc16;
  unsigned char packet[PACKETSIZE];
/* filling single erase packet */
  memset (packet, 0x00, PACKETSIZE);
  packet[0] = DATA;
  packet[1] = ERASE;
  packet[2] = mem;
  packet[3] = mbc;
  packet[4] = par;
  packet[5] = Settings::dap;
  crc16 = Logic::generate_crc16 (packet);
  packet[PACKETSIZE - 2] = crc16 / 256;
  packet[PACKETSIZE - 1] = crc16 % 256;
  end = false;

  /* send erase packet */
  if (port->send_packet (packet) < PACKETSIZE)
    {
      port->close_port ();
      error (SEND_ERROR);
      return;
    }

  t0 = tp = time (NULL);
  do
    {
      /* end of thread - operation canceled */
      if(end) { 
          port->close_port();
          error (END);
	  return;
      }
      /* erase done */
      if (port->receive_char () == ACK) 
	{
	  port->close_port ();
	  set_progress (1, 1);
	  error (true);
	  return;
	}
      if (time (NULL) != tp)
	set_progress (time (NULL) - tp, DELTIME);
    }
  while (time (NULL) - tp < DELTIME);
  /* wait for erase DELTIME sec.
   * hardware independent!
   */

  set_progress (1, 1);	//100%
  port->close_port ();
  error (TIMEOUT);
  return;
}
void
EraseThread::set_progress (int p, int escala)
{
	if (escala > 1)
		std::cout << p*100/escala << "%" << "\r";
	else
		std::cout << "100%" << std::endl;

	std::cout.flush();
	
}

void EraseThread::error(int err) {
	if (err =! true) {
		 std::cout << ">> ERROR Erase: " << err << std::endl;
		 exit(1);
	}
	else
		std::cout << "Success." << std::endl;
}

