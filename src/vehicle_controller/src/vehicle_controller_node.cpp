//ROS and node class header file
#include "vehicle_controller/vehicle_controller.hpp"


int main(int argc, char** argv)
{
  //Initialize ROS and declar node handles
  ros::init(argc, argv, "vehicle_controller"); //Registers node with core. Can be named anything
  ros::NodeHandle n; //Declare public nodehandle
  ros::NodeHandle pn("~"); //Declar private nodehandle

  //Initialize node class
  //Creates instance of a class that will implement the functionality of the node
  vehicle_controller::Controls node(n, pn);


  //Spin and process callbacks
  ros::spin(); //Wait in rospin until program is stopped.
}
