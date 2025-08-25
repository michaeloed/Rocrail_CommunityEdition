/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#ifndef __object_Doc_H
#define __object_Doc_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"

#ifdef __cplusplus
  extern "C" {
#endif


typedef enum {MaxNodeNameLen=1024,MaxAttrNameLen=1024,MaxAttrValLen=2048} parserConst;



typedef struct ODoc {
  /***** Base *****/
  struct OBase  base;

  /***** Object: Doc *****/
  const char* ENC_UTF8;
  const char* ENC_ISO885915;
  /** Search for a given attribute in the given node. */
  Boolean (*getBool)( struct ODoc* inst ,const char* nodename ,const char* attrname ,Boolean defval );
  /** Document node keeps all 1st level nodes. */
  iONode (*getDocNode)( struct ODoc* inst );
  /** Get XML encoding for serialize. */
  const char* (*getEncoding)( void );
  /** Get XML encoding as a property: <?xml encoding="UTF-8"?> */
  char* (*getEncodingProperty)( void );
  /** Search for a given attribute in the given node. */
  int (*getInt)( struct ODoc* inst ,const char* nodename ,const char* attrname ,int defval );
  /** This is probably what you want. */
  iONode (*getRootNode)( struct ODoc* inst );
  /** Search for a given attribute in the given node. */
  const char* (*getStr)( struct ODoc* inst ,const char* nodename ,const char* attrname ,const char* defval );
  /** Is HTML escapes set. */
  Boolean (*isHTMLEscapes)( void );
  /** Ignoring case in node and attribute names. */
  Boolean (*isIgnoreCase)( void );
  /** Is UTF-8 decoded to Latin. */
  Boolean (*isUTF2Latin)( void );
  /** Is XML UTF-8 encoded. */
  Boolean (*isUTF8Encoded)( struct ODoc* inst );
  /** UTF-8 encoding for serializing. */
  Boolean (*isUTF8Encoding)( void );
  /** Is UniCode escapes set. */
  Boolean (*isUniCodeEscapes)( void );
  /** Represents a node recursive as string. */
  char* (*node2String)( iONode node ,Boolean escaped );
  /** Parses given buffer. */
  struct ODoc* (*parse)( const char* xml );
  /** Set XML encoding for serialize. */
  void (*setEncoding)( const char* enc );
  /** Set HTML escapes. */
  void (*setHTMLEscapes)( Boolean html );
  /** Ignoring case in node and attribute names. */
  void (*setIgnoreCase)( Boolean ignore );
  /** Is UTF-8 decoded to Latin. */
  void (*setUTF2Latin)( Boolean decode );
  /** Set UniCode escapes. */
  void (*setUniCodeEscapes)( Boolean uni );
  /** Add XML Prolog. */
  void (*setXMLProlog)( Boolean prolog );
} *iODoc;

extern struct ODoc DocOp;

#ifdef __cplusplus
  }
#endif


#endif
