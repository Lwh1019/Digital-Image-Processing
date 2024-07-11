
// PhotoSystemDlg.h: 头文件
//

#pragma once
#include "opencv2/opencv.hpp";

// CPhotoSystemDlg 对话框
class CPhotoSystemDlg : public CDialogEx
{
// 构造
public:
	CPhotoSystemDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PHOTOSYSTEM_DIALOG };
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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnFlychange();
	afx_msg void OnNoise1();
	afx_msg void OnNoise2();
	afx_msg void OnLubo1();
	afx_msg void OnLubo3();
	afx_msg void OnLubo2();
	afx_msg void OnLubo4();
	afx_msg void OnLubo5();
	afx_msg void OnLubo6();
	afx_msg void OnLubo7();
	afx_msg void OnLubo8();
	afx_msg void OnLubo9();
	afx_msg void OnLubo10();
	afx_msg void OnColorchange();
	afx_msg void OnCaijian();
	afx_msg void Onmakechange();
	afx_msg void OnRotate();
	afx_msg void OnBnClickedRadio8();
	afx_msg void OnBnClickedRadio17();
	afx_msg void OnBnClickedRadio9();
	afx_msg void OnBnClickedRadio10();
	afx_msg void OnBnClickedRadio11();
	afx_msg void OnBnClickedRadio12();
	afx_msg void OnSymmetry1();
	afx_msg void OnSymmetry2();
	afx_msg void OnSymmetry3();
	afx_msg void OnJunh();
	afx_msg void OnChazhi1();
	afx_msg void OnChazhi2();
	afx_msg void OnChazhi4();
	afx_msg void OnChazhi3();
	afx_msg void OnChazhi5();
	afx_msg void OnEdsrX2();
	afx_msg void OnMeihua1();
	afx_msg void OnMeihua5();
	afx_msg void OnMeihua2();
	afx_msg void OnMeihua3();
	afx_msg void OnMeihua4();
	afx_msg void OnMeihua6();
	afx_msg void OnEdsrX3();
	afx_msg void OnEdsrX4();
	afx_msg void OnEspcnX2();
	afx_msg void OnEspcnX3();
	afx_msg void OnFsrcnnX2();
	afx_msg void OnEspcnX4();
	afx_msg void OnFsrcnnX3();
	afx_msg void OnFsrcnnX4();
	afx_msg void OnLapsrnX2();
	afx_msg void OnLapsrnX4();
	afx_msg void OnLapsrnX8();
	afx_msg void OnLapulasi();
	afx_msg void OnLog();
	afx_msg void OnGrama();
	afx_msg void Onssim();
	afx_msg void OnPsnr();
	afx_msg void OnBnClickedRadio13();
	afx_msg void OnBnClickedRadio14();
	afx_msg void OnBnClickedRadio15();
	afx_msg void OnBnClickedRadio16();
	afx_msg void OnFmm();
	afx_msg void Onfengge();
	afx_msg void Onfengge2();
	afx_msg void Onfengge3();
	afx_msg void Onfengge4();
	afx_msg void Onfengge5();
	afx_msg void Onfengge6();
	afx_msg void Onfengge7();
	afx_msg void Onfengge8();
	afx_msg void Onfengge9();
};
