/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ixfun.c
 *
 * Code generation for function 'ixfun'
 *
 */

/* Include files */
#include "ixfun.h"
#include "EvaluationPath_vec_emxutil.h"
#include "EvaluationPath_vec_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRTEInfo k_emlrtRTEI = {
    225,            /* lineNo */
    23,             /* colNo */
    "expand_atan2", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/ixfun.m" /* pName
                                                                         */
};

static emlrtRTEInfo p_emlrtRTEI = {
    225,          /* lineNo */
    23,           /* colNo */
    "expand_min", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/ixfun.m" /* pName
                                                                         */
};

static emlrtRTEInfo wh_emlrtRTEI = {
    234,     /* lineNo */
    20,      /* colNo */
    "ixfun", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/ixfun.m" /* pName
                                                                         */
};

/* Function Definitions */
void expand_atan2(const emlrtStack *sp, const emxArray_real_T *a,
                  const emxArray_real_T *b, emxArray_real_T *c)
{
  const real_T *a_data;
  const real_T *b_data;
  real_T *c_data;
  int32_T b_k;
  int32_T c_k;
  int32_T csz_idx_0;
  int32_T csz_idx_2;
  int32_T csz_idx_3;
  int32_T i;
  int32_T k;
  int32_T sak;
  int32_T sbk_tmp;
  boolean_T dimagree;
  b_data = b->data;
  a_data = a->data;
  dimagree = true;
  sak = a->size[0];
  sbk_tmp = b->size[0];
  if (b->size[0] == 1) {
    csz_idx_0 = a->size[0];
  } else if (a->size[0] == 1) {
    csz_idx_0 = b->size[0];
  } else {
    csz_idx_0 = muIntScalarMin_sint32(sak, sbk_tmp);
    dimagree = (a->size[0] == b->size[0]);
  }
  sak = a->size[2];
  sbk_tmp = b->size[2];
  if (b->size[2] == 1) {
    csz_idx_2 = a->size[2];
  } else if (a->size[2] == 1) {
    csz_idx_2 = b->size[2];
  } else {
    csz_idx_2 = muIntScalarMin_sint32(sak, sbk_tmp);
    if ((!dimagree) || (a->size[2] != b->size[2])) {
      dimagree = false;
    }
  }
  sak = a->size[3];
  sbk_tmp = b->size[3];
  if (b->size[3] == 1) {
    csz_idx_3 = a->size[3];
  } else if (a->size[3] == 1) {
    csz_idx_3 = b->size[3];
  } else {
    csz_idx_3 = muIntScalarMin_sint32(sak, sbk_tmp);
    if ((!dimagree) || (a->size[3] != b->size[3])) {
      dimagree = false;
    }
  }
  if (!dimagree) {
    emlrtErrorWithMessageIdR2018a(sp, &k_emlrtRTEI,
                                  "MATLAB:sizeDimensionsMustMatch",
                                  "MATLAB:sizeDimensionsMustMatch", 0);
  }
  i = c->size[0] * c->size[1] * c->size[2] * c->size[3];
  c->size[0] = csz_idx_0;
  c->size[1] = 1;
  c->size[2] = csz_idx_2;
  c->size[3] = csz_idx_3;
  emxEnsureCapacity_real_T(sp, c, i, &wh_emlrtRTEI);
  c_data = c->data;
  if ((csz_idx_0 != 0) && (csz_idx_2 != 0) && (csz_idx_3 != 0)) {
    boolean_T b1;
    boolean_T b2;
    boolean_T b3;
    boolean_T b4;
    boolean_T b_b;
    dimagree = (a->size[3] != 1);
    b_b = (b->size[3] != 1);
    b1 = (a->size[2] != 1);
    b2 = (b->size[2] != 1);
    b3 = (a->size[0] != 1);
    b4 = (b->size[0] != 1);
    for (k = 0; k < csz_idx_3; k++) {
      sak = dimagree * k;
      sbk_tmp = b_b * k;
      i = c->size[2];
      for (b_k = 0; b_k < i; b_k++) {
        int32_T i1;
        csz_idx_2 = b1 * b_k;
        csz_idx_0 = b2 * b_k;
        i1 = c->size[0];
        for (c_k = 0; c_k < i1; c_k++) {
          c_data[(c_k + c->size[0] * b_k) + c->size[0] * c->size[2] * k] =
              muDoubleScalarAtan2(a_data[(b3 * c_k + a->size[0] * csz_idx_2) +
                                         a->size[0] * a->size[2] * sak],
                                  b_data[(b4 * c_k + b->size[0] * csz_idx_0) +
                                         b->size[0] * b->size[2] * sbk_tmp]);
        }
      }
    }
  }
}

void expand_min(const emlrtStack *sp, const emxArray_real_T *a,
                const emxArray_real_T *b, emxArray_real_T *c)
{
  const real_T *a_data;
  const real_T *b_data;
  real_T *c_data;
  int32_T csz_idx_2;
  int32_T csz_idx_3;
  int32_T i;
  int32_T k;
  int32_T sak;
  int32_T sbk_tmp;
  boolean_T dimagree;
  b_data = b->data;
  a_data = a->data;
  dimagree = true;
  sak = a->size[2];
  sbk_tmp = b->size[2];
  if (b->size[2] == 1) {
    csz_idx_2 = a->size[2];
  } else if (a->size[2] == 1) {
    csz_idx_2 = b->size[2];
  } else {
    csz_idx_2 = muIntScalarMin_sint32(sak, sbk_tmp);
    dimagree = (a->size[2] == b->size[2]);
  }
  sak = a->size[3];
  sbk_tmp = b->size[3];
  if (b->size[3] == 1) {
    csz_idx_3 = a->size[3];
  } else if (a->size[3] == 1) {
    csz_idx_3 = b->size[3];
  } else {
    csz_idx_3 = muIntScalarMin_sint32(sak, sbk_tmp);
    if ((!dimagree) || (a->size[3] != b->size[3])) {
      dimagree = false;
    }
  }
  if (!dimagree) {
    emlrtErrorWithMessageIdR2018a(sp, &p_emlrtRTEI,
                                  "MATLAB:sizeDimensionsMustMatch",
                                  "MATLAB:sizeDimensionsMustMatch", 0);
  }
  i = c->size[0] * c->size[1] * c->size[2] * c->size[3];
  c->size[0] = 1;
  c->size[1] = 1;
  c->size[2] = csz_idx_2;
  c->size[3] = csz_idx_3;
  emxEnsureCapacity_real_T(sp, c, i, &wh_emlrtRTEI);
  c_data = c->data;
  if ((csz_idx_2 != 0) && (csz_idx_3 != 0)) {
    boolean_T b1;
    boolean_T b2;
    boolean_T b_b;
    dimagree = (a->size[3] != 1);
    b_b = (b->size[3] != 1);
    b1 = (a->size[2] != 1);
    b2 = (b->size[2] != 1);
    for (csz_idx_2 = 0; csz_idx_2 < csz_idx_3; csz_idx_2++) {
      sak = dimagree * csz_idx_2;
      sbk_tmp = b_b * csz_idx_2;
      i = c->size[2];
      for (k = 0; k < i; k++) {
        c_data[k + c->size[2] * csz_idx_2] =
            muDoubleScalarMin(a_data[b1 * k + a->size[2] * sak],
                              b_data[b2 * k + b->size[2] * sbk_tmp]);
      }
    }
  }
}

/* End of code generation (ixfun.c) */
