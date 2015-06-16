#pragma once

// MyAX7Ctrl.h : CMyAX7Ctrl ActiveX �ؼ����������


// CMyAX7Ctrl : �й�ʵ�ֵ���Ϣ������� MyAX7Ctrl.cpp��

class CMyAX7Ctrl : public COleControl
{
	DECLARE_DYNCREATE(CMyAX7Ctrl)

// ���캯��
public:
	CMyAX7Ctrl();

// ��д
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// ʵ��
protected:
	~CMyAX7Ctrl();

	DECLARE_OLECREATE_EX(CMyAX7Ctrl)    // �๤���� guid
	DECLARE_OLETYPELIB(CMyAX7Ctrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CMyAX7Ctrl)     // ����ҳ ID
	DECLARE_OLECTLTYPE(CMyAX7Ctrl)		// �������ƺ�����״̬

	// ����ؼ�֧��
	BOOL IsSubclassedControl();
	LRESULT OnOcmCommand(WPARAM wParam, LPARAM lParam);

// ��Ϣӳ��
	DECLARE_MESSAGE_MAP()

// ����ӳ��
	DECLARE_DISPATCH_MAP()

// �¼�ӳ��
	DECLARE_EVENT_MAP()

// ���Ⱥ��¼� ID
public:
	enum {
	};
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
private:
	HGLRC m_RC;
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

