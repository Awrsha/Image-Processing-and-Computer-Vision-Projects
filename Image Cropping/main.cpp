#include<opencv2\core.hpp>
#include<opencv2\imgcodecs.hpp>
#include<opencv2\highgui.hpp>
#include<opencv2\imgproc.hpp>

using namespace cv;

#include<opencv2\core.hpp>
#include<opencv2\imgcodecs.hpp>
#include<opencv2\highgui.hpp>
#include<opencv2\imgproc.hpp>

static void onMouse(int event, int x, int y, int flags, void*) {
	if (selectObject)
	{
		selection.x = min(x, origin.x);
		selection.y = min(y, origin.y);
		selection.width = abs(x - origin.x);
		selection.height = abs(y - origin.y);

		selection &= Rect(0, 0, img.cols, img.rows);
	}


	switch (event)
	{
	case EVENT_LBUTTONDOWN:
		origin = Point(x, y);
		selection = Rect(x, y, 0, 0);
		selectObject = true;
		break;
	case EVENT_LBUTTONUP:
		selectObject = false;
		if (selection.width > 0 && selection.height > 0)
			objectCropped = true;
	default:
		break;
	}
	img.copyTo(imgClone);
	rectangle(imgClone, selection, Scalar(0, 0, 255), 1, 8, 0);
	imshow("image", imgClone);
}

int main() {
	img = imread("test.jpg");
	namedWindow("image", WINDOW_AUTOSIZE);
	setMouseCallback("image", onMouse);
	imshow("image", img);

	int d = 1;
	while (d == 1)
	{
		if (objectCropped)
		{
			Mat crop = img(selection);
			namedWindow("crop", WINDOW_AUTOSIZE);
			imshow("crop", crop);
			d = 0;
		}
		waitKey(10);
	}
	waitKey(0);

	return 0;
}