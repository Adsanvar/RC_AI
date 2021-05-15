// Header file for this class
#include "vehicle_controller/vehicle_controller.hpp"

// Namespace commnly matches ROS package name
namespace vehicle_controller
{
  // Constructor with global and private node handle arguments
  Controls::Controls(ros::NodeHandle& n, ros::NodeHandle& pn)
  {
  
    node_name_ = ros::this_node::getName();

    //Define Subscribers
    sub_xbox_joy_cmds_ = n.subscribe<xbox_driver::XboxInterface>("/xbox_joy_cmds", 10, &Xbox::msgCallbackJoystick, this);

    //Define Publishers
    
    ROS_INFO("This node is running successfully"); //Print to console
  }

  void Controls::msgCallbackXboxCmds(const xbox_driver::XboxInterface::ConstPtr& msg)
  {
    // Copy ROS message data to new message
    /* Currently just for reference
    msg.Reverse
    msg.Neutral
    msg.Park
    msg.Drive
    msg.ClearFaults
    msg.Ignition
    msg.Steering
    msg.Brake
    msg.Throttle
    */
    float speed = 0.0;
    //Convert Joystick commands to yaw and velocity
    if(msg.Ignition == true)
    {
      speed = 0;
    }else
    {
      speed = 0;
    }
    
    //Publish Message
   
  }

  //void calculate_velocity()

}
