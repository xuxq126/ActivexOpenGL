// MyAX7PropPage.cpp : CMyAX7PropPage 属性页类的实现。

#include "stdafx.h"
#include "MyAX7.h"
#include "MyAX7PropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMyAX7PropPage, COlePropertyPage)

// 消息映射

BEGIN_MESSAGE_MAP(CMyAX7PropPage, COlePropertyPage)
END_MESSAGE_MAP()

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CMyAX7PropPage, "MYAX7.MyAX7PropPage.1",
	0x6990ab2f, 0x84cb, 0x4b8b, 0x8a, 0xe5, 0xbc, 0x41, 0xa3, 0x61, 0x10, 0x3d)

// CMyAX7PropPage::CMyAX7PropPageFactory::UpdateRegistry -
// 添加或移除 CMyAX7PropPage 的系统注册表项

BOOL CMyAX7PropPage::CMyAX7PropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_MYAX7_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CMyAX7PropPage::CMyAX7PropPage - 构造函数

CMyAX7PropPage::CMyAX7PropPage() :
	COlePropertyPage(IDD, IDS_MYAX7_PPG_CAPTION)
{
}

// CMyAX7PropPage::DoDataExchange - 在页和属性间移动数据

void CMyAX7PropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CMyAX7PropPage 消息处理程序
