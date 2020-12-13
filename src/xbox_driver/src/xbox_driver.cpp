// Header file for this class
#include "xbox_driver/xbox_driver.hpp"

// Namespace commnly matches ROS package name
namespace xbox_driver
{
  // Constructor with global and private node handle arguments
  Xbox::Xbox(ros::NodeHandle& n, ros::NodeHandle& pn)
  {
    ROS_INFO("This node is running successfully"); //Print to console
  }


}
