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
#include "Faster_processingPcloud_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "mwmathutil.h"
#include <math.h>

/* Variable Definitions */
static emlrtRSInfo tb_emlrtRSI = {
    342,                      /* lineNo */
    "validateRotationMatrix", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/images/images/+images/+internal/"
    "rigid3dImpl.m" /* pathName */
};

static emlrtRSInfo vb_emlrtRSI = {
    349,                         /* lineNo */
    "validateTranslationVector", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/images/images/+images/+internal/"
    "rigid3dImpl.m" /* pathName */
};

static emlrtRSInfo wb_emlrtRSI = {
    315,                                       /* lineNo */
    "rigid3dImpl/isTransformationMatrixRigid", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/images/images/+images/+internal/"
    "rigid3dImpl.m" /* pathName */
};

static emlrtRSInfo xb_emlrtRSI = {
    317,                                       /* lineNo */
    "rigid3dImpl/isTransformationMatrixRigid", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/images/images/+images/+internal/"
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
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack st;
  real_T rot[9];
  real_T singularValues[3];
  real_T absx;
  real_T ex;
  real_T s;
  int32_T exponent;
  int32_T idx;
  int32_T ijA;
  int32_T j;
  int32_T jp1j;
  int32_T k;
  boolean_T exitg1;
  boolean_T isRigid;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  for (ijA = 0; ijA < 3; ijA++) {
    idx = ijA << 2;
    rot[3 * ijA] = T[idx];
    rot[3 * ijA + 1] = T[idx + 1];
    rot[3 * ijA + 2] = T[idx + 2];
  }
  st.site = &wb_emlrtRSI;
  svd(&st, rot, singularValues);
  isRigid = !muDoubleScalarIsNaN(singularValues[0]);
  if (isRigid) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!muDoubleScalarIsNaN(singularValues[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    s = singularValues[0];
  } else {
    s = singularValues[idx - 1];
    ijA = idx + 1;
    for (k = ijA; k < 4; k++) {
      absx = singularValues[k - 1];
      if (s < absx) {
        s = absx;
      }
    }
  }
  if (isRigid) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!muDoubleScalarIsNaN(singularValues[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    ex = singularValues[0];
  } else {
    ex = singularValues[idx - 1];
    ijA = idx + 1;
    for (k = ijA; k < 4; k++) {
      absx = singularValues[k - 1];
      if (ex > absx) {
        ex = absx;
      }
    }
  }
  absx = muDoubleScalarAbs(s);
  if (muDoubleScalarIsInf(absx) || muDoubleScalarIsNaN(absx)) {
    absx = rtNaN;
  } else if (absx < 4.4501477170144028E-308) {
    absx = 4.94065645841247E-324;
  } else {
    frexp(absx, &exponent);
    absx = ldexp(1.0, exponent - 53);
  }
  if (s - ex < 1000.0 * absx) {
    int8_T ipiv[3];
    st.site = &xb_emlrtRSI;
    b_st.site = &gd_emlrtRSI;
    c_st.site = &hd_emlrtRSI;
    ipiv[0] = 1;
    ipiv[1] = 2;
    for (j = 0; j < 2; j++) {
      int32_T b_tmp;
      int32_T mmj_tmp;
      mmj_tmp = 1 - j;
      b_tmp = j << 2;
      jp1j = b_tmp + 2;
      idx = 4 - j;
      exponent = 0;
      absx = muDoubleScalarAbs(rot[b_tmp]);
      for (k = 2; k < idx; k++) {
        s = muDoubleScalarAbs(rot[(b_tmp + k) - 1]);
        if (s > absx) {
          exponent = k - 1;
          absx = s;
        }
      }
      if (rot[b_tmp + exponent] != 0.0) {
        if (exponent != 0) {
          idx = j + exponent;
          ipiv[j] = (int8_T)(idx + 1);
          absx = rot[j];
          rot[j] = rot[idx];
          rot[idx] = absx;
          absx = rot[j + 3];
          rot[j + 3] = rot[idx + 3];
          rot[idx + 3] = absx;
          absx = rot[j + 6];
          rot[j + 6] = rot[idx + 6];
          rot[idx + 6] = absx;
        }
        ijA = (b_tmp - j) + 3;
        d_st.site = &id_emlrtRSI;
        for (idx = jp1j; idx <= ijA; idx++) {
          rot[idx - 1] /= rot[b_tmp];
        }
      }
      d_st.site = &jd_emlrtRSI;
      e_st.site = &kd_emlrtRSI;
      f_st.site = &ld_emlrtRSI;
      g_st.site = &md_emlrtRSI;
      idx = b_tmp + 5;
      h_st.site = &nd_emlrtRSI;
      for (jp1j = 0; jp1j <= mmj_tmp; jp1j++) {
        absx = rot[(b_tmp + jp1j * 3) + 3];
        if (absx != 0.0) {
          exponent = (idx - j) + 1;
          h_st.site = &od_emlrtRSI;
          if ((idx <= exponent) && (exponent > 2147483646)) {
            i_st.site = &ab_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          for (ijA = idx; ijA <= exponent; ijA++) {
            rot[ijA - 1] += rot[((b_tmp + ijA) - idx) + 1] * -absx;
          }
        }
        idx += 3;
      }
    }
    isRigid = false;
    isRigid = ((ipiv[0] > 1) || isRigid);
    absx = rot[0] * rot[4] * rot[8];
    if (ipiv[1] > 2) {
      isRigid = !isRigid;
    }
    if (isRigid) {
      absx = -absx;
    }
    if (muDoubleScalarAbs(absx - 1.0) < 2.2204460492503131E-13) {
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
  st.site = &tb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &ub_emlrtRSI;
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
        &b_st, &i_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
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
  st.site = &vb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &ub_emlrtRSI;
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
        &b_st, &i_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:rigid3d:expectedFinite", 3, 4, 5, "trans");
  }
}

/* End of code generation (rigid3dImpl.c) */
