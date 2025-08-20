/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * unsafeSxfun.c
 *
 * Code generation for function 'unsafeSxfun'
 *
 */

/* Include files */
#include "unsafeSxfun.h"
#include "removePlane_ransac_data.h"
#include "removePlane_ransac_emxutil.h"
#include "removePlane_ransac_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo nb_emlrtRTEI = {
    3,                    /* lineNo */
    36,                   /* colNo */
    "removePlane_ransac", /* fName */
    "C:\\Users\\student\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\g"
    "raduation\\noPrimeEst_ubuntu\\src\\Estimator\\removePlane_ransac.m" /* pName
                                                                          */
};

/* Function Definitions */
void binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1,
                      const emxArray_real_T *in3)
{
  emxArray_real_T *b_in3;
  const real_T *in3_data;
  real_T *b_in3_data;
  real_T *in1_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  in3_data = in3->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in3, 1, &nb_emlrtRTEI);
  if (in1->size[0] == 1) {
    loop_ub = in3->size[0];
  } else {
    loop_ub = in1->size[0];
  }
  i = b_in3->size[0];
  b_in3->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, b_in3, i, &nb_emlrtRTEI);
  b_in3_data = b_in3->data;
  stride_0_0 = (in3->size[0] != 1);
  stride_1_0 = (in1->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in3_data[i] =
        in3_data[i * stride_0_0 + in3->size[0]] - in1_data[i * stride_1_0];
  }
  i = in1->size[0];
  in1->size[0] = b_in3->size[0];
  emxEnsureCapacity_real_T(sp, in1, i, &jb_emlrtRTEI);
  in1_data = in1->data;
  loop_ub = b_in3->size[0];
  for (i = 0; i < loop_ub; i++) {
    real_T varargin_1;
    varargin_1 = b_in3_data[i];
    in1_data[i] = varargin_1 * varargin_1;
  }
  emxFree_real_T(sp, &b_in3);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (unsafeSxfun.c) */
