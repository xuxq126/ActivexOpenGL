#pragma once

// MyAX7PropPage.h : CMyAX7PropPage ����ҳ���������


// CMyAX7PropPage : �й�ʵ�ֵ���Ϣ������� MyAX7PropPage.cpp��

class CMyAX7PropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CMyAX7PropPage)
	DECLARE_OLECREATE_EX(CMyAX7PropPage)

// ���캯��
public:
	CMyAX7PropPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_MYAX7 };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
};

