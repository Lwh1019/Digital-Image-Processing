
// Photo-idfDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "yuzhi.h"
#include "Photo-idf.h"
#include "Photo-idfDlg.h"
#include <bits/stdc++.h> //万能头文件 
#include "pch.h"
#include "framework.h"
#include "afxdialogex.h"
#include <easyx.h>
#include "Fushi.h"
#define M_PI 3.14159265358979323846
#include <playsoundapi.h>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/dnn_superres.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/photo.hpp>
#include <dlib/gui_widgets.h>
#include <dlib/image_transforms.h>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/image_io.h>
#include <dlib/opencv.h> 
#include "camera.h";
#include "fengge.h";
using namespace dlib;
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


// CPhotoidfDlg 对话框



CPhotoidfDlg::CPhotoidfDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PHOTOIDF_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CPhotoidfDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPhotoidfDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_image, &CPhotoidfDlg::Onimage)
	ON_COMMAND(ID_camera, &CPhotoidfDlg::Oncamera)
	ON_COMMAND(ID_fushi, &CPhotoidfDlg::Onfushi)
	ON_COMMAND(ID_pengzhang, &CPhotoidfDlg::Onpengzhang)
	ON_COMMAND(ID_bi, &CPhotoidfDlg::Onbi)
	ON_COMMAND(ID_kai, &CPhotoidfDlg::Onkai)
	ON_COMMAND(ID_jizhong, &CPhotoidfDlg::Onjizhong)
	ON_COMMAND(ID_dingmao, &CPhotoidfDlg::Ondingmao)
	ON_COMMAND(ID_dimao, &CPhotoidfDlg::Ondimao)
	ON_COMMAND(ID_tidu, &CPhotoidfDlg::Ontidu)
	ON_COMMAND(ID_liantong, &CPhotoidfDlg::Onliantong)
	ON_COMMAND(ID_sift, &CPhotoidfDlg::Onsift)
	ON_COMMAND(ID_surf, &CPhotoidfDlg::Onsurf)
	ON_COMMAND(ID_censure, &CPhotoidfDlg::Oncensure)
	ON_COMMAND(ID_orb, &CPhotoidfDlg::Onorb)
	ON_COMMAND(ID_brisk, &CPhotoidfDlg::Onbrisk)
	ON_COMMAND(ID_kaze, &CPhotoidfDlg::Onkaze)
	ON_COMMAND(ID_akaze, &CPhotoidfDlg::Onakaze)
	ON_COMMAND(ID_harris, &CPhotoidfDlg::Onharris)
	ON_COMMAND(ID_shitomasi, &CPhotoidfDlg::Onshitomasi)
	ON_COMMAND(ID_fast, &CPhotoidfDlg::Onfast)
	ON_COMMAND(ID_quyu1, &CPhotoidfDlg::Onquyu1)
	ON_COMMAND(ID_quyu2, &CPhotoidfDlg::Onquyu2)
	ON_COMMAND(ID_roberts, &CPhotoidfDlg::Onroberts)
	ON_COMMAND(ID_sobel, &CPhotoidfDlg::Onsobel)
	ON_COMMAND(ID_prewitt, &CPhotoidfDlg::Onprewitt)
	ON_COMMAND(ID_laplacian, &CPhotoidfDlg::Onlaplacian)
	ON_COMMAND(ID_kirsch, &CPhotoidfDlg::Onkirsch)
	ON_COMMAND(ID_LoG, &CPhotoidfDlg::OnLog)
	ON_COMMAND(ID_canny, &CPhotoidfDlg::Oncanny)
	ON_COMMAND(ID_otsu, &CPhotoidfDlg::Onotsu)
	ON_COMMAND(ID_guding, &CPhotoidfDlg::Onguding)
	ON_COMMAND(ID_zsy, &CPhotoidfDlg::Onzsy)
	ON_COMMAND(ID_double, &CPhotoidfDlg::Ondouble)
	ON_COMMAND(ID_kmean, &CPhotoidfDlg::Onkmean)
	ON_COMMAND(ID_harr, &CPhotoidfDlg::Onharr)
	ON_COMMAND(ID_dnn, &CPhotoidfDlg::Ondnn)
	ON_COMMAND(ID_fenggehua, &CPhotoidfDlg::Onfenggehua)
	ON_COMMAND(ID_mopi, &CPhotoidfDlg::Onmopi)
	ON_COMMAND(ID_kouhong, &CPhotoidfDlg::Onkouhong)
	ON_COMMAND(ID_huanlian, &CPhotoidfDlg::Onhuanlian)
	ON_COMMAND(ID_eye, &CPhotoidfDlg::Oneye)
	ON_COMMAND(ID_big, &CPhotoidfDlg::Onbig)
END_MESSAGE_MAP()


// CPhotoidfDlg 消息处理程序

BOOL CPhotoidfDlg::OnInitDialog()
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

void CPhotoidfDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPhotoidfDlg::OnPaint()
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
HCURSOR CPhotoidfDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


Mat srcImg, result;
void CPhotoidfDlg::Onimage()   //导入图像
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


void CPhotoidfDlg::Oncamera()   //摄像头截取图像
{
	// TODO: 在此添加命令处理程序代码
	VideoCapture cap(0);
	if (!cap.isOpened())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	namedWindow("摄像头预览", WINDOW_AUTOSIZE);
	Mat frame;
	bool saveFrame = false;

	while (true)
	{
		cap >> frame;
		if (frame.empty())
		{
			cerr << "ERROR: 帧为空" << endl;
			break;
		}
		imshow("摄像头预览", frame);
		char key = waitKey(1);
		if (key == 27) 
		{
			break;
		}
		else if (key == 13) 
		{
			srcImg = frame.clone(); 
			break;
		}
	}
	cap.release();
	destroyAllWindows();

	if (!srcImg.empty())
	{
		namedWindow("截取的帧", WINDOW_AUTOSIZE);
		imshow("截取的帧", srcImg);
		char ch=waitKey();
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
					imwrite((LPCTSTR)savePath, srcImg);
					MessageBox("图像保存成功!", "保存成功", MB_OK);
				}
			}
		}
	}
}


void CPhotoidfDlg::Onfushi()  //腐蚀
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	Mat image1, image2;
	cvtColor(srcImg, image1, COLOR_BGR2GRAY);
	threshold(image1, image2, 120, 255, 0);
	imshow("二值图", image2);
	Mat mask = getStructuringElement(0, Size(3, 3));
	Fushi Dlg;
	int pos;
	if (Dlg.DoModal() == IDOK)
	{	
		pos = Dlg.Getsize();
	}
	erode(image2, result, mask, Point(-1, -1), pos);
	imshow("腐蚀", result);
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}


void CPhotoidfDlg::Onpengzhang()  //膨胀
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	Mat image1, image2;
	cvtColor(srcImg, image1, COLOR_BGR2GRAY);
	threshold(image1, image2, 120, 255, 0);
	imshow("二值图", image2);
	Mat mask = getStructuringElement(0, Size(3, 3));
	Fushi Dlg;
	int pos;
	if (Dlg.DoModal() == IDOK)
	{
		pos = Dlg.Getsize();
	}
	dilate(image2, result, mask, Point(-1, -1), pos);
	imshow("膨胀", result);
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}


void CPhotoidfDlg::Onbi()  //闭运算  先膨胀再腐蚀
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	Mat image1, image2;
	cvtColor(srcImg, image1, COLOR_BGR2GRAY);
	threshold(image1, image2, 120, 255, 0);
	imshow("二值图", image2);
	Mat mask = getStructuringElement(0, Size(3, 3));
	Fushi Dlg;
	int pos;
	if (Dlg.DoModal() == IDOK)
	{
		pos = Dlg.Getsize();
	}
	dilate(image2, result, mask, Point(-1, -1), pos);
	erode(image2, result, mask, Point(-1, -1), pos);
	imshow("闭运算", result);
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}


