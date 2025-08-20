/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sortLambdaQP.c
 *
 * Code generation for function 'sortLambdaQP'
 *
 */

/* Include files */
#include "sortLambdaQP.h"
#include "eml_int_forloop_overflow_check.h"
#include "pcfitellipse_data.h"
#include "rt_nonfinite.h"
#include "xcopy.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ne_emlrtRSI = {
    1,              /* lineNo */
    "sortLambdaQP", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "parseoutput\\sortLambdaQP.p" /* pathName */
};

static emlrtBCInfo db_emlrtBCI = {
    1,              /* iFirst */
    15,             /* iLast */
    1,              /* lineNo */
    1,              /* colNo */
    "",             /* aName */
    "sortLambdaQP", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "parseoutput\\sortLambdaQP.p", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = {
    1,              /* iFirst */
    120,            /* iLast */
    1,              /* lineNo */
    1,              /* colNo */
    "",             /* aName */
    "sortLambdaQP", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "parseoutput\\sortLambdaQP.p", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = {
    1,              /* iFirst */
    15,             /* iLast */
    1,              /* lineNo */
    1,              /* colNo */
    "",             /* aName */
    "sortLambdaQP", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "parseoutput\\sortLambdaQP.p", /* pName */
    3                              /* checkKind */
};

/* Function Definitions */
void sortLambdaQP(const emlrtStack *sp, real_T lambda[15],
                  int32_T WorkingSet_nActiveConstr,
                  const int32_T WorkingSet_sizes[5],
                  const int32_T WorkingSet_isActiveIdx[6],
                  const int32_T WorkingSet_Wid[15],
                  const int32_T WorkingSet_Wlocalidx[15], real_T workspace[120])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if (WorkingSet_nActiveConstr != 0) {
    int32_T currentMplier;
    int32_T i;
    int32_T idx;
    int32_T mAll;
    boolean_T exitg1;
    mAll =
        ((WorkingSet_sizes[0] + WorkingSet_sizes[3]) + WorkingSet_sizes[4]) + 2;
    st.site = &ne_emlrtRSI;
    b_st.site = &wc_emlrtRSI;
    c_st.site = &xc_emlrtRSI;
    if (mAll > 2147483646) {
      d_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    i = (uint8_T)mAll;
    memcpy(&workspace[0], &lambda[0], (uint32_T)i * sizeof(real_T));
    st.site = &ne_emlrtRSI;
    g_xcopy(&st, mAll, lambda);
    currentMplier = 1;
    idx = 1;
    exitg1 = false;
    while ((!exitg1) && (idx <= WorkingSet_nActiveConstr)) {
      if (idx > 15) {
        emlrtDynamicBoundsCheckR2012b(16, 1, 15, &db_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      i = WorkingSet_Wid[idx - 1];
      if (i <= 2) {
        if (currentMplier > 120) {
          emlrtDynamicBoundsCheckR2012b(121, 1, 120, &eb_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (i == 1) {
          i = 0;
        } else {
          i = WorkingSet_isActiveIdx[1] - 1;
        }
        i += WorkingSet_Wlocalidx[idx - 1];
        if ((i < 1) || (i > 15)) {
          emlrtDynamicBoundsCheckR2012b(i, 1, 15, &fb_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        lambda[i - 1] = workspace[currentMplier - 1];
        currentMplier++;
        idx++;
      } else {
        exitg1 = true;
      }
    }
    while (idx <= WorkingSet_nActiveConstr) {
      if (idx > 15) {
        emlrtDynamicBoundsCheckR2012b(16, 1, 15, &db_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      switch (WorkingSet_Wid[idx - 1]) {
      case 3:
        mAll = WorkingSet_isActiveIdx[2];
        break;
      case 4:
        mAll = WorkingSet_isActiveIdx[3];
        break;
      default:
        mAll = WorkingSet_isActiveIdx[4];
        break;
      }
      if (currentMplier > 120) {
        emlrtDynamicBoundsCheckR2012b(121, 1, 120, &eb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      i = (mAll + WorkingSet_Wlocalidx[idx - 1]) - 1;
      if ((i < 1) || (i > 15)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 15, &fb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      lambda[i - 1] = workspace[currentMplier - 1];
      currentMplier++;
      idx++;
    }
  }
}

/* End of code generation (sortLambdaQP.c) */
