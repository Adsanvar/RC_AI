//
// File: RCAI_SimulinkModel.h
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
#ifndef RTW_HEADER_RCAI_SimulinkModel_h_
#define RTW_HEADER_RCAI_SimulinkModel_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef RCAI_SimulinkModel_COMMON_INCLUDES_
# define RCAI_SimulinkModel_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#endif                                 // RCAI_SimulinkModel_COMMON_INCLUDES_

#include "RCAI_SimulinkModel_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

// Block signals (default storage)
typedef struct {
  SL_Bus_RCAI_SimulinkModel_geometry_msgs_TwistStamped In1;// '<S11>/In1'
  SL_Bus_RCAI_SimulinkModel_geometry_msgs_TwistStamped b_varargout_2;
  SL_Bus_RCAI_SimulinkModel_geometry_msgs_Vector3Stamped BusAssignment;// '<S4>/Bus Assignment' 
  real_T J[8];
  real_T MATLABSystem[4];              // '<S12>/MATLAB System'
  uint32_T Output;                     // '<S7>/Output'
} B_RCAI_SimulinkModel_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  robotics_slmobile_internal_bl_T obj; // '<S12>/MATLAB System'
  ros_slros_internal_block_Curr_T obj_b;// '<S2>/Current Time'
  ros_slros_internal_block_Publ_T obj_l;// '<S5>/SinkBlock'
  ros_slros_internal_block_Subs_T obj_j;// '<S10>/SourceBlock'
  uint32_T Output_DSTATE;              // '<S7>/Output'
} DW_RCAI_SimulinkModel_T;

// Continuous states (default storage)
typedef struct {
  real_T Integrator_CSTATE[4];         // '<S12>/Integrator'
} X_RCAI_SimulinkModel_T;

// State derivatives (default storage)
typedef struct {
  real_T Integrator_CSTATE[4];         // '<S12>/Integrator'
} XDot_RCAI_SimulinkModel_T;

// State disabled
typedef struct {
  boolean_T Integrator_CSTATE[4];      // '<S12>/Integrator'
} XDis_RCAI_SimulinkModel_T;

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
typedef struct {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
} ODE3_IntgData;

#endif

// Parameters (default storage)
struct P_RCAI_SimulinkModel_T_ {
  real_T AckermannKinematicModel_Vehicle[2];
                              // Mask Parameter: AckermannKinematicModel_Vehicle
                                 //  Referenced by: '<S12>/MATLAB System'

  real_T AckermannKinematicModel_WheelBa;
                              // Mask Parameter: AckermannKinematicModel_WheelBa
                                 //  Referenced by: '<S12>/MATLAB System'

  uint32_T WrapToZero_Threshold;       // Mask Parameter: WrapToZero_Threshold
                                          //  Referenced by: '<S9>/FixPt Switch'

  SL_Bus_RCAI_SimulinkModel_geometry_msgs_TwistStamped Out1_Y0;// Computed Parameter: Out1_Y0
                                                                  //  Referenced by: '<S11>/Out1'

  SL_Bus_RCAI_SimulinkModel_geometry_msgs_TwistStamped Constant_Value;// Computed Parameter: Constant_Value
                                                                      //  Referenced by: '<S10>/Constant'

  SL_Bus_RCAI_SimulinkModel_geometry_msgs_Vector3Stamped Constant_Value_l;// Computed Parameter: Constant_Value_l
                                                                      //  Referenced by: '<S13>/Constant'

  SL_Bus_RCAI_SimulinkModel_std_msgs_Header Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                                //  Referenced by: '<S6>/Constant'

  real_T Integrator_IC[4];    // Expression: double(InitialState(:)).*[1 1 1 1]'
                                 //  Referenced by: '<S12>/Integrator'

  real_T Integrator_UpperSat[4];
                          // Expression: [inf inf inf double(MaxSteeringAngle)]'
                             //  Referenced by: '<S12>/Integrator'

  real_T Integrator_LowerSat[4];
                         // Expression: -[inf inf inf double(MaxSteeringAngle)]'
                            //  Referenced by: '<S12>/Integrator'

  uint32_T Constant_Value_f;           // Computed Parameter: Constant_Value_f
                                          //  Referenced by: '<S9>/Constant'

  uint32_T Output_InitialCondition;
                                  // Computed Parameter: Output_InitialCondition
                                     //  Referenced by: '<S7>/Output'

  uint32_T FixPtConstant_Value;       // Computed Parameter: FixPtConstant_Value
                                         //  Referenced by: '<S8>/FixPt Constant'

};

// Real-time Model Data Structure
struct tag_RTM_RCAI_SimulinkModel_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_RCAI_SimulinkModel_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[4];
  real_T odeF[3][4];
  ODE3_IntgData intgData;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_RCAI_SimulinkModel_T RCAI_SimulinkModel_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_RCAI_SimulinkModel_T RCAI_SimulinkModel_B;

#ifdef __cplusplus

}
#endif

// Continuous states (default storage)
extern X_RCAI_SimulinkModel_T RCAI_SimulinkModel_X;

// Block states (default storage)
extern DW_RCAI_SimulinkModel_T RCAI_SimulinkModel_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void RCAI_SimulinkModel_initialize(void);
  extern void RCAI_SimulinkModel_step(void);
  extern void RCAI_SimulinkModel_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_RCAI_SimulinkModel_T *const RCAI_SimulinkModel_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S7>/FixPt Data Type Propagation' : Unused code path elimination
//  Block '<S8>/FixPt Data Type Duplicate' : Unused code path elimination
//  Block '<S9>/FixPt Data Type Duplicate1' : Unused code path elimination
//  Block '<S12>/Data Type Duplicate' : Unused code path elimination
//  Block '<S12>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S12>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S12>/Reshape' : Reshape block reduction


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'RCAI_SimulinkModel'
//  '<S1>'   : 'RCAI_SimulinkModel/Publishers'
//  '<S2>'   : 'RCAI_SimulinkModel/ROS Time'
//  '<S3>'   : 'RCAI_SimulinkModel/Subscribers'
//  '<S4>'   : 'RCAI_SimulinkModel/Vehicle Kinematics Model'
//  '<S5>'   : 'RCAI_SimulinkModel/Publishers/Publish'
//  '<S6>'   : 'RCAI_SimulinkModel/ROS Time/Blank Message8'
//  '<S7>'   : 'RCAI_SimulinkModel/ROS Time/Counter Free-Running1'
//  '<S8>'   : 'RCAI_SimulinkModel/ROS Time/Counter Free-Running1/Increment Real World'
//  '<S9>'   : 'RCAI_SimulinkModel/ROS Time/Counter Free-Running1/Wrap To Zero'
//  '<S10>'  : 'RCAI_SimulinkModel/Subscribers/Subscribe'
//  '<S11>'  : 'RCAI_SimulinkModel/Subscribers/Subscribe/Enabled Subsystem'
//  '<S12>'  : 'RCAI_SimulinkModel/Vehicle Kinematics Model/Ackermann Kinematic Model'
//  '<S13>'  : 'RCAI_SimulinkModel/Vehicle Kinematics Model/Blank Message'

#endif                                 // RTW_HEADER_RCAI_SimulinkModel_h_

//
// File trailer for generated code.
//
// [EOF]
//
