//
// File: RCAI_SimulinkModel_types.h
//
// Code generated for Simulink model 'RCAI_SimulinkModel'.
//
// Model version                  : 1.11
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Sat Jun 26 19:37:50 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_RCAI_SimulinkModel_types_h_
#define RTW_HEADER_RCAI_SimulinkModel_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_RCAI_SimulinkModel_ros_time_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_RCAI_SimulinkModel_ros_time_Time_

// MsgType=ros_time/Time
typedef struct {
  real_T Sec;
  real_T Nsec;
} SL_Bus_RCAI_SimulinkModel_ros_time_Time;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_RCAI_SimulinkModel_std_msgs_Header_
#define DEFINED_TYPEDEF_FOR_SL_Bus_RCAI_SimulinkModel_std_msgs_Header_

// MsgType=std_msgs/Header
typedef struct {
  uint32_T Seq;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=FrameId_SL_Info:TruncateAction=warn 
  uint8_T FrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=FrameId
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;

  // MsgType=ros_time/Time
  SL_Bus_RCAI_SimulinkModel_ros_time_Time Stamp;
} SL_Bus_RCAI_SimulinkModel_std_msgs_Header;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_RCAI_SimulinkModel_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_RCAI_SimulinkModel_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_RCAI_SimulinkModel_geometry_msgs_Vector3;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_RCAI_SimulinkModel_geometry_msgs_Vector3Stamped_
#define DEFINED_TYPEDEF_FOR_SL_Bus_RCAI_SimulinkModel_geometry_msgs_Vector3Stamped_

// MsgType=geometry_msgs/Vector3Stamped
typedef struct {
  // MsgType=std_msgs/Header
  SL_Bus_RCAI_SimulinkModel_std_msgs_Header Header;

  // MsgType=geometry_msgs/Vector3:ROSPropName=Vector
  SL_Bus_RCAI_SimulinkModel_geometry_msgs_Vector3 Vector_;
} SL_Bus_RCAI_SimulinkModel_geometry_msgs_Vector3Stamped;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_RCAI_SimulinkModel_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_RCAI_SimulinkModel_geometry_msgs_Twist_

// MsgType=geometry_msgs/Twist
typedef struct {
  // MsgType=geometry_msgs/Vector3
  SL_Bus_RCAI_SimulinkModel_geometry_msgs_Vector3 Linear;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_RCAI_SimulinkModel_geometry_msgs_Vector3 Angular;
} SL_Bus_RCAI_SimulinkModel_geometry_msgs_Twist;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_RCAI_SimulinkModel_geometry_msgs_TwistStamped_
#define DEFINED_TYPEDEF_FOR_SL_Bus_RCAI_SimulinkModel_geometry_msgs_TwistStamped_

// MsgType=geometry_msgs/TwistStamped
typedef struct {
  // MsgType=std_msgs/Header
  SL_Bus_RCAI_SimulinkModel_std_msgs_Header Header;

  // MsgType=geometry_msgs/Twist
  SL_Bus_RCAI_SimulinkModel_geometry_msgs_Twist Twist;
} SL_Bus_RCAI_SimulinkModel_geometry_msgs_TwistStamped;

#endif

#ifndef typedef_ros_slros_internal_block_Publ_T
#define typedef_ros_slros_internal_block_Publ_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
} ros_slros_internal_block_Publ_T;

#endif                                 //typedef_ros_slros_internal_block_Publ_T

#ifndef typedef_d_robotics_slcore_internal_bl_T
#define typedef_d_robotics_slcore_internal_bl_T

typedef struct {
  int32_T __dummy;
} d_robotics_slcore_internal_bl_T;

#endif                                 //typedef_d_robotics_slcore_internal_bl_T

#ifndef typedef_ros_slros_internal_block_Curr_T
#define typedef_ros_slros_internal_block_Curr_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  d_robotics_slcore_internal_bl_T SampleTimeHandler;
} ros_slros_internal_block_Curr_T;

#endif                                 //typedef_ros_slros_internal_block_Curr_T

#ifndef typedef_ros_slros_internal_block_Subs_T
#define typedef_ros_slros_internal_block_Subs_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
} ros_slros_internal_block_Subs_T;

#endif                                 //typedef_ros_slros_internal_block_Subs_T

#ifndef struct_tag_sEvOy1kfGvlGN8v8hnfDJAF
#define struct_tag_sEvOy1kfGvlGN8v8hnfDJAF

struct tag_sEvOy1kfGvlGN8v8hnfDJAF
{
  uint32_T WheelBase;
  uint32_T VehicleSpeedRange;
};

#endif                                 //struct_tag_sEvOy1kfGvlGN8v8hnfDJAF

#ifndef typedef_sEvOy1kfGvlGN8v8hnfDJAF_RCAI__T
#define typedef_sEvOy1kfGvlGN8v8hnfDJAF_RCAI__T

typedef struct tag_sEvOy1kfGvlGN8v8hnfDJAF sEvOy1kfGvlGN8v8hnfDJAF_RCAI__T;

#endif                                 //typedef_sEvOy1kfGvlGN8v8hnfDJAF_RCAI__T

