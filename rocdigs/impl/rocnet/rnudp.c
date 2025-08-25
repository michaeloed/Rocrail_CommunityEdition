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
#include "rocdigs/impl/rocnet_impl.h"
#include "rocdigs/impl/rocnet/rnudp.h"

#include "rocrail/wrapper/public/RocNet.h"


Boolean rnUDPConnect( obj inst ) {
  iOrocNetData data = Data(inst);

  data->readUDP = SocketOp.inst( wRocNet.getaddr(data->rnini), wRocNet.getport(data->rnini), False, True, True );
  SocketOp.bind(data->readUDP);
  data->writeUDP = SocketOp.inst( wRocNet.getaddr(data->rnini), wRocNet.getport(data->rnini), False, True, True );
  return True;
}


void rnUDPDisconnect( obj inst ) {
  iOrocNetData data = Data(inst);
}


int rnUDPRead ( obj inst, unsigned char *msg ) {
  iOrocNetData data = Data(inst);
  SocketOp.recvfrom( data->readUDP, (char*)msg, 0x7F, NULL, NULL );
  return 0;
}


Boolean rnUDPWrite( obj inst, unsigned char *msg, int len ) {
  iOrocNetData data = Data(inst);

  SocketOp.sendto( data->writeUDP, (char*)msg, len, NULL, 0 );

  return True;
}


Boolean rnUDPAvailable( obj inst ) {
  iOrocNetData data = Data(inst);
  return True;
}

