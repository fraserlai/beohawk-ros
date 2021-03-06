#include <ros/ros.h>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <art_common/timer.hpp>

using namespace std;

class boost_thread
{	
  private:
	ros::NodeHandle nh;
	art::Timer t;
	
  public:

	boost_thread(ros::NodeHandle& _nh): nh(_nh)
	{
		/// Output the number of cores in CPU.
		cout << endl << "Number of threads can be in parallel: " << boost::thread::hardware_concurrency() << endl;
		
		cv::Mat img = cv::imread("test.jpg"); // A 600 (col) * 400 (row) image, should be put in the ~/ folder
		
		/// These sub-images need to have overlapping regions with each other,
		/// so that enough information can be used to detect features on the boundaries.
		cv::Mat img1(img, cv::Rect(0, 0, 320, 220));
		cv::Mat img2(img, cv::Rect(280, 0, 320, 220));
		cv::Mat img3(img, cv::Rect(0, 180, 320, 220));
		cv::Mat img4(img, cv::Rect(280, 180, 320, 220));
		cv::Mat features, features1, features2, features3, features4;
		
		/// Test the original function and show the time elapsed.
		t.reset();
		original(img, features);
		t.echospan("Original");
		
		/// Test the multi-threading implementation and show the time elapsed.
		t.reset();
		boost::thread t1(&boost_thread::threading, this, img1, features1); // cv::Mat is a smart pointer itself.
		boost::thread t2(&boost_thread::threading, this, img2, features2);
		boost::thread t3(&boost_thread::threading, this, img3, features3);
		boost::thread t4(&boost_thread::threading, this, img4, features4);
		t1.join();
		t2.join();
		t3.join();
		t4.join();
		t.echospan("Multi-threading");
	}
	
	void original(cv::Mat _img, cv::Mat descriptors)
	{
		cv::SurfFeatureDetector surf_feature_detector;
		cv::SurfDescriptorExtractor surf_descriptor_extractor;
		vector<cv::KeyPoint> keypoints;
		surf_feature_detector.detect(_img, keypoints);
		surf_descriptor_extractor.compute(_img, keypoints, descriptors);
		cout << endl << "origianl " << descriptors.rows << endl;
	}
	
	void threading(cv::Mat _img, cv::Mat descriptors)
	{
		cv::SurfFeatureDetector surf_feature_detector;
		cv::SurfDescriptorExtractor surf_descriptor_extractor;
		vector<cv::KeyPoint> keypoints;
		surf_feature_detector.detect(_img, keypoints);
		surf_descriptor_extractor.compute(_img, keypoints, descriptors);
		cout << endl << "thread " << descriptors.rows << endl;
	}
	
	~boost_thread()
	{
		
	}
};

int main(int argc, char** argv)
{
	ros::init(argc, argv, "programming_standard_boost_thread");
	ros::NodeHandle nh;
	
	boost_thread bt(nh);
	
	ros::spin();
	return 0;
}
