#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;


int main() {
    string directory = "/home/pappykunj/Desktop/newfolder";

    Mat image_1 = imread(directory + "/image1.bmp",IMREAD_COLOR);
    Mat image_2 = imread(directory + "/image2.bmp",IMREAD_COLOR);
    Mat image_3 = imread(directory + "/image3.bmp",IMREAD_COLOR);
    Mat image_4 = imread(directory + "/image4.bmp",IMREAD_COLOR);
    if(image_1.rows==720 && image_2.rows==720 && image_3.rows==720 && image_4.rows==720)
    {
        // Created a blank canvas 
        Mat input = Mat::zeros(Size(2560,1440),CV_8UC3);

        for(int i=0;i<input.rows;i++)
        {
            for(int j=0;j<input.cols;j++)
            {
                if(i<720 && j<1280)
                    input.at<Vec3b>(i,j)=image_1.at<Vec3b>(i,j);
                if(i<720 && j>=1280)
                    input.at<Vec3b>(i,j)=image_2.at<Vec3b>(i,j-1280);
                if(i>=720 && j<1280)
                    input.at<Vec3b>(i,j)=image_3.at<Vec3b>(i-720,j);
                if(i>=720 && j>=1280)
                    input.at<Vec3b>(i,j)=image_4.at<Vec3b>(i-720,j-1280);
            }
        }
        bool check = imwrite(directory + "/output.bmp", input);
        // imshow("Result",input);
        waitKey(0);

    }
    return 0;

} 
