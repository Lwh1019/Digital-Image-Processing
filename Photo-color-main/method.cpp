#include "pch.h"
#include "framework.h"
#include "afxdialogex.h"
#include <easyx.h>
#include "resource.h"
#include "method.h"

IMPLEMENT_DYNAMIC(method, CDialogEx)

method::method(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_DIALOG3, pParent)
    , m_size(0)
{
}

method::~method()
{
}

BEGIN_MESSAGE_MAP(method, CDialogEx)
    ON_BN_CLICKED(IDOK, &method::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &method::OnBnClickedCancel)
    ON_BN_CLICKED(IDC_BUTTON1, &method::OnBnClickedButton1)
    ON_BN_CLICKED(IDC_BUTTON2, &method::OnBnClickedButton2)
    ON_BN_CLICKED(IDC_BUTTON3, &method::OnBnClickedButton3)
    ON_BN_CLICKED(IDC_BUTTON4, &method::OnBnClickedButton4)
    ON_BN_CLICKED(IDC_BUTTON7, &method::OnBnClickedButton7)
END_MESSAGE_MAP()

void method::OnBnClickedOk()
{
    // TODO: Add your control notification handler code here
    CDialogEx::OnOK();
}

void method::OnBnClickedCancel()
{
    // TODO: Add your control notification handler code here
    CDialogEx::OnCancel();
}

void method::OnBnClickedButton1()
{
    // TODO: 在此添加控件通知处理程序代码
    m_size = 1;
}


void method::OnBnClickedButton2()
{
    // TODO: 在此添加控件通知处理程序代码
    m_size = 2;
}


void method::OnBnClickedButton3()
{
    // TODO: 在此添加控件通知处理程序代码
    m_size = 3;
}


void method::OnBnClickedButton4()
{
    // TODO: 在此添加控件通知处理程序代码
    m_size = 4;
}

void method::OnBnClickedButton7()
{
    // TODO: 在此添加控件通知处理程序代码
    m_size = 7;
}