void CPhotoidfDlg::Onkai() //开运算  先腐蚀再膨胀
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	Mat image1, image2;
	cvtColor(srcImg, image1, COLOR_BGR2GRAY);
	threshold(image1, image2, 120, 255, 0);
	imshow("二值图", image2);
	Mat mask = getStructuringElement(0, Size(3, 3));
	Fushi Dlg;
	int pos;
	if (Dlg.DoModal() == IDOK)
	{
		pos = Dlg.Getsize();
	}
	erode(image2, result, mask, Point(-1, -1), pos);
	dilate(image2, result, mask, Point(-1, -1), pos);
	imshow("开运算", result); 
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}


void CPhotoidfDlg::Onjizhong() //击中-击不中变换
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	Mat image1, image2;
	cvtColor(srcImg, image1, COLOR_BGR2GRAY);
	threshold(image1, image2, 120, 255, 0);
	imshow("二值图", image2);
	Mat kernel = (cv::Mat_<float>(3, 3) << 1, 1, -1,
		1, 1, -1,
		1, 1, -1);
	morphologyEx(image2, result, 7, kernel);
	imshow("击中-击不中变换", result);
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}

void CPhotoidfDlg::Ondingmao()  //顶帽变换
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	Mat image1, image2;
	cvtColor(srcImg, image1, COLOR_BGR2GRAY);
	threshold(image1, image2, 120, 255, 0);
	imshow("二值图", image2);
	Mat mask = getStructuringElement(0, Size(5, 5));
	morphologyEx(image2, result, 5, mask);
	imshow("顶帽变换", result);
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}


void CPhotoidfDlg::Ondimao()  //底帽变换
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	Mat image1, image2;
	cvtColor(srcImg, image1, COLOR_BGR2GRAY);
	threshold(image1, image2, 120, 255, 0);
	imshow("二值图", image2);
	Mat mask = getStructuringElement(0, Size(5, 5));
	morphologyEx(image2, result, 6, mask);
	imshow("底帽变换", result);
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}


void CPhotoidfDlg::Ontidu()  //形态学梯度
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	Mat image1, image2;
	cvtColor(srcImg, image1, COLOR_BGR2GRAY);
	threshold(image1, image2, 120, 255, 0);
	imshow("二值图", image2);
	Mat mask = getStructuringElement(0, Size(5, 5));
	morphologyEx(image2, result, 4, mask);
	imshow("形态学梯度", result);
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}


void CPhotoidfDlg::Onliantong()  //提取连通域 并染色
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	Mat image1, image2;
	cvtColor(srcImg, image1, COLOR_BGR2GRAY);
	threshold(image1, image2, 120, 255, 0);
	imshow("二值图", image2);
	int number = connectedComponents(image2, result, 8, CV_16U);
	RNG rng(50);
	std::vector<Vec3b>colors;
	for (int i = 0; i < number; i++)
	{
		Vec3b vec3 = Vec3b(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
		colors.push_back(vec3);
	}
	Mat dst = Mat::zeros(image2.size(), CV_8UC3);
	int w = dst.cols;
	int h = dst.rows;
	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < w; col++)
		{
			int x = result.at<uint16_t>(row, col);
			if (x == 0)
			{
				continue;
			}
			dst.at<Vec3b>(row, col) = colors[x];
		}
	}
	imshow("最终图像", dst);
	result = dst.clone();
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}


void CPhotoidfDlg::Onsift() //SIFT算法(尺度不变特征变换)
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	Ptr<SIFT> detector = SIFT::create();
	std::vector<KeyPoint> keypoints;
	detector->detect(srcImg, keypoints);
	drawKeypoints(srcImg, keypoints, result);
	imshow("SIFT", result);
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}


void CPhotoidfDlg::Onsurf()  //SURF
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	Ptr<SURF> detector = SURF::create(400);
	std::vector<KeyPoint> keypoints;
	detector->detect(srcImg, keypoints);
	drawKeypoints(srcImg, keypoints, result);
	imshow("SURF", result);
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}

 
void CPhotoidfDlg::Oncensure() //类CenSurE
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	Ptr<StarDetector> detector = StarDetector::create(20,20);
	std::vector<KeyPoint> keypoints;
	detector->detect(srcImg, keypoints);
	drawKeypoints(srcImg, keypoints, result);
	imshow("类CenSurE", result);
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}


void CPhotoidfDlg::Onorb()   //ORB
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	Ptr<ORB> detector = ORB::create(2000);
	std::vector<KeyPoint> keypoints;
	detector->detect(srcImg, keypoints);
	drawKeypoints(srcImg, keypoints, result);
	imshow("ORB", result);
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}

 
void CPhotoidfDlg::Onbrisk() //BRISK
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	Ptr<BRISK> detector = BRISK::create();
	std::vector<KeyPoint> keypoints;
	detector->detect(srcImg, keypoints);
	drawKeypoints(srcImg, keypoints, result);
	imshow("BRISK", result);
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}


void CPhotoidfDlg::Onkaze()  //KAZE
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	Ptr<KAZE> detector = KAZE::create();
	std::vector<KeyPoint> keypoints;
	detector->detect(srcImg, keypoints);
	drawKeypoints(srcImg, keypoints, result);
	imshow("KAZE", result);
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}


void CPhotoidfDlg::Onakaze()   //AKAZE
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	Ptr<AKAZE> detector = AKAZE::create();
	std::vector<KeyPoint> keypoints;
	detector->detect(srcImg, keypoints);
	drawKeypoints(srcImg, keypoints, result);
	imshow("AKAZE", result);
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}
void CPhotoidfDlg::Onharris()   //Harris角点
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	int thresh = 100;
	namedWindow("原图");
	imshow("原图", srcImg);
	Mat gray;
	cvtColor(srcImg, gray, COLOR_BGR2GRAY);
	Mat harris;
	cornerHarris(gray, harris, 3, 3, 0.04);
	Mat harrisn;
	normalize(harris, harrisn, 0, 255, NORM_MINMAX);
	Mat image = srcImg.clone();
	for (int i = 0; i < harrisn.rows; i++) {
		for (int j = 0; j < harrisn.cols; j++) {
			if (static_cast<int>(harrisn.at<float>(i, j)) > 50) { // 设定阈值
				circle(image, Point(j, i), 5, Scalar(0, 255, 0), 2);
			}
		}
	}
	imshow("Harris角点",image);
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, image);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}

void CPhotoidfDlg::Onshitomasi()  // Shi-Tomasi 
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	imshow("原图", srcImg);
	Mat gray;
	cvtColor(srcImg, gray, COLOR_BGR2GRAY);
	std::vector<Point2f> corners;
	int maxCorners = 100; // 设定最多检测角点的数量
	double qualityLevel = 0.01; // 角点质量水平
	double minDistance = 10; // 角点之间的最小距离
	goodFeaturesToTrack(gray, corners, maxCorners, qualityLevel, minDistance);
	Mat image = srcImg.clone();
	for (size_t i = 0; i < corners.size(); i++) {
		circle(image, corners[i], 5, Scalar(0, 0, 255), 2);
	}
	imshow("Shi-Tomasi", image);
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, image);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}


