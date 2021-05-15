//Prevent multiple declarations caused by including this header
//file from multiple locations. Naming convention is normally PACKAGE_PATH_FILE_H
#ifndef VEHICLE_CONTROLLER_H
#define VEHICLE_CONTROLLER_H


//ROS header
#include <ros/ros.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Float32.h>
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
      xbox_driver::XboxInterface xbox_msg;
      std::string node_name_;
      int temp;

      //Subscribers
      ros::Subscriber sub_xbox_joy_cmds_;

      //Publishers
      //ros::Publisher pub_;
      
      //Functions
      void msgCallbackXboxCmds(const sensor_msgs::Joy::ConstPtr& msg);



  };

}

#endif //Must always be last line of file
