/*
 Rocrail - Model Railroad Control System

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

/*
 * CAN over TCP/IP 13 byte format:
 *
 *  |  0   |  1    | 2 | 3 |  4  | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
 *  | PRIO CMD RSP | HASH  | DLC |             DATA                 |
 *
 *
 *
 *
 */


#ifndef MCS2CONST_H_
#define MCS2CONST_H_

#define BIT_RESPONSE 0x01

/* SYSTEM */
#define CMD_SYSTEM            0x00
#define ID_SYSTEM             0x00
#define CMD_SYSSUB_STOP       0x00
#define CMD_SYSSUB_GO         0x01
#define CMD_SYSSUB_HALT       0x02
#define CMD_SYSSUB_EMBREAK    0x03
#define CMD_SYSSUB_STOPCYCLE  0x04
#define CMD_SYSSUB_LOCOPROT   0x05
#define CMD_SYSSUB_SWTIME     0x06
#define CMD_SYSSUB_ENAPROT    0x08
#define CMD_SYSSUB_NEWREGNR   0x09
#define CMD_SYSSUB_OVERLOAD   0x0A
#define CMD_SYSSUB_STATUS     0x0B
#define CMD_SYSSUB_GKENNUNG   0x0C
#define CMD_SYSSUB_RESET      0x80

/* PROTOCOLS */
#define PROT_MM2              0x01
#define PROT_MFX              0x02
#define PROT_DCC              0x04

/* LOC PROTOCOLS */
#define LOCO_PROT_DCC_28      0x00
#define LOCO_PROT_DCC_14      0x01
#define LOCO_PROT_DCC_128     0x02
#define LOCO_PROT_DCC_L_28    0x03
#define LOCO_PROT_DCC_L_128   0x04

/* LOCOs */
#define CMD_LOCO_DISCOVERY    0x01
#define ID_LOCO_DISCOVERY     0x02

#define CMD_LOCO_BIND         0x02
#define ID_LOCO_BIND          0x04

#define CMD_LOCO_VERIFY       0x03
#define ID_LOCO_VERIFY        0x06

#define CMD_LOCO_VELOCITY     0x04
#define ID_LOCO_VELOCITY      0x08

#define CMD_LOCO_DIRECTION    0x05
#define ID_LOCO_DIRECTION     0x0A

#define CMD_LOCO_FUNCTION     0x06
#define ID_LOCO_FUNCTION      0x0C

#define CMD_LOCO_READ_CONFIG  0x07
#define ID_LOCO_READ_CONFIG   0x0E

#define CMD_LOCO_WRITE_CONFIG 0x08
#define ID_LOCO_WRITE_CONFIG  0x10


/* ACCESSORIES */
#define CMD_ACC_SWITCH        0x0B
#define ID_ACC_SWITCH         0x16
#define ID_ACC_SWITCH_RSP     0x17
#define CMD_ACC_SENSOR        0x11


/* SOFTWARE */
#define CAN_CMD_PING         0x18
#define CAN_ID_PING          0x30

/* Sensors */
#define CAN_S88_REPORT       0x21
#define CAN_SENSOR_EVENT     0x23

/* CAN device control */
# define CMD_CAN_BOOT_BOUND  0x1B
# define ID_CAN_BOOT_BOUND   0x36

/* System Status data */
#define CMD_SYS_STAT_DATA    0x1D
#define ID_SYS_STAT_DATA     0x3A

#endif /* MCS2CONST_H_ */
