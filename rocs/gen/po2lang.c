/* ------------------------------------------------------------
 Copyright (C) 2002-2014 Rob Versluis, Rocrail.net

 


 * libc interfaces.
 */
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <time.h>

/* ------------------------------------------------------------
 * platform dependent interfaces.
 */
#if defined __linux__ || defined __aix__
#include <sys/resource.h>
#endif

/* ------------------------------------------------------------
 * rocs interfaces.
 */
#include "rocs/public/mem.h"
#include "rocs/public/trace.h"
#include "rocs/public/file.h"
#include "rocs/public/doc.h"
#include "rocs/public/node.h"
#include "rocs/public/system.h"
#include "rocs/public/str.h"
#include "rocs/public/list.h"
#include "rocs/public/map.h"
#include "rocs/public/thread.h"
#include "rocs/public/cmdln.h"

static iOMap nodeMap = NULL;
static iOMap enMap = NULL;
static iOMap tipMap = NULL;

static const char* package   = "PACKAGE";
static const char* language  = "LANGUAGE";
static const char* copyright = "YEAR THE PACKAGE'S COPYRIGHT HOLDER";


static void __po2lang( char* po, iONode xml, const char* lang );


static void __createMap(iONode root) {
  iONode msg = NodeOp.findNode( root, "Msg" );

  nodeMap = MapOp.inst();
  enMap = MapOp.inst();
  tipMap = MapOp.inst();
  while( msg != NULL ) {
    const char* id = NodeOp.getStr(msg, "id", NULL);
    iONode enlang = NodeOp.findNode( msg, "en" );

    if( id != NULL ) {
      TraceOp.println( "added [%s] to map", id );
      MapOp.put( nodeMap, id, (obj)msg );
    }

    if( enlang != NULL ) {
      const char* id = NodeOp.getStr(enlang, "txt", NULL);
      if( id != NULL ) {
        TraceOp.println( "added [%s] to ENmap", id );
        MapOp.put( enMap, id, (obj)msg );
      }
      id = NodeOp.getStr(enlang, "tip", NULL);
      if( id != NULL ) {
        TraceOp.println( "added [%s] to TIPmap", id );
        MapOp.put( tipMap, id, (obj)msg );
      }
    }

    msg = NodeOp.findNextNode( root, msg );
  };

}

/** ------------------------------------------------------------
  * public main()
  * usage: po2lang -i <po-file> -o <xml-file> [-l <lang>]
  *
  * @param  argc Number of commanline arguments.
  * @param  argv Commanline arguments.
  * @return      Applications exit code.
  */
int main( int argc, const char* argv[] ) {
  int rc = 0;
  iOCmdLn arg = NULL;
  const char* infile = NULL;
  const char* outfile = NULL;
  const char* lang = NULL;


  iOTrace trc = TraceOp.inst( TRCLEVEL_INFO, "po2lang", True );
  TraceOp.setAppID( trc, "a" );

  /* Enable coredump for Linux platforms. */
  #if defined __linux__
  {
    struct rlimit rl;
    getrlimit( RLIMIT_CORE, &rl );
    /* Default = 0 */
    rl.rlim_cur = 10240 * 10240;
    setrlimit( RLIMIT_CORE, &rl );
  }
  #endif

  /* Resets memory statistics. */
  MemOp.resetDump();

  /* Check commandline arguments. */
  arg = CmdLnOp.inst( argc, argv );

  infile   = CmdLnOp.getStrDef( arg, "-i", NULL );
  outfile  = CmdLnOp.getStrDef( arg, "-o", NULL );
  lang     = CmdLnOp.getStrDef( arg, "-l", NULL );
  package  = CmdLnOp.getStrDef( arg, "-p", NULL );

  /* Read const.xml */
  if( infile != NULL && FileOp.exist(infile) && lang != NULL && outfile != NULL && FileOp.exist(outfile) ) {
    TraceOp.println( "Processing %s...", infile );
    {
      iOFile constXml = FileOp.inst( outfile, OPEN_READONLY );
      char* xmlStr = allocMem( FileOp.size( constXml ) + 1 );
      iODoc doc = NULL;
      iONode root = NULL;

      TraceOp.println( "Reading %s...", outfile );
      FileOp.read( constXml, xmlStr, FileOp.size( constXml ) );
      FileOp.close( constXml );
      FileOp.base.del( constXml );

      TraceOp.println( "Parsing %s...", outfile );
      doc = DocOp.parse( xmlStr );
      freeMem( xmlStr );
      if( doc == NULL ) {
        TraceOp.println( "invalid file %s...", outfile );
        return -1;
      }
      root = DocOp.getRootNode( doc );
      __createMap(root);

      TraceOp.println( "Reading %s...", infile );
      {
        iOFile pofile = FileOp.inst( infile, OPEN_READONLY );
        char* po = allocMem( FileOp.size( pofile ) + 1 );
        FileOp.read( pofile, po, FileOp.size( pofile ) );
        FileOp.close( pofile );
        FileOp.base.del( pofile );
        __po2lang( po, root, lang );


        iOFile constXml = FileOp.inst( outfile, OPEN_WRITE );
        TraceOp.println( "serialize..." );
        xmlStr = NodeOp.base.toString(root);
        TraceOp.println( "writing %s...", outfile );
        FileOp.write( constXml, xmlStr, StrOp.len( xmlStr ) );
        FileOp.close( constXml );
        FileOp.base.del( constXml );

      }

    }

  }
  else {
    TraceOp.println( "usage: po2lang -i <po-file> -o <xml-file> -l <lang>" );
  }

  return rc;
}



