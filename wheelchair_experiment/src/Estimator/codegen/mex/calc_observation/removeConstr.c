/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * removeConstr.c
 *
 * Code generation for function 'removeConstr'
 *
 */

/* Include files */
#include "removeConstr.h"
#include "calc_observation_data.h"
#include "calc_observation_internal_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ih_emlrtRSI = {
    1,              /* lineNo */
    "removeConstr", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/removeConstr.p" /* pathName */
};

static emlrtRSInfo jh_emlrtRSI = {
    1,                 /* lineNo */
    "moveConstraint_", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/moveConstraint_.p" /* pathName */
};

static emlrtBCInfo wc_emlrtBCI = {
    1,              /* iFirst */
    6,              /* iLast */
    1,              /* lineNo */
    1,              /* colNo */
    "",             /* aName */
    "removeConstr", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/removeConstr.p", /* pName */
    0                             /* checkKind */
};

static emlrtBCInfo xc_emlrtBCI = {
    1,              /* iFirst */
    15,             /* iLast */
    1,              /* lineNo */
    1,              /* colNo */
    "",             /* aName */
    "removeConstr", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/removeConstr.p", /* pName */
    0                             /* checkKind */
};

static emlrtBCInfo yc_emlrtBCI = {
    1,              /* iFirst */
    15,             /* iLast */
    1,              /* lineNo */
    1,              /* colNo */
    "",             /* aName */
    "removeConstr", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/removeConstr.p", /* pName */
    3                             /* checkKind */
};

static emlrtBCInfo ad_emlrtBCI = {
    1,                 /* iFirst */
    15,                /* iLast */
    1,                 /* lineNo */
    1,                 /* colNo */
    "",                /* aName */
    "moveConstraint_", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/moveConstraint_.p", /* pName */
    0                                /* checkKind */
};

static emlrtBCInfo bd_emlrtBCI = {
    1,              /* iFirst */
    5,              /* iLast */
    1,              /* lineNo */
    1,              /* colNo */
    "",             /* aName */
    "removeConstr", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/removeConstr.p", /* pName */
    3                             /* checkKind */
};

/* Function Definitions */
void removeConstr(const emlrtStack *sp, g_struct_T *obj, int32_T idx_global)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T TYPE_tmp;
  int32_T i;
  int32_T idx;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if ((idx_global < 1) || (idx_global > 15)) {
    emlrtDynamicBoundsCheckR2012b(idx_global, 1, 15, &xc_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  TYPE_tmp = obj->Wid[idx_global - 1];
  if ((TYPE_tmp < 1) || (TYPE_tmp > 6)) {
    emlrtDynamicBoundsCheckR2012b(obj->Wid[idx_global - 1], 1, 6, &wc_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  i = (obj->isActiveIdx[TYPE_tmp - 1] + obj->Wlocalidx[idx_global - 1]) - 1;
  if ((i < 1) || (i > 15)) {
    emlrtDynamicBoundsCheckR2012b(i, 1, 15, &yc_emlrtBCI, (emlrtConstCTX)sp);
  }
  obj->isActiveConstr[i - 1] = false;
  if (idx_global < obj->nActiveConstr) {
    int32_T i1;
    st.site = &ih_emlrtRSI;
    if ((obj->nActiveConstr < 1) || (obj->nActiveConstr > 15)) {
      emlrtDynamicBoundsCheckR2012b(obj->nActiveConstr, 1, 15, &ad_emlrtBCI,
                                    &st);
    }
    i = obj->nActiveConstr - 1;
    obj->Wid[idx_global - 1] = obj->Wid[i];
    obj->Wlocalidx[idx_global - 1] = obj->Wlocalidx[i];
    b_st.site = &jh_emlrtRSI;
    if (obj->nVar > 2147483646) {
      c_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    i1 = (uint8_T)obj->nVar;
    for (idx = 0; idx < i1; idx++) {
      obj->ATwset[idx + ((idx_global - 1) << 3)] = obj->ATwset[idx + (i << 3)];
    }
    obj->bwset[idx_global - 1] = obj->bwset[i];
  }
  obj->nActiveConstr--;
  if ((TYPE_tmp < 1) || (TYPE_tmp > 5)) {
    emlrtDynamicBoundsCheckR2012b(TYPE_tmp, 1, 5, &bd_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  obj->nWConstr[TYPE_tmp - 1]--;
}

/* End of code generation (removeConstr.c) */
