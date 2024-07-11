
// PhotoSystemDlg.cpp: 实现文件
//
#include <bits/stdc++.h> //万能头文件 
#include "pch.h"
#include "framework.h"
#include "PhotoSystem.h"
#include "PhotoSystemDlg.h"
#include "afxdialogex.h"
#include <easyx.h>
#define M_PI 3.14159265358979323846
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "CRotateDialog.h"
#include "CResize.h"
#include <playsoundapi.h>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/dnn_superres.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/photo.hpp>

using namespace dnn_superres;
using namespace cv::xfeatures2d;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
typedef struct
{
	//四个顶点
	Point2f left_top;
	Point2f left_bottom;
	Point2f right_top;
	Point2f right_bottom;
}four_corners_t;

four_corners_t corners;
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
public:
	afx_msg void OnEspcnX4();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_COMMAND(ID_ESPCN_X4, &CAboutDlg::OnEspcnX4)
END_MESSAGE_MAP()


// CPhotoSystemDlg 对话框

CPhotoSystemDlg::CPhotoSystemDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PHOTOSYSTEM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CPhotoSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPhotoSystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CPhotoSystemDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CPhotoSystemDlg::OnBnClickedButton3)
	ON_COMMAND(ID_FLYChange, &CPhotoSystemDlg::OnFlychange)
	ON_COMMAND(ID_Noise1, &CPhotoSystemDlg::OnNoise1)
	ON_COMMAND(ID_Noise2, &CPhotoSystemDlg::OnNoise2)
	ON_COMMAND(ID_LUBO1, &CPhotoSystemDlg::OnLubo1)
	ON_COMMAND(ID_LUBO3, &CPhotoSystemDlg::OnLubo3)
	ON_COMMAND(ID_LUBO2, &CPhotoSystemDlg::OnLubo2)
	ON_COMMAND(ID_LUBO4, &CPhotoSystemDlg::OnLubo4)
	ON_COMMAND(ID_LUBO5, &CPhotoSystemDlg::OnLubo5)
	ON_COMMAND(ID_LUBO6, &CPhotoSystemDlg::OnLubo6)
	ON_COMMAND(ID_LUBO7, &CPhotoSystemDlg::OnLubo7)
	ON_COMMAND(ID_LUBO8, &CPhotoSystemDlg::OnLubo8)
	ON_COMMAND(ID_LUBO9, &CPhotoSystemDlg::OnLubo9)
	ON_COMMAND(ID_LUBO10, &CPhotoSystemDlg::OnLubo10)
	ON_COMMAND(ID_COLORCHANGE, &CPhotoSystemDlg::OnColorchange)
	ON_COMMAND(ID_CAIJIAN, &CPhotoSystemDlg::OnCaijian)
	ON_COMMAND(ID_makeChange, &CPhotoSystemDlg::Onmakechange)
	ON_COMMAND(ID_Rotate, &CPhotoSystemDlg::OnRotate)
	ON_BN_CLICKED(IDC_RADIO8, &CPhotoSystemDlg::OnBnClickedRadio8)
	ON_BN_CLICKED(IDC_RADIO17, &CPhotoSystemDlg::OnBnClickedRadio17)
	ON_BN_CLICKED(IDC_RADIO9, &CPhotoSystemDlg::OnBnClickedRadio9)
	ON_BN_CLICKED(IDC_RADIO10, &CPhotoSystemDlg::OnBnClickedRadio10)
	ON_BN_CLICKED(IDC_RADIO11, &CPhotoSystemDlg::OnBnClickedRadio11)
	ON_BN_CLICKED(IDC_RADIO12, &CPhotoSystemDlg::OnBnClickedRadio12)
	ON_COMMAND(ID_Symmetry1, &CPhotoSystemDlg::OnSymmetry1)
	ON_COMMAND(ID_Symmetry2, &CPhotoSystemDlg::OnSymmetry2)
	ON_COMMAND(ID_JunH, &CPhotoSystemDlg::OnJunh)
	ON_COMMAND(ID_Chazhi1, &CPhotoSystemDlg::OnChazhi1)
	ON_COMMAND(ID_Chazhi2, &CPhotoSystemDlg::OnChazhi2)
	ON_COMMAND(ID_Chazhi4, &CPhotoSystemDlg::OnChazhi4)
	ON_COMMAND(ID_Chazhi3, &CPhotoSystemDlg::OnChazhi3)
	ON_COMMAND(ID_Chazhi5, &CPhotoSystemDlg::OnChazhi5)
	ON_COMMAND(ID_EDSR_X2, &CPhotoSystemDlg::OnEdsrX2)
	ON_COMMAND(ID_Meihua1, &CPhotoSystemDlg::OnMeihua1)
	ON_COMMAND(ID_Meihua5, &CPhotoSystemDlg::OnMeihua5)
	ON_COMMAND(ID_Meihua2, &CPhotoSystemDlg::OnMeihua2)
	ON_COMMAND(ID_Meihua3, &CPhotoSystemDlg::OnMeihua3)
	ON_COMMAND(ID_Meihua4, &CPhotoSystemDlg::OnMeihua4)
	ON_COMMAND(ID_Meihua6, &CPhotoSystemDlg::OnMeihua6)
	ON_COMMAND(ID_EDSR_X3, &CPhotoSystemDlg::OnEdsrX3)
	ON_COMMAND(ID_EDSR_X4, &CPhotoSystemDlg::OnEdsrX4)
	ON_COMMAND(ID_ESPCN_X2, &CPhotoSystemDlg::OnEspcnX2)
	ON_COMMAND(ID_ESPCN_X3, &CPhotoSystemDlg::OnEspcnX3)
	ON_COMMAND(ID_FSRCNN_X2, &CPhotoSystemDlg::OnFsrcnnX2)
	ON_COMMAND(ID_ESPCN_X4, &CPhotoSystemDlg::OnEspcnX4)
	ON_COMMAND(ID_FSRCNN_X3, &CPhotoSystemDlg::OnFsrcnnX3)
	ON_COMMAND(ID_FSRCNN_X4, &CPhotoSystemDlg::OnFsrcnnX4)
	ON_COMMAND(ID_LAPSRN_X2, &CPhotoSystemDlg::OnLapsrnX2)
	ON_COMMAND(ID_LAPSRN_X4, &CPhotoSystemDlg::OnLapsrnX4)
	ON_COMMAND(ID_LAPSRN_X8, &CPhotoSystemDlg::OnLapsrnX8)
	ON_COMMAND(ID_LAPULASI, &CPhotoSystemDlg::OnLapulasi)
	ON_COMMAND(ID_LOG, &CPhotoSystemDlg::OnLog)
	ON_COMMAND(ID_GRAMA, &CPhotoSystemDlg::OnGrama)
	ON_COMMAND(ID_ssim, &CPhotoSystemDlg::Onssim)
	ON_COMMAND(ID_PSNR, &CPhotoSystemDlg::OnPsnr)
	ON_BN_CLICKED(IDC_RADIO13, &CPhotoSystemDlg::OnBnClickedRadio13)
	ON_BN_CLICKED(IDC_RADIO14, &CPhotoSystemDlg::OnBnClickedRadio14)
	ON_BN_CLICKED(IDC_RADIO15, &CPhotoSystemDlg::OnBnClickedRadio15)
	ON_BN_CLICKED(IDC_RADIO16, &CPhotoSystemDlg::OnBnClickedRadio16)
	ON_COMMAND(ID_Fmm, &CPhotoSystemDlg::OnFmm)
	ON_COMMAND(ID_fengge, &CPhotoSystemDlg::Onfengge)
	ON_COMMAND(ID_fengge2, &CPhotoSystemDlg::Onfengge2)
	ON_COMMAND(ID_fengge3, &CPhotoSystemDlg::Onfengge3)
	ON_COMMAND(ID_fengge4, &CPhotoSystemDlg::Onfengge4)
	ON_COMMAND(ID_fengge5, &CPhotoSystemDlg::Onfengge5)
	ON_COMMAND(ID_fengge6, &CPhotoSystemDlg::Onfengge6)
	ON_COMMAND(ID_fengge7, &CPhotoSystemDlg::Onfengge7)
	ON_COMMAND(ID_fengge8, &CPhotoSystemDlg::Onfengge8)
	ON_COMMAND(ID_fengge9, &CPhotoSystemDlg::Onfengge9)
END_MESSAGE_MAP()


// CPhotoSystemDlg 消息处理程序

BOOL CPhotoSystemDlg::OnInitDialog()
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

void CPhotoSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPhotoSystemDlg::OnPaint()
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
HCURSOR CPhotoSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPhotoSystemDlg::OnBnClickedButton1()  //打开文件
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
		TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);
	CString m_path;//用来存储文件路径
	if (dlg.DoModal() == IDOK)
	{
		m_path = dlg.GetPathName();
	}
	else
		return;
	Mat srcImg = imread((LPCTSTR)m_path, 1);
	Mat image;
	if (srcImg.empty())
	{
		AfxMessageBox(_T("the image is not exist！"));
	}
	resize(srcImg, srcImg, Size(512, 512));
	srcImg.convertTo(srcImg, CV_32F, 1.0 / 255);
	imshow("原图", srcImg);
}
void CPhotoSystemDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UINT i;
	i = MessageBox(_T("确定要退出系统吗?!"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
	if (i == IDYES)
	{
		exit(0);
	}
}
void My_DFT(Mat input_image, Mat& output_image, Mat& transform_image)  //自制傅里叶变换
{
	//扩展图像矩阵，为2，3，5的倍数时运算速度快
	int m = getOptimalDFTSize(input_image.rows);
	int n = getOptimalDFTSize(input_image.cols);
	copyMakeBorder(input_image, input_image, 0, m - input_image.rows, 0, n - input_image.cols, BORDER_CONSTANT, Scalar::all(0));

	//创建一个双通道矩阵planes，用来储存复数的实部与虚部
	Mat planes[] = { Mat_<float>(input_image), Mat::zeros(input_image.size(), CV_32F) };

	//从多个单通道数组中创建一个多通道数组:transform_image。函数Merge将几个数组合并为一个多通道阵列，即输出数组的每个元素将是输入数组元素的级联
	merge(planes, 2, transform_image);

	//进行傅立叶变换
	dft(transform_image, transform_image);

	//计算复数的幅值，保存在output_image（频谱图）
	split(transform_image, planes); // 将双通道分为两个单通道，一个表示实部，一个表示虚部
	Mat transform_image_real = planes[0];
	Mat transform_image_imag = planes[1];

	magnitude(planes[0], planes[1], output_image); //计算复数的幅值，保存在output_image（频谱图）

	//前面得到的频谱图数级过大，不好显示，因此转换
	output_image += Scalar(1);   // 取对数前将所有的像素都加1，防止log0
	log(output_image, output_image);   // 取对数
	normalize(output_image, output_image, 0, 1, NORM_MINMAX); //归一化

	//剪切和重分布幅度图像限
	output_image = output_image(Rect(0, 0, output_image.cols & -2, output_image.rows & -2));

	// 重新排列傅里叶图像中的象限，使原点位于图像中心
	int cx = output_image.cols / 2;
	int cy = output_image.rows / 2;
	Mat q0(output_image, Rect(0, 0, cx, cy));   // 左上区域
	Mat q1(output_image, Rect(cx, 0, cx, cy));  // 右上区域
	Mat q2(output_image, Rect(0, cy, cx, cy));  // 左下区域
	Mat q3(output_image, Rect(cx, cy, cx, cy)); // 右下区域

	//交换象限中心化
	Mat tmp;
	q0.copyTo(tmp); q3.copyTo(q0); tmp.copyTo(q3);//左上与右下进行交换
	q1.copyTo(tmp); q2.copyTo(q1); tmp.copyTo(q2);//右上与左下进行交换


	Mat q00(transform_image_real, Rect(0, 0, cx, cy));   // 左上区域
	Mat q01(transform_image_real, Rect(cx, 0, cx, cy));  // 右上区域
	Mat q02(transform_image_real, Rect(0, cy, cx, cy));  // 左下区域
	Mat q03(transform_image_real, Rect(cx, cy, cx, cy)); // 右下区域
	q00.copyTo(tmp); q03.copyTo(q00); tmp.copyTo(q03);//左上与右下进行交换
	q01.copyTo(tmp); q02.copyTo(q01); tmp.copyTo(q02);//右上与左下进行交换

	Mat q10(transform_image_imag, Rect(0, 0, cx, cy));   // 左上区域
	Mat q11(transform_image_imag, Rect(cx, 0, cx, cy));  // 右上区域
	Mat q12(transform_image_imag, Rect(0, cy, cx, cy));  // 左下区域
	Mat q13(transform_image_imag, Rect(cx, cy, cx, cy)); // 右下区域
	q10.copyTo(tmp); q13.copyTo(q10); tmp.copyTo(q13);//左上与右下进行交换
	q11.copyTo(tmp); q12.copyTo(q11); tmp.copyTo(q12);//右上与左下进行交换

	planes[0] = transform_image_real;
	planes[1] = transform_image_imag;
	merge(planes, 2, transform_image);//将傅里叶变换结果中心化
}
void CPhotoSystemDlg::OnFlychange()  //傅里叶变换
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
		TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);
	CString m_path;//用来存储文件路径
	if (dlg.DoModal() == IDOK)
	{
		m_path = dlg.GetPathName();
	}
	else
		return;
	Mat srcImg = imread((LPCTSTR)m_path, 1);
	Mat image;
	if (srcImg.empty())
	{
		AfxMessageBox(_T("the image is not exist！"));
	}
	resize(srcImg, srcImg, Size(512, 512));
	cvtColor(srcImg,image, COLOR_RGB2GRAY);
	imshow("灰度", image);
	image.convertTo(image, CV_32F, 1.0 / 255);
	Mat result, img_transform;
	My_DFT(image, result, img_transform);
	imshow("原图", srcImg);
	moveWindow("原图", (1920 - srcImg.cols) / 2, (1080 - srcImg.rows) / 2);
	imshow("傅里叶变换", result);
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
}
void CPhotoSystemDlg::OnNoise1()  //椒盐
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
	Mat srcImg = imread((LPCTSTR)m_path, 1);
	imshow("原图", srcImg);
	moveWindow("原图", (1920 - srcImg.cols) / 2, (1080 - srcImg.rows) / 2);
	Mat image = srcImg;
	for (int k = 0; k < 15000; k++) {
		int i, j;
		i = cvflann::rand_int() % image.cols;
		j = cvflann::rand_int() % image.rows;
		int white_black = cvflann::rand_int() % 2;
		if (white_black == 0)
		{
			if (image.type() == CV_8UC1)
			{
				image.at<uchar>(j, i) = 255;
			}
			else if (image.type() == CV_8UC3)
			{
				image.at<cv::Vec3b>(j, i)[0] = 255;
				image.at<cv::Vec3b>(j, i)[1] = 255;
				image.at<cv::Vec3b>(j, i)[2] = 255;
			}
		}
		else
		{
			if (image.type() == CV_8UC1)
			{
				image.at<uchar>(j, i) = 0;
			}
			else if (image.type() == CV_8UC3)
			{
				image.at<cv::Vec3b>(j, i)[0] = 0;
				image.at<cv::Vec3b>(j, i)[1] = 0;
				image.at<cv::Vec3b>(j, i)[2] = 0;
			}
		}
	}
	imshow("椒盐噪声", image);
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

}
void CPhotoSystemDlg::OnNoise2() //高斯
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
	Mat srcImg = imread((LPCTSTR)m_path, 1);
	imshow("原图", srcImg);
	moveWindow("原图", (1920 - srcImg.cols) / 2, (1080 - srcImg.rows) / 2);
	Mat image = srcImg;
	Mat image_noise = Mat::zeros(image.rows, image.cols, image.type());
	RNG rng;
	rng.fill(image_noise, RNG::NORMAL, 10, 20);
	image = image + image_noise;
	imshow("高斯噪声", image);
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
}
Mat meanFilter(Mat src, int ksize) //均值滤波
{
	Mat dst = src.clone();
	int k0 = ksize / 2;
	int sum[3] = { 0,0,0 };
	for (int i = k0; i < dst.rows - k0 - 1; i++)
	{
		for (int j = k0; j < dst.cols - k0 - 1; j++)
		{
			memset(sum, 0, sizeof(sum));
			for (int c = 0; c < 3; c++)
			{
				for (int m = 0; m < ksize; m++)
				{
					for (int n = 0; n < ksize; n++)
					{
						sum[c] += src.at<cv::Vec3b>(i - k0 + m, j - k0 + n)[c];
					}
				}
				dst.at<cv::Vec3b>(i, j)[c] = cv::saturate_cast<uchar>((float)sum[c] / (ksize * ksize));
			}
		}
	}
	return dst;
}
void CPhotoSystemDlg::OnLubo1()  //均值滤波
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
	Mat srcImg = imread((LPCTSTR)m_path, 1);
	imshow("原图", srcImg);
	moveWindow("原图", (1920 - srcImg.cols) / 2, (1080 - srcImg.rows) / 2);
	Mat result = meanFilter(srcImg, 3);
	imshow("均值滤波", result);
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
}
Mat GuessLUBO(Mat src, int ksize)  //高斯滤波
{
	Mat dst = src.clone();
	int k = ksize / 2;
	double sum[3] = { 0,0,0 };
	double sum1[3] = { 0,0,0 };
	for (int i = k; i < dst.rows - k - 1; i++)
	{
		for (int j = k; j < dst.cols - k - 1; j++)
		{
			memset(sum, 0, sizeof(sum));
			memset(sum1, 0, sizeof(sum1));
			double sigma = 7;
			double g;
			for (int c = 0; c < 3; c++)
			{
				for (int m = -k; m < k + 1; m++)
				{
					for (int n = -k; n < k + 1; n++)
					{
						g = exp(-(m * m + n * n)) / (2 * sigma * sigma);
						sum[c] = sum[c] + g * src.at<cv::Vec3b>(i + m, j + n)[c];
						sum1[c] = sum1[c] + g;
					}
				}
				dst.at<cv::Vec3b>(i, j)[c] = cv::saturate_cast<uchar>(sum[c] / sum1[c]);
			}
		}
	}
	return dst;
}
void CPhotoSystemDlg::OnLubo3()  //高斯滤波
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
	Mat srcImg = imread((LPCTSTR)m_path, 1);
	imshow("原图", srcImg);
	moveWindow("原图", (1920 - srcImg.cols) / 2, (1080 - srcImg.rows) / 2);
	Mat result = GuessLUBO(srcImg, 3);
	imshow("高斯滤波", result);
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
	//Mat l;
	//GaussianBlur(srcImg, l, Size(3, 3), 2, 2);
	//imshow("another", l);
}
void CPhotoSystemDlg::OnLubo2() //中值滤波
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
	Mat srcImg = imread((LPCTSTR)m_path, 1);
	imshow("原图", srcImg);
	moveWindow("原图", (1920 - srcImg.cols) / 2, (1080 - srcImg.rows) / 2);
	Mat result;
	medianBlur(srcImg, result,3);
	imshow("中值滤波", result);
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

}
void CPhotoSystemDlg::OnLubo4()   //理想低通滤波
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
		TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);
	CString m_path;//用来存储文件路径
	if (dlg.DoModal() == IDOK)
	{
		m_path = dlg.GetPathName();
	}
	else
		return;
	Mat srcImg = imread((LPCTSTR)m_path, 1);
	Mat image;
	if (srcImg.empty())
	{
		AfxMessageBox(_T("the image is not exist！"));
	}
	resize(srcImg, srcImg, Size(512, 512));
	cvtColor(srcImg, image, COLOR_RGB2GRAY);
	imshow("灰度", image);
	image.convertTo(image, CV_32F, 1.0 / 255);
	Mat result, img_transform;
	My_DFT(image, result, img_transform);
	imshow("原图", srcImg);
	moveWindow("原图", (1920 - srcImg.cols) / 2, (1080 - srcImg.rows) / 2);
	imshow("傅里叶变换", result);
	Mat planes[] = { Mat_<float>(result),Mat::zeros(result.size(),CV_32F) };
	split(img_transform, planes);
	Mat img_r_transform = planes[0];
	Mat img_l_transform = planes[1];
	int core_x = img_r_transform.rows / 2;
	int core_y = img_l_transform.cols / 2;
	int r = 60;  
	for (int i = 0; i < img_r_transform.rows; i++)
	{
		for (int j = 0; j < img_r_transform.cols; j++)
		{
			//距离中心的距离大于设置半径r的点所在值设为0
			if (((i - core_x) * (i - core_x) + (j - core_y) * (j - core_y)) > r * r)
			{
				img_r_transform.at<float>(i, j) = 0;
				img_l_transform.at<float>(i, j) = 0;
			}
		}
	}
	planes[0] = img_r_transform;
	planes[1] = img_l_transform;
	Mat image_transform_ilpf;//定义理想低通滤波矩阵
	merge(planes, 2, image_transform_ilpf);

	//傅里叶逆变换
	Mat iDft[] = { Mat_<float>(result), Mat::zeros(result.size(),CV_32F) };
	idft(image_transform_ilpf, image_transform_ilpf);//傅立叶逆变换
	split(image_transform_ilpf, iDft);//分离通道，主要获取0通道
	magnitude(iDft[0], iDft[1], iDft[0]); //计算复数的幅值，保存在iDft[0]
	normalize(iDft[0], iDft[0], 0, 1, NORM_MINMAX);//归一化处理
	imshow("理想低通滤波", iDft[0]);
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
				imwrite((LPCTSTR)savePath, iDft[0]);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}
