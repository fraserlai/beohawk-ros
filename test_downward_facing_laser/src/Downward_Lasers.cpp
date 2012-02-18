
#include <ros/ros.h>
#include <cmath>
#include <iostream>
#include <cv.h>
#include <sensor_msgs/Image.h>
#include <cv_bridge/cv_bridge.h>
#include <boost/foreach.hpp>
#include <boost/shared_ptr.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <Eigen/Eigen>


using namespace std;

using cv::Mat;
using namespace Eigen;

class Downward_Lasers
{	
  public:
	ros::NodeHandle nh;
	ros::Subscriber sub_image;
	uint sub_image_count;
	
	Mat img_color;
	Mat img_green;
	Mat img_not_green;
	Mat img_green_blur;
	Mat img_not_green_blur;
	Mat img_laser_points_no_thresh;
	Mat img_laser_points;
	Mat img_laser_points_maxed;
	
	cv::Point* points[4];
	
	int num_points;
	
	int green_blur_amt;
	int not_green_blur_amt;

	int threshold;
	
	int image_select;
	int filter_source;
	int frameRateSlower;
	
	
  public:

	Downward_Lasers(ros::NodeHandle& _nh)
	{
		nh = _nh;
		
		img_color = Mat(cv::Size(640, 480), CV_8UC3);
		img_green = Mat(cv::Size(640, 480), CV_8UC1);
		img_not_green = Mat(cv::Size(640, 480), CV_8UC1);
		img_green_blur = Mat(cv::Size(640, 480), CV_8UC1);
		img_not_green_blur = Mat(cv::Size(640, 480), CV_8UC1);
		img_laser_points_no_thresh = Mat(cv::Size(640, 480), CV_8UC1);
		img_laser_points = Mat(cv::Size(640, 480), CV_8UC1);
		img_laser_points_maxed = Mat(cv::Size(640, 480), CV_8UC1);
		
		num_points = 4;
		
		for(int i = 0; i < 4; i++)
		{
			points[i] = new cv::Point();
		}
		
		green_blur_amt = 3;
		not_green_blur_amt = 8;
		
		threshold = 128;
		
		image_select = 0;
		filter_source = 0;
		frameRateSlower = 4;

		sub_image_count = 0;
		sub_image = nh.subscribe("/usb_cam/image_raw", 10, &Downward_Lasers::sub_image_callback, this);
		
		cv::namedWindow("Image");
		cv::namedWindow("Filtered Result");
		cv::namedWindow("Parameters");
		
		cv::createTrackbar( "Green Blur","Parameters", &green_blur_amt, 50, 0 );
		cv::createTrackbar( "Not Green Blur","Parameters", &not_green_blur_amt, 50, 0 );
		cv::createTrackbar( "Threshold","Parameters", &threshold, 255, 0 );
		cv::createTrackbar( "Image Select- C, G, NG, GB, NGB, L","Parameters", &image_select, 5, 0 );
		cv::createTrackbar( "FLT Src Select- LNT, LT","Parameters", &filter_source, 1, 0 );
		cv::createTrackbar( "num_points","Parameters", &num_points, 4, 0 );
		cv::createTrackbar( "'frame rate' slowing","Parameters", &frameRateSlower, 20, 0 );
	}
	
	~Downward_Lasers()
	{
		cv::destroyWindow("Image");
		cv::destroyWindow("Filtered Result");
		cv::destroyWindow("Parameters");
		img_color.release();
		img_green.release();
		img_not_green.release();
		img_green_blur.release();
		img_not_green_blur.release();
		img_laser_points.release();
	}
	
	void sub_image_callback(const sensor_msgs::ImageConstPtr& msg)
	{
		if(sub_image_count % (frameRateSlower + 1) == 0)
		{
			std::cout << "\n" << std::endl;
			convert_image(msg, img_color);
			
			//get the green and not green images
			vector<Mat> imageChannels;
			cv::split(img_color, imageChannels);
			img_green = imageChannels[1];
			img_not_green = ((imageChannels[0] + imageChannels[2]) * 2) - imageChannels[1];

			
			
			//filter the image
			if(green_blur_amt % 2 == 0)
				green_blur_amt++;
			if(not_green_blur_amt % 2 == 0)
				not_green_blur_amt++;
			
			cv::GaussianBlur( img_green, img_green_blur, cv::Size(green_blur_amt, green_blur_amt), 0, 0 );
			cv::GaussianBlur( img_not_green, img_not_green_blur, cv::Size(not_green_blur_amt, not_green_blur_amt), 0, 0 );

			img_laser_points_no_thresh = img_green_blur - img_not_green_blur;
			cv::threshold(img_laser_points_no_thresh, img_laser_points, threshold, 255, cv::THRESH_BINARY);
					
			
			//find the top 4 points

			for(int i = 0; i < num_points; i++)
			{
				int blackoutRadius = 25;
				double max_val = 0;
				switch(filter_source)
				{
					default:
					case 0:
						img_laser_points_maxed = img_laser_points_no_thresh;
						break;
					case 1:
						img_laser_points_maxed = img_laser_points;
						break;
				}
				minMaxLoc(img_laser_points_maxed, NULL, &max_val, NULL, points[i]);
				std::cout << i << "  X: " << points[i]->x << " Y: " << points[i]->y << "  Max Value: " << max_val << std::endl;
				cv::circle(img_laser_points_maxed, *points[i], blackoutRadius, 0, -1, 8, 0);	//black out a region
			}
			std::cout << std::endl;
			
			
			//Draw circles on the color image
			for(int i = 0; i < num_points; i++)
			{
				cv::circle(img_color, *points[i] /*cv::Point(points[i]->x, points[i]->y)*/, 8, cv::Scalar(0,0,255), 2, 8, 0);
			}
					
			switch(filter_source)
			{
				case 0:
					cv::imshow("Filtered Result", img_laser_points_no_thresh);
					break;
				case 1:
					cv::imshow("Filtered Result", img_laser_points);
					break;
				default:
					cv::imshow("Filtered Result", img_laser_points);
					break;
			}
			
			switch(image_select)
			{
				case 0:
					cv::imshow("Image", img_color);
					break;
				case 1:
					cv::imshow("Image", img_green);
					break;
				case 2:
					cv::imshow("Image", img_not_green);
					break;
				case 3:
					cv::imshow("Image", img_green_blur);
					break;
				case 4:
					cv::imshow("Image", img_not_green_blur);
					break;
				case 5:
					cv::imshow("Image", img_laser_points_no_thresh);
					break;
				default:
					cv::imshow("Image", img_color);
					break;
	
			}

			planeFinder(points);

			cv::waitKey(1);
		}
		//cout << sub_image_count << endl;
		++ sub_image_count;
	}

