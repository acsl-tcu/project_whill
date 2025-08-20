/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * countsort.c
 *
 * Code generation for function 'countsort'
 *
 */

/* Include files */
#include "countsort.h"
#include "eml_int_forloop_overflow_check.h"
#include "pcfitellipse_init_data.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo te_emlrtRSI =
    {
        1,           /* lineNo */
        "countsort", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
        "utils\\countsort.p" /* pathName */
};

static emlrtBCInfo xb_emlrtBCI = {
    1,           /* iFirst */
    13,          /* iLast */
    1,           /* lineNo */
    1,           /* colNo */
    "",          /* aName */
    "countsort", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+utils\\countsort."
    "p", /* pName */
    3    /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = {
    1,           /* iFirst */
    13,          /* iLast */
    1,           /* lineNo */
    1,           /* colNo */
    "",          /* aName */
    "countsort", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+utils\\countsort."
    "p", /* pName */
    0    /* checkKind */
};

/* Function Definitions */
void countsort(const emlrtStack *sp, int32_T x[13], int32_T xLen,
               int32_T workspace[13], int32_T xMin, int32_T xMax)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T idx;
  int32_T idxFill;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((xLen > 1) && (xMax > xMin)) {
    int32_T b_tmp;
    int32_T idxEnd;
    int32_T idxStart;
    b_tmp = (xMax - xMin) + 1;
    st.site = &te_emlrtRSI;
    if (b_tmp > 2147483646) {
      b_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (idx = 0; idx < b_tmp; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > 13)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 13, &xb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      workspace[idx] = 0;
    }
    st.site = &te_emlrtRSI;
    if (xLen > 2147483646) {
      b_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (idx = 0; idx < xLen; idx++) {
      if (idx + 1 > 13) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 13, &yb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      idxStart = (x[idx] - xMin) + 1;
      if ((idxStart < 1) || (idxStart > 13)) {
        emlrtDynamicBoundsCheckR2012b(idxStart, 1, 13, &yb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (idx + 1 > 13) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 13, &yb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if ((idxStart < 1) || (idxStart > 13)) {
        emlrtDynamicBoundsCheckR2012b(idxStart, 1, 13, &xb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      workspace[idxStart - 1]++;
    }
    st.site = &te_emlrtRSI;
    for (idx = 2; idx <= b_tmp; idx++) {
      if (idx > 13) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 13, &xb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      workspace[idx - 1] += workspace[idx - 2];
    }
    idxStart = 1;
    idxEnd = workspace[0];
    st.site = &te_emlrtRSI;
    if (b_tmp - 1 > 2147483646) {
      b_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (idx = 0; idx <= b_tmp - 2; idx++) {
      st.site = &te_emlrtRSI;
      if ((idxStart <= idxEnd) && (idxEnd > 2147483646)) {
        b_st.site = &hb_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (idxFill = idxStart; idxFill <= idxEnd; idxFill++) {
        if ((idxFill < 1) || (idxFill > 13)) {
          emlrtDynamicBoundsCheckR2012b(idxFill, 1, 13, &xb_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        x[idxFill - 1] = idx + xMin;
      }
      if ((idx + 1 < 1) || (idx + 1 > 13)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 13, &yb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      idxStart = workspace[idx] + 1;
      if ((idx + 2 < 1) || (idx + 2 > 13)) {
        emlrtDynamicBoundsCheckR2012b(idx + 2, 1, 13, &yb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      idxEnd = workspace[idx + 1];
    }
    st.site = &te_emlrtRSI;
    if ((idxStart <= idxEnd) && (idxEnd > 2147483646)) {
      b_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (idx = idxStart; idx <= idxEnd; idx++) {
      if ((idx < 1) || (idx > 13)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 13, &xb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      x[idx - 1] = xMax;
    }
  }
}

/* End of code generation (countsort.c) */
