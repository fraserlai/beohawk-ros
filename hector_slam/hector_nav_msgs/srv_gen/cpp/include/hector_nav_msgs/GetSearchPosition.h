/* Auto-generated by genmsg_cpp for file /home/tallevy/ros-workspace/hector_slam/hector_nav_msgs/srv/GetSearchPosition.srv */
#ifndef HECTOR_NAV_MSGS_SERVICE_GETSEARCHPOSITION_H
#define HECTOR_NAV_MSGS_SERVICE_GETSEARCHPOSITION_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"

#include "ros/service_traits.h"

#include "geometry_msgs/PoseStamped.h"


#include "geometry_msgs/PoseStamped.h"

namespace hector_nav_msgs
{
template <class ContainerAllocator>
struct GetSearchPositionRequest_ {
  typedef GetSearchPositionRequest_<ContainerAllocator> Type;

  GetSearchPositionRequest_()
  : ooi_pose()
  , distance(0.0)
  {
  }

  GetSearchPositionRequest_(const ContainerAllocator& _alloc)
  : ooi_pose(_alloc)
  , distance(0.0)
  {
  }

  typedef  ::geometry_msgs::PoseStamped_<ContainerAllocator>  _ooi_pose_type;
   ::geometry_msgs::PoseStamped_<ContainerAllocator>  ooi_pose;

  typedef float _distance_type;
  float distance;


private:
  static const char* __s_getDataType_() { return "hector_nav_msgs/GetSearchPositionRequest"; }
public:
  ROS_DEPRECATED static const std::string __s_getDataType() { return __s_getDataType_(); }

  ROS_DEPRECATED const std::string __getDataType() const { return __s_getDataType_(); }

private:
  static const char* __s_getMD5Sum_() { return "a579e8b989d066f6c17946ab060a6ff9"; }
public:
  ROS_DEPRECATED static const std::string __s_getMD5Sum() { return __s_getMD5Sum_(); }

  ROS_DEPRECATED const std::string __getMD5Sum() const { return __s_getMD5Sum_(); }

private:
  static const char* __s_getServerMD5Sum_() { return "a28d7c2840927c12082b304156df4111"; }
public:
  ROS_DEPRECATED static const std::string __s_getServerMD5Sum() { return __s_getServerMD5Sum_(); }

