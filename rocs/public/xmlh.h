/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#ifndef __object_Xmlh_H
#define __object_Xmlh_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"
#include "rocs/public/list.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OXmlh {
  /***** Base *****/
  struct OBase  base;

  /***** Object: Xmlh *****/
  const char* header_tagname;
  const char* xml_tagname;
  const char* bin_tagname;
  int initAllocSize;
  /** Add. */
  void (*addNode)( struct OXmlh* inst ,iONode node );
  /** Get filename for bin block by index. */
  const char* (*getBinName)( struct OXmlh* inst ,int idx );
  /** Get size of bin block by index. */
  long (*getBinSize)( struct OXmlh* inst ,int dataIdx );
  /** Get header childnode by name. */
  iONode (*getNodeByTagName)( struct OXmlh* inst ,const char* name ,int idx );
  /** Get size of block by name. */
  int (*getSizeByTagName)( struct OXmlh* inst ,const char* name ,int idx );
  /** Get node for xml block by index. */
  const char* (*getXmlName)( struct OXmlh* inst ,int dataIdx );
  /** Get size of xml block by index. */
  int (*getXmlSize)( struct OXmlh* inst ,int idx );
  /** Get number of bin nodes. */
  int (*hasBin)( struct OXmlh* inst );
  /** Get number of xml nodes. */
  int (*hasXml)( struct OXmlh* inst );
  /** Object creator. */
  struct OXmlh* (*inst)( Boolean create ,const char* header_tagname ,const char* bin_tagname );
  /** Get error state of Xmlh. */
  Boolean (*isError)( struct OXmlh* inst );
  /** Reads the Xmlh from buffer. True if complete header is read. */
  Boolean (*read)( struct OXmlh* inst ,const byte* buffer ,int size );
  /**  */
  void (*reset)( struct OXmlh* inst );
} *iOXmlh;

extern struct OXmlh XmlhOp;

#ifdef __cplusplus
  }
#endif


#endif
