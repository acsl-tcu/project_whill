/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ransac.c
 *
 * Code generation for function 'ransac'
 *
 */

/* Include files */
#include "ransac.h"
#include "msac.h"
#include "pcfitellipse_internal_types.h"
#include "pcfitellipse_types.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo p_emlrtRSI = {
    148,      /* lineNo */
    "ransac", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pathName
                                                                            */
};

static emlrtRSInfo q_emlrtRSI = {
    164,      /* lineNo */
    "ransac", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pathName
                                                                            */
};

static emlrtRSInfo r_emlrtRSI = {
    175,      /* lineNo */
    "ransac", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pathName
                                                                            */
};

static emlrtRSInfo s_emlrtRSI = {
    180,      /* lineNo */
    "ransac", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pathName
                                                                            */
};

static emlrtRSInfo t_emlrtRSI = {
    199,           /* lineNo */
    "parseInputs", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pathName
                                                                            */
};

static emlrtRSInfo u_emlrtRSI = {
    205,           /* lineNo */
    "parseInputs", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pathName
                                                                            */
};

static emlrtRSInfo v_emlrtRSI = {
    207,           /* lineNo */
    "parseInputs", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pathName
                                                                            */
};

static emlrtRSInfo w_emlrtRSI = {
    261,           /* lineNo */
    "parseInputs", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pathName
                                                                            */
};

static emlrtRSInfo x_emlrtRSI = {
    262,           /* lineNo */
    "parseInputs", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pathName
                                                                            */
};

static emlrtRSInfo y_emlrtRSI = {
    263,           /* lineNo */
    "parseInputs", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pathName
                                                                            */
};

static emlrtRSInfo ab_emlrtRSI = {
    93,                   /* lineNo */
    "validateattributes", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes"
    ".m" /* pathName */
};

static emlrtRSInfo bb_emlrtRSI = {
    294,                /* lineNo */
    "checkMaxDistance", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pathName
                                                                            */
};

static emlrtRSInfo cb_emlrtRSI = {
    276,                 /* lineNo */
    "checkMaxNumTrials", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pathName
                                                                            */
};

static emlrtRSInfo db_emlrtRSI = {
    282,                        /* lineNo */
    "checkMaxSamplingAttempts", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pathName
                                                                            */
};

static emlrtRSInfo eb_emlrtRSI = {
    288,               /* lineNo */
    "checkConfidence", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pathName
                                                                            */
};

static emlrtRTEInfo c_emlrtRTEI = {
    188,                  /* lineNo */
    5,                    /* colNo */
    "checkRuntimeStatus", /* fName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pName
                                                                            */
};

static emlrtRTEInfo d_emlrtRTEI = {
    190,                  /* lineNo */
    1,                    /* colNo */
    "checkRuntimeStatus", /* fName */
    "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\ransac.m" /* pName
                                                                            */
};

static emlrtRTEInfo e_emlrtRTEI = {
    13,                 /* lineNo */
    37,                 /* colNo */
    "validatenonempty", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatenonempty.m" /* pName */
};

static emlrtRTEInfo f_emlrtRTEI = {
    13,                /* lineNo */
    37,                /* colNo */
    "validateinteger", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validateinteger.m" /* pName */
};

static emlrtRTEInfo g_emlrtRTEI = {
    14,                 /* lineNo */
    37,                 /* colNo */
    "validatepositive", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatepositive.m" /* pName */
};

static emlrtRTEInfo h_emlrtRTEI = {
    14,                    /* lineNo */
    37,                    /* colNo */
    "validatenonnegative", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatenonnegative.m" /* pName */
};

static emlrtRTEInfo i_emlrtRTEI = {
    14,               /* lineNo */
    37,               /* colNo */
    "validatefinite", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatefinite.m" /* pName */
};

static emlrtRTEInfo j_emlrtRTEI = {
    22,           /* lineNo */
    27,           /* colNo */
    "validatelt", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatelt.m" /* pName */
};