void CPhotoSystemDlg::OnLubo5()    //高斯低通滤波
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
	Mat srcImg = imread((LPCTSTR)m_path, 1);
	imshow("原图", srcImg);
	moveWindow("原图", (1920 - srcImg.cols) / 2, (1080 - srcImg.rows) / 2);
	Mat image;
	cvtColor(srcImg, image,COLOR_BGR2GRAY);
	imshow("灰度", image);
	Mat image_output, image_transform;
	My_DFT(image, image_output, image_transform);
	imshow("傅里叶变换", image_output);

	Mat planes[] = { Mat_<float>(image_output), Mat::zeros(image_output.size(),CV_32F) };
	split(image_transform, planes);//分离通道，获取实部虚部
	Mat image_transform_real = planes[0];
	Mat image_transform_imag = planes[1];

	int core_x = image_transform_real.rows / 2;//频谱图中心坐标
	int core_y = image_transform_real.cols / 2;
	int r = 60;
	float h;
	for (int i = 0; i < image_transform_real.rows; i++)
	{
		for (int j = 0; j < image_transform_real.cols; j++)
		{
			h = exp(-((i - core_x) * (i - core_x) + (j - core_y) * (j - core_y)) / (2 * r * r));
			image_transform_real.at<float>(i, j) = image_transform_real.at<float>(i, j) * h;
			image_transform_imag.at<float>(i, j) = image_transform_imag.at<float>(i, j) * h;

		}
	}
	planes[0] = image_transform_real;
	planes[1] = image_transform_imag;
	Mat image_transform_ilpf;
	merge(planes, 2, image_transform_ilpf);

	//傅里叶逆变换
	Mat iDft[] = { Mat_<float>(image_output), Mat::zeros(image_output.size(),CV_32F) };
	idft(image_transform_ilpf, image_transform_ilpf);//傅立叶逆变换
	split(image_transform_ilpf, iDft);//分离通道，主要获取0通道
	magnitude(iDft[0], iDft[1], iDft[0]); //计算复数的幅值，保存在iDft[0]
	normalize(iDft[0], iDft[0], 0, 1, NORM_MINMAX);//归一化处理
	imshow("高斯低通滤波", iDft[0]);
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
				imwrite((LPCTSTR)savePath, iDft[0]);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}
void CPhotoSystemDlg::OnLubo6()  //巴特沃斯低通滤波
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
	Mat srcImg = imread((LPCTSTR)m_path, 1);
	imshow("原图", srcImg);
	moveWindow("原图", (1920 - srcImg.cols) / 2, (1080 - srcImg.rows) / 2);
	Mat image;
	cvtColor(srcImg, image, COLOR_BGR2GRAY);
	imshow("灰度", image);
	Mat image_output, image_transform;
	My_DFT(image, image_output, image_transform);
	imshow("傅里叶变换", image_output);

	Mat planes[] = { Mat_<float>(image_output), Mat::zeros(image_output.size(),CV_32F) };
	split(image_transform, planes);//分离通道，获取实部虚部
	Mat image_transform_real = planes[0];
	Mat image_transform_imag = planes[1];

	int core_x = image_transform_real.rows / 2;//频谱图中心坐标
	int core_y = image_transform_real.cols / 2;

	int r = 60;  //滤波半径
	float h;
	float n = 3; //巴特沃斯系数
	float D;  //距离中心距离

	for (int i = 0; i < image_transform_real.rows; i++)
	{
		for (int j = 0; j < image_transform_real.cols; j++)
		{
			D = (i - core_x) * (i - core_x) + (j - core_y) * (j - core_y);
			h = 1 / (1 + pow((D / (r * r)), n));
			image_transform_real.at<float>(i, j) = image_transform_real.at<float>(i, j) * h;
			image_transform_imag.at<float>(i, j) = image_transform_imag.at<float>(i, j) * h;
		}
	}
	planes[0] = image_transform_real;
	planes[1] = image_transform_imag;
	Mat image_transform_ilpf;
	merge(planes, 2, image_transform_ilpf);

	Mat iDft[] = { Mat_<float>(image_output), Mat::zeros(image_output.size(),CV_32F) };
	idft(image_transform_ilpf, image_transform_ilpf);
	split(image_transform_ilpf, iDft);
	magnitude(iDft[0], iDft[1], iDft[0]);
	normalize(iDft[0], iDft[0], 0, 1, NORM_MINMAX);
	imshow("巴特沃斯低通滤波", iDft[0]);
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
				imwrite((LPCTSTR)savePath, iDft[0]);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}

}
void CPhotoSystemDlg::OnLubo7()  //理想高通滤波
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
		TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);
	CString m_path;//用来存储文件路径
	if (dlg.DoModal() == IDOK)
	{
		m_path = dlg.GetPathName();
	}
	else
		return;
	Mat srcImg = imread((LPCTSTR)m_path, 1);
	Mat image;
	if (srcImg.empty())
	{
		AfxMessageBox(_T("the image is not exist！"));
	}
	resize(srcImg, srcImg, Size(512, 512));
	cvtColor(srcImg, image, COLOR_RGB2GRAY);
	imshow("灰度", image);
	image.convertTo(image, CV_32F, 1.0 / 255);
	Mat result, img_transform;
	My_DFT(image, result, img_transform);
	imshow("原图", srcImg);
	moveWindow("原图", (1920 - srcImg.cols) / 2, (1080 - srcImg.rows) / 2);
	imshow("傅里叶变换", result);
	Mat planes[] = { Mat_<float>(result),Mat::zeros(result.size(),CV_32F) };
	split(img_transform, planes);
	Mat img_r_transform = planes[0];
	Mat img_l_transform = planes[1];
	int core_x = img_r_transform.rows / 2;
	int core_y = img_l_transform.cols / 2;
	int r = 60;
	for (int i = 0; i < img_r_transform.rows; i++)
	{
		for (int j = 0; j < img_r_transform.cols; j++)
		{
			//距离中心的距离大于设置半径r的点所在值设为0
			if (((i - core_x) * (i - core_x) + (j - core_y) * (j - core_y)) < r * r)
			{
				img_r_transform.at<float>(i, j) = 0;
				img_l_transform.at<float>(i, j) = 0;
			}
		}
	}
	planes[0] = img_r_transform;
	planes[1] = img_l_transform;
	Mat image_transform_ilpf;//定义理想低通滤波矩阵
	merge(planes, 2, image_transform_ilpf);

	//傅里叶逆变换
	Mat iDft[] = { Mat_<float>(result), Mat::zeros(result.size(),CV_32F) };
	idft(image_transform_ilpf, image_transform_ilpf);//傅立叶逆变换
	split(image_transform_ilpf, iDft);//分离通道，主要获取0通道
	magnitude(iDft[0], iDft[1], iDft[0]); //计算复数的幅值，保存在iDft[0]
	normalize(iDft[0], iDft[0], 0, 1, NORM_MINMAX);//归一化处理
	imshow("理想高通滤波", iDft[0]);
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
				imwrite((LPCTSTR)savePath, iDft[0]);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}
void CPhotoSystemDlg::OnLubo8()  //高斯高通滤波
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
	Mat srcImg = imread((LPCTSTR)m_path, 1);
	imshow("原图", srcImg);
	moveWindow("原图", (1920 - srcImg.cols) / 2, (1080 - srcImg.rows) / 2);
	Mat image;
	cvtColor(srcImg, image, COLOR_BGR2GRAY);
	imshow("灰度", image);
	Mat image_output, image_transform;
	My_DFT(image, image_output, image_transform);
	imshow("傅里叶变换", image_output);

	Mat planes[] = { Mat_<float>(image_output), Mat::zeros(image_output.size(),CV_32F) };
	split(image_transform, planes);//分离通道，获取实部虚部
	Mat image_transform_real = planes[0];
	Mat image_transform_imag = planes[1];

	int core_x = image_transform_real.rows / 2;//频谱图中心坐标
	int core_y = image_transform_real.cols / 2;
	int r = 60;
	float h;
	for (int i = 0; i < image_transform_real.rows; i++)
	{
		for (int j = 0; j < image_transform_real.cols; j++)
		{
			h = 1-exp(-((i - core_x) * (i - core_x) + (j - core_y) * (j - core_y)) / (2 * r * r));
			image_transform_real.at<float>(i, j) = image_transform_real.at<float>(i, j) * h;
			image_transform_imag.at<float>(i, j) = image_transform_imag.at<float>(i, j) * h;

		}
	}
	planes[0] = image_transform_real;
	planes[1] = image_transform_imag;
	Mat image_transform_ilpf;
	merge(planes, 2, image_transform_ilpf);

	//傅里叶逆变换
	Mat iDft[] = { Mat_<float>(image_output), Mat::zeros(image_output.size(),CV_32F) };
	idft(image_transform_ilpf, image_transform_ilpf);//傅立叶逆变换
	split(image_transform_ilpf, iDft);//分离通道，主要获取0通道
	magnitude(iDft[0], iDft[1], iDft[0]); //计算复数的幅值，保存在iDft[0]
	normalize(iDft[0], iDft[0], 0, 1, NORM_MINMAX);//归一化处理
	imshow("高斯高通滤波", iDft[0]);
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
				imwrite((LPCTSTR)savePath, iDft[0]);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}
