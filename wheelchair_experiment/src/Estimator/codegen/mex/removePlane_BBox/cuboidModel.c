/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * cuboidModel.c
 *
 * Code generation for function 'cuboidModel'
 *
 */

/* Include files */
#include "cuboidModel.h"
#include "removePlane_BBox_data.h"
#include "removePlane_BBox_internal_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo pe_emlrtRSI =
    {
        59,                        /* lineNo */
        "cuboidModel/cuboidModel", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\cuboidModel.m" /* pathName
                                                                       */
};

static emlrtRSInfo qe_emlrtRSI =
    {
        64,                        /* lineNo */
        "cuboidModel/cuboidModel", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\cuboidModel.m" /* pathName
                                                                       */
};

static emlrtRSInfo re_emlrtRSI =
    {
        80,                        /* lineNo */
        "cuboidModel/cuboidModel", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\lidar\\lidar\\cuboidModel.m" /* pathName
                                                                       */
};

static emlrtRTEInfo o_emlrtRTEI = {
    14,               /* lineNo */
    37,               /* colNo */
    "validatenonnan", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatenonnan.m" /* pName */
};

static emlrtRTEInfo p_emlrtRTEI = {
    14,               /* lineNo */
    37,               /* colNo */
    "validatefinite", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatefinite.m" /* pName */
};

static emlrtRTEInfo q_emlrtRTEI = {
    14,                    /* lineNo */
    37,                    /* colNo */
    "validatenonnegative", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatenonnegative.m" /* pName */
};

/* Function Definitions */
cuboidModel *cuboidModel_cuboidModel(const emlrtStack *sp, cuboidModel *this,
                                     const real_T paramsInput[9])
{
  cuboidModel *b_this;
  emlrtStack b_st;
  emlrtStack st;
  int32_T k;
  boolean_T x[9];
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_this = this;
  st.site = &pe_emlrtRSI;
  st.site = &qe_emlrtRSI;
  b_st.site = &fb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    if (!muDoubleScalarIsNaN(paramsInput[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &o_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:cuboidModel:expectedNonNaN", 3, 4, 6, "params");
  }
  b_st.site = &fb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    if ((!muDoubleScalarIsInf(paramsInput[k])) &&
        (!muDoubleScalarIsNaN(paramsInput[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &p_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:cuboidModel:expectedFinite", 3, 4, 6, "params");
  }
  for (k = 0; k < 9; k++) {
    x[k] = (paramsInput[k] == 0.0);
  }
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    if (!x[k]) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (!p) {
    st.site = &re_emlrtRSI;
    b_st.site = &fb_emlrtRSI;
    if (paramsInput[5] < 0.0) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &q_emlrtRTEI,
          "Coder:toolbox:ValidateattributesexpectedNonnegative",
          "MATLAB:cuboidModel:expectedNonnegative", 3, 4, 4, "zlen");
    }
  }
  for (k = 0; k < 9; k++) {
    b_this->Parameters[k] = paramsInput[k];
  }
  return b_this;
}

/* End of code generation (cuboidModel.c) */
