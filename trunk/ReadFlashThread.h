/*****************************************************************************
** ReadFlashThread.h 
** Author: Kraku, CLI Version: David Pello
*****************************************************************************/
#ifndef _READFLASHTHREAD_H_
#define _READFLASHTHREAD_H_
#include "AbstractPort.h"
#include "Logic.h"

class ReadFlashThread
{
public:
  ReadFlashThread ()
  {
  }
  virtual void run ();
  bool end;
  FILE *file;
  char mbc;
  char algorythm;
  char dap;
  int page_count;
  AbstractPort *port;

  void canceled (void);

  void set_progress (int ile, int max);
  void error (int err);
};

#endif
