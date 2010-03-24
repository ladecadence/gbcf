/*****************************************************************************
** WriteFlashThread.h
** Author: Kraku
*****************************************************************************/
#ifndef _WRITEFLASHTHREAD_H_
#define _WRITEFLASHTHREAD_H_
#include "AbstractPort.h"
#include "Logic.h"

class WriteFlashThread
{
public:
  WriteFlashThread ()
  {
  }
  virtual void run ();
  FILE *file;
  char mbc;
  char algorythm;
  char dap;
  int page_count;
  bool end;
  AbstractPort *port;

  void canceled (void);
  void set_progress (int ile, int max);
  void error (int err);
};

#endif
