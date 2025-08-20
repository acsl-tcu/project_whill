/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ExtendedKalmanFilter.c
 *
 * Code generation for function 'ExtendedKalmanFilter'
 *
 */

/* Include files */
#include "ExtendedKalmanFilter.h"
#include "cholPSD.h"
#include "cvmeas.h"
#include "cvmeasjac.h"
#include "eigSkewHermitianStandard.h"
#include "eml_int_forloop_overflow_check.h"
#include "isSymmetricPositiveSemiDefinite.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_types.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <math.h>
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo dr_emlrtRSI = {
    999,                                        /* lineNo */
    "ExtendedKalmanFilter/set.StateCovariance", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo er_emlrtRSI = {
    1008,                                       /* lineNo */
    "ExtendedKalmanFilter/set.StateCovariance", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo fr_emlrtRSI = {
    1012,                                       /* lineNo */
    "ExtendedKalmanFilter/set.StateCovariance", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo gr_emlrtRSI = {
    1019,                                       /* lineNo */
    "ExtendedKalmanFilter/set.StateCovariance", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo hr_emlrtRSI = {
    17,                                /* lineNo */
    "isSymmetricPositiveSemiDefinite", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/isSymmetricPositiveSemiDefinite.m" /* pathName
                                                                           */
};

static emlrtRSInfo ir_emlrtRSI =
    {
        42,      /* lineNo */
        "xgeev", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgeev.m" /* pathName */
};

static emlrtRSInfo jr_emlrtRSI =
    {
        159,           /* lineNo */
        "ceval_xgeev", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgeev.m" /* pathName */
};

static emlrtRSInfo ps_emlrtRSI = {
    1110,                                        /* lineNo */
    "ExtendedKalmanFilter/set.MeasurementNoise", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo qs_emlrtRSI = {
    1121,                                        /* lineNo */
    "ExtendedKalmanFilter/set.MeasurementNoise", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo rs_emlrtRSI = {
    1132,                                        /* lineNo */
    "ExtendedKalmanFilter/set.MeasurementNoise", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo ss_emlrtRSI = {
    1139,                                        /* lineNo */
    "ExtendedKalmanFilter/set.MeasurementNoise", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo yeb_emlrtRSI = {
    1960,                                                           /* lineNo */
    "ExtendedKalmanFilter/validateMeasurementAndRelatedProperties", /* fcnName
                                                                     */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo afb_emlrtRSI = {
    1964,                                                           /* lineNo */
    "ExtendedKalmanFilter/validateMeasurementAndRelatedProperties", /* fcnName
                                                                     */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo bfb_emlrtRSI = {
    1970,                                                           /* lineNo */
    "ExtendedKalmanFilter/validateMeasurementAndRelatedProperties", /* fcnName
                                                                     */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo cfb_emlrtRSI = {
    1976,                                                           /* lineNo */
    "ExtendedKalmanFilter/validateMeasurementAndRelatedProperties", /* fcnName
                                                                     */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo dfb_emlrtRSI = {
    1912,                                          /* lineNo */
    "ExtendedKalmanFilter/validateMeasurementFcn", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo efb_emlrtRSI = {
    14,                                            /* lineNo */
    "EKFCorrectorAdditive/validateMeasurementFcn", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/EKFCorrectorAdditive.m" /* pathName */
};

static emlrtRSInfo gfb_emlrtRSI = {
    1938,                                                  /* lineNo */
    "ExtendedKalmanFilter/validateMeasurementJacobianFcn", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo hfb_emlrtRSI = {
    1940,                                                  /* lineNo */
    "ExtendedKalmanFilter/validateMeasurementJacobianFcn", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

static emlrtRSInfo ifb_emlrtRSI = {
    22,                                                    /* lineNo */
    "EKFCorrectorAdditive/validateMeasurementJacobianFcn", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/EKFCorrectorAdditive.m" /* pathName */
};

static emlrtRSInfo mfb_emlrtRSI = {
    1991,                                                   /* lineNo */
    "ExtendedKalmanFilter/ensureMeasurementNoiseIsDefined", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/ExtendedKalmanFilter.m" /* pathName */
};

/* Function Definitions */
trackingEKF *ExtendedKalmanFilter_clone(const trackingEKF *EKF,
                                        trackingEKF *iobj_0)
{
  trackingEKF *newEKF;
  real_T b_value[36];
  real_T c_value[9];
  real_T b_EKF[6];
  int32_T i;
  iobj_0->pIsFirstCallPredict = true;
  iobj_0->pIsFirstCallCorrect = true;
  iobj_0->pSqrtStateCovarianceScalar = 1.0;
  iobj_0->pIsValidMeasurementFcn = false;
  iobj_0->pIsValidStateTransitionFcn = false;
  iobj_0->pSqrtProcessNoiseScalar = 1.0;
  iobj_0->pSqrtMeasurementNoiseScalar = 1.0;
  iobj_0->pHasPrediction = false;
  iobj_0->pWasRetrodicted = false;
  iobj_0->IsLastJacobianInitialized = false;
  iobj_0->pIsDistributionsSetup = false;
  iobj_0->pIsInitialized = false;
  newEKF = iobj_0;
  iobj_0->pIsSetStateCovariance = EKF->pIsSetStateCovariance;
  iobj_0->pIsSetProcessNoise = EKF->pIsSetProcessNoise;
  iobj_0->pIsSetMeasurementNoise = EKF->pIsSetMeasurementNoise;
  for (i = 0; i < 6; i++) {
    b_EKF[i] = EKF->pState[i];
  }
  for (i = 0; i < 6; i++) {
    iobj_0->pState[i] = b_EKF[i];
  }
  iobj_0->pIsValidStateTransitionFcn = false;
  iobj_0->pIsValidMeasurementFcn = false;
  for (i = 0; i < 36; i++) {
    b_value[i] = EKF->pSqrtStateCovariance[i];
  }
  for (i = 0; i < 36; i++) {
    iobj_0->pSqrtStateCovariance[i] = b_value[i];
  }
  iobj_0->pIsSetStateCovariance = true;
  iobj_0->pSqrtStateCovarianceScalar = -1.0;
  iobj_0->pSqrtStateCovarianceScalar = EKF->pSqrtStateCovarianceScalar;
  for (i = 0; i < 9; i++) {
    c_value[i] = EKF->pSqrtProcessNoise[i];
  }
  for (i = 0; i < 9; i++) {
    iobj_0->pSqrtProcessNoise[i] = c_value[i];
  }
  iobj_0->pIsSetProcessNoise = true;
  iobj_0->pSqrtProcessNoiseScalar = -1.0;
  iobj_0->pSqrtProcessNoiseScalar = EKF->pSqrtProcessNoiseScalar;
  for (i = 0; i < 9; i++) {
    c_value[i] = EKF->pSqrtMeasurementNoise[i];
  }
  for (i = 0; i < 9; i++) {
    iobj_0->pSqrtMeasurementNoise[i] = c_value[i];
  }
  iobj_0->pIsSetMeasurementNoise = true;
  iobj_0->pSqrtMeasurementNoiseScalar = -1.0;
  iobj_0->pSqrtMeasurementNoiseScalar = EKF->pSqrtMeasurementNoiseScalar;
  iobj_0->pHasPrediction = EKF->pHasPrediction;
  iobj_0->pIsValidStateTransitionFcn = EKF->pIsValidStateTransitionFcn;
  iobj_0->pIsValidMeasurementFcn = EKF->pIsValidMeasurementFcn;
  return newEKF;
}

void c_ExtendedKalmanFilter_set_Meas(const emlrtStack *sp, trackingEKF *obj,
                                     real_T b_value[9])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T c_value[9];
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ps_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &jc_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    if ((!muDoubleScalarIsInf(b_value[k])) &&
        (!muDoubleScalarIsNaN(b_value[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &h_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:ExtendedKalmanFilter:expectedFinite", 3, 4, 16,
        "MeasurementNoise");
  }
  st.site = &qs_emlrtRSI;
  isSymmetricPositiveSemiDefinite(&st, b_value);
  memcpy(&c_value[0], &b_value[0], 9U * sizeof(real_T));
  st.site = &rs_emlrtRSI;
  b_cholPSD(&st, c_value, b_value);
  st.site = &ss_emlrtRSI;
  memcpy(&obj->pSqrtMeasurementNoise[0], &b_value[0], 9U * sizeof(real_T));
  obj->pIsSetMeasurementNoise = true;
  obj->pSqrtMeasurementNoiseScalar = -1.0;
}

void c_ExtendedKalmanFilter_set_Stat(const emlrtStack *sp, trackingEKF *obj,
                                     real_T b_value[36])
{
  static const char_T fname[14] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                   '_', 'd', 'g', 'e', 'e', 'v', 'x'};
  ptrdiff_t ihi_t;
  ptrdiff_t ilo_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  creal_T d[6];
  real_T A[36];
  real_T y[36];
  real_T scale[6];
  real_T wimag[6];
  real_T wreal[6];
  real_T abnrm;
  real_T absx;
  real_T rconde;
  real_T rcondv;
  real_T tol;
  real_T vright;
  int32_T exponent;
  int32_T i;
  int32_T i1;
  int32_T idx;
  boolean_T b_y[6];
  boolean_T c_y;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &dr_emlrtRSI;
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
  b_st.site = &jc_emlrtRSI;
  p = true;
  i1 = 0;
  exitg1 = false;
  while ((!exitg1) && (i1 < 36)) {
    if ((!muDoubleScalarIsInf(b_value[i1])) &&
        (!muDoubleScalarIsNaN(b_value[i1]))) {
      i1++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &h_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:ExtendedKalmanFilter:expectedFinite", 3, 4, 15,
        "StateCovariance");
  }
  st.site = &er_emlrtRSI;
  b_st.site = &hr_emlrtRSI;
  for (i1 = 0; i1 < 6; i1++) {
    wreal[i1] = muDoubleScalarAbs(b_value[i1 + 6 * i1]);
  }
  c_st.site = &lf_emlrtRSI;
  d_st.site = &mf_emlrtRSI;
  e_st.site = &nf_emlrtRSI;
  if (!muDoubleScalarIsNaN(wreal[0])) {
    idx = 1;
  } else {
    idx = 0;
    i1 = 2;
    exitg1 = false;
    while ((!exitg1) && (i1 < 7)) {
      if (!muDoubleScalarIsNaN(wreal[i1 - 1])) {
        idx = i1;
        exitg1 = true;
      } else {
        i1++;
      }
    }
  }
  if (idx == 0) {
    absx = wreal[0];
  } else {
    absx = wreal[idx - 1];
    i = idx + 1;
    for (i1 = i; i1 < 7; i1++) {
      vright = wreal[i1 - 1];
      if (absx < vright) {
        absx = vright;
      }
    }
  }
  if (muDoubleScalarIsInf(absx) || muDoubleScalarIsNaN(absx)) {
    absx = rtNaN;
  } else if (absx < 4.4501477170144028E-308) {
    absx = 4.94065645841247E-324;
  } else {
    frexp(absx, &exponent);
    absx = ldexp(1.0, exponent - 53);
  }
  tol = 100.0 * absx;
  for (i = 0; i < 6; i++) {
    for (idx = 0; idx < 6; idx++) {
      A[idx + 6 * i] = b_value[i + 6 * idx];
    }
  }
  for (i1 = 0; i1 < 36; i1++) {
    y[i1] = muDoubleScalarAbs(b_value[i1] - A[i1]);
  }
  b_st.site = &ml_emlrtRSI;
  absx = muDoubleScalarSqrt(tol);
  b_st.site = &ml_emlrtRSI;
  c_st.site = &ol_emlrtRSI;
  for (i = 0; i < 6; i++) {
    b_y[i] = true;
  }
  idx = 6;
  for (i = 0; i < 6; i++) {
    exponent = idx;
    i1 = idx - 5;
    idx += 6;
    d_st.site = &pl_emlrtRSI;
    if ((i1 <= exponent) && (exponent > 2147483646)) {
      e_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }
    exitg1 = false;
    while ((!exitg1) && (i1 <= exponent)) {
      if (!(y[i1 - 1] < absx)) {
        b_y[i] = false;
        exitg1 = true;
      } else {
        i1++;
      }
    }
  }
  c_y = true;
  i1 = 0;
  exitg1 = false;
  while ((!exitg1) && (i1 <= 5)) {
    if (!b_y[i1]) {
      c_y = false;
      exitg1 = true;
    } else {
      i1++;
    }
  }
  b_st.site = &nl_emlrtRSI;
  for (i = 0; i <= 34; i += 2) {
    __m128d r;
    __m128d r1;
    r = _mm_loadu_pd(&b_value[i]);
    r1 = _mm_loadu_pd(&A[i]);
    _mm_storeu_pd(&A[i], _mm_div_pd(_mm_add_pd(r, r1), _mm_set1_pd(2.0)));
  }
  c_st.site = &ql_emlrtRSI;
  d_st.site = &qc_emlrtRSI;
  e_st.site = &rc_emlrtRSI;
  p = true;
  for (i1 = 0; i1 < 36; i1++) {
    if (p) {
      vright = A[i1];
      if (muDoubleScalarIsInf(vright) || muDoubleScalarIsNaN(vright)) {
        p = false;
      }
    } else {
      p = false;
    }
  }
  if (!p) {
    for (i = 0; i < 6; i++) {
      d[i].re = rtNaN;
      d[i].im = 0.0;
    }
  } else {
    int32_T exitg2;
    p = true;
    idx = 0;
    exitg1 = false;
    while ((!exitg1) && (idx < 6)) {
      i = 0;
      do {
        exitg2 = 0;
        if (i <= idx) {
          if (!(A[i + 6 * idx] == A[idx + 6 * i])) {
            p = false;
            exitg2 = 1;
          } else {
            i++;
          }
        } else {
          idx++;
          exitg2 = 2;
        }
      } while (exitg2 == 0);
      if (exitg2 == 1) {
        exitg1 = true;
      }
    }
    if (p) {
      ptrdiff_t info_t;
      c_st.site = &rl_emlrtRSI;
      d_st.site = &ul_emlrtRSI;
      e_st.site = &wl_emlrtRSI;
      ilo_t = (ptrdiff_t)6;
      info_t = LAPACKE_dsyev(102, 'N', 'L', ilo_t, &A[0], ilo_t, &scale[0]);
      f_st.site = &xl_emlrtRSI;
      if ((int32_T)info_t < 0) {
        if ((int32_T)info_t == -1010) {
          emlrtErrorWithMessageIdR2018a(&f_st, &lb_emlrtRTEI, "MATLAB:nomem",
                                        "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&f_st, &kb_emlrtRTEI,
                                        "Coder:toolbox:LAPACKCallErrorInfo",
                                        "Coder:toolbox:LAPACKCallErrorInfo", 5,
                                        4, 13, &cv[0], 12, (int32_T)info_t);
        }
      }
      for (i = 0; i < 6; i++) {
        d[i].re = scale[i];
        d[i].im = 0.0;
      }
      if ((int32_T)info_t != 0) {
        d_st.site = &vl_emlrtRSI;
        warning(&d_st);
      }
    } else {
      p = true;
      idx = 0;
      exitg1 = false;
      while ((!exitg1) && (idx < 6)) {
        i = 0;
        do {
          exitg2 = 0;
          if (i <= idx) {
            if (!(A[i + 6 * idx] == -A[idx + 6 * i])) {
              p = false;
              exitg2 = 1;
            } else {
              i++;
            }
          } else {
            idx++;
            exitg2 = 2;
          }
        } while (exitg2 == 0);
        if (exitg2 == 1) {
          exitg1 = true;
        }
      }
      if (p) {
        c_st.site = &sl_emlrtRSI;
        eigSkewHermitianStandard(&c_st, A, d);
      } else {
        ptrdiff_t info_t;
        c_st.site = &tl_emlrtRSI;
        d_st.site = &io_emlrtRSI;
        e_st.site = &ir_emlrtRSI;
        info_t = LAPACKE_dgeevx(102, 'B', 'N', 'N', 'N', (ptrdiff_t)6, &A[0],
                                (ptrdiff_t)6, &wreal[0], &wimag[0], &absx,
                                (ptrdiff_t)1, &vright, (ptrdiff_t)1, &ilo_t,
                                &ihi_t, &scale[0], &abnrm, &rconde, &rcondv);
        f_st.site = &jr_emlrtRSI;
        if ((int32_T)info_t < 0) {
          if ((int32_T)info_t == -1010) {
            emlrtErrorWithMessageIdR2018a(&f_st, &lb_emlrtRTEI, "MATLAB:nomem",
                                          "MATLAB:nomem", 0);
          } else {
            emlrtErrorWithMessageIdR2018a(
                &f_st, &kb_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
                "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &fname[0], 12,
                (int32_T)info_t);
          }
        }
        for (i = 0; i < 6; i++) {
          d[i].re = wreal[i];
          d[i].im = wimag[i];
        }
        if ((int32_T)info_t != 0) {
          d_st.site = &jo_emlrtRSI;
          warning(&d_st);
        }
      }
    }
  }
  for (i = 0; i < 6; i++) {
    b_y[i] = (d[i].re < -tol);
  }
  p = false;
  i1 = 0;
  exitg1 = false;
  while ((!exitg1) && (i1 <= 5)) {
    if (b_y[i1]) {
      p = true;
      exitg1 = true;
    } else {
      i1++;
    }
  }
  if (p || (!c_y)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &mb_emlrtRTEI,
        "shared_tracking:KalmanFilter:invalidCovarianceValues",
        "shared_tracking:KalmanFilter:invalidCovarianceValues", 3, 4, 15,
        "StateCovariance");
  }
  memcpy(&A[0], &b_value[0], 36U * sizeof(real_T));
  st.site = &fr_emlrtRSI;
  cholPSD(&st, A, b_value);
  st.site = &gr_emlrtRSI;
  memcpy(&obj->pSqrtStateCovariance[0], &b_value[0], 36U * sizeof(real_T));
  obj->pIsSetStateCovariance = true;
  obj->pSqrtStateCovarianceScalar = -1.0;
}

void c_ExtendedKalmanFilter_validate(const emlrtStack *sp, trackingEKF *obj)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T b_unusedExpr[18];
  real_T unusedExpr[3];
  real_T a;
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &yeb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &cdb_emlrtRSI;
  if ((!obj->pIsSetStateCovariance) ||
      (obj->pSqrtStateCovarianceScalar != -1.0)) {
    a = obj->pSqrtStateCovarianceScalar;
    for (i = 0; i < 36; i++) {
      obj->pSqrtStateCovariance[i] = a * (real_T)iv2[i];
    }
    obj->pIsSetStateCovariance = true;
    obj->pSqrtStateCovarianceScalar = -1.0;
  }
  if (obj->pIsFirstCallCorrect) {
    st.site = &afb_emlrtRSI;
    if (!obj->pIsValidMeasurementFcn) {
      b_st.site = &dfb_emlrtRSI;
      c_st.site = &efb_emlrtRSI;
      cvmeas(&c_st, obj->pState, unusedExpr);
      obj->pIsValidMeasurementFcn = true;
    }
    st.site = &bfb_emlrtRSI;
    b_st.site = &gfb_emlrtRSI;
    c_st.site = &ifb_emlrtRSI;
    cvmeasjac(&c_st, obj->pState, b_unusedExpr);
    b_st.site = &hfb_emlrtRSI;
    obj->pIsFirstCallCorrect = false;
  }
  st.site = &cfb_emlrtRSI;
  b_st.site = &mfb_emlrtRSI;
  if ((!obj->pIsSetMeasurementNoise) ||
      (obj->pSqrtMeasurementNoiseScalar != -1.0)) {
    a = obj->pSqrtMeasurementNoiseScalar;
    for (i = 0; i < 9; i++) {
      obj->pSqrtMeasurementNoise[i] = a * (real_T)iv1[i];
    }
    obj->pIsSetMeasurementNoise = true;
    obj->pSqrtMeasurementNoiseScalar = -1.0;
  }
}

/* End of code generation (ExtendedKalmanFilter.c) */
