/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#ifndef __object_Str_H
#define __object_Str_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/mem.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OStr {

  /***** Object: Str *****/
  /** Converts binary data into a hex string like 0AFE... */
  char* (*byteToStr)( unsigned char* bin ,int len );
  /**  */
  char* (*cat)( char* dest ,const char* src );
  /**  */
  char* (*catID)( char* dest ,const char* src ,RocsMemID id );
  /** Copies a string. */
  char* (*copy)( char* dst ,const char* src );
  /** Copies a zero terminated string as a non-zero terminated string. */
  int (*copynz)( char* snz ,int snzlen ,const char* str );
  /** Creates a timestamp: YYYYmmdd.hhMMss.SSS. */
  char* (*createStamp)( void );
  /** Creates a timestamp: YYYYmmdd.hhMMss.SSS. */
  char* (*createStampID)( RocsMemID id );
  /** Creates a timestamp: YYYYmmddhhMMssSSS. */
  char* (*createStampNoDots)( void );
  /** replace url escapes with special chars */
  char* (*decode4URL)( const char* url );
  /** Duplicates a string. */
  char* (*dup)( const char* src );
  /** Duplicates a string. */
  char* (*dupID)( const char* src ,RocsMemID id );
  /** replace special chars with url escapes */
  char* (*encode4URL)( const char* url );
  /** Check if str1 ends with str2. */
  Boolean (*endsWith)( const char* str1 ,const char* str2 );
  /** Check if str1 ends with str2. (ignoring case) */
  Boolean (*endsWithi)( const char* str1 ,const char* str2 );
  /** Compares two strings. */
  Boolean (*equals)( const char* str1 ,const char* str2 );
  /** Equals ignore case. */
  Boolean (*equalsi)( const char* str1 ,const char* str2 );
  /** Equals till number off char is reached. */
  Boolean (*equalsn)( const char* str1 ,const char* str2 ,int cnt );
  /** Equals ignore case till number off char is reached. */
  Boolean (*equalsni)( const char* str1 ,const char* str2 ,int cnt );
  /** Finds a substring. */
  char* (*find)( const char* str ,const char* substr );
  /** Find the first occurrence of a character. */
  char* (*findc)( const char* str ,char c );
  /** Finds a substring ignoring case. */
  char* (*findi)( const char* str ,const char* substr );
  /** Formats a string. */
  char* (*fmt)( const char* format ,...  );
  /** Formats a string. */
  char* (*fmtID)( RocsMemID id ,const char* format ,...  );
  /** Formats a string into a buffer. */
  char* (*fmtb)( char* buffer ,const char* format ,...  );
  /** Free up a string allocation. */
  void (*free)( char* str );
  /** Free up a string allocation. */
  void (*freeID)( char* str ,RocsMemID id );
  /** Returns number of linefeed chars found. */
  int (*getCntLinefeeds)( const char* str );
  /** Returns a pointer to the string extension: [readme.txt] would return a pointer to [txt]. */
  char* (*getExtension)( const char* str );
  /** Returns pointer to the specified line. */
  char* (*getLine)( const char* str ,int nr );
  /** Returns pointer to the specified line. */
  char* (*getLineID)( const char* str ,int nr ,RocsMemID id );
  /** Returns pointer to the next line. */
  char* (*getNextLine)( const char* str ,int* nr );
  /** Converts an integer into a non-zero string. */
  void (*int2snz)( char* snz ,int snzlen ,int val );
  /** Creates an ISO date string: YYYY-mm-dd */
  char* (*isoDate)( long tt );
  /** Creates an ISO time string: hh:MM:ss */
  char* (*isoTime)( long tt );
  /** Calculates the string length. */
  int (*len)( const char* str );
  /** Converts an long into a non-zero string. */
  void (*long2snz)( char* snz ,int snzlen ,long val );
  /** Replace all charA's with charB */
  int (*replaceAll)( char* str ,char charA ,char charB );
  /** Replace all substrings with the replacement. */
  char* (*replaceAllSub)( const char* inputString ,const char* substring ,const char* replacement );
  /** Replace all environment variables with there current values. */
  char* (*replaceAllSubstitutions)( const char* str );
  /** Converts an non-zero string as a zero terminated string. */
  char* (*snz2sz)( const char* snz ,int snzlen );
  /** Converts an non-zero string as a zero terminated string. */
  char* (*snz2szID)( const char* snz ,int snzlen ,RocsMemID id );
  /** Check if str1 starts with str2. */
  Boolean (*startsWith)( const char* str1 ,const char* str2 );
  /** Check if str1 starts with str2. (ignoring case) */
  Boolean (*startsWithi)( const char* str1 ,const char* str2 );
  /** Converts a hex string into binary data */
  unsigned char* (*strToByte)( const char* str );
  /** Converts all chars into lowercase. */
  const char* (*strlwr)( const char* str );
  /** Converts all chars into uppercase. */
  const char* (*strupr)( const char* str );
  /** Removes leading and trailing blanks. */
  char* (*trim)( char* str );
  /** Removes trailing blanks. */
  char* (*trimID)( char* str ,RocsMemID id );
} *iOStr;

extern struct OStr StrOp;

#ifdef __cplusplus
  }
#endif


#endif
