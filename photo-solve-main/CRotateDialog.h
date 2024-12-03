// RotateDialog.h
#pragma once
#include "opencv2/opencv.hpp";
class CRotateDialog : public CDialogEx
{
    DECLARE_DYNAMIC(CRotateDialog)

public:
    CRotateDialog(CWnd* pParent = nullptr);   // standard constructor
    virtual ~CRotateDialog();

    // Dialog Data
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_ROTATE_DIALOG };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

    DECLARE_MESSAGE_MAP()

public:
    afx_msg void OnBnClickedOk();
    afx_msg void OnBnClickedCancel();

    float GetAngle() const { return m_angle; }

private:
    float m_angle;
public:
    afx_msg void OnEnChangeEditAngle();
};
