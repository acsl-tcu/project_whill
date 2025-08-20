/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * initializeEKF.c
 *
 * Code generation for function 'initializeEKF'
 *
 */

/* Include files */
#include "initializeEKF.h"
#include "ExtendedKalmanFilter.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo nq_emlrtRSI = {
    84,              /* lineNo */
    "initializeEKF", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/initializeEKF.m" /* pathName */
};

static emlrtRSInfo oq_emlrtRSI = {
    149,             /* lineNo */
    "initializeEKF", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/initializeEKF.m" /* pathName */
};

static emlrtRSInfo pq_emlrtRSI = {
    46,                         /* lineNo */
    "parseDetectionForInitFcn", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/parseDetectionForInitFcn.m" /* pathName */
};

static emlrtRSInfo qq_emlrtRSI =
    {
        141,                       /* lineNo */
        "trackingEKF/trackingEKF", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m" /* pathName */
};

static emlrtRSInfo rq_emlrtRSI =
    {
        142,                       /* lineNo */
        "trackingEKF/trackingEKF", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m" /* pathName */
};

static emlrtRSInfo sq_emlrtRSI =
    {
        134,                       /* lineNo */
        "trackingEKF/trackingEKF", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m" /* pathName */
};

static emlrtRSInfo tq_emlrtRSI =
    {
        143,                       /* lineNo */
        "trackingEKF/trackingEKF", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m" /* pathName */
};

