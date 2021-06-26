//
// File: RCAI_SimulinkModel_private.h
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
#ifndef RTW_HEADER_RCAI_SimulinkModel_private_h_
#define RTW_HEADER_RCAI_SimulinkModel_private_h_
#include "rtwtypes.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

// private model entry point functions
extern void RCAI_SimulinkModel_derivatives(void);

#endif                              // RTW_HEADER_RCAI_SimulinkModel_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
