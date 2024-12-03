#include "pch.h"
#include "fengge.h"
#include "framework.h"
#include "afxdialogex.h"
#include <easyx.h>
#include "resource.h"

IMPLEMENT_DYNAMIC(fengge, CDialogEx)

fengge::fengge(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_DIALOG4, pParent)
    , m_size(0)
{
}
fengge::~fengge()
{
}

BEGIN_MESSAGE_MAP(fengge, CDialogEx)
    ON_BN_CLICKED(IDOK, &fengge::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &fengge::OnBnClickedCancel)
    ON_BN_CLICKED(IDC_BUTTON1, &fengge::OnBnClickedButton1)
    ON_BN_CLICKED(IDC_BUTTON2, &fengge::OnBnClickedButton2)
    ON_BN_CLICKED(IDC_BUTTON3, &fengge::OnBnClickedButton3)
    ON_BN_CLICKED(IDC_BUTTON4, &fengge::OnBnClickedButton4)
    ON_BN_CLICKED(IDC_BUTTON5, &fengge::OnBnClickedButton5)
    ON_BN_CLICKED(IDC_BUTTON6, &fengge::OnBnClickedButton6)
    ON_BN_CLICKED(IDC_BUTTON7, &fengge::OnBnClickedButton7)
    ON_BN_CLICKED(IDC_BUTTON8, &fengge::OnBnClickedButton8)
    ON_BN_CLICKED(IDC_BUTTON9, &fengge::OnBnClickedButton9)
END_MESSAGE_MAP()

void fengge::OnBnClickedOk()
{
    // TODO: Add your control notification handler code here
    CDialogEx::OnOK();
}

void fengge::OnBnClickedCancel()
{
    // TODO: Add your control notification handler code here
    CDialogEx::OnCancel();
}

void fengge::OnBnClickedButton1()
{
    // TODO: 在此添加控件通知处理程序代码
    m_size=1;
}


void fengge::OnBnClickedButton2()
{
    // TODO: 在此添加控件通知处理程序代码
    m_size = 2;
}


void fengge::OnBnClickedButton3()
{
    // TODO: 在此添加控件通知处理程序代码
    m_size = 3;
}


void fengge::OnBnClickedButton4()
{
    // TODO: 在此添加控件通知处理程序代码
    m_size = 4;
}


void fengge::OnBnClickedButton5()
{
    // TODO: 在此添加控件通知处理程序代码
    m_size = 5;
}


void fengge::OnBnClickedButton6()
{
    // TODO: 在此添加控件通知处理程序代码
    m_size = 6;
}


void fengge::OnBnClickedButton7()
{
    // TODO: 在此添加控件通知处理程序代码
    m_size = 7;
}


void fengge::OnBnClickedButton8()
{
    // TODO: 在此添加控件通知处理程序代码
    m_size = 8;
}


void fengge::OnBnClickedButton9()
{
    // TODO: 在此添加控件通知处理程序代码
    m_size = 9;
}
