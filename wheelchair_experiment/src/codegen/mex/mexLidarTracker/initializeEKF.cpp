//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  initializeEKF.cpp
//
//  Code generation for function 'initializeEKF'
//


// Include files
#include "initializeEKF.h"
#include "mexLidarTracker_data.h"
#include "objectDetection.h"
#include "rt_nonfinite.h"
#include "trackingEKF.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo hs_emlrtRSI = { 84, // lineNo
  "initializeEKF",                     // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/initializeEKF.m"// pathName 
};

static emlrtRSInfo is_emlrtRSI = { 149,// lineNo
  "initializeEKF",                     // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/src/Estimator/initializeEKF.m"// pathName 
};

static emlrtRSInfo js_emlrtRSI = { 46, // lineNo
  "parseDetectionForInitFcn",          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/fusionlib/+matlabshared/+tracking/+internal/+fusion/parseDetectionForInitFcn.m"// pathName 
};

// Function Definitions
coder::trackingEKF *initializeEKF(const emlrtStack *sp, const coder::
  objectDetection *Detection, coder::trackingEKF *iobj_0)
{
  static const int8_T y[36] = { 0, 0, 0, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100 };

  static const int8_T a[18] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0 };

  static const int8_T b_iv[18] = { 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 1, 0 };

  coder::trackingEKF *EKF;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T dv1[36];
  real_T dv3[18];
  real_T b_localAxes[9];
  real_T localAxes[9];
  real_T measurementNoise_tmp[9];
  real_T dv[6];
  real_T dv2[3];
  real_T d;
  real_T d1;
  real_T d2;
  int32_T i;
  int32_T i1;
  int32_T k;
  emlrtProfilerSentinel profilerSentinel;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtMEXProfilingFunctionEntryCPP(initializeEKF_complete_name,
    static_cast<boolean_T>(isMexOutdated), &profilerSentinel);

  // INITCVEKF  Constant velocity trackingEKF initialization
  //    EKF = INITCVEKF(Detection)   initializes a constant velocity (CV)
  //    trackingEKF (EKF) based on information provided in Detection. Detection
  //    must be an objectDetection. The detection must specify the measurement
  //    parameters, as a struct with the following fields. Default values are
  //    used when a field is missing:
  //      Frame			  - 'rectangular' or 'spherical'. Default: 'rectangular'
  //      OriginPosition  - a 3-by-1 real vector.  Default: [0;0;0]
  //      OriginVelocity  - a 3-by-1 real vector.  Default: [0;0;0]
  //      Orientation     - a 3-by-3 orthonormal
  //                        orientation matrix.    Default: eye(3)
  //      HasElevation    - a logical scalar.      Default: true, elevation is measured 
  //      HasVelocity     - a logical scalar.	   Default: false in rectangular, true in spherical 
  // 	  IsParentToChild - a logical scalar.	   Default: false, orientation defines a rotation from child to parent frame 
  //
  //    Notes:
  //    ------
  //    1. You can use INITCVEKF as the FilterInitializationFcn property.
  //    2. In creating the filter the function configures the process noise
  //       assuming a unit acceleration standard deviation.
  //
  //    Example 1 - detection with position measurement in rectangular frame
  //    --------------------------------------------------------------------
  //    % The constant velocity measurement function, cvmeas, provides a
  //    % position measurement in 3-D. For example: x=1, y=3, z=0.
  //    % Use a 3-D position measurement noise [1 0.2 0; 0.2 2 0; 0 0 1];
  //    detection = objectDetection(0, [1;3;0], 'MeasurementNoise', [1 0.2 0; 0.2 2 0; 0 0 1]); 
  //
  //    % Use INITCVEKF to create a trackingEKF filter initialized at the
  //    % provided position and using the measurement noise defined above.
  //    ekf1 = initcvekf(detection);
  //
  //    % Check the values of the state and measurement noise.
  //    % Verify that the filter state, ekf1.State, has the same position
  //    % components as detection measurement, detection.Measurement.  Verify
  //    % that the filter measurement noise, ekf1.MeasurementNoise, is the same  
  //    % as the detection.MeasurementNoise values.
  //    ekf1.State
  //    ekf1.MeasurementNoise
  //
  //    Example 2 - detection with position measurement in spherical frame
  //    ------------------------------------------------------------------
  //    % The constant velocity measurement function, cvmeas, provides a
  //    % spherical measurement. For example: az = 30, el = 5, r = 100, rr = 4
  //    % Measurement noise is diag([2.5, 2.5, 0.5, 1].^2)
  //    meas = [30;5;100;4];
  //    measNoise = diag([2.5, 2.5, 0.5, 1].^2);
  //
  //    % Use the MeasurementParameters to define the frame. You can leave out
  //    % other fields of the MeasurementParameters struct and they will be
  //    % completed by default values. In this example, sensor position, sensor
  //    % velocity, orientation, elevation and range rate flags are default.
  //    measParams = struct('Frame','spherical');
  //    detection = objectDetection(0, meas, 'MeasurementNoise', measNoise,...
  //        'MeasurementParameters', measParams);
  //
  //    % Use INITCVEKF to create a trackingEKF filter initialized at the
  //    % provided position and using the measurement noise defined above.
  //    ekf2 = initcvekf(detection);
  //
  //    % Verify that the filter state produces the same measurement as above
  //    meas2 = cvmeas(ekf2.State, measParams)
  //    isequal(meas, meas2)
  //
  //    See also: trackingEKF, objectDetection, initcvkf, initcakf, initcaekf,
  //    initctekf, initcvukf, initcaukf, initctukf, constvel, constveljac,
  //    cvmeas, cvmeasjac
  //  Copyright 2016-2018 The MathWorks, Inc.
  //  Input validation:
  //  Convert the Measurement to Rectangular Coordinates
  //  A detection may have measurements in a sensor local coordinate system,
  //  either spherical or rectangular. This filter defines the state in a
  //  rectangular coordinate system relative to the ego vehicle. This requires
  //  the conversion of the measurement between frames
  emlrtMEXProfilingStatement(4, static_cast<boolean_T>(isMexOutdated));
  emlrtMEXProfilingStatement(5, static_cast<boolean_T>(isMexOutdated));
  st.site = &hs_emlrtRSI;
  b_st.site = &js_emlrtRSI;
  c_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 3)) {
    if ((!muDoubleScalarIsInf(Detection->Measurement[k])) &&
        (!muDoubleScalarIsNaN(Detection->Measurement[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&c_st, &j_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:initializeEKF:expectedFinite", 3, 4, 21, "Detection.Measurement");
  }

  Detection->get_MeasurementNoise(measurementNoise_tmp);

  //  How to Initialize a Tracking Filter?
  //  Things to consider when creating a filter:
  //    1. Defining the motion model and state
  //    2. Defining the process noise
  //    3. Defining the measurement model
  //    4. Mapping the sensor measurements to an initial state vector
  //    5. Mapping the sensor measurement noise to a state covariance
  //    6. Creating the correct filter
  //  Step 1: Defining the motion model and state
  //    In this example, use a constant velocity model in a rectangular frame
  //      1. In 3-D motion, the state is [x;vx;y;vy;z;vz]
  //      2. The state transition function is constvel
  //      3. The state transition Jacobian function is constveljac
  //  Step 2: Defining the process noise
  //    The process noise represents the parts of the process that are not
  //    taken into account in the model. For example, in a constant velocity
  //    model, the acceleration is neglected. To account for it, a scaled 1-d
  //    scaled acceleration represents the magnitude of the possible
  //    acceleration that is neglected in each direction.
  //  Step 3: Defining the measurement model
  //    For a constant velocity state, use the following:
  //    1. The measurement function is cvmeas
  //    2. The measurement Jacobian function is cvmeasjac
  //  Step 4: Initializing the state vector using the Measurement
  //    Since the state is [x;vx;y;vy;z;vz], use the measurements of position
  //    and velocity (if available) to initialize the state
  //  position = Hpos * state
  //  velocity = Hvel * state
  emlrtMEXProfilingStatement(11, static_cast<boolean_T>(isMexOutdated));

  //  Step 5: Initializing the state covariance using MeasurementNoise
  //    For the parts of the state that are measured directly by the sensor,
  //    use the corresponding measurement noise components. For the parts that
  //    are not measured directly, assume a large initial state covariance.
  //    This will allow future detections to be assigned to the track.
  emlrtMEXProfilingStatement(12, static_cast<boolean_T>(isMexOutdated));

  //  Step 6: Creating the correct filter
  //    Creating a trackingEKF filter with a constant velocity model and the
  //    properties defined above
  emlrtMEXProfilingStatement(13, static_cast<boolean_T>(isMexOutdated));
  emlrtMEXProfilingStatement(19, static_cast<boolean_T>(isMexOutdated));
  emlrtMEXProfilingStatement(21, static_cast<boolean_T>(isMexOutdated));
  emlrtMEXProfilingStatement(23, static_cast<boolean_T>(isMexOutdated));
  emlrtMEXProfilingStatement(24, static_cast<boolean_T>(isMexOutdated));
  emlrtMEXProfilingStatement(25, static_cast<boolean_T>(isMexOutdated));
  emlrtMEXProfilingStatement(26, static_cast<boolean_T>(isMexOutdated));
  emlrtMEXProfilingStatement(29, static_cast<boolean_T>(isMexOutdated));
  emlrtMEXProfilingStatement(30, static_cast<boolean_T>(isMexOutdated));
  for (i = 0; i < 3; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 3; i1++) {
      k = i + 3 * i1;
      d += static_cast<real_T>(iv[k]) * Detection->Measurement[i1];
      localAxes[k] = (static_cast<real_T>(iv[i]) * measurementNoise_tmp[3 * i1]
                      + static_cast<real_T>(iv[i + 3]) * measurementNoise_tmp[3 *
                      i1 + 1]) + static_cast<real_T>(iv[i + 6]) *
        measurementNoise_tmp[3 * i1 + 2];
    }

    dv2[i] = d;
    d = localAxes[i];
    d1 = localAxes[i + 3];
    d2 = localAxes[i + 6];
    for (i1 = 0; i1 < 3; i1++) {
      b_localAxes[i + 3 * i1] = (d * static_cast<real_T>(iv[3 * i1]) + d1 *
        static_cast<real_T>(iv[3 * i1 + 1])) + d2 * static_cast<real_T>(iv[3 *
        i1 + 2]);
    }
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 3; i1++) {
      k = i + 6 * i1;
      dv3[k] = (static_cast<real_T>(b_iv[i]) * b_localAxes[3 * i1] +
                static_cast<real_T>(b_iv[i + 6]) * b_localAxes[3 * i1 + 1]) +
        static_cast<real_T>(b_iv[i + 12]) * b_localAxes[3 * i1 + 2];
      d += static_cast<real_T>(b_iv[k]) * dv2[i1];
    }

    dv[i] = d;
    d = dv3[i];
    d1 = dv3[i + 6];
    d2 = dv3[i + 12];
    for (i1 = 0; i1 < 6; i1++) {
      k = i + 6 * i1;
      dv1[k] = ((d * static_cast<real_T>(a[3 * i1]) + d1 * static_cast<real_T>
                 (a[3 * i1 + 1])) + d2 * static_cast<real_T>(a[3 * i1 + 2])) +
        static_cast<real_T>(y[k]);
    }
  }

  st.site = &is_emlrtRSI;
  EKF = iobj_0->init(&st, dv, dv1, measurementNoise_tmp);
  emlrtMEXProfilingStatement(32, static_cast<boolean_T>(isMexOutdated));

  //  Helps coder deduce the measurement sizes
  emlrtMEXProfilingStatement(33, static_cast<boolean_T>(isMexOutdated));
  emlrtMEXProfilingFunctionExitCPP(&profilerSentinel);
  return EKF;
}

// End of code generation (initializeEKF.cpp)
