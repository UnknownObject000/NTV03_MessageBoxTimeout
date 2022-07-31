
// NTV_03_MessageBoxTimeoutDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "NTV_03_MessageBoxTimeout.h"
#include "NTV_03_MessageBoxTimeoutDlg.h"
#include "afxdialogex.h"
#include "MessageBoxTimeout.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define GetControl(Class,ID) ((Class*)(GetDlgItem(ID)))

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CNTV03MessageBoxTimeoutDlg 对话框



CNTV03MessageBoxTimeoutDlg::CNTV03MessageBoxTimeoutDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NTV_03_MESSAGEBOXTIMEOUT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNTV03MessageBoxTimeoutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CNTV03MessageBoxTimeoutDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CNTV03MessageBoxTimeoutDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CNTV03MessageBoxTimeoutDlg::OnBnClickedCancel)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDB_CREATE, &CNTV03MessageBoxTimeoutDlg::OnBnClickedCreate)
	ON_BN_CLICKED(IDB_EXIT, &CNTV03MessageBoxTimeoutDlg::OnBnClickedExit)
END_MESSAGE_MAP()


void CNTV03MessageBoxTimeoutDlg::InitGUI()
{
	GetControl(CComboBox, IDC_ICON_STYLE)->AddString(L"<无>");
	GetControl(CComboBox, IDC_ICON_STYLE)->AddString(L"红色错号(MB_ICONHAND/MB_ICONERROR/MB_ICONSTOP)");
	GetControl(CComboBox, IDC_ICON_STYLE)->AddString(L"黄色三角警告(MB_ICONEXCLAMATION/MB_ICONWARNING)");
	GetControl(CComboBox, IDC_ICON_STYLE)->AddString(L"蓝色圆叹号(MB_ICONASTERISK/MB_ICONINFORMATION)");
	GetControl(CComboBox, IDC_ICON_STYLE)->AddString(L"蓝色圆问号(MB_ICONQUESTION)");
	GetControl(CComboBox, IDC_ICON_STYLE)->SetCurSel(0);
	GetControl(CComboBox, IDC_BUTTON_STYLE)->AddString(L"【确定】(MB_OK)");
	GetControl(CComboBox, IDC_BUTTON_STYLE)->AddString(L"【确定】【取消】(MB_OKCANCEL)");
	GetControl(CComboBox, IDC_BUTTON_STYLE)->AddString(L"【是】【否】(MB_YESNO)");
	GetControl(CComboBox, IDC_BUTTON_STYLE)->AddString(L"【是】【否】【取消】(MB_YESNOCANCEL)");
	GetControl(CComboBox, IDC_BUTTON_STYLE)->AddString(L"【中止】【重试】【忽略】(MB_ABORTRETRYIGNORE)");
	GetControl(CComboBox, IDC_BUTTON_STYLE)->AddString(L"【重试】【取消】(MB_RETRYCANCEL)");
	GetControl(CComboBox, IDC_BUTTON_STYLE)->SetCurSel(0);
	SetDlgItemText(IDE_LAST_STATUS, L"<无数据>");
}

int CNTV03MessageBoxTimeoutDlg::CreateMessageBox()
{
	CString caption, text;
	DWORD messagebox_flag = 0;
	int timeout_value, icon_style, button_style;
	GetDlgItemText(IDE_CAPTION, caption);
	GetDlgItemText(IDE_TEXT, text);
	timeout_value = GetDlgItemInt(IDE_TIMEOUT_VALUE);
	icon_style = GetControl(CComboBox, IDC_ICON_STYLE)->GetCurSel();
	button_style = GetControl(CComboBox, IDC_BUTTON_STYLE)->GetCurSel();
	switch (button_style)
	{
	case 0:
		messagebox_flag = MB_OK;
		break;
	case 1:
		messagebox_flag = MB_OKCANCEL;
		break;
	case 2:
		messagebox_flag = MB_YESNO;
		break;
	case 3:
		messagebox_flag = MB_YESNOCANCEL;
		break;
	case 4:
		messagebox_flag = MB_ABORTRETRYIGNORE;
		break;
	case 5:
		messagebox_flag = MB_RETRYCANCEL;
		break;
	default:
		messagebox_flag = MB_OK;
		break;
	}
	switch (icon_style)
	{
	case 1:
		messagebox_flag |= MB_ICONERROR;
		break;
	case 2:
		messagebox_flag |= MB_ICONWARNING;
		break;
	case 3:
		messagebox_flag |= MB_ICONINFORMATION;
		break;
	case 4:
		messagebox_flag |= MB_ICONQUESTION;
		break;
	}
	//此处应返回MessageBoxTimeout的返回值
	return MessageBoxTimeout(NULL, text.GetString(), caption.GetString(), messagebox_flag, 0, timeout_value);
}

// CNTV03MessageBoxTimeoutDlg 消息处理程序

BOOL CNTV03MessageBoxTimeoutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	InitGUI();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CNTV03MessageBoxTimeoutDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CNTV03MessageBoxTimeoutDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CNTV03MessageBoxTimeoutDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CNTV03MessageBoxTimeoutDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	exit(0);
	CDialogEx::OnClose();
}


void CNTV03MessageBoxTimeoutDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}


void CNTV03MessageBoxTimeoutDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnCancel();
}


void CNTV03MessageBoxTimeoutDlg::OnBnClickedCreate()
{
	// TODO: 在此添加控件通知处理程序代码
	int result = CreateMessageBox();
	CString status_str = L"<无数据>";
	switch (result)
	{
	case IDOK:
		status_str = L"按下了【确定】按钮 (IDOK)";
		break;
	case IDCANCEL:
		status_str = L"按下了【取消】按钮 (IDCANCEL)";
		break;
	case IDABORT:
		status_str = L"按下了【中止】按钮 (IDABORT)";
		break;
	case IDRETRY:
		status_str = L"按下了【重试】按钮 (IDRETRY)";
		break;
	case IDIGNORE:
		status_str = L"按下了【忽略】按钮 (IDIGNORE)";
		break;
	case IDYES:
		status_str = L"按下了【是】按钮 (IDYES)";
		break;
	case IDNO:
		status_str = L"按下了【否】按钮 (IDNO)";
		break;
	case IDTIMEOUT:
		status_str = L"对话框超时退出 (IDTIMEOUT)";
		break;
	}
	SetDlgItemText(IDE_LAST_STATUS, status_str);
}


void CNTV03MessageBoxTimeoutDlg::OnBnClickedExit()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}
