/*
 Rocs - OS independent C library

 Copyright (C) 2002-2014 Rob Versluis, Rocrail.net

 


 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public License
 as published by the Free Software Foundation.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/
#ifdef _WIN32

#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "rocs/impl/system_impl.h"
#include "rocs/public/trace.h"
#include "rocs/public/mem.h"

#ifndef __ROCS_SYSTEM__
	#pragma message("*** Win32 OSystem is disabled. (define __ROCS_SYSTEM__ in rocs.h) ***")
#endif
/*
 ***** __Private functions.
 */
const char* rocs_system_getWSName( iOSystemData o ) {
#ifdef __ROCS_SYSTEM__
  unsigned long size = sizeof o->WSName;
  if( !GetComputerName( o->WSName, &size ) ) {
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "rocs_system_getWSName failed. rc=%d", GetLastError() );
    return NULL;
  }
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "rocs_system_getWSName OK [%s]", o->WSName );
  return o->WSName;
#else
  return NULL;
#endif
}

const char* rocs_system_getUserName( iOSystemData o ) {
#ifdef __ROCS_SYSTEM__
  unsigned long size = sizeof o->UserName;
  if( !GetUserName( o->UserName, &size ) ) {
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "rocs_system_getUserName failed. rc=%d", GetLastError() );
    return NULL;
  }
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "rocs_system_getUserName OK [%s]", o->UserName );
  return o->UserName;
#else
  return NULL;
#endif
}

const char* rocs_system_getProperty( iOSystemData o, const char* name ) {
#ifdef __ROCS_SYSTEM__
  unsigned long size = GetEnvironmentVariable( name, NULL, 0 );
  char* value = allocIDMem( size, RocsSystemID );
  if( !GetEnvironmentVariable( name, value, size ) ) {
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "rocs_system_getProperty failed. rc=%d", GetLastError() );
    return NULL;
  }
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "rocs_system_getProperty OK [%s=%s]", name, value );
  return value;
#else
  return NULL;
#endif
}

int rocs_system_getMillis( void ) {
#ifdef __ROCS_SYSTEM__
  SYSTEMTIME st;
  GetSystemTime(&st);
  return st.wMilliseconds;
#endif
}

Boolean rocs_system_uBusyWait( int us) {
#ifdef __ROCS_SYSTEM__
	LARGE_INTEGER ticksPerSecond;
	LARGE_INTEGER start_ticks, curr_ticks, end_ticks;

    if (!QueryPerformanceCounter(&start_ticks) ){
		TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "QueryPerformanceTimer not present!" );
		return False;
	}
    if (!QueryPerformanceFrequency(&ticksPerSecond)){
		TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "QueryPerformanceFrequency not present!" );
		return False;
	}
//	TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "TimerFrequency:   %I64Ld ticks/sec",ticksPerSecond );
    end_ticks.QuadPart = start_ticks.QuadPart + (ticksPerSecond.QuadPart * us) / 1000000;
//	TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "End_ticks  :    %I64Ld ticks",end_ticks );
//	TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "Start_ticks:    %I64Ld ticks",start_ticks );

	do {
		if (!QueryPerformanceCounter(&curr_ticks) ){
			TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "QueryPerformanceTimer failed!" );
			return False;
		}

	} while (curr_ticks.QuadPart < end_ticks.QuadPart);
//	TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "Exit_ticks :   %I64Ld ticks",curr_ticks );
	return True;
#endif
}

Boolean rocs_system_usWait( int us) {
  return rocs_system_uBusyWait(us);
}



int rocs_system_getTime( int* hours, int* minutes, int* seconds ) {
#ifdef __ROCS_SYSTEM__
  SYSTEMTIME st;
  GetSystemTime( &st );
  if( hours   != NULL ) *hours = st.wHour;
  if( minutes != NULL ) *minutes = st.wMinute;
  if( seconds != NULL ) *seconds = st.wSecond;
  return st.wMilliseconds;
#endif
}

