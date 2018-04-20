/*!\file Blatt1_OpenCV_ReadAndDisplayImage.cpp
 * \brief OpenCV demo, load and display image, show image from webcam
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

int main(int argc, char** argv){  // set input parameters in Run->Run Configurations... -> Blatt1_ReadAndDisplayImage.exe->(x)Arguments
	if (argc == 2) {
		std::cout << " Command line parameter is " << argv[1] << std::endl;
	}
	cv::Mat img = cv::imread(argc == 2 ? argv[1] : "./src/opencv-logo.png", 1);  // if no command line parameter, then predefined image
	if(img.empty())return -1;                            // stop if nothing can be displayed
	cv::namedWindow("Example 1", cv::WINDOW_AUTOSIZE);   // window is identified by name
	cv::imshow("Example 1", img);                        // make window visible
	cv::waitKey(0);                                      // prevent window from closing until user keypress
	cv::destroyWindow("Example 1");                      // remove window

	return 0;
}
