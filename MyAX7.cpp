// MyAX7.cpp : CMyAX7App 和 DLL 注册的实现。

#include "stdafx.h"
#include "MyAX7.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CMyAX7App theApp;

const GUID CDECL _tlid = { 0xC61A31F2, 0x1F1F, 0x4442, { 0x89, 0x7F, 0xE0, 0x2C, 0x9F, 0x9A, 0x2D, 0xFE } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CMyAX7App::InitInstance - DLL 初始化

BOOL CMyAX7App::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: 在此添加您自己的模块初始化代码。
	}

	return bInit;
}



// CMyAX7App::ExitInstance - DLL 终止

int CMyAX7App::ExitInstance()
{
	// TODO: 在此添加您自己的模块终止代码。

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - 将项添加到系统注册表

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - 将项从系统注册表中移除

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