void CPhotoidfDlg::Onfast()  //FAST
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	imshow("原图", srcImg);
	Mat gray;
	cvtColor(srcImg, gray, COLOR_BGR2GRAY);
	Mat image = srcImg.clone();
	std::vector<KeyPoint> keypoints;
	Ptr<FastFeatureDetector> detector = FastFeatureDetector::create();
	detector->detect(gray, keypoints);
	drawKeypoints(image, keypoints, result, Scalar(0, 0, 255));
	imshow("FAST", result);
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}
Point seedPoint(-1, -1);
Vec3b seedColor;
void onMouse(int event, int x, int y, int flags, void* userdata)
{
	if (event == EVENT_LBUTTONDOWN) {
		seedPoint = Point(x, y);
		seedColor = ((Mat*)userdata)->at<Vec3b>(seedPoint);
	}
}
void regionGrowing(Mat& inputImage, Mat& outputImage, int seedX, int seedY, int threshold) //区域生长
{
	// 确保种子点在图像内
	if (seedX < 0 || seedY < 0 || seedX >= inputImage.cols || seedY >= inputImage.rows) {
		return;
	}

	outputImage = Mat::zeros(inputImage.size(), CV_8UC1);

	std::vector<std::vector<bool>> visited(inputImage.rows, std::vector<bool>(inputImage.cols, false));  //记录

	std::queue<Point> pixelsQueue;	// 使用队列进行广度优先搜索
	pixelsQueue.push(Point(seedX, seedY));

	Vec3b seedValue = inputImage.at<Vec3b>(seedY, seedX);  //颜色

	while (!pixelsQueue.empty())  //队列处理
	{
		Point currentPixel = pixelsQueue.front();
		pixelsQueue.pop();

		int currentX = currentPixel.x;
		int currentY = currentPixel.y;

		Vec3b currentColor = inputImage.at<Vec3b>(currentY, currentX);

		// 计算当前像素与种子点的颜色差异
		int colorDiff = abs(currentColor[0] - seedColor[0]) + abs(currentColor[1] - seedColor[1]) + abs(currentColor[2] - seedColor[2]);

		if (!visited[currentY][currentX] && colorDiff <= threshold)
		{
			outputImage.at<uchar>(currentY, currentX) = 255;  //区域内的标记成白色
			visited[currentY][currentX] = true;  			// 将当前像素标记为区域中的像素

			for (int i = -1; i <= 1; i++)   //8联通 将相邻像素加入队列
			{
				for (int j = -1; j <= 1; j++)
				{
					int newX = currentX + j;
					int newY = currentY + i;

					if (newX >= 0 && newY >= 0 && newX < inputImage.cols && newY < inputImage.rows && !visited[newY][newX]) {
						pixelsQueue.push(Point(newX, newY));
					}
				}
			}
		}
	}
}
void CPhotoidfDlg::Onquyu1()  // 区域生长：  基于区域灰度差的生长准则和方法
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	imshow("原图", srcImg);
again:
	setMouseCallback("原图", onMouse,&srcImg);
	waitKey(0);
	if (seedPoint.x != -1 && seedPoint.y != -1) {
		int threshold = 10;
		regionGrowing(srcImg, result, seedPoint.x, seedPoint.y, threshold);
		imshow("区域生长", result);
		char ch=waitKey();
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
					imwrite((LPCTSTR)savePath, result);
					MessageBox("图像保存成功!", "保存成功", MB_OK);
				}
			}
		}
		goto again;
	}
}
std::vector<Rect> regions;
Mat calculateHistogram(const Mat& region)  //颜色直方图
{
	std::vector<Mat> bgr_planes;
	split(region, bgr_planes);

	int histSize = 256;
	float range[] = { 0, 256 };
	const float* histRange = { range };

	Mat b_hist, g_hist, r_hist;
	calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, true, false);
	calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, true, false);
	calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, true, false);

	Mat hist;
	hconcat(b_hist, g_hist, hist);
	hconcat(hist, r_hist, hist);

	return hist;
}
double compareHistograms(const Mat& hist1, const Mat& hist2)
{
	return compareHist(hist1, hist2, HISTCMP_BHATTACHARYYA);
}
void regionGrowing2(const Mat& inputImage, Mat& outputImage, const Rect& seedRegion, double threshold)
{
	outputImage = Mat::zeros(inputImage.size(), CV_8UC1);

	std::vector<std::vector<bool>> visited(inputImage.rows, std::vector<bool>(inputImage.cols, false));

	std::queue<Point> pixelsQueue;// 使用队列进行广度优先搜索
	pixelsQueue.push(seedRegion.tl()); // 种子区域的左上角作为起始点

	Mat seedHist = calculateHistogram(inputImage(seedRegion)); 	// 种子点的颜色直方图

	while (!pixelsQueue.empty()) {
		Point currentPixel = pixelsQueue.front();
		pixelsQueue.pop();

		int currentX = currentPixel.x;
		int currentY = currentPixel.y;

		if (!visited[currentY][currentX])
		{
			visited[currentY][currentX] = true;

			Rect currentRegion(currentX, currentY, 1, 1);
			Mat currentHist = calculateHistogram(inputImage(currentRegion)); 			// 当前像素的颜色直方图

			double similarity = compareHistograms(seedHist, currentHist);
			if (similarity <= threshold) {
				outputImage.at<uchar>(currentY, currentX) = 255;				// 将当前像素标记为区域中的像素

				for (int i = -1; i <= 1; i++)  //相邻像素
				{
					for (int j = -1; j <= 1; j++)
					{
						int newX = currentX + j;
						int newY = currentY + i;

						if (newX >= 0 && newY >= 0 && newX < inputImage.cols && newY < inputImage.rows && !visited[newY][newX]) {
							pixelsQueue.push(Point(newX, newY));
						}
					}
				}
			}
		}
	}
}

void CPhotoidfDlg::Onquyu2()    //基于区域灰度分布统计
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	imshow("原图", srcImg);
	Size regionSize(10, 10); //将图像分成互不重叠的小区域
	for (int y = 0; y < srcImg.rows; y += regionSize.height)
	{
		for (int x = 0; x < srcImg.cols; x += regionSize.width)
		{
			regions.push_back(Rect(x, y, min(regionSize.width, srcImg.cols - x), min(regionSize.height, srcImg.rows - y)));
		}
	}
again:
	setMouseCallback("原图", onMouse, &srcImg);
	waitKey(0);
	if (seedPoint.x != -1 && seedPoint.y != -1)
	{
		Rect seedRegion;
		for (const auto& region : regions)
		{
			if (region.contains(seedPoint))
			{
				seedRegion = region;
				break;
			}
		}
		double throld = 0.3;
		regionGrowing2(srcImg, result, seedRegion, throld);
		imshow("区域生长2", result);
		char ch = waitKey();
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
					imwrite((LPCTSTR)savePath, result);
					MessageBox("图像保存成功!", "保存成功", MB_OK);
				}
			}
		}
		goto again;
	}
}


void CPhotoidfDlg::Onroberts()   //Roberts
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	imshow("原图", srcImg);
	Mat gray;
	cvtColor(srcImg, gray, COLOR_BGR2GRAY);
	Mat kernel1 = (cv::Mat_<float>(2, 2) << -1, 0, 0, 1);
	Mat kernel2 = (cv::Mat_<float>(2, 2) << 0, -1, 1, 0);
	Mat image1, image2;
	filter2D(gray, image1, -1, kernel1);
	filter2D(gray, image2, -1, kernel2);
	convertScaleAbs(image1, image1);
	convertScaleAbs(image2, image2);
	threshold(image1, image1, 30, 255, 0);
	threshold(image2, image2, 30, 255, 0);
	result = image1 + image2;
	imshow("Roberts", result);
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}


void CPhotoidfDlg::Onsobel()   //Sobel
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	imshow("原图", srcImg);
	Mat gray;
	cvtColor(srcImg, gray, COLOR_BGR2GRAY);
	Mat image1, image2;
	Mat kernel1 = (cv::Mat_<float>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1);
	Mat kernel2 = (cv::Mat_<float>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1);
	filter2D(gray, image1, -1, kernel1);
	filter2D(gray, image2, -1, kernel2);
	convertScaleAbs(image1, image1);
	convertScaleAbs(image2, image2);
	threshold(image1, image1, 60, 255, 0);
	threshold(image2, image2, 60, 255, 0);
	result = image1 + image2;
	imshow("Sobel", result);
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}


