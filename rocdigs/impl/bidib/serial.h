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
#ifndef BIDIBSERIAL_H_
#define BIDIBSERIAL_H_

Boolean serialInit( obj inst );
Boolean serialConnect( obj inst );
void  serialDisconnect( obj inst );

int serialRead ( obj inst, unsigned char *msg );
Boolean serialWrite( obj inst, unsigned char *path, unsigned char code, unsigned char* data, int datalen, void* node );
Boolean serialAvailable( obj inst );

#endif /*BIDIBSERIAL_H_*/
