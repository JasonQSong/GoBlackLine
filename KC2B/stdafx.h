// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
#pragma once

// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�

#ifdef _DEBUG

#pragma comment(lib, "opencv_calib3d231d.lib")
#pragma comment(lib, "opencv_contrib231d.lib")
#pragma comment(lib, "opencv_core231d.lib")
#pragma comment(lib, "opencv_features2d231d.lib")
#pragma comment(lib, "opencv_flann231d.lib")
#pragma comment(lib, "opencv_gpu231d.lib")
#pragma comment(lib, "opencv_highgui231d.lib")
#pragma comment(lib, "opencv_imgproc231d.lib")
#pragma comment(lib, "opencv_legacy231d.lib")
#pragma comment(lib, "opencv_ml231d.lib")
#pragma comment(lib, "opencv_objdetect231d.lib")
#pragma comment(lib, "opencv_ts231d.lib")
#pragma comment(lib, "opencv_video231d.lib")

#else

#pragma comment(lib, "opencv_calib3d231.lib")
#pragma comment(lib, "opencv_contrib231.lib")
#pragma comment(lib, "opencv_core231.lib")
#pragma comment(lib, "opencv_features2d231.lib")
#pragma comment(lib, "opencv_flann231.lib")
#pragma comment(lib, "opencv_gpu231.lib")
#pragma comment(lib, "opencv_highgui231.lib")
#pragma comment(lib, "opencv_imgproc231.lib")
#pragma comment(lib, "opencv_legacy231.lib")
#pragma comment(lib, "opencv_ml231.lib")
#pragma comment(lib, "opencv_objdetect231.lib")
#pragma comment(lib, "opencv_ts231.lib")
#pragma comment(lib, "opencv_video231.lib")

#endif

#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;