void CPhotoidfDlg::Onprewitt()  //Prewitt
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	imshow("原图", srcImg);
	Mat gray;
	cvtColor(srcImg, gray, COLOR_BGR2GRAY);
	Mat image1, image2;
	Mat kernel1 = (cv::Mat_<float>(3, 3) << -1, -1, -1, 0, 0, 0, 1, 1, 1);
	Mat kernel2 = (cv::Mat_<float>(3, 3) << -1, 0, 1, -1, 0, 1, -1, 0, 1);
	filter2D(gray, image1, -1, kernel1);
	filter2D(gray, image2, -1, kernel2);
	convertScaleAbs(image1, image1);
	convertScaleAbs(image2, image2);
	threshold(image1, image1, 60, 255, 0);
	threshold(image2, image2, 60, 255, 0);
	result = image1 + image2;
	imshow("Prewitt", result);
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}


void CPhotoidfDlg::Onlaplacian()   //Laplacian
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	imshow("原图", srcImg);
	Mat gray;
	cvtColor(srcImg, gray, COLOR_BGR2GRAY);
	Laplacian(gray, result, CV_16S);
	convertScaleAbs(result, result);
	imshow("Laplacian", result);
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}


void CPhotoidfDlg::Onkirsch()  //Kirsch
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	imshow("原图", srcImg);
	Mat gray;
	cvtColor(srcImg, gray, COLOR_BGR2GRAY);  //8方向
	Mat kernel1 = (cv::Mat_<float>(3, 3) << -3, -3, 5, -3, 0, 5, -3, -3, 5);//N
	Mat kernel2 = (cv::Mat_<float>(3, 3) << -3, 5, 5, -3, 0, 5, -3, -3, -3);//NW
	Mat kernel3 = (cv::Mat_<float>(3, 3) << 5, 5, 5, -3, 0, -3, -3, -3, -3);//W
	Mat kernel4 = (cv::Mat_<float>(3, 3) << 5, 5, -3, 5, 0, -3, -3, -3, -3);//SW
	Mat kernel5 = (cv::Mat_<float>(3, 3) << 5, -3, -3, 5, 0, -3, 5, -3, -3);//S
	Mat kernel6 = (cv::Mat_<float>(3, 3) << -3, -3, -3, 5, 0, -3, 5, 5, -3);//SE
	Mat kernel7 = (cv::Mat_<float>(3, 3) << -3, -3, -3, -3, 0, -3, 5, 5, 5);//E
	Mat kernel8 = (cv::Mat_<float>(3, 3) << -3, -3, -3, -3, 0, 5, -3, 5, 5);//NE
	Mat image1, image2,image3, image4,image5, image6, image7, image8;
	filter2D(gray, image1, -1, kernel1);
	filter2D(gray, image2, -1, kernel2);
	filter2D(gray, image3, -1, kernel3);
	filter2D(gray, image4, -1, kernel4);
	filter2D(gray, image5, -1, kernel5);
	filter2D(gray, image6, -1, kernel6);
	filter2D(gray, image7, -1, kernel7);
	filter2D(gray, image8, -1, kernel8);
	convertScaleAbs(image1, image1);
	convertScaleAbs(image2, image2);
	convertScaleAbs(image3, image3);
	convertScaleAbs(image4, image4);
	convertScaleAbs(image5, image5);
	convertScaleAbs(image6, image6);
	convertScaleAbs(image7, image7);
	convertScaleAbs(image8, image8);
	result = gray.clone();
	for (int i = 0; i < gray.rows; i++)
	{
		for (int j = 0; j < gray.cols; j++)
		{
			int arr[] = { image1.at<uchar>(i, j), image2.at<uchar>(i, j)
				, image3.at<uchar>(i, j), image4.at<uchar>(i, j), image5.at<uchar>(i, j)
				, image6.at<uchar>(i, j), image7.at<uchar>(i, j), image8.at<uchar>(i, j) };
			int max_num = *max_element(arr, arr + 8);  //取8方向最大
			result.at<uchar>(i, j) = max_num;
		}
	}

	threshold(result,result, 220, 255, 0);
	cv::imshow("Kirsch", result);
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}
void CPhotoidfDlg::OnLog()  //LoG
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	imshow("原图", srcImg);
	Mat gray;
	cvtColor(srcImg, gray, COLOR_BGR2GRAY); 
	Mat kernel = (Mat_<float>(5, 5) << 0, 0, 1, 0, 0, 0, 1, 2, 1, 0, 1, 2, -16, 2, 1, 0, 1, 2, 1, 0, 0, 0, 1, 0, 0);
	filter2D(gray, result, -1,kernel);
	cv::imshow("LoG", result);
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}


void CPhotoidfDlg::Oncanny() //Canny
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	imshow("原图", srcImg);
	Mat gray;
	cvtColor(srcImg, gray, COLOR_BGR2GRAY);
	result = Mat(gray.size(), CV_8U, Scalar(0));
	Canny(gray, result, 50, 150);
	imshow("Canny", result);
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}


void CPhotoidfDlg::Onotsu() //Otsu
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	imshow("原图", srcImg);
	Mat image;
	cvtColor(srcImg,image, COLOR_BGR2GRAY);
	int num = 0;
	double var = 0;
	double w0 = 0, w1 = 0, u0 = 0, u1 = 0;
	double Histogram[256] = { 0 };
	uchar* data = image.data;
	double totalnum = image.cols * image.rows;
	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols; j++)
		{
			if (image.at<uchar>(i, j) != 0) Histogram[data[i * image.step + j]]++;
		}
	}
	int minpos, maxpos;
	for (int i = 0; i < 255; i++)
	{
		if (Histogram[i] != 0)
		{
			minpos = i;
			break;
		}
	}
	for (int i = 255; i >= 0; i--)
	{
		if (Histogram[i] != 0)
		{
			maxpos = i;
			break;
		}
	}
	for (int i = minpos; i <= maxpos; i++)
	{
		w1 = 0;
		u1 = 0;
		w0 = 0;
		u0 = 0;
		for (int j = 0; j <= i; j++)
		{
			w1 += Histogram[j];
			u1 += j * Histogram[j];
		}
		if (w1 == 0)
		{
			break;
		}
		u1 = u1 / w1;
		w1 = w1 / totalnum;
		for (int k = i + 1; k < 255; k++)
		{
			w0 += Histogram[k];
			u0 += k * Histogram[k];
		}
		if (w0 == 0)
		{
			break;
		}
		u0 = u0 / w0;
		w0 = w0 / totalnum;
		double varValue = w0 * w1 * (u1 - u0) * (u1 - u0);
		if (var < varValue)
		{
			var = varValue;
			num = i;
		}
	}
	threshold(image, result,num, 255, THRESH_BINARY);
	imshow("Otsu", result);
	char ch = waitKey();
	if(ch == 's' || ch == 'S')
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
void CPhotoidfDlg::Onguding()  //固定阈值
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	imshow("原图", srcImg);
	Mat image;
	cvtColor(srcImg, image, COLOR_BGR2GRAY);
change:
	yuzhi Dlg;
	int pos;
	if (Dlg.DoModal() == IDOK)
	{
		pos = Dlg.Getsize();
	}
	threshold(image, result, pos, 255, THRESH_BINARY);
	imshow("固定阈值", result);
	char ch = waitKey();
	if (ch == 'r' || ch == 'R')
	{
		goto change;
	}
	else if (ch == 's' || ch == 'S')
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


void CPhotoidfDlg::Onzsy()  //自适应阈值
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	imshow("原图", srcImg);
	Mat image;
	cvtColor(srcImg, image, COLOR_BGR2GRAY);
	adaptiveThreshold(image, result, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 11, 2);
	imshow("自适应阈值", result);
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}


