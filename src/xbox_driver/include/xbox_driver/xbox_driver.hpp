//Prevent multiple declarations caused by including this header
//file from multiple locations. Naming convention is normally PACKAGE_PATH_FILE_H
#ifndef XBOX_H
#define XBOX_H


//ROS header
#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <std_msgs/Bool.h>
#include "xbox_driver/XboxInterface.h"

//Namespace commonly matches ROS package name
namespace xbox_driver{

  //Class name can be unique but commonly matches filename
  class Xbox{
    public:
      Xbox(ros::NodeHandle& n, ros::NodeHandle& pn);

    private:
    //Node-specific stuff here.

    //Variables
    xbox_driver::XboxInterface xbox_msg;
    std::string node_name_;
    ros::Timer heartbeat_timer_;

    //Subscribers
    ros::Subscriber sub_joystick_;

    //Publishers
    ros::Publisher pub_xbox_joy_cmds_;
    ros::Publisher pub_xbox_joy_heartbeat_;
    
    //Functions
    void msgCallbackJoystick(const sensor_msgs::Joy::ConstPtr& msg);
    void HeartbeatTimerCallback(const ros::TimerEvent& event);
    
  };

}

#endif //Must always be last line of file
