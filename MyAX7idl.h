

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __MyAX7idl_h__
#define __MyAX7idl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DMyAX7_FWD_DEFINED__
#define ___DMyAX7_FWD_DEFINED__
typedef interface _DMyAX7 _DMyAX7;

#endif 	/* ___DMyAX7_FWD_DEFINED__ */


#ifndef ___DMyAX7Events_FWD_DEFINED__
#define ___DMyAX7Events_FWD_DEFINED__
typedef interface _DMyAX7Events _DMyAX7Events;

#endif 	/* ___DMyAX7Events_FWD_DEFINED__ */


#ifndef __MyAX7_FWD_DEFINED__
#define __MyAX7_FWD_DEFINED__

#ifdef __cplusplus
typedef class MyAX7 MyAX7;
#else
typedef struct MyAX7 MyAX7;
#endif /* __cplusplus */

#endif 	/* __MyAX7_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_MyAX7_0000_0000 */
/* [local] */ 

#pragma once
#pragma region Desktop Family
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_MyAX7_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_MyAX7_0000_0000_v0_0_s_ifspec;


#ifndef __MyAX7Lib_LIBRARY_DEFINED__
#define __MyAX7Lib_LIBRARY_DEFINED__

/* library MyAX7Lib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_MyAX7Lib;

#ifndef ___DMyAX7_DISPINTERFACE_DEFINED__
#define ___DMyAX7_DISPINTERFACE_DEFINED__

/* dispinterface _DMyAX7 */
/* [uuid] */ 


EXTERN_C const IID DIID__DMyAX7;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("621E8B08-8C65-4CE2-980E-35C0FF70343B")
    _DMyAX7 : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DMyAX7Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DMyAX7 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DMyAX7 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DMyAX7 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DMyAX7 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DMyAX7 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DMyAX7 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DMyAX7 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DMyAX7Vtbl;

    interface _DMyAX7
    {
        CONST_VTBL struct _DMyAX7Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DMyAX7_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DMyAX7_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DMyAX7_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DMyAX7_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DMyAX7_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DMyAX7_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DMyAX7_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DMyAX7_DISPINTERFACE_DEFINED__ */


#ifndef ___DMyAX7Events_DISPINTERFACE_DEFINED__
#define ___DMyAX7Events_DISPINTERFACE_DEFINED__

/* dispinterface _DMyAX7Events */
/* [uuid] */ 


EXTERN_C const IID DIID__DMyAX7Events;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("234D167B-2B62-4D13-B32B-ADC9714898C9")
    _DMyAX7Events : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DMyAX7EventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DMyAX7Events * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DMyAX7Events * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DMyAX7Events * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DMyAX7Events * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DMyAX7Events * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DMyAX7Events * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DMyAX7Events * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DMyAX7EventsVtbl;

    interface _DMyAX7Events
    {
        CONST_VTBL struct _DMyAX7EventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DMyAX7Events_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DMyAX7Events_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DMyAX7Events_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DMyAX7Events_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DMyAX7Events_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DMyAX7Events_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DMyAX7Events_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DMyAX7Events_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_MyAX7;

#ifdef __cplusplus

class DECLSPEC_UUID("0F832A91-FFC8-4CAE-A5CA-0E038590F1A0")
MyAX7;
#endif
#endif /* __MyAX7Lib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