void CPhotoidfDlg::Ondouble()  //双阈值
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	imshow("原图", srcImg);
	Mat image;
	cvtColor(srcImg, image, COLOR_BGR2GRAY);
	Mat dst1, dst2;
	yuzhi Dlg1, Dlg2;
	double l, r;
	if (Dlg1.DoModal() == IDOK)
	{
		l = Dlg1.Getsize();
	}
	if (Dlg2.DoModal() == IDOK)
	{
		r = Dlg2.Getsize();
	}
	threshold(image, dst1, l, 255,THRESH_BINARY);
	threshold(image, dst2, r, 255,THRESH_BINARY_INV);
	bitwise_and(dst1, dst2, result);
	imshow("双阈值", result);
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}


void CPhotoidfDlg::Onkmean()  //K均值聚类
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	imshow("原图", srcImg);
	Mat src;
	cvtColor(srcImg, src, COLOR_BGR2GRAY);
	Mat samples(src.total(), 1, CV_32F);
	for (int y = 0; y < src.rows; y++)
	{
		for (int x = 0; x < src.cols; x++)
		{
			samples.at<float>(y + x * src.rows, 0) = src.at<uchar>(y, x);
		}
	}
	Mat labels;
	int clusterCount = 2;
	kmeans(samples, clusterCount, labels, TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, 10, 1.0), 3, KMEANS_PP_CENTERS);
	Mat result(src.size(), src.type());
	for (int y = 0; y < src.rows; y++) {
		for (int x = 0; x < src.cols; x++) {
			int cluster_idx = labels.at<int>(y + x * src.rows, 0);
			result.at<uchar>(y, x) = (cluster_idx == 1) ? 255 : 0;
		}
	}
	imshow("K均值聚类", result);
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}
void CPhotoidfDlg::Onharr()  //Harr分类器
{
	// TODO: 在此添加命令处理程序代码
	camera Dlg;
	if (Dlg.DoModal() == IDOK)
	{
		VideoCapture cap(0);
		if (!cap.isOpened())
		{
			cerr << "ERROR" << '\n';
			return;
		}
		CascadeClassifier face;
		if (!face.load("haarcascade_frontalface_default.xml"))
		{
			cerr << "ERROR" << "\n";
			return;
		}
		Mat frame;
		while (1)
		{
			cap >> frame;
			if (frame.empty())
			{
				break;
			}
			Mat gray;
			cvtColor(frame, gray, COLOR_BGR2GRAY);
			std::vector<Rect>faces;
			face.detectMultiScale(gray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, cv::Size(30, 30));
			for (size_t i = 0; i < faces.size(); i++) {
				cv::rectangle(frame, faces[i], cv::Scalar(255, 0, 0), 2);
			}
			imshow("人脸识别Harri", frame);
			if (waitKey(30) >= 0 && (waitKey(30) == 'q' || waitKey(30) == 'Q'))
			{
				break;
			}
		}
		cap.release();
	}
	else
	{
		if (srcImg.empty())
		{
			cerr << "ERROR" << '\n';
			return;
		}
		imshow("原图", srcImg);
		CascadeClassifier face;
		Mat src = srcImg.clone();
		if (!face.load("haarcascade_frontalface_default.xml"))
		{
			cerr << "ERROR" << "\n";
			return;
		}
		Mat gray;
		cvtColor(src, gray, COLOR_BGR2GRAY);
		equalizeHist(gray, gray);
		std::vector<Rect>faces;
		face.detectMultiScale(gray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, cv::Size(30, 30));
		for (size_t i = 0; i < faces.size(); i++) {
			cv::rectangle(src, faces[i], cv::Scalar(255, 0, 0), 2);
		}
		imshow("人脸识别Harr", src);
		char ch = waitKey();
	}
}
void CPhotoidfDlg::Ondnn()  //DNN
{
	// TODO: 在此添加命令处理程序代码
	camera Dlg;
	string modelConf = "deploy.prototxt";
	string model = "res10_300x300_ssd_iter_140000_fp16.caffemodel";
	Net net = readNetFromCaffe(modelConf, model);
	if (Dlg.DoModal() == IDOK)
	{
		VideoCapture cap(0);
		if (!cap.isOpened())
		{
			cerr << "ERROR" << '\n';
			return;
		}
		Mat frame;
		while (1)
		{
			cap >> frame;
			if (frame.empty())
			{
				cerr << "ERROR" << '\n';
				break;
			}
			Mat blob = blobFromImage(frame, 1.0, Size(300, 300), Scalar(104.0, 177.0, 123.0), false, false);
			net.setInput(blob);
			Mat detection = net.forward();
			Mat detectionMat(detection.size[2], detection.size[3], CV_32F, detection.ptr<float>());
			for (int i = 0; i < detectionMat.rows; i++)
			{
				float confidence = detectionMat.at<float>(i, 2);
				if (confidence > 0.5)
				{
					int x1 = static_cast<int>(detectionMat.at<float>(i, 3) * frame.cols);
					int y1 = static_cast<int>(detectionMat.at<float>(i, 4) * frame.rows);
					int x2 = static_cast<int>(detectionMat.at<float>(i, 5) * frame.cols);
					int y2 = static_cast<int>(detectionMat.at<float>(i, 6) * frame.rows);
					cv::rectangle(frame, Point(x1, y1), Point(x2, y2), Scalar(0, 255, 0), 2, 4);
				}
			}
			imshow("人脸检测DNN", frame);
			if (waitKey(30) >= 0 &&(waitKey(30) == 'q'||waitKey(30)=='Q'))
			{
				break;
			}
		}
		cap.release();
	}
	else
	{
		if (srcImg.empty())
		{
			cerr << "ERROR" << '\n';
			return;
		}
		imshow("原图", srcImg);
		Mat src = srcImg.clone();
		Mat blob = blobFromImage(src, 1.0, Size(300, 300), Scalar(104.0, 177.0, 123.0), false, false);
		net.setInput(blob);
		Mat detection = net.forward();
		Mat detectionMat(detection.size[2], detection.size[3], CV_32F, detection.ptr<float>());
		for (int i = 0; i < detectionMat.rows; i++)
		{
			float confidence = detectionMat.at<float>(i, 2);
			if (confidence > 0.5)
			{
				int x1 = static_cast<int>(detectionMat.at<float>(i, 3) * src.cols);
				int y1 = static_cast<int>(detectionMat.at<float>(i, 4) * src.rows);
				int x2 = static_cast<int>(detectionMat.at<float>(i, 5) * src.cols);
				int y2 = static_cast<int>(detectionMat.at<float>(i, 6) * src.rows);
				cv::rectangle(src, Point(x1, y1), Point(x2, y2), Scalar(0, 255, 0), 2, 4);
			}
		}
		imshow("人脸检测DNN", src);
	}
}
string fgk[11] = {
	"","models//mosaic.t7", "models//starry_night.t7", "models//feathers.t7", "models//candy.t7", "models//la_muse.t7"
		"models//the_scream.t7", "models//udnie.t7", "models//the_wave.t7", "models//composition_vii.t7","models//composition_vii.t7"
};
void CPhotoidfDlg::Onfenggehua()  //人脸风格化
{
	// TODO: 在此添加命令处理程序代码
	fengge dlg;
	int choice = 1;
	if (dlg.DoModal() == IDOK)
	{
		choice = dlg.Getsize();
	}
	string modelBin = fgk[choice];
	camera Dlg;
	string modelConf = "deploy.prototxt";
	string model = "res10_300x300_ssd_iter_140000_fp16.caffemodel";
	float scale = 1.0;
	cv::Scalar mean{ 103.939, 116.779, 123.68 };
	bool swapRB = false;
	bool crop = false;
	bool useOpenCL = false;
	Net net2 = readNetFromTorch(modelBin);
	if (useOpenCL)
		net2.setPreferableTarget(DNN_TARGET_OPENCL);
	Net net = readNetFromCaffe(modelConf, model);
	if (Dlg.DoModal() == IDOK)
	{
		VideoCapture cap(0);
		if (!cap.isOpened())
		{
			cerr << "ERROR" << '\n';
			return;
		}
		Mat frame;
		while (1)
		{
			cap >> frame;
			if (frame.empty())
			{
				cerr << "ERROR" << '\n';
				break;
			}
			Mat blob = blobFromImage(frame, 1.0, Size(300, 300), Scalar(104.0, 177.0, 123.0), false, false);
			net.setInput(blob);
			Mat detection = net.forward();
			Mat detectionMat(detection.size[2], detection.size[3], CV_32F, detection.ptr<float>());
			for (int i = 0; i < detectionMat.rows; i++)
			{
				float confidence = detectionMat.at<float>(i, 2);
				if (confidence > 0.5)
				{
					int x1 = static_cast<int>(detectionMat.at<float>(i, 3) * frame.cols);
					int y1 = static_cast<int>(detectionMat.at<float>(i, 4) * frame.rows);
					int x2 = static_cast<int>(detectionMat.at<float>(i, 5) * frame.cols);
					int y2 = static_cast<int>(detectionMat.at<float>(i, 6) * frame.rows);
					Rect faceROI(x1, y1, x2 - x1, y2 - y1);
					Mat face = frame(faceROI).clone();
					Mat inputBlob = blobFromImage(face, scale, frame.size(), mean, swapRB, crop);
					net2.setInput(inputBlob);
					Mat output = net2.forward();
					Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 0)) += 103.939;
					Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 1)) += 116.779;
					Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 2)) += 123.68;
					std::vector<cv::Mat> ress;
					imagesFromBlob(output, ress);
					Mat res;
					ress[0].convertTo(res, CV_8UC3);
					resize(res, res, Size(3 * face.cols, 3 * face.rows));
					imshow("人脸部分风格化", res);
					cv::rectangle(frame, Point(x1, y1), Point(x2, y2), Scalar(0, 255, 0), 2, 4);
				}
			}
			imshow("人脸检测DNN", frame);
			if (waitKey(30) >= 0 && (waitKey(30) == 'q' || waitKey(30) == 'Q'))
			{
				break;
			}
		}
		cap.release();
	}
	else
	{
		if (srcImg.empty())
		{
			cerr << "ERROR" << '\n';
			return;
		}
		imshow("原图", srcImg);
		Mat src = srcImg.clone();
		Mat blob = blobFromImage(src, 1.0, Size(300, 300), Scalar(104.0, 177.0, 123.0), false, false);
		net.setInput(blob);
		Mat detection = net.forward();
		Mat detectionMat(detection.size[2], detection.size[3], CV_32F, detection.ptr<float>());
		std::vector<Rect>faces;
		result = src.clone();
		for (int i = 0; i < detectionMat.rows; i++)
		{
			float confidence = detectionMat.at<float>(i, 2);
			if (confidence > 0.5)
			{
				int x1 = static_cast<int>(detectionMat.at<float>(i, 3) * src.cols);
				int y1 = static_cast<int>(detectionMat.at<float>(i, 4) * src.rows);
				int x2 = static_cast<int>(detectionMat.at<float>(i, 5) * src.cols);
				int y2 = static_cast<int>(detectionMat.at<float>(i, 6) * src.rows);
				Rect faceROI(x1, y1, x2 - x1, y2 - y1);
				faces.push_back(faceROI);
				cv::rectangle(src, Point(x1, y1), Point(x2, y2), Scalar(0, 255, 0), 2, 4);
			}
		}
		for (int i = 0; i < faces.size(); i++)
		{
			Rect re = faces[i];
			Mat face = src(re).clone();
			Mat inputBlob = blobFromImage(face, scale, src.size(), mean, swapRB, crop);
			net2.setInput(inputBlob);
			Mat output = net2.forward();
			Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 0)) += 103.939;
			Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 1)) += 116.779;
			Mat(output.size[2], output.size[3], CV_32F, output.ptr<float>(0, 2)) += 123.68;
			std::vector<cv::Mat> ress;
			imagesFromBlob(output, ress);
			Mat res;
			ress[0].convertTo(res, CV_8UC3);
			Mat image = res.clone();
			resize(res, res, Size(3*face.cols, 3*face.rows));
			resize(image, image, Size(face.cols, face.rows));
			image.copyTo(result(re));
			imshow("人脸风格化" + to_string(i), res);
		}
		imshow("人脸风格化", result);
		imshow("人脸检测DNN", src);
	}
}
void CPhotoidfDlg::Onmopi()  //磨皮
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	imshow("原图", srcImg);
	bilateralFilter(srcImg, result, 15, 100, 15);
	imshow("磨皮", result);
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}


