// Photo-colorDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Photo-color.h"
#include "Photo-colorDlg.h"
#include "afxdialogex.h"
#include <bits/stdc++.h> //万能头文件 
#include <easyx.h>
#define M_PI 3.14159265358979323846
#include <playsoundapi.h>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/dnn_superres.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/photo.hpp>
#include <opencv2/stitching.hpp>
#include <opencv2/ximgproc.hpp>
#include "angle.h"
#include "sat.h"
#include "method.h"
using namespace dnn_superres;
using namespace cv::xfeatures2d;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPhotocolorDlg 对话框



CPhotocolorDlg::CPhotocolorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PHOTOCOLOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CPhotocolorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPhotocolorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_init, &CPhotocolorDlg::Oninit)
	ON_COMMAND(ID_init2, &CPhotocolorDlg::Oninit2)
	ON_COMMAND(ID_rgbtohsi, &CPhotocolorDlg::Onrgbtohsi)
	ON_COMMAND(ID_colortogray, &CPhotocolorDlg::Oncolortogray)
	ON_COMMAND(ID_colortotwo, &CPhotocolorDlg::Oncolortotwo)
	ON_COMMAND(ID_colortocmyk, &CPhotocolorDlg::Oncolortocmyk)
	ON_COMMAND(ID_colortohsv, &CPhotocolorDlg::Oncolortohsv)
	ON_COMMAND(ID_rgbtolib, &CPhotocolorDlg::Onrgbtolib)
	ON_COMMAND(ID_rgbtoyuv, &CPhotocolorDlg::Onrgbtoyuv)
	ON_COMMAND(ID_rgbtoycbcr, &CPhotocolorDlg::Onrgbtoycbcr)
	ON_COMMAND(ID_lightp, &CPhotocolorDlg::Onlightp)
	ON_COMMAND(ID_colorp, &CPhotocolorDlg::Oncolorp)
	ON_COMMAND(ID_sap, &CPhotocolorDlg::Onsap)
	ON_COMMAND(ID_midu, &CPhotocolorDlg::Onmidu)
	ON_COMMAND(ID_grayrgb, &CPhotocolorDlg::Ongrayrgb)
	ON_COMMAND(ID_hzlvb, &CPhotocolorDlg::Onhzlvb)
	ON_COMMAND(ID_xianxing, &CPhotocolorDlg::Onxianxing)
	ON_COMMAND(ID_zhishu, &CPhotocolorDlg::Onzhishu)
	ON_COMMAND(ID_fengdu, &CPhotocolorDlg::Onfengdu)
	ON_COMMAND(ID_SIFT, &CPhotocolorDlg::OnSift)
	ON_COMMAND(ID_stitch, &CPhotocolorDlg::Onstitch)
	ON_COMMAND(ID_homo, &CPhotocolorDlg::Onhomo)
	ON_COMMAND(ID_moban, &CPhotocolorDlg::Onmoban)
	ON_COMMAND(ID_all, &CPhotocolorDlg::Onall)
END_MESSAGE_MAP()


// CPhotocolorDlg 消息处理程序

BOOL CPhotocolorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CPhotocolorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CPhotocolorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CPhotocolorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
class MyPyrFusionTest {
public:
	MyPyrFusionTest();
	~MyPyrFusionTest();

	Mat Run(vector<Mat> src_arr, vector<Mat> mask_arr);

private:
	vector<Mat> LaplacianPyramid(Mat img, int level);
	vector<Mat> GaussianPyramid(Mat img, int level);
	vector<Mat> EdgeFusion(vector<vector<Mat>> pyr_i_arr, vector<vector<Mat>> pyr_w_arr, int n_scales);
	Mat PyrBuild(vector<Mat> pyr, int n_scales);
};
MyPyrFusionTest::MyPyrFusionTest() {}
MyPyrFusionTest::~MyPyrFusionTest() {}
vector<Mat>  MyPyrFusionTest::GaussianPyramid(Mat img, int level)
{
	vector<Mat> pyr;
	Mat item = img;
	pyr.push_back(item);
	for (int i = 1; i < level; i++)
	{
		resize(item, item, item.size() / 2, 0, 0, cv::INTER_AREA);
		pyr.push_back(item);
	}
	return pyr;
}

vector<Mat> MyPyrFusionTest::LaplacianPyramid(Mat img, int level)
{
	vector<Mat> pyr;
	Mat item = img;
	for (int i = 1; i < level; i++)
	{
		Mat item_down;
		Mat item_up;
		resize(item, item_down, item.size()/ 2, 0, 0, INTER_AREA);
		resize(item_down, item_up, item.size());

		Mat diff(item.size(), CV_16SC1);
		for (int m = 0; m < item.rows; m++) {
			short* ptr_diff = diff.ptr<short>(m);
			uchar* ptr_up = item_up.ptr(m);
			uchar* ptr_item = item.ptr(m);

			for (int n = 0; n < item.cols; n++)
			{
				ptr_diff[n] = (short)ptr_item[n] - (short)ptr_up[n];//求残差
			}
		}
		pyr.push_back(diff);
		item = item_down;
	}
	item.convertTo(item, CV_16SC1);
	pyr.push_back(item);
	return pyr;
}
vector<Mat> MyPyrFusionTest::EdgeFusion(vector<vector<Mat>> pyr_i_arr, vector<vector<Mat>> pyr_w_arr, int n_scales)
{
	vector<Mat> pyr;
	int img_vec_size = pyr_i_arr.size();
	for (int scale = 0; scale < n_scales; scale++)
	{
		Mat cur_i = Mat::zeros(pyr_w_arr[0][scale].size(), CV_16SC1);
		for (int i = 0; i < cur_i.rows; i++)
		{
			for (int j = 0; j < cur_i.cols; j++)
			{
				float value = 0.0, weight = 0.0;
				for (int m = 0; m < img_vec_size; m++)
				{
					weight += pyr_w_arr[m][scale].at<uchar>(i, j);
					value += pyr_i_arr[m][scale].at<short>(i, j) * pyr_w_arr[m][scale].at<uchar>(i, j);//加残差和融合权重的乘
				}
				value = (value + 1) / (weight + 1);//加1是为了防止除0
				cur_i.at<short>(i, j) = value;
			}
		}
		pyr.push_back(cur_i);
		pyr_i_arr[0][scale].convertTo(pyr_i_arr[0][scale], CV_8UC1);
	}
	return pyr;
}

Mat MyPyrFusionTest::PyrBuild(vector<Mat> pyr, int n_scales)
{
	Mat out = pyr[n_scales - 1].clone();
	for (int i = n_scales - 2; i >= 0; i--)
	{
		resize(out, out, pyr[i].size());//上采样
		for (int m = 0; m < out.rows; m++)
		{
			short* ptr_out = out.ptr<short>(m);
			short* ptr_i = pyr[i].ptr<short>(m);
			for (int n = 0; n < out.cols; n++)
			{
				ptr_out[n] = ptr_out[n] + ptr_i[n];
			}
		}
	}
	out.convertTo(out, CV_8UC1);
	return out;
}

