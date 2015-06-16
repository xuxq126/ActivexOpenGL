#pragma once

// MyAX7PropPage.h : CMyAX7PropPage 属性页类的声明。


// CMyAX7PropPage : 有关实现的信息，请参阅 MyAX7PropPage.cpp。

class CMyAX7PropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CMyAX7PropPage)
	DECLARE_OLECREATE_EX(CMyAX7PropPage)

// 构造函数
public:
	CMyAX7PropPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_MYAX7 };

// 实现
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 消息映射
protected:
	DECLARE_MESSAGE_MAP()
};

