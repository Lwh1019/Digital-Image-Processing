#include "pch.h"
#include "framework.h"
#include "afxdialogex.h"
#include <easyx.h>
#include "resource.h"
#include "sat.h"

IMPLEMENT_DYNAMIC(sat, CDialogEx)

sat::sat(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_DIALOG2, pParent)
    , m_size(0.0f)
{
}

sat::~sat()
{
}

void sat::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT1, m_size);
}

BEGIN_MESSAGE_MAP(sat, CDialogEx)
    ON_BN_CLICKED(IDOK, &sat::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &sat::OnBnClickedCancel)
    ON_EN_CHANGE(IDC_EDIT1, &sat::OnEnChangeEditsize)
END_MESSAGE_MAP()

void sat::OnBnClickedOk()
{
    // TODO: Add your control notification handler code here
    CDialogEx::OnOK();
}

void sat::OnBnClickedCancel()
{
    // TODO: Add your control notification handler code here
    CDialogEx::OnCancel();
}

void sat::OnEnChangeEditsize()
{
    // TODO: Add your control notification handler code here
}