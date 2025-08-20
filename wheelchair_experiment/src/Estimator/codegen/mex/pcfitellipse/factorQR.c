/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * factorQR.c
 *
 * Code generation for function 'factorQR'
 *
 */

/* Include files */
#include "factorQR.h"
#include "eml_int_forloop_overflow_check.h"
#include "pcfitellipse_data.h"
#include "pcfitellipse_internal_types.h"
#include "rt_nonfinite.h"
#include "xcopy.h"
#include "xgeqrf.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtBCInfo ff_emlrtBCI = {
    1,          /* iFirst */
    15,         /* iLast */
    1,          /* lineNo */
    1,          /* colNo */
    "",         /* aName */
    "factorQR", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "QRManager\\factorQR.p", /* pName */
    3                        /* checkKind */
};

/* Function Definitions */
void factorQR(const emlrtStack *sp, g_struct_T *obj, const real_T A[120],
              int32_T mrows, int32_T ncols)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T idx;
  boolean_T guard1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  idx = mrows * ncols;
  guard1 = false;
  if (idx > 0) {
    st.site = &if_emlrtRSI;
    if (ncols > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (idx = 0; idx < ncols; idx++) {
      st.site = &if_emlrtRSI;
      b_xcopy(&st, mrows, A, (idx << 3) + 1, obj->QR, 15 * idx + 1);
    }
    guard1 = true;
  } else if (idx == 0) {
    obj->mrows = mrows;
    obj->ncols = ncols;
    obj->minRowCol = 0;
  } else {
    guard1 = true;
  }
  if (guard1) {
    obj->usedPivoting = false;
    obj->mrows = mrows;
    obj->ncols = ncols;
    st.site = &if_emlrtRSI;
    if (ncols > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (idx = 0; idx < ncols; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > 15)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 15, &ff_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      obj->jpvt[idx] = idx + 1;
    }
    obj->minRowCol = muIntScalarMin_sint32(mrows, ncols);
    st.site = &if_emlrtRSI;
    xgeqrf(&st, obj->QR, mrows, ncols, obj->tau);
  }
}

/* End of code generation (factorQR.c) */
