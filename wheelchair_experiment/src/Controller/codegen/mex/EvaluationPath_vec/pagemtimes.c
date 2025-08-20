/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pagemtimes.c
 *
 * Code generation for function 'pagemtimes'
 *
 */

/* Include files */
#include "pagemtimes.h"
#include "EvaluationPath_vec_data.h"
#include "EvaluationPath_vec_emxutil.h"
#include "EvaluationPath_vec_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo de_emlrtRSI = {
    25,           /* lineNo */
    "pagemtimes", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/pagemtimes.m" /* pathName
                                                                        */
};

static emlrtRSInfo ee_emlrtRSI = {
    61,           /* lineNo */
    "pagemtimes", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/pagemtimes.m" /* pathName
                                                                        */
};

static emlrtRSInfo fe_emlrtRSI = {
    66,           /* lineNo */
    "pagemtimes", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/pagemtimes.m" /* pathName
                                                                        */
};

static emlrtRSInfo ge_emlrtRSI = {
    67,           /* lineNo */
    "pagemtimes", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/pagemtimes.m" /* pathName
                                                                        */
};

static emlrtRSInfo he_emlrtRSI = {
    83,           /* lineNo */
    "pagemtimes", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/pagemtimes.m" /* pathName
                                                                        */
};

static emlrtRSInfo ie_emlrtRSI = {
    129,                          /* lineNo */
    "computeMultiplicationIndex", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/pagemtimes.m" /* pathName
                                                                        */
};

static emlrtRSInfo je_emlrtRSI = {
    33,        /* lineNo */
    "idivide", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/idivide.m" /* pathName
                                                                     */
};

static emlrtRSInfo ke_emlrtRSI = {
    81,            /* lineNo */
    "idivide_fix", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/idivide.m" /* pathName
                                                                     */
};

static emlrtRSInfo le_emlrtRSI =
    {
        142,      /* lineNo */
        "mtimes", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+blas/"
        "mtimes.m" /* pathName */
};

static emlrtRSInfo me_emlrtRSI =
    {
        178,           /* lineNo */
        "mtimes_blas", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+blas/"
        "mtimes.m" /* pathName */
};

static emlrtRTEInfo l_emlrtRTEI = {
    132,                                                            /* lineNo */
    9,                                                              /* colNo */
    "eml_idivide",                                                  /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/idivide.m" /* pName */
};

static emlrtRTEInfo m_emlrtRTEI = {
    188,                 /* lineNo */
    13,                  /* colNo */
    "processArraySizes", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/pagemtimes.m" /* pName
                                                                        */
};

static emlrtRTEInfo xh_emlrtRTEI = {
    56,           /* lineNo */
    24,           /* colNo */
    "pagemtimes", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/pagemtimes.m" /* pName
                                                                        */
};

static emlrtRSInfo sg_emlrtRSI =
    {
        103,      /* lineNo */
        "intmod", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+scalar/"
        "mod.m" /* pathName */
};

/* Function Declarations */
static int32_T div_s32(const emlrtStack *sp, int32_T numerator,
                       int32_T denominator);

/* Function Definitions */
static int32_T div_s32(const emlrtStack *sp, int32_T numerator,
                       int32_T denominator)
{
  int32_T quotient;
  if (denominator == 0) {
    emlrtDivisionByZeroErrorR2012b(NULL, (emlrtConstCTX)sp);
  } else {
    uint32_T u;
    uint32_T u1;
    if (numerator < 0) {
      u = ~(uint32_T)numerator + 1U;
    } else {
      u = (uint32_T)numerator;
    }
    if (denominator < 0) {
      u1 = ~(uint32_T)denominator + 1U;
    } else {
      u1 = (uint32_T)denominator;
    }
    u /= u1;
    if ((numerator < 0) != (denominator < 0)) {
      quotient = -(int32_T)u;
    } else {
      quotient = (int32_T)u;
    }
  }
  return quotient;
}