void CPhotoidfDlg::Onkouhong()  //口红
{
	// TODO: 在此添加命令处理程序代码
	if (srcImg.empty())
	{
		cerr << "ERROR" << '\n';
		return;
	}
	imshow("原图", srcImg);
	Mat gray;
	cvtColor(srcImg, gray, COLOR_BGR2GRAY);
	frontal_face_detector detector = get_frontal_face_detector();
	shape_predictor sp;
	deserialize("models/shape_predictor_68_face_landmarks.dat") >> sp;

	dlib::cv_image<unsigned char> dlibImg(gray);
	std::vector<dlib::rectangle> faces = detector(dlibImg);

	if (faces.empty()) {
		cerr << "No faces detected." << endl;
		return;
	}
	full_object_detection shape = sp(dlibImg, faces[0]);
	std::vector<Point2f> points;
	for (int i = 0; i < shape.num_parts(); ++i)
	{
		points.push_back(Point2f(shape.part(i).x(), shape.part(i).y()));
	}
	Mat resultImg = srcImg.clone();
	std::vector<Point> lips;
	for (int i = 48; i <= 59; ++i)
	{
		lips.push_back(Point(points[i].x, points[i].y));
	}
	for (int i = 60; i <= 67; ++i)
	{
		lips.push_back(Point(points[i].x, points[i].y));
	}

	Mat lipMask = Mat::zeros(resultImg.size(), resultImg.type());
	fillConvexPoly(lipMask, lips, Scalar(0, 0, 255)); 
	GaussianBlur(lipMask, lipMask, Size(15, 15), 10);

	addWeighted(resultImg, 1.0, lipMask, 0.2, 0, resultImg);

	imshow("Lipstick Effect", resultImg);
}
struct correspondens
{
	std::vector<int> index;
};

void faceLandmarkDetection(dlib::array2d<unsigned char>& img, shape_predictor sp, std::vector<Point2f>& landmark)
{
	dlib::frontal_face_detector detector = get_frontal_face_detector();
	std::vector<dlib::rectangle> dets = detector(img);
	if (dets.empty()) {
		cerr << "No face detected in the image!" << endl;
		return;
	}
	full_object_detection shape = sp(img, dets[0]);
	for (int i = 0; i < shape.num_parts(); ++i)
	{
		float x = shape.part(i).x();
		float y = shape.part(i).y();
		landmark.push_back(Point2f(x, y));
	}
}

void delaunayTriangulation(const std::vector<Point2f>& hull, std::vector<correspondens>& delaunayTri, Rect rect)
{
	cv::Subdiv2D subdiv(rect);
	for (int it = 0; it < hull.size(); it++)
		subdiv.insert(hull[it]);
	std::vector<Vec6f> triangleList;
	subdiv.getTriangleList(triangleList);
	for (size_t i = 0; i < triangleList.size(); ++i)
	{
		std::vector<Point2f> pt;
		correspondens ind;
		Vec6f t = triangleList[i];
		pt.push_back(Point2f(t[0], t[1]));
		pt.push_back(Point2f(t[2], t[3]));
		pt.push_back(Point2f(t[4], t[5]));
		if (rect.contains(pt[0]) && rect.contains(pt[1]) && rect.contains(pt[2]))
		{
			int count = 0;
			for (int j = 0; j < 3; ++j)
				for (size_t k = 0; k < hull.size(); k++)
					if (abs(pt[j].x - hull[k].x) < 1.0 && abs(pt[j].y - hull[k].y) < 1.0)
					{
						ind.index.push_back(k);
						count++;
					}
			if (count == 3)
				delaunayTri.push_back(ind);
		}
	}
}