static emlrtRSInfo uq_emlrtRSI = {
    425,                                         /* lineNo */
    "ExtendedKalmanFilter/ExtendedKalmanFilter", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo vq_emlrtRSI = {
    487,                                         /* lineNo */
    "ExtendedKalmanFilter/ExtendedKalmanFilter", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo wq_emlrtRSI = {
    495,                                         /* lineNo */
    "ExtendedKalmanFilter/ExtendedKalmanFilter", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo xq_emlrtRSI = {
    510,                                         /* lineNo */
    "ExtendedKalmanFilter/ExtendedKalmanFilter", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo yq_emlrtRSI = {
    513,                                         /* lineNo */
    "ExtendedKalmanFilter/ExtendedKalmanFilter", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo ar_emlrtRSI = {
    535,                                         /* lineNo */
    "ExtendedKalmanFilter/ExtendedKalmanFilter", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo br_emlrtRSI = {
    559,                                         /* lineNo */
    "ExtendedKalmanFilter/ExtendedKalmanFilter", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo cr_emlrtRSI = {
    911,                              /* lineNo */
    "ExtendedKalmanFilter/set.State", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo ns_emlrtRSI = {
    1077,                                    /* lineNo */
    "ExtendedKalmanFilter/set.ProcessNoise", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo ts_emlrtRSI = {
    1,                                       /* lineNo */
    "RetrodictionFilter/RetrodictionFilter", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/RetrodictionFilter.m" /* pathName */
};

static emlrtRSInfo us_emlrtRSI = {
    1,                                         /* lineNo */
    "OOSMFilter/updateHistoryAfterCorrection", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/OOSMFilter.p" /* pathName */
};

static emlrtRSInfo vs_emlrtRSI = {
    1,                                               /* lineNo */
    "AbstractTrackingFilter/AbstractTrackingFilter", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/AbstractTrackingFilter.m" /* pathName */
};

static emlrtRSInfo ws_emlrtRSI = {
    1,                                       /* lineNo */
    "AbstractJPDAFilter/AbstractJPDAFilter", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/AbstractJPDAFilter.m" /* pathName */
};

static emlrtRSInfo xs_emlrtRSI = {
    1,                                             /* lineNo */
    "AbstractTunableFilter/AbstractTunableFilter", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AbstractTunableFilter.m" /* pathName */
};

static emlrtRSInfo ys_emlrtRSI = {
    1,                                                         /* lineNo */
    "GaussianSmootherJIPDAFilter/GaussianSmootherJIPDAFilter", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/GaussianSmootherJIPDAFilter"
    ".m" /* pathName */
};

static emlrtRSInfo at_emlrtRSI = {
    1,                                                         /* lineNo */
    "AbstractSmootherJIPDAFilter/AbstractSmootherJIPDAFilter", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AbstractSmootherJIPDAFilter"
    ".m" /* pathName */
};

static emlrtRSInfo bt_emlrtRSI = {
    55,                        /* lineNo */
    "EKFSmoother/EKFSmoother", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/smoothers/+matlabshared/"
    "+smoothers/+internal/EKFSmoother.m" /* pathName */
};

static emlrtRSInfo ct_emlrtRSI = {
    19,                                      /* lineNo */
    "LinearizedSmoother/LinearizedSmoother", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/smoothers/+matlabshared/"
    "+smoothers/+internal/LinearizedSmoother.m" /* pathName */
};

/* Function Definitions */
trackingEKF *initializeEKF(const emlrtStack *sp,
                           const real_T Detection_Measurement[3],
                           const real_T Detection_pMeasurementNoise[9],
                           trackingEKF *iobj_0)
{
  static const real_T b_value[9] = {0.070710678118654752, 0.0, 0.0, 0.0,
                                    0.070710678118654752, 0.0, 0.0, 0.0,
                                    0.070710678118654752};
  static const int8_T y[36] = {0, 0, 0, 0, 0, 0, 0, 100, 0, 0,   0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0,   0, 100, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0,   0, 0,   0, 100};
  static const int8_T a[18] = {1, 0, 0, 0, 0, 0, 0, 1, 0,
                               0, 0, 0, 0, 0, 1, 0, 0, 0};
  static const int8_T b_iv[18] = {1, 0, 0, 0, 0, 0, 0, 0, 1,
                                  0, 0, 0, 0, 0, 0, 0, 1, 0};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  trackingEKF *EKF;
  real_T dv1[36];
  real_T dv[18];
  real_T b_localAxes[9];
  real_T c_localAxes[9];
  real_T filterArgs_f3[6];
  real_T localAxes[3];
  real_T d;
  real_T d1;
  real_T d2;
  int32_T b_i;
  int32_T i;
  int32_T i4;
  int8_T i1;
  int8_T i2;
  int8_T i3;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtMEXProfilingFunctionEntry((char_T *)initializeEKF_complete_name,
                                 isMexOutdated);
  /* INITCVEKF  Constant velocity trackingEKF initialization */
  /*    EKF = INITCVEKF(Detection)   initializes a constant velocity (CV) */
  /*    trackingEKF (EKF) based on information provided in Detection. Detection
   */
  /*    must be an objectDetection. The detection must specify the measurement
   */
  /*    parameters, as a struct with the following fields. Default values are */
  /*    used when a field is missing: */
  /*      Frame			  - 'rectangular' or 'spherical'. Default:
   * 'rectangular' */
  /*      OriginPosition  - a 3-by-1 real vector.  Default: [0;0;0] */
  /*      OriginVelocity  - a 3-by-1 real vector.  Default: [0;0;0] */
  /*      Orientation     - a 3-by-3 orthonormal  */
  /*                        orientation matrix.    Default: eye(3) */
  /*      HasElevation    - a logical scalar.      Default: true, elevation is
   * measured */
  /*      HasVelocity     - a logical scalar.	   Default: false in
   * rectangular, true in spherical */
  /* 	  IsParentToChild - a logical scalar.	   Default: false, orientation
   * defines a rotation from child to parent frame */
  /*  */
  /*    Notes: */
  /*    ------ */
  /*    1. You can use INITCVEKF as the FilterInitializationFcn property. */
  /*    2. In creating the filter the function configures the process noise  */
  /*       assuming a unit acceleration standard deviation. */
  /*  */
  /*    Example 1 - detection with position measurement in rectangular frame */
  /*    -------------------------------------------------------------------- */
  /*    % The constant velocity measurement function, cvmeas, provides a  */
  /*    % position measurement in 3-D. For example: x=1, y=3, z=0. */
  /*    % Use a 3-D position measurement noise [1 0.2 0; 0.2 2 0; 0 0 1]; */
  /*    detection = objectDetection(0, [1;3;0], 'MeasurementNoise', [1 0.2 0;
   * 0.2 2 0; 0 0 1]); */
  /*   */
  /*    % Use INITCVEKF to create a trackingEKF filter initialized at the  */
  /*    % provided position and using the measurement noise defined above. */
  /*    ekf1 = initcvekf(detection); */
  /*  */
  /*    % Check the values of the state and measurement noise.  */
  /*    % Verify that the filter state, ekf1.State, has the same position  */
  /*    % components as detection measurement, detection.Measurement.  Verify */
  /*    % that the filter measurement noise, ekf1.MeasurementNoise, is the same
   */
  /*    % as the detection.MeasurementNoise values.  */
  /*    ekf1.State  */
  /*    ekf1.MeasurementNoise */
  /*  */
  /*    Example 2 - detection with position measurement in spherical frame */
  /*    ------------------------------------------------------------------ */
  /*    % The constant velocity measurement function, cvmeas, provides a */
  /*    % spherical measurement. For example: az = 30, el = 5, r = 100, rr = 4
   */
  /*    % Measurement noise is diag([2.5, 2.5, 0.5, 1].^2) */
  /*    meas = [30;5;100;4]; */
  /*    measNoise = diag([2.5, 2.5, 0.5, 1].^2); */
  /*  */
  /*    % Use the MeasurementParameters to define the frame. You can leave out
   */
  /*    % other fields of the MeasurementParameters struct and they will be */
  /*    % completed by default values. In this example, sensor position, sensor
   */
  /*    % velocity, orientation, elevation and range rate flags are default. */
  /*    measParams = struct('Frame','spherical'); */
  /*    detection = objectDetection(0, meas, 'MeasurementNoise', measNoise,...
   */
  /*        'MeasurementParameters', measParams); */
  /*   */
  /*    % Use INITCVEKF to create a trackingEKF filter initialized at the  */
  /*    % provided position and using the measurement noise defined above. */
  /*    ekf2 = initcvekf(detection); */
  /*  */
  /*    % Verify that the filter state produces the same measurement as above */
  /*    meas2 = cvmeas(ekf2.State, measParams) */
  /*    isequal(meas, meas2) */
  /*  */
  /*    See also: trackingEKF, objectDetection, initcvkf, initcakf, initcaekf,
   */
  /*    initctekf, initcvukf, initcaukf, initctukf, constvel, constveljac, */
  /*    cvmeas, cvmeasjac */
  /*  Copyright 2016-2018 The MathWorks, Inc. */
  /*  Input validation: */
  /*  Convert the Measurement to Rectangular Coordinates */
  /*  A detection may have measurements in a sensor local coordinate system, */
  /*  either spherical or rectangular. This filter defines the state in a */
  /*  rectangular coordinate system relative to the ego vehicle. This requires
   */
  /*  the conversion of the measurement between frames */
  emlrtMEXProfilingStatement(4, isMexOutdated);
  emlrtMEXProfilingStatement(5, isMexOutdated);
  st.site = &nq_emlrtRSI;
  b_st.site = &pq_emlrtRSI;
  c_st.site = &jc_emlrtRSI;
  p = true;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 3)) {
    if ((!muDoubleScalarIsInf(Detection_Measurement[i])) &&
        (!muDoubleScalarIsNaN(Detection_Measurement[i]))) {
      i++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &h_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:initializeEKF:expectedFinite", 3, 4, 21,
        "Detection.Measurement");
  }
  /*  How to Initialize a Tracking Filter? */
  /*  Things to consider when creating a filter: */
  /*    1. Defining the motion model and state */
  /*    2. Defining the process noise */
  /*    3. Defining the measurement model */
  /*    4. Mapping the sensor measurements to an initial state vector */
  /*    5. Mapping the sensor measurement noise to a state covariance */
  /*    6. Creating the correct filter */
  /*  Step 1: Defining the motion model and state */
  /*    In this example, use a constant velocity model in a rectangular frame */
  /*      1. In 3-D motion, the state is [x;vx;y;vy;z;vz] */
  /*      2. The state transition function is constvel */
  /*      3. The state transition Jacobian function is constveljac */
  /*  Step 2: Defining the process noise  */
  /*    The process noise represents the parts of the process that are not */
  /*    taken into account in the model. For example, in a constant velocity */
  /*    model, the acceleration is neglected. To account for it, a scaled 1-d */
  /*    scaled acceleration represents the magnitude of the possible */
  /*    acceleration that is neglected in each direction. */
  /*  Step 3: Defining the measurement model */
  /*    For a constant velocity state, use the following: */
  /*    1. The measurement function is cvmeas */
  /*    2. The measurement Jacobian function is cvmeasjac */
  /*  Step 4: Initializing the state vector using the Measurement */
  /*    Since the state is [x;vx;y;vy;z;vz], use the measurements of position */
  /*    and velocity (if available) to initialize the state */
  /*  position = Hpos * state */
  /*  velocity = Hvel * state */
  emlrtMEXProfilingStatement(11, isMexOutdated);
  /*  Step 5: Initializing the state covariance using MeasurementNoise */
  /*    For the parts of the state that are measured directly by the sensor, */
  /*    use the corresponding measurement noise components. For the parts that
   */
  /*    are not measured directly, assume a large initial state covariance. */
  /*    This will allow future detections to be assigned to the track. */
  emlrtMEXProfilingStatement(12, isMexOutdated);
  /*  Step 6: Creating the correct filter */
  /*    Creating a trackingEKF filter with a constant velocity model and the */
  /*    properties defined above */
  emlrtMEXProfilingStatement(13, isMexOutdated);
  emlrtMEXProfilingStatement(19, isMexOutdated);
  emlrtMEXProfilingStatement(21, isMexOutdated);
  emlrtMEXProfilingStatement(23, isMexOutdated);
  emlrtMEXProfilingStatement(24, isMexOutdated);
  emlrtMEXProfilingStatement(25, isMexOutdated);
  emlrtMEXProfilingStatement(26, isMexOutdated);
  emlrtMEXProfilingStatement(29, isMexOutdated);
  emlrtMEXProfilingStatement(30, isMexOutdated);
  st.site = &oq_emlrtRSI;
  d = Detection_Measurement[0];
  d1 = Detection_Measurement[1];
  d2 = Detection_Measurement[2];
  for (b_i = 0; b_i < 3; b_i++) {
    localAxes[b_i] = ((real_T)iv1[b_i] * d + (real_T)iv1[b_i + 3] * d1) +
                     (real_T)iv1[b_i + 6] * d2;
  }
  d = localAxes[0];
  d1 = localAxes[1];
  d2 = localAxes[2];
  for (b_i = 0; b_i < 6; b_i++) {
    filterArgs_f3[b_i] = ((real_T)b_iv[b_i] * d + (real_T)b_iv[b_i + 6] * d1) +
                         (real_T)b_iv[b_i + 12] * d2;
  }
  b_st.site = &qq_emlrtRSI;
  iobj_0->pIsFirstCallPredict = true;
  iobj_0->pIsFirstCallCorrect = true;
  c_st.site = &uq_emlrtRSI;
  c_st.site = &vq_emlrtRSI;
  d_st.site = &cr_emlrtRSI;
  e_st.site = &jc_emlrtRSI;
  p = true;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 6)) {
    if ((!muDoubleScalarIsInf(filterArgs_f3[i])) &&
        (!muDoubleScalarIsNaN(filterArgs_f3[i]))) {
      i++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &h_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:ExtendedKalmanFilter:expectedFinite", 3, 4, 5, "State");
  }
  for (i = 0; i < 6; i++) {
    iobj_0->pState[i] = filterArgs_f3[i];
  }
  iobj_0->pSqrtStateCovarianceScalar = 1.0;
  for (b_i = 0; b_i < 3; b_i++) {
    i1 = iv1[b_i];
    i2 = iv1[b_i + 3];
    i3 = iv1[b_i + 6];
    for (i4 = 0; i4 < 3; i4++) {
      b_localAxes[b_i + 3 * i4] =
          ((real_T)i1 * Detection_pMeasurementNoise[3 * i4] +
           (real_T)i2 * Detection_pMeasurementNoise[3 * i4 + 1]) +
          (real_T)i3 * Detection_pMeasurementNoise[3 * i4 + 2];
    }
    d = b_localAxes[b_i];
    d1 = b_localAxes[b_i + 3];
    d2 = b_localAxes[b_i + 6];
    for (i4 = 0; i4 < 3; i4++) {
      c_localAxes[b_i + 3 * i4] =
          (d * (real_T)iv1[3 * i4] + d1 * (real_T)iv1[3 * i4 + 1]) +
          d2 * (real_T)iv1[3 * i4 + 2];
    }
  }
  for (b_i = 0; b_i < 6; b_i++) {
    i1 = b_iv[b_i];
    i2 = b_iv[b_i + 6];
    i3 = b_iv[b_i + 12];
    for (i4 = 0; i4 < 3; i4++) {
      dv[b_i + 6 * i4] = ((real_T)i1 * c_localAxes[3 * i4] +
                          (real_T)i2 * c_localAxes[3 * i4 + 1]) +
                         (real_T)i3 * c_localAxes[3 * i4 + 2];
    }
    d = dv[b_i];
    d1 = dv[b_i + 6];
    d2 = dv[b_i + 12];
    for (i4 = 0; i4 < 6; i4++) {
      i = b_i + 6 * i4;
      dv1[i] = ((d * (real_T)a[3 * i4] + d1 * (real_T)a[3 * i4 + 1]) +
                d2 * (real_T)a[3 * i4 + 2]) +
               (real_T)y[i];
    }
  }
  c_st.site = &wq_emlrtRSI;
  c_ExtendedKalmanFilter_set_Stat(&c_st, iobj_0, dv1);
  c_st.site = &xq_emlrtRSI;
  iobj_0->pIsValidStateTransitionFcn = false;
  c_st.site = &yq_emlrtRSI;
  iobj_0->pIsValidMeasurementFcn = false;
  iobj_0->pIsValidMeasurementFcn = false;
  iobj_0->pIsValidStateTransitionFcn = false;
  iobj_0->pSqrtProcessNoiseScalar = 1.0;
  c_st.site = &ar_emlrtRSI;
  d_st.site = &ns_emlrtRSI;
  for (b_i = 0; b_i < 9; b_i++) {
    iobj_0->pSqrtProcessNoise[b_i] = b_value[b_i];
  }
  iobj_0->pIsSetProcessNoise = true;
  iobj_0->pSqrtProcessNoiseScalar = -1.0;
  iobj_0->pSqrtMeasurementNoiseScalar = 1.0;
  memcpy(&b_localAxes[0], &Detection_pMeasurementNoise[0], 9U * sizeof(real_T));
  c_st.site = &br_emlrtRSI;
  c_ExtendedKalmanFilter_set_Meas(&c_st, iobj_0, b_localAxes);
  iobj_0->pHasPrediction = false;
  b_st.site = &rq_emlrtRSI;
  iobj_0->pWasRetrodicted = false;
  c_st.site = &ts_emlrtRSI;
  d_st.site = &us_emlrtRSI;
  b_st.site = &sq_emlrtRSI;
  c_st.site = &vs_emlrtRSI;
  b_st.site = &sq_emlrtRSI;
  c_st.site = &ws_emlrtRSI;
  b_st.site = &sq_emlrtRSI;
  c_st.site = &xs_emlrtRSI;
  b_st.site = &sq_emlrtRSI;
  c_st.site = &ys_emlrtRSI;
  d_st.site = &at_emlrtRSI;
  b_st.site = &tq_emlrtRSI;
  c_st.site = &bt_emlrtRSI;
  iobj_0->IsLastJacobianInitialized = false;
  d_st.site = &ct_emlrtRSI;
  iobj_0->pIsDistributionsSetup = false;
  iobj_0->pIsInitialized = false;
  EKF = iobj_0;
  emlrtMEXProfilingStatement(32, isMexOutdated);
  /*  Helps coder deduce the measurement sizes */
  emlrtMEXProfilingStatement(33, isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  return EKF;
}

/* End of code generation (initializeEKF.c) */