void CPhotoSystemDlg::OnLubo9()  //巴特沃斯高通滤波
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
	Mat srcImg = imread((LPCTSTR)m_path, 1);
	imshow("原图", srcImg);
	moveWindow("原图", (1920 - srcImg.cols) / 2, (1080 - srcImg.rows) / 2);
	Mat image;
	cvtColor(srcImg, image, COLOR_BGR2GRAY);
	imshow("灰度", image);
	Mat image_output, image_transform;
	My_DFT(image, image_output, image_transform);
	imshow("傅里叶变换", image_output);

	Mat planes[] = { Mat_<float>(image_output), Mat::zeros(image_output.size(),CV_32F) };
	split(image_transform, planes);//分离通道，获取实部虚部
	Mat image_transform_real = planes[0];
	Mat image_transform_imag = planes[1];

	int core_x = image_transform_real.rows / 2;//频谱图中心坐标
	int core_y = image_transform_real.cols / 2;

	int r = 60;  //滤波半径
	float h;
	float n = 3; //巴特沃斯系数
	float D;  //距离中心距离

	for (int i = 0; i < image_transform_real.rows; i++)
	{
		for (int j = 0; j < image_transform_real.cols; j++)
		{
			D = (i - core_x) * (i - core_x) + (j - core_y) * (j - core_y);
			h = 1 / (1 + pow(((r*r)/D), n));
			image_transform_real.at<float>(i, j) = image_transform_real.at<float>(i, j) * h;
			image_transform_imag.at<float>(i, j) = image_transform_imag.at<float>(i, j) * h;
		}
	}
	planes[0] = image_transform_real;
	planes[1] = image_transform_imag;
	Mat image_transform_ilpf;
	merge(planes, 2, image_transform_ilpf);

	Mat iDft[] = { Mat_<float>(image_output), Mat::zeros(image_output.size(),CV_32F) };
	idft(image_transform_ilpf, image_transform_ilpf);
	split(image_transform_ilpf, iDft);
	magnitude(iDft[0], iDft[1], iDft[0]);
	normalize(iDft[0], iDft[0], 0, 1, NORM_MINMAX);
	imshow("巴特沃斯高通滤波", iDft[0]);
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
				imwrite((LPCTSTR)savePath, iDft[0]);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}

}
void CPhotoSystemDlg::OnLubo10()  //拉普拉斯滤波（锐化）
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
	Mat srcImg = imread((LPCTSTR)m_path, 1);
	imshow("原图", srcImg);
	moveWindow("原图", (1920 - srcImg.cols) / 2, (1080 - srcImg.rows) / 2);
	Mat image;
	cvtColor(srcImg, image, COLOR_BGR2GRAY);
	imshow("灰度", image);
	Mat image_output, image_transform;
	My_DFT(image, image_output, image_transform);
	imshow("傅里叶变换", image_output);

	Mat planes[] = { Mat_<float>(image_output), Mat::zeros(image_output.size(),CV_32F) };
	split(image_transform, planes);//分离通道，获取实部虚部
	Mat image_transform_real = planes[0];
	Mat image_transform_imag = planes[1];

	int core_x = image_transform_real.rows / 2;//频谱图中心坐标
	int core_y = image_transform_real.cols / 2;
	float h;
	float D;  //距离中心距离
	for (int i = 0; i < image_transform_real.rows; i++)
	{
		for (int j = 0; j < image_transform_real.cols; j++)
		{
			D = (i - core_x) * (i - core_x) + (j - core_y) * (j - core_y);
			h = -4 * M_PI * M_PI * D;
			image_transform_real.at<float>(i, j) = image_transform_real.at<float>(i, j) * h;
			image_transform_imag.at<float>(i, j) = image_transform_imag.at<float>(i, j) * h;

		}
	}
	planes[0] = image_transform_real;
	planes[1] = image_transform_imag;
	Mat image_transform_ilpf;
	merge(planes, 2, image_transform_ilpf);

	Mat iDft[] = { Mat_<float>(image_output), Mat::zeros(image_output.size(),CV_32F) };
	idft(image_transform_ilpf, image_transform_ilpf);//傅立叶逆变换
	split(image_transform_ilpf, iDft);//分离通道，主要获取0通道
	magnitude(iDft[0], iDft[1], iDft[0]); //计算复数的幅值，保存在iDft[0]
	normalize(iDft[0], iDft[0], 0, 1, NORM_MINMAX);//归一化处理
	imshow("拉普拉斯滤波", iDft[0]);//显示逆变换图像

	iDft[0].convertTo(iDft[0], CV_8U, 255 / 1.0, 0);
	Mat image_result(iDft[0].size(), CV_8U);
	for (int i = 0; i < iDft[0].rows; i++)
	{
		for (int j = 0; j < iDft[0].cols; j++)
		{
			image_result.at<uchar>(i, j) = saturate_cast<uchar>(image.at<uchar>(i, j) + iDft[0].at<uchar>(i, j));
		}
	}
	imshow("标定处理", image_result);
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
				imwrite((LPCTSTR)savePath, image_result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}
void CPhotoSystemDlg::OnColorchange() //彩色转灰度
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
	Mat srcImg = imread((LPCTSTR)m_path, 1);
	imshow("原图", srcImg);
	moveWindow("原图", (1920 - srcImg.cols) / 2, (1080 - srcImg.rows) / 2);
	Mat image;
	cvtColor(srcImg, image, COLOR_BGR2GRAY);
	imshow("灰度", image);
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
}
void CPhotoSystemDlg::OnCaijian()  //图像裁剪与保存
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
	Mat srcImg = imread((LPCTSTR)m_path, 1);
	char key = 0;
	while (key != 'esc')
	{
		auto roi = selectROI(srcImg, TRUE, FALSE);
		Mat result;
		srcImg(Rect(roi)).copyTo(result);
		if (result.empty()) break;
		imshow("截取后的图", result);
		key = waitKey(0);
		if (key == 's' || key == 'S')
		{
			UINT i;
			i = MessageBox(_T("是否要保存截取图像?!"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
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
	}
}
Mat srcImg,result;
int light{ 0 };
int contast{ 0 };
int light_max{ 255 };
int contastmax{ 255 };
int sa{ 0 };
int maxsa{ 255 };
void adjustSaturation(int saturation, void* userdata){
	Mat* src = (Mat*)userdata;
	Mat hsv;
	cvtColor(*src, hsv, COLOR_BGR2HSV); 
	std::vector<Mat> channels;
	split(hsv, channels);
	channels[1] += saturation;
	merge(channels, hsv);
	cvtColor(hsv, *src, COLOR_HSV2BGR);
}
void mytrackBarCallback2(int, void*)
{
	Mat dst;
	Mat image = srcImg.clone();
	adjustSaturation(sa, &image);
	image.convertTo(dst, -1, contast * 0.01, light);
	imshow("图像调整", dst);
	result = dst.clone();
}
void CPhotoSystemDlg::Onmakechange()   //图像饱和度、亮度、对比度调整
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
	if (srcImg.empty()) {
		// 图像加载失败，显示错误消息
		MessageBox("无法加载图像文件！", "错误", MB_OK | MB_ICONERROR);
		return;
	}
	Mat image = srcImg;
	imshow("原图", image);
	moveWindow("原图", (1920 - srcImg.cols) / 2, (1080 - srcImg.rows) / 2);
	namedWindow("图像调整", WINDOW_AUTOSIZE);
	createTrackbar("亮度", "图像调整", &light, light_max, mytrackBarCallback2);
	setTrackbarMin("亮度", "图像调整", -150);
	createTrackbar("对比度", "图像调整", &contast, contastmax, mytrackBarCallback2);
	setTrackbarMin("对比度", "图像调整", -150);
	createTrackbar("饱和度", "图像调整", &sa,maxsa, mytrackBarCallback2);
	setTrackbarMin("饱和度", "图像调整", -150);
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
}
void CPhotoSystemDlg::OnRotate()  //旋转任意角度
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
	float angle;
	imshow("原图", srcImg);
	moveWindow("原图", (1920 - srcImg.cols) / 2, (1080- srcImg.rows) / 2);
	CRotateDialog rotateDlg;
rotate:
	if (rotateDlg.DoModal() == IDOK) {
		angle = rotateDlg.GetAngle();
		RotatedRect rotatedRect = RotatedRect(Point2f(srcImg.cols / 2.0, srcImg.rows / 2.0), srcImg.size(), angle);
		Point2f vertices[4];
		rotatedRect.points(vertices);
		Rect boundingRect = rotatedRect.boundingRect();
		Point2f point1 = vertices[0];
		Point2f point2 = vertices[2];
		Point2f point3 = vertices[1];
		Point2f point4 = vertices[3];
		if ((int)(angle / 90.0f) % 2 == 1|| boundingRect.width>boundingRect.height){
			swap(boundingRect.width, boundingRect.height);
		}
		int canvasWidth = max(boundingRect.width, max(static_cast<int>(point2.x - point1.x), static_cast<int>(point4.x - point3.x)));
		int canvasHeight = max(boundingRect.height, max(static_cast<int>(point2.y - point1.y), static_cast<int>(point4.y - point3.y)));
		Mat canvas(canvasHeight, canvasWidth, srcImg.type(), Scalar(0, 0, 0));
		int offsetX = (canvasWidth - srcImg.cols) / 2;
		int offsetY = (canvasHeight - srcImg.rows) / 2;
		srcImg.copyTo(canvas(Rect(offsetX, offsetY, srcImg.cols, srcImg.rows)));
		Mat rotatedImg;
		Point2f center(canvas.cols / 2.0, canvas.rows / 2.0);
		Mat rotationMat = getRotationMatrix2D(center, angle, 1.0);
		warpAffine(canvas, rotatedImg, rotationMat, canvas.size());
		imshow("旋转后的图像", rotatedImg);

		char key = waitKey(0);
		if (key == 's' || key == 'S') {
			UINT i = MessageBox(_T("是否要保存图像?!"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
			if (i == IDYES) {
				CFileDialog saveDlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT,
					TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);

				if (saveDlg.DoModal() == IDOK) {
					CString savePath = saveDlg.GetPathName();
					imwrite((LPCTSTR)savePath, rotatedImg);
					MessageBox("图像保存成功!", "保存成功", MB_OK);
				}
			}
		}
		else if (key == 'r' || key == 'R') {
			goto rotate; // 跳回到重新接受角度
		}
	}
}
void CPhotoSystemDlg::OnBnClickedRadio8() //音乐1
{
	// TODO: 在此添加控件通知处理程序代码
	PlaySound("1.wav", NULL, SND_FILENAME | SND_ASYNC);
}
void CPhotoSystemDlg::OnBnClickedRadio17() //暂停
{
	// TODO: 在此添加控件通知处理程序代码
	PlaySound(NULL, NULL, 0);
}
void CPhotoSystemDlg::OnBnClickedRadio9() //音乐2
{
	// TODO: 在此添加控件通知处理程序代码
	PlaySound("2.wav", NULL, SND_FILENAME | SND_ASYNC);
}
void CPhotoSystemDlg::OnBnClickedRadio10() //音乐3
{
	// TODO: 在此添加控件通知处理程序代码
	PlaySound("3.wav", NULL, SND_FILENAME | SND_ASYNC);
}
void CPhotoSystemDlg::OnBnClickedRadio11() //音乐4
{
	// TODO: 在此添加控件通知处理程序代码
	PlaySound("4.wav", NULL, SND_FILENAME | SND_ASYNC);
}
void CPhotoSystemDlg::OnBnClickedRadio12() //音乐5
{
	// TODO: 在此添加控件通知处理程序代码
	PlaySound("5.wav", NULL, SND_FILENAME | SND_ASYNC);
}
void CPhotoSystemDlg::OnSymmetry1()   //水平翻转
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
	moveWindow("原图", (1920 - srcImg.cols) / 2, (1080 - srcImg.rows) / 2);
	Mat flipped;
	flip(srcImg, flipped, 1);
	imshow("水平翻转", flipped);
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
				imwrite((LPCTSTR)savePath, flipped);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}
void CPhotoSystemDlg::OnSymmetry2() //垂直翻转
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
	moveWindow("原图", (1920 - srcImg.cols) / 2, (1080 - srcImg.rows) / 2);
	Mat flipped;
	flip(srcImg, flipped, 0);
	imshow("垂直翻转", flipped);
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
				imwrite((LPCTSTR)savePath, flipped);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}
void CPhotoSystemDlg::OnJunh()   //直方图均衡化
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
	moveWindow("原图", (1920 - srcImg.cols) / 2, (1080 - srcImg.rows) / 2);
	Mat src = srcImg.clone();
	vector<Mat>channels;
	split(src,channels);
	Mat blue, green, red;
	blue = channels.at(0);
	green = channels.at(1);
	red = channels.at(2);
	equalizeHist(blue, blue);
	equalizeHist(green, green);
	equalizeHist(red, red);
	Mat image;
	merge(channels,image);
	imshow("直方图均衡化", image);
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
}
void CPhotoSystemDlg::OnChazhi1()   //最近邻插值缩放
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
	float scale;
	imshow("原图", srcImg);
	moveWindow("原图", (1920 - srcImg.cols) / 2, (1080 - srcImg.rows) / 2);
	CResize resizeDlg;
