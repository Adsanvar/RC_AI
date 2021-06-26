//
// File: RCAI_SimulinkModel.cpp
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
#include "RCAI_SimulinkModel.h"
#include "RCAI_SimulinkModel_private.h"

// Block signals (default storage)
B_RCAI_SimulinkModel_T RCAI_SimulinkModel_B;

// Continuous states
X_RCAI_SimulinkModel_T RCAI_SimulinkModel_X;

// Block states (default storage)
DW_RCAI_SimulinkModel_T RCAI_SimulinkModel_DW;

// Real-time model
RT_MODEL_RCAI_SimulinkModel_T RCAI_SimulinkModel_M_ =
  RT_MODEL_RCAI_SimulinkModel_T();
RT_MODEL_RCAI_SimulinkModel_T *const RCAI_SimulinkModel_M =
  &RCAI_SimulinkModel_M_;

// Forward declaration for local functions
static void matlabCodegenHandle_matlabCo_kq(ros_slros_internal_block_Subs_T *obj);
static void matlabCodegenHandle_matlabCod_k(ros_slros_internal_block_Curr_T *obj);
static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Publ_T *obj);
static void RCAI_SimulinkM_SystemCore_setup(robotics_slmobile_internal_bl_T *obj);

//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  // Solver Matrices
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  RCAI_SimulinkModel_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  RCAI_SimulinkModel_step();
  RCAI_SimulinkModel_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  RCAI_SimulinkModel_step();
  RCAI_SimulinkModel_derivatives();

  // tnew = t + hA(3);
  // ynew = y + f*hB(:,3);
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

