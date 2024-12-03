#include "pch.h"
#include "yuzhi.h"
#include "framework.h"
#include "afxdialogex.h"
#include <easyx.h>
#include "resource.h"

IMPLEMENT_DYNAMIC(yuzhi, CDialogEx)

yuzhi::yuzhi(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_DIALOG2, pParent)
    , m_size(0.0f)
{
}
yuzhi::~yuzhi()
{
}

void yuzhi::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT1, m_size);
}

BEGIN_MESSAGE_MAP(yuzhi, CDialogEx)
    ON_BN_CLICKED(IDOK, &yuzhi::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &yuzhi::OnBnClickedCancel)
    ON_EN_CHANGE(IDC_EDIT1, &yuzhi::OnEnChangeEditsize)
END_MESSAGE_MAP()

void yuzhi::OnBnClickedOk()
{
    // TODO: Add your control notification handler code here
    CDialogEx::OnOK();
}

void yuzhi::OnBnClickedCancel()
{
    // TODO: Add your control notification handler code here
    CDialogEx::OnCancel();
}

void yuzhi::OnEnChangeEditsize()
{
    // TODO: Add your control notification handler code here
}