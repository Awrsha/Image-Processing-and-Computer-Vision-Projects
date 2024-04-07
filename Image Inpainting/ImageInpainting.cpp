#include <iostream>

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/opencv.hpp>
#include "opencv2/core.hpp"

// OpenCV Utility Class for Mouse Handling
class Sketcher {
public:
    Sketcher(const std::string& windowname, std::vector<cv::Mat>& dests, std::function<std::vector<cv::Scalar>()> colors_func)
        : prev_pt(cv::Point(-1, -1)), windowname(windowname), dests(dests), colors_func(colors_func), dirty(false) {
        show();
        cv::setMouseCallback(windowname, &Sketcher::on_mouse, this);
    }

    void show() {
        cv::imshow(windowname, dests[0]);
        cv::imshow(windowname + ": mask", dests[1]);
    }

    static void on_mouse(int event, int x, int y, int flags, void* param) {
        Sketcher* sketcher = static_cast<Sketcher*>(param);
        sketcher->on_mouse(event, x, y, flags);
    }

    void on_mouse(int event, int x, int y, int flags) {
        cv::Point pt(x, y);
        if (event == cv::EVENT_LBUTTONDOWN) {
            prev_pt = pt;
        }
        else if (event == cv::EVENT_LBUTTONUP) {
            prev_pt = cv::Point(-1, -1);
        }

        if (prev_pt.x >= 0 && flags & cv::EVENT_FLAG_LBUTTON) {
            for (size_t i = 0; i < dests.size(); i++) {
                cv::line(dests[i], prev_pt, pt, colors_func()[i], 5);
            }
            dirty = true;
            prev_pt = pt;
            show();
        }
    }

private:
    cv::Point prev_pt;
    std::string windowname;
    std::vector<cv::Mat>& dests;
    std::function<std::vector<cv::Scalar>()> colors_func;
    bool dirty;
};

int main() {
    cv::Mat img = cv::imread("blemish.png", cv::IMREAD_COLOR);
    cv::Mat img_mask = img.clone();
    cv::Mat inpaintMask = cv::Mat::zeros(img.size(), CV_8U);
    Sketcher sketch("image", { img_mask, inpaintMask }, []() {
        return std::vector<cv::Scalar>{ cv::Scalar(255, 255, 255), cv::Scalar(255) };
    });

    while (true) {
        int ch = cv::waitKey();
        if (ch == 27) {
            break;
        }
        if (ch == 't') {
            cv::Mat res;
            cv::inpaint(img_mask, inpaintMask, res, 3, cv::INPAINT_TELEA);
            cv::imshow("Inpaint Output using FMM", res);
        }
        if (ch == 'n') {
            cv::Mat res;
            cv::inpaint(img_mask, inpaintMask, res, 3, cv::INPAINT_NS);
            cv::imshow("Inpaint Output using NS Technique", res);
        }
        if (ch == 'r') {
            img_mask = img.clone();
            inpaintMask = cv::Mat::zeros(img.size(), CV_8U);
            sketch.show();
        }
    }

    std::cout << "Completed" << std::endl;
    cv::destroyAllWindows();
    cv::imwrite("inpaintMask.png", inpaintMask);

    return 0;
}