static void matlabCodegenHandle_matlabCo_kq(ros_slros_internal_block_Subs_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void matlabCodegenHandle_matlabCod_k(ros_slros_internal_block_Curr_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Publ_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void RCAI_SimulinkM_SystemCore_setup(robotics_slmobile_internal_bl_T *obj)
{
  obj->isInitialized = 1;
  obj->KinModel.WheelBase = 1.0;
  obj->KinModel.VehicleSpeedRange[0] = (rtMinusInf);
  obj->KinModel.VehicleSpeedRange[0] = obj->VehicleSpeedRange[0];
  obj->KinModel.VehicleSpeedRange[1] = (rtInf);
  obj->KinModel.VehicleSpeedRange[1] = obj->VehicleSpeedRange[1];
  obj->KinModel.WheelBase = obj->WheelBase;
  obj->TunablePropsChanged = false;
}

// Model step function
void RCAI_SimulinkModel_step(void)
{
  SL_Bus_RCAI_SimulinkModel_ros_time_Time rtb_CurrentTime_0;
  real_T varargin_1[2];
  robotics_slmobile_internal_bl_T *obj;
  boolean_T p;
  int32_T b_k;
  real_T c;
  real_T varargin_2;
  boolean_T b_varargout_1;
  boolean_T exitg1;
  if (rtmIsMajorTimeStep(RCAI_SimulinkModel_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&RCAI_SimulinkModel_M->solverInfo,
                          ((RCAI_SimulinkModel_M->Timing.clockTick0+1)*
      RCAI_SimulinkModel_M->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(RCAI_SimulinkModel_M)) {
    RCAI_SimulinkModel_M->Timing.t[0] = rtsiGetT
      (&RCAI_SimulinkModel_M->solverInfo);
  }

  // Integrator: '<S12>/Integrator'
  // Limited  Integrator
  if (RCAI_SimulinkModel_X.Integrator_CSTATE[0] >=
      RCAI_SimulinkModel_P.Integrator_UpperSat[0]) {
    RCAI_SimulinkModel_X.Integrator_CSTATE[0] =
      RCAI_SimulinkModel_P.Integrator_UpperSat[0];
  } else {
    if (RCAI_SimulinkModel_X.Integrator_CSTATE[0] <=
        RCAI_SimulinkModel_P.Integrator_LowerSat[0]) {
      RCAI_SimulinkModel_X.Integrator_CSTATE[0] =
        RCAI_SimulinkModel_P.Integrator_LowerSat[0];
    }
  }

  if (RCAI_SimulinkModel_X.Integrator_CSTATE[1] >=
      RCAI_SimulinkModel_P.Integrator_UpperSat[1]) {
    RCAI_SimulinkModel_X.Integrator_CSTATE[1] =
      RCAI_SimulinkModel_P.Integrator_UpperSat[1];
  } else {
    if (RCAI_SimulinkModel_X.Integrator_CSTATE[1] <=
        RCAI_SimulinkModel_P.Integrator_LowerSat[1]) {
      RCAI_SimulinkModel_X.Integrator_CSTATE[1] =
        RCAI_SimulinkModel_P.Integrator_LowerSat[1];
    }
  }

  if (RCAI_SimulinkModel_X.Integrator_CSTATE[2] >=
      RCAI_SimulinkModel_P.Integrator_UpperSat[2]) {
    RCAI_SimulinkModel_X.Integrator_CSTATE[2] =
      RCAI_SimulinkModel_P.Integrator_UpperSat[2];
  } else {
    if (RCAI_SimulinkModel_X.Integrator_CSTATE[2] <=
        RCAI_SimulinkModel_P.Integrator_LowerSat[2]) {
      RCAI_SimulinkModel_X.Integrator_CSTATE[2] =
        RCAI_SimulinkModel_P.Integrator_LowerSat[2];
    }
  }

  if (RCAI_SimulinkModel_X.Integrator_CSTATE[3] >=
      RCAI_SimulinkModel_P.Integrator_UpperSat[3]) {
    RCAI_SimulinkModel_X.Integrator_CSTATE[3] =
      RCAI_SimulinkModel_P.Integrator_UpperSat[3];
  } else {
    if (RCAI_SimulinkModel_X.Integrator_CSTATE[3] <=
        RCAI_SimulinkModel_P.Integrator_LowerSat[3]) {
      RCAI_SimulinkModel_X.Integrator_CSTATE[3] =
        RCAI_SimulinkModel_P.Integrator_LowerSat[3];
    }
  }

  if (rtmIsMajorTimeStep(RCAI_SimulinkModel_M)) {
    // Outputs for Atomic SubSystem: '<S3>/Subscribe'
    // MATLABSystem: '<S10>/SourceBlock' incorporates:
    //   Inport: '<S11>/In1'

    b_varargout_1 = Sub_RCAI_SimulinkModel_17.getLatestMessage
      (&RCAI_SimulinkModel_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S10>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S11>/Enable'

    if (b_varargout_1) {
      RCAI_SimulinkModel_B.In1 = RCAI_SimulinkModel_B.b_varargout_2;
    }

    // End of MATLABSystem: '<S10>/SourceBlock'
    // End of Outputs for SubSystem: '<S10>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<S3>/Subscribe'
  }

  // MATLABSystem: '<S12>/MATLAB System' incorporates:
  //   Integrator: '<S12>/Integrator'

  if (RCAI_SimulinkModel_DW.obj.WheelBase !=
      RCAI_SimulinkModel_P.AckermannKinematicModel_WheelBa) {
    b_varargout_1 = (RCAI_SimulinkModel_DW.obj.isInitialized == 1);
    if (b_varargout_1) {
      RCAI_SimulinkModel_DW.obj.TunablePropsChanged = true;
      RCAI_SimulinkModel_DW.obj.tunablePropertyChanged[0] = true;
    }

    RCAI_SimulinkModel_DW.obj.WheelBase =
      RCAI_SimulinkModel_P.AckermannKinematicModel_WheelBa;
  }

  varargin_1[0] = RCAI_SimulinkModel_DW.obj.VehicleSpeedRange[0];
  varargin_1[1] = RCAI_SimulinkModel_DW.obj.VehicleSpeedRange[1];
  b_varargout_1 = false;
  p = true;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 2)) {
    if (!(varargin_1[b_k] ==
          RCAI_SimulinkModel_P.AckermannKinematicModel_Vehicle[b_k])) {
      p = false;
      exitg1 = true;
    } else {
      b_k++;
    }
  }

  if (p) {
    b_varargout_1 = true;
  }

  if (!b_varargout_1) {
    b_varargout_1 = (RCAI_SimulinkModel_DW.obj.isInitialized == 1);
    if (b_varargout_1) {
      RCAI_SimulinkModel_DW.obj.TunablePropsChanged = true;
      RCAI_SimulinkModel_DW.obj.tunablePropertyChanged[1] = true;
    }

    RCAI_SimulinkModel_DW.obj.VehicleSpeedRange[0] =
      RCAI_SimulinkModel_P.AckermannKinematicModel_Vehicle[0];
    RCAI_SimulinkModel_DW.obj.VehicleSpeedRange[1] =
      RCAI_SimulinkModel_P.AckermannKinematicModel_Vehicle[1];
  }

  obj = &RCAI_SimulinkModel_DW.obj;
  if (RCAI_SimulinkModel_DW.obj.TunablePropsChanged) {
    RCAI_SimulinkModel_DW.obj.TunablePropsChanged = false;
    b_varargout_1 = RCAI_SimulinkModel_DW.obj.tunablePropertyChanged[1];
    if (b_varargout_1) {
      varargin_1[0] = RCAI_SimulinkModel_DW.obj.VehicleSpeedRange[0];
      varargin_1[1] = RCAI_SimulinkModel_DW.obj.VehicleSpeedRange[1];
      obj->KinModel.VehicleSpeedRange[0] = varargin_1[0];
      obj->KinModel.VehicleSpeedRange[1] = varargin_1[1];
    }

    b_varargout_1 = RCAI_SimulinkModel_DW.obj.tunablePropertyChanged[0];
    if (b_varargout_1) {
      c = RCAI_SimulinkModel_DW.obj.WheelBase;
      obj->KinModel.WheelBase = c;
    }

    RCAI_SimulinkModel_DW.obj.tunablePropertyChanged[0] = false;
    RCAI_SimulinkModel_DW.obj.tunablePropertyChanged[1] = false;
  }

  c = obj->KinModel.VehicleSpeedRange[0];
  varargin_2 = obj->KinModel.VehicleSpeedRange[1];
  RCAI_SimulinkModel_B.J[0] = cos(RCAI_SimulinkModel_X.Integrator_CSTATE[2]);
  RCAI_SimulinkModel_B.J[4] = 0.0;
  RCAI_SimulinkModel_B.J[1] = sin(RCAI_SimulinkModel_X.Integrator_CSTATE[2]);
  RCAI_SimulinkModel_B.J[5] = 0.0;
  RCAI_SimulinkModel_B.J[2] = tan(RCAI_SimulinkModel_X.Integrator_CSTATE[3]) /
    obj->KinModel.WheelBase;
  RCAI_SimulinkModel_B.J[6] = 0.0;
  RCAI_SimulinkModel_B.J[3] = 0.0;
  RCAI_SimulinkModel_B.J[7] = 1.0;
  if ((RCAI_SimulinkModel_B.In1.Twist.Linear.X > c) || rtIsNaN(c)) {
    c = RCAI_SimulinkModel_B.In1.Twist.Linear.X;
  }

  if ((c < varargin_2) || rtIsNaN(varargin_2)) {
    varargin_2 = c;
  }

  for (b_k = 0; b_k < 4; b_k++) {
    RCAI_SimulinkModel_B.MATLABSystem[b_k] = 0.0;
    RCAI_SimulinkModel_B.MATLABSystem[b_k] += RCAI_SimulinkModel_B.J[b_k] *
      varargin_2;
    RCAI_SimulinkModel_B.MATLABSystem[b_k] += RCAI_SimulinkModel_B.J[b_k + 4] *
      RCAI_SimulinkModel_B.In1.Twist.Angular.Z;
  }

  // End of MATLABSystem: '<S12>/MATLAB System'
  if (rtmIsMajorTimeStep(RCAI_SimulinkModel_M)) {
    // UnitDelay: '<S7>/Output'
    RCAI_SimulinkModel_B.Output = RCAI_SimulinkModel_DW.Output_DSTATE;
  }

  // MATLABSystem: '<S2>/Current Time'
  currentROSTimeBus(&rtb_CurrentTime_0);

  // BusAssignment: '<S4>/Bus Assignment' incorporates:
  //   BusAssignment: '<S2>/Bus Assignment8'
  //   Constant: '<S6>/Constant'

  RCAI_SimulinkModel_B.BusAssignment.Header =
    RCAI_SimulinkModel_P.Constant_Value_g;

  // BusAssignment: '<S2>/Bus Assignment8' incorporates:
  //   BusAssignment: '<S4>/Bus Assignment'
  //   MATLABSystem: '<S2>/Current Time'

  RCAI_SimulinkModel_B.BusAssignment.Header.Seq = RCAI_SimulinkModel_B.Output;
  RCAI_SimulinkModel_B.BusAssignment.Header.Stamp = rtb_CurrentTime_0;

  // BusAssignment: '<S4>/Bus Assignment' incorporates:
  //   Integrator: '<S12>/Integrator'

  RCAI_SimulinkModel_B.BusAssignment.Vector_.X =
    RCAI_SimulinkModel_X.Integrator_CSTATE[0];
  RCAI_SimulinkModel_B.BusAssignment.Vector_.Y =
    RCAI_SimulinkModel_X.Integrator_CSTATE[1];
  RCAI_SimulinkModel_B.BusAssignment.Vector_.Z =
    RCAI_SimulinkModel_X.Integrator_CSTATE[2];

  // Outputs for Atomic SubSystem: '<S1>/Publish'
  // MATLABSystem: '<S5>/SinkBlock'
  Pub_RCAI_SimulinkModel_16.publish(&RCAI_SimulinkModel_B.BusAssignment);

  // End of Outputs for SubSystem: '<S1>/Publish'
  if (rtmIsMajorTimeStep(RCAI_SimulinkModel_M)) {
    // Sum: '<S8>/FixPt Sum1' incorporates:
    //   Constant: '<S8>/FixPt Constant'

    RCAI_SimulinkModel_DW.Output_DSTATE = RCAI_SimulinkModel_B.Output +
      RCAI_SimulinkModel_P.FixPtConstant_Value;

    // Switch: '<S9>/FixPt Switch' incorporates:
    //   Constant: '<S9>/Constant'
    //   UnitDelay: '<S7>/Output'

    if (RCAI_SimulinkModel_DW.Output_DSTATE >
        RCAI_SimulinkModel_P.WrapToZero_Threshold) {
      RCAI_SimulinkModel_DW.Output_DSTATE =
        RCAI_SimulinkModel_P.Constant_Value_f;
    }

    // End of Switch: '<S9>/FixPt Switch'
  }

  if (rtmIsMajorTimeStep(RCAI_SimulinkModel_M)) {
    rt_ertODEUpdateContinuousStates(&RCAI_SimulinkModel_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++RCAI_SimulinkModel_M->Timing.clockTick0;
    RCAI_SimulinkModel_M->Timing.t[0] = rtsiGetSolverStopTime
      (&RCAI_SimulinkModel_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.05s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.05, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      RCAI_SimulinkModel_M->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void RCAI_SimulinkModel_derivatives(void)
{
  boolean_T lsat;
  boolean_T usat;
  XDot_RCAI_SimulinkModel_T *_rtXdot;
  _rtXdot = ((XDot_RCAI_SimulinkModel_T *) RCAI_SimulinkModel_M->derivs);

  // Derivatives for Integrator: '<S12>/Integrator'
  lsat = (RCAI_SimulinkModel_X.Integrator_CSTATE[0] <=
          RCAI_SimulinkModel_P.Integrator_LowerSat[0]);
  usat = (RCAI_SimulinkModel_X.Integrator_CSTATE[0] >=
          RCAI_SimulinkModel_P.Integrator_UpperSat[0]);
  if (((!lsat) && (!usat)) || (lsat && (RCAI_SimulinkModel_B.MATLABSystem[0] >
        0.0)) || (usat && (RCAI_SimulinkModel_B.MATLABSystem[0] < 0.0))) {
    _rtXdot->Integrator_CSTATE[0] = RCAI_SimulinkModel_B.MATLABSystem[0];
  } else {
    // in saturation
    _rtXdot->Integrator_CSTATE[0] = 0.0;
  }

  lsat = (RCAI_SimulinkModel_X.Integrator_CSTATE[1] <=
          RCAI_SimulinkModel_P.Integrator_LowerSat[1]);
  usat = (RCAI_SimulinkModel_X.Integrator_CSTATE[1] >=
          RCAI_SimulinkModel_P.Integrator_UpperSat[1]);
  if (((!lsat) && (!usat)) || (lsat && (RCAI_SimulinkModel_B.MATLABSystem[1] >
        0.0)) || (usat && (RCAI_SimulinkModel_B.MATLABSystem[1] < 0.0))) {
    _rtXdot->Integrator_CSTATE[1] = RCAI_SimulinkModel_B.MATLABSystem[1];
  } else {
    // in saturation
    _rtXdot->Integrator_CSTATE[1] = 0.0;
  }

  lsat = (RCAI_SimulinkModel_X.Integrator_CSTATE[2] <=
          RCAI_SimulinkModel_P.Integrator_LowerSat[2]);
  usat = (RCAI_SimulinkModel_X.Integrator_CSTATE[2] >=
          RCAI_SimulinkModel_P.Integrator_UpperSat[2]);
  if (((!lsat) && (!usat)) || (lsat && (RCAI_SimulinkModel_B.MATLABSystem[2] >
        0.0)) || (usat && (RCAI_SimulinkModel_B.MATLABSystem[2] < 0.0))) {
    _rtXdot->Integrator_CSTATE[2] = RCAI_SimulinkModel_B.MATLABSystem[2];
  } else {
    // in saturation
    _rtXdot->Integrator_CSTATE[2] = 0.0;
  }

  lsat = (RCAI_SimulinkModel_X.Integrator_CSTATE[3] <=
          RCAI_SimulinkModel_P.Integrator_LowerSat[3]);
  usat = (RCAI_SimulinkModel_X.Integrator_CSTATE[3] >=
          RCAI_SimulinkModel_P.Integrator_UpperSat[3]);
  if (((!lsat) && (!usat)) || (lsat && (RCAI_SimulinkModel_B.MATLABSystem[3] >
        0.0)) || (usat && (RCAI_SimulinkModel_B.MATLABSystem[3] < 0.0))) {
    _rtXdot->Integrator_CSTATE[3] = RCAI_SimulinkModel_B.MATLABSystem[3];
  } else {
    // in saturation
    _rtXdot->Integrator_CSTATE[3] = 0.0;
  }

  // End of Derivatives for Integrator: '<S12>/Integrator'
}

// Model initialize function
void RCAI_SimulinkModel_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // non-finite (run-time) assignments
  RCAI_SimulinkModel_P.Integrator_UpperSat[0] = rtInf;
  RCAI_SimulinkModel_P.Integrator_UpperSat[1] = rtInf;
  RCAI_SimulinkModel_P.Integrator_UpperSat[2] = rtInf;
  RCAI_SimulinkModel_P.Integrator_LowerSat[0] = rtMinusInf;
  RCAI_SimulinkModel_P.Integrator_LowerSat[1] = rtMinusInf;
  RCAI_SimulinkModel_P.Integrator_LowerSat[2] = rtMinusInf;

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&RCAI_SimulinkModel_M->solverInfo,
                          &RCAI_SimulinkModel_M->Timing.simTimeStep);
    rtsiSetTPtr(&RCAI_SimulinkModel_M->solverInfo, &rtmGetTPtr
                (RCAI_SimulinkModel_M));
    rtsiSetStepSizePtr(&RCAI_SimulinkModel_M->solverInfo,
                       &RCAI_SimulinkModel_M->Timing.stepSize0);
    rtsiSetdXPtr(&RCAI_SimulinkModel_M->solverInfo,
                 &RCAI_SimulinkModel_M->derivs);
    rtsiSetContStatesPtr(&RCAI_SimulinkModel_M->solverInfo, (real_T **)
                         &RCAI_SimulinkModel_M->contStates);
    rtsiSetNumContStatesPtr(&RCAI_SimulinkModel_M->solverInfo,
      &RCAI_SimulinkModel_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&RCAI_SimulinkModel_M->solverInfo,
      &RCAI_SimulinkModel_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&RCAI_SimulinkModel_M->solverInfo,
      &RCAI_SimulinkModel_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&RCAI_SimulinkModel_M->solverInfo,
      &RCAI_SimulinkModel_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&RCAI_SimulinkModel_M->solverInfo, (&rtmGetErrorStatus
      (RCAI_SimulinkModel_M)));
    rtsiSetRTModelPtr(&RCAI_SimulinkModel_M->solverInfo, RCAI_SimulinkModel_M);
  }

  rtsiSetSimTimeStep(&RCAI_SimulinkModel_M->solverInfo, MAJOR_TIME_STEP);
  RCAI_SimulinkModel_M->intgData.y = RCAI_SimulinkModel_M->odeY;
  RCAI_SimulinkModel_M->intgData.f[0] = RCAI_SimulinkModel_M->odeF[0];
  RCAI_SimulinkModel_M->intgData.f[1] = RCAI_SimulinkModel_M->odeF[1];
  RCAI_SimulinkModel_M->intgData.f[2] = RCAI_SimulinkModel_M->odeF[2];
  RCAI_SimulinkModel_M->contStates = ((X_RCAI_SimulinkModel_T *)
    &RCAI_SimulinkModel_X);
  rtsiSetSolverData(&RCAI_SimulinkModel_M->solverInfo, static_cast<void *>
                    (&RCAI_SimulinkModel_M->intgData));
  rtsiSetSolverName(&RCAI_SimulinkModel_M->solverInfo,"ode3");
  rtmSetTPtr(RCAI_SimulinkModel_M, &RCAI_SimulinkModel_M->Timing.tArray[0]);
  RCAI_SimulinkModel_M->Timing.stepSize0 = 0.05;

  {
    boolean_T flag;
    char_T tmp[18];
    char_T tmp_0[13];
    int32_T i;
    real_T b;
    static const char_T tmp_1[12] = { '/', 'M', 'o', 'b', 'i', 'l', 'i', 't',
      'y', 'C', 'm', 'd' };

    static const char_T tmp_2[17] = { '/', 'v', 'e', 'h', 'i', 'c', 'l', 'e',
      '_', 'd', 'y', 'n', 'a', 'm', 'i', 'c', 's' };

    // Start for Atomic SubSystem: '<S3>/Subscribe'
    // Start for MATLABSystem: '<S10>/SourceBlock'
    RCAI_SimulinkModel_DW.obj_j.matlabCodegenIsDeleted = false;
    RCAI_SimulinkModel_DW.obj_j.isInitialized = 1;
    for (i = 0; i < 12; i++) {
      tmp_0[i] = tmp_1[i];
    }

    tmp_0[12] = '\x00';
    Sub_RCAI_SimulinkModel_17.createSubscriber(tmp_0, 1);
    RCAI_SimulinkModel_DW.obj_j.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S10>/SourceBlock'
    // End of Start for SubSystem: '<S3>/Subscribe'

    // Start for MATLABSystem: '<S12>/MATLAB System'
    RCAI_SimulinkModel_DW.obj.isInitialized = 0;
    RCAI_SimulinkModel_DW.obj.tunablePropertyChanged[0] = false;
    RCAI_SimulinkModel_DW.obj.tunablePropertyChanged[1] = false;
    flag = (RCAI_SimulinkModel_DW.obj.isInitialized == 1);
    if (flag) {
      RCAI_SimulinkModel_DW.obj.TunablePropsChanged = true;
      RCAI_SimulinkModel_DW.obj.tunablePropertyChanged[0] = true;
    }

    RCAI_SimulinkModel_DW.obj.WheelBase =
      RCAI_SimulinkModel_P.AckermannKinematicModel_WheelBa;
    flag = (RCAI_SimulinkModel_DW.obj.isInitialized == 1);
    if (flag) {
      RCAI_SimulinkModel_DW.obj.TunablePropsChanged = true;
      RCAI_SimulinkModel_DW.obj.tunablePropertyChanged[1] = true;
    }

    RCAI_SimulinkModel_DW.obj.VehicleSpeedRange[0] =
      RCAI_SimulinkModel_P.AckermannKinematicModel_Vehicle[0];
    RCAI_SimulinkModel_DW.obj.VehicleSpeedRange[1] =
      RCAI_SimulinkModel_P.AckermannKinematicModel_Vehicle[1];
    RCAI_SimulinkM_SystemCore_setup(&RCAI_SimulinkModel_DW.obj);

    // End of Start for MATLABSystem: '<S12>/MATLAB System'

    // Start for MATLABSystem: '<S2>/Current Time'
    RCAI_SimulinkModel_DW.obj_b.matlabCodegenIsDeleted = false;
    RCAI_SimulinkModel_DW.obj_b.isInitialized = 1;
    RCAI_SimulinkModel_DW.obj_b.isSetupComplete = true;

    // Start for Atomic SubSystem: '<S1>/Publish'
    // Start for MATLABSystem: '<S5>/SinkBlock'
    RCAI_SimulinkModel_DW.obj_l.matlabCodegenIsDeleted = false;
    RCAI_SimulinkModel_DW.obj_l.isInitialized = 1;
    for (i = 0; i < 17; i++) {
      tmp[i] = tmp_2[i];
    }

    tmp[17] = '\x00';
    Pub_RCAI_SimulinkModel_16.createPublisher(tmp, 1);
    RCAI_SimulinkModel_DW.obj_l.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SinkBlock'
    // End of Start for SubSystem: '<S1>/Publish'

    // InitializeConditions for Integrator: '<S12>/Integrator'
    RCAI_SimulinkModel_X.Integrator_CSTATE[0] =
      RCAI_SimulinkModel_P.Integrator_IC[0];
    RCAI_SimulinkModel_X.Integrator_CSTATE[1] =
      RCAI_SimulinkModel_P.Integrator_IC[1];
    RCAI_SimulinkModel_X.Integrator_CSTATE[2] =
      RCAI_SimulinkModel_P.Integrator_IC[2];
    RCAI_SimulinkModel_X.Integrator_CSTATE[3] =
      RCAI_SimulinkModel_P.Integrator_IC[3];

    // InitializeConditions for UnitDelay: '<S7>/Output'
    RCAI_SimulinkModel_DW.Output_DSTATE =
      RCAI_SimulinkModel_P.Output_InitialCondition;

    // SystemInitialize for Atomic SubSystem: '<S3>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S10>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S11>/Out1'
    RCAI_SimulinkModel_B.In1 = RCAI_SimulinkModel_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S10>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<S3>/Subscribe'

    // InitializeConditions for MATLABSystem: '<S12>/MATLAB System'
    b = RCAI_SimulinkModel_DW.obj.VehicleSpeedRange[0];
    RCAI_SimulinkModel_DW.obj.KinModel.VehicleSpeedRange[0] = b;
    b = RCAI_SimulinkModel_DW.obj.VehicleSpeedRange[1];
    RCAI_SimulinkModel_DW.obj.KinModel.VehicleSpeedRange[1] = b;
    b = RCAI_SimulinkModel_DW.obj.WheelBase;
    RCAI_SimulinkModel_DW.obj.KinModel.WheelBase = b;
  }
}

// Model terminate function
void RCAI_SimulinkModel_terminate(void)
{
  // Terminate for Atomic SubSystem: '<S3>/Subscribe'
  // Terminate for MATLABSystem: '<S10>/SourceBlock'
  matlabCodegenHandle_matlabCo_kq(&RCAI_SimulinkModel_DW.obj_j);

  // End of Terminate for SubSystem: '<S3>/Subscribe'

  // Terminate for MATLABSystem: '<S2>/Current Time'
  matlabCodegenHandle_matlabCod_k(&RCAI_SimulinkModel_DW.obj_b);

  // Terminate for Atomic SubSystem: '<S1>/Publish'
  // Terminate for MATLABSystem: '<S5>/SinkBlock'
  matlabCodegenHandle_matlabCodeg(&RCAI_SimulinkModel_DW.obj_l);

  // End of Terminate for SubSystem: '<S1>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
