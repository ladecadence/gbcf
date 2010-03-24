/*****************************************************************************
** gbcflsh.cpp - Main source file
** 
** Author: Kraku, CLI Version: David Pello
**
** Adapted to CLI in 2008, for USB version of GBCartFlasher developed by
** David Pello. 	
** zako@ladecadence.net	http://ladecadence.net
*****************************************************************************/

#define __UNIX

#include "const.h"
#include "Settings.h"
#include "Console.h"
#include "Logic.h"
#include "const.h"
#include "ReadFlashThread.h"
#include "EraseThread.h"
#include "WriteFlashThread.h"
#include "ReadRamThread.h"
#include "WriteRamThread.h"


#ifdef __UNIX
#include "USBPort.h"
#endif

#ifdef __WIN32
#include "USBPortWin.h"
#endif

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <stdlib.h>



Settings *settings = new Settings();
Console *console = new Console();


int
parse_params (int /*argc*/, char *argv[])
{
  int act = 0;
  int param = 0; /* not numeric param. */
  while (*++argv)
  {
  	settings->filename.assign(*argv); /* last param is filename */
    if (param == 0) {  	
/* additional communication params */
      if (strcmp (*argv, "-12bit") == 0)
	settings->algorythm = ALG12;
      if (strcmp (*argv, "-longer") == 0)
	settings->dap = LONGER;
      if (strcmp (*argv, "-default") == 0)
	settings->dap = DEFAULT;
      if (strcmp (*argv, "-datapoll") == 0)
	settings->dap = DATAPOLL;
      if (strcmp (*argv, "-showbbl") == 0)
	settings->showbbl = true;
/*
 * USB speed LOW 125000bps HI 375000
 */
      if (strcmp (*argv, "-lowspeed") == 0)
	settings->speed = LOW;
      if (strcmp (*argv, "-highspeed") == 0)
	settings->speed = HIGH;
/* 
 *  What to do
 */
 	if (strcmp (*argv, "--status") == 0)
		act = 1;
	if (strcmp (*argv, "--read-flash") == 0)
		act = 2;
	if (strcmp (*argv, "--write-flash") == 0)
		act = 3;
	if (strcmp (*argv, "--read-ram") == 0)
		act = 4;
	if (strcmp (*argv, "--write-ram") == 0)
		act = 5;	
	if (strcmp (*argv, "--erase-flash") == 0)
		act = 6;
	if (strcmp (*argv, "--erase-ram") == 0)
		act = 7;
	if (strcmp (*argv, "--help") == 0)
		act = 8;
		
/* second level params */
	
	if (strcmp (*argv, "--ram") == 0)
		param = 1;
	
	if (strcmp (*argv, "--flash") == 0)
		param = 2;
	
    }
    
/* numbers */

    else {
    	if (param == 1) {
    		settings->setRam(atoi(*argv));
    		param = 0;
    	}
    	if (param == 2) {
    		settings->setFlash(atoi(*argv));
    		param = 0;
    	}
    }
    	
  }

return act;
    
}

void
print_error (int err)
{
  switch (err)
    {
    case FILEERROR_O:
      console->print (">Error opening file.");
      break;

    case FILEERROR_W:
      console->print (">File write error.");
      break;

    case FILEERROR_R:
      console->print (">File read error.");
      break;

    case SEND_ERROR:
      console->print (">Error sending data to device.");
      break;

    case TIMEOUT:
      console->print (">Timeout!");
      break;

    case END:
      console->print (">Canceled.");
      break;

    case PORT_ERROR:
      console->print (">Error opening COM port.");
      break;

    case WRONG_SIZE:
      console->print (">Bad file size.");
      break;

    case false:
      console->print (">Operation failure.");
      break;

    case true:
      console->print (">Success!");	/* succes is not a error code */
      break;
    }

  console->line ();
}


