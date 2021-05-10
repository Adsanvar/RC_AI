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
    sub_joystick_ = n.subscribe<sensor_msgs::Joy>("/joy", 1, &Xbox::msgCallbackJoystick, this);

    //Define Publishers
    pub_xbox_joy_cmds_ = n.advertise<xbox_driver::XboxInterface>(node_name_ + "/xbox_joy_cmds", 10); //Set pub rate 10Hz for testing only.
    
    ROS_INFO("This node is running successfully"); //Print to console
  }

  void Xbox::msgCallbackJoystick(const sensor_msgs::Joy::ConstPtr& msg)
  {
    ROS_INFO("I am here!");
    // Copy ROS message data to new message
    /*
    xbox_msg.Drive = msg->buttons[0];
    xbox_msg.Reverse = msg->buttons[1];
    xbox_msg.Park = msg->buttons[2];
    xbox_msg.Neutral = msg->buttons[3];
    xbox_msg.ClearFaults = msg->buttons[4];
    xbox_msg.Ignition = msg->buttons[5];
    xbox_msg.Throttle = msg->axes[2];
    xbox_msg.Brake = msg->axes[3];
    xbox_msg.LeftSteer = msg->axes[0];
    xbox_msg.RightSteer = msg->axes[1];

    //Publish Message
    pub_xbox_joy_cmds_.publish(xbox_msg);
    */
  }
}