static char* getDriveLetter( const char* sFile ) {
  if( sFile[1] == ':' )
    return StrOp.fmt( "%c:", sFile[0] );
  else  /* Not a DOS path or just relative. */
    return NULL;
}

#define BUFFER_SIZE 1024*10
char* rocs_system_getURL( const char* szFile )
{
  char*  szDrive = NULL;
  char* szReturn = NULL;
  long     iSize = 0;
  int         rc = 0;

  char szUNC[ BUFFER_SIZE + 1 ];

  iSize = sizeof( szUNC[0] ) * BUFFER_SIZE;

  szDrive = getDriveLetter( szFile );

  if( szDrive == NULL )
    return NULL;

  rc = WNetGetConnection( szDrive, szUNC, &iSize );
  if ( rc == NO_ERROR ) {

    szReturn = StrOp.fmt( "%s%s", szUNC, szFile + StrOp.len( szDrive ) );
    StrOp.free( szDrive );
    return szReturn;
  }
  else {
    StrOp.free( szDrive );
    TraceOp.trc( "wunc", TRCLEVEL_INFO, __LINE__, 9999, "Error calling WNetGetConnection( %s, 0x%08X, 0x%08X ) rc=%d",
                  szDrive, szUNC, &iSize,rc );
    return NULL;
  }
}

Boolean rocs_system_setadmin() {
  /* TODO: set to admin. */
  return True;
}

static Boolean __isNT() {
  int Plattform;
  OSVERSIONINFO VersionInfo;
  MemOp.set( &VersionInfo, 0, sizeof(VersionInfo) );
  VersionInfo.dwOSVersionInfoSize = sizeof(VersionInfo);
  GetVersionEx(&VersionInfo);
  Plattform = VersionInfo.dwPlatformId /* = VER_PLATFORM_WIN32_NT*/;
  if(Plattform == 2)
    return True;
  else return False;
}

Boolean rocs_system_accessPort( int from, int num ) {
  if( !__isNT() ) {
    return True;
  }
  else {
    HANDLE h;
    h = CreateFile("\\\\.\\giveio", GENERIC_READ, 0, NULL,
                   OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if(h == INVALID_HANDLE_VALUE) {
        TraceOp.trc( "wunc", TRCLEVEL_DEBUG, __LINE__, 9999, "no giveio device available\n");
        return False;
    }
    CloseHandle(h);
    return True;
  }
}

Boolean rocs_system_releasePort( int from, int num ) {
  return True;
}

Boolean rocs_system_accessDev( const char* device, Boolean readonly ) {
  return True;
}

void rocs_system_writePort( int port, byte val ) {
#ifndef _WIN64
  _outp(port, val);
#endif
}

byte rocs_system_readPort( int port ) {
#ifndef _WIN64
  return _inp(port);
#endif
}


long rocs_system_openDevice( const char* devname ) {
  HANDLE h;
  h = CreateFile(devname, GENERIC_READ | GENERIC_WRITE, 0, NULL,
                 OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
  if(h == INVALID_HANDLE_VALUE) {
      int rc = GetLastError();
      TraceOp.terrno( name, TRCLEVEL_INFO, __LINE__, 9999, rc,
          "Opening device[%s]  [return code=%d]", devname, rc );
      return 0;
  }
  return (long)h;
}

Boolean rocs_system_writeDevice( long h, char* buffer, int size ) {
  long send = 0;
  int  ok   = 0;
  ok = WriteFile( (HANDLE)h, buffer, size, &send, NULL );

  if( !ok ) {
    int rc = GetLastError();
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999,
        "send %d of %d bytes [rc=%d]", send, size, rc );
  }

  return ok;
}

Boolean rocs_system_readDevice( long h, char* buffer, int size ) {
  long read = 0;
  int  ok   = 0;
  ok = ReadFile( (HANDLE)h, buffer, size, &read, NULL );

  if( !ok ) {
    int rc = GetLastError();
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999,
        "read %d of %d bytes [rc=%d]", read, size, rc );
  }

  return ok;
}


int rocs_system_availDevice( long h ) {
  return GetFileSize( (HANDLE)h, NULL );
}




#endif




