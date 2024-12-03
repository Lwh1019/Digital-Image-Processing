#include "pch.h"
#include "framework.h"
#include "afxdialogex.h"
#include <easyx.h>
#include "resource.h"
#include "angle.h"

IMPLEMENT_DYNAMIC(angle, CDialogEx)

angle::angle(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_DIALOG1, pParent)
    , m_size(0.0f)
{
}

angle::~angle()
{
}

void angle::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT1, m_size);
}

BEGIN_MESSAGE_MAP(angle, CDialogEx)
    ON_BN_CLICKED(IDOK, &angle::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &angle::OnBnClickedCancel)
    ON_EN_CHANGE(IDC_EDIT1, &angle::OnEnChangeEditsize)
END_MESSAGE_MAP()

void angle::OnBnClickedOk()
{
    // TODO: Add your control notification handler code here
    CDialogEx::OnOK();
}

void angle::OnBnClickedCancel()
{
    // TODO: Add your control notification handler code here
    CDialogEx::OnCancel();
}

void angle::OnEnChangeEditsize()
{
    // TODO: Add your control notification handler code here
}