// MyAX7Ctrl.cpp : CMyAX7Ctrl ActiveX �ؼ����ʵ�֡�
/*Opengl���������������1
ע����������������޷���ʾ��ԭ��
//�����޷���ʾ�򴰿���˸
	Create�����setfocus����ô��ڣ�LbuttonDown�����ҲҪ��setfocus
	����style�Ƿ�ȥ���������ʣ�����������ΪCLIPCHILDREN����������return true
OnSize�Ƿ�������Ӧ
//����ֻ�б�����ɫû������
	1�ӽ������Ƿ�����Ұ֮�⣬���ܲ��ܿ�������
	2Onsize��ȱ���������ݻ�ĳ��
		glViewport(0, 0, cx, cy);//���ݴ��ڴ�С
		glMatrixMode(GL_PROJECTION);			// set projection matrix current matrix
		glLoadIdentity();						// reset projection matrix
		gluPerspective(45.0f,(GLfloat)cx/(GLfloat)cy,1.0f,1000.0f);
		glMatrixMode(GL_MODELVIEW);				// set modelview matrix
		glLoadIdentity();
		Invalidate();
//�������ҳ�޷���ʾ
GUID���ܲ���ȷGUID�� CMyCtrl ������Ϣid��idl�ļ��еĵ�����
��ҳ�������
	<html>
		<head>
			<title>OCX test page </title>
		</head>
		<body>
		<OBJECT ID="MyAX5" border=0 width=300 height=300
		CLASSID = "CLSID:0F832A91-FFC8-4CAE-A5CA-0E038590F1A0">
		</object>
		</body>
		</html>
*/
#include "stdafx.h"
#include "MyAX7.h"
#include "MyAX7Ctrl.h"
#include "MyAX7PropPage.h"
#include "afxdialogex.h"
#include "gl/GL.h"
#include "gl/GLU.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMyAX7Ctrl, COleControl)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CMyAX7Ctrl, COleControl)
	ON_MESSAGE(OCM_COMMAND, &CMyAX7Ctrl::OnOcmCommand)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// ����ӳ��

BEGIN_DISPATCH_MAP(CMyAX7Ctrl, COleControl)
END_DISPATCH_MAP()

// �¼�ӳ��

BEGIN_EVENT_MAP(CMyAX7Ctrl, COleControl)
END_EVENT_MAP()

// ����ҳ

// TODO: ����Ҫ��Ӹ�������ҳ�����ס���Ӽ���!
BEGIN_PROPPAGEIDS(CMyAX7Ctrl, 1)
	PROPPAGEID(CMyAX7PropPage::guid)
END_PROPPAGEIDS(CMyAX7Ctrl)

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CMyAX7Ctrl, "MYAX7.MyAX7Ctrl.1",
	0xf832a91, 0xffc8, 0x4cae, 0xa5, 0xca, 0xe, 0x3, 0x85, 0x90, 0xf1, 0xa0)

// ����� ID �Ͱ汾

IMPLEMENT_OLETYPELIB(CMyAX7Ctrl, _tlid, _wVerMajor, _wVerMinor)

// �ӿ� ID

const IID IID_DMyAX7 = { 0x621E8B08, 0x8C65, 0x4CE2, { 0x98, 0xE, 0x35, 0xC0, 0xFF, 0x70, 0x34, 0x3B } };
const IID IID_DMyAX7Events = { 0x234D167B, 0x2B62, 0x4D13, { 0xB3, 0x2B, 0xAD, 0xC9, 0x71, 0x48, 0x98, 0xC9 } };

// �ؼ�������Ϣ

static const DWORD _dwMyAX7OleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CMyAX7Ctrl, IDS_MYAX7, _dwMyAX7OleMisc)

// CMyAX7Ctrl::CMyAX7CtrlFactory::UpdateRegistry -
// ��ӻ��Ƴ� CMyAX7Ctrl ��ϵͳע�����

BOOL CMyAX7Ctrl::CMyAX7CtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: ��֤���Ŀؼ��Ƿ���ϵ�Ԫģ���̴߳������
	// �йظ�����Ϣ����ο� MFC ����˵�� 64��
	// ������Ŀؼ������ϵ�Ԫģ�͹�����
	// �����޸����´��룬��������������
	// afxRegApartmentThreading ��Ϊ 0��

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_MYAX7,
			IDB_MYAX7,
			afxRegApartmentThreading,
			_dwMyAX7OleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CMyAX7Ctrl::CMyAX7Ctrl - ���캯��

CMyAX7Ctrl::CMyAX7Ctrl()
{
	InitializeIIDs(&IID_DMyAX7, &IID_DMyAX7Events);
	// TODO: �ڴ˳�ʼ���ؼ���ʵ�����ݡ�
}

