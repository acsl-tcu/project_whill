/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sum.c
 *
 * Code generation for function 'sum'
 *
 */

/* Include files */
#include "sum.h"
#include "EvaluationPath_data.h"
#include "EvaluationPath_emxutil.h"
#include "EvaluationPath_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"

/* Variable Definitions */
static emlrtRSInfo vd_emlrtRSI = {
    20,    /* lineNo */
    "sum", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/sum.m" /* pathName
                                                                     */
};

static emlrtRSInfo wd_emlrtRSI =
    {
        99,        /* lineNo */
        "sumprod", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
        "sumprod.m" /* pathName */
};

static emlrtRSInfo xd_emlrtRSI = {
    86,                      /* lineNo */
    "combineVectorElements", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
    "combineVectorElements.m" /* pathName */
};

static emlrtRSInfo yd_emlrtRSI = {
    107,                /* lineNo */
    "blockedSummation", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pathName */
};

static emlrtRSInfo ae_emlrtRSI = {
    22,                    /* lineNo */
    "sumMatrixIncludeNaN", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo be_emlrtRSI = {
    41,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo ce_emlrtRSI = {
    42,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo de_emlrtRSI = {
    50,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo ee_emlrtRSI = {
    57,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRTEInfo n_emlrtRTEI =
    {
        76,        /* lineNo */
        9,         /* colNo */
        "sumprod", /* fName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
        "sumprod.m" /* pName */
};

static emlrtRTEInfo o_emlrtRTEI =
    {
        46,        /* lineNo */
        23,        /* colNo */
        "sumprod", /* fName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
        "sumprod.m" /* pName */
};

static emlrtRTEInfo ue_emlrtRTEI = {
    20,                                                             /* lineNo */
    1,                                                              /* colNo */
    "sum",                                                          /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/sum.m" /* pName */
};

static emlrtRTEInfo ve_emlrtRTEI = {
    35,                    /* lineNo */
    20,                    /* colNo */
    "sumMatrixIncludeNaN", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pName */
};

/* Function Definitions */
void b_sum(const real_T x[20000], real_T y[1000])
{
  int32_T k;
  int32_T xi;
  for (xi = 0; xi < 1000; xi++) {
    real_T d;
    int32_T xpageoffset;
    xpageoffset = xi * 20;
    d = x[xpageoffset];
    for (k = 0; k < 19; k++) {
      d += x[(xpageoffset + k) + 1];
    }
    y[xi] = d;
  }
}

void sum(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  real_T *y_data;
  int32_T col;
  int32_T ib;
  int32_T inb;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &vd_emlrtRSI;
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
  if (((x->size[0] != 1) || (x->size[1] != 1)) && (x->size[0] == 1)) {
    emlrtErrorWithMessageIdR2018a(&st, &o_emlrtRTEI,
                                  "Coder:toolbox:autoDimIncompatibility",
                                  "Coder:toolbox:autoDimIncompatibility", 0);
  }
  if ((x->size[0] == 0) && (x->size[1] == 0)) {
    emlrtErrorWithMessageIdR2018a(&st, &n_emlrtRTEI,
                                  "Coder:toolbox:UnsupportedSpecialEmpty",
                                  "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }
  b_st.site = &wd_emlrtRSI;
  c_st.site = &xd_emlrtRSI;
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    int32_T nfb;
    inb = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = x->size[1];
    emxEnsureCapacity_real_T(&c_st, y, inb, &ue_emlrtRTEI);
    y_data = y->data;
    nfb = x->size[1];
    for (inb = 0; inb < nfb; inb++) {
      y_data[inb] = 0.0;
    }
  } else {
    int32_T i;
    d_st.site = &yd_emlrtRSI;
    e_st.site = &ae_emlrtRSI;
    inb = y->size[0] * y->size[1];
    y->size[0] = 1;
    i = x->size[1];
    y->size[1] = x->size[1];
    emxEnsureCapacity_real_T(&e_st, y, inb, &ve_emlrtRTEI);
    y_data = y->data;
    if (x->size[0] < 4096) {
      f_st.site = &be_emlrtRSI;
      if (x->size[1] > 2147483646) {
        g_st.site = &t_emlrtRSI;
        check_forloop_overflow_error(&g_st);
      }
      for (col = 0; col < i; col++) {
        f_st.site = &ce_emlrtRSI;
        y_data[col] = sumColumnB(&f_st, x, col + 1, x->size[0]);
      }
    } else {
      int32_T nfb;
      int32_T nleft;
      nfb = (int32_T)((uint32_T)x->size[0] >> 12);
      inb = nfb << 12;
      nleft = x->size[0] - inb;
      f_st.site = &de_emlrtRSI;
      if (x->size[1] > 2147483646) {
        g_st.site = &t_emlrtRSI;
        check_forloop_overflow_error(&g_st);
      }
      for (col = 0; col < i; col++) {
        real_T s;
        s = sumColumnB4(x, col + 1, 1);
        for (ib = 2; ib <= nfb; ib++) {
          s += sumColumnB4(x, col + 1, ((ib - 1) << 12) + 1);
        }
        if (nleft > 0) {
          f_st.site = &ee_emlrtRSI;
          s += b_sumColumnB(&f_st, x, col + 1, nleft, inb + 1);
        }
        y_data[col] = s;
      }
    }
  }
}

/* End of code generation (sum.c) */
