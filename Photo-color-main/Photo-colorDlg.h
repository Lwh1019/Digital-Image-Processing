
// Photo-colorDlg.h: 头文件
//

#pragma once


// CPhotocolorDlg 对话框
class CPhotocolorDlg : public CDialogEx
{
// 构造
public:
	CPhotocolorDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PHOTOCOLOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Oninit();
	afx_msg void Oninit2();
	afx_msg void Onrgbtohsi();
	afx_msg void Oncolortogray();
	afx_msg void Oncolortotwo();
	afx_msg void Oncolortocmyk();
	afx_msg void Oncolortohsv();
	afx_msg void Onrgbtolib();
	afx_msg void Onrgbtoyuv();
	afx_msg void Onrgbtoycbcr();
	afx_msg void Onlightp();
	afx_msg void Oncolorp();
	afx_msg void Onsap();
	afx_msg void Onmidu();
	afx_msg void Ongrayrgb();
	afx_msg void Onhzlvb();
	afx_msg void Onxianxing();
	afx_msg void Onzhishu();
	afx_msg void Onfengdu();
	afx_msg void OnSift();
	afx_msg void Onstitch();
	afx_msg void Onhomo();
	afx_msg void On32822();
	afx_msg void Onmoban();
	afx_msg void Onall();
};