void
show_info ()
{
  status_t status;
  std::ostringstream tmp (std::ostringstream::out);
  char* str;
  AbstractPort *port = new USBPort;
  int return_code = Logic::read_status (port, "", READ_ID,
					0x00,
					0x00, &status);

  if (return_code == true)	/* no error */
    {
      console->print ("--Device information--");
      console->line();
      tmp << (int)status.ver_11 << (int)status.ver_12 << "." << (int)status.ver_21
      	  << (int)status.ver_22;
      console->print ("Device firmware version:");
      console->print (tmp.str());
      console->print ("\n--Cartridge information--");
      console->line();
      tmp.str("");
      tmp << "0x" << std::hex << (int)status.manufacturer_id;
      console->print ("FLASH memory manufacturer ID:");
      console->print (tmp.str());
      console->line();
      tmp.str("");
      tmp << (char*)status.manufacturer;
      console->print ("FLASH memory manufacturer name:");
      console->print (tmp.str());
      console->line();
      tmp.str("");
      tmp << " 0x" << std::hex << (int)status.chip_id;
      console->print ("FLASH memory chip ID:" + tmp.str());
	  console->line();

      if (Settings::showbbl == true)
	{
	  if (status.bbl == 1)
	    tmp.str("Locked!");
	  else
	    tmp.str("Unlocked");
	  console->print ("Boot Block Status: ");
	  console->print(tmp.str());
	}

      if (status.logo_correct == true)
	  {
	  console->print ("\n--ROM/FLASH content information--\n");
	  console->print ("Game logo signature is correct.\n");
	  tmp.str("");
	  tmp.str((char*)status.game_name);
	  console->print ("Game title:");
	  console->print (tmp.str());
	  console->line();
	  if (status.cgb == 1)
	    tmp.str("YES");
	  else
	    tmp.str("NO");
	  console->print ("Designed for Color GB: " + tmp.str());
	  console->line();
	  if (status.sgb == 1)
	    tmp.str("YES");
	  else
	    tmp.str("NO");
	  console->print ("Designed for Super GB: " + tmp.str());
	  console->line();
	  tmp.str("");
	  tmp << status.typ;
	  console->print ("Cartridge type: " + tmp.str());
	  console->line();
	  tmp.str("");
	  tmp << status.rom_size;
	  console->print ("ROM size: " + tmp.str());
	  console->line();
	  tmp.str("");
	  tmp << status.ram_size;
	  console->print ("RAM size: " + tmp.str());
	  console->line();
	  tmp.str("");
	  tmp << "0x" << std::hex << (int)status.crc16;
	  console->print ("Checksum: " + tmp.str());
	  console->line ();
	}
      else
	{
	  console->print ("Game logo signature is incorrect.\n");
	  console->
	    print ("Cartridge is blank, damaged or not connected.");
	  console->line ();
	}
    }
  else
    print_error (return_code);

}

void
read_flash (void)
{
  std::string file_name = settings->filename;
  
  ReadFlashThread* thread_RFLA = new ReadFlashThread();
  std::string path = Logic::get_path (file_name);
  if (file_name != "")
    {
      thread_RFLA->port = new USBPort;
      if (thread_RFLA->port->open_port ("") == false)
	{
	  print_error (PORT_ERROR);
	  return;
	}
      if ((file_name.find(".gb") == -1)
	  && (file_name.find(".gbc") == -1)
	  && (file_name.find(".sgb") == -1))
	  file_name.append(".gb");

      thread_RFLA->file = fopen (file_name.c_str(), "wb");
      thread_RFLA->mbc = settings->getMbc ();
      thread_RFLA->page_count = settings->getFlash () / 16;
      thread_RFLA->dap = settings->dap;
      thread_RFLA->algorythm = settings->algorythm;


      console->print ("Reading data from FLASH to file: " +
		      file_name + " ...");
	  console->line();
      thread_RFLA->run ();

    }
}

void
erase_flash (void)
{
  EraseThread *thread_E = new EraseThread();
  thread_E->port = new USBPort;
  if (thread_E->port->open_port ("") == false)
    {
      print_error (PORT_ERROR);
      return;
    }
  thread_E->mbc = settings->getMbc ();
  thread_E->mem = EFLA;		//FLASH
  thread_E->par = settings->algorythm;
  thread_E->dap = settings->dap;
  console->print ("Erasing FLASH memory...");
  console->line();
  thread_E->run();
}

