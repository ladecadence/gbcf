/*****************************************************************************
** Settings.cpp
** Author: Kraku, CLI Version: David Pello
*****************************************************************************/
#include "Settings.h"
#include <math.h>
#include <string>

alg_t
  Settings::algorythm = ALG16;
dap_t
  Settings::dap = TOGGLE;
bool
  Settings::showbbl = false;
speed_type
  Settings::speed = STANDARD;

Settings::Settings ()
{

  usb = true;
  ram = true;

  auto_size = true;
  mbc = MBCAUTO;
  
  ram_size = 8;
  flash_size = 512;
  
  algorythm = ALG16;
  dap = TOGGLE;
  showbbl = false;
  speed = STANDARD;
  
  filename = "";
      
}


void
Settings::setFlash (int index)
{
  /* size = 32 * 2 ^ index */
  flash_size = 32 * (int) pow (2.0, (double) index);
}

void
Settings::setRam (int index)
{
  switch (index)
    {
    case 0:
      ram_size = 2;
      break;
    case 1:
      ram_size = 8;
      break;
    case 2:
      ram_size = 32;
      break;
    case 3:
      ram_size = 128;
      break;
    }

}

void
Settings::setMbc (int mbc_nr)
{
  mbc = (mbc_t) mbc_nr;
}

void
Settings::setAuto (int state)
{
  if (state == 1)
    auto_size = true;
  else
    auto_size = false;
}
