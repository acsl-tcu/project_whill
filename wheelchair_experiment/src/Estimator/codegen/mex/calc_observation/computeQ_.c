/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeQ_.c
 *
 * Code generation for function 'computeQ_'
 *
 */

/* Include files */
#include "computeQ_.h"
#include "calc_observation_data.h"
#include "calc_observation_internal_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "lapacke.h"
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ng_emlrtRSI = {
    1,           /* lineNo */
    "computeQ_", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+QRManager/"
    "computeQ_.p" /* pathName */
};

static emlrtRSInfo og_emlrtRSI =
    {
        60,             /* lineNo */
        "ceval_xorgqr", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xorgqr.m" /* pathName */
};

static emlrtRSInfo pg_emlrtRSI =
    {
        14,       /* lineNo */
        "xorgqr", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xorgqr.m" /* pathName */
};

/* Function Definitions */
void computeQ_(const emlrtStack *sp, j_struct_T *obj, int32_T nrows)
{
  static const char_T fname[14] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                   '_', 'd', 'o', 'r', 'g', 'q', 'r'};
  ptrdiff_t info_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T b;
  int32_T idx;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b = obj->minRowCol;
  st.site = &ng_emlrtRSI;
  if (obj->minRowCol > 2147483646) {
    b_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (idx = 0; idx < b; idx++) {
    int32_T iQR0;
    int32_T n;
    iQR0 = 15 * idx + idx;
    st.site = &ng_emlrtRSI;
    n = (obj->mrows - idx) - 1;
    b_st.site = &cf_emlrtRSI;
    c_st.site = &df_emlrtRSI;
    if (n > 2147483646) {
      d_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    if (n - 1 >= 0) {
      memcpy(&obj->Q[iQR0 + 1], &obj->QR[iQR0 + 1],
             (uint32_T)n * sizeof(real_T));
    }
  }
  st.site = &ng_emlrtRSI;
  b_st.site = &pg_emlrtRSI;
  info_t = LAPACKE_dorgqr(102, (ptrdiff_t)obj->mrows, (ptrdiff_t)nrows,
                          (ptrdiff_t)obj->minRowCol, &obj->Q[0], (ptrdiff_t)15,
                          &obj->tau[0]);
  c_st.site = &og_emlrtRSI;
  if ((int32_T)info_t != 0) {
    boolean_T b_p;
    p = true;
    b_p = false;
    if ((int32_T)info_t == -7) {
      b_p = true;
    } else if ((int32_T)info_t == -5) {
      b_p = true;
    }
    if (!b_p) {
      if ((int32_T)info_t == -1010) {
        emlrtErrorWithMessageIdR2018a(&c_st, &db_emlrtRTEI, "MATLAB:nomem",
                                      "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&c_st, &eb_emlrtRTEI,
                                      "Coder:toolbox:LAPACKCallErrorInfo",
                                      "Coder:toolbox:LAPACKCallErrorInfo", 5, 4,
                                      14, &fname[0], 12, (int32_T)info_t);
      }
    }
  } else {
    p = false;
  }
  if (p) {
    for (b = 0; b < 225; b++) {
      obj->Q[b] = rtNaN;
    }
  }
}

/* End of code generation (computeQ_.c) */