// CMyAX7Ctrl::~CMyAX7Ctrl - ��������

CMyAX7Ctrl::~CMyAX7Ctrl()
{
	wglMakeCurrent(NULL,NULL);
	wglDeleteContext(m_RC);
	// TODO: �ڴ�����ؼ���ʵ�����ݡ�
}

// CMyAX7Ctrl::OnDraw - ��ͼ����

void CMyAX7Ctrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     
	glLoadIdentity();
	//��ֱ���¿�eyey=centery
	gluLookAt(0.0,0.0, 5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	static float angle=0.0f;
	angle+=1.5f;
	glRotatef(angle,0.0f,1.0f,0.0f);
	
	////glDrawPixels
	glBegin(GL_TRIANGLES);
	glVertex3f(1.0f,-1.0f,0.0f);
	glVertex3f(-1.0f,-1.0f,0.0f);
	glVertex3f(0.0f,1.0f,0.0f);
	glEnd();

	SwapBuffers(pdc->GetSafeHdc());
	DoSuperclassPaint(pdc, rcBounds);
}

// CMyAX7Ctrl::DoPropExchange - �־���֧��

void CMyAX7Ctrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Ϊÿ���־õ��Զ������Ե��� PX_ ������
}


// CMyAX7Ctrl::OnResetState - ���ؼ�����ΪĬ��״̬

void CMyAX7Ctrl::OnResetState()
{
	COleControl::OnResetState();  // ���� DoPropExchange ���ҵ���Ĭ��ֵ

	// TODO: �ڴ��������������ؼ�״̬��
}


// CMyAX7Ctrl::PreCreateWindow - �޸� CreateWindowEx �Ĳ���

BOOL CMyAX7Ctrl::PreCreateWindow(CREATESTRUCT& cs)
{
	//cs.lpszClass = _T("STATIC");
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), NULL, NULL);
	return COleControl::PreCreateWindow(cs);
}

// CMyAX7Ctrl::IsSubclassedControl - ����һ������ؼ�

BOOL CMyAX7Ctrl::IsSubclassedControl()
{
	return TRUE;
}

// CMyAX7Ctrl::OnOcmCommand - ����������Ϣ

LRESULT CMyAX7Ctrl::OnOcmCommand(WPARAM wParam, LPARAM lParam)
{
	WORD wNotifyCode = HIWORD(wParam);

	// TODO: �ڴ˽�ͨ wNotifyCode��

	return 0;
}


// CMyAX7Ctrl ��Ϣ�������


int CMyAX7Ctrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;
	if(GetDC()==NULL)
	{
		MessageBox(_T("GetDC error"));
		return 0;
	}
	//
	SetFocus();
	HDC hDC = GetDC()->GetSafeHdc();
	GLuint PixelFormat;
	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		24,											// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};
	if (!(PixelFormat=ChoosePixelFormat(hDC,&pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		ASSERT(0&&"ChoosePixelFormat");
		return 0;								// Return FALSE
	}

	if(!SetPixelFormat(hDC,PixelFormat,&pfd))
	{
		ASSERT(0&&"SetPixelFormat");
		return 0;
	}

	m_RC = wglCreateContext(hDC);

	if(!wglMakeCurrent(hDC, m_RC))
	{
		ASSERT(0&&"wglMakeCurrent");
		return 0;
	}

	glClearColor(0.0, 0.0, 0.0, 0.0);
	//glEnable(GL_DEPTH_TEST);
	//glEnable(GL_TEXTURE_2D);
	//glDepthFunc(GL_LEQUAL);
	glViewport(0, 0, 100, 100);//���ݴ��ڴ�С
	// select the projection matrix and clear it out
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// select modelview matrix and clear it out
	//glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, 1000.0);
	//glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	SetTimer(1,100,NULL);
		return 0;
}


BOOL CMyAX7Ctrl::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	return TRUE;
	//return COleControl::OnEraseBkgnd(pDC);
}


void CMyAX7Ctrl::OnSize(UINT nType, int cx, int cy)
{
	COleControl::OnSize(nType, cx, cy);
	glViewport(0, 0, cx, cy);//���ݴ��ڴ�С
	glMatrixMode(GL_PROJECTION);			// set projection matrix current matrix
	glLoadIdentity();						// reset projection matrix
	//
	
	//// calculate perspective
	gluPerspective(45.0f,(GLfloat)cx/(GLfloat)cy,1.0f,1000.0f);

	glMatrixMode(GL_MODELVIEW);				// set modelview matrix
	glLoadIdentity();

	Invalidate();

	// TODO: �ڴ˴������Ϣ����������
}


void CMyAX7Ctrl::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ;;
	Invalidate();
	COleControl::OnTimer(nIDEvent);
}
