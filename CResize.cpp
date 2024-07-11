#include "pch.h"
#include "CResize.h"
#include "framework.h"
#include "afxdialogex.h"
#include <easyx.h>
#include "resource.h"

IMPLEMENT_DYNAMIC(CResize, CDialogEx)

CResize::CResize(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_RESIZE_DIALOG, pParent)
    , m_size(0.0f)
{
}

CResize::~CResize()
{
}

void CResize::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT1, m_size);
}

BEGIN_MESSAGE_MAP(CResize, CDialogEx)
    ON_BN_CLICKED(IDOK, &CResize::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &CResize::OnBnClickedCancel)
    ON_EN_CHANGE(IDC_EDIT1, &CResize::OnEnChangeEditsize)
END_MESSAGE_MAP()

void CResize::OnBnClickedOk()
{
    // TODO: Add your control notification handler code here
    CDialogEx::OnOK();
}

void CResize::OnBnClickedCancel()
{
    // TODO: Add your control notification handler code here
    CDialogEx::OnCancel();
}

void CResize::OnEnChangeEditsize()
{
    // TODO: Add your control notification handler code here
}