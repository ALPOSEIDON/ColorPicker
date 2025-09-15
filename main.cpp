#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int hmin = 0, smin = 0, vmin = 0;
int hmax = 179, smax = 255, vmax = 255;

int main() {
	int swhKey = 0;
	Mat imgHSV, mask, img;
	string path;

	cout << "��������ʹ�õ�ģ�飺1.ͼƬ��2.����ͷ��";
	cin >> swhKey;

	

	switch (swhKey) {

	case 1:
		cout << "�������ļ�·����";
		cin >> path;
		img = imread(path);
		
		cvtColor(img, imgHSV, COLOR_BGR2HSV);

		namedWindow("Trackbars", (640, 200));
		createTrackbar("Hue Min", "Trackbars", &hmin, 179);
		createTrackbar("Hue Max", "Trackbars", &hmax, 179);
		createTrackbar("Sat Min", "Trackbars", &smin, 255);
		createTrackbar("Sat Max", "Trackbars", &smax, 255);
		createTrackbar("Val Min", "Trackbars", &vmin, 255);
		createTrackbar("Val Max", "Trackbars", &vmax, 255);

		while (true) {

			Scalar lower(hmin, smin, vmin);
			Scalar upper(hmax, smax, vmax);
			inRange(imgHSV, lower, upper, mask);
			imshow("Image", img);
			imshow("Image HSV", imgHSV);
			imshow("Image mask", mask);

			waitKey(1);//������ʱ
		}
		break;

	case 2:
		VideoCapture cap(0);

		waitKey(3000);

		namedWindow("Trackbars", (640, 200));
		createTrackbar("Hue Min", "Trackbars", &hmin, 179);
		createTrackbar("Hue Max", "Trackbars", &hmax, 179);
		createTrackbar("Sat Min", "Trackbars", &smin, 255);
		createTrackbar("Sat Max", "Trackbars", &smax, 255);
		createTrackbar("Val Min", "Trackbars", &vmin, 255);
		createTrackbar("Val Max", "Trackbars", &vmax, 255);

		while (true) {
			cap.read(img);
			cvtColor(img, imgHSV, COLOR_BGR2HSV);

			Scalar lower(hmin, smin, vmin);
			Scalar upper(hmax, smax, vmax);
			inRange(imgHSV, lower, upper, mask);
			imshow("Image", img);
			imshow("Image HSV", imgHSV);
			imshow("Image mask", mask);

			waitKey(1);//������ʱ
		}
	}
}