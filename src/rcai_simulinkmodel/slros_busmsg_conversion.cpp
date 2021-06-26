#include "slros_busmsg_conversion.h"


// Conversions between SL_Bus_RCAI_SimulinkModel_geometry_msgs_Twist and geometry_msgs::Twist

void convertFromBus(geometry_msgs::Twist* msgPtr, SL_Bus_RCAI_SimulinkModel_geometry_msgs_Twist const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Twist");

  convertFromBus(&msgPtr->angular, &busPtr->Angular);
  convertFromBus(&msgPtr->linear, &busPtr->Linear);
}

void convertToBus(SL_Bus_RCAI_SimulinkModel_geometry_msgs_Twist* busPtr, geometry_msgs::Twist const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Twist");

  convertToBus(&busPtr->Angular, &msgPtr->angular);
  convertToBus(&busPtr->Linear, &msgPtr->linear);
}


// Conversions between SL_Bus_RCAI_SimulinkModel_geometry_msgs_TwistStamped and geometry_msgs::TwistStamped

void convertFromBus(geometry_msgs::TwistStamped* msgPtr, SL_Bus_RCAI_SimulinkModel_geometry_msgs_TwistStamped const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/TwistStamped");

  convertFromBus(&msgPtr->header, &busPtr->Header);
  convertFromBus(&msgPtr->twist, &busPtr->Twist);
}

void convertToBus(SL_Bus_RCAI_SimulinkModel_geometry_msgs_TwistStamped* busPtr, geometry_msgs::TwistStamped const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/TwistStamped");

  convertToBus(&busPtr->Header, &msgPtr->header);
  convertToBus(&busPtr->Twist, &msgPtr->twist);
}


// Conversions between SL_Bus_RCAI_SimulinkModel_geometry_msgs_Vector3 and geometry_msgs::Vector3

void convertFromBus(geometry_msgs::Vector3* msgPtr, SL_Bus_RCAI_SimulinkModel_geometry_msgs_Vector3 const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3");

  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
  msgPtr->z =  busPtr->Z;
}

void convertToBus(SL_Bus_RCAI_SimulinkModel_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3");

  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
  busPtr->Z =  msgPtr->z;
}


// Conversions between SL_Bus_RCAI_SimulinkModel_geometry_msgs_Vector3Stamped and geometry_msgs::Vector3Stamped

void convertFromBus(geometry_msgs::Vector3Stamped* msgPtr, SL_Bus_RCAI_SimulinkModel_geometry_msgs_Vector3Stamped const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3Stamped");

  convertFromBus(&msgPtr->header, &busPtr->Header);
  convertFromBus(&msgPtr->vector, &busPtr->Vector_);
}

void convertToBus(SL_Bus_RCAI_SimulinkModel_geometry_msgs_Vector3Stamped* busPtr, geometry_msgs::Vector3Stamped const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3Stamped");

  convertToBus(&busPtr->Header, &msgPtr->header);
  convertToBus(&busPtr->Vector_, &msgPtr->vector);
}


// Conversions between SL_Bus_RCAI_SimulinkModel_ros_time_Time and ros::Time

void convertFromBus(ros::Time* msgPtr, SL_Bus_RCAI_SimulinkModel_ros_time_Time const* busPtr)
{
  const std::string rosMessageType("ros_time/Time");

  msgPtr->sec =  busPtr->Sec;
  msgPtr->nsec =  busPtr->Nsec;
}

void convertToBus(SL_Bus_RCAI_SimulinkModel_ros_time_Time* busPtr, ros::Time const* msgPtr)
{
  const std::string rosMessageType("ros_time/Time");

  busPtr->Sec =  msgPtr->sec;
  busPtr->Nsec =  msgPtr->nsec;
}


// Conversions between SL_Bus_RCAI_SimulinkModel_std_msgs_Header and std_msgs::Header

void convertFromBus(std_msgs::Header* msgPtr, SL_Bus_RCAI_SimulinkModel_std_msgs_Header const* busPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertFromBusVariablePrimitiveArray(msgPtr->frame_id, busPtr->FrameId, busPtr->FrameId_SL_Info);
  msgPtr->seq =  busPtr->Seq;
  convertFromBus(&msgPtr->stamp, &busPtr->Stamp);
}

void convertToBus(SL_Bus_RCAI_SimulinkModel_std_msgs_Header* busPtr, std_msgs::Header const* msgPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertToBusVariablePrimitiveArray(busPtr->FrameId, busPtr->FrameId_SL_Info, msgPtr->frame_id, slros::EnabledWarning(rosMessageType, "frame_id"));
  busPtr->Seq =  msgPtr->seq;
  convertToBus(&busPtr->Stamp, &msgPtr->stamp);
}

