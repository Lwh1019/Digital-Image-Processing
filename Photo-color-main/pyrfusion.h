#ifndef PYRFUSION_H
#define PYRFUSION_H
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

class MyPyrFusionTest{
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
#endif // PYRFUSION_H