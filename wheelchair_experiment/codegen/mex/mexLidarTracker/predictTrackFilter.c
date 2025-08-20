/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * predictTrackFilter.c
 *
 * Code generation for function 'predictTrackFilter'
 *
 */

/* Include files */
#include "predictTrackFilter.h"
#include "EKFPredictorNonAdditive.h"
#include "constvel.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_types.h"
#include "rt_nonfinite.h"
#include "validateattributes.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo qv_emlrtRSI = {
    1601,                                                       /* lineNo */
    "ExtendedKalmanFilter/processNoiseScalarExpandIfNecessary", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo xcb_emlrtRSI = {
    154,                                          /* lineNo */
    "AbstractSmoother/setupInitialDistributions", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/smoothers/+matlabshared/"
    "+smoothers/+internal/AbstractSmoother.m" /* pathName */
};

static emlrtRSInfo ycb_emlrtRSI = {
    42,                                          /* lineNo */
    "LinearizedSmoother/ensureMethodDefinition", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/smoothers/+matlabshared/"
    "+smoothers/+internal/LinearizedSmoother.m" /* pathName */
};

static emlrtRSInfo adb_emlrtRSI = {
    31,                                               /* lineNo */
    "LinearizedSmoother/ensureLastJacobianIsDefined", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/smoothers/+matlabshared/"
    "+smoothers/+internal/LinearizedSmoother.m" /* pathName */
};

static emlrtRSInfo bdb_emlrtRSI = {
    220,                                      /* lineNo */
    "GaussianSmoother/getStateAndCovariance", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/smoothers/+matlabshared/"
    "+smoothers/+internal/GaussianSmoother.m" /* pathName */
};

