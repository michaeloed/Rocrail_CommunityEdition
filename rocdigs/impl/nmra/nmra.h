/*
 Rocrail - Model Railroad Software

 Copyright (C) 2002-2014 Rob Versluis, Rocrail.net

 

 Some parts are copied from the DDL project of Torsten Vogt: http://www.vogt-it.com/OpenSource/DDL

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/
#ifndef __IMPL_NMRA_H__
#define __IMPL_NMRA_H__

#include "rocs/public/mem.h"


/* signal generating functions for nmra dcc */

int idlePacket(char* packetstream, Boolean longIdle);

/* standard decoder */
int compSpeed14(char* packetstream, int address, int direction, int speed);


int compSpeed(char* packetstream, int address, Boolean longaddr, int direction, int speed, int steps);
int compFunction(char* packetstream, int address, Boolean longaddr, int group, Boolean f[]);
int compBinStat(char* packetstream, int address, Boolean longaddr, int nr, int val);

/* short addresses */
int compSpeed28ShortAddr(char* packetstream, int address, int direction, int speed);
int compSpeed128ShortAddr(char* packetstream, int address, int direction, int speed);
int compFunctionShortAddr(char* packetstream, int address, int group, Boolean f[]);

/* long addresses */
int compSpeed28LongAddr(char* packetstream, int address, int direction, int speed);
int compSpeed128LongAddr(char* packetstream, int address, int direction, int speed);
int compFunctionLongAddr(char* packetstream, int address, int group, Boolean f[]);

/* accessory decoder */
int compAccessory(char* packetstream, int addr, int port, int gate, int activate);

/* POM */
int dccPOM(char* packetstream, int address, Boolean longaddr, int cvNum, int data, Boolean verify);

/* PT */
int createCVgetpacket(int cv, int value, char* SendStream, int start);
int createCVsetpacket(int cv, int value, char* SendStream, int verify);
char* getResetStream(int *rsSize);


#endif