re:
	if (resizeDlg.DoModal() == IDOK) {
		scale = resizeDlg.Getsize();
		Mat resizeImg;
		resize(srcImg, resizeImg,Size(srcImg.cols * scale, srcImg.rows * scale),0,0,INTER_NEAREST);
		imshow("缩放后的图像", resizeImg);
		char key = waitKey(0);
		if (key == 's' || key == 'S') {
			UINT i = MessageBox(_T("是否要保存图像?!"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
			if (i == IDYES) {
				CFileDialog saveDlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT,
					TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);

				if (saveDlg.DoModal() == IDOK) {
					CString savePath = saveDlg.GetPathName();
					imwrite((LPCTSTR)savePath,resizeImg);
					MessageBox("图像保存成功!", "保存成功", MB_OK);
				}
			}
		}
		else if (key == 'r' || key == 'R') {
			goto re; // 跳回到重新接受比例
		}
	}
}
void CPhotoSystemDlg::OnChazhi2()  //双插值
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
	float scale;
	imshow("原图", srcImg);
	moveWindow("原图", (1920 - srcImg.cols) / 2, (1080 - srcImg.rows) / 2);
	CResize resizeDlg;
re:
	if (resizeDlg.DoModal() == IDOK) {
		scale = resizeDlg.Getsize();
		Mat resizeImg;
		resize(srcImg, resizeImg, Size(srcImg.cols * scale, srcImg.rows * scale), 0, 0, INTER_LINEAR);
		imshow("缩放后的图像", resizeImg);
		char key = waitKey(0);
		if (key == 's' || key == 'S') {
			UINT i = MessageBox(_T("是否要保存图像?!"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
			if (i == IDYES) {
				CFileDialog saveDlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT,
					TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);

				if (saveDlg.DoModal() == IDOK) {
					CString savePath = saveDlg.GetPathName();
					imwrite((LPCTSTR)savePath, resizeImg);
					MessageBox("图像保存成功!", "保存成功", MB_OK);
				}
			}
		}
		else if (key == 'r' || key == 'R') {
			goto re; // 跳回到重新接受比例
		}
	}
}
void CPhotoSystemDlg::OnChazhi4()  //金字塔
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
	Mat gsrc;
	Mat lsrc;
	pyrDown(srcImg, gsrc);
	pyrUp(srcImg, lsrc);
	imshow("原图", srcImg);
	imshow("gsrc", gsrc);
	imshow("lsrc", lsrc);
}
void CPhotoSystemDlg::OnChazhi3() //双立方插值
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
	float scale;
	imshow("原图", srcImg);
	moveWindow("原图", (1920 - srcImg.cols) / 2, (1080 - srcImg.rows) / 2);
	CResize resizeDlg;
re:
	if (resizeDlg.DoModal() == IDOK) {
		scale = resizeDlg.Getsize();
		Mat resizeImg;
		resize(srcImg, resizeImg, Size(srcImg.cols * scale, srcImg.rows * scale), 0, 0,INTER_CUBIC);
		imshow("缩放后的图像", resizeImg);
		char key = waitKey(0);
		if (key == 's' || key == 'S') {
			UINT i = MessageBox(_T("是否要保存图像?!"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
			if (i == IDYES) {
				CFileDialog saveDlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT,
					TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);

				if (saveDlg.DoModal() == IDOK) {
					CString savePath = saveDlg.GetPathName();
					imwrite((LPCTSTR)savePath, resizeImg);
					MessageBox("图像保存成功!", "保存成功", MB_OK);
				}
			}
		}
		else if (key == 'r' || key == 'R') {
			goto re; // 跳回到重新接受比例
		}
	}
}
void CPhotoSystemDlg::OnChazhi5() //像素重采样
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
	float scale;
	imshow("原图", srcImg);
	moveWindow("原图", (1920 - srcImg.cols) / 2, (1080 - srcImg.rows) / 2);
	CResize resizeDlg;
re:
	if (resizeDlg.DoModal() == IDOK) {
		scale = resizeDlg.Getsize();
		Mat resizeImg;
		resize(srcImg, resizeImg, Size(srcImg.cols * scale, srcImg.rows * scale), 0, 0, INTER_AREA);
		imshow("缩放后的图像", resizeImg);
		char key = waitKey(0);
		if (key == 's' || key == 'S') {
			UINT i = MessageBox(_T("是否要保存图像?!"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
			if (i == IDYES) {
				CFileDialog saveDlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT,
					TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);

				if (saveDlg.DoModal() == IDOK) {
					CString savePath = saveDlg.GetPathName();
					imwrite((LPCTSTR)savePath, resizeImg);
					MessageBox("图像保存成功!", "保存成功", MB_OK);
				}
			}
		}
		else if (key == 'r' || key == 'R') {
			goto re; // 跳回到重新接受比例
		}
	}
}
void CPhotoSystemDlg::OnMeihua1() //加框
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
	Mat srcImg1 = imread((LPCTSTR)m_path, 1);
	imshow("原图", srcImg1);

	CFileDialog edlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
		TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);
	if (edlg.DoModal() == IDOK)
	{
		m_path = edlg.GetPathName();
	}
	else
		return;
	Mat srcImg2 = imread((LPCTSTR)m_path, 1);
	imshow("原图2", srcImg2);

	resize(srcImg2, srcImg2, srcImg1.size()); // 调整第二张图像大小与第一张图像一致

	Mat result = srcImg1.clone();

	// 循环遍历每个像素，如果第二张图像对应位置的像素不是白色，则将该像素值赋给结果图像
	for (int y = 0; y < srcImg1.rows; ++y) {
		for (int x = 0; x < srcImg1.cols; ++x) {
			if (srcImg2.at<Vec3b>(y, x) != Vec3b(255, 255, 255)) {
				result.at<Vec3b>(y, x) = srcImg2.at<Vec3b>(y, x);
			}
		}
	}

	imshow("加框后的图像", result);
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
				imwrite((LPCTSTR)savePath,result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}
void CPhotoSystemDlg::OnMeihua5() //融合
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
	imshow("原图1", srcImg);
	CFileDialog edlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
		TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);
	if (edlg.DoModal() == IDOK)
	{
		m_path = edlg.GetPathName();
	}
	else
		return;
	Mat src = imread((LPCTSTR)m_path, 1);
	imshow("原图2", src);
	Mat img1, img2;
	if (srcImg.size() != src.size())
	{
		resize(srcImg, img1, src.size(), 0, 0, INTER_LINEAR);
		img2 = src.clone();
	}
	else
	{
		img1 = srcImg.clone();
		img2 = src.clone();
	}

	double alpha = 0.7; // 第一张图像的权重
	double beta = 0.3;  // 第二张图像的权重
	double gamma = 0;   // 常数值（可选，通常设为0）
	Mat result;
	addWeighted(img1, alpha, img2, beta, gamma, result);
	imshow("融合后的图片", result);
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
				imwrite((LPCTSTR)savePath,result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}
void CPhotoSystemDlg::OnMeihua2() //拼图
{
	vector<Mat> oddRowImages;  // 用于存储奇数编号图片
	vector<Mat> evenRowImages; // 用于存储偶数编号图片

	int i = 1;
	while (1)
	{
		CString m_path;
		CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
			TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);
		if (dlg.DoModal() == IDOK)
		{
			m_path = dlg.GetPathName();
		}
		else
			break;

		Mat srcImg = imread((LPCTSTR)m_path, 1);
		if (i % 2 == 1) // 如果是奇数编号图片
		{
			oddRowImages.push_back(srcImg);
		}
		else // 如果是偶数编号图片
		{
			evenRowImages.push_back(srcImg);
		}

		imshow("原图" + to_string(i), srcImg); // 显示加载的图片

		int result = MessageBox("是否继续添加图片？", "提示", MB_YESNO | MB_ICONQUESTION);
		if (result == IDNO)
			break;

		i++;
	}

	// 计算拼接后图片的大小
	int totalHeight = 0;
	int totalWidth = 0;
	int sumHeight = 0;
	int sumWidth = 0;
	for (const auto& img : oddRowImages)
	{
		totalHeight=max(img.rows,totalHeight);
		totalWidth+=img.cols;
	}
	for (const auto& img : evenRowImages)
	{
		sumHeight=max(img.rows,sumHeight);
		sumWidth += img.cols;
	}
	totalHeight += sumHeight;
	totalWidth = max(totalWidth, sumWidth);

	Mat mergedImage(totalHeight, totalWidth, oddRowImages[0].type(), Scalar(255, 255, 255));

	// 将奇数编号图片拼接到拼接后的图像中
	int xOdd = 0;
	for (const auto& img : oddRowImages)
	{
		Rect roi(xOdd, 0, img.cols, img.rows);
		Mat targetROI = mergedImage(roi);
		img.copyTo(targetROI, img != Scalar(255, 255, 255)); // 覆盖非白色部分
		xOdd += img.cols;
	}

	// 将偶数编号图片拼接到拼接后的图像中
	int xEven = 0;
	int yEven = oddRowImages[0].rows; // 偶数编号图片应该位于奇数编号图片的下方
	for (const auto& img : evenRowImages)
	{
		Rect roi(xEven, yEven, img.cols, img.rows);
		Mat targetROI = mergedImage(roi);
		img.copyTo(targetROI, img != Scalar(255, 255, 255));
		xEven += img.cols;
	}

	imshow("拼接后的图像", mergedImage);
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
				imwrite((LPCTSTR)savePath, mergedImage);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
	waitKey(0);
}
Mat guidedFilter(Mat& srcMat, Mat& guidedMat, int radius, double eps) //背景虚化
{
	srcMat.convertTo(srcMat, CV_64FC1);
	guidedMat.convertTo(guidedMat, CV_64FC1);
	// 计算均值
	Mat mean_p, mean_I, mean_Ip, mean_II;
	boxFilter(srcMat, mean_p, CV_64FC1, Size(radius, radius));                      // 生成待滤波图像均值mean_p 
	boxFilter(guidedMat, mean_I, CV_64FC1, Size(radius, radius));                   // 生成引导图像均值mean_I   
	boxFilter(srcMat.mul(guidedMat), mean_Ip, CV_64FC1, Size(radius, radius));      // 生成互相关均值mean_Ip
	boxFilter(guidedMat.mul(guidedMat), mean_II, CV_64FC1, Size(radius, radius));   // 生成引导图像自相关均值mean_II
	// 计算相关系数、Ip的协方差cov和I的方差var
	Mat cov_Ip = mean_Ip - mean_I.mul(mean_p);
	Mat var_I = mean_II - mean_I.mul(mean_I);
	// 计算参数系数a、b
	Mat a = cov_Ip / (var_I + eps);
	Mat b = mean_p - a.mul(mean_I);
	// 计算系数a、b的均值
	Mat mean_a, mean_b;
	boxFilter(a, mean_a, CV_64FC1, Size(radius, radius));
	boxFilter(b, mean_b, CV_64FC1, Size(radius, radius));
	// 生成输出矩阵
	Mat dstImage = mean_a.mul(srcMat) + mean_b;
	return dstImage;
}
void CPhotoSystemDlg::OnMeihua3() //背景虚化
{
	// TODO: 在此添加命令处理程序代码
	Mat resultMat;
	Mat vSrcImage[3], vResultImage[3];
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
		TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);
	CString m_path;
	if (dlg.DoModal() == IDOK)
	{
		m_path = dlg.GetPathName();
	}
	else
		return;
	Mat srcImage = imread((LPCTSTR)m_path, 1);
	imshow("原图1", srcImage);
	split(srcImage, vSrcImage);
	for (int i = 0; i < 3; i++)
	{
		Mat tempImage;
		vSrcImage[i].convertTo(tempImage, CV_64FC1, 1.0 / 255.0);
		Mat cloneImage = tempImage.clone();
		Mat resultImage = guidedFilter(tempImage, cloneImage, 5, 0.3);
		vResultImage[i] = resultImage;
	}
	merge(vResultImage, 3, resultMat);
	imshow("背景虚化特效", resultMat);
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
				imwrite((LPCTSTR)savePath,resultMat);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
	waitKey(0);
}
void CPhotoSystemDlg::OnMeihua4() //浮雕
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
	Mat src = imread((LPCTSTR)m_path, 1);
	imshow("原图", src);
	CV_Assert(src.channels() == 3);
	int row = src.rows;
	int col = src.cols;
	cv::Mat temp = src.clone();
	for (int i = 1; i < row - 1; ++i)
	{
		uchar* s1 = src.ptr<uchar>(i - 1);
		uchar* s2 = src.ptr<uchar>(i + 1);
		uchar* t = temp.ptr<uchar>(i);
		for (int j = 1; j < col - 1; ++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				int RGB = s1[3 * (j - 1) + k] - s2[3 * (j + 1) + k] + 128;
				if (RGB < 0)RGB = 0;
				if (RGB > 255)RGB = 255;
				t[3 * j + k] = (uchar)RGB;
			}
		}
	}
	imshow("浮雕", temp);
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
				imwrite((LPCTSTR)savePath, temp);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}
