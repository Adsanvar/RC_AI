// Header file for this class
#include "vehicle_controller/vehicle_controller.hpp"

// Namespace commnly matches ROS package name
namespace vehicle_controller
{
  // Constructor with global and private node handle arguments
  Controls::Controls(ros::NodeHandle& n, ros::NodeHandle& pn)
  {
    ROS_INFO("This node is running successfully"); //Print to console
  }


}
