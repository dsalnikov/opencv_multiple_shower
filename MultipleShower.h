#ifndef __MULTIPLE_SHOWER__
#define __MULTIPLE_SHOWER__

#include <opencv/cv.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class MultipleShower
{
	int w_padding = 10;
	int h_padding = 10;
	int rows = 1;
	int columns = 1;
	int image_width = 512;
	int image_height = 512;
	cv::Mat background;
	std::vector<cv::Mat> img_list;
	void draw();
public:
	MultipleShower();
	MultipleShower(int, int);
	~MultipleShower();

	void set_grid(int r, int c);
	int get_length();
	void add(int x, int y, cv::Mat img);
	void show();
	void save(const char * filename);
	void set_padding(int,int);
};

#endif /* __MULTIPLE_SHOWER__ */
