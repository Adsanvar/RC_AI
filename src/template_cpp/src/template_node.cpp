//ROS and node class header file
#include "template_cpp/Template.hpp"


int main(int argc, char** argv)
{
  //Initialize ROS and declar node handles
  ros::init(argc, argv, "template_node"); //This indicates node name at runtime. Can be named anything
  ros::NodeHandle n; //Declare public nodehandle
  ros::NodeHandle pn("~"); //Declar private nodehandle

  //Initialize node class
  //Creates instance of a class that will implement the functionality of the node
  template_cpp::Template node(n, pn);


  //Spin and process callbacks
  ros::spin(); //Wait in rospin until program is stopped.
}