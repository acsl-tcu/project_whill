/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * repmat.c
 *
 * Code generation for function 'repmat'
 *
 */

/* Include files */
#include "repmat.h"
#include "assertValidSizeArg.h"
#include "eml_int_forloop_overflow_check.h"
#include "removePlane_BBox_data.h"
#include "removePlane_BBox_emxutil.h"
#include "removePlane_BBox_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void repmat(const emlrtStack *sp, const real_T a[91],
            const real_T varargin_1[2], emxArray_real_T *b)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T *b_data;
  int32_T i;
  int32_T ibmat;
  int32_T itilerow;
  int32_T jcol;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &n_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  assertValidSizeArg(&st, varargin_1);
  i = (int32_T)varargin_1[0];
  ibmat = b->size[0] * b->size[1];
  b->size[0] = (int32_T)varargin_1[0];
  b->size[1] = 91;
  emxEnsureCapacity_real_T(sp, b, ibmat, &ab_emlrtRTEI);
  b_data = b->data;
  overflow = ((int32_T)varargin_1[0] > 2147483646);
  for (jcol = 0; jcol < 91; jcol++) {
    ibmat = jcol * i;
    st.site = &p_emlrtRSI;
    if (overflow) {
      b_st.site = &r_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (itilerow = 0; itilerow < i; itilerow++) {
      b_data[ibmat + itilerow] = a[jcol];
    }
  }
}

/* End of code generation (repmat.c) */
