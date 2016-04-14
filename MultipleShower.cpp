#include "MultipleShower.h"

MultipleShower::MultipleShower()
{
	image_height = 100;
	image_width = 100;
}

MultipleShower::MultipleShower(int h, int w)
{
	image_height = h;
	image_width = w;
}

MultipleShower::~MultipleShower()
{
}

void MultipleShower::set_grid(int r, int c)
{
	rows = r;
	columns = c;
	img_list.resize(r*c);
}

int MultipleShower::get_length()
{
	return rows * columns;
}

void MultipleShower::add(int x, int y, cv::Mat img)
{
	img_list[x*rows + y] = img;
}

void MultipleShower::draw()
{
	int width = columns * (image_width + w_padding) + w_padding;
	int height = rows * (image_height + h_padding) + h_padding;
	background.deallocate();
	background = cv::Mat(height, width, CV_8U, cv::Scalar(255, 255, 255));

	for (int j = 0; j < rows; j++)
	{
		int pos_y = h_padding + j*(image_height + h_padding);

		for (int i = 0; i < columns; i++)
		{
			int pos_x = w_padding + i*(image_width + w_padding);

			cv::Rect roi(pos_x, pos_y, image_width, image_height);
			cv::Mat img_roi = background(roi);
			cv::Mat img = img_list[j*rows + i];
			if (img.data)
				cv::resize(img, img_roi, cv::Size(image_width, image_height));
		}
	}
}

void MultipleShower::show()
{
	draw();
	imshow("title", background);
}

void MultipleShower::set_padding(int w, int h)
{
	w_padding = w;
	h_padding = h;
}

void MultipleShower::save(const char * filename)
{
	draw();
	cv::imwrite(filename, background);
}
