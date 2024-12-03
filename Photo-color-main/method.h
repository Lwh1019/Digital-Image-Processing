// RotateDialog.h
#pragma once
#include "opencv2/opencv.hpp";
class method : public CDialogEx
{
    DECLARE_DYNAMIC(method)

public:
    method(CWnd* pParent = nullptr);   // standard constructor
    virtual ~method();

    // Dialog Data
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_DIALOG3 };
#endif

protected:

    DECLARE_MESSAGE_MAP()

public:
    afx_msg void OnBnClickedOk();
    afx_msg void OnBnClickedCancel();


    float Getsize() const { return m_size; }

private:
    int m_size;
public:
    afx_msg void OnEnChangeEditsize();
    afx_msg void OnBnClickedButton1();
    afx_msg void OnBnClickedButton2();
    afx_msg void OnBnClickedButton3();
    afx_msg void OnBnClickedButton4();
    afx_msg void OnBnClickedButton7();
};
