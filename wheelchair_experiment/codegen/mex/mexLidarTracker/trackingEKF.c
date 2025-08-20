/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * trackingEKF.c
 *
 * Code generation for function 'trackingEKF'
 *
 */

/* Include files */
#include "trackingEKF.h"
#include "EKFCorrector.h"
#include "ExtendedKalmanFilter.h"
#include "cholPSD.h"
#include "constvel.h"
#include "cvmeas.h"
#include "cvmeasjac.h"
#include "indexShapeCheck.h"
#include "jpdaWeightInnovationAndCovariances.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_emxutil.h"
#include "mexLidarTracker_types.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "validateInputSizeAndType.h"
#include "xgemv.h"
#include "xgerc.h"
#include "xnrm2.h"
#include "xscal.h"
#include "xzlarf.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ju_emlrtRSI = {
    119,                                  /* lineNo */
    "RetrodictionFilter/syncRetroFilter", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/RetrodictionFilter.m" /* pathName */
};

static emlrtRSInfo qu_emlrtRSI =
    {
        610,                   /* lineNo */
        "trackingEKF/nullify", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m" /* pathName */
};

static emlrtRSInfo ru_emlrtRSI =
    {
        611,                   /* lineNo */
        "trackingEKF/nullify", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m" /* pathName */
};

static emlrtRSInfo cv_emlrtRSI =
    {
        639,                /* lineNo */
        "trackingEKF/sync", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m" /* pathName */
};

static emlrtRSInfo dv_emlrtRSI =
    {
        640,                /* lineNo */
        "trackingEKF/sync", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m" /* pathName */
};

static emlrtRSInfo ev_emlrtRSI =
    {
        641,                /* lineNo */
        "trackingEKF/sync", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m" /* pathName */
};

static emlrtRSInfo fv_emlrtRSI =
    {
        642,                /* lineNo */
        "trackingEKF/sync", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m" /* pathName */
};

static emlrtRSInfo gv_emlrtRSI =
    {
        645,                /* lineNo */
        "trackingEKF/sync", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m" /* pathName */
};

