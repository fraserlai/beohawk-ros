//      message_filters.cpp
//      Synchronization of messages based on message_filters package.
//
//      Copyright (C) 2011 Sam (Yujia Zhai) <yujia.zhai@usc.edu>
//      Aerial Robotics Team, USC Robotics Society - http://www.uscrs.org - http://uscrs.googlecode.com
//
//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//      
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//      
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.

#include <ros/ros.h>
#include <iomanip>
#include <opencv2/core/core.hpp>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/Image.h>
#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>

using namespace std;

typedef cv::Mat Mat;
typedef ros::Time Time;

class Test_Message_Filters
{
  public:	
	ros::NodeHandle nh;
	
	message_filters::Subscriber<sensor_msgs::PointCloud2> sub_points;
	message_filters::Subscriber<sensor_msgs::Image> sub_image;
	typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::PointCloud2, sensor_msgs::Image> Policy_sync_subs;
	message_filters::Synchronizer<Policy_sync_subs> sync_subs;
	
	
	Test_Message_Filters(ros::NodeHandle& _nh): nh(_nh),
		sub_points(nh, "/camera/rgb/points" , 10),
		sub_image(nh, "/camera/rgb/image_color" , 10),
		sync_subs(Policy_sync_subs(10),sub_points, sub_image)
		
	{
		sub_points.registerCallback(&Test_Message_Filters::sub_points_callback, this);
		sub_image.registerCallback(&Test_Message_Filters::sub_image_callback, this);
		sync_subs.registerCallback(boost::bind(&Test_Message_Filters::sync_subs_callback, this, _1, _2));
		
	}
	
	void sync_subs_callback(const sensor_msgs::PointCloud2::ConstPtr& _msg_points, const sensor_msgs::Image::ConstPtr& _msg_image)
	{
		cout << endl << "\t\t\t\t\t\t" << _msg_points->header.stamp << " " << _msg_image->header.stamp;
	}
	
	void sub_points_callback(const sensor_msgs::PointCloud2::ConstPtr& _msg)
	{
		cout << endl << _msg->header.stamp;
	}
	void sub_image_callback(const sensor_msgs::Image::ConstPtr& _msg)
	{
		cout << endl << "\t\t\t" << _msg->header.stamp;
	}
	
	~Test_Message_Filters()
	{
		cout << endl;
	}
};

int main(int argc, char** argv)
{
	ros::init(argc, argv, "test_message_filters");
	ros::NodeHandle nh;
	
	Test_Message_Filters test_message_filters(nh);
	
	ros::Rate loop_rate(10);
	while(ros::ok())
	{	
		ros::spinOnce();
		loop_rate.sleep();
	}
	return 0;
}