void CalcCorners(const Mat& H, const Mat& src)  //特征提取
{
	double v2[] = { 0, 0, 1 };//左上角
	double v1[3];//变换后的坐标值
	Mat V2 = Mat(3, 1, CV_64FC1, v2);  //列向量
	Mat V1 = Mat(3, 1, CV_64FC1, v1);  //列向量

	V1 = H * V2;
	//左上角(0,0,1)
	cout << "V2: " << V2 << endl;
	cout << "V1: " << V1 << endl;
	corners.left_top.x = v1[0] / v1[2];
	corners.left_top.y = v1[1] / v1[2];

	//左下角(0,src.rows,1)
	v2[0] = 0;
	v2[1] = src.rows;
	v2[2] = 1;
	V2 = Mat(3, 1, CV_64FC1, v2);  //列向量
	V1 = Mat(3, 1, CV_64FC1, v1);  //列向量
	V1 = H * V2;
	corners.left_bottom.x = v1[0] / v1[2];
	corners.left_bottom.y = v1[1] / v1[2];

	//右上角(src.cols,0,1)
	v2[0] = src.cols;
	v2[1] = 0;
	v2[2] = 1;
	V2 = Mat(3, 1, CV_64FC1, v2);  //列向量
	V1 = Mat(3, 1, CV_64FC1, v1);  //列向量
	V1 = H * V2;
	corners.right_top.x = v1[0] / v1[2];
	corners.right_top.y = v1[1] / v1[2];

	//右下角(src.cols,src.rows,1)
	v2[0] = src.cols;
	v2[1] = src.rows;
	v2[2] = 1;
	V2 = Mat(3, 1, CV_64FC1, v2);  //列向量
	V1 = Mat(3, 1, CV_64FC1, v1);  //列向量
	V1 = H * V2;
	corners.right_bottom.x = v1[0] / v1[2];
	corners.right_bottom.y = v1[1] / v1[2];

}
void OptimizeSeam(Mat& img1, Mat& trans, Mat& dst) //特征提取
{
	int start = MIN(corners.left_top.x, corners.left_bottom.x);//开始位置，即重叠区域的左边界

	double processWidth = img1.cols - start;//重叠区域的宽度
	int rows = dst.rows;
	int cols = img1.cols; //注意，是列数*通道数
	double alpha = 1;//img1中像素的权重
	for (int i = 0; i < rows; i++)
	{
		uchar* p = img1.ptr<uchar>(i);  //获取第i行的首地址
		uchar* t = trans.ptr<uchar>(i);
		uchar* d = dst.ptr<uchar>(i);
		for (int j = start; j < cols; j++)
		{
			//如果遇到图像trans中无像素的黑点，则完全拷贝img1中的数据
			if (t[j * 3] == 0 && t[j * 3 + 1] == 0 && t[j * 3 + 2] == 0)
			{
				alpha = 1;
			}
			else
			{
				//img1中像素的权重，与当前处理点距重叠区域左边界的距离成正比，实验证明，这种方法确实好
				alpha = (processWidth - (j - start)) / processWidth;
			}

			d[j * 3] = p[j * 3] * alpha + t[j * 3] * (1 - alpha);
			d[j * 3 + 1] = p[j * 3 + 1] * alpha + t[j * 3 + 1] * (1 - alpha);
			d[j * 3 + 2] = p[j * 3 + 2] * alpha + t[j * 3 + 2] * (1 - alpha);

		}
	}

}
void CPhotoSystemDlg::OnMeihua6() //图像拼接
{
	// TODO: 在此添加命令处理程序代码
	Mat left, right;
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
		TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);
	CString m_path;
	if (dlg.DoModal() == IDOK)
	{
		m_path = dlg.GetPathName();
	}
	else
		return;
	left = imread((LPCTSTR)m_path, 1);
	imshow("原图1", left);
	CFileDialog edlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
		TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);
	if (edlg.DoModal() == IDOK)
	{
		m_path = edlg.GetPathName();
	}
	else
		return;
	right = imread((LPCTSTR)m_path, 1);
	imshow("原图2", right);
	Ptr<SURF>surf;
	surf = SURF::create(800);
	BFMatcher matcher;
	vector<KeyPoint>key1, key2;
	Mat c, d;
	surf->detectAndCompute(left, Mat(), key2, d);
	surf->detectAndCompute(right, Mat(), key1, c);
	//特征点对比，保存下来
	vector<DMatch>matches;//DMatch 点和点之间的关系
	//使用暴力匹配器匹配特征点，找到存来
	matcher.match(d, c, matches);

	//排序 从小到大
	sort(matches.begin(), matches.end());

	//保留最优的特征点对象
	vector<DMatch>good_matches;//最优

	//设置比例
	int ptrPoint = std::min(50, (int)(matches.size() * 0.15));

	for (int i = 0; i < ptrPoint; i++)
	{
		good_matches.push_back(matches[i]);
	}

	//最佳匹配的特征点连成线
	Mat outimg;

	drawMatches(left, key2, right, key1, good_matches, outimg,
		Scalar::all(-1), Scalar::all(-1),
		vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
	imshow("outimg", outimg);

	//特征点配准
	vector<Point2f>imagepoint1, imagepoint2;

	for (int i = 0; i < good_matches.size(); i++)
	{
		imagepoint1.push_back(key1[good_matches[i].trainIdx].pt);
		imagepoint2.push_back(key2[good_matches[i].queryIdx].pt);
	}

	//透视转换
	Mat homo = findHomography(imagepoint1, imagepoint2, RANSAC);


	//四个顶点坐标的转换计算
	CalcCorners(homo, right);

	Mat imageTranForm;
	warpPerspective(right, imageTranForm, homo,
		Size(MAX(corners.right_top.x,
			corners.right_bottom.x),
			left.rows));


	//创建拼接后的图，计算图的大小
	int dst_width = imageTranForm.cols;//获取最右点为拼接图长度
	int dst_height = left.rows;

	Mat dst(dst_height, dst_width, CV_8UC3);
	dst.setTo(0);

	imageTranForm.copyTo(dst(Rect(0, 0, imageTranForm.cols, imageTranForm.rows)));
	left.copyTo(dst(Rect(0, 0, left.cols, left.rows)));

	//优化拼接，主要目的去除黑边
	OptimizeSeam(left, imageTranForm, dst);

	imshow("拼接后的图", dst);
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
				imwrite((LPCTSTR)savePath, dst);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
	waitKey(0);
}
Mat upscaleImage(Mat img, string modelName, string modelPath, int scale) //模型使用
{
	DnnSuperResImpl sr;
	sr.readModel(modelPath);
	sr.setModel(modelName, scale);
	// 输出图片
	Mat outputImage;
	sr.upsample(img, outputImage);
	return outputImage;
}
void CPhotoSystemDlg::OnEdsrX2()  //EDSR_X2
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
	string path = "models//EDSR_x2.pb";
	string modelName = "edsr";
	int scale = 2;
	Mat result = upscaleImage(srcImg, modelName, path, scale);
	Mat resized;
	resize(srcImg, resized, Size(), scale, scale);
	imshow("EDSR_x2", result);
	imshow("Opencv Change", resized);
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
}
void CPhotoSystemDlg::OnEdsrX3() //EDSR_X3
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
	string path = "models//EDSR_x3.pb";
	string modelName = "edsr";
	int scale = 3;
	Mat result = upscaleImage(srcImg, modelName, path, scale);
	Mat resized;
	resize(srcImg, resized, Size(), scale, scale);
	imshow("EDSR_x3", result);
	imshow("Opencv Change", resized);
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
}
void CPhotoSystemDlg::OnEdsrX4() //EDSR_X4
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
	string path = "models//EDSR_x4.pb";
	string modelName = "edsr";
	int scale = 4;
	Mat result = upscaleImage(srcImg, modelName, path, scale);
	Mat resized;
	resize(srcImg, resized, Size(), scale, scale);
	imshow("EDSR_x4", result);
	imshow("Opencv Change", resized);
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
}
void CPhotoSystemDlg::OnEspcnX2() //ESPCN_X2
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
	string path = "models//ESPCN_x2.pb";
	string modelName = "espcn";
	int scale = 2;
	Mat result = upscaleImage(srcImg, modelName, path, scale);
	Mat resized;
	resize(srcImg, resized, Size(), scale, scale);
	imshow("ESPCN_x2", result);
	imshow("Opencv Change", resized);
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
}
void CPhotoSystemDlg::OnEspcnX3() //ESPCN_X3
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
	string path = "models//ESPCN_x3.pb";
	string modelName = "espcn";
	int scale = 3;
	Mat result = upscaleImage(srcImg, modelName, path, scale);
	Mat resized;
	resize(srcImg, resized, Size(), scale, scale);
	imshow("ESPCN_x3", result);
	imshow("Opencv Change", resized);
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
}
void CAboutDlg::OnEspcnX4() { return; }
void CPhotoSystemDlg::OnFsrcnnX2() //FSRCNN_X2
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
	string path = "models//FSRCNN_x2.pb";
	string modelName = "fsrcnn";
	int scale = 2;
	Mat result = upscaleImage(srcImg, modelName, path, scale);
	Mat resized;
	resize(srcImg, resized, Size(), scale, scale);
	imshow("FSRCNN_x2", result);
	imshow("Opencv Change", resized);
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
}
void CPhotoSystemDlg::OnEspcnX4() //ESPCN_X4
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
	string path = "models//ESPCN_x4.pb";
	string modelName = "espcn";
	int scale = 4;
	Mat result = upscaleImage(srcImg, modelName, path, scale);
	Mat resized;
	resize(srcImg, resized, Size(), scale, scale);
	imshow("ESPCN_x4", result);
	imshow("Opencv Change", resized);
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
}
void CPhotoSystemDlg::OnFsrcnnX3() //FSRCNN_X3
{
	// TODO: 在此添加命令处理程序代码
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
	string path = "models//FSRCNN_x3.pb";
	string modelName = "fsrcnn";
	int scale = 3;
	Mat result = upscaleImage(srcImg, modelName, path, scale);
	Mat resized;
	resize(srcImg, resized, Size(), scale, scale);
	imshow("FSRCNN_x3", result);
	imshow("Opencv Change", resized);
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
}
void CPhotoSystemDlg::OnFsrcnnX4() //FSRCNN_X4
{
	// TODO: 在此添加命令处理程序代码
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
	string path = "models//FSRCNN_x4.pb";
	string modelName = "fsrcnn";
	int scale = 4;
	Mat result = upscaleImage(srcImg, modelName, path, scale);
	Mat resized;
	resize(srcImg, resized, Size(), scale, scale);
	imshow("FSRCNN_x4", result);
	imshow("Opencv Change", resized);
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
}
void CPhotoSystemDlg::OnLapsrnX2() //LAPSRN_X2
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
	string path = "models//LapSRN_x2.pb";
	string modelName = "lapsrn";
	int scale = 2;
	Mat result = upscaleImage(srcImg, modelName, path, scale);
	Mat resized;
	resize(srcImg, resized, Size(), scale, scale);
	imshow("LapSRN_x2", result);
	imshow("Opencv Change", resized);
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
}
void CPhotoSystemDlg::OnLapsrnX4() //LAPSRN_X4
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
	string path = "models//LapSRN_x4.pb";
	string modelName = "lapsrn";
	int scale = 4;
	Mat result = upscaleImage(srcImg, modelName, path, scale);
	Mat resized;
	resize(srcImg, resized, Size(), scale, scale);
	imshow("LapSRN_x4", result);
	imshow("Opencv Change", resized);
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
}
void CPhotoSystemDlg::OnLapsrnX8() //LAPSRN_X8
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
	string path = "models//LapSRN_x8.pb";
	string modelName = "lapsrn";
	int scale = 8;
	Mat result = upscaleImage(srcImg, modelName, path, scale);
	Mat resized;
	resize(srcImg, resized, Size(), scale, scale);
	imshow("LapSRN_x8", result);
	imshow("Opencv Change", resized);
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
}
void CPhotoSystemDlg::OnLapulasi() //拉普拉斯算子 图像增强
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
	Mat kernel = (Mat_<int>(3, 3) << 0, -1, 0, 0, 5, 0, 0, -1, 0);
	filter2D(srcImg, result, CV_8UC3, kernel);
	imshow("拉普拉斯增强", result);
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
}
void CPhotoSystemDlg::OnLog() //LOG变换增强
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
	Mat imageLog(srcImg.size(), CV_32FC3);
	for (int i = 0; i < srcImg.rows; i++)
	{
		for (int j = 0; j < srcImg.cols; j++)
		{
			imageLog.at<Vec3f>(i, j)[0] = log(1 + srcImg.at<Vec3b>(i, j)[0]);
			imageLog.at<Vec3f>(i, j)[1] = log(1 + srcImg.at<Vec3b>(i, j)[1]);
			imageLog.at<Vec3f>(i, j)[2] = log(1 + srcImg.at<Vec3b>(i, j)[2]);
		}
	}  
	normalize(imageLog, imageLog, 0, 255, NORM_MINMAX);  
	convertScaleAbs(imageLog, imageLog);
	imshow("LOG变换", imageLog);
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
				imwrite((LPCTSTR)savePath, imageLog);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}
