// RotateDialog.h
#pragma once
#include "opencv2/opencv.hpp";
class CResize : public CDialogEx
{
    DECLARE_DYNAMIC(CResize)

public:
    CResize(CWnd* pParent = nullptr);   // standard constructor
    virtual ~CResize();

    // Dialog Data
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_RESIZE_DIALOG };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

    DECLARE_MESSAGE_MAP()

public:
    afx_msg void OnBnClickedOk();
    afx_msg void OnBnClickedCancel();


    float Getsize() const { return m_size; }

private:
    float m_size;
public:
    afx_msg void OnEnChangeEditsize();
};