void
erase_ram (void)
{
  EraseThread *thread_E = new EraseThread(); 
  thread_E->port = new USBPort ();
  if (thread_E->port->open_port ("") == false)
    {
      print_error (PORT_ERROR);
      return;
    }
  int window_count;
  thread_E->mbc = settings->getMbc ();
  thread_E->mem = ERAM;
  switch (settings->getRam ())
    {
    case 2:
    case 8:
      window_count = 0;
      break;
    case 32:
      window_count = 3;
      break;
    case 128:
      window_count = 15;
      break;
    default:
      window_count = 15;
    }

  thread_E->par = window_count;
  thread_E->dap = settings->dap;
  console->print ("Erasing RAM memory...");
  console->line();
  thread_E->run ();
}

void
write_flash (void)
{

  std::string file_name = settings->filename;
  WriteFlashThread* thread_WFLA = new WriteFlashThread();
  std::string path = Logic::get_path (file_name);
  if (file_name != "")
    {
      long bytes_count;
      short kilobytes_count;
      thread_WFLA->port = new USBPort;
      if (thread_WFLA->port->open_port ("") == false)
	{
	  print_error (PORT_ERROR);
	  return;
	}
      thread_WFLA->file = fopen (file_name.c_str(), "rb");
      thread_WFLA->mbc = settings->getMbc ();
      thread_WFLA->algorythm = settings->algorythm;
      thread_WFLA->dap = settings->dap;

      if (settings->isAuto () == false)
	{
	  bytes_count = Logic::file_size (thread_WFLA->file);
	  thread_WFLA->page_count =
	    (short) ((bytes_count % 16384L) ? (bytes_count / 16384 +
					       1) : (bytes_count / 16384L));
	  kilobytes_count =
	    (short) ((bytes_count % 1024L) ? (bytes_count / 1024 +
					      1) : (bytes_count / 1024L));

	}
      else if ((kilobytes_count = Logic::flash_file_size (thread_WFLA->file))
	       != false)
	thread_WFLA->page_count = kilobytes_count / 16;
      else
	{
	  print_error (WRONG_SIZE);
	  thread_WFLA->port->close_port ();
	  return;
	}
      
      console->print ("Writing data to FLASH from file: \n" +
		      file_name + "\n");
      std::cout << "File size: " << kilobytes_count << " KB" << std::endl;
		      
	  thread_WFLA->run ();
    }
}

void
read_ram (void)
{


  std::string file_name = settings->filename;
  std::string path = Logic::get_path (file_name);
  
  ReadRamThread *thread_RRAM = new ReadRamThread;
  
  if (file_name != "")
    {
      thread_RRAM->port = new USBPort;
      if (thread_RRAM->port->open_port ("") == false)
	{
	  print_error (PORT_ERROR);
	  return;
	}
      if (file_name.find(".sav") == -1)
			file_name.append(".sav");
      thread_RRAM->file = fopen (file_name.c_str(), "wb");
      thread_RRAM->mbc = settings->getMbc ();
      thread_RRAM->algorythm = settings->algorythm;
      thread_RRAM->dap = settings->dap;
      if (settings->getRam () == 2)
	{
	  thread_RRAM->_2k = 1;
	  thread_RRAM->page_count = 1;
	}
      else
	{
	  thread_RRAM->_2k = 0;
	  thread_RRAM->page_count = settings->getRam () / 8;
	}
      console->print ("Reading data from RAM to file:\n" +
		      file_name);
      console->line();
      
      thread_RRAM->run();

    }
}

