/*
 Rocrail - Model Railroad Software

 Copyright (C) 2002-2014 Rob Versluis, Rocrail.net

 


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

#ifndef BIDIBUTILS_H_
#define BIDIBUTILS_H_

/* C++ */
#ifdef __cplusplus
  extern "C" {
#endif

char* bidibGetClassName(int classid, char* mnemonic, Boolean* bridge );
const char* bidibGetFeatureName(int feature);
int bidibDeEscapeMessage(byte* msg, int inLen);
void bidibUpdateCRC(byte newb, byte* crc);
byte bidibCheckSum(byte* packet, int len);
void bidibEscapeMessage(byte* msg, int* newLen, int inLen);
int bidibMakeMessage(byte* msg, int inLen);
const char* bidibGetAccError(int rc);
const char* bidibGetPTState(int state);
const char* bidibGetDynStateName(int dynnum);

/* C++ */
#ifdef __cplusplus
  }
#endif

#endif /* BIDIBUTILS_H_ */
