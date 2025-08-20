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
#include "mexLidarTracker_emxutil.h"
#include "mexLidarTracker_types.h"
#include "mod.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRTEInfo fd_emlrtRTEI = {
    225,          /* lineNo */
    23,           /* colNo */
    "expand_mod", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/ixfun.m" /* pName
                                                                         */
};

static emlrtRTEInfo jn_emlrtRTEI = {
    234,     /* lineNo */
    20,      /* colNo */
    "ixfun", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/ixfun.m" /* pName
                                                                         */
};

/* Function Definitions */
void expand_mod(const emlrtStack *sp, const emxArray_real_T *a,
                const real_T b_data[], int32_T b_size, emxArray_real_T *c)
{
  const real_T *a_data;
  real_T *c_data;
  int32_T b_k;
  int32_T i;
  int32_T k;
  int32_T sak;
  a_data = a->data;
  sak = a->size[0];
  if (b_size == 1) {
    sak = a->size[0];
  } else if (a->size[0] == 1) {
    sak = b_size;
  } else {
    sak = muIntScalarMin_sint32(sak, b_size);
    if (a->size[0] != b_size) {
      emlrtErrorWithMessageIdR2018a(sp, &fd_emlrtRTEI,
                                    "MATLAB:sizeDimensionsMustMatch",
                                    "MATLAB:sizeDimensionsMustMatch", 0);
    }
  }
  i = c->size[0] * c->size[1];
  c->size[0] = sak;
  c->size[1] = a->size[1];
  emxEnsureCapacity_real_T(sp, c, i, &jn_emlrtRTEI);
  c_data = c->data;
  if ((sak != 0) && (a->size[1] != 0)) {
    boolean_T b;
    boolean_T b1;
    i = a->size[1] - 1;
    b = (a->size[0] != 1);
    b1 = (b_size != 1);
    for (k = 0; k <= i; k++) {
      sak = c->size[0] - 1;
      for (b_k = 0; b_k <= sak; b_k++) {
        c_data[b_k + c->size[0] * k] =
            b_mod(a_data[b * b_k + a->size[0] * k], b_data[b1 * b_k]);
      }
    }
  }
}

/* End of code generation (ixfun.c) */
