/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#include "rocs/public/node.h"

/* rocs and system includes: */
#include "rocs/public/map.h"

static const char* name = "ONode";

typedef struct ONodeData {

    /** Node name. */
  char* name;
    /** Node type. */
  nodetype ntype;
    /** Number of attributes in node. */
  int attrCnt;
    /** Number of childnodes. */
  int childCnt;
    /** Parent node. */
  iONode parent;
    /** List of attributes. */
  iOAttr* attrs;
    /** Map of attributes which is only used incase of DocOp.isIgnoreCase() == False. */
  iOMap attrmap;
    /** List of child nodes. */
  iONode* childs;

} *iONodeData;

static iONodeData Data( void* p ) { return (iONodeData)((iONode)p)->base.data; }

