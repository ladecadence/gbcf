/*****************************************************************************
** Console.h - header of Console used to print infos from other
** modules
** Author: Kraku
*****************************************************************************/
#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include <iostream>

class Console
{
public:
  Console ()
  {
  }

  void print (std::string string)
  {
    std::cout << string;
  }

  void line ()
  {
  	std::cout << std::endl;
  }
};

#endif
