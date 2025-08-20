/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * affine3d.c
 *
 * Code generation for function 'affine3d'
 *
 */

/* Include files */
#include "affine3d.h"
#include "det.h"
#include "rt_nonfinite.h"
#include "validateattributes.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo pe_emlrtRSI = {
    49,                  /* lineNo */
    "affine3d/affine3d", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/images/images/+images/+internal/+coder/"
    "affine3d.m" /* pathName */
};

static emlrtRSInfo qe_emlrtRSI = {
    50,                  /* lineNo */
    "affine3d/affine3d", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/images/images/+images/+internal/+coder/"
    "affine3d.m" /* pathName */
};

static emlrtRSInfo re_emlrtRSI = {
    82,                          /* lineNo */
    "affine3dImpl/affine3dImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/images/images/+images/+internal/"
    "affine3dImpl.m" /* pathName */
};

static emlrtRSInfo se_emlrtRSI = {
    285,                  /* lineNo */
    "affine3dImpl/set.T", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/images/images/+images/+internal/"
    "affine3dImpl.m" /* pathName */
};

static emlrtRSInfo te_emlrtRSI = {
    291,                  /* lineNo */
    "affine3dImpl/set.T", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/images/images/+images/+internal/"
    "affine3dImpl.m" /* pathName */
};

static emlrtRTEInfo o_emlrtRTEI = {
    292,                  /* lineNo */
    21,                   /* colNo */
    "affine3dImpl/set.T", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/images/images/+images/+internal/"
    "affine3dImpl.m" /* pName */
};

static emlrtRTEInfo p_emlrtRTEI = {
    307,                  /* lineNo */
    17,                   /* colNo */
    "affine3dImpl/set.T", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/images/images/+images/+internal/"
    "affine3dImpl.m" /* pName */
};

/* Function Definitions */
void affine3d_affine3d(const emlrtStack *sp, const real_T varargin_1[16],
                       real_T this_T[16])
{
  static const int8_T varargin_2[4] = {0, 0, 0, 1};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T x1;
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  st.site = &pe_emlrtRSI;
  b_st.site = &re_emlrtRSI;
  c_st.site = &se_emlrtRSI;
  validateattributes(&c_st, varargin_1);
  c_st.site = &te_emlrtRSI;
  x1 = b_det(&c_st, varargin_1);
  if (x1 == 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &o_emlrtRTEI, "images:geotrans:singularTransformationMatrix",
        "images:geotrans:singularTransformationMatrix", 0);
  }
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 4)) {
    if (!(varargin_1[k + 12] == varargin_2[k])) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &p_emlrtRTEI,
                                  "images:geotrans:invalidAffineMatrix",
                                  "images:geotrans:invalidAffineMatrix", 0);
  }
  memcpy(&this_T[0], &varargin_1[0], 16U * sizeof(real_T));
  st.site = &qe_emlrtRSI;
  b_st.site = &re_emlrtRSI;
  c_st.site = &se_emlrtRSI;
  validateattributes(&c_st, varargin_1);
  c_st.site = &te_emlrtRSI;
  x1 = b_det(&c_st, varargin_1);
  if (x1 == 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &o_emlrtRTEI, "images:geotrans:singularTransformationMatrix",
        "images:geotrans:singularTransformationMatrix", 0);
  }
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 4)) {
    if (!(varargin_1[k + 12] == varargin_2[k])) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &p_emlrtRTEI,
                                  "images:geotrans:invalidAffineMatrix",
                                  "images:geotrans:invalidAffineMatrix", 0);
  }
}

/* End of code generation (affine3d.c) */
