

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.00.0595 */
/* at Tue Jun 16 10:20:57 2015
 */
/* Compiler settings for MyAX7.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0595 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_MyAX7Lib,0xC61A31F2,0x1F1F,0x4442,0x89,0x7F,0xE0,0x2C,0x9F,0x9A,0x2D,0xFE);


MIDL_DEFINE_GUID(IID, DIID__DMyAX7,0x621E8B08,0x8C65,0x4CE2,0x98,0x0E,0x35,0xC0,0xFF,0x70,0x34,0x3B);


MIDL_DEFINE_GUID(IID, DIID__DMyAX7Events,0x234D167B,0x2B62,0x4D13,0xB3,0x2B,0xAD,0xC9,0x71,0x48,0x98,0xC9);


MIDL_DEFINE_GUID(CLSID, CLSID_MyAX7,0x0F832A91,0xFFC8,0x4CAE,0xA5,0xCA,0x0E,0x03,0x85,0x90,0xF1,0xA0);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



