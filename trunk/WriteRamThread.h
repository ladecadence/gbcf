/*****************************************************************************
** WriteRamThread.h
** Author: Kraku
*****************************************************************************/
#ifndef _WRITERAMTHREAD_H_
#define _WRITERAMTHREAD_H_
#include "AbstractPort.h"
#include "Logic.h"

class WriteRamThread
{
public:
  WriteRamThread ()
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
  char _2k;
  void canceled (void);
  
  void set_progress (int ile, int max);
  void error (int err);
};

#endif
