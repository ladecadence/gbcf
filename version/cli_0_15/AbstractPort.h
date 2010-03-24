/*****************************************************************************
** AbstractPort.h
** Author: Kraku, xzakox (2008)
** 
*****************************************************************************/
#ifndef _ABSTRACTPORT_H_
#define _ABSTRACTPORT_H_

#include <string>
#include <cctype>

class AbstractPort
{
public:
  virtual bool open_port (std::string port_name) = 0;
  virtual bool close_port () = 0;
  virtual int receive_char () = 0;
  virtual bool send_char (unsigned char character) = 0;
  virtual int receive_packet (unsigned char *packet) = 0;
  virtual int send_packet (unsigned char *packet) = 0;
  virtual ~AbstractPort ()
  {
  };
  virtual bool isOpen () = 0;
  
  virtual void error (int err)=0;

};

#endif