void CPhotoSystemDlg::OnGrama() //伽马增强
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
	Mat imageGamma(srcImg.size(), CV_32FC3);
	for (int i = 0; i < srcImg.rows; i++)
	{
		for (int j = 0; j < srcImg.cols; j++)
		{
			imageGamma.at<Vec3f>(i, j)[0] = (srcImg.at<Vec3b>(i, j)[0]) * (srcImg.at<Vec3b>(i, j)[0]) * (srcImg.at<Vec3b>(i, j)[0]);
			imageGamma.at<Vec3f>(i, j)[1] = (srcImg.at<Vec3b>(i, j)[1]) * (srcImg.at<Vec3b>(i, j)[1]) * (srcImg.at<Vec3b>(i, j)[1]);
			imageGamma.at<Vec3f>(i, j)[2] = (srcImg.at<Vec3b>(i, j)[2]) * (srcImg.at<Vec3b>(i, j)[2]) * (srcImg.at<Vec3b>(i, j)[2]);
		}
	}
	normalize(imageGamma, imageGamma, 0, 255, NORM_MINMAX);
	convertScaleAbs(imageGamma, imageGamma);
	imshow("伽马变换图像增强", imageGamma);
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
				imwrite((LPCTSTR)savePath, imageGamma);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}


void CPhotoSystemDlg::Onssim()  //SSIM判定
{
	// TODO: 在此添加命令处理程序代码
	const double C1 = 6.5025, C2 = 58.5225;  //系数常数
	Mat image1, image2;
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
		TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);
	CString m_path;
	if (dlg.DoModal() == IDOK)
	{
		m_path = dlg.GetPathName();
	}
	else
		return;
	image1= imread((LPCTSTR)m_path, 1);
	imshow("原图",image1);

	CFileDialog edlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
		TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);
	if (edlg.DoModal() == IDOK)
	{
		m_path = edlg.GetPathName();
	}
	else
		return;
	image2 = imread((LPCTSTR)m_path, 1);
	imshow("原图2", image2);

	Mat src1, src2;
	image1.convertTo(src1, CV_32F);
	image2.convertTo(src2, CV_32F);
	Mat src1_2 = src1.mul(src1);
	Mat src2_2 = src2.mul(src2);
	Mat use = src1.mul(src2);
	Mat mu1, mu2;
	GaussianBlur(src1, mu1, Size(11, 11), 1.5);
	GaussianBlur(src2, mu2, Size(11, 11), 1.5);
	Mat mu1_2 = mu1.mul(mu1);
	Mat mu2_2 = mu2.mul(mu2);
	Mat mu1_mu2 = mu1.mul(mu2);
	Mat sigma1_2, sigam2_2, sigam12;
	GaussianBlur(src1_2, sigma1_2, Size(11, 11), 1.5);
	sigma1_2 -= mu1_2;

	GaussianBlur(src2_2, sigam2_2, Size(11, 11), 1.5);
	sigam2_2 -= mu2_2;

	GaussianBlur(use, sigam12, Size(11, 11), 1.5);
	sigam12 -= mu1_mu2;
	Mat t1, t2, t3;
	t1 = 2 * mu1_mu2 + C1;
	t2 = 2 * sigam12 + C2;
	t3 = t1.mul(t2);

	t1 = mu1_2 + mu2_2 + C1;
	t2 = sigma1_2 + sigam2_2 + C2;
	t1 = t1.mul(t2);

	Mat ssim_map;
	divide(t3, t1, ssim_map);
	Scalar mssim = mean(ssim_map);

	double ssim = (mssim.val[0] + mssim.val[1] + mssim.val[2]) / 3;

	namedWindow("图像相似度为: "+to_string(ssim),1);
	resizeWindow("图像相似度为: " + to_string(ssim), 500, 10);
}


void CPhotoSystemDlg::OnPsnr()  //PSNR判定
{
	// TODO: 在此添加命令处理程序代码
	Mat image1, image2;
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
		TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);
	CString m_path;
	if (dlg.DoModal() == IDOK)
	{
		m_path = dlg.GetPathName();
	}
	else
		return;
	image1 = imread((LPCTSTR)m_path, 1);
	imshow("原图", image1);

	CFileDialog edlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
		TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);
	if (edlg.DoModal() == IDOK)
	{
		m_path = edlg.GetPathName();
	}
	else
		return;
	image2 = imread((LPCTSTR)m_path, 1);
	imshow("原图2", image2);
	Mat result;
	absdiff(image1, image2, result);
	result.convertTo(result, CV_32F);
	result = result.mul(result);
	Scalar s = sum(result);
	double sse = s.val[0] + s.val[1] + s.val[2];
	double psnr;
	if (sse <= 1e-10) psnr = 0;
	else
	{
		double mse = sse / (double)(image1.channels() * image1.total());
		psnr = 10.0 * log10((255 * 255) / mse);
	}
	namedWindow("图像差异度为: " + to_string(psnr), 1);
	resizeWindow("图像差异度为: " + to_string(psnr), 500, 10);
}


void CPhotoSystemDlg::OnBnClickedRadio13()
{
	// TODO: 在此添加控件通知处理程序代码
	PlaySound("6.wav", NULL, SND_FILENAME | SND_ASYNC);
}


void CPhotoSystemDlg::OnBnClickedRadio14()
{
	// TODO: 在此添加控件通知处理程序代码
	PlaySound("7.wav", NULL, SND_FILENAME | SND_ASYNC);
}


void CPhotoSystemDlg::OnBnClickedRadio15()
{
	// TODO: 在此添加控件通知处理程序代码
	PlaySound("8.wav", NULL, SND_FILENAME | SND_ASYNC);
}


void CPhotoSystemDlg::OnBnClickedRadio16()
{
	// TODO: 在此添加控件通知处理程序代码
	PlaySound("9.wav", NULL, SND_FILENAME | SND_ASYNC);
}

Mat img, inpaintMask, res;
Point prevPt(-1, -1);
static void onMouse(int event, int x, int y, int flags, void*)
{
	if (event == EVENT_LBUTTONUP || !(flags & EVENT_FLAG_LBUTTON))
		prevPt = Point(-1, -1);
	else if (event == EVENT_LBUTTONDOWN)
		prevPt = Point(x, y);
	else if (event == EVENT_MOUSEMOVE && (flags & EVENT_FLAG_LBUTTON))
	{
		Point pt(x, y);
		if (prevPt.x < 0)
			prevPt = pt;
		line(inpaintMask, prevPt, pt, Scalar::all(255), 5, 8, 0);
		line(img, prevPt, pt, Scalar::all(255), 5, 8, 0);
		prevPt = pt;
		imshow("原图", img);
		imshow("遮罩", inpaintMask);
	}
}
void CPhotoSystemDlg::OnFmm()
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
	img = imread((LPCTSTR)m_path, 1);
	Mat image = img;