static emlrtRSInfo ddb_emlrtRSI = {
    1860,                                               /* lineNo */
    "ExtendedKalmanFilter/ensureProcessNoiseIsDefined", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo edb_emlrtRSI = {
    22,                   /* lineNo */
    "predictTrackFilter", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/predictTrackFilter.m" /* pathName */
};

static emlrtRSInfo fdb_emlrtRSI =
    {
        167,                   /* lineNo */
        "trackingEKF/predict", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m" /* pathName */
};

static emlrtRSInfo gdb_emlrtRSI =
    {
        170,                   /* lineNo */
        "trackingEKF/predict", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m" /* pathName */
};

static emlrtRSInfo hdb_emlrtRSI = {
    599,                            /* lineNo */
    "ExtendedKalmanFilter/predict", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo idb_emlrtRSI = {
    602,                            /* lineNo */
    "ExtendedKalmanFilter/predict", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo jdb_emlrtRSI = {
    1542,                                                   /* lineNo */
    "ExtendedKalmanFilter/ensureFilterPredictionReadiness", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo kdb_emlrtRSI = {
    1543,                                                   /* lineNo */
    "ExtendedKalmanFilter/ensureFilterPredictionReadiness", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo ldb_emlrtRSI = {
    1567,                                                   /* lineNo */
    "ExtendedKalmanFilter/ensureFilterPredictionReadiness", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo mdb_emlrtRSI = {
    1577,                                                   /* lineNo */
    "ExtendedKalmanFilter/ensureFilterPredictionReadiness", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo ndb_emlrtRSI = {
    13,                                                   /* lineNo */
    "EKFPredictorNonAdditive/validateStateTransitionFcn", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/EKFPredictorNonAdditive.m" /* pathName */
};

static emlrtRSInfo odb_emlrtRSI = {
    1881,                                                      /* lineNo */
    "ExtendedKalmanFilter/validateStateTransitionJacobianFcn", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo pdb_emlrtRSI = {
    1883,                                                      /* lineNo */
    "ExtendedKalmanFilter/validateStateTransitionJacobianFcn", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo qdb_emlrtRSI = {
    18,                                                           /* lineNo */
    "EKFPredictorNonAdditive/validateStateTransitionJacobianFcn", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/EKFPredictorNonAdditive.m" /* pathName */
};

/* Function Definitions */
void predictTrackFilter(const emlrtStack *sp, trackingEKF *filter, real_T dt)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  real_T dv[6];
  real_T a;
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &edb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  b_st.site = &fdb_emlrtRSI;
  c_st.site = &xcb_emlrtRSI;
  d_st.site = &ycb_emlrtRSI;
  if (!filter->IsLastJacobianInitialized) {
    e_st.site = &adb_emlrtRSI;
    f_st.site = &bdb_emlrtRSI;
    filter->IsLastJacobianInitialized = true;
  }
  if (!filter->pIsDistributionsSetup) {
    filter->pIsDistributionsSetup = true;
  }
  b_st.site = &gdb_emlrtRSI;
  c_st.site = &hdb_emlrtRSI;
  d_st.site = &jdb_emlrtRSI;
  e_st.site = &cdb_emlrtRSI;
  if ((!filter->pIsSetStateCovariance) ||
      (filter->pSqrtStateCovarianceScalar != -1.0)) {
    a = filter->pSqrtStateCovarianceScalar;
    f_st.site = &jv_emlrtRSI;
    for (i = 0; i < 36; i++) {
      filter->pSqrtStateCovariance[i] = a * (real_T)iv2[i];
    }
  }
  d_st.site = &kdb_emlrtRSI;
  e_st.site = &ddb_emlrtRSI;
  if ((!filter->pIsSetProcessNoise) ||
      (filter->pSqrtProcessNoiseScalar != -1.0)) {
    a = filter->pSqrtProcessNoiseScalar;
    f_st.site = &qv_emlrtRSI;
    for (i = 0; i < 9; i++) {
      filter->pSqrtProcessNoise[i] = a * (real_T)iv1[i];
    }
    filter->pIsSetProcessNoise = true;
    filter->pSqrtProcessNoiseScalar = -1.0;
  }
  if (filter->pIsFirstCallPredict) {
    if (!filter->pIsValidStateTransitionFcn) {
      d_st.site = &ldb_emlrtRSI;
      for (i = 0; i < 6; i++) {
        dv[i] = filter->pState[i];
      }
      e_st.site = &ndb_emlrtRSI;
      constvel(&e_st, dv, dt);
      filter->pIsValidStateTransitionFcn = true;
    }
    d_st.site = &mdb_emlrtRSI;
    e_st.site = &odb_emlrtRSI;
    f_st.site = &qdb_emlrtRSI;
    g_st.site = &rdb_emlrtRSI;
    b_validateattributes(&g_st, filter->pState);
    g_st.site = &sdb_emlrtRSI;
    h_st.site = &jc_emlrtRSI;
    if (muDoubleScalarIsInf(dt) || muDoubleScalarIsNaN(dt)) {
      emlrtErrorWithMessageIdR2018a(
          &h_st, &h_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
          "MATLAB:constveljac:expectedFinite", 3, 4, 19, "input number 3, dt,");
    }
    g_st.site = &tdb_emlrtRSI;
    e_st.site = &pdb_emlrtRSI;
    filter->pIsFirstCallPredict = false;
  }
  for (i = 0; i < 6; i++) {
    dv[i] = filter->pState[i];
  }
  c_st.site = &idb_emlrtRSI;
  EKFPredictorNonAdditive_predict(&c_st, filter->pSqrtProcessNoise, dv,
                                  filter->pSqrtStateCovariance, dt,
                                  filter->pJacobian);
  for (i = 0; i < 6; i++) {
    filter->pState[i] = dv[i];
  }
  c_st.site = &idb_emlrtRSI;
  filter->pIsSetStateCovariance = true;
  filter->pSqrtStateCovarianceScalar = -1.0;
  filter->pHasPrediction = true;
}

/* End of code generation (predictTrackFilter.c) */
