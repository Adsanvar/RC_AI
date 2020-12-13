//ROS and node class header file
#include "xbox_driver/xbox_driver.hpp"


int main(int argc, char** argv)
{
  //Initialize ROS and declar node handles
  ros::init(argc, argv, "xbox_driver"); //Registers node with core. Can be named anything
  ros::NodeHandle n; //Declare public nodehandle
  ros::NodeHandle pn("~"); //Declar private nodehandle

  //Initialize node class
  //Creates instance of a class that will implement the functionality of the node
  xbox_driver::Xbox node(n, pn);


  //Spin and process callbacks
  ros::spin(); //Wait in rospin until program is stopped.
}
