
// NTV_03_MessageBoxTimeoutDlg.h: 头文件
//

#pragma once


// CNTV03MessageBoxTimeoutDlg 对话框
class CNTV03MessageBoxTimeoutDlg : public CDialogEx
{
// 构造
public:
	CNTV03MessageBoxTimeoutDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NTV_03_MESSAGEBOXTIMEOUT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	void InitGUI();

	int CreateMessageBox();

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnClose();
	afx_msg void OnBnClickedCreate();
	afx_msg void OnBnClickedExit();
};
