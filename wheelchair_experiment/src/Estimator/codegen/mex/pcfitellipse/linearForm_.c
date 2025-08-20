/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * linearForm_.c
 *
 * Code generation for function 'linearForm_'
 *
 */

/* Include files */
#include "linearForm_.h"
#include "eml_int_forloop_overflow_check.h"
#include "pcfitellipse_data.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo bg_emlrtRSI = {
    1,             /* lineNo */
    "linearForm_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "Objective\\linearForm_.p" /* pathName */
};

/* Function Definitions */
void linearForm_(const emlrtStack *sp, boolean_T obj_hasLinear,
                 int32_T obj_nvar, real_T workspace[120], const real_T H[25],
                 const real_T f[8], const real_T x[8])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T beta1;
  int32_T ia;
  int32_T iac;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  beta1 = 0;
  if (obj_hasLinear) {
    st.site = &bg_emlrtRSI;
    if (obj_nvar > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    beta1 = (uint8_T)obj_nvar;
    if (beta1 - 1 >= 0) {
      memcpy(&workspace[0], &f[0], (uint32_T)beta1 * sizeof(real_T));
    }
    beta1 = 1;
  }
  st.site = &bg_emlrtRSI;
  b_st.site = &sc_emlrtRSI;
  if (obj_nvar != 0) {
    int32_T b_tmp;
    int32_T ix;
    boolean_T overflow;
    if (beta1 != 1) {
      c_st.site = &ce_emlrtRSI;
      if (obj_nvar > 2147483646) {
        d_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      beta1 = (uint8_T)obj_nvar;
      memset(&workspace[0], 0, (uint32_T)beta1 * sizeof(real_T));
    }
    ix = 0;
    b_tmp = obj_nvar * (obj_nvar - 1) + 1;
    c_st.site = &hd_emlrtRSI;
    if ((obj_nvar == 0) || (b_tmp < 1)) {
      overflow = false;
    } else {
      overflow = (b_tmp > MAX_int32_T - obj_nvar);
    }
    if (obj_nvar == 0) {
      emlrtErrorWithMessageIdR2018a(&c_st, &w_emlrtRTEI,
                                    "Coder:builtins:VectorStride",
                                    "Coder:builtins:VectorStride", 0);
    }
    if (overflow) {
      d_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (iac = 1; obj_nvar < 0 ? iac >= b_tmp : iac <= b_tmp; iac += obj_nvar) {
      real_T c;
      int32_T b;
      c = 0.5 * x[ix];
      b = (iac + obj_nvar) - 1;
      c_st.site = &gd_emlrtRSI;
      if ((iac <= b) && (b > 2147483646)) {
        d_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (ia = iac; ia <= b; ia++) {
        beta1 = ia - iac;
        workspace[beta1] += H[ia - 1] * c;
      }
      ix++;
    }
  }
}

/* End of code generation (linearForm_.c) */