#ifndef struct_tag_seCA6rJGa7BDBlM4TA16ERD
#define struct_tag_seCA6rJGa7BDBlM4TA16ERD

struct tag_seCA6rJGa7BDBlM4TA16ERD
{
  real_T WheelBase;
  real_T VehicleSpeedRange;
};

#endif                                 //struct_tag_seCA6rJGa7BDBlM4TA16ERD

#ifndef typedef_seCA6rJGa7BDBlM4TA16ERD_RCAI__T
#define typedef_seCA6rJGa7BDBlM4TA16ERD_RCAI__T

typedef struct tag_seCA6rJGa7BDBlM4TA16ERD seCA6rJGa7BDBlM4TA16ERD_RCAI__T;

#endif                                 //typedef_seCA6rJGa7BDBlM4TA16ERD_RCAI__T

#ifndef typedef_c_cell_wrap_RCAI_SimulinkMode_T
#define typedef_c_cell_wrap_RCAI_SimulinkMode_T

typedef struct {
  uint32_T f1[8];
} c_cell_wrap_RCAI_SimulinkMode_T;

#endif                                 //typedef_c_cell_wrap_RCAI_SimulinkMode_T

#ifndef typedef_struct_T_RCAI_SimulinkModel_T
#define typedef_struct_T_RCAI_SimulinkModel_T

typedef struct {
  char_T Value[6];
} struct_T_RCAI_SimulinkModel_T;

#endif                                 //typedef_struct_T_RCAI_SimulinkModel_T

#ifndef typedef_b_struct_T_RCAI_SimulinkModel_T
#define typedef_b_struct_T_RCAI_SimulinkModel_T

typedef struct {
  char_T Value[3];
} b_struct_T_RCAI_SimulinkModel_T;

#endif                                 //typedef_b_struct_T_RCAI_SimulinkModel_T

#ifndef struct_tag_sI6PfD9gKI62KvmaMlArLgH
#define struct_tag_sI6PfD9gKI62KvmaMlArLgH

struct tag_sI6PfD9gKI62KvmaMlArLgH
{
  char_T HeaderFile[18];
  char_T SourceFile[20];
};

#endif                                 //struct_tag_sI6PfD9gKI62KvmaMlArLgH

#ifndef typedef_sI6PfD9gKI62KvmaMlArLgH_RCAI__T
#define typedef_sI6PfD9gKI62KvmaMlArLgH_RCAI__T

typedef struct tag_sI6PfD9gKI62KvmaMlArLgH sI6PfD9gKI62KvmaMlArLgH_RCAI__T;

#endif                                 //typedef_sI6PfD9gKI62KvmaMlArLgH_RCAI__T

#ifndef typedef_c_struct_T_RCAI_SimulinkModel_T
#define typedef_c_struct_T_RCAI_SimulinkModel_T

typedef struct {
  char_T Value[17];
} c_struct_T_RCAI_SimulinkModel_T;

#endif                                 //typedef_c_struct_T_RCAI_SimulinkModel_T

#ifndef struct_tag_so4pBuofLXIy3ixtLNBoZq
#define struct_tag_so4pBuofLXIy3ixtLNBoZq

struct tag_so4pBuofLXIy3ixtLNBoZq
{
  char_T PartialMatching[6];
};

#endif                                 //struct_tag_so4pBuofLXIy3ixtLNBoZq

#ifndef typedef_so4pBuofLXIy3ixtLNBoZq_RCAI_S_T
#define typedef_so4pBuofLXIy3ixtLNBoZq_RCAI_S_T

typedef struct tag_so4pBuofLXIy3ixtLNBoZq so4pBuofLXIy3ixtLNBoZq_RCAI_S_T;

#endif                                 //typedef_so4pBuofLXIy3ixtLNBoZq_RCAI_S_T

#ifndef typedef_ackermannKinematics_RCAI_Simu_T
#define typedef_ackermannKinematics_RCAI_Simu_T

typedef struct {
  real_T WheelBase;
  real_T VehicleSpeedRange[2];
} ackermannKinematics_RCAI_Simu_T;

#endif                                 //typedef_ackermannKinematics_RCAI_Simu_T

#ifndef typedef_robotics_slmobile_internal_bl_T
#define typedef_robotics_slmobile_internal_bl_T

typedef struct {
  boolean_T tunablePropertyChanged[2];
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  c_cell_wrap_RCAI_SimulinkMode_T inputVarSize[3];
  ackermannKinematics_RCAI_Simu_T KinModel;
  real_T WheelBase;
  real_T VehicleSpeedRange[2];
} robotics_slmobile_internal_bl_T;

#endif                                 //typedef_robotics_slmobile_internal_bl_T

// Parameters (default storage)
typedef struct P_RCAI_SimulinkModel_T_ P_RCAI_SimulinkModel_T;

// Forward declaration for rtModel
typedef struct tag_RTM_RCAI_SimulinkModel_T RT_MODEL_RCAI_SimulinkModel_T;

#endif                                // RTW_HEADER_RCAI_SimulinkModel_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
