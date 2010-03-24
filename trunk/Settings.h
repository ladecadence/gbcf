/*****************************************************************************
** Settings.h - configuration widget
** Author: Kraku, CLI Version: David Pello
*****************************************************************************/
#ifndef _SETTINGS_H_
#define _SETTINGS_H_

#include "const.h"
#include <string>

class Settings
{
  mbc_t mbc;
  int flash_size;
  int ram_size;
  bool auto_size;
  bool usb;
  bool ram;


public:
  Settings();
  std::string filename;
  static alg_t algorythm;
  static dap_t dap;
  static bool showbbl;
  static speed_type speed;

  int getFlash ()
  {
    return flash_size;
  }

  int getRam ()
  {
    return ram_size;
  }

  mbc_t getMbc ()
  {
    if (mbc == MBC5 || mbc == RUMBLE)
      return MBC5;
    else
      return mbc;
  }
  bool isAuto ()
  {
    return auto_size;
  }

  bool isRamDisabled ()
  {

    return !ram;
  }
  
  void setMbc (int mbc_nr);
  void setFlash (int index);
  void setRam (int index);

  void setAuto (int state);

};

#endif