/* Function Definitions */
int32_T ransac(pcfitellipseStackData *SD, const emlrtStack *sp,
               const real_T data_data[], const int32_T data_size[2],
               const real_T fitFun_workspace_a0[5],
               const real_T fitFun_workspace_A[5], real_T fitFun_workspace_B,
               const real_T fitFun_workspace_lb[5],
               const real_T fitFun_workspace_ub[5],
               const real_T c_fitFun_workspace_nonlcon_work[2],
               real_T sampleSize, real_T maxDistance, real_T varargin_2,
               real_T varargin_4, real_T varargin_6,
               const e_struct_T *varargin_8_workspace, real_T model_data[],
               int32_T model_size[2], boolean_T inlierIdx_data[])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T inlierIdx_size;
  int32_T status;
  boolean_T reachedMaxSkipTrials;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &p_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &t_emlrtRSI;
  c_st.site = &ab_emlrtRSI;
  if (data_size[0] == 0) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &e_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonempty",
        "MATLAB:ransac:expectedNonempty", 3, 4, 4, "data");
  }
  b_st.site = &u_emlrtRSI;
  c_st.site = &ab_emlrtRSI;
  if (muDoubleScalarIsInf(sampleSize) || muDoubleScalarIsNaN(sampleSize) ||
      (!(muDoubleScalarFloor(sampleSize) == sampleSize))) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &f_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedInteger",
        "MATLAB:ransac:expectedInteger", 3, 4, 10, "sampleSize");
  }
  c_st.site = &ab_emlrtRSI;
  if (sampleSize <= 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &g_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:ransac:expectedPositive", 3, 4, 10, "sampleSize");
  }
  b_st.site = &v_emlrtRSI;
  c_st.site = &bb_emlrtRSI;
  d_st.site = &ab_emlrtRSI;
  if (maxDistance < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &h_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonnegative",
        "MATLAB:ransac:expectedNonnegative", 3, 4, 11, "maxDistance");
  }
  d_st.site = &ab_emlrtRSI;
  if (muDoubleScalarIsInf(maxDistance) || muDoubleScalarIsNaN(maxDistance)) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &i_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:ransac:expectedFinite", 3, 4, 11, "maxDistance");
  }
  b_st.site = &w_emlrtRSI;
  c_st.site = &cb_emlrtRSI;
  d_st.site = &ab_emlrtRSI;
  if (muDoubleScalarIsInf(varargin_4) || muDoubleScalarIsNaN(varargin_4) ||
      (!(muDoubleScalarFloor(varargin_4) == varargin_4))) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &f_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedInteger",
        "MATLAB:ransac:expectedInteger", 3, 4, 12, "MaxNumTrials");
  }
  d_st.site = &ab_emlrtRSI;
  if (varargin_4 <= 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &g_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:ransac:expectedPositive", 3, 4, 12, "MaxNumTrials");
  }
  b_st.site = &x_emlrtRSI;
  c_st.site = &db_emlrtRSI;
  d_st.site = &ab_emlrtRSI;
  if (muDoubleScalarIsInf(varargin_2) || muDoubleScalarIsNaN(varargin_2) ||
      (!(muDoubleScalarFloor(varargin_2) == varargin_2))) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &f_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedInteger",
        "MATLAB:ransac:expectedInteger", 3, 4, 19, "MaxSamplingAttempts");
  }
  d_st.site = &ab_emlrtRSI;
  if (varargin_2 <= 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &g_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:ransac:expectedPositive", 3, 4, 19, "MaxSamplingAttempts");
  }
  b_st.site = &y_emlrtRSI;
  c_st.site = &eb_emlrtRSI;
  d_st.site = &ab_emlrtRSI;
  if (varargin_6 <= 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &g_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:ransac:expectedPositive", 3, 4, 10, "Confidence");
  }
  d_st.site = &ab_emlrtRSI;
  if (!(varargin_6 < 100.0)) {
    emlrtErrorWithMessageIdR2018a(&d_st, &j_emlrtRTEI,
                                  "MATLAB:validateattributes:expectedScalar",
                                  "MATLAB:ransac:notLess", 9, 4, 10,
                                  "Confidence", 4, 1, "<", 4, 3, "100");
  }
  reachedMaxSkipTrials = false;
  if (data_size[0] < sampleSize) {
    int32_T loop_ub;
    status = 1;
    model_size[0] = 0;
    model_size[1] = 0;
    inlierIdx_size = data_size[0];
    loop_ub = data_size[0];
    memset(&inlierIdx_data[0], 0, (uint32_T)loop_ub * sizeof(boolean_T));
  } else {
    boolean_T isFound;
    st.site = &q_emlrtRSI;
    isFound = msac(SD, &st, data_data, data_size, sampleSize, maxDistance,
                   varargin_6, varargin_4, varargin_2, fitFun_workspace_a0,
                   fitFun_workspace_A, fitFun_workspace_B, fitFun_workspace_lb,
                   fitFun_workspace_ub, c_fitFun_workspace_nonlcon_work,
                   varargin_8_workspace, model_data, model_size, inlierIdx_data,
                   &inlierIdx_size, &reachedMaxSkipTrials);
    if (isFound) {
      status = 0;
    } else {
      status = 2;
    }
  }
  if (reachedMaxSkipTrials) {
    st.site = &r_emlrtRSI;
    c_warning(&st, varargin_2);
  }
  st.site = &s_emlrtRSI;
  if (status == 1) {
    emlrtErrorWithMessageIdR2018a(
        &st, &c_emlrtRTEI, "vision:ransac:notEnoughDataPts",
        "vision:ransac:notEnoughDataPts", 2, 6, sampleSize);
  }
  if (status == 2) {
    emlrtErrorWithMessageIdR2018a(&st, &d_emlrtRTEI,
                                  "vision:ransac:notEnoughInliers",
                                  "vision:ransac:notEnoughInliers", 0);
  }
  return inlierIdx_size;
}

/* End of code generation (ransac.c) */
