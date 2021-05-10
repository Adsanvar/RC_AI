// Header file for this class
#include "xbox_driver/xbox_driver.hpp"

// Namespace commnly matches ROS package name
namespace xbox_driver
{
  // Constructor with global and private node handle arguments
  Xbox::Xbox(ros::NodeHandle& n, ros::NodeHandle& pn)
  {
    node_name_ = ros::this_node::getName();

    //Define Subscribers
    sub_joystick_ = n.subscribe<sensor_msgs::Joy>("/joy", 10, &Xbox::msgCallbackJoystick, this);

    //Define Publishers
    pub_xbox_joy_cmds_ = n.advertise<xbox_driver::XboxInterface>("/xbox_joy_cmds", 10);

    ROS_INFO("This node is running successfully"); //Print to console
  }

  void Xbox::msgCallbackJoystick(const sensor_msgs::Joy::ConstPtr& msg)
  {
    // Copy ROS message data to new message
    xbox_msg.Reverse = msg->buttons[0];
    xbox_msg.Neutral = msg->buttons[1];
    xbox_msg.Park = msg->buttons[2];
    xbox_msg.Drive = msg->buttons[3];
    xbox_msg.ClearFaults = msg->buttons[7];
    xbox_msg.Ignition = msg->buttons[8];
    xbox_msg.Steering = msg->axes[0];
    xbox_msg.Brake = msg->axes[2];
    xbox_msg.Throttle = msg->axes[5];

    //Publish Message
    pub_xbox_joy_cmds_.publish(xbox_msg);
  }
}