/* The input file should be formated like this:
<Messages>
  <Msg id="thanks">
    <de txt="Besonderer Dank an:"/>
    <en txt="Special thanks to:"/>
    <nl txt="Met speciale dank aan:"/>
    <sv txt="Special thanks to:"/>
    <fr txt="Remerciement:"/>
  </Msg>
</Messages>
*/


static void __merge( const char* aid, const char* msgstr, const char* lang, iONode xml ) {
  /*
    iONode msg = NodeOp.findNode( xml, "Msg" );
    iONode en     = NodeOp.findNode( msg, "en" );
    iONode polang = NodeOp.findNode( msg, lang );
    msg = NodeOp.findNextNode( xml, msg );
  */
  Boolean tip = False;
  iONode msg = (iONode)MapOp.get( nodeMap, aid);
  if( msg == NULL ) {
    msg = (iONode)MapOp.get( enMap, aid);
  }
  if( msg == NULL ) {
    msg = (iONode)MapOp.get( tipMap, aid);
    tip = True;
  }

  if( StrOp.len(msgstr) == 0 ) {
    TraceOp.println( "skip empty msgstr..." );
    return;
  }

  TraceOp.println( "id=[%s]", aid );

  if( msg != NULL ) {
    iONode polang = NodeOp.findNode( msg, lang );
    if( polang == NULL ) {
      polang = NodeOp.inst( lang, msg, ELEMENT_NODE );
      TraceOp.println( "adding [%s]", lang );
      NodeOp.addChild(msg, polang);
    }
    if( tip ) {
      NodeOp.setStr( polang, "tip", msgstr );
      TraceOp.println( "replace tip [%s] with [%s]", NodeOp.getStr( polang, "tip", "" ), msgstr );
    }
    else {
      NodeOp.setStr( polang, "txt", msgstr );
      TraceOp.println( "replace [%s] with [%s]", NodeOp.getStr( polang, "txt", "" ), msgstr );
    }
  }
  else {
    TraceOp.println( "undef id[%s]", aid );

  }

}


/*
#. context
# id="myname"
#, c-format
msgid "My name is %s.\n"
msgstr ""

# id="change_language_msg"
#, c-format
msgid ""
"The language setting of the user interface has been updated and will take "
"effect the next time you start."
msgstr ""
"Die Spracheinstellung der Benutzeroberfläche wurde geändert und wird erst "
"beim nächsten Start wirksam."

# id="straight"
#, c-format
msgid "Straight"
msgstr "Gerade"

*/

/* po file witout id:
#, c-format
msgid "no"
msgstr "Ne"
*/

static void __po2lang( char* po, iONode xml, const char* lang ) {
  int cnt = 0;
  char* msgid = StrOp.find( po, "msgid \"" );


  while( msgid != NULL ) {
    char* msgstr = StrOp.find( msgid, "msgstr \"" );
    char* endline = NULL;
    char* tmp = NULL;
    char* str = NULL;
    char* id  = NULL;

    if( msgstr != NULL ) {
      TraceOp.println( "try to find end of id..." );

      /* looking for all lines */
      endline = msgid + 5;
      while( endline[1] == '\"' ) {
        msgid = endline + 2;
        endline = StrOp.find( endline+1, "\n");
        tmp = endline;

        while( tmp[0] != '\"' && msgid != tmp ) {
          tmp--;
        }
        tmp[0] = '\0';

        id = StrOp.cat( id, msgid );
      }
      TraceOp.println( "id=%s", id );


      TraceOp.println( "try to find end of msgstr..." );
      /* looking for all lines */
      endline = msgstr + 6;
      while( endline[1] == '\"' ) {
        msgstr = endline + 2;
        endline = StrOp.find( endline+1, "\n");
        tmp = endline;

        while( tmp[0] != '\"' && msgstr != tmp ) {
          tmp--;
        }
        tmp[0] = '\0';

        str = StrOp.cat( str, msgstr );
        TraceOp.println( "id[%s] msgstr[%s]", id, str );
      }

      __merge( id, str, lang, xml );
      StrOp.free(id);
      StrOp.free(str);

      cnt++;
    }
    msgid = StrOp.find( endline + 1, "msgid \"" );

  };
  TraceOp.println( "Merged [%d] msgid's", cnt );

}