void applyAffineTransform(Mat& warpImage, Mat& src, std::vector<Point2f>& srcTri, std::vector<Point2f>& dstTri)
{
	Mat warpMat = getAffineTransform(srcTri, dstTri);
	warpAffine(src, warpImage, warpMat, warpImage.size(), cv::INTER_LINEAR, BORDER_REFLECT_101);
}

void warpTriangle(Mat& img1, Mat& img2, std::vector<Point2f>& t1, std::vector<Point2f>& t2)
{
	Rect r1 = boundingRect(t1);
	Rect r2 = boundingRect(t2);
	std::vector<Point2f> t1Rect, t2Rect;
	std::vector<Point> t2RectInt;
	for (int i = 0; i < 3; i++)
	{
		t1Rect.push_back(Point2f(t1[i].x - r1.x, t1[i].y - r1.y));
		t2Rect.push_back(Point2f(t2[i].x - r2.x, t2[i].y - r2.y));
		t2RectInt.push_back(Point(t2[i].x - r2.x, t2[i].y - r2.y));
	}
	Mat mask = Mat::zeros(r2.height, r2.width, CV_32FC3);
	fillConvexPoly(mask, t2RectInt, Scalar(1.0, 1.0, 1.0), 16, 0);
	Mat img1Rect;
	img1(r1).copyTo(img1Rect);
	Mat img2Rect = Mat::zeros(r2.height, r2.width, img1Rect.type());
	applyAffineTransform(img2Rect, img1Rect, t1Rect, t2Rect);
	multiply(img2Rect, mask, img2Rect);
	multiply(img2(r2), Scalar(1.0, 1.0, 1.0) - mask, img2(r2));
	img2(r2) = img2(r2) + img2Rect;
}

void CPhotoidfDlg::Onhuanlian()  //换脸
{
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
		TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);
	CString m_path;
	if (dlg.DoModal() == IDOK)
	{
		m_path = dlg.GetPathName();
	}
	else
		return;
	CString n_path;
	CFileDialog edlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
		TEXT("Supported Types (*.jpg;*.png;*.gif;*.bmp;...)|*.jpg;*.png;*.gif;*.bmp|Tiff(*.tiff;*.tif)|*.tiff;*.tif|All Files(*.*)|*.*||"), NULL);
	if (edlg.DoModal() == IDOK)
	{
		n_path = edlg.GetPathName();
	}
	else
		return;
	dlib::array2d<unsigned char> imgDlib1, imgDlib2;
	dlib::load_image(imgDlib1, (LPCTSTR)m_path);
	dlib::load_image(imgDlib2, (LPCTSTR)n_path);

	Mat imgCV1 = imread((LPCTSTR)m_path, 1);
	Mat imgCV2 = imread((LPCTSTR)n_path, 1);
	imshow("原图1", imgCV1);
	imshow("覆盖图", imgCV2);

	shape_predictor sp;
	deserialize("models/shape_predictor_68_face_landmarks.dat") >> sp;
	std::vector<Point2f> points1, points2;

	faceLandmarkDetection(imgDlib1, sp, points1);
	faceLandmarkDetection(imgDlib2, sp, points2);

	if (points1.size() != 68 || points2.size() != 68) {
		cerr << "Face landmarks not detected properly!" << endl;
		return;
	}

	Mat imgCV1Warped = imgCV2.clone();
	imgCV1.convertTo(imgCV1, CV_32F);
	imgCV1Warped.convertTo(imgCV1Warped, CV_32F);

	std::vector<Point2f> hull1;
	std::vector<Point2f> hull2;
	std::vector<int> hullIndex;

	cv::convexHull(points2, hullIndex, false, false);

	for (int i = 0; i < hullIndex.size(); i++)
	{
		hull1.push_back(points1[hullIndex[i]]);
		hull2.push_back(points2[hullIndex[i]]);
	}

	std::vector<correspondens> delaunayTri;
	Rect rect(0, 0, imgCV1Warped.cols, imgCV1Warped.rows);
	delaunayTriangulation(hull2, delaunayTri, rect);

	for (size_t i = 0; i < delaunayTri.size(); ++i)
	{
		std::vector<Point2f> t1, t2;
		correspondens corpd = delaunayTri[i];
		if (corpd.index.size() != 3) {
			cerr << "Invalid triangulation!" << endl;
			continue;
		}
		for (size_t j = 0; j < 3; ++j)
		{
			t1.push_back(hull1[corpd.index[j]]);
			t2.push_back(hull2[corpd.index[j]]);
		}

		warpTriangle(imgCV1, imgCV1Warped, t1, t2);
	}

	std::vector<Point> hull8U;

	for (int i = 0; i < hull2.size(); ++i)
	{
		Point pt(hull2[i].x, hull2[i].y);
		hull8U.push_back(pt);
	}

	Mat mask = Mat::zeros(imgCV2.rows, imgCV2.cols, imgCV2.depth());
	fillConvexPoly(mask, &hull8U[0], hull8U.size(), Scalar(255, 255, 255));

	Rect r = boundingRect(hull2);
	Point center = (r.tl() + r.br()) / 2;

	Mat output;
	imgCV1Warped.convertTo(imgCV1Warped, CV_8UC3);
	seamlessClone(imgCV1Warped, imgCV2, mask, center, output, NORMAL_CLONE);

	imshow("换脸后的图", output);
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, output);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}
shape_predictor predictor;
std::vector<dlib::full_object_detection> detect_landmarks(cv::Mat& img) {
	frontal_face_detector detector = get_frontal_face_detector();
	cv_image<bgr_pixel> cimg(img);
	std::vector<dlib::rectangle> faces = detector(cimg);
	std::vector<full_object_detection> shapes;
	for (unsigned long i = 0; i < faces.size(); ++i) {
		full_object_detection shape = predictor(cimg, faces[i]);
		shapes.push_back(shape);
	}
	return shapes;
}

cv::Mat localTranslationWarp(cv::Mat srcImg, int startX, int startY, int endX, int endY, int radius) {
	double ddradius = double(radius * radius);
	cv::Mat copyImg = srcImg.clone();
	double ddmc = (endX - startX) * (endX - startX) + (endY - startY) * (endY - startY);
	int H = srcImg.rows;
	int W = srcImg.cols;

	for (int i = 0; i < W; ++i) {
		for (int j = 0; j < H; ++j) {
			if (fabs(i - startX) > radius && fabs(j - startY) > radius)
				continue;

			double distance = (i - startX) * (i - startX) + (j - startY) * (j - startY);

			if (distance < ddradius) {
				double ratio = (ddradius - distance) / (ddradius - distance + ddmc);
				ratio = ratio * ratio;

				double UX = i - ratio * (endX - startX);
				double UY = j - ratio * (endY - startY);

				int x1 = int(UX);
				int y1 = int(UY);
				int x2 = x1 + 1;
				int y2 = y1 + 1;

				if (x1 >= 0 && x2 < W && y1 >= 0 && y2 < H) {
					for (int c = 0; c < srcImg.channels(); ++c) {
						double part1 = srcImg.at<Vec3b>(y1, x1)[c] * (x2 - UX) * (y2 - UY);
						double part2 = srcImg.at<Vec3b>(y1, x2)[c] * (UX - x1) * (y2 - UY);
						double part3 = srcImg.at<Vec3b>(y2, x1)[c] * (x2 - UX) * (UY - y1);
						double part4 = srcImg.at<Vec3b>(y2, x2)[c] * (UX - x1) * (UY - y1);

						copyImg.at<Vec3b>(j, i)[c] = saturate_cast<uchar>(part1 + part2 + part3 + part4);
					}
				}
			}
		}
	}
	return copyImg;
}

