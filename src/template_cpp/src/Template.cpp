// Header file for this class
#include "template_cpp/Template.hpp"

// Namespace commnly matches ROS package name
namespace template_cpp
{
  // Constructor with global and private node handle arguments
  Template::Template(ros::NodeHandle& n, ros::NodeHandle& pn)
  {
    ROS_INFO("This node is running successfully"); //Print to console
  }


}