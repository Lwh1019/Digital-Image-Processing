// RotateDialog.h
#pragma once
#include "opencv2/opencv.hpp";
class sat : public CDialogEx
{
    DECLARE_DYNAMIC(sat)

public:
    sat(CWnd* pParent = nullptr);   // standard constructor
    virtual ~sat();

    // Dialog Data
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_DIALOG2 };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

    DECLARE_MESSAGE_MAP()

public:
    afx_msg void OnBnClickedOk();
    afx_msg void OnBnClickedCancel();


    float Getsize() const { return m_size; }

private:
    int m_size;
public:
    afx_msg void OnEnChangeEditsize();
};
