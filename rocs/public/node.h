/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#ifndef __object_Node_H
#define __object_Node_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/attr.h"

#ifdef __cplusplus
  extern "C" {
#endif


typedef enum {ELEMENT_NODE, TEXT_NODE, PROPERTY_NODE, REMARK_NODE, VARIABLE_NODE} nodetype;



typedef struct ONode {
  /***** Base *****/
  struct OBase  base;

  /***** Object: Node *****/
  /** Add an attribute. */
  void (*addAttr)( struct ONode* inst ,iOAttr attr );
  /** Add a child node. */
  void (*addChild)( struct ONode* inst ,struct ONode* child );
  /** Search for an attribute with the given name. */
  iOAttr (*findAttr)( struct ONode* inst ,const char* attrname );
  /** Find next node with the same name. */
  struct ONode* (*findNextNode)( struct ONode* inst ,struct ONode* node );
  /** Search for a child node with the given name. */
  struct ONode* (*findNode)( struct ONode* inst ,const char* nodename );
  /** Get an attribute by index. */
  iOAttr (*getAttr)( struct ONode* inst ,int idx );
  /** Get the number of attributes. */
  int (*getAttrCnt)( struct ONode* inst );
  /** Get an attribute value as boolean. */
  Boolean (*getBool)( struct ONode* inst ,const char* attrname ,Boolean defval );
  /** Get an child node by index. */
  struct ONode* (*getChild)( struct ONode* inst ,int idx );
  /** Get the number of child nodes. */
  int (*getChildCnt)( struct ONode* inst );
  /** Get an attribute value as float. */
  double (*getFloat)( struct ONode* inst ,const char* attrname ,double defval );
  /** Get an attribute value as integer. */
  int (*getInt)( struct ONode* inst ,const char* attrname ,int defval );
  /** Get an attribute value as long. */
  long (*getLong)( struct ONode* inst ,const char* attrname ,long defval );
  /** Get the node name. */
  const char* (*getName)( struct ONode* inst );
  /** Same as findNode but if no node is found it creates one. */
  struct ONode* (*getNode)( struct ONode* inst ,const char* nodename );
  /** Get the parent node. */
  struct ONode* (*getParent)( struct ONode* inst );
  /** Get an attribute value as string. */
  const char* (*getStr)( struct ONode* inst ,const char* attrname ,const char* defval );
  /** Get the node type. */
  nodetype (*getType)( struct ONode* inst );
  /** Object creator */
  struct ONode* (*inst)( const char* name ,struct ONode* parent ,nodetype type );
  /** Merge nodeB into A. */
  struct ONode* (*mergeNode)( struct ONode* nodeA ,struct ONode* nodeB ,Boolean overwrite ,Boolean recursive ,Boolean keepid );
  /** Removes an attribute. */
  void (*removeAttr)( struct ONode* inst ,iOAttr attr );
  /** Removes an attribute. */
  void (*removeAttrByName)( struct ONode* inst ,const char* name );
  /** Remove a child node. */
  struct ONode* (*removeChild)( struct ONode* inst ,struct ONode* child );
  /** Set an attribute value as boolean. */
  void (*setBool)( struct ONode* inst ,const char* attrname ,Boolean val );
  /** Set an attribute value as float. */
  void (*setFloat)( struct ONode* inst ,const char* attrname ,double val );
  /** Set an attribute value as integer. */
  void (*setInt)( struct ONode* inst ,const char* attrname ,int val );
  /** Set an attribute value as long. */
  void (*setLong)( struct ONode* inst ,const char* attrname ,long val );
  /** Set the node name. */
  void (*setName)( struct ONode* inst ,const char* name );
  /** Change or set parent of this node. */
  void (*setParent)( struct ONode* inst ,struct ONode* parent );
  /** Set an attribute value as string. */
  void (*setStr)( struct ONode* inst ,const char* attrname ,const char* val );
  /** Set the node type. */
  void (*setType)( struct ONode* inst ,nodetype type );
  /** Serialize this node with escaped attribute values. */
  char* (*toEscString)( struct ONode* inst );
} *iONode;

extern struct ONode NodeOp;

#ifdef __cplusplus
  }
#endif


#endif
