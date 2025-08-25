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

#ifndef RNUTILS_H_
#define RNUTILS_H_

unsigned char rnChecksum(const unsigned char *b, int len);

int rnCheckPacket(unsigned char* rn, int* extended, int* event);

int rnSenderAddrFromPacket(unsigned char* rn, int seven);
int rnReceipientAddrFromPacket(unsigned char* rn, int seven);
void rnSenderAddresToPacket( int addr, unsigned char* rn, int seven );
void rnReceipientAddresToPacket( int addr, unsigned char* rn, int seven );
const char* rnActionTypeString(unsigned char* rn);
int rnActionFromPacket(unsigned char* rn);
int rnActionTypeFromPacket(unsigned char* rn);
const char* rnClassString(int pclass, char* mnemonic);
const char* rnGetRC(int rc);
const char* rnGetRS(int rs);



#endif /*RNUTILS_H_*/
