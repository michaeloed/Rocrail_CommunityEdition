/*
 Copyright (C) 2002-2014 Rob Versluis, Rocrail.net

 

 */

#ifndef __ROCRAIL_H
#define __ROCRAIL_H


#define MANU_ROCRAIL 70
// Module types
#define MTYP_CANGC2  2 // 16 I/O
#define MTYP_CANGC4  4 // 8 channel rfid12 concentrator
#define MTYP_CANGC6  6 // 4 Chanal Servo
#define MTYP_CANGC7  7 // Fast clock
#define MTYP_CANGC8  8 // Display driver
#define MTYP_CANGC1E  11 // Ethernet bridge
#define MTYP_CANGCLN  56 // LocoNet bridge

#define OPC_DSPLOC 0x24    // Dispatch Loco <session>
#define OPC_PNN    0xB6    // <NN hi><NN lo><manu id><module id><flags>

/* Requested at 20-09-2011. (Mike & Pete)
    So the reply to QNN from each node would be a new opcode PNN which would have
    the following format:

    #define OPC_PNN    0xB6     // <NN hi><NN lo><manu id><module id><flags>

    The manufacturer id, module id and flag byte are from the module parameters and
    are as defined for RQNP and RQNPN, see Appendix 1 of spec version 7h.

    With this change, NNACK will only be used in response to SNN.
*/
#define CVMODE_DIRECTBYTE 0
#define CVMODE_DIRECTBIT 1
#define CVMODE_PAGE 2
#define CVMODE_REGISTER 3
#define CVMODE_ADDRONLY 4

// Boot mode codes in extended frames.
#define BOOTCMD_NOP 0
#define BOOTCMD_RESET 1
#define BOOTCMD_INIT 2
#define BOOTCMD_CHECK 3
#define BOOTCMD_TEST 4

#define BOOTMSG_ERR 0
#define BOOTMSG_OK 1
#define BOOTMSG_ACK 2 // Response to the test command.

/* extended opcodes for LNCV */
#define OPC_WLNID   0x87    // Set LocoNet Module ID
#define OPC_QLNID   0x88    // Query LocoNet Module ID
#define OPC_PLNID   0x89    // Report LocoNet Module ID
#define OPC_WLNCV   0x8A    // Write LNCV
#define OPC_QLNCV   0x8B    // Read LNCV
#define OPC_PLNCV   0x8C    // Report LNCV



#endif