static emlrtRSInfo nv_emlrtRSI = {
    1325,                                         /* lineNo */
    "ExtendedKalmanFilter/set.pMeasurementNoise", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo ov_emlrtRSI = {
    1103,                                    /* lineNo */
    "ExtendedKalmanFilter/get.ProcessNoise", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo pv_emlrtRSI = {
    1104,                                    /* lineNo */
    "ExtendedKalmanFilter/get.ProcessNoise", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo rv_emlrtRSI = {
    1295,                                     /* lineNo */
    "ExtendedKalmanFilter/set.pProcessNoise", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo ybb_emlrtRSI =
    {
        660,                                                /* lineNo */
        "@(state,dt)filter.StateTransitionFcn(state,v,dt)", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m" /* pathName */
};

static emlrtRSInfo vjb_emlrtRSI =
    {
        348,                    /* lineNo */
        "trackingEKF/residual", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m" /* pathName */
};

static emlrtRSInfo wjb_emlrtRSI = {
    708,                             /* lineNo */
    "ExtendedKalmanFilter/residual", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo xjb_emlrtRSI = {
    718,                             /* lineNo */
    "ExtendedKalmanFilter/residual", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo yjb_emlrtRSI = {
    721,                             /* lineNo */
    "ExtendedKalmanFilter/residual", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo bkb_emlrtRSI = {
    131,                     /* lineNo */
    "EKFCorrector/residual", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/EKFCorrector.m" /* pathName */
};

static emlrtRSInfo ckb_emlrtRSI = {
    137,                                                        /* lineNo */
    "EKFCorrectorAdditive/getMeasurementJacobianAndCovariance", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/EKFCorrectorAdditive.m" /* pathName */
};

static emlrtRSInfo dkb_emlrtRSI = {
    128,                                                        /* lineNo */
    "EKFCorrectorAdditive/getMeasurementJacobianAndCovariance", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/EKFCorrectorAdditive.m" /* pathName */
};

static emlrtRSInfo ekb_emlrtRSI = {
    121,                                                        /* lineNo */
    "EKFCorrectorAdditive/getMeasurementJacobianAndCovariance", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/EKFCorrectorAdditive.m" /* pathName */
};

static emlrtRSInfo fkb_emlrtRSI = {
    163,                                        /* lineNo */
    "EKFCorrectorAdditive/measurementMatrices", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/EKFCorrectorAdditive.m" /* pathName */
};

static emlrtRSInfo mmb_emlrtRSI =
    {
        857,                                     /* lineNo */
        "trackingEKF/validateCorrectJPDAInputs", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m" /* pathName */
};

static emlrtRSInfo nmb_emlrtRSI =
    {
        862,                                     /* lineNo */
        "trackingEKF/validateCorrectJPDAInputs", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m" /* pathName */
};

static emlrtRSInfo rmb_emlrtRSI = {
    173,                        /* lineNo */
    "EKFCorrector/correctjpda", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/EKFCorrector.m" /* pathName */
};

static emlrtRTEInfo
    sc_emlrtRTEI =
        {
            150,        /* lineNo */
            27,         /* colNo */
            "constvel", /* fName */
            "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
            "constvel.m" /* pName */
};

static emlrtECInfo
    q_emlrtECI =
        {
            2,          /* nDims */
            165,        /* lineNo */
            25,         /* colNo */
            "constvel", /* fName */
            "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
            "constvel.m" /* pName */
};

static emlrtECInfo
    r_emlrtECI =
        {
            -1,         /* nDims */
            165,        /* lineNo */
            5,          /* colNo */
            "constvel", /* fName */
            "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
            "constvel.m" /* pName */
};

static emlrtECInfo
    s_emlrtECI =
        {
            2,          /* nDims */
            166,        /* lineNo */
            23,         /* colNo */
            "constvel", /* fName */
            "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
            "constvel.m" /* pName */
};

static emlrtECInfo
    t_emlrtECI =
        {
            -1,         /* nDims */
            166,        /* lineNo */
            5,          /* colNo */
            "constvel", /* fName */
            "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
            "constvel.m" /* pName */
};

static emlrtBCInfo hh_emlrtBCI =
    {
        -1,                                      /* iFirst */
        -1,                                      /* iLast */
        842,                                     /* lineNo */
        43,                                      /* colNo */
        "",                                      /* aName */
        "trackingEKF/validateCorrectJPDAInputs", /* fName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m", /* pName */
        0                /* checkKind */
};

static emlrtBCInfo ih_emlrtBCI =
    {
        -1,                                      /* iFirst */
        -1,                                      /* iLast */
        850,                                     /* lineNo */
        64,                                      /* colNo */
        "",                                      /* aName */
        "trackingEKF/validateCorrectJPDAInputs", /* fName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m", /* pName */
        0                /* checkKind */
};

static emlrtRTEInfo bd_emlrtRTEI =
    {
        863,                                     /* lineNo */
        16,                                      /* colNo */
        "trackingEKF/validateCorrectJPDAInputs", /* fName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m" /* pName */
};

static emlrtBCInfo jh_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    173,                        /* lineNo */
    26,                         /* colNo */
    "",                         /* aName */
    "EKFCorrector/correctjpda", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/EKFCorrector.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo kh_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    173,                        /* lineNo */
    28,                         /* colNo */
    "",                         /* aName */
    "EKFCorrector/correctjpda", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/EKFCorrector.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo lh_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    174,                        /* lineNo */
    29,                         /* colNo */
    "",                         /* aName */
    "EKFCorrector/correctjpda", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/EKFCorrector.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtRTEInfo cd_emlrtRTEI = {
    18,              /* lineNo */
    23,              /* colNo */
    "validatenumel", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatenumel.m" /* pName */
};

static emlrtRTEInfo dd_emlrtRTEI = {
    28,           /* lineNo */
    27,           /* colNo */
    "validatele", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatele.m" /* pName */
};

static emlrtRTEInfo an_emlrtRTEI = {
    173,            /* lineNo */
    21,             /* colNo */
    "EKFCorrector", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/EKFCorrector.m" /* pName */
};

/* Function Definitions */
trackingEKF *trackingEKF_clone(trackingEKF *obj, trackingEKF *iobj_0)
{
  trackingEKF *obj2;
  obj2 = ExtendedKalmanFilter_clone(obj, iobj_0);
  obj2->IsLastJacobianInitialized = obj->IsLastJacobianInitialized;
  if (obj->pIsDistributionsSetup) {
    obj2->pIsDistributionsSetup = obj->pIsDistributionsSetup;
  }
  obj2->pShouldWarn = obj->pShouldWarn;
  obj2->pWasRetrodicted = obj->pWasRetrodicted;
  return obj2;
}

void trackingEKF_correctjpda(const emlrtStack *sp, trackingEKF *filter,
                             const emxArray_real_T *z,
                             const emxArray_real_T *jpda)
{
  static real_T wrapping[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  __m128d r;
  __m128d r1;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_real_T *b_jpda;
  real_T P[36];
  real_T b_a[36];
  real_T b_value[36];
  real_T Pxy[18];
  real_T dHdx[18];
  real_T gain[18];
  real_T a[9];
  real_T b_dHdx[9];
  real_T c_a[9];
  real_T yy[9];
  real_T dv[6];
  real_T y[3];
  real_T zEstimated[3];
  const real_T *jpda_data;
  const real_T *z_data;
  real_T x;
  real_T *b_jpda_data;
  int32_T b_iv[2];
  int32_T b_i;
  int32_T i;
  int32_T i1;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  wrapping[0U] = rtMinusInf;
  wrapping[1U] = rtMinusInf;
  wrapping[2U] = rtMinusInf;
  wrapping[3U] = rtInf;
  wrapping[4U] = rtInf;
  wrapping[5U] = rtInf;
  jpda_data = jpda->data;
  z_data = z->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &dmb_emlrtRSI;
  b_st.site = &jmb_emlrtRSI;
  c_st.site = &jc_emlrtRSI;
  p = true;
  i = 3 * z->size[1];
  b_i = 0;
  exitg1 = false;
  while ((!exitg1) && (b_i <= i - 1)) {
    if ((!muDoubleScalarIsInf(z_data[b_i])) &&
        (!muDoubleScalarIsNaN(z_data[b_i]))) {
      b_i++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &h_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:correctjpda:expectedFinite", 3, 4, 1, "z");
  }
  if (z->size[1] < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, z->size[1], &hh_emlrtBCI, &st);
  }
  b_st.site = &kmb_emlrtRSI;
  validateInputSizeAndType(&b_st, &z_data[0]);
  if (z->size[1] < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, z->size[1], &ih_emlrtBCI, &st);
  }
  b_st.site = &lmb_emlrtRSI;
  c_ExtendedKalmanFilter_validate(&b_st, filter);
  b_st.site = &mmb_emlrtRSI;
  c_st.site = &jc_emlrtRSI;
  p = true;
  b_i = 0;
  exitg1 = false;
  while ((!exitg1) && (b_i <= jpda->size[0] - 1)) {
    if ((!muDoubleScalarIsInf(jpda_data[b_i])) &&
        (!muDoubleScalarIsNaN(jpda_data[b_i]))) {
      b_i++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &h_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:correctjpda:expectedFinite", 3, 4, 4, "jpda");
  }
  c_st.site = &jc_emlrtRSI;
  p = true;
  b_i = 0;
  exitg1 = false;
  while ((!exitg1) && (b_i <= jpda->size[0] - 1)) {
    if (!(jpda_data[b_i] < 0.0)) {
      b_i++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &ib_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonnegative",
        "MATLAB:correctjpda:expectedNonnegative", 3, 4, 4, "jpda");
  }
  c_st.site = &jc_emlrtRSI;
  if (jpda->size[0] != z->size[1] + 1) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &cd_emlrtRTEI, "Coder:toolbox:ValidateattributesincorrectNumel",
        "MATLAB:correctjpda:incorrectNumel", 5, 4, 4, "jpda", 12,
        z->size[1] + 1);
  }
  c_st.site = &jc_emlrtRSI;
  p = true;
  b_i = 0;
  exitg1 = false;
  while ((!exitg1) && (b_i <= jpda->size[0] - 1)) {
    if (jpda_data[b_i] <= 1.0) {
      b_i++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&c_st, &dd_emlrtRTEI,
                                  "MATLAB:validateattributes:expectedArray",
                                  "MATLAB:correctjpda:notLessEqual", 9, 4, 4,
                                  "jpda", 4, 2, "<=", 4, 1, "1");
  }
  b_st.site = &nmb_emlrtRSI;
  x = b_sum(&b_st, jpda) - 1.0;
  b_st.site = &nmb_emlrtRSI;
  if (muDoubleScalarAbs(x) > 1.4901161193847656E-8) {
    emlrtErrorWithMessageIdR2018a(
        &st, &bd_emlrtRTEI,
        "shared_tracking:ExtendedKalmanFilter:InvalidJPDAInput",
        "shared_tracking:ExtendedKalmanFilter:InvalidJPDAInput", 3, 4, 4,
        "jpda");
  }
  st.site = &emb_emlrtRSI;
  memcpy(&yy[0], &filter->pSqrtMeasurementNoise[0], 9U * sizeof(real_T));
  memcpy(&a[0], &filter->pSqrtMeasurementNoise[0], 9U * sizeof(real_T));
  st.site = &fmb_emlrtRSI;
  memcpy(&b_value[0], &filter->pSqrtStateCovariance[0], 36U * sizeof(real_T));
  memcpy(&b_a[0], &filter->pSqrtStateCovariance[0], 36U * sizeof(real_T));
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      x = 0.0;
      for (b_i = 0; b_i < 6; b_i++) {
        x += b_a[i + 6 * b_i] * b_value[i1 + 6 * b_i];
      }
      P[i + 6 * i1] = x;
    }
  }
  st.site = &gmb_emlrtRSI;
  for (b_i = 0; b_i < 6; b_i++) {
    dv[b_i] = filter->pState[b_i];
  }
  b_st.site = &qmb_emlrtRSI;
  c_st.site = &pmb_emlrtRSI;
  cvmeasjac(&c_st, dv, dHdx);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 3; i1++) {
      x = 0.0;
      for (b_i = 0; b_i < 6; b_i++) {
        x += P[i + 6 * b_i] * dHdx[i1 + 3 * b_i];
      }
      Pxy[i + 6 * i1] = x;
    }
  }
  for (i = 0; i < 3; i++) {
    for (i1 = 0; i1 < 3; i1++) {
      x = 0.0;
      for (b_i = 0; b_i < 6; b_i++) {
        x += dHdx[i + 3 * b_i] * Pxy[b_i + 6 * i1];
      }
      b_i = i + 3 * i1;
      b_dHdx[b_i] = x;
      c_a[b_i] =
          (a[i] * yy[i1] + a[i + 3] * yy[i1 + 3]) + a[i + 6] * yy[i1 + 6];
    }
  }
  r = _mm_loadu_pd(&b_dHdx[0]);
  r1 = _mm_loadu_pd(&c_a[0]);
  _mm_storeu_pd(&b_dHdx[0], _mm_add_pd(r, r1));
  r = _mm_loadu_pd(&b_dHdx[2]);
  r1 = _mm_loadu_pd(&c_a[2]);
  _mm_storeu_pd(&b_dHdx[2], _mm_add_pd(r, r1));
  r = _mm_loadu_pd(&b_dHdx[4]);
  r1 = _mm_loadu_pd(&c_a[4]);
  _mm_storeu_pd(&b_dHdx[4], _mm_add_pd(r, r1));
  r = _mm_loadu_pd(&b_dHdx[6]);
  r1 = _mm_loadu_pd(&c_a[6]);
  _mm_storeu_pd(&b_dHdx[6], _mm_add_pd(r, r1));
  b_dHdx[8] += c_a[8];
  c_st.site = &omb_emlrtRSI;
  cvmeas(&c_st, dv, zEstimated);
  if (jpda->size[0] - 1 < 1) {
    b_i = 0;
  } else {
    if (jpda->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, jpda->size[0], &jh_emlrtBCI, &st);
    }
    if ((jpda->size[0] - 1 < 1) || (jpda->size[0] - 1 > jpda->size[0])) {
      emlrtDynamicBoundsCheckR2012b(jpda->size[0] - 1, 1, jpda->size[0],
                                    &kh_emlrtBCI, &st);
    }
    b_i = jpda->size[0] - 1;
  }
  b_iv[0] = 1;
  b_iv[1] = b_i;
  b_st.site = &rmb_emlrtRSI;
  indexShapeCheck(&b_st, jpda->size[0], b_iv);
  if (jpda->size[0] < 1) {
    emlrtDynamicBoundsCheckR2012b(jpda->size[0], 1, jpda->size[0], &lh_emlrtBCI,
                                  &st);
  }
  emxInit_real_T(&st, &b_jpda, 1, &an_emlrtRTEI, true);
  i = b_jpda->size[0];
  b_jpda->size[0] = b_i;
  emxEnsureCapacity_real_T(&st, b_jpda, i, &an_emlrtRTEI);
  b_jpda_data = b_jpda->data;
  for (i = 0; i < b_i; i++) {
    b_jpda_data[i] = jpda_data[i];
  }
  b_st.site = &smb_emlrtRSI;
  c_jpdaWeightInnovationAndCovari(&b_st, z, zEstimated, b_jpda, wrapping, y,
                                  yy);
  emxFree_real_T(&st, &b_jpda);
  b_st.site = &tmb_emlrtRSI;
  c_EKFCorrector_correctStateAndC(&b_st, dv, P, y, Pxy, b_dHdx, dHdx, gain);
  for (b_i = 0; b_i < 6; b_i++) {
    filter->pState[b_i] = dv[b_i];
  }
  __m128d r2;
  __m128d r3;
  __m128d r4;
  st.site = &gmb_emlrtRSI;
  b_st.site = &su_emlrtRSI;
  x = jpda_data[jpda->size[0] - 1];
  r = _mm_loadu_pd(&y[0]);
  r1 = _mm_loadu_pd(&b_dHdx[0]);
  r2 = _mm_loadu_pd(&yy[0]);
  r3 = _mm_set1_pd(x);
  r4 = _mm_set1_pd(0.0);
  _mm_storeu_pd(&a[0],
                _mm_sub_pd(_mm_add_pd(_mm_mul_pd(r3, r1), r2),
                           _mm_add_pd(r4, _mm_mul_pd(r, _mm_set1_pd(y[0])))));
  a[2] = (x * b_dHdx[2] + yy[2]) - y[0] * y[2];
  r = _mm_loadu_pd(&y[0]);
  r1 = _mm_loadu_pd(&b_dHdx[3]);
  r2 = _mm_loadu_pd(&yy[3]);
  _mm_storeu_pd(&a[3],
                _mm_sub_pd(_mm_add_pd(_mm_mul_pd(r3, r1), r2),
                           _mm_add_pd(r4, _mm_mul_pd(r, _mm_set1_pd(y[1])))));
  a[5] = (x * b_dHdx[5] + yy[5]) - y[1] * y[2];
  r = _mm_loadu_pd(&y[0]);
  r1 = _mm_loadu_pd(&b_dHdx[6]);
  r2 = _mm_loadu_pd(&yy[6]);
  _mm_storeu_pd(&a[6],
                _mm_sub_pd(_mm_add_pd(_mm_mul_pd(r3, r1), r2),
                           _mm_add_pd(r4, _mm_mul_pd(r, _mm_set1_pd(y[2])))));
  a[8] = (x * b_dHdx[8] + yy[8]) - y[2] * y[2];
  for (i = 0; i < 6; i++) {
    real_T d;
    real_T d1;
    x = gain[i];
    d = gain[i + 6];
    d1 = gain[i + 12];
    for (i1 = 0; i1 < 3; i1++) {
      Pxy[i + 6 * i1] =
          (x * a[3 * i1] + d * a[3 * i1 + 1]) + d1 * a[3 * i1 + 2];
    }
    x = Pxy[i];
    d = Pxy[i + 6];
    d1 = Pxy[i + 12];
    for (i1 = 0; i1 < 6; i1++) {
      b_i = i + 6 * i1;
      b_a[b_i] =
          P[b_i] + ((x * gain[i1] + d * gain[i1 + 6]) + d1 * gain[i1 + 12]);
    }
  }
  c_st.site = &su_emlrtRSI;
  cholPSD(&c_st, b_a, b_value);
  memcpy(&filter->pSqrtStateCovariance[0], &b_value[0], 36U * sizeof(real_T));
  filter->pIsSetStateCovariance = true;
  filter->pSqrtStateCovarianceScalar = -1.0;
  filter->pHasPrediction = false;
  st.site = &hmb_emlrtRSI;
  if (!filter->pIsInitialized) {
    filter->pIsDistributionsSetup = true;
  }
  st.site = &imb_emlrtRSI;
  filter->pWasRetrodicted = false;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void trackingEKF_models_anonFcn1(const emlrtStack *sp,
                                 const real_T state_data[],
                                 const int32_T state_size[2], real_T dt,
                                 real_T varargout_1_data[],
                                 int32_T varargout_1_size[2])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T b_tmp_data[30];
  real_T tmp_data[30];
  real_T a;
  int32_T b_iv[2];
  int32_T b_tmp_size[2];
  int32_T tmp_size[2];
  int32_T acoef;
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T d_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T k;
  int32_T loop_ub;
  int8_T varargin_1[2];
  int8_T varargin_2[2];
  int8_T csz_idx_1_tmp;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ybb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  varargout_1_size[0] = 6;
  varargout_1_size[1] = state_size[1];
  acoef = 6 * state_size[1];
  if (acoef - 1 >= 0) {
    memcpy(&varargout_1_data[0], &state_data[0],
           (uint32_T)acoef * sizeof(real_T));
  }
  b_st.site = &acb_emlrtRSI;
  c_st.site = &jc_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= acoef - 1)) {
    if ((!muDoubleScalarIsInf(state_data[k])) &&
        (!muDoubleScalarIsNaN(state_data[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &h_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:constvel:expectedFinite", 3, 4, 22, "input number 1, state,");
  }
  varargin_1[0] = 3;
  varargin_1[1] = (int8_T)state_size[1];
  varargin_2[0] = 3;
  varargin_2[1] = (int8_T)state_size[1];
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (varargin_1[k] != varargin_2[k]) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&st, &sc_emlrtRTEI,
                                  "shared_tracking:motion:incorrectNoiseDim",
                                  "shared_tracking:motion:incorrectNoiseDim", 7,
                                  4, 1, "w", 12, 3, 12, state_size[1]);
  }
  b_st.site = &bcb_emlrtRSI;
  c_st.site = &jc_emlrtRSI;
  if (muDoubleScalarIsInf(dt) || muDoubleScalarIsNaN(dt)) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &h_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:constvel:expectedFinite", 3, 4, 19, "input number 3, dt,");
  }
  a = 0.5 * (dt * dt);
  csz_idx_1_tmp = (int8_T)state_size[1];
  loop_ub = varargout_1_size[1];
  tmp_size[0] = 1;
  tmp_size[1] = state_size[1];
  if (csz_idx_1_tmp != 0) {
    i = csz_idx_1_tmp - 1;
    for (k = 0; k <= i; k++) {
      tmp_data[k] = a * 0.0;
    }
  }
  b_loop_ub = varargout_1_size[1];
  c_loop_ub = varargout_1_size[1];
  d_loop_ub = varargout_1_size[1];
  for (b_i = 0; b_i < 3; b_i++) {
    i = (b_i + 1) << 1;
    if (varargout_1_size[1] != 0) {
      acoef = (varargout_1_size[1] != 1);
      i1 = varargout_1_size[1] - 1;
      for (k = 0; k <= i1; k++) {
        b_tmp_data[k] = varargout_1_data[(i + 6 * (acoef * k)) - 1] * dt;
      }
    }
    b_tmp_size[0] = 1;
    b_tmp_size[1] = varargout_1_size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_tmp_data[i1] += varargout_1_data[(i + 6 * i1) - 2];
    }
    b_st.site = &ccb_emlrtRSI;
    if ((b_tmp_size[1] != state_size[1]) &&
        ((b_tmp_size[1] != 1) && (state_size[1] != 1))) {
      emlrtDimSizeImpxCheckR2021b(b_tmp_size[1], state_size[1], &q_emlrtECI,
                                  &st);
    }
    if (b_tmp_size[1] == state_size[1]) {
      int32_T vectorUB;
      acoef = b_tmp_size[1] - 1;
      b_tmp_size[0] = 1;
      k = (b_tmp_size[1] / 2) << 1;
      vectorUB = k - 2;
      for (i1 = 0; i1 <= vectorUB; i1 += 2) {
        __m128d r;
        __m128d r1;
        r = _mm_loadu_pd(&b_tmp_data[i1]);
        r1 = _mm_loadu_pd(&tmp_data[i1]);
        _mm_storeu_pd(&b_tmp_data[i1], _mm_add_pd(r, r1));
      }
      for (i1 = k; i1 <= acoef; i1++) {
        b_tmp_data[i1] += tmp_data[i1];
      }
    } else {
      plus(b_tmp_data, b_tmp_size, tmp_data, tmp_size);
    }
    b_iv[0] = 1;
    b_iv[1] = varargout_1_size[1];
    emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &b_tmp_size[0], 2, &r_emlrtECI,
                                  &st);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      varargout_1_data[(i + 6 * i1) - 2] = b_tmp_data[i1];
    }
    b_tmp_size[0] = 1;
    b_tmp_size[1] = state_size[1];
    if (csz_idx_1_tmp != 0) {
      i1 = csz_idx_1_tmp - 1;
      for (k = 0; k <= i1; k++) {
        b_tmp_data[k] = 0.0 * dt;
      }
    }
    if ((varargout_1_size[1] != state_size[1]) &&
        ((varargout_1_size[1] != 1) && (state_size[1] != 1))) {
      emlrtDimSizeImpxCheckR2021b(varargout_1_size[1], state_size[1],
                                  &s_emlrtECI, &st);
    }
    if (varargout_1_size[1] == state_size[1]) {
      b_tmp_size[0] = 1;
      b_tmp_size[1] = varargout_1_size[1];
      for (i1 = 0; i1 < c_loop_ub; i1++) {
        b_tmp_data[i1] += varargout_1_data[(i + 6 * i1) - 1];
      }
    } else {
      binary_expand_op(b_tmp_data, b_tmp_size, varargout_1_data,
                       varargout_1_size, b_i + 1);
    }
    b_iv[0] = 1;
    b_iv[1] = varargout_1_size[1];
    emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &b_tmp_size[0], 2, &t_emlrtECI,
                                  &st);
    for (i1 = 0; i1 < d_loop_ub; i1++) {
      varargout_1_data[(i + 6 * i1) - 1] = b_tmp_data[i1];
    }
  }
}

