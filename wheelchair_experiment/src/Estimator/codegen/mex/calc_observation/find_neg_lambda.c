/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * find_neg_lambda.c
 *
 * Code generation for function 'find_neg_lambda'
 *
 */

/* Include files */
#include "find_neg_lambda.h"
#include "calc_observation_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo kj_emlrtRSI = {
    1,                 /* lineNo */
    "find_neg_lambda", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "find_neg_lambda.p" /* pathName */
};

static emlrtBCInfo db_emlrtBCI = {
    1,                 /* iFirst */
    15,                /* iLast */
    1,                 /* lineNo */
    1,                 /* colNo */
    "",                /* aName */
    "find_neg_lambda", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "find_neg_lambda.p", /* pName */
    0                    /* checkKind */
};

/* Function Definitions */
int32_T find_neg_lambda(const emlrtStack *sp, const real_T solution_lambda[15],
                        int32_T workingset_nActiveConstr,
                        const int32_T workingset_nWConstr[5])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T minLambda;
  int32_T a;
  int32_T idx;
  int32_T idxMinLambda;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  idxMinLambda = 0;
  minLambda = 0.0;
  a = (workingset_nWConstr[0] + workingset_nWConstr[1]) + 1;
  st.site = &kj_emlrtRSI;
  if ((a <= workingset_nActiveConstr) &&
      (workingset_nActiveConstr > 2147483646)) {
    b_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (idx = a; idx <= workingset_nActiveConstr; idx++) {
    real_T d;
    if ((idx < 1) || (idx > 15)) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, 15, &db_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    d = solution_lambda[idx - 1];
    if (d < minLambda) {
      minLambda = d;
      idxMinLambda = idx;
    }
  }
  return idxMinLambda;
}

/* End of code generation (find_neg_lambda.c) */
