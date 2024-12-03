#include "pch.h"
#include "Fushi.h"
#include "framework.h"
#include "afxdialogex.h"
#include <easyx.h>
#include "resource.h"

IMPLEMENT_DYNAMIC(Fushi, CDialogEx)

Fushi::Fushi(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_DIALOG1, pParent)
    , m_size(0.0f)
{
}

Fushi::~Fushi()
{
}

void Fushi::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT1, m_size);
}

BEGIN_MESSAGE_MAP(Fushi, CDialogEx)
    ON_BN_CLICKED(IDOK, &Fushi::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &Fushi::OnBnClickedCancel)
    ON_EN_CHANGE(IDC_EDIT1, &Fushi::OnEnChangeEditsize)
END_MESSAGE_MAP()

void Fushi::OnBnClickedOk()
{
    // TODO: Add your control notification handler code here
    CDialogEx::OnOK();
}

void Fushi::OnBnClickedCancel()
{
    // TODO: Add your control notification handler code here
    CDialogEx::OnCancel();
}

void Fushi::OnEnChangeEditsize()
{
    // TODO: Add your control notification handler code here
}