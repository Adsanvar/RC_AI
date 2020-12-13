//Prevent multiple declarations caused by including this header
//file from multiple locations. Naming convention is normally PACKAGE_PATH_FILE_H
#ifndef XBOX_H
#define XBOX_H


//ROS header
#include <ros/ros.h>

//Namespace commonly matches ROS package name
namespace xbox_driver{

  //Class name can be unique but commonly matches filename
  class Xbox{
    public:
      Xbox(ros::NodeHandle& n, ros::NodeHandle& pn);

    private:
      //Node-specific stuff here.
  };

}

#endif //Must always be last line of file
