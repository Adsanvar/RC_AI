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
    sub_xbox_joy_cmds_ = n.subscribe<xbox_driver::XboxInterface>("/xbox_joy_publisher/xbox_joy_cmds", 10, &Controls::msgCallbackXboxCmds, this);
    sub_vehicle_dynamics_ = n.subscribe<geometry_msgs::Vector3Stamped>("/vehicle_dynamics", 10, &Controls::msgCallbackVehicleDynamics, this);

    //Define Publishers
    pub_mobility_cmd_ = n.advertise<geometry_msgs::TwistStamped>("/MobilityCmd", 10);
    pub_vehicle_marker_ = n.advertise<visualization_msgs::Marker>("/VehicleMarker", 10);

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

    //Need to create and update state machine based on controller inputs

    //Get ROS time
    vehicle_twist_.header.stamp = ros::Time::now();

    vehicle_twist_.twist.linear.x = msg->Throttle;
    vehicle_twist_.twist.angular.z = msg->Steering;

    pub_mobility_cmd_.publish(vehicle_twist_);

    /*
    //Initialize Header
    //Check if vehicle is ON
    if(msg.Ignition == true){

      //Check if vehicle is in Park/Drive
      if(msg.Drive == true){
        vehicle_twist_.linear.x = msg.Throttle;
        vehicle_twist_.angular.z = msg.Steering;
      }

      if(msg.Park == true){
        vehicle_twist_.linear.x = 0;
        vehicle_twist_.angular.z = 0;
      }


    }else{
      //Do Nothing
    }
    */

}

  //Publisher Callback for Visualization of Marker in Rviz
  void Controls::msgCallbackVehicleDynamics(const geometry_msgs::Vector3Stamped::ConstPtr& msg)
  {

    //Get ROS time
    vehicle_marker_.header.stamp = ros::Time::now();

    //Select Marker Parameters
    vehicle_marker_.header.frame_id = "base_link";

    vehicle_marker_.ns = "basic_shapes";
    vehicle_marker_.id = 0;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    vehicle_marker_.type = visualization_msgs::Marker::CUBE;

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    vehicle_marker_.action = visualization_msgs::Marker::ADD;

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    vehicle_marker_.pose.position.x = msg->vector.x;
    vehicle_marker_.pose.position.y = msg->vector.y;
    vehicle_marker_.pose.position.z = 1;
    vehicle_marker_.pose.orientation.x = 0.0;
    vehicle_marker_.pose.orientation.y = 0.0;
    vehicle_marker_.pose.orientation.z = 0.0;
    vehicle_marker_.pose.orientation.w = 1.0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    vehicle_marker_.scale.x = 2.0;
    vehicle_marker_.scale.y = 1.0;
    vehicle_marker_.scale.z = 1.0;

    // Set the color -- be sure to set alpha to something non-zero!
    vehicle_marker_.color.r = 0.0f;
    vehicle_marker_.color.g = 1.0f;
    vehicle_marker_.color.b = 0.0f;
    vehicle_marker_.color.a = 1.0;

    pub_vehicle_marker_.publish(vehicle_marker_);

  }
}
