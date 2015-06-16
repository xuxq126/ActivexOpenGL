// MyAX7Ctrl.cpp : CMyAX7Ctrl ActiveX 控件类的实现。
/*Opengl组件开发样例程序1
注意事项：可能造成组件无法显示的原因
//窗口无法显示或窗口闪烁
	Create后必须setfocus激活该窗口，LbuttonDown中最好也要有setfocus
	窗口style是否去除背景画笔，父窗口设置为CLIPCHILDREN，擦除背景return true
OnSize是否设置响应
//窗口只有背景颜色没有物体
	1视角问题是否在视野之外，可能不能看见物体
	2Onsize中缺少以下内容或某句
		glViewport(0, 0, cx, cy);//根据窗口大小
		glMatrixMode(GL_PROJECTION);			// set projection matrix current matrix
		glLoadIdentity();						// reset projection matrix
		gluPerspective(45.0f,(GLfloat)cx/(GLfloat)cy,1.0f,1000.0f);
		glMatrixMode(GL_MODELVIEW);				// set modelview matrix
		glLoadIdentity();
		Invalidate();
//组件在网页无法显示
GUID可能不正确GUID是 CMyCtrl 的类信息id，idl文件中的第三个
网页语句如下
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

// 消息映射

BEGIN_MESSAGE_MAP(CMyAX7Ctrl, COleControl)
	ON_MESSAGE(OCM_COMMAND, &CMyAX7Ctrl::OnOcmCommand)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// 调度映射

BEGIN_DISPATCH_MAP(CMyAX7Ctrl, COleControl)
END_DISPATCH_MAP()

// 事件映射

BEGIN_EVENT_MAP(CMyAX7Ctrl, COleControl)
END_EVENT_MAP()

// 属性页

// TODO: 按需要添加更多属性页。请记住增加计数!
BEGIN_PROPPAGEIDS(CMyAX7Ctrl, 1)
	PROPPAGEID(CMyAX7PropPage::guid)
END_PROPPAGEIDS(CMyAX7Ctrl)

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CMyAX7Ctrl, "MYAX7.MyAX7Ctrl.1",
	0xf832a91, 0xffc8, 0x4cae, 0xa5, 0xca, 0xe, 0x3, 0x85, 0x90, 0xf1, 0xa0)

// 键入库 ID 和版本

IMPLEMENT_OLETYPELIB(CMyAX7Ctrl, _tlid, _wVerMajor, _wVerMinor)

// 接口 ID

const IID IID_DMyAX7 = { 0x621E8B08, 0x8C65, 0x4CE2, { 0x98, 0xE, 0x35, 0xC0, 0xFF, 0x70, 0x34, 0x3B } };
const IID IID_DMyAX7Events = { 0x234D167B, 0x2B62, 0x4D13, { 0xB3, 0x2B, 0xAD, 0xC9, 0x71, 0x48, 0x98, 0xC9 } };

// 控件类型信息

static const DWORD _dwMyAX7OleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CMyAX7Ctrl, IDS_MYAX7, _dwMyAX7OleMisc)

// CMyAX7Ctrl::CMyAX7CtrlFactory::UpdateRegistry -
// 添加或移除 CMyAX7Ctrl 的系统注册表项

BOOL CMyAX7Ctrl::CMyAX7CtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: 验证您的控件是否符合单元模型线程处理规则。
	// 有关更多信息，请参考 MFC 技术说明 64。
	// 如果您的控件不符合单元模型规则，则
	// 必须修改如下代码，将第六个参数从
	// afxRegApartmentThreading 改为 0。

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


// CMyAX7Ctrl::CMyAX7Ctrl - 构造函数

CMyAX7Ctrl::CMyAX7Ctrl()
{
	InitializeIIDs(&IID_DMyAX7, &IID_DMyAX7Events);
	// TODO: 在此初始化控件的实例数据。
}

// CMyAX7Ctrl::~CMyAX7Ctrl - 析构函数

CMyAX7Ctrl::~CMyAX7Ctrl()
{
	wglMakeCurrent(NULL,NULL);
	wglDeleteContext(m_RC);
	// TODO: 在此清理控件的实例数据。
}

// CMyAX7Ctrl::OnDraw - 绘图函数

void CMyAX7Ctrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     
	glLoadIdentity();
	//垂直向下看eyey=centery
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

// CMyAX7Ctrl::DoPropExchange - 持久性支持

void CMyAX7Ctrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: 为每个持久的自定义属性调用 PX_ 函数。
}


// CMyAX7Ctrl::OnResetState - 将控件重置为默认状态

void CMyAX7Ctrl::OnResetState()
{
	COleControl::OnResetState();  // 重置 DoPropExchange 中找到的默认值

	// TODO: 在此重置任意其他控件状态。
}


// CMyAX7Ctrl::PreCreateWindow - 修改 CreateWindowEx 的参数

BOOL CMyAX7Ctrl::PreCreateWindow(CREATESTRUCT& cs)
{
	//cs.lpszClass = _T("STATIC");
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), NULL, NULL);
	return COleControl::PreCreateWindow(cs);
}

// CMyAX7Ctrl::IsSubclassedControl - 这是一个子类控件

BOOL CMyAX7Ctrl::IsSubclassedControl()
{
	return TRUE;
}

// CMyAX7Ctrl::OnOcmCommand - 处理命令消息

LRESULT CMyAX7Ctrl::OnOcmCommand(WPARAM wParam, LPARAM lParam)
{
	WORD wNotifyCode = HIWORD(wParam);

	// TODO: 在此接通 wNotifyCode。

	return 0;
}


// CMyAX7Ctrl 消息处理程序


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
	glViewport(0, 0, 100, 100);//根据窗口大小
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	return TRUE;
	//return COleControl::OnEraseBkgnd(pDC);
}


void CMyAX7Ctrl::OnSize(UINT nType, int cx, int cy)
{
	COleControl::OnSize(nType, cx, cy);
	glViewport(0, 0, cx, cy);//根据窗口大小
	glMatrixMode(GL_PROJECTION);			// set projection matrix current matrix
	glLoadIdentity();						// reset projection matrix
	//
	
	//// calculate perspective
	gluPerspective(45.0f,(GLfloat)cx/(GLfloat)cy,1.0f,1000.0f);

	glMatrixMode(GL_MODELVIEW);				// set modelview matrix
	glLoadIdentity();

	Invalidate();

	// TODO: 在此处添加消息处理程序代码
}


void CMyAX7Ctrl::OnTimer(UINT_PTR nIDEvent)
{

	// TODO: 在此添加消息处理程序代码和/或调用默认值
	// TODO: 在此添加消息处理程序代码和/或调用默认值;;

	Invalidate();
	COleControl::OnTimer(nIDEvent);
}
