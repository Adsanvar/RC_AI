#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "RCAI_SimulinkModel";

// For Block RCAI_SimulinkModel/Subscribers/Subscribe
SimulinkSubscriber<geometry_msgs::TwistStamped, SL_Bus_RCAI_SimulinkModel_geometry_msgs_TwistStamped> Sub_RCAI_SimulinkModel_17;

// For Block RCAI_SimulinkModel/Publishers/Publish
SimulinkPublisher<geometry_msgs::Vector3Stamped, SL_Bus_RCAI_SimulinkModel_geometry_msgs_Vector3Stamped> Pub_RCAI_SimulinkModel_16;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

