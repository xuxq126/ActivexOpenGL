// MyAX7PropPage.cpp : CMyAX7PropPage ����ҳ���ʵ�֡�

#include "stdafx.h"
#include "MyAX7.h"
#include "MyAX7PropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMyAX7PropPage, COlePropertyPage)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CMyAX7PropPage, COlePropertyPage)
END_MESSAGE_MAP()

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CMyAX7PropPage, "MYAX7.MyAX7PropPage.1",
	0x6990ab2f, 0x84cb, 0x4b8b, 0x8a, 0xe5, 0xbc, 0x41, 0xa3, 0x61, 0x10, 0x3d)

// CMyAX7PropPage::CMyAX7PropPageFactory::UpdateRegistry -
// ��ӻ��Ƴ� CMyAX7PropPage ��ϵͳע�����

BOOL CMyAX7PropPage::CMyAX7PropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_MYAX7_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CMyAX7PropPage::CMyAX7PropPage - ���캯��

CMyAX7PropPage::CMyAX7PropPage() :
	COlePropertyPage(IDD, IDS_MYAX7_PPG_CAPTION)
{
}

// CMyAX7PropPage::DoDataExchange - ��ҳ�����Լ��ƶ�����

void CMyAX7PropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CMyAX7PropPage ��Ϣ�������
