/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * initActiveSet.c
 *
 * Code generation for function 'initActiveSet'
 *
 */

/* Include files */
#include "initActiveSet.h"
#include "calc_observation_data.h"
#include "calc_observation_internal_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ef_emlrtRSI = {
    1,               /* lineNo */
    "initActiveSet", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/initActiveSet.p" /* pathName */
};

static emlrtBCInfo pf_emlrtBCI = {
    1,               /* iFirst */
    15,              /* iLast */
    1,               /* lineNo */
    1,               /* colNo */
    "",              /* aName */
    "initActiveSet", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/initActiveSet.p", /* pName */
    3                              /* checkKind */
};

static emlrtBCInfo qf_emlrtBCI = {
    1,               /* iFirst */
    120,             /* iLast */
    1,               /* lineNo */
    1,               /* colNo */
    "",              /* aName */
    "initActiveSet", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/initActiveSet.p", /* pName */
    3                              /* checkKind */
};

static emlrtBCInfo rf_emlrtBCI = {
    1,               /* iFirst */
    8,               /* iLast */
    1,               /* lineNo */
    1,               /* colNo */
    "",              /* aName */
    "initActiveSet", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/initActiveSet.p", /* pName */
    0                              /* checkKind */
};

/* Function Definitions */
void initActiveSet(const emlrtStack *sp, g_struct_T *obj)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T i;
  int32_T idx;
  int32_T idxFillStart;
  int32_T idx_local;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ef_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  setProblemType(&st, obj, 3);
  idxFillStart = obj->isActiveIdx[2];
  st.site = &ef_emlrtRSI;
  for (idx = idxFillStart; idx < 16; idx++) {
    if (idx < 1) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, 15, &pf_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    obj->isActiveConstr[idx - 1] = false;
  }
  obj->nWConstr[0] = obj->sizes[0];
  obj->nWConstr[1] = 0;
  obj->nWConstr[2] = 0;
  obj->nWConstr[3] = 0;
  obj->nWConstr[4] = 0;
  obj->nActiveConstr = obj->nWConstr[0];
  st.site = &ef_emlrtRSI;
  if (obj->sizes[0] > 2147483646) {
    b_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)obj->sizes[0];
  for (idx_local = 0; idx_local < i; idx_local++) {
    int32_T colOffsetATw;
    obj->Wid[idx_local] = 1;
    obj->Wlocalidx[idx_local] = idx_local + 1;
    obj->isActiveConstr[idx_local] = true;
    colOffsetATw = idx_local << 3;
    idxFillStart = obj->indexFixed[idx_local];
    st.site = &ef_emlrtRSI;
    if (obj->indexFixed[idx_local] - 1 > 2147483646) {
      b_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    if (idxFillStart - 2 >= 0) {
      memset(&obj->ATwset[colOffsetATw], 0,
             (uint32_T)(idxFillStart - 1) * sizeof(real_T));
    }
    idxFillStart = obj->indexFixed[idx_local] + colOffsetATw;
    if ((idxFillStart < 1) || (idxFillStart > 120)) {
      emlrtDynamicBoundsCheckR2012b(idxFillStart, 1, 120, &qf_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    obj->ATwset[idxFillStart - 1] = 1.0;
    idx = obj->indexFixed[idx_local] + 1;
    idxFillStart = obj->nVar;
    st.site = &ef_emlrtRSI;
    if ((obj->indexFixed[idx_local] + 1 <= obj->nVar) &&
        (obj->nVar > 2147483646)) {
      b_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    if (idx <= idxFillStart) {
      memset(&obj->ATwset[(idx + colOffsetATw) + -1], 0,
             (uint32_T)((((idxFillStart + colOffsetATw) - idx) - colOffsetATw) +
                        1) *
                 sizeof(real_T));
    }
    if ((obj->indexFixed[idx_local] < 1) || (obj->indexFixed[idx_local] > 8)) {
      emlrtDynamicBoundsCheckR2012b(obj->indexFixed[idx_local], 1, 8,
                                    &rf_emlrtBCI, (emlrtConstCTX)sp);
    }
    obj->bwset[idx_local] = obj->ub[obj->indexFixed[idx_local] - 1];
  }
  st.site = &ef_emlrtRSI;
}

/* End of code generation (initActiveSet.c) */
