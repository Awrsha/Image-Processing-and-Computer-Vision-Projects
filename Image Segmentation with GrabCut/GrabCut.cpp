#include <iostream>
#include <opencv2/opencv.hpp>

bool draw_rectangle = false;
bool drawing = false;
int rect_or_mask = -1;
bool rect_is_drawed = false;
cv::Point start_point;
cv::Rect rect;
cv::Mat draw_image;
cv::Mat mask;
cv::Mat output;

void onmouse(int event, int x, int y, int flags, void* param)
{
    // Draw Rectangle
    if (event == cv::EVENT_RBUTTONDOWN)
    {
        draw_rectangle = true;
        start_point = cv::Point(x, y);
    }
    else if (event == cv::EVENT_MOUSEMOVE)
    {
        if (draw_rectangle)
        {
            draw_image = param->clone();
            cv::rectangle(draw_image, start_point, cv::Point(x, y), cv::Scalar(255, 0, 0), 2);
        }
    }
    else if (event == cv::EVENT_RBUTTONUP)
    {
        draw_rectangle = false;
        cv::rectangle(draw_image, start_point, cv::Point(x, y), cv::Scalar(255, 0, 0), 2);
        rect = cv::Rect(cv::min(start_point.x, x), cv::min(start_point.y, y), abs(start_point.x - x), abs(start_point.y - y));
        rect_is_drawed = true;
        rect_or_mask = 0;
    }

    // Draw touchup curves
    if (event == cv::EVENT_LBUTTONDOWN)
    {
        if (!rect_is_drawed)
        {
            std::cout << "First draw rectangle." << std::endl;
        }
        else
        {
            drawing = true;
            cv::circle(draw_image, cv::Point(x, y), 3, cv::Scalar(255, 255, 255), -1);
            cv::circle(mask, cv::Point(x, y), 3, cv::Scalar(1, 1, 1), -1);
        }
    }
    else if (event == cv::EVENT_MOUSEMOVE)
    {
        if (drawing)
        {
            cv::circle(draw_image, cv::Point(x, y), 3, cv::Scalar(255, 255, 255), -1);
            cv::circle(mask, cv::Point(x, y), 3, cv::Scalar(1, 1, 1), -1);
        }
    }
    else if (event == cv::EVENT_LBUTTONUP)
    {
        if (drawing)
        {
            drawing = false;
        }
    }
}

int main()
{
    cv::Mat image = cv::imread("test.jpg");
    draw_image = image.clone();
    mask = cv::Mat(image.size(), CV_8UC1, cv::Scalar(0));
    output = cv::Mat(image.size(), CV_8UC3, cv::Scalar(0, 0, 0));

    cv::namedWindow("output");
    cv::namedWindow("input");
    cv::setMouseCallback("input", onmouse, &draw_image);

    cv::Scalar DRAW_BG(0, 0, 0);
    cv::Scalar DRAW_FG(255, 255, 255);

    while (true)
    {
        cv::imshow("output", output);
        cv::imshow("input", draw_image);
        int key = cv::waitKey(1);

        // Key bindings
        if (key == 27)  // Esc key to exit
            break;
        else if (key == '0')
            value = DRAW_BG;
        else if (key == '1')
            value = DRAW_FG;
        else if (key == 'n')
        {
            cv::Mat bgdmodel, fgdmodel;
            if (rect_or_mask == 0)
            {
                cv::grabCut(image, mask, rect, bgdmodel, fgdmodel, 1, cv::GC_INIT_WITH_RECT);
                rect_or_mask = 1;
            }
            else if (rect_or_mask == 1)
            {
                cv::grabCut(image, mask, rect, bgdmodel, fgdmodel, 1, cv::GC_INIT_WITH_MASK);
            }
        }

        cv::Mat mask2 = (mask == 1) | (mask == 3);
        mask2.convertTo(mask2, CV_8UC1, 255);
        output.setTo(cv::Scalar(0, 0, 0));
        image.copyTo(output, mask2);
    }

    cv::destroyAllWindows();
    cv::imwrite("grabcut_output.png", output);

    cv::imshow("mask", mask2);
    cv::imshow("Output", output);
    cv::waitKey(0);

    return 0;
}