Mat MyPyrFusionTest::Run(vector<Mat> src_arr, vector<Mat> mask_arr)
{
	int h = src_arr[0].rows;
	int w = src_arr[0].cols;
	int n_sc_ref = int(log(min(h, w)) / log(2));
	int n_scales = 1;
	while (n_scales < n_sc_ref)
	{
		n_scales++;
	}
	int img_vec_size = (int)src_arr.size();
	vector<vector<Mat>> pyr_i_arr, pyr_w_arr;
	for (int i = 0; i < img_vec_size; i++)
	{
		vector<Mat> pyr_m1 = GaussianPyramid(mask_arr[i], n_scales);
		vector<Mat> pyr_s1 = LaplacianPyramid(src_arr[i], n_scales);
		pyr_w_arr.push_back(pyr_m1);
		pyr_i_arr.push_back(pyr_s1);
	}
	vector<Mat> pyr = EdgeFusion(pyr_i_arr, pyr_w_arr, n_scales);
	Mat out = PyrBuild(pyr, n_scales);
	return out;
}
Mat srcImg, result;
void CPhotocolorDlg::Oninit() //导入彩色图像
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
		TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);
	CString m_path;
	if (dlg.DoModal() == IDOK)
	{
		m_path = dlg.GetPathName();
	}
	else
		return;
	srcImg = imread((LPCTSTR)m_path, 1);
	imshow("原图", srcImg);
}
void CPhotocolorDlg::Oninit2() //导入灰度图像
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
		TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);
	CString m_path;
	if (dlg.DoModal() == IDOK)
	{
		m_path = dlg.GetPathName();
	}
	else
		return;
	srcImg = imread((LPCTSTR)m_path, 0);
	imshow("原图", srcImg);
}