cv::Mat face_thin_auto(cv::Mat src) {
	std::vector<full_object_detection> landmarks = detect_landmarks(src);

	if (landmarks.empty()) {
		return src;
	}

	for (auto& landmark : landmarks) {
		// 使用更多的特征点进行更精细的瘦脸处理
		cv::Point left_landmark_up(landmark.part(1).x(), landmark.part(1).y());
		cv::Point left_landmark(landmark.part(3).x(), landmark.part(3).y());
		cv::Point left_landmark_down(landmark.part(5).x(), landmark.part(5).y());

		cv::Point right_landmark_up(landmark.part(15).x(), landmark.part(15).y());
		cv::Point right_landmark(landmark.part(13).x(), landmark.part(13).y());
		cv::Point right_landmark_down(landmark.part(11).x(), landmark.part(11).y());

		cv::Point endPt(landmark.part(30).x(), landmark.part(30).y());

		double r_left = sqrt(pow(left_landmark.x - left_landmark_down.x, 2) + pow(left_landmark.y - left_landmark_down.y, 2));
		double r_right = sqrt(pow(right_landmark.x - right_landmark_down.x, 2) + pow(right_landmark.y - right_landmark_down.y, 2));

		// 调整瘦脸变形的半径和力度
		r_left *= 1.05;
		r_right *= 1.05;

		src = localTranslationWarp(src, left_landmark.x, left_landmark.y, endPt.x, endPt.y, int(r_left));
		src = localTranslationWarp(src, right_landmark.x, right_landmark.y, endPt.x, endPt.y, int(r_right));

		// 使用更多特征点进行局部微调
		src = localTranslationWarp(src, left_landmark_up.x, left_landmark_up.y, endPt.x, endPt.y, int(r_left / 2));
		src = localTranslationWarp(src, right_landmark_up.x, right_landmark_up.y, endPt.x, endPt.y, int(r_right / 2));
	}
	return src;
}
void CPhotoidfDlg::Oneye()  //瘦脸效果
{
	deserialize("models/shape_predictor_68_face_landmarks.dat") >> predictor;
	if (srcImg.empty())
	{
		cerr << "ERROR: Image is empty." << endl;
		return;
	}
	imshow("原图", srcImg);
	result= face_thin_auto(srcImg);
	imshow("瘦脸", result);
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}
frontal_face_detector detector = get_frontal_face_detector();
std::vector<dlib::full_object_detection> landmark_dec_dlib_fun(cv::Mat img_src) {
	cv::Mat img_gray;
	cvtColor(img_src, img_gray, cv::COLOR_BGR2GRAY);
	std::vector<dlib::rectangle> rects = detector(dlib::cv_image<unsigned char>(img_gray));
	std::vector<dlib::full_object_detection> land_marks;

	for (auto rect : rects) {
		land_marks.push_back(predictor(dlib::cv_image<unsigned char>(img_gray), rect));
	}
	return land_marks;
}
cv::Vec3b BilinearInsert(cv::Mat src, float ux, float uy) {
	int x1 = int(ux);
	int x2 = x1 + 1;
	int y1 = int(uy);
	int y2 = y1 + 1;

	float part1_b = src.at<cv::Vec3b>(y1, x1)[0] * (x2 - ux) * (y2 - uy);
	float part1_g = src.at<cv::Vec3b>(y1, x1)[1] * (x2 - ux) * (y2 - uy);
	float part1_r = src.at<cv::Vec3b>(y1, x1)[2] * (x2 - ux) * (y2 - uy);

	float part2_b = src.at<cv::Vec3b>(y1, x2)[0] * (ux - x1) * (y2 - uy);
	float part2_g = src.at<cv::Vec3b>(y1, x2)[1] * (ux - x1) * (y2 - uy);
	float part2_r = src.at<cv::Vec3b>(y1, x2)[2] * (ux - x1) * (y2 - uy);

	float part3_b = src.at<cv::Vec3b>(y2, x1)[0] * (x2 - ux) * (uy - y1);
	float part3_g = src.at<cv::Vec3b>(y2, x1)[1] * (x2 - ux) * (uy - y1);
	float part3_r = src.at<cv::Vec3b>(y2, x1)[2] * (x2 - ux) * (uy - y1);

	float part4_b = src.at<cv::Vec3b>(y2, x2)[0] * (ux - x1) * (uy - y1);
	float part4_g = src.at<cv::Vec3b>(y2, x2)[1] * (ux - x1) * (uy - y1);
	float part4_r = src.at<cv::Vec3b>(y2, x2)[2] * (ux - x1) * (uy - y1);

	float sum_b = part1_b + part2_b + part3_b + part4_b;
	float sum_g = part1_g + part2_g + part3_g + part4_g;
	float sum_r = part1_r + part2_r + part3_r + part4_r;

	return cv::Vec3b(sum_b, sum_g, sum_r);
}

cv::Mat localTranslationWarp(cv::Mat srcImg, int startX, int startY, int endX, int endY, float radius) {
	float ddradius = radius * radius;
	cv::Mat copyImg = srcImg.clone();

	float ddmc = (endX - startX) * (endX - startX) + (endY - startY) * (endY - startY);
	int H = srcImg.rows;
	int W = srcImg.cols;
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			if (fabs(i - startX) > radius && fabs(j - startY) > radius) continue;

			float distance = (i - startX) * (i - startX) + (j - startY) * (j - startY);

			if (distance < ddradius) {
				float rnorm = sqrt(distance) / radius;
				float ratio = 1 - (rnorm - 1) * (rnorm - 1) * 0.5;

				float UX = startX + ratio * (i - startX);
				float UY = startY + ratio * (j - startY);

				cv::Vec3b value = BilinearInsert(srcImg, UX, UY);
				copyImg.at<cv::Vec3b>(j, i) = value;
			}
		}
	}
	return copyImg;
}

cv::Mat eye_thin_auto(cv::Mat src) {
	std::vector<dlib::full_object_detection> landmarks = landmark_dec_dlib_fun(src);

	if (landmarks.empty())
	{
		return src;
	}
	for (auto& landmarks_node : landmarks) {
		cv::Point left_landmark(landmarks_node.part(38).x(), landmarks_node.part(38).y());
		cv::Point left_landmark_down(landmarks_node.part(27).x(), landmarks_node.part(27).y());

		cv::Point right_landmark(landmarks_node.part(43).x(), landmarks_node.part(43).y());
		cv::Point right_landmark_down(landmarks_node.part(27).x(), landmarks_node.part(27).y());

		cv::Point endPt(landmarks_node.part(30).x(), landmarks_node.part(30).y());

		float r_left = sqrt(pow(left_landmark.x - left_landmark_down.x, 2) + pow(left_landmark.y - left_landmark_down.y, 2));
		float r_right = sqrt(pow(right_landmark.x - right_landmark_down.x, 2) + pow(right_landmark.y - right_landmark_down.y, 2));

		cv::Mat thin_image = localTranslationWarp(src, left_landmark.x, left_landmark.y, endPt.x, endPt.y, r_left);
		thin_image = localTranslationWarp(thin_image, right_landmark.x, right_landmark.y, endPt.x, endPt.y, r_right);

		return thin_image;
	}
	return src;
}
void CPhotoidfDlg::Onbig()  //大眼
{
	// TODO: 在此添加命令处理程序代码
	deserialize("models/shape_predictor_68_face_landmarks.dat") >> predictor;
	if (srcImg.empty())
	{
		cerr << "ERROR: Image is empty." << endl;
		return;
	}
	imshow("原图", srcImg);
	result = eye_thin_auto(srcImg);
	imshow("大眼", result);
	char ch = waitKey();
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
				imwrite((LPCTSTR)savePath, result);
				MessageBox("图像保存成功!", "保存成功", MB_OK);
			}
		}
	}
}
