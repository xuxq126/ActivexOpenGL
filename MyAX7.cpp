// MyAX7.cpp : CMyAX7App �� DLL ע���ʵ�֡�

#include "stdafx.h"
#include "MyAX7.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CMyAX7App theApp;

const GUID CDECL _tlid = { 0xC61A31F2, 0x1F1F, 0x4442, { 0x89, 0x7F, 0xE0, 0x2C, 0x9F, 0x9A, 0x2D, 0xFE } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CMyAX7App::InitInstance - DLL ��ʼ��

BOOL CMyAX7App::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: �ڴ�������Լ���ģ���ʼ�����롣
	}

	return bInit;
}



// CMyAX7App::ExitInstance - DLL ��ֹ

int CMyAX7App::ExitInstance()
{
	// TODO: �ڴ�������Լ���ģ����ֹ���롣

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - ������ӵ�ϵͳע���

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - �����ϵͳע������Ƴ�

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