  ROS_DEPRECATED const std::string __getServerMD5Sum() const { return __s_getServerMD5Sum_(); }

private:
  static const char* __s_getMessageDefinition_() { return "\n\
\n\
geometry_msgs/PoseStamped ooi_pose\n\
float32 distance\n\
\n\
================================================================================\n\
MSG: geometry_msgs/PoseStamped\n\
# A Pose with reference coordinate frame and timestamp\n\
Header header\n\
Pose pose\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of postion and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
\n\
"; }
public:
  ROS_DEPRECATED static const std::string __s_getMessageDefinition() { return __s_getMessageDefinition_(); }

  ROS_DEPRECATED const std::string __getMessageDefinition() const { return __s_getMessageDefinition_(); }

  ROS_DEPRECATED virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
  {
    ros::serialization::OStream stream(write_ptr, 1000000000);
    ros::serialization::serialize(stream, ooi_pose);
    ros::serialization::serialize(stream, distance);
    return stream.getData();
  }

  ROS_DEPRECATED virtual uint8_t *deserialize(uint8_t *read_ptr)
  {
    ros::serialization::IStream stream(read_ptr, 1000000000);
    ros::serialization::deserialize(stream, ooi_pose);
    ros::serialization::deserialize(stream, distance);
    return stream.getData();
  }

  ROS_DEPRECATED virtual uint32_t serializationLength() const
  {
    uint32_t size = 0;
    size += ros::serialization::serializationLength(ooi_pose);
    size += ros::serialization::serializationLength(distance);
    return size;
  }

  typedef boost::shared_ptr< ::hector_nav_msgs::GetSearchPositionRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::hector_nav_msgs::GetSearchPositionRequest_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct GetSearchPositionRequest
typedef  ::hector_nav_msgs::GetSearchPositionRequest_<std::allocator<void> > GetSearchPositionRequest;

typedef boost::shared_ptr< ::hector_nav_msgs::GetSearchPositionRequest> GetSearchPositionRequestPtr;
typedef boost::shared_ptr< ::hector_nav_msgs::GetSearchPositionRequest const> GetSearchPositionRequestConstPtr;


template <class ContainerAllocator>
struct GetSearchPositionResponse_ {
  typedef GetSearchPositionResponse_<ContainerAllocator> Type;

  GetSearchPositionResponse_()
  : search_pose()
  {
  }

  GetSearchPositionResponse_(const ContainerAllocator& _alloc)
  : search_pose(_alloc)
  {
  }

  typedef  ::geometry_msgs::PoseStamped_<ContainerAllocator>  _search_pose_type;
   ::geometry_msgs::PoseStamped_<ContainerAllocator>  search_pose;


private:
  static const char* __s_getDataType_() { return "hector_nav_msgs/GetSearchPositionResponse"; }
public:
  ROS_DEPRECATED static const std::string __s_getDataType() { return __s_getDataType_(); }

  ROS_DEPRECATED const std::string __getDataType() const { return __s_getDataType_(); }

private:
  static const char* __s_getMD5Sum_() { return "6cc90c22cc49490b4dd1ef4798491231"; }
public:
  ROS_DEPRECATED static const std::string __s_getMD5Sum() { return __s_getMD5Sum_(); }

  ROS_DEPRECATED const std::string __getMD5Sum() const { return __s_getMD5Sum_(); }

private:
  static const char* __s_getServerMD5Sum_() { return "a28d7c2840927c12082b304156df4111"; }
public:
  ROS_DEPRECATED static const std::string __s_getServerMD5Sum() { return __s_getServerMD5Sum_(); }

  ROS_DEPRECATED const std::string __getServerMD5Sum() const { return __s_getServerMD5Sum_(); }

private:
  static const char* __s_getMessageDefinition_() { return "geometry_msgs/PoseStamped search_pose\n\
\n\
\n\
\n\
================================================================================\n\
MSG: geometry_msgs/PoseStamped\n\
# A Pose with reference coordinate frame and timestamp\n\
Header header\n\
Pose pose\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of postion and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
\n\
"; }
public:
  ROS_DEPRECATED static const std::string __s_getMessageDefinition() { return __s_getMessageDefinition_(); }

  ROS_DEPRECATED const std::string __getMessageDefinition() const { return __s_getMessageDefinition_(); }

  ROS_DEPRECATED virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
  {
    ros::serialization::OStream stream(write_ptr, 1000000000);
    ros::serialization::serialize(stream, search_pose);
    return stream.getData();
  }

  ROS_DEPRECATED virtual uint8_t *deserialize(uint8_t *read_ptr)
  {
    ros::serialization::IStream stream(read_ptr, 1000000000);
    ros::serialization::deserialize(stream, search_pose);
    return stream.getData();
  }

  ROS_DEPRECATED virtual uint32_t serializationLength() const
  {
    uint32_t size = 0;
    size += ros::serialization::serializationLength(search_pose);
    return size;
  }

  typedef boost::shared_ptr< ::hector_nav_msgs::GetSearchPositionResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::hector_nav_msgs::GetSearchPositionResponse_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct GetSearchPositionResponse
typedef  ::hector_nav_msgs::GetSearchPositionResponse_<std::allocator<void> > GetSearchPositionResponse;

typedef boost::shared_ptr< ::hector_nav_msgs::GetSearchPositionResponse> GetSearchPositionResponsePtr;
typedef boost::shared_ptr< ::hector_nav_msgs::GetSearchPositionResponse const> GetSearchPositionResponseConstPtr;

struct GetSearchPosition
{

typedef GetSearchPositionRequest Request;
typedef GetSearchPositionResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;
}; // struct GetSearchPosition
} // namespace hector_nav_msgs

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::hector_nav_msgs::GetSearchPositionRequest_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::hector_nav_msgs::GetSearchPositionRequest_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::hector_nav_msgs::GetSearchPositionRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "a579e8b989d066f6c17946ab060a6ff9";
  }

  static const char* value(const  ::hector_nav_msgs::GetSearchPositionRequest_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xa579e8b989d066f6ULL;
  static const uint64_t static_value2 = 0xc17946ab060a6ff9ULL;
};

template<class ContainerAllocator>
struct DataType< ::hector_nav_msgs::GetSearchPositionRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "hector_nav_msgs/GetSearchPositionRequest";
  }

