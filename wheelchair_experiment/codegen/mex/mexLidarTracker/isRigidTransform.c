/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * isRigidTransform.c
 *
 * Code generation for function 'isRigidTransform'
 *
 */

/* Include files */
#include "isRigidTransform.h"
#include "det.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "xzsvdc.h"
#include "mwmathutil.h"
#include <math.h>

/* Variable Definitions */
static emlrtRSInfo if_emlrtRSI = {
    10,                 /* lineNo */
    "isRigidTransform", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/"
    "isRigidTransform.m" /* pathName */
};

static emlrtRSInfo jf_emlrtRSI = {
    11,                 /* lineNo */
    "isRigidTransform", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/"
    "isRigidTransform.m" /* pathName */
};

static emlrtRSInfo kf_emlrtRSI = {
    12,                 /* lineNo */
    "isRigidTransform", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/vision/vision/+vision/+internal/"
    "isRigidTransform.m" /* pathName */
};

/* Function Definitions */
boolean_T isRigidTransform(const emlrtStack *sp, const real32_T T[16])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T exponent;
  int32_T i;
  int32_T idx;
  int32_T k;
  real32_T s[3];
  real32_T absx;
  real32_T b_ex;
  real32_T c_ex;
  real32_T ex;
  boolean_T exitg1;
  boolean_T p;
  boolean_T tf;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &if_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &oc_emlrtRSI;
  c_st.site = &qc_emlrtRSI;
  d_st.site = &rc_emlrtRSI;
  p = true;
  for (k = 0; k < 9; k++) {
    if (p) {
      absx = T[k % 3 + ((k / 3) << 2)];
      if (muSingleScalarIsInf(absx) || muSingleScalarIsNaN(absx)) {
        p = false;
      }
    } else {
      p = false;
    }
  }
  if (p) {
    real32_T b_T[9];
    b_st.site = &pc_emlrtRSI;
    c_st.site = &tc_emlrtRSI;
    d_st.site = &uc_emlrtRSI;
    for (i = 0; i < 3; i++) {
      idx = i << 2;
      b_T[3 * i] = T[idx];
      b_T[3 * i + 1] = T[idx + 1];
      b_T[3 * i + 2] = T[idx + 2];
    }
    e_st.site = &vc_emlrtRSI;
    b_xzsvdc(&e_st, b_T, s);
  } else {
    s[0] = rtNaNF;
    s[1] = rtNaNF;
    s[2] = rtNaNF;
  }
  st.site = &jf_emlrtRSI;
  b_st.site = &lf_emlrtRSI;
  c_st.site = &mf_emlrtRSI;
  d_st.site = &nf_emlrtRSI;
  p = !muSingleScalarIsNaN(s[0]);
  if (p) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!muSingleScalarIsNaN(s[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    ex = s[0];
  } else {
    ex = s[idx - 1];
    i = idx + 1;
    for (k = i; k < 4; k++) {
      absx = s[k - 1];
      if (ex < absx) {
        ex = absx;
      }
    }
  }
  st.site = &jf_emlrtRSI;
  b_st.site = &vd_emlrtRSI;
  c_st.site = &wd_emlrtRSI;
  d_st.site = &xd_emlrtRSI;
  if (p) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!muSingleScalarIsNaN(s[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    b_ex = s[0];
  } else {
    b_ex = s[idx - 1];
    i = idx + 1;
    for (k = i; k < 4; k++) {
      absx = s[k - 1];
      if (b_ex > absx) {
        b_ex = absx;
      }
    }
  }
  st.site = &jf_emlrtRSI;
  b_st.site = &lf_emlrtRSI;
  c_st.site = &mf_emlrtRSI;
  d_st.site = &nf_emlrtRSI;
  if (p) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!muSingleScalarIsNaN(s[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    c_ex = s[0];
  } else {
    c_ex = s[idx - 1];
    i = idx + 1;
    for (k = i; k < 4; k++) {
      absx = s[k - 1];
      if (c_ex < absx) {
        c_ex = absx;
      }
    }
  }
  absx = muSingleScalarAbs(c_ex);
  if (muSingleScalarIsInf(absx) || muSingleScalarIsNaN(absx)) {
    absx = rtNaNF;
  } else if (absx < 2.3509887E-38F) {
    absx = 1.4013E-45F;
  } else {
    frexpf(absx, &exponent);
    absx = ldexpf(1.0F, exponent - 24);
  }
  if (ex - b_ex < 100.0F * absx) {
    st.site = &kf_emlrtRSI;
    absx = c_det(&st, T) - 1.0F;
    if (muSingleScalarAbs(absx) < 1.1920929E-5F) {
      tf = true;
    } else {
      tf = false;
    }
  } else {
    tf = false;
  }
  return tf;
}

/* End of code generation (isRigidTransform.c) */