void trackingEKF_nullify(const emlrtStack *sp, trackingEKF *EKF)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T b_I[36];
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &qu_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  for (i = 0; i < 6; i++) {
    EKF->pState[i] = 0.0;
  }
  st.site = &ru_emlrtRSI;
  memset(&b_I[0], 0, 36U * sizeof(real_T));
  for (i = 0; i < 6; i++) {
    b_I[i + 6 * i] = 1.0;
  }
  st.site = &ru_emlrtRSI;
  b_st.site = &su_emlrtRSI;
  c_st.site = &su_emlrtRSI;
  cholPSD(&c_st, b_I, EKF->pSqrtStateCovariance);
  EKF->pIsSetStateCovariance = true;
  EKF->pSqrtStateCovarianceScalar = -1.0;
}

void trackingEKF_residual(const emlrtStack *sp, trackingEKF *EKF,
                          const real_T z[3], real_T res[3], real_T S[9])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
  emlrtStack k_st;
  emlrtStack l_st;
  emlrtStack st;
  real_T M[27];
  real_T dHdx[18];
  real_T y[18];
  real_T R[9];
  real_T Sy[9];
  real_T tau[3];
  real_T work[3];
  real_T d;
  real_T s;
  int32_T aoffset;
  int32_T coffset;
  int32_T i;
  int32_T ii;
  int32_T j;
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &vjb_emlrtRSI;
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
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  k_st.prev = &j_st;
  k_st.tls = j_st.tls;
  l_st.prev = &k_st;
  l_st.tls = k_st.tls;
  b_st.site = &wjb_emlrtRSI;
  c_st.site = &akb_emlrtRSI;
  d_st.site = &jc_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 3)) {
    if ((!muDoubleScalarIsInf(z[k])) && (!muDoubleScalarIsNaN(z[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &h_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:residual:expectedFinite", 3, 4, 1, "z");
  }
  b_st.site = &xjb_emlrtRSI;
  c_ExtendedKalmanFilter_validate(&b_st, EKF);
  b_st.site = &yjb_emlrtRSI;
  c_st.site = &bkb_emlrtRSI;
  d_st.site = &ekb_emlrtRSI;
  e_st.site = &fkb_emlrtRSI;
  cvmeasjac(&e_st, EKF->pState, dHdx);
  d_st.site = &dkb_emlrtRSI;
  cvmeas(&d_st, EKF->pState, res);
  d_st.site = &ckb_emlrtRSI;
  e_st.site = &ydb_emlrtRSI;
  f_st.site = &ef_emlrtRSI;
  g_st.site = &beb_emlrtRSI;
  h_st.site = &gf_emlrtRSI;
  for (j = 0; j < 3; j++) {
    coffset = j * 6;
    for (i = 0; i < 6; i++) {
      aoffset = i * 6;
      s = 0.0;
      i_st.site = &ceb_emlrtRSI;
      for (k = 0; k < 6; k++) {
        s += EKF->pSqrtStateCovariance[aoffset + k] * dHdx[k * 3 + j];
      }
      y[coffset + i] = s;
    }
  }
  for (aoffset = 0; aoffset < 3; aoffset++) {
    for (coffset = 0; coffset < 6; coffset++) {
      M[coffset + 9 * aoffset] = y[coffset + 6 * aoffset];
    }
    M[9 * aoffset + 6] = EKF->pSqrtMeasurementNoise[aoffset];
    M[9 * aoffset + 7] = EKF->pSqrtMeasurementNoise[aoffset + 3];
    M[9 * aoffset + 8] = EKF->pSqrtMeasurementNoise[aoffset + 6];
  }
  e_st.site = &aeb_emlrtRSI;
  f_st.site = &deb_emlrtRSI;
  g_st.site = &eeb_emlrtRSI;
  h_st.site = &feb_emlrtRSI;
  i_st.site = &ieb_emlrtRSI;
  j_st.site = &jeb_emlrtRSI;
  work[0] = 0.0;
  work[1] = 0.0;
  work[2] = 0.0;
  k_st.site = &meb_emlrtRSI;
  for (i = 0; i < 3; i++) {
    real_T atmp;
    ii = i * 9 + i;
    atmp = M[ii];
    k_st.site = &leb_emlrtRSI;
    tau[i] = 0.0;
    l_st.site = &gm_emlrtRSI;
    s = g_xnrm2(&l_st, 8 - i, M, ii + 2);
    if (s != 0.0) {
      d = M[ii];
      s = muDoubleScalarHypot(d, s);
      if (d >= 0.0) {
        s = -s;
      }
      if (muDoubleScalarAbs(s) < 1.0020841800044864E-292) {
        coffset = 0;
        do {
          coffset++;
          l_st.site = &fm_emlrtRSI;
          j_xscal(&l_st, 8 - i, 9.9792015476736E+291, M, ii + 2);
          s *= 9.9792015476736E+291;
          atmp *= 9.9792015476736E+291;
        } while ((muDoubleScalarAbs(s) < 1.0020841800044864E-292) &&
                 (coffset < 20));
        l_st.site = &em_emlrtRSI;
        s = g_xnrm2(&l_st, 8 - i, M, ii + 2);
        s = muDoubleScalarHypot(atmp, s);
        if (atmp >= 0.0) {
          s = -s;
        }
        tau[i] = (s - atmp) / s;
        l_st.site = &dm_emlrtRSI;
        j_xscal(&l_st, 8 - i, 1.0 / (atmp - s), M, ii + 2);
        for (k = 0; k < coffset; k++) {
          s *= 1.0020841800044864E-292;
        }
        atmp = s;
      } else {
        tau[i] = (s - d) / s;
        l_st.site = &bm_emlrtRSI;
        j_xscal(&l_st, 8 - i, 1.0 / (M[ii] - s), M, ii + 2);
        atmp = s;
      }
    }
    M[ii] = atmp;
    if (i + 1 < 3) {
      M[ii] = 1.0;
      k_st.site = &keb_emlrtRSI;
      if (tau[i] != 0.0) {
        aoffset = 9 - i;
        coffset = (ii - i) + 8;
        while ((aoffset > 0) && (M[coffset] == 0.0)) {
          aoffset--;
          coffset--;
        }
        l_st.site = &dn_emlrtRSI;
        coffset = b_ilazlc(&l_st, aoffset, 2 - i, M, ii + 10);
      } else {
        aoffset = 0;
        coffset = 0;
      }
      if (aoffset > 0) {
        l_st.site = &cn_emlrtRSI;
        c_xgemv(&l_st, aoffset, coffset, M, ii + 10, M, ii + 1, work);
        l_st.site = &bn_emlrtRSI;
        c_xgerc(&l_st, aoffset, coffset, -tau[i], ii + 1, work, M, ii + 10);
      }
      M[ii] = atmp;
    }
  }
  for (j = 0; j < 3; j++) {
    h_st.site = &geb_emlrtRSI;
    for (i = 0; i <= j; i++) {
      R[i + 3 * j] = M[i + 9 * j];
    }
    aoffset = j + 2;
    if (aoffset <= 3) {
      memset(&R[(j * 3 + aoffset) + -1], 0,
             (uint32_T)(-aoffset + 4) * sizeof(real_T));
    }
  }
  h_st.site = &heb_emlrtRSI;
  i_st.site = &neb_emlrtRSI;
  j_st.site = &oeb_emlrtRSI;
  k_st.site = &seb_emlrtRSI;
  work[0] = 0.0;
  work[1] = 0.0;
  work[2] = 0.0;
  for (i = 2; i >= 0; i--) {
    ii = i + i * 9;
    if (i + 1 < 3) {
      M[ii] = 1.0;
      k_st.site = &reb_emlrtRSI;
      if (tau[i] != 0.0) {
        aoffset = 9 - i;
        coffset = ii - i;
        while ((aoffset > 0) && (M[coffset + 8] == 0.0)) {
          aoffset--;
          coffset--;
        }
        l_st.site = &dn_emlrtRSI;
        coffset = b_ilazlc(&l_st, aoffset, 2 - i, M, ii + 10);
      } else {
        aoffset = 0;
        coffset = 0;
      }
      if (aoffset > 0) {
        l_st.site = &cn_emlrtRSI;
        c_xgemv(&l_st, aoffset, coffset, M, ii + 10, M, ii + 1, work);
        l_st.site = &bn_emlrtRSI;
        c_xgerc(&l_st, aoffset, coffset, -tau[i], ii + 1, work, M, ii + 10);
      }
    }
    d = tau[i];
    k_st.site = &qeb_emlrtRSI;
    j_xscal(&k_st, 8 - i, -d, M, ii + 2);
    M[ii] = 1.0 - d;
    k_st.site = &peb_emlrtRSI;
    for (j = 0; j < i; j++) {
      M[(ii - j) - 1] = 0.0;
    }
  }
  for (aoffset = 0; aoffset < 3; aoffset++) {
    Sy[3 * aoffset] = R[aoffset];
    Sy[3 * aoffset + 1] = R[aoffset + 3];
    Sy[3 * aoffset + 2] = R[aoffset + 6];
  }
  for (aoffset = 0; aoffset < 3; aoffset++) {
    res[aoffset] = z[aoffset] - res[aoffset];
    for (coffset = 0; coffset < 3; coffset++) {
      S[aoffset + 3 * coffset] =
          (Sy[aoffset] * Sy[coffset] + Sy[aoffset + 3] * Sy[coffset + 3]) +
          Sy[aoffset + 6] * Sy[coffset + 6];
    }
  }
}

void trackingEKF_sync(const emlrtStack *sp, trackingEKF *EKF, trackingEKF *EKF2)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T b_a[36];
  real_T c_a[36];
  real_T c_value[36];
  real_T d_a[9];
  real_T d_value[9];
  real_T e_a[9];
  real_T b_value[6];
  real_T a;
  real_T d;
  real_T d1;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  st.site = &cv_emlrtRSI;
  for (i = 0; i < 6; i++) {
    b_value[i] = EKF2->pState[i];
  }
  for (i = 0; i < 6; i++) {
    EKF->pState[i] = b_value[i];
  }
  st.site = &dv_emlrtRSI;
  b_st.site = &hv_emlrtRSI;
  if ((!EKF2->pIsSetStateCovariance) ||
      (EKF2->pSqrtStateCovarianceScalar != -1.0)) {
    a = EKF2->pSqrtStateCovarianceScalar;
    for (i = 0; i < 36; i++) {
      EKF2->pSqrtStateCovariance[i] = a * (real_T)iv2[i];
    }
    EKF2->pIsSetStateCovariance = true;
    EKF2->pSqrtStateCovarianceScalar = -1.0;
  }
  b_st.site = &iv_emlrtRSI;
  for (i = 0; i < 36; i++) {
    c_value[i] = EKF2->pSqrtStateCovariance[i];
  }
  for (i = 0; i < 36; i++) {
    b_a[i] = EKF2->pSqrtStateCovariance[i];
  }
  st.site = &dv_emlrtRSI;
  b_st.site = &su_emlrtRSI;
  for (i = 0; i < 6; i++) {
    for (b_i = 0; b_i < 6; b_i++) {
      a = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        a += b_a[i + 6 * i1] * c_value[b_i + 6 * i1];
      }
      c_a[i + 6 * b_i] = a;
    }
  }
  c_st.site = &su_emlrtRSI;
  cholPSD(&c_st, c_a, c_value);
  for (i = 0; i < 36; i++) {
    EKF->pSqrtStateCovariance[i] = c_value[i];
  }
  EKF->pIsSetStateCovariance = true;
  EKF->pSqrtStateCovarianceScalar = -1.0;
  st.site = &ev_emlrtRSI;
  b_st.site = &kv_emlrtRSI;
  if ((!EKF2->pIsSetMeasurementNoise) ||
      (EKF2->pSqrtMeasurementNoiseScalar != -1.0)) {
    a = EKF2->pSqrtMeasurementNoiseScalar;
    for (i = 0; i < 9; i++) {
      EKF2->pSqrtMeasurementNoise[i] = a * (real_T)iv1[i];
    }
    EKF2->pIsSetMeasurementNoise = true;
    EKF2->pSqrtMeasurementNoiseScalar = -1.0;
  }
  b_st.site = &lv_emlrtRSI;
  for (i = 0; i < 9; i++) {
    d_value[i] = EKF2->pSqrtMeasurementNoise[i];
  }
  for (i = 0; i < 9; i++) {
    d_a[i] = EKF2->pSqrtMeasurementNoise[i];
  }
  st.site = &ev_emlrtRSI;
  b_st.site = &nv_emlrtRSI;
  for (i = 0; i < 3; i++) {
    a = d_a[i];
    d = d_a[i + 3];
    d1 = d_a[i + 6];
    for (b_i = 0; b_i < 3; b_i++) {
      e_a[i + 3 * b_i] =
          (a * d_value[b_i] + d * d_value[b_i + 3]) + d1 * d_value[b_i + 6];
    }
  }
  c_st.site = &nv_emlrtRSI;
  b_cholPSD(&c_st, e_a, d_value);
  for (i = 0; i < 9; i++) {
    EKF->pSqrtMeasurementNoise[i] = d_value[i];
  }
  EKF->pIsSetMeasurementNoise = true;
  EKF->pSqrtMeasurementNoiseScalar = -1.0;
  st.site = &fv_emlrtRSI;
  b_st.site = &ov_emlrtRSI;
  if ((!EKF2->pIsSetProcessNoise) || (EKF2->pSqrtProcessNoiseScalar != -1.0)) {
    a = EKF2->pSqrtProcessNoiseScalar;
    for (i = 0; i < 9; i++) {
      EKF2->pSqrtProcessNoise[i] = a * (real_T)iv1[i];
    }
    EKF2->pIsSetProcessNoise = true;
    EKF2->pSqrtProcessNoiseScalar = -1.0;
  }
  b_st.site = &pv_emlrtRSI;
  for (i = 0; i < 9; i++) {
    d_value[i] = EKF2->pSqrtProcessNoise[i];
  }
  for (i = 0; i < 9; i++) {
    d_a[i] = EKF2->pSqrtProcessNoise[i];
  }
  st.site = &fv_emlrtRSI;
  b_st.site = &rv_emlrtRSI;
  for (i = 0; i < 3; i++) {
    a = d_a[i];
    d = d_a[i + 3];
    d1 = d_a[i + 6];
    for (b_i = 0; b_i < 3; b_i++) {
      e_a[i + 3 * b_i] =
          (a * d_value[b_i] + d * d_value[b_i + 3]) + d1 * d_value[b_i + 6];
    }
  }
  c_st.site = &rv_emlrtRSI;
  b_cholPSD(&c_st, e_a, d_value);
  for (i = 0; i < 9; i++) {
    EKF->pSqrtProcessNoise[i] = d_value[i];
  }
  EKF->pIsSetProcessNoise = true;
  EKF->pSqrtProcessNoiseScalar = -1.0;
  EKF->pIsFirstCallCorrect = EKF2->pIsFirstCallCorrect;
  EKF->pIsFirstCallPredict = EKF2->pIsFirstCallPredict;
  st.site = &gv_emlrtRSI;
  b_st.site = &ju_emlrtRSI;
  EKF->pWasRetrodicted = EKF2->pWasRetrodicted;
}

/* End of code generation (trackingEKF.c) */