void pagemtimes(const emlrtStack *sp, const emxArray_real_T *varargin_1,
                const emxArray_real_T *varargin_2, emxArray_real_T *Z)
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T pageY_data[60];
  real_T tmp_data[60];
  const real_T *varargin_1_data;
  const real_T *varargin_2_data;
  real_T alpha1;
  real_T beta1;
  real_T *Z_data;
  int32_T b_p;
  int32_T i;
  int32_T ii;
  int32_T k;
  int32_T loop_ub;
  int32_T outputSize_idx_2;
  int32_T outputSize_idx_3;
  int32_T pageCount_tmp;
  uint32_T sizeX[4];
  uint32_T sizeY[4];
  char_T TRANSA1;
  char_T TRANSB1;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  varargin_2_data = varargin_2->data;
  varargin_1_data = varargin_1->data;
  st.site = &de_emlrtRSI;
  if (varargin_1->size[2] != 1) {
    if ((varargin_2->size[2] != 1) &&
        (varargin_1->size[2] != varargin_2->size[2])) {
      emlrtErrorWithMessageIdR2018a(
          &st, &m_emlrtRTEI, "MATLAB:pagemtimes:mismatchImplicitExpansion",
          "MATLAB:pagemtimes:mismatchImplicitExpansion", 0);
    }
    outputSize_idx_2 = varargin_1->size[2];
  } else {
    outputSize_idx_2 = varargin_2->size[2];
  }
  if (varargin_1->size[3] != 1) {
    if ((varargin_2->size[3] != 1) &&
        (varargin_1->size[3] != varargin_2->size[3])) {
      emlrtErrorWithMessageIdR2018a(
          &st, &m_emlrtRTEI, "MATLAB:pagemtimes:mismatchImplicitExpansion",
          "MATLAB:pagemtimes:mismatchImplicitExpansion", 0);
    }
    outputSize_idx_3 = varargin_1->size[3];
  } else {
    outputSize_idx_3 = varargin_2->size[3];
  }
  pageCount_tmp =
      (int32_T)((real_T)outputSize_idx_2 * (real_T)outputSize_idx_3);
  i = Z->size[0] * Z->size[1] * Z->size[2] * Z->size[3];
  Z->size[0] = 2;
  loop_ub = varargin_2->size[1];
  Z->size[1] = varargin_2->size[1];
  Z->size[2] = outputSize_idx_2;
  Z->size[3] = outputSize_idx_3;
  emxEnsureCapacity_real_T(sp, Z, i, &xh_emlrtRTEI);
  Z_data = Z->data;
  sizeX[0] = 2U;
  sizeY[0] = 2U;
  sizeX[1] = 2U;
  sizeY[1] = (uint32_T)varargin_2->size[1];
  sizeX[2] = (uint32_T)varargin_1->size[2];
  sizeY[2] = (uint32_T)varargin_2->size[2];
  sizeX[3] = (uint32_T)varargin_1->size[3];
  sizeY[3] = (uint32_T)varargin_2->size[3];
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((int32_T)sizeX[k + 2] != (int32_T)sizeY[k + 2]) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  st.site = &ee_emlrtRSI;
  if ((int32_T)((real_T)outputSize_idx_2 * (real_T)outputSize_idx_3) >
      2147483646) {
    b_st.site = &gb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (ii = 0; ii < pageCount_tmp; ii++) {
    int32_T X_idx;
    int32_T Y_idx;
    if (p) {
      X_idx = ii;
      Y_idx = ii;
    } else {
      uint32_T u;
      st.site = &fe_emlrtRSI;
      X_idx = 0;
      b_p = 1;
      if (varargin_1->size[2] != 1) {
        if (outputSize_idx_2 == 0) {
          X_idx = ii;
        } else {
          X_idx = ii - (int32_T)((uint32_T)ii / (uint32_T)outputSize_idx_2) *
                           outputSize_idx_2;
        }
        b_p = outputSize_idx_2;
      }
      b_st.site = &ie_emlrtRSI;
      c_st.site = &je_emlrtRSI;
      d_st.site = &ke_emlrtRSI;
      if (outputSize_idx_2 == 0) {
        emlrtErrorWithMessageIdR2018a(&d_st, &l_emlrtRTEI,
                                      "Coder:toolbox:idivide_divideByZero",
                                      "Coder:toolbox:idivide_divideByZero", 0);
      }
      u = (uint32_T)ii / (uint32_T)outputSize_idx_2;
      if (varargin_1->size[3] != 1) {
        if (outputSize_idx_3 == 0) {
          k = (int32_T)u;
        } else {
          b_st.site = &sg_emlrtRSI;
          k = (int32_T)u -
              div_s32(&b_st, (int32_T)u, outputSize_idx_3) * outputSize_idx_3;
        }
        X_idx += b_p * k;
      }
      b_st.site = &ie_emlrtRSI;
      c_st.site = &je_emlrtRSI;
      d_st.site = &ke_emlrtRSI;
      if (outputSize_idx_3 == 0) {
        emlrtErrorWithMessageIdR2018a(&d_st, &l_emlrtRTEI,
                                      "Coder:toolbox:idivide_divideByZero",
                                      "Coder:toolbox:idivide_divideByZero", 0);
      }
      st.site = &ge_emlrtRSI;
      Y_idx = 0;
      b_p = 1;
      if (varargin_2->size[2] != 1) {
        Y_idx = ii - (int32_T)u * outputSize_idx_2;
        b_p = outputSize_idx_2;
      }
      b_st.site = &ie_emlrtRSI;
      c_st.site = &je_emlrtRSI;
      if (varargin_2->size[3] != 1) {
        b_st.site = &sg_emlrtRSI;
        Y_idx +=
            b_p * ((int32_T)u - div_s32(&b_st, (int32_T)u, outputSize_idx_3) *
                                    outputSize_idx_3);
      }
      b_st.site = &ie_emlrtRSI;
      c_st.site = &je_emlrtRSI;
    }
    for (i = 0; i < loop_ub; i++) {
      k = 2 * i + 2 * loop_ub * Y_idx;
      pageY_data[2 * i] = varargin_2_data[k];
      pageY_data[2 * i + 1] = varargin_2_data[k + 1];
    }
    st.site = &he_emlrtRSI;
    if (varargin_2->size[1] != 0) {
      b_st.site = &le_emlrtRSI;
      c_st.site = &me_emlrtRSI;
      TRANSB1 = 'N';
      TRANSA1 = 'N';
      alpha1 = 1.0;
      beta1 = 0.0;
      m_t = (ptrdiff_t)2;
      n_t = (ptrdiff_t)varargin_2->size[1];
      k_t = (ptrdiff_t)2;
      lda_t = (ptrdiff_t)2;
      ldb_t = (ptrdiff_t)2;
      ldc_t = (ptrdiff_t)2;
      dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1,
            (real_T *)&varargin_1_data[4 * X_idx], &lda_t, &pageY_data[0],
            &ldb_t, &beta1, &tmp_data[0], &ldc_t);
    }
    for (i = 0; i < loop_ub; i++) {
      for (b_p = 0; b_p < 2; b_p++) {
        k = b_p + 2 * i;
        Z_data[k + 2 * loop_ub * ii] = tmp_data[k];
      }
    }
  }
}

/* End of code generation (pagemtimes.c) */
