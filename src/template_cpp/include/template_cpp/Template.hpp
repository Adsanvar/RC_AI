//Prevent multiple declarations caused by including this header
//file from multiple locations. Naming convention is normally PACKAGE_PATH_FILE_H
#ifndef TEMPLATE_H
#define TEMPLATE_H


//ROS header
#include <ros/ros.h>

//Namespace commonly matches ROS package name
namespace template_cpp{

  //Class name can be unique but commonly matches filename
  class Template{
    public:
      Template(ros::NodeHandle& n, ros::NodeHandle& pn);

    private:
      //Node-specific stuff here.
  };

}

#endif //Must always be last line of file