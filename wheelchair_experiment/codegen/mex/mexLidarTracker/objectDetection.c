/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * objectDetection.c
 *
 * Code generation for function 'objectDetection'
 *
 */

/* Include files */
#include "objectDetection.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo jl_emlrtRSI = {
    179,                        /* lineNo */
    "objectDetection/set.Time", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
    "objectDetection.m" /* pathName */
};

/* Function Definitions */
void objectDetection_set_Time(const emlrtStack *sp, objectDetection *detection,
                              real_T b_value)
{
  emlrtStack b_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &jl_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &jc_emlrtRSI;
  if (muDoubleScalarIsInf(b_value) || muDoubleScalarIsNaN(b_value)) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &h_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:objectDetection:expectedFinite", 3, 4, 4, "Time");
  }
  b_st.site = &jc_emlrtRSI;
  if (b_value < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &ib_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonnegative",
        "MATLAB:objectDetection:expectedNonnegative", 3, 4, 4, "Time");
  }
  detection->Time = b_value;
}

/* End of code generation (objectDetection.c) */
