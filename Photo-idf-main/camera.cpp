#include "pch.h"
#include "camera.h"
#include "framework.h"
#include "afxdialogex.h"
#include <easyx.h>
#include "resource.h"

IMPLEMENT_DYNAMIC(camera, CDialogEx)

camera::camera(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_DIALOG3, pParent)
    , m_size(0)
{
}
camera::~camera()
{
}

BEGIN_MESSAGE_MAP(camera, CDialogEx)
    ON_BN_CLICKED(IDOK, &camera::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &camera::OnBnClickedCancel)
END_MESSAGE_MAP()

void camera::OnBnClickedOk()
{
    // TODO: Add your control notification handler code here
    CDialogEx::OnOK();
}

void camera::OnBnClickedCancel()
{
    // TODO: Add your control notification handler code here
    CDialogEx::OnCancel();
}