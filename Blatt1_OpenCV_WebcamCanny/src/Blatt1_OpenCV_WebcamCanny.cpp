/*!\file Blatt1_OpenCV_WebcamCanny.cpp
 * \brief OpenCV demo, grabbing image from webcam and display canny edges
 *
 * Documentation: just google for "opencv3 api" or "opencv3 tutorial" or similar
 * API and Tutorials: http://docs.opencv.org/3.1.0/index.html
 * Warning, do not use documentation of OpenCV 2, we use version OpenCV 3.
 * Many examples in the tutorials still refer to OpenCV2.
 *
 * Source code:
 * Tutorials: portableDevEnv\opencv320\x64\mingw\samples\tutorials
 * Examples:  portableDevEnv\opencv320\x64\mingw\samples\cpp (exe files only)
 * Start examples with OpenCVExamplesStartHere.bat, then OpenCV path to libraries is set accordingly.
 * If you want to start the examples from Windows Explorer, you have to add the full path to
 * C:\......\portableDevEnv\opencv320\x64\mingw\bin to your system path variable.
 *
 */
#include <iostream>   // std::cout
#include <opencv2/opencv.hpp>

int main(int argc, char** argv){
	std::cout << " Webcam capture and Canny edges demo, type q to quit the program." << std::endl;
	cv::VideoCapture cap(0);
	if (!cap.isOpened()) return -1;

	cv::Mat frame, edges;
	cv::namedWindow("Input image", 1);
	cv::namedWindow("Canny edges", 1);
	for (;;)
	{
		cap >> frame;
		cv::cvtColor(frame, edges, cv::COLOR_BGR2GRAY);
		cv::GaussianBlur(edges, edges, cv::Size(7, 7), 1.5, 1.5);
		cv::Canny(edges, edges, 0, 30, 3);
		cv::imshow("Input image", frame);
		cv::imshow("Canny edges", edges);
		if (cv::waitKey(30) == 113) break;  // 113 is ASCII key 'q'
	}

	return 0;
}