void
write_ram (void)
{

  std::string file_name = settings->filename;
  
  std::string path = Logic::get_path (file_name);
  
  WriteRamThread *thread_WRAM =  new WriteRamThread;
  
  if (file_name != "")
    {
      long bytes_count;
      short kilobytes_count;
      thread_WRAM->port = new USBPort;
      if (thread_WRAM->port->open_port ("") == false)
	{
	  print_error (PORT_ERROR);
	  return;
	}
      thread_WRAM->file = fopen (file_name.c_str(), "rb");
      thread_WRAM->mbc = settings->getMbc ();
      thread_WRAM->algorythm = settings->algorythm;
      thread_WRAM->dap = settings->dap;

      if (settings->isAuto () == false)
	{
	  bytes_count = Logic::file_size (thread_WRAM->file);
	  if (bytes_count == 2048)
	    {
	      thread_WRAM->_2k = 1;
	      thread_WRAM->page_count = 1;
	      kilobytes_count = 2;
	    }
	  else
	    {
	      thread_WRAM->_2k = 0;
	      thread_WRAM->page_count =
		(short) ((bytes_count % 8192L) ? (bytes_count / 8192L +
						  1) : bytes_count / 8192L);
	      kilobytes_count =
		(short) ((bytes_count % 1024L) ? (bytes_count / 1024 +
						  1) : (bytes_count / 1024L));
	    }
	}
      else if ((kilobytes_count = Logic::ram_file_size (thread_WRAM->file)) !=
	       false)
	if (kilobytes_count == 2)
	  {
	    thread_WRAM->_2k = 1;
	    thread_WRAM->page_count = 1;
	  }
	else
	  {
	    thread_WRAM->_2k = 0;
	    thread_WRAM->page_count = kilobytes_count / 8;
	  }
      else
	{
	  print_error (WRONG_SIZE);
	  thread_WRAM->port->close_port ();
	  return;
	}

      console->print ("Writing data to RAM from file:\n" +
		      file_name + "\n");
      std::cout << "File size: " << kilobytes_count <<
		      " KB" << std::endl;
		      
	  thread_WRAM->run();
    }
}

int
help() 
{
	console->line();
	console->print("USAGE:\n");
	console->print("gbcf <action> [options] [file]\n");
	console->line();
	console->print("ACTIONS:\n");
	console->print("--status:       Show cartridge information\n");
	console->print("--read-flash :  Read Cartridge FLASH Memory (ROM)\n");
	console->print("--write-flash:  Write cartridge FLASH Memory\n");
	console->print("--erase-flash:  Clear cartridge FLASH Memory\n");
	console->print("--read-ram:     Read cartridge RAM Memory (Saves)\n");
	console->print("--write-ram:    Write cartridge RAM Memory\n");
	console->print("--erase-ram:    Clear cartridge RAM Memory\n");
	console->line();
	console->print("OPTIONS:\n");
	console->print("--flash <num>:  Flash Size:\n");
	console->print("                0=32Kb, 1=64Kb, 2=128Kb, 3=256Kb, 4=512Kb, 5=1Mb\n");
	console->print("                6=2Mb, 7=4Mb, 8=8Mb\n");
	console->print("--ram <num>:    RAM Size:\n");
	console->print("                0=2KB, 1=8KB, 2=32KB, 3=128KB\n");
	console->line();
	
}


int
main (int argc, char *argv[])
{  

  status_t status;
  
  /* defaults */
  settings->setFlash(5);
  settings->setRam(2);
  
  /* what to do */
  int action;
  
  action = parse_params (argc, argv);
  
  /* Greeting */
  console->print("GB Flasher CLI v0.15");
  console->line();
  
  /* Test if some action was specified */
  if (action == 0) {
  	console->print(">> ERROR. No action specified");
  	console->line();
  	exit(1);
  }  
  
  switch (action) {
	case 1:
		settings->setMbc(MBCAUTO);
		settings->algorythm = ALG16;
		show_info();
		break;
	case 2:
		settings->setMbc(MBCAUTO);
		settings->algorythm = ALG16;
		read_flash();
		break;
	case 3:
		settings->setMbc(MBCAUTO);
		settings->algorythm = ALG16;
		write_flash();
		break;
	case 4:
		settings->setMbc(MBCAUTO);
		settings->algorythm = ALG16;
		read_ram();
		break;
	case 5:
		settings->setMbc(MBCAUTO);
		settings->algorythm = ALG16;
		write_ram();
		break;
	case 6:
		settings->setMbc(MBCAUTO);
		settings->algorythm = ALG16;
		erase_flash();
		break;
    case 7:
    	settings->setMbc(MBCAUTO);
		settings->algorythm = ALG16;
		erase_ram();
		break;		
	case 8:
		help();
		break;
  }  	 
  
  return 0;
  
}
