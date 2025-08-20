/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pagetranspose.c
 *
 * Code generation for function 'pagetranspose'
 *
 */

/* Include files */
#include "pagetranspose.h"
#include "EvaluationPath_data.h"
#include "EvaluationPath_emxutil.h"
#include "EvaluationPath_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo w_emlrtRSI = {
    8,               /* lineNo */
    "pagetranspose", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/pagetranspose.m" /* pathName
                                                                           */
};

static emlrtRTEInfo ac_emlrtRTEI = {
    8,               /* lineNo */
    1,               /* colNo */
    "pagetranspose", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/pagetranspose.m" /* pName
                                                                           */
};

/* Function Definitions */
void pagetranspose(const emlrtStack *sp, const emxArray_real_T *x,
                   emxArray_real_T *y)
{
  static const int8_T b_iv[4] = {2, 1, 3, 4};
  emlrtStack st;
  const real_T *x_data;
  real_T *y_data;
  int32_T b_k;
  int32_T c_k;
  int32_T d_k;
  int32_T k;
  int32_T plast;
  int16_T subsa_idx_3;
  boolean_T b;
  st.prev = sp;
  st.tls = sp->tls;
  x_data = x->data;
  st.site = &w_emlrtRSI;
  b = true;
  if (x->size[2] != 0) {
    boolean_T exitg1;
    plast = 0;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (x->size[b_iv[k] - 1] != 1) {
        if (plast > b_iv[k]) {
          b = false;
          exitg1 = true;
        } else {
          plast = b_iv[k];
          k++;
        }
      } else {
        k++;
      }
    }
  }
  if (b) {
    b_k = y->size[0] * y->size[1] * y->size[2] * y->size[3];
    y->size[0] = 4;
    y->size[1] = 6;
    y->size[2] = x->size[2];
    y->size[3] = 1000;
    emxEnsureCapacity_real_T(&st, y, b_k, &ac_emlrtRTEI);
    y_data = y->data;
    plast = 24 * x->size[2] * 1000;
    for (b_k = 0; b_k < plast; b_k++) {
      y_data[b_k] = x_data[b_k];
    }
  } else {
    b_k = y->size[0] * y->size[1] * y->size[2] * y->size[3];
    y->size[0] = 4;
    y->size[1] = 6;
    plast = x->size[2];
    y->size[2] = x->size[2];
    y->size[3] = 1000;
    emxEnsureCapacity_real_T(&st, y, b_k, &bc_emlrtRTEI);
    y_data = y->data;
    for (k = 0; k < 1000; k++) {
      if (plast - 1 >= 0) {
        subsa_idx_3 = (int16_T)(k + 1);
      }
      for (b_k = 0; b_k < plast; b_k++) {
        for (c_k = 0; c_k < 4; c_k++) {
          for (d_k = 0; d_k < 6; d_k++) {
            y_data[((c_k + 4 * d_k) + 24 * b_k) +
                   24 * y->size[2] * (subsa_idx_3 - 1)] =
                x_data[((d_k + 6 * c_k) + 24 * b_k) +
                       24 * x->size[2] * (subsa_idx_3 - 1)];
          }
        }
      }
    }
  }
}

/* End of code generation (pagetranspose.c) */
