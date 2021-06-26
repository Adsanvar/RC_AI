#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "slros_time.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block RCAI_SimulinkModel/Subscribers/Subscribe
extern SimulinkSubscriber<geometry_msgs::TwistStamped, SL_Bus_RCAI_SimulinkModel_geometry_msgs_TwistStamped> Sub_RCAI_SimulinkModel_17;

// For Block RCAI_SimulinkModel/Publishers/Publish
extern SimulinkPublisher<geometry_msgs::Vector3Stamped, SL_Bus_RCAI_SimulinkModel_geometry_msgs_Vector3Stamped> Pub_RCAI_SimulinkModel_16;

void slros_node_init(int argc, char** argv);

#endif
