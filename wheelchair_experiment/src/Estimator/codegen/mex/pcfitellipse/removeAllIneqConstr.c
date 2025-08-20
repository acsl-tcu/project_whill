/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * removeAllIneqConstr.c
 *
 * Code generation for function 'removeAllIneqConstr'
 *
 */

/* Include files */
#include "removeAllIneqConstr.h"
#include "eml_int_forloop_overflow_check.h"
#include "pcfitellipse_data.h"
#include "pcfitellipse_internal_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo xf_emlrtRSI = {
    1,                     /* lineNo */
    "removeAllIneqConstr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\removeAllIneqConstr.p" /* pathName */
};

static emlrtBCInfo qc_emlrtBCI = {
    1,                     /* iFirst */
    15,                    /* iLast */
    1,                     /* lineNo */
    1,                     /* colNo */
    "",                    /* aName */
    "removeAllIneqConstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\removeAllIneqConstr.p", /* pName */
    0                                    /* checkKind */
};

static emlrtBCInfo rc_emlrtBCI = {
    1,                     /* iFirst */
    6,                     /* iLast */
    1,                     /* lineNo */
    1,                     /* colNo */
    "",                    /* aName */
    "removeAllIneqConstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\removeAllIneqConstr.p", /* pName */
    0                                    /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = {
    1,                     /* iFirst */
    15,                    /* iLast */
    1,                     /* lineNo */
    1,                     /* colNo */
    "",                    /* aName */
    "removeAllIneqConstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\removeAllIneqConstr.p", /* pName */
    3                                    /* checkKind */
};

/* Function Definitions */
void removeAllIneqConstr(const emlrtStack *sp, k_struct_T *obj)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T idxEndIneq;
  int32_T idxStartIneq;
  int32_T idxStartIneq_tmp;
  int32_T idx_global;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  idxStartIneq_tmp = obj->nWConstr[0] + obj->nWConstr[1];
  idxStartIneq = idxStartIneq_tmp + 1;
  idxEndIneq = obj->nActiveConstr;
  st.site = &xf_emlrtRSI;
  if ((idxStartIneq_tmp + 1 <= obj->nActiveConstr) &&
      (obj->nActiveConstr > 2147483646)) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (idx_global = idxStartIneq; idx_global <= idxEndIneq; idx_global++) {
    int32_T i;
    if ((idx_global < 1) || (idx_global > 15)) {
      emlrtDynamicBoundsCheckR2012b(idx_global, 1, 15, &qc_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i = obj->Wid[idx_global - 1];
    if ((i < 1) || (i > 6)) {
      emlrtDynamicBoundsCheckR2012b(obj->Wid[idx_global - 1], 1, 6,
                                    &rc_emlrtBCI, (emlrtConstCTX)sp);
    }
    i = (obj->isActiveIdx[i - 1] + obj->Wlocalidx[idx_global - 1]) - 1;
    if ((i < 1) || (i > 15)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 15, &sc_emlrtBCI, (emlrtConstCTX)sp);
    }
    obj->isActiveConstr[i - 1] = false;
  }
  obj->nWConstr[2] = 0;
  obj->nWConstr[3] = 0;
  obj->nWConstr[4] = 0;
  obj->nActiveConstr = idxStartIneq_tmp;
}

/* End of code generation (removeAllIneqConstr.c) */