void CPhotocolorDlg::Onrgbtohsi()   //RGB转HSI
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	Mat result(srcImg.size(), srcImg.type());
	for (int i = 0; i < srcImg.rows; i++)
	{
		for (int j = 0; j < srcImg.cols; j++)
		{
			Vec3b rgb = srcImg.at<Vec3b>(i, j);
			float r = rgb[2] / 255.0;
			float g = rgb[1] / 255.0;
			float b = rgb[0] / 255.0;
			float intensity = (r + g + b) / 3.0;
			float minVal = min(r, min(g, b));
			float saturation = 1 - 3 * minVal / (r + g + b + 1e-6);
			float hue = 0;
			if (saturation != 0)
			{
				hue = acos((0.5 * ((r - g) + (r - b))) / sqrt((r - g) * (r - g) + (r - b) * (g - b) + 1e-6));
				if (b > g) {
					hue = 2 * CV_PI - hue;
				}
			}
			result.at<Vec3b>(i, j)[0] = hue * 180 / CV_PI; 
			result.at<Vec3b>(i, j)[1] = saturation * 255;
			result.at<Vec3b>(i, j)[2] = intensity * 255;
		}
	}
	imshow("RGB转HSI", result);
	char key = waitKey(0);
	if (key == 's' || key == 'S')
	{
		UINT i;
		i = MessageBox(_T("是否要保存图像?!"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			CFileDialog saveDlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT,
				TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);

			if (saveDlg.DoModal() == IDOK)
			{
				CString savePath = saveDlg.GetPathName();
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
	waitKey(0);
}

void CPhotocolorDlg::Oncolortogray()  //彩色转灰度
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	cvtColor(srcImg, result, COLOR_BGR2GRAY);
	imshow("彩色转灰度", result);
	char key = waitKey(0);
	if (key == 's' || key == 'S')
	{
		UINT i;
		i = MessageBox(_T("是否要保存图像?!"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			CFileDialog saveDlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT,
				TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);

			if (saveDlg.DoModal() == IDOK)
			{
				CString savePath = saveDlg.GetPathName();
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
	waitKey(0);
}

void CPhotocolorDlg::Oncolortotwo()  //彩色转二值图
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	Mat gray;
	cvtColor(srcImg, gray, COLOR_BGR2GRAY);
	threshold(gray, result, 128, 255, THRESH_BINARY);
	imshow("彩色转二值图", result);
	char key = waitKey(0);
	if (key == 's' || key == 'S')
	{
		UINT i;
		i = MessageBox(_T("是否要保存图像?!"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			CFileDialog saveDlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT,
				TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);

			if (saveDlg.DoModal() == IDOK)
			{
				CString savePath = saveDlg.GetPathName();
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
	waitKey(0);
}

void CPhotocolorDlg::Oncolortocmyk() //RGB转CMYK
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	Mat result(srcImg.size(), CV_8UC4);
	for (int i = 0; i < srcImg.rows; i++)
	{
		for (int j = 0; j < srcImg.cols; j++)
		{
			Vec3b rgb = srcImg.at<Vec3b>(i, j);
			float r = rgb[2] / 255.0;
			float g = rgb[1] / 255.0;
			float b = rgb[0] / 255.0;
			float k = 1 - max({ r, g, b });
			float c = (1 - r - k) / (1 - k + 1e-6);
			float m = (1 - g - k) / (1 - k + 1e-6);
			float y = (1 - b - k) / (1 - k + 1e-6);
			result.at<Vec4b>(i, j)[0] = static_cast<uchar>(c * 255);
			result.at<Vec4b>(i, j)[1] = static_cast<uchar>(m * 255);
			result.at<Vec4b>(i, j)[2] = static_cast<uchar>(y * 255);
			result.at<Vec4b>(i, j)[3] = static_cast<uchar>(k * 255);
		}
	}
	imshow("RGB转CMYK", result);
	char key = waitKey(0);
	if (key == 's' || key == 'S')
	{
		UINT i;
		i = MessageBox(_T("是否要保存图像?!"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			CFileDialog saveDlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT,
				TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);

			if (saveDlg.DoModal() == IDOK)
			{
				CString savePath = saveDlg.GetPathName();
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
	waitKey(0);
}
void CPhotocolorDlg::Oncolortohsv()  //RGB转HSV
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	cvtColor(srcImg, result, COLOR_BGR2HSV);
	imshow("RGB转HSV", result);
	char key = waitKey(0);
	if (key == 's' || key == 'S')
	{
		UINT i;
		i = MessageBox(_T("是否要保存图像?!"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			CFileDialog saveDlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT,
				TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);

			if (saveDlg.DoModal() == IDOK)
			{
				CString savePath = saveDlg.GetPathName();
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
	waitKey(0);
}
void CPhotocolorDlg::Onrgbtolib()  //RGB转Lib
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	cvtColor(srcImg, result, COLOR_BGR2Lab);
	imshow("RGB转Lab", result);
	char key = waitKey(0);
	if (key == 's' || key == 'S')
	{
		UINT i;
		i = MessageBox(_T("是否要保存图像?!"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			CFileDialog saveDlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT,
				TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);

			if (saveDlg.DoModal() == IDOK)
			{
				CString savePath = saveDlg.GetPathName();
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
	waitKey(0);
}
void CPhotocolorDlg::Onrgbtoyuv()  //RGB转YUV
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	cvtColor(srcImg, result, COLOR_BGR2YUV);
	imshow("RGB转YUV", result);
	char key = waitKey(0);
	if (key == 's' || key == 'S')
	{
		UINT i;
		i = MessageBox(_T("是否要保存图像?!"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			CFileDialog saveDlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT,
				TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);

			if (saveDlg.DoModal() == IDOK)
			{
				CString savePath = saveDlg.GetPathName();
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
	waitKey(0);
}
void CPhotocolorDlg::Onrgbtoycbcr() //RGB转YCrCb
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	cvtColor(srcImg, result, COLOR_BGR2YCrCb);
	imshow("RGB转YCrCb", result);
	char key = waitKey(0);
	if (key == 's' || key == 'S')
	{
		UINT i;
		i = MessageBox(_T("是否要保存图像?!"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			CFileDialog saveDlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT,
				TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);

			if (saveDlg.DoModal() == IDOK)
			{
				CString savePath = saveDlg.GetPathName();
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
	waitKey(0);
}
void CPhotocolorDlg::Onlightp()  //亮度增强
{
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	// 将RGB图像转换为HSI图像
	Mat hsiImg(srcImg.size(), srcImg.type());
	for (int i = 0; i < srcImg.rows; ++i)
	{
		for (int j = 0; j < srcImg.cols; ++j)
		{
			Vec3b rgb = srcImg.at<Vec3b>(i, j);
			float r = rgb[2] / 255.0;
			float g = rgb[1] / 255.0;
			float b = rgb[0] / 255.0;
			float intensity = (r + g + b) / 3.0;
			float minVal = min(r, min(g, b));
			float saturation = (r + g + b == 0) ? 0 : 1 - 3 * minVal / (r + g + b + 1e-6);
			float hue = 0;
			if (saturation != 0)
			{
				hue = acos((0.5 * ((r - g) + (r - b))) / sqrt((r - g) * (r - g) + (r - b) * (g - b) + 1e-6));
				if (b > g) {
					hue = 2 * CV_PI - hue;
				}
			}
			hsiImg.at<Vec3b>(i, j)[0] = hue * 255 / (2 * CV_PI);
			hsiImg.at<Vec3b>(i, j)[1] = saturation * 255;
			hsiImg.at<Vec3b>(i, j)[2] = intensity * 255;
		}
	}
	std::vector<Mat> channels;
	split(hsiImg, channels);
	equalizeHist(channels[2], channels[2]); // 对HSI图像的亮度（I通道）进行直方图均衡化
	merge(channels, hsiImg);
	imshow("亮度增强--HSI图", hsiImg);

	Mat resultImg(srcImg.size(), srcImg.type()); 
	for (int i = 0; i < hsiImg.rows; ++i)	// 将增强后的HSI图像转换回RGB
	{
		for (int j = 0; j < hsiImg.cols; ++j)
		{
			Vec3b hsi_pixel = hsiImg.at<Vec3b>(i, j);
			float h = hsi_pixel[0] / 255.0 * 2 * CV_PI;
			float s = hsi_pixel[1] / 255.0;
			float I = hsi_pixel[2] / 255.0;
			float r, g, b;

			if (h < 2 * CV_PI / 3)
			{
				b = I * (1 - s);
				r = I * (1 + s * cos(h) / cos(CV_PI / 3 - h));
				g = 3 * I - (r + b);
			}
			else if (h < 4 * CV_PI / 3)
			{
				h -= 2 * CV_PI / 3;
				r = I * (1 - s);
				g = I * (1 + s * cos(h) / cos(CV_PI / 3 - h));
				b = 3 * I - (r + g);
			}
			else
			{
				h -= 4 * CV_PI / 3;
				g = I * (1 - s);
				b = I * (1 + s * cos(h) / cos(CV_PI / 3 - h));
				r = 3 * I - (g + b);
			}
			resultImg.at<Vec3b>(i, j) = Vec3b(static_cast<uchar>(b * 255), static_cast<uchar>(g * 255), static_cast<uchar>(r * 255));
		}
	}
	imshow("亮度增强--RGB图", resultImg);
	char key = waitKey(0);
	if (key == 's' || key == 'S')
	{
		UINT i;
		i = MessageBox(_T("是否要保存图像?!"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			CFileDialog saveDlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT,
				TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);

			if (saveDlg.DoModal() == IDOK)
			{
				CString savePath = saveDlg.GetPathName();
				imwrite((LPCTSTR)savePath, resultImg);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
	waitKey(0);
}
void adjustHueHSI(Mat& hsi, int angle)
{
	for (int i = 0; i < hsi.rows; ++i)
	{
		for (int j = 0; j < hsi.cols; ++j)
		{
			float hue = hsi.at<Vec3b>(i, j)[0] * 2.0 * CV_PI / 255.0; // 转换为角度
			hue += angle * CV_PI / 180.0; // 加上角度偏移
			if (hue < 0) hue += 2.0 * CV_PI;
			if (hue >= 2.0 * CV_PI) hue -= 2.0 * CV_PI;
			hsi.at<Vec3b>(i, j)[0] = hue * 255.0 / (2.0 * CV_PI); // 转换回0-255范围
		}
	}
}

void CPhotocolorDlg::Oncolorp()  //色调增强
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	Mat result(srcImg.size(), srcImg.type());
	for (int i = 0; i < srcImg.rows; i++)
	{
		for (int j = 0; j < srcImg.cols; j++)
		{
			Vec3b rgb = srcImg.at<Vec3b>(i, j);
			float r = rgb[2] / 255.0;
			float g = rgb[1] / 255.0;
			float b = rgb[0] / 255.0;
			float intensity = (r + g + b) / 3.0;
			float minVal = min(r, min(g, b));
			float saturation = 1 - 3 * minVal / (r + g + b + 1e-6);
			float hue = 0;
			if (saturation != 0)
			{
				hue = acos((0.5 * ((r - g) + (r - b))) / sqrt((r - g) * (r - g) + (r - b) * (g - b) + 1e-6));
				if (b > g) {
					hue = 2 * CV_PI - hue;
				}
			}
			result.at<Vec3b>(i, j)[0] = hue * 255 / (2 * CV_PI);
			result.at<Vec3b>(i, j)[1] = saturation * 255;
			result.at<Vec3b>(i, j)[2] = intensity * 255;
		}
	}
	float ang;
	angle Dlg;
	if (Dlg.DoModal() == IDOK)
	{
		ang = Dlg.Getsize();
	}
	adjustHueHSI(result, ang);
	imshow("色调增强--HSI图", result);
	Mat image(result.size(), result.type());
	for (int i = 0; i < result.rows; ++i) {
		for (int j = 0; j < result.cols; ++j)
		{
			Vec3b hsi_pixel = result.at<Vec3b>(i, j);
			float h = hsi_pixel[0] / 255.0 * 2 * CV_PI;
			float s = hsi_pixel[1] / 255.0;
			float I = hsi_pixel[2] / 255.0;
			float r, g, b;
			if (h < 2 * CV_PI / 3)
			{
				b = I * (1 - s);
				r = I * (1 + s * cos(h) / cos(CV_PI / 3 - h));
				g = 3 * I - (r + b);
			}
			else if (h < 4 * CV_PI / 3)
			{
				h = h - 2 * CV_PI / 3;
				r = I * (1 - s);
				g = I * (1 + s * cos(h) / cos(CV_PI / 3 - h));
				b = 3 * I - (r + g);
			}
			else
			{
				h = h - 4 * CV_PI / 3;
				g = I * (1 - s);
				b = I * (1 + s * cos(h) / cos(CV_PI / 3 - h));
				r = 3 * I - (g + b);
			}
			image.at<Vec3b>(i, j) = Vec3b((b * 255), (g * 255), (r * 255));
		}
	}
	imshow("色调增强--RGB图", image);
	char key = waitKey(0);
	if (key == 's' || key == 'S')
	{
		UINT i;
		i = MessageBox(_T("是否要保存图像?!"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			CFileDialog saveDlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT,
				TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);

			if (saveDlg.DoModal() == IDOK)
			{
				CString savePath = saveDlg.GetPathName();
				imwrite((LPCTSTR)savePath, image);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
	waitKey(0);
}
void enhanceSaturation(Mat& hsi, float factor)
{
	for (int i = 0; i < hsi.rows; ++i)
	{
		for (int j = 0; j < hsi.cols; ++j)
		{
			float saturation = hsi.at<Vec3b>(i, j)[1] / 255.0;
			saturation *= factor;
			if (saturation > 1) saturation = 1;
			hsi.at<Vec3b>(i, j)[1] = saturation * 255;
		}
	}
}
void CPhotocolorDlg::Onsap() // 对比度增强
{
	// 检查源图像是否为空
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}

	Mat hsiImg(srcImg.size(), srcImg.type()); 	// 创建HSI图像
	for (int i = 0; i < srcImg.rows; ++i)
	{
		for (int j = 0; j < srcImg.cols; ++j)
		{
			Vec3b rgb = srcImg.at<Vec3b>(i, j);
			float r = rgb[2] / 255.0;
			float g = rgb[1] / 255.0;
			float b = rgb[0] / 255.0;
			float intensity = (r + g + b) / 3.0;
			float minVal = min(r, min(g, b));
			float saturation = (r + g + b == 0) ? 0 : 1 - 3 * minVal / (r + g + b);
			float hue = 0;
			if (saturation != 0)
			{
				hue = acos((0.5 * ((r - g) + (r - b))) / sqrt((r - g) * (r - g) + (r - b) * (g - b) + 1e-6));
				if (b > g) {
					hue = 2 * CV_PI - hue;
				}
			}
			hsiImg.at<Vec3b>(i, j)[0] = hue * 255 / (2 * CV_PI);
			hsiImg.at<Vec3b>(i, j)[1] = saturation * 255;
			hsiImg.at<Vec3b>(i, j)[2] = intensity * 255;
		}
	}
	float scale;
	sat Dlg;
	if (Dlg.DoModal() == IDOK)
	{
		scale = Dlg.Getsize(); 	// 获取饱和度增强因子
	}
	enhanceSaturation(hsiImg, scale);  	// 增强饱和度
	imshow("对比度增强--HSI图", hsiImg);

	Mat resultImg(srcImg.size(), srcImg.type());
	for (int i = 0; i < hsiImg.rows; ++i)	// 将增强后的HSI图像转换回RGB
	{
		for (int j = 0; j < hsiImg.cols; ++j)
		{
			Vec3b hsi_pixel = hsiImg.at<Vec3b>(i, j);
			float h = hsi_pixel[0] / 255.0 * 2 * CV_PI;
			float s = hsi_pixel[1] / 255.0;
			float I = hsi_pixel[2] / 255.0;

			float r, g, b;
			if (h < 2 * CV_PI / 3)
			{
				b = I * (1 - s);
				r = I * (1 + s * cos(h) / cos(CV_PI / 3 - h));
				g = 3 * I - (r + b);
			}
			else if (h < 4 * CV_PI / 3)
			{
				h = h - 2 * CV_PI / 3;
				r = I * (1 - s);
				g = I * (1 + s * cos(h) / cos(CV_PI / 3 - h));
				b = 3 * I - (r + g);
			}
			else
			{
				h = h - 4 * CV_PI / 3;
				g = I * (1 - s);
				b = I * (1 + s * cos(h) / cos(CV_PI / 3 - h));
				r = 3 * I - (g + b);
			}
			resultImg.at<Vec3b>(i, j) = Vec3b(static_cast<uchar>(b * 255), static_cast<uchar>(g * 255), static_cast<uchar>(r * 255));
		}
	}
	imshow("对比度增强--RGB图", resultImg);
	char key = waitKey(0);
	if (key == 's' || key == 'S')
	{
		UINT i;
		i = MessageBox(_T("是否要保存图像?!"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			CFileDialog saveDlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT,
				TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);

			if (saveDlg.DoModal() == IDOK)
			{
				CString savePath = saveDlg.GetPathName();
				imwrite((LPCTSTR)savePath, resultImg);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
	waitKey(0);
}
void densitySlicing(const Mat& src, Mat& dst, int numSlices)
{
	// 分层
	CV_Assert(numSlices > 1);
	dst.create(src.size(), CV_8UC3);
	int step = 256 / numSlices;
	std::vector<Vec3b> colors;

	// 创建伪彩色映射表
	for (int i = 0; i < numSlices; ++i)
	{
		int r = (i * 255 / numSlices);
		int g = 255 - (i * 255 / numSlices);
		int b = (i * 128 / numSlices);
		colors.push_back(Vec3b(b, g, r));
	}
	// 应用伪彩色
	for (int i = 0; i < src.rows; ++i)
	{
		for (int j = 0; j < src.cols; ++j)
		{
			uchar pixel = src.at<uchar>(i, j);
			int index = pixel / step;
			if (index >= numSlices)
			{
				index = numSlices - 1;
			}
			dst.at<Vec3b>(i, j) = colors[index];
		}
	}
}
void CPhotocolorDlg::Onmidu()  //密度分层法
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	Mat result;
	densitySlicing(srcImg, result,16);
	imshow("密度分层法", result);
	char key = waitKey(0);
	if (key == 's' || key == 'S')
	{
		UINT i;
		i = MessageBox(_T("是否要保存图像?!"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			CFileDialog saveDlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT,
				TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);

			if (saveDlg.DoModal() == IDOK)
			{
				CString savePath = saveDlg.GetPathName();
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
	waitKey(0);
}
void grayscaleToColor(const Mat& src, Mat& dst)
{
	dst.create(src.size(), CV_8UC3);
	int L = 256;

	for (int i = 0; i < src.rows; ++i)
	{
		for (int j = 0; j < src.cols; ++j)
		{
			uchar pixel = src.at<uchar>(i, j);
			Vec3b color;
			if (pixel <= L / 4)
			{
				color[0] = L;
				color[1] = 4 * pixel;
				color[2] = 0;
			}
			else if (pixel <= L / 2)
			{
				color[0] = -4 * pixel + 2 * L;
				color[1] = L;
				color[2] = 0;
			}
			else if (pixel <= 3 * L / 4)
			{
				color[0] = 0;
				color[1] = L;
				color[2] = 4 * pixel - 2 * L;
			}
			else
			{
				color[0] = 0;
				color[1] = -4 * pixel + 4 * L;
				color[2] = 4 * pixel - 2 * L;
			}
			dst.at<Vec3b>(i, j) = color;
		}
	}
}
void CPhotocolorDlg::Ongrayrgb()  //灰度级-彩色变换
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty()) {
		cerr << "ERROR" << '\n';
		return;
	}
	Mat result;
	grayscaleToColor(srcImg, result);
	imshow("灰度级-彩色变换", result);
	char key = waitKey(0);
	if (key == 's' || key == 'S')
	{
		UINT i;
		i = MessageBox(_T("是否要保存图像?!"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			CFileDialog saveDlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT,
				TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);

			if (saveDlg.DoModal() == IDOK)
			{
				CString savePath = saveDlg.GetPathName();
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
	waitKey(0);
}
void createLowPassFilter(Mat& filter, int cutoff)   //巴特沃斯低通滤波器
{
	int rows = filter.rows;
	int cols = filter.cols;
	Point center = Point(rows / 2, cols / 2);
	double radius;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			radius = sqrt(pow(i - center.y, 2) + pow(j - center.x, 2));
			filter.at<float>(i, j) = 1 / (1 + (sqrt(2) - 1) * pow(radius / cutoff, 2));
		}
	}
}
void createHighPassFilter(Mat& filter, int cutoff) //巴特沃斯高通滤波
{
	int rows = filter.rows;
	int cols = filter.cols;
	Point center = Point(rows / 2, cols / 2);
	double radius;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			radius = sqrt(pow(i - center.y, 2) + pow(j - center.x, 2));
			filter.at<float>(i, j) = 1 / (1 + (sqrt(2) - 1) * pow(cutoff / radius, 2));
		}
	}
}
void createBandPassFilter(Mat& filter, int center, int width, int u0, int v0)  //带通滤波器
{
	int rows = filter.rows;
	int cols = filter.cols;
	double radius;
	Point centerOffset = Point(u0, v0);

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			radius = sqrt(pow(i - centerOffset.y, 2) + pow(j - centerOffset.x, 2));
			filter.at<float>(i, j) = 1 - 1 / (1 + pow((radius * width) / (pow(radius, 2) - pow(center, 2)), 2));
		}
	}
}
void applyFrequencyFilter(const Mat& src, Mat& dst, const Mat& filter)
{
	Mat planes[] = { Mat_<float>(src), Mat::zeros(src.size(), CV_32F) };
	Mat complexI;
	merge(planes, 2, complexI);

	dft(complexI, complexI); 	// 进行DFT

	Mat planesH[] = { Mat_<float>(filter), Mat::zeros(filter.size(), CV_32F) };  	// 应用频率滤波器
	Mat complexH;
	merge(planesH, 2, complexH);
	mulSpectrums(complexI, complexH, complexI, 0);

	idft(complexI, complexI, DFT_SCALE | DFT_REAL_OUTPUT); 	// 进行逆DFT

	dst = complexI;
}
void frequencyFiltering(const Mat& src, Mat& dst)
{
	Mat gray;
	if (src.channels() == 3)
		cvtColor(src, gray, COLOR_BGR2GRAY);
	else
		gray = src.clone();

	Mat redFilter = Mat::zeros(gray.size(), CV_32F);
	Mat greenFilter = Mat::zeros(gray.size(), CV_32F);
	Mat blueFilter = Mat::zeros(gray.size(), CV_32F);

	createLowPassFilter(redFilter, 100);  	// 创建滤波器
	createHighPassFilter(greenFilter, 200);
	createBandPassFilter(blueFilter, 150, 100, 10, 10);

	Mat redChannel, greenChannel, blueChannel;

	applyFrequencyFilter(gray, redChannel, redFilter); 	// 应用滤波器
	applyFrequencyFilter(gray, greenChannel, greenFilter);
	applyFrequencyFilter(gray, blueChannel, blueFilter);

	normalize(redChannel, redChannel, 0, 1, NORM_MINMAX);  	// 将结果归一化
	normalize(greenChannel, greenChannel, 0, 1, NORM_MINMAX);
	normalize(blueChannel, blueChannel, 0, 1, NORM_MINMAX);

	redChannel.convertTo(redChannel, CV_8U, 255.0); 	// 增强对比度
	greenChannel.convertTo(greenChannel, CV_8U, 255.0);
	blueChannel.convertTo(blueChannel, CV_8U, 255.0);
	equalizeHist(redChannel, redChannel);  //直方图均衡化
	equalizeHist(greenChannel, greenChannel);
	equalizeHist(blueChannel, blueChannel);
	redChannel.convertTo(redChannel, CV_32F, 1.0 / 255.0);
	greenChannel.convertTo(greenChannel, CV_32F, 1.0 / 255.0);
	blueChannel.convertTo(blueChannel, CV_32F, 1.0 / 255.0);

	std::vector<Mat> channels = { blueChannel, greenChannel, redChannel };
	merge(channels, dst); 	// 合并通道
}
void CPhotocolorDlg::Onhzlvb()  //频率滤波法
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty()) {
		cerr << "ERROR" << '\n';
		return;
	}
	Mat result;
	frequencyFiltering(srcImg, result);
	imshow("频率滤波法", result);
	char key = waitKey(0);
	if (key == 's' || key == 'S')
	{
		UINT i;
		i = MessageBox(_T("是否要保存图像?!"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			CFileDialog saveDlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT,
				TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);

			if (saveDlg.DoModal() == IDOK)
			{
				CString savePath = saveDlg.GetPathName();
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
	waitKey(0);
}
void CPhotocolorDlg::Onxianxing()
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR: Image is empty" << '\n';
		return;
	}
	Mat result = srcImg.clone();

	for (int y = 0; y < srcImg.rows; y++)
	{
		for (int x = 0; x < srcImg.cols; x++)
		{
			Vec3b& color = result.at<Vec3b>(Point(x, y));
			color[2] = saturate_cast<uchar>(color[2] * 1.5); // 增强红色通道
		}
	}

	imshow("增强红色通道", result);
	char key = waitKey(0);
	if (key == 's' || key == 'S')
	{
		UINT i;
		i = MessageBox(_T("是否要保存图像?!"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			CFileDialog saveDlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT,
				TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);

			if (saveDlg.DoModal() == IDOK)
			{
				CString savePath = saveDlg.GetPathName();
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
	waitKey(0);
}

void CPhotocolorDlg::Onzhishu()
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR: Image is empty" << '\n';
		return;
	}
	Mat result = srcImg.clone();

	for (int y = 0; y < srcImg.rows; y++)
	{
		for (int x = 0; x < srcImg.cols; x++)
		{
			Vec3b& color = result.at<Vec3b>(Point(x, y));
			color[1] = saturate_cast<uchar>(color[1] * 1.5); // 增强绿色通道
		}
	}

	imshow("增强绿色通道", result);
	char key = waitKey(0);
	if (key == 's' || key == 'S')
	{
		UINT i;
		i = MessageBox(_T("是否要保存图像?!"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			CFileDialog saveDlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT,
				TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);

			if (saveDlg.DoModal() == IDOK)
			{
				CString savePath = saveDlg.GetPathName();
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
	waitKey(0);
}

void CPhotocolorDlg::Onfengdu()
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR: Image is empty" << '\n';
		return;
	}
	Mat result = srcImg.clone();
	for (int y = 0; y < srcImg.rows; y++)
	{
		for (int x = 0; x < srcImg.cols; x++)
		{
			Vec3b& color = result.at<Vec3b>(Point(x, y));
			color[0] = saturate_cast<uchar>(color[0] * 1.5); // 增强蓝色通道
		}
	}
	imshow("增强蓝色通道", result);
	char key = waitKey(0);
	if (key == 's' || key == 'S')
	{
		UINT i;
		i = MessageBox(_T("是否要保存图像?!"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			CFileDialog saveDlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT,
				TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);

			if (saveDlg.DoModal() == IDOK)
			{
				CString savePath = saveDlg.GetPathName();
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
	waitKey(0);
}

void CPhotocolorDlg::Onall()
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR: Image is empty" << '\n';
		return;
	}
	Mat result = srcImg.clone();
	for (int y = 0; y < srcImg.rows; y++)
	{
		for (int x = 0; x < srcImg.cols; x++)
		{
			Vec3b& color = result.at<Vec3b>(Point(x, y));
			// 混合红色和蓝色到绿色通道
			color[1] = saturate_cast<uchar>(0.5 * color[2] + color[1] + 0.5 * color[0]); // 增强绿色通道

			// 增强所有通道对比度
			color[0] = saturate_cast<uchar>(color[0] * 1.2); // 增强蓝色通道
			color[1] = saturate_cast<uchar>(color[1] * 1.2); // 增强绿色通道（包含混合信息）
			color[2] = saturate_cast<uchar>(color[2] * 1.2); // 增强红色通道
		}
	}
	imshow("将红色和蓝色混合到绿色通道", result);
	char key = waitKey(0);
	if (key == 's' || key == 'S')
	{
		UINT i;
		i = MessageBox(_T("是否要保存图像?!"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			CFileDialog saveDlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT,
				TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);

			if (saveDlg.DoModal() == IDOK)
			{
				CString savePath = saveDlg.GetPathName();
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
	waitKey(0);
}
typedef struct
{
	Point2f left_top;
	Point2f left_bottom;
	Point2f right_top;
	Point2f right_bottom;
} four_corners_t;
four_corners_t corners;
void CalcCorners(const Mat& H, const Mat& src)
{
	double v2[] = { 0, 0, 1 }; // 左上角
	double v1[3]; // 变换后的坐标值
	Mat V2 = Mat(3, 1, CV_64FC1, v2);
	Mat V1 = Mat(3, 1, CV_64FC1, v1);

	V1 = H * V2;
	corners.left_top.x = v1[0] / v1[2];
	corners.left_top.y = v1[1] / v1[2];

	v2[0] = 0;
	v2[1] = src.rows;
	v2[2] = 1;
	V2 = Mat(3, 1, CV_64FC1, v2);
	V1 = Mat(3, 1, CV_64FC1, v1);
	V1 = H * V2;
	corners.left_bottom.x = v1[0] / v1[2];
	corners.left_bottom.y = v1[1] / v1[2];

	v2[0] = src.cols;
	v2[1] = 0;
	v2[2] = 1;
	V2 = Mat(3, 1, CV_64FC1, v2);
	V1 = Mat(3, 1, CV_64FC1, v1);
	V1 = H * V2;
	corners.right_top.x = v1[0] / v1[2];
	corners.right_top.y = v1[1] / v1[2];

	v2[0] = src.cols;
	v2[1] = src.rows;
	v2[2] = 1;
	V2 = Mat(3, 1, CV_64FC1, v2);
	V1 = Mat(3, 1, CV_64FC1, v1);
	V1 = H * V2;
	corners.right_bottom.x = v1[0] / v1[2];
	corners.right_bottom.y = v1[1] / v1[2];
}
Mat equalizeHistogramColor(const Mat& img)
{
	Mat img_yuv;
	cvtColor(img, img_yuv, COLOR_BGR2YUV);
	vector<Mat> channels;
	split(img_yuv, channels);
	equalizeHist(channels[0], channels[0]);
	merge(channels, img_yuv);
	Mat result;
	cvtColor(img_yuv, result, COLOR_YUV2BGR);
	return result;
}
void createMask(const Mat& img1, const Mat& img2, Mat& mask)
{
	mask = Mat::zeros(img1.size(), CV_8UC1);
	int cols = img1.cols;
	int rows = img1.rows;
	int halfCols = cols / 2;

	// 将左半部分设置为 255（白色），右半部分为 0（黑色）
	mask(Rect(0, 0, halfCols, rows)) = 255;
	mask(Rect(halfCols, 0, cols - halfCols, rows)) = 0;
}
void PoissonBlending(const Mat& src, const Mat& dst, Mat& result, Rect region)
{

	Mat mask = Mat::ones(src.size(), CV_8UC1) * 255;

	Point center(region.x + region.width / 2, region.y + region.height / 2);
	seamlessClone(src(region), dst, mask(region), center, result, NORMAL_CLONE);
}
void waveletTransform(const Mat& src, vector<Mat>& wavelets, int levels)
{
	Mat temp = src.clone();
	for (int i = 0; i < levels; i++)
	{
		Mat low, high;
		pyrDown(temp, low);
		pyrUp(low, high, temp.size());
		wavelets.push_back(temp - high);
		temp = low;
	}
	wavelets.push_back(temp);
}
void inverseWaveletTransform(const vector<Mat>& wavelets, Mat& dst, int levels)
{
	dst = wavelets.back();
	for (int i = levels - 1; i >= 0; i--)
	{
		Mat temp;
		pyrUp(dst, temp, wavelets[i].size());
		dst = temp + wavelets[i];
	}
}
void waveletFusion(const Mat& img1, const Mat& img2, Mat& result, int levels)
{
	vector<Mat> wavelets1, wavelets2, waveletsFused;
	waveletTransform(img1, wavelets1, levels);
	waveletTransform(img2, wavelets2, levels);
	for (int i = 0; i < levels + 1; i++)
	{
		Mat fused;
		addWeighted(wavelets1[i], 0.5, wavelets2[i], 0.5, 0, fused);
		waveletsFused.push_back(fused);
	}
	inverseWaveletTransform(waveletsFused, result, levels);
	cvtColor(result, result,COLOR_BGR2GRAY);
}
void multiBandBlending(Mat& img1, Mat& img2, Mat& dst, int levels) //多段融合
{
	Mat src1 = img1;
	Mat src2 = img2;
	Mat mask;
	createMask(img1, img2, mask);
	vector<Mat> channels1, channels2;
	split(src1, channels1);
	split(src2, channels2);
	for (int i = 0; i < src1.channels(); i++)
	{
		MyPyrFusionTest* my_pyr_fusion_test = new MyPyrFusionTest();

		vector<Mat> src_arr, mask_arr;
		src_arr.push_back(channels1[i]);
		src_arr.push_back(channels2[i]);
		mask_arr.push_back(mask);
		mask_arr.push_back(255 - mask);
		channels1[i] = my_pyr_fusion_test->Run(src_arr, mask_arr);
	}
	Mat out;
	merge(channels1, out);
	dst = out;
}
void fadeInOutBlend(Mat& stitched, int seamX, int overlapWidth)  //渐入渐出
{
	int rows = stitched.rows;
	for (int y = 0; y < rows; ++y) {
		for (int x = seamX; x < seamX + overlapWidth; ++x)
		{
			float alpha = float(x - seamX) / overlapWidth;
			Vec3b leftPixel = stitched.at<Vec3b>(y, x - overlapWidth);
			Vec3b rightPixel = stitched.at<Vec3b>(y, x);
			Vec3b blendedPixel = leftPixel * (1.0 - alpha) + rightPixel * alpha;
			stitched.at<Vec3b>(y, x) = blendedPixel;
		}
	}
}
void OptimizeSeam(Mat& img1, Mat& trans, Mat& dst)  //加权线性融合
{
	int start = min(corners.left_top.x, corners.left_bottom.x);
	double processWidth = img1.cols - start;
	int rows = dst.rows;
	int cols = img1.cols;
	double alpha = 1;
	for (int i = 0; i < rows; i++)
	{
		uchar* p = img1.ptr<uchar>(i);
		uchar* t = trans.ptr<uchar>(i);
		uchar* d = dst.ptr<uchar>(i);
		for (int j = start; j < cols; j++)
		{
			// 如果遇到图像trans中无像素的黑点，则完全拷贝img1中的数据
			if (t[j * 3] == 0 && t[j * 3 + 1] == 0 && t[j * 3 + 2] == 0)
			{
				alpha = 1;
			}
			else
			{
				// img1中像素的权重，与当前处理点距重叠区域左边界的距离成正比
				alpha = (processWidth - (j - start)) / processWidth;
			}

			d[j * 3] = p[j * 3] * alpha + t[j * 3] * (1 - alpha);
			d[j * 3 + 1] = p[j * 3 + 1] * alpha + t[j * 3 + 1] * (1 - alpha);
			d[j * 3 + 2] = p[j * 3 + 2] * alpha + t[j * 3 + 2] * (1 - alpha);
		}
	}
}
int getMatchCount(const Mat& img1, const Mat& img2, const Ptr<Feature2D>& sift)
{
	vector<KeyPoint> key1, key2;
	Mat des1, des2;
	sift->detectAndCompute(img1, noArray(), key1, des1);
	sift->detectAndCompute(img2, noArray(), key2, des2);

	BFMatcher matcher(NORM_L2);
	vector<vector<DMatch>> knn_matches;
	matcher.knnMatch(des1, des2, knn_matches, 2);

	int good_match_count = 0;
	for (size_t i = 0; i < knn_matches.size(); i++)
	{
		if (knn_matches[i][0].distance < 0.75 * knn_matches[i][1].distance)
		{
			good_match_count++;
		}
	}
	return good_match_count;
}
int flag = 0;
Mat stitchImages(Mat& img1,Mat& img2, const Ptr<Feature2D>& sift)
{
	vector<KeyPoint> key1, key2;
	Mat des1, des2;
	sift->detectAndCompute(img1, noArray(), key1, des1);
	sift->detectAndCompute(img2, noArray(), key2, des2); BFMatcher matcher(NORM_L2);
	vector<vector<DMatch>> knn_matches;
	matcher.knnMatch(des1, des2, knn_matches, 2);

	vector<DMatch> good_matches;
	for (size_t i = 0; i < knn_matches.size(); i++)
	{
		if (knn_matches[i][0].distance < 0.75 * knn_matches[i][1].distance)
		{
			good_matches.push_back(knn_matches[i][0]);
		}
	}
	vector<Point2f> points1, points2;
	for (size_t i = 0; i < good_matches.size(); i++) {
		points1.push_back(key1[good_matches[i].queryIdx].pt);
		points2.push_back(key2[good_matches[i].trainIdx].pt);
	}

	Mat H = findHomography(points2, points1, RANSAC);

	CalcCorners(H, img2);

	Mat img2_warped;
	warpPerspective(img2, img2_warped, H, Size(max(corners.right_top.x, corners.right_bottom.x), img1.rows)); //变形图像

	int dst_width = img2_warped.cols;
	int dst_height = img1.rows;
	Mat dst(dst_height, dst_width, CV_8UC3);
	dst.setTo(Scalar(0, 0, 0));

	img2_warped.copyTo(dst(Rect(0, 0, img2_warped.cols, img2_warped.rows)));
	img1.copyTo(dst(Rect(0, 0, img1.cols, img1.rows)));
	int top = 0;
	int bottom = img2_warped.rows - img1.rows;
	int left = 0;
	int right = img2_warped.cols - img1.cols;

	// 添加边框以匹配img2_warped的大小
	Mat img1_resized;
	copyMakeBorder(img1, img1_resized, top, bottom, left, right, BORDER_CONSTANT, Scalar(0, 0, 0));
	imshow("初始图", dst);
	if (flag == 1)
	{
		OptimizeSeam(img1, img2_warped, dst);
	}
	else if (flag == 2)
	{
		multiBandBlending(img1_resized, img2_warped,dst,3);
	}
	else if (flag == 4)
	{
		int seamX = img1.cols;
		fadeInOutBlend(dst,seamX,5);
	}
	else if (flag == 3)
	{
		int seamX = img1.cols;
		Rect region(seamX, 0, img2_warped.cols - seamX, img2_warped.rows);
		PoissonBlending(img2_warped, dst, result,region);
		dst = result;
	}
	else if (flag == 7)
	{
		waveletFusion(img1_resized, img2_warped, dst,4);
	}
	return dst;
}
void CPhotocolorDlg::OnSift()
{
	vector<Mat> images;
	CString m_path;
	while (true)
	{
		CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
			TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);
		if (dlg.DoModal() == IDOK)
		{
			m_path = dlg.GetPathName();
			Mat img = imread((LPCTSTR)m_path, 1);
			if (img.empty())
			{
				cerr << "无法读取图像文件！" << endl;
				return;
			}
			images.push_back(img);
			imshow("原图" + to_string(images.size()), img);
		}
		else
		{
			break;
		}
		int w = MessageBox("是否继续添加图片？", "提示", MB_YESNO | MB_ICONQUESTION);
		if (w == IDNO)
			break;
	}

	method Dlg;
	if (Dlg.DoModal() == IDOK)
	{
		flag = Dlg.Getsize();
	}
	if (images.size() < 2)
	{
		cerr << "照片数量太少无法拼接!" << '\n';
		return;
	}
	Ptr<SIFT> sift = SIFT::create(800);
	// 图像配对
	vector<pair<int, int>> image_pairs;
	vector<pair<int, int>> match_counts;
	for (size_t i = 0; i < images.size(); ++i)
	{
		for (size_t j = i + 1; j < images.size(); ++j)
		{
			int count = getMatchCount(images[i], images[j], sift);
			match_counts.push_back(make_pair(i, j));
			image_pairs.push_back(make_pair(count, image_pairs.size()));
		}
	}

	// 图像配对排序
	sort(image_pairs.rbegin(), image_pairs.rend());
	vector<vector<int>> adj_list(images.size());
	for (const auto& pair : image_pairs)
	{
		int idx = pair.second;
		int i = match_counts[idx].first;
		int j = match_counts[idx].second;
		adj_list[i].push_back(j);
		adj_list[j].push_back(i);
	}

	// 最小生成树
	vector<bool> visited(images.size(), false);
	vector<int> image_order;
	function<void(int)> dfs = [&](int u)
	{
		visited[u] = true;
		image_order.push_back(u);
		for (int v : adj_list[u])
		{
			if (!visited[v]) dfs(v);
		}
	};

	// 从第一个图像开始DFS
	dfs(0);

	// 拼接图像
	Mat result_image = images[image_order[0]];
	for (size_t i = 1; i < image_order.size(); ++i)
	{
		result_image = stitchImages(result_image, images[image_order[i]], sift);
	}

	imshow("SIFT拼接后的图", result_image);
	char key = waitKey(0);
	if (key == 's' || key == 'S')
	{
		UINT i;
		i = MessageBox(_T("是否要保存图像?!"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			CFileDialog saveDlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT,
				TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);

			if (saveDlg.DoModal() == IDOK)
			{
				CString savePath = saveDlg.GetPathName();
				imwrite((LPCTSTR)savePath, result_image);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
	waitKey(0);
}
void CPhotocolorDlg::Onstitch()  //Opencv Stitcher拼接
{
	// TODO: 在此添加命令处理程序代码
	std::vector<Mat> images;
	CString m_path;
	while (true)
	{
		CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
			TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);
		if (dlg.DoModal() == IDOK)
		{
			m_path = dlg.GetPathName();
			Mat img = imread((LPCTSTR)m_path, 1);
			if (img.empty())
			{
				cerr << "无法读取图像文件！" << endl;
				return;
			}
			img = equalizeHistogramColor(img);
			images.push_back(img);
			imshow("原图" + to_string(images.size()), img);
		}
		else
		{
			break;
		}
		int w = MessageBox("是否继续添加图片？", "提示", MB_YESNO | MB_ICONQUESTION);
		if (w == IDNO)
			break;
	}

	if (images.size() < 2)
	{
		cerr << "照片数量太少无法拼接!" << '\n';
		return;
	}

	Mat result_image;
	Ptr<Stitcher> stitcher = Stitcher::create(Stitcher::PANORAMA);
	Stitcher::Status status = stitcher->stitch(images, result_image); //默认多带融合

	if (status != Stitcher::OK)
	{
		cerr << "拼接失败，错误代码: " << status << endl;
		switch (status) {
		case Stitcher::ERR_NEED_MORE_IMGS:
			cerr << "需要更多的图片进行拼接" << endl;
			break;
		case Stitcher::ERR_HOMOGRAPHY_EST_FAIL:
			cerr << "Homography 估计失败" << endl;
			break;
		case Stitcher::ERR_CAMERA_PARAMS_ADJUST_FAIL:
			cerr << "相机参数调整失败" << endl;
			break;
		default:
			cerr << "未知错误" << endl;
			break;
		}
		return;
	}
	imshow("Stitch拼接后的图像", result_image);
	char key = waitKey(0);
	if (key == 's' || key == 'S')
	{
		UINT i;
		i = MessageBox(_T("是否要保存图像?!"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			CFileDialog saveDlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT,
				TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);

			if (saveDlg.DoModal() == IDOK)
			{
				CString savePath = saveDlg.GetPathName();
				imwrite((LPCTSTR)savePath, result_image);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
	waitKey(0);
}
void CPhotocolorDlg::Onhomo()   //ORB
{
	// TODO: 在此添加命令处理程序代码
	vector<Mat> images;
	CString m_path;

	while (true)
	{
		CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
			TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);
		if (dlg.DoModal() == IDOK)
		{
			m_path = dlg.GetPathName();
			Mat img = imread((LPCTSTR)m_path, 1);
			if (img.empty())
			{
				cerr << "无法读取图像文件！" << endl;
				return;
			}
			img = equalizeHistogramColor(img);
			images.push_back(img);
			imshow("原图" + to_string(images.size()), img);
		}
		else
		{
			break;
		}
		int w = MessageBox("是否继续添加图片？", "提示", MB_YESNO | MB_ICONQUESTION);
		if (w == IDNO)
			break;
	}
	method Dlg;
	if (Dlg.DoModal() == IDOK)
	{
		flag = Dlg.Getsize();
	}
	if (images.size() < 2)
	{
		cerr << "照片数量太少无法拼接!" << '\n';
		return;
	}

	Ptr<ORB> orb = ORB::create(800);

	// 图像配对
	vector<pair<int, int>> image_pairs;
	vector<pair<int, int>> match_counts;
	for (size_t i = 0; i < images.size(); ++i)
	{
		for (size_t j = i + 1; j < images.size(); ++j)
		{
			int count = getMatchCount(images[i], images[j], orb);
			match_counts.push_back(make_pair(i, j));
			image_pairs.push_back(make_pair(count, image_pairs.size()));
		}
	}

	// 图像配对排序
	sort(image_pairs.rbegin(), image_pairs.rend());
	vector<vector<int>> adj_list(images.size());
	for (const auto& pair : image_pairs)
	{
		int idx = pair.second;
		int i = match_counts[idx].first;
		int j = match_counts[idx].second;
		adj_list[i].push_back(j);
		adj_list[j].push_back(i);
	}

	// 最小生成树
	vector<bool> visited(images.size(), false);
	vector<int> image_order;
	function<void(int)> dfs = [&](int u)
	{
		visited[u] = true;
		image_order.push_back(u);
		for (int v : adj_list[u])
		{
			if (!visited[v]) dfs(v);
		}
	};

	// 从第一个图像开始DFS
	dfs(0);

	// 拼接图像
	Mat result_image = images[image_order[0]];
	for (size_t i = 1; i < image_order.size(); ++i)
	{
		result_image = stitchImages(result_image, images[image_order[i]],orb);
	}

	imshow("ORB拼接后的图", result_image);
	char key = waitKey(0);
	if (key == 's' || key == 'S')
	{
		UINT i;
		i = MessageBox(_T("是否要保存图像?!"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			CFileDialog saveDlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT,
				TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);

			if (saveDlg.DoModal() == IDOK)
			{
				CString savePath = saveDlg.GetPathName();
				imwrite((LPCTSTR)savePath, result_image);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
	waitKey(0);
}
void CPhotocolorDlg::Onmoban()   //基于模板匹配方法
{
	// TODO: 在此添加命令处理程序代码
	Mat imgL, imgR;
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
		TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);
	CString m_path;
	if (dlg.DoModal() == IDOK)
	{
		m_path = dlg.GetPathName();
	}
	else
		return;
	imgL = imread((LPCTSTR)m_path, 1);
	imshow("imgL", imgL);
	CFileDialog dlg1(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
		TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);
	CString m_path1;
	if (dlg1.DoModal() == IDOK)
	{
		m_path1 = dlg1.GetPathName();
	}
	else
		return;
	imgR = imread((LPCTSTR)m_path1, 1);
	imshow("imgR", imgR);
	Mat ImageLeft_gray, ImageRight_gray;
	cvtColor(imgL, ImageLeft_gray, COLOR_BGR2GRAY);
	cvtColor(imgR, ImageRight_gray, COLOR_BGR2GRAY);

	int height_Left = ImageLeft_gray.rows;
	int width_left = ImageLeft_gray.cols;
	int height_Right = ImageRight_gray.rows;
	int width_Right = ImageRight_gray.cols;

	int left_width_begin = 3 * width_left / 4;
	int left_height_begin = 0;
	//左侧模板
	Mat template_left = imgL(Rect(left_width_begin, left_height_begin, width_left - left_width_begin, height_Left / 2 - left_height_begin));
	rectangle(imgL, Point(left_width_begin, left_height_begin), Point(width_left, height_Left / 2), Scalar(0, 0, 255), 1);

	//右侧匹配模板
	Mat match_right = imgR(Rect(0, 0, 2 * width_Right / 3, height_Right));

	Mat matchResult;
	matchTemplate(match_right, template_left, matchResult, TM_CCOEFF_NORMED);
	normalize(matchResult, matchResult, 0, 1, NORM_MINMAX, -1);

	Point max_loc;
	minMaxLoc(matchResult, NULL, NULL, NULL, &max_loc);

	int dst_width = width_Right + left_width_begin - max_loc.x;
	Mat dstStitch(height_Left, dst_width, imgL.type());
	imgL.copyTo(dstStitch(Rect(0, 0, width_left, height_Left)));
	int matchRight_H = height_Right - max_loc.y + left_height_begin;
	int dst_y_start = 0;
	Mat matchRight;
	if (dstStitch.rows == matchRight_H)
	{
		matchRight = imgR(Rect(max_loc.x, max_loc.y - left_height_begin, width_Right - max_loc.x, height_Right));
	}
	else if (dstStitch.rows < matchRight_H)
	{
		matchRight = imgR(Rect(max_loc.x, max_loc.y - left_height_begin, width_Right - max_loc.x, height_Right - 1));
	}
	else
	{
		matchRight = imgR(Rect(max_loc.x, max_loc.y - left_height_begin, width_Right - max_loc.x, height_Right));
		dst_y_start = dstStitch.rows - matchRight_H;
	}
	matchRight.copyTo(dstStitch(Rect(left_width_begin, dst_y_start, matchRight.cols, matchRight.rows)));
	imshow("模板拼接后的图像", dstStitch);
	result = dstStitch.clone();
	char key = waitKey(0);
	if (key == 's' || key == 'S')
	{
		UINT i;
		i = MessageBox(_T("是否要保存图像?!"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			CFileDialog saveDlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT,
				TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);

			if (saveDlg.DoModal() == IDOK)
			{
				CString savePath = saveDlg.GetPathName();
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
	waitKey(0);
}