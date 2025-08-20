/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rigid3dImpl.c
 *
 * Code generation for function 'rigid3dImpl'
 *
 */

/* Include files */
#include "rigid3dImpl.h"
#include "det.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "xzsvdc.h"
#include "mwmathutil.h"
#include <math.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ic_emlrtRSI = {
    342,                      /* lineNo */
    "validateRotationMatrix", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/images/images/+images/+internal/"
    "rigid3dImpl.m" /* pathName */
};

static emlrtRSInfo kc_emlrtRSI = {
    349,                         /* lineNo */
    "validateTranslationVector", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/images/images/+images/+internal/"
    "rigid3dImpl.m" /* pathName */
};

static emlrtRSInfo lc_emlrtRSI = {
    315,                                       /* lineNo */
    "rigid3dImpl/isTransformationMatrixRigid", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/images/images/+images/+internal/"
    "rigid3dImpl.m" /* pathName */
};

static emlrtRSInfo mc_emlrtRSI = {
    316,                                       /* lineNo */
    "rigid3dImpl/isTransformationMatrixRigid", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/images/images/+images/+internal/"
    "rigid3dImpl.m" /* pathName */
};

static emlrtRSInfo nc_emlrtRSI = {
    317,                                       /* lineNo */
    "rigid3dImpl/isTransformationMatrixRigid", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/images/images/+images/+internal/"
    "rigid3dImpl.m" /* pathName */
};

/* Function Definitions */
boolean_T c_rigid3dImpl_isTransformationM(const emlrtStack *sp,
                                          const real_T T[16])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T b_rot[9];
  real_T rot[9];
  real_T s[3];
  real_T absx;
  real_T b_ex;
  real_T c_ex;
  real_T ex;
  int32_T exponent;
  int32_T i;
  int32_T idx;
  int32_T k;
  boolean_T exitg1;
  boolean_T isRigid;
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
  for (i = 0; i < 3; i++) {
    idx = i << 2;
    rot[3 * i] = T[idx];
    rot[3 * i + 1] = T[idx + 1];
    rot[3 * i + 2] = T[idx + 2];
  }
  st.site = &lc_emlrtRSI;
  b_st.site = &oc_emlrtRSI;
  c_st.site = &qc_emlrtRSI;
  d_st.site = &rc_emlrtRSI;
  p = true;
  for (k = 0; k < 9; k++) {
    if (p) {
      absx = T[k % 3 + ((k / 3) << 2)];
      if (muDoubleScalarIsInf(absx) || muDoubleScalarIsNaN(absx)) {
        p = false;
      }
    } else {
      p = false;
    }
  }
  if (p) {
    b_st.site = &pc_emlrtRSI;
    c_st.site = &tc_emlrtRSI;
    d_st.site = &uc_emlrtRSI;
    memcpy(&b_rot[0], &rot[0], 9U * sizeof(real_T));
    e_st.site = &vc_emlrtRSI;
    xzsvdc(&e_st, b_rot, s);
  } else {
    s[0] = rtNaN;
    s[1] = rtNaN;
    s[2] = rtNaN;
  }
  p = !muDoubleScalarIsNaN(s[0]);
  if (p) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!muDoubleScalarIsNaN(s[k - 1])) {
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
  st.site = &mc_emlrtRSI;
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
      if (!muDoubleScalarIsNaN(s[k - 1])) {
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
  if (p) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!muDoubleScalarIsNaN(s[k - 1])) {
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
  absx = muDoubleScalarAbs(c_ex);
  if (muDoubleScalarIsInf(absx) || muDoubleScalarIsNaN(absx)) {
    absx = rtNaN;
  } else if (absx < 4.4501477170144028E-308) {
    absx = 4.94065645841247E-324;
  } else {
    frexp(absx, &exponent);
    absx = ldexp(1.0, exponent - 53);
  }
  if (ex - b_ex < 1000.0 * absx) {
    st.site = &nc_emlrtRSI;
    absx = det(&st, rot) - 1.0;
    if (muDoubleScalarAbs(absx) < 2.2204460492503131E-13) {
      isRigid = true;
    } else {
      isRigid = false;
    }
  } else {
    isRigid = false;
  }
  return isRigid;
}

void validateRotationMatrix(const emlrtStack *sp, const real_T rot[9])
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ic_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &jc_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    if ((!muDoubleScalarIsInf(rot[k])) && (!muDoubleScalarIsNaN(rot[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &h_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:rigid3d:expectedFinite", 3, 4, 3, "rot");
  }
}

void validateTranslationVector(const emlrtStack *sp, const real_T trans[3])
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &kc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &jc_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 3)) {
    if ((!muDoubleScalarIsInf(trans[k])) && (!muDoubleScalarIsNaN(trans[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &h_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:rigid3d:expectedFinite", 3, 4, 5, "trans");
  }
}

/* End of code generation (rigid3dImpl.c) */