  private:

	void convert_image(const sensor_msgs::ImageConstPtr& _msg, Mat& _img)
	{
		cv_bridge::CvImageConstPtr cv_image_ptr;
		cv_image_ptr = cv_bridge::toCvShare(_msg, "bgr8");
		_img = cv_image_ptr->image;
	}
	
	void planeFinder(cv::Point* points[])
	{
		vector<cv::Point> sorted_points; // = new vector<cv::Point>();
		vector<cv::Point> points_vector; // = new vector<cv::Point>();
		
		
		//begin simple by x point sort
		
		//vector<Point> fixed_laser_points;
		vector<int> xCoords; // = new vector<int>();
		vector<int> yCoords; // = new vector<int>();
		
		int x_center = 320;
		int y_center = 240;
		
		for(int i = 0 ; i < num_points; i++)
		{
			points_vector.push_back(*points[i]);
			xCoords.push_back(points_vector[i].x);
			yCoords.push_back(points_vector[i].y);
		}
		
		std::sort(xCoords.begin(), xCoords.end());
		std::sort(yCoords.begin(), yCoords.end());
		
		for(int i = 0; i < xCoords.size(); i++)
		{
			int x_coord = xCoords[i];
			
			for(int j = 0; j < points_vector.size(); j++)
			{
				if(points_vector[j].x == x_coord)
				{
					sorted_points.push_back(points_vector[j]);
				}
			}
		}
		
		std::cout << "SORTED POINTS:  " << std::endl;
		for(int i = 0 ; i < sorted_points.size(); i++)
		{
			std::cout << sorted_points[i] << std::endl;
		}
		std::cout << std::endl;
		
		//end somple sort by x
		
		
		//eig
		Vector4f x;
		Vector4f y;
		Vector4f z;
		
		for(int i = 0; i < xCoords.size(); i++)
		{
			//map pixel values to between -1 and 1
			x(i) = xCoords.at(i);	//subtract or dicivde to convert to whatever everything else needs.  -240 or something?
			y(i) = yCoords.at(i);
			std::cout << "X: " << x(i) << "  Y: " << y(i) << std::endl;
		}
		
		
		Vector4f p(1, -1, 0, 0);
		Vector4f q(0, 0, 1, -1);
		
		Vector2f a;
		Vector2f b;
		Matrix<float, 2, 2> D;
		Vector2f v;
		
		Matrix<float, 4, 3> A;
		Matrix<float, 3, 2> A2;
		
		
		Vector3f w;
		
		p.transposeInPlace();
		q.transposeInPlace();
		
		for(int i = 0; i < 4; i++)
		{
			a << p(i), q(i);
			a.transposeInPlace();
			
			D = a * (a.transpose() * a).inverse() * a.transpose();	//what am i inverting?
			
			b << x(i), y(i);
			v = D * b/*.transpose()*/;
			
			z(i) = ((a.transpose() * a).cwiseSqrt())(0) / ((v.transpose() * v).cwiseSqrt())(0);	//a is a nxm matrix a.transpose * a is mxm matrix  representing (x^2 + y^2)
			
		}
		
		A << x(0), y(0), 1,
			 x(1), y(1), 1,
			 x(2), y(2), 1,
			 x(3), y(3), 1;
		
		w = (A.transpose() * A).inverse() * A.transpose() * z;
		
		
		float tan_theta = w(0);
		float tan_phi = w(1);
		float g = w(2);
		
		float theta = atan(tan_theta);
		float theta_d = theta * ((float)180 / (float) M_PI);
		
		float phi = atan(tan_phi);
		float phi_d = phi * ((float)180 / (float) M_PI);
		
		
		A2 << 1, 0,
			  0, 1,
			  w(1), w(2);
			  
			  
		Vector3f gVector;
		gVector << 0,0,g;
		gVector.transposeInPlace();
		
		Vector3f position;
		float height;
		
		position = A2 * (A2.transpose() * A2).inverse() * A2.transpose() * gVector;
		height = ((position - gVector).transpose() * (position - gVector)).cwiseSqrt()(0);
		
		
		std::cout << "Height: " << height << std::endl;
		std::cout << "Position: " << position(0) << ", " << position(1) << ", " << position(2) << std::endl;
		
		//end eig
		
		
	
	}
	
};

int main(int argc, char** argv)
{
	ros::init(argc, argv, "test_downward_facing_lasers");
	ros::NodeHandle nh;
	
	Downward_Lasers downward_lasers(nh);
	
	ros::spin();
	return 0;
}