  static const char* value(const  ::hector_nav_msgs::GetSearchPositionRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::hector_nav_msgs::GetSearchPositionRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "\n\
\n\
geometry_msgs/PoseStamped ooi_pose\n\
float32 distance\n\
\n\
================================================================================\n\
MSG: geometry_msgs/PoseStamped\n\
# A Pose with reference coordinate frame and timestamp\n\
Header header\n\
Pose pose\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of postion and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
\n\
";
  }

  static const char* value(const  ::hector_nav_msgs::GetSearchPositionRequest_<ContainerAllocator> &) { return value(); } 
};

} // namespace message_traits
} // namespace ros


namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::hector_nav_msgs::GetSearchPositionResponse_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::hector_nav_msgs::GetSearchPositionResponse_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::hector_nav_msgs::GetSearchPositionResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "6cc90c22cc49490b4dd1ef4798491231";
  }

  static const char* value(const  ::hector_nav_msgs::GetSearchPositionResponse_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x6cc90c22cc49490bULL;
  static const uint64_t static_value2 = 0x4dd1ef4798491231ULL;
};

template<class ContainerAllocator>
struct DataType< ::hector_nav_msgs::GetSearchPositionResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "hector_nav_msgs/GetSearchPositionResponse";
  }

  static const char* value(const  ::hector_nav_msgs::GetSearchPositionResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::hector_nav_msgs::GetSearchPositionResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "geometry_msgs/PoseStamped search_pose\n\
\n\
\n\
\n\
================================================================================\n\
MSG: geometry_msgs/PoseStamped\n\
# A Pose with reference coordinate frame and timestamp\n\
Header header\n\
Pose pose\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of postion and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
\n\
";
  }

  static const char* value(const  ::hector_nav_msgs::GetSearchPositionResponse_<ContainerAllocator> &) { return value(); } 
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::hector_nav_msgs::GetSearchPositionRequest_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.ooi_pose);
    stream.next(m.distance);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct GetSearchPositionRequest_
} // namespace serialization
} // namespace ros


namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::hector_nav_msgs::GetSearchPositionResponse_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.search_pose);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct GetSearchPositionResponse_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace service_traits
{
template<>
struct MD5Sum<hector_nav_msgs::GetSearchPosition> {
  static const char* value() 
  {
    return "a28d7c2840927c12082b304156df4111";
  }

  static const char* value(const hector_nav_msgs::GetSearchPosition&) { return value(); } 
};

template<>
struct DataType<hector_nav_msgs::GetSearchPosition> {
  static const char* value() 
  {
    return "hector_nav_msgs/GetSearchPosition";
  }

  static const char* value(const hector_nav_msgs::GetSearchPosition&) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<hector_nav_msgs::GetSearchPositionRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "a28d7c2840927c12082b304156df4111";
  }

  static const char* value(const hector_nav_msgs::GetSearchPositionRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<hector_nav_msgs::GetSearchPositionRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "hector_nav_msgs/GetSearchPosition";
  }

  static const char* value(const hector_nav_msgs::GetSearchPositionRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<hector_nav_msgs::GetSearchPositionResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "a28d7c2840927c12082b304156df4111";
  }

  static const char* value(const hector_nav_msgs::GetSearchPositionResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<hector_nav_msgs::GetSearchPositionResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "hector_nav_msgs/GetSearchPosition";
  }

  static const char* value(const hector_nav_msgs::GetSearchPositionResponse_<ContainerAllocator> &) { return value(); } 
};

} // namespace service_traits
} // namespace ros

#endif // HECTOR_NAV_MSGS_SERVICE_GETSEARCHPOSITION_H

