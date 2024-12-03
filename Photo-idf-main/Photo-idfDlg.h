
// Photo-idfDlg.h: 头文件
//

#pragma once


// CPhotoidfDlg 对话框
class CPhotoidfDlg : public CDialogEx
{
// 构造
public:
	CPhotoidfDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PHOTOIDF_DIALOG };
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
	afx_msg void Onimage();
	afx_msg void Oncamera();
	afx_msg void Onfushi();
	afx_msg void Onpengzhang();
	afx_msg void Onbi();
	afx_msg void Onkai();
	afx_msg void Onjizhong();
	afx_msg void Ondingmao();
	afx_msg void Ondimao();
	afx_msg void Ontidu();
	afx_msg void Onliantong();
	afx_msg void Onsift();
	afx_msg void Onsurf();
	afx_msg void Oncensure();
	afx_msg void Onorb();
	afx_msg void Onbrisk();
	afx_msg void Onkaze();
	afx_msg void Onakaze();
	afx_msg void Onharris();
	afx_msg void Onshitomasi();
	afx_msg void Onfast();
	afx_msg void Onquyu1();
	afx_msg void Onquyu2();
	afx_msg void Onquyu3();
	afx_msg void Onroberts();
	afx_msg void Onsobel();
	afx_msg void Onprewitt();
	afx_msg void Onlaplacian();
	afx_msg void Onkirsch();
	afx_msg void OnLog();
	afx_msg void Oncanny();
	afx_msg void Onotsu();
	afx_msg void Onguding();
	afx_msg void Onzsy();
	afx_msg void Ondouble();
	afx_msg void Onkmean();
	afx_msg void Onface();
	afx_msg void Onharr();
	afx_msg void Ondnn();
	afx_msg void Onfenggehua();
	afx_msg void Onmeiyan();
	afx_msg void OnBnClickedButton1();
	afx_msg void Onmopi();
	afx_msg void Onkouhong();
	afx_msg void Onhuanlian();
	afx_msg void Oneye();
	afx_msg void Onbig();
};
