//Prevent multiple declarations caused by including this header
//file from multiple locations. Naming convention is normally PACKAGE_PATH_FILE_H
#ifndef VEHICLE_CONTROLLER_H
#define VEHICLE_CONTROLLER_H


//ROS header
#include <ros/ros.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Float32.h>
#include <visualization_msgs/Marker.h>
#include <geometry_msgs/TwistStamped.h>
#include <geometry_msgs/Vector3.h>
#include "xbox_driver/XboxInterface.h"

//Namespace commonly matches ROS package name
namespace vehicle_controller{

  //Class name can be unique but commonly matches filename
  class Controls{
    public:
      Controls(ros::NodeHandle& n, ros::NodeHandle& pn);

    private:
      //Node-specific stuff here.

      //Variables
      //xbox_driver::XboxInterface xbox_msg;
      visualization_msgs::Marker vehicle_marker_;
      geometry_msgs::TwistStamped vehicle_twist_;
      geometry_msgs::Vector3 vehicle_dynamics_;
      std::string node_name_;
      int temp;

      //Subscribers
      ros::Subscriber sub_xbox_joy_cmds_;
      ros::Subscriber sub_vehicle_dynamics_;

      //Publishers
      ros::Publisher pub_vehicle_marker_;
      ros::Publisher pub_mobility_cmd_;

      //Functions
      void msgCallbackXboxCmds(const xbox_driver::XboxInterface::ConstPtr& msg);
      //void msgCallbackPubMarker(const visualization_msgs::Marker::ConstPtr& msg);
      void msgCallbackVehicleDynamics(const geometry_msgs::Vector3::ConstPtr& msg);

  };

}

#endif //Must always be last line of file