use:
	img = image.clone();
	imshow("原图", img);
	Mat img_mask;
	img_mask = img.clone();
	inpaintMask = Mat::zeros(img_mask.size(), CV_8U);
    setMouseCallback("原图", onMouse, NULL);
	while(1)
	{
		char ch = (char)waitKey();
		if (ch == 't')
		{
			inpaint(img, inpaintMask, res, 3, INPAINT_TELEA);
			imshow("FMM", res);
		}
		if (ch == 'n')
		{
			inpaint(img, inpaintMask, res, 3, INPAINT_NS);
			imshow("NS", res);
		}
		if (ch == 's' || ch == 'S')
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
					imwrite((LPCTSTR)savePath, res);
					MessageBox("图像保存成功!", "保存成功", MB_OK);
				}
			}
		}
		if (ch == 27)
		{
			break;
		}
		if (ch == 'r') goto use;
	}
}


void CPhotoSystemDlg::Onfengge()
{
	// TODO: 在此添加命令处理程序代码
	string modelBin = "models//starry_night.t7";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
		TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);
	CString m_path;
	if (dlg.DoModal() == IDOK)
	{
		m_path = dlg.GetPathName();
	}
	else
		return;
	img = imread((LPCTSTR)m_path, 1);
	float scale = 1.0;
	cv::Scalar mean{ 103.939, 116.779, 123.68 };
	bool swapRB = false;
	bool crop = false;
	bool useOpenCL = false;
	Net net = dnn::readNetFromTorch(modelBin);
	if (useOpenCL)
		net.setPreferableTarget(DNN_TARGET_OPENCL);

	Mat inputBlob = blobFromImage(img, scale, img.size(), mean, swapRB, crop);

	net.setInput(inputBlob);
	Mat output = net.forward();

	Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 0)) += 103.939;
	Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 1)) += 116.779;
	Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 2)) += 123.68;

	std::vector<cv::Mat> ress;
	imagesFromBlob(output, ress);

	Mat res;
	ress[0].convertTo(res, CV_8UC3);
	imshow("Starry_night", res);

	imshow("原图", img);
}


void CPhotoSystemDlg::Onfengge2()
{
	// TODO: 在此添加命令处理程序代码
	string modelBin = "models//feathers.t7";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
		TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);
	CString m_path;
	if (dlg.DoModal() == IDOK)
	{
		m_path = dlg.GetPathName();
	}
	else
		return;
	img = imread((LPCTSTR)m_path, 1);
	float scale = 1.0;
	cv::Scalar mean{ 103.939, 116.779, 123.68 };
	bool swapRB = false;
	bool crop = false;
	bool useOpenCL = false;
	Net net = dnn::readNetFromTorch(modelBin);
	if (useOpenCL)
		net.setPreferableTarget(DNN_TARGET_OPENCL);

	Mat inputBlob = blobFromImage(img, scale, img.size(), mean, swapRB, crop);

	net.setInput(inputBlob);
	Mat output = net.forward();

	Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 0)) += 103.939;
	Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 1)) += 116.779;
	Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 2)) += 123.68;

	std::vector<cv::Mat> ress;
	imagesFromBlob(output, ress);

	Mat res;
	ress[0].convertTo(res, CV_8UC3);
	imshow("Feathers", res);

	imshow("原图", img);
}


void CPhotoSystemDlg::Onfengge3()
{
	// TODO: 在此添加命令处理程序代码
	string modelBin = "models//candy.t7";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
		TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);
	CString m_path;
	if (dlg.DoModal() == IDOK)
	{
		m_path = dlg.GetPathName();
	}
	else
		return;
	img = imread((LPCTSTR)m_path, 1);
	float scale = 1.0;
	cv::Scalar mean{ 103.939, 116.779, 123.68 };
	bool swapRB = false;
	bool crop = false;
	bool useOpenCL = false;
	Net net = dnn::readNetFromTorch(modelBin);
	if (useOpenCL)
		net.setPreferableTarget(DNN_TARGET_OPENCL);

	Mat inputBlob = blobFromImage(img, scale, img.size(), mean, swapRB, crop);

	net.setInput(inputBlob);
	Mat output = net.forward();

	Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 0)) += 103.939;
	Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 1)) += 116.779;
	Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 2)) += 123.68;

	std::vector<cv::Mat> ress;
	imagesFromBlob(output, ress);

	Mat res;
	ress[0].convertTo(res, CV_8UC3);
	imshow("Candy", res);
	imshow("原图", img);	
}



void CPhotoSystemDlg::Onfengge4()
{
	// TODO: 在此添加命令处理程序代码
	string modelBin = "models//la_muse.t7";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
		TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);
	CString m_path;
	if (dlg.DoModal() == IDOK)
	{
		m_path = dlg.GetPathName();
	}
	else
		return;
	img = imread((LPCTSTR)m_path, 1);
	float scale = 1.0;
	cv::Scalar mean{ 103.939, 116.779, 123.68 };
	bool swapRB = false;
	bool crop = false;
	bool useOpenCL = false;
	Net net = dnn::readNetFromTorch(modelBin);
	if (useOpenCL)
		net.setPreferableTarget(DNN_TARGET_OPENCL);

	Mat inputBlob = blobFromImage(img, scale, img.size(), mean, swapRB, crop);

	net.setInput(inputBlob);
	Mat output = net.forward();

	Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 0)) += 103.939;
	Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 1)) += 116.779;
	Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 2)) += 123.68;

	std::vector<cv::Mat> ress;
	imagesFromBlob(output, ress);

	Mat res;
	ress[0].convertTo(res, CV_8UC3);
	imshow("La_muse", res);
	imshow("原图", img);
}


void CPhotoSystemDlg::Onfengge5()
{
	// TODO: 在此添加命令处理程序代码
	string modelBin = "models//mosaic.t7";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
		TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);
	CString m_path;
	if (dlg.DoModal() == IDOK)
	{
		m_path = dlg.GetPathName();
	}
	else
		return;
	img = imread((LPCTSTR)m_path, 1);
	float scale = 1.0;
	cv::Scalar mean{ 103.939, 116.779, 123.68 };
	bool swapRB = false;
	bool crop = false;
	bool useOpenCL = false;
	Net net = dnn::readNetFromTorch(modelBin);
	if (useOpenCL)
		net.setPreferableTarget(DNN_TARGET_OPENCL);

	Mat inputBlob = blobFromImage(img, scale, img.size(), mean, swapRB, crop);

	net.setInput(inputBlob);
	Mat output = net.forward();

	Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 0)) += 103.939;
	Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 1)) += 116.779;
	Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 2)) += 123.68;

	std::vector<cv::Mat> ress;
	imagesFromBlob(output, ress);

	Mat res;
	ress[0].convertTo(res, CV_8UC3);
	imshow("Mosaic", res);
	imshow("原图", img);
}


void CPhotoSystemDlg::Onfengge6()
{
	// TODO: 在此添加命令处理程序代码
	string modelBin = "models//the_scream.t7";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
		TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);
	CString m_path;
	if (dlg.DoModal() == IDOK)
	{
		m_path = dlg.GetPathName();
	}
	else
		return;
	img = imread((LPCTSTR)m_path, 1);
	float scale = 1.0;
	cv::Scalar mean{ 103.939, 116.779, 123.68 };
	bool swapRB = false;
	bool crop = false;
	bool useOpenCL = false;
	Net net = dnn::readNetFromTorch(modelBin);
	if (useOpenCL)
		net.setPreferableTarget(DNN_TARGET_OPENCL);

	Mat inputBlob = blobFromImage(img, scale, img.size(), mean, swapRB, crop);

	net.setInput(inputBlob);
	Mat output = net.forward();

	Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 0)) += 103.939;
	Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 1)) += 116.779;
	Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 2)) += 123.68;

	std::vector<cv::Mat> ress;
	imagesFromBlob(output, ress);

	Mat res;
	ress[0].convertTo(res, CV_8UC3);
	imshow("The_scream", res);
	imshow("原图", img);
}


void CPhotoSystemDlg::Onfengge7()
{
	// TODO: 在此添加命令处理程序代码
	string modelBin = "models//udnie.t7";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
		TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);
	CString m_path;
	if (dlg.DoModal() == IDOK)
	{
		m_path = dlg.GetPathName();
	}
	else
		return;
	img = imread((LPCTSTR)m_path, 1);
	float scale = 1.0;
	cv::Scalar mean{ 103.939, 116.779, 123.68 };
	bool swapRB = false;
	bool crop = false;
	bool useOpenCL = false;
	Net net = dnn::readNetFromTorch(modelBin);
	if (useOpenCL)
		net.setPreferableTarget(DNN_TARGET_OPENCL);

	Mat inputBlob = blobFromImage(img, scale, img.size(), mean, swapRB, crop);

	net.setInput(inputBlob);
	Mat output = net.forward();

	Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 0)) += 103.939;
	Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 1)) += 116.779;
	Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 2)) += 123.68;

	std::vector<cv::Mat> ress;
	imagesFromBlob(output, ress);

	Mat res;
	ress[0].convertTo(res, CV_8UC3);
	imshow("Udnie", res);
	imshow("原图", img);
	
}


void CPhotoSystemDlg::Onfengge8()
{
	// TODO: 在此添加命令处理程序代码
	string modelBin = "models//the_wave.t7";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
		TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);
	CString m_path;
	if (dlg.DoModal() == IDOK)
	{
		m_path = dlg.GetPathName();
	}
	else
		return;
	img = imread((LPCTSTR)m_path, 1);
	float scale = 1.0;
	cv::Scalar mean{ 103.939, 116.779, 123.68 };
	bool swapRB = false;
	bool crop = false;
	bool useOpenCL = false;
	Net net = dnn::readNetFromTorch(modelBin);
	if (useOpenCL)
		net.setPreferableTarget(DNN_TARGET_OPENCL);

	Mat inputBlob = blobFromImage(img, scale, img.size(), mean, swapRB, crop);

	net.setInput(inputBlob);
	Mat output = net.forward();

	Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 0)) += 103.939;
	Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 1)) += 116.779;
	Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 2)) += 123.68;

	std::vector<cv::Mat> ress;
	imagesFromBlob(output, ress);

	Mat res;
	ress[0].convertTo(res, CV_8UC3);
	imshow("The_wave", res);
	imshow("原图", img);
}


void CPhotoSystemDlg::Onfengge9()
{
	// TODO: 在此添加命令处理程序代码
	string modelBin = "models//composition_vii.t7";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
		TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);
	CString m_path;
	if (dlg.DoModal() == IDOK)
	{
		m_path = dlg.GetPathName();
	}
	else
		return;
	img = imread((LPCTSTR)m_path, 1);
	float scale = 1.0;
	cv::Scalar mean{ 103.939, 116.779, 123.68 };
	bool swapRB = false;
	bool crop = false;
	bool useOpenCL = false;
	Net net = dnn::readNetFromTorch(modelBin);
	if (useOpenCL)
		net.setPreferableTarget(DNN_TARGET_OPENCL);

	Mat inputBlob = blobFromImage(img, scale, img.size(), mean, swapRB, crop);

	net.setInput(inputBlob);
	Mat output = net.forward();

	Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 0)) += 103.939;
	Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 1)) += 116.779;
	Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 2)) += 123.68;

	std::vector<cv::Mat> ress;
	imagesFromBlob(output, ress);

	Mat res;
	ress[0].convertTo(res, CV_8UC3);
	imshow("Composition_vii", res);
	imshow("原图", img);
}
