#include "pch.h"
#include "CRotateDialog.h"
#include "framework.h"
#include "afxdialogex.h"
#include <easyx.h>
#include "resource.h"
IMPLEMENT_DYNAMIC(CRotateDialog, CDialogEx)

CRotateDialog::CRotateDialog(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_ROTATE_DIALOG, pParent)
    , m_angle(0.0f)
{
}

CRotateDialog::~CRotateDialog()
{
}

void CRotateDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT_ANGLE, m_angle);
}

BEGIN_MESSAGE_MAP(CRotateDialog, CDialogEx)
    ON_BN_CLICKED(IDOK, &CRotateDialog::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &CRotateDialog::OnBnClickedCancel)
    ON_EN_CHANGE(IDC_EDIT_ANGLE, &CRotateDialog::OnEnChangeEditAngle)
END_MESSAGE_MAP()

void CRotateDialog::OnBnClickedOk()
{
    // TODO: Add your control notification handler code here
    CDialogEx::OnOK();
}

void CRotateDialog::OnBnClickedCancel()
{
    // TODO: Add your control notification handler code here
    CDialogEx::OnCancel();
}

void CRotateDialog::OnEnChangeEditAngle()
{
    // TODO: Add your control notification handler code here
}