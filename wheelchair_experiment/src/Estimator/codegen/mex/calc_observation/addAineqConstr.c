/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * addAineqConstr.c
 *
 * Code generation for function 'addAineqConstr'
 *
 */

/* Include files */
#include "addAineqConstr.h"
#include "calc_observation_data.h"
#include "calc_observation_internal_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo mj_emlrtRSI = {
    1,                /* lineNo */
    "addAineqConstr", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/addAineqConstr.p" /* pathName */
};

static emlrtBCInfo qe_emlrtBCI = {
    1,                /* iFirst */
    2,                /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "addAineqConstr", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/addAineqConstr.p", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo re_emlrtBCI = {
    1,                /* iFirst */
    15,               /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "addAineqConstr", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/addAineqConstr.p", /* pName */
    3                               /* checkKind */
};

static emlrtBCInfo se_emlrtBCI = {
    1,                /* iFirst */
    16,               /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "addAineqConstr", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/addAineqConstr.p", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo te_emlrtBCI = {
    1,                /* iFirst */
    120,              /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "addAineqConstr", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/addAineqConstr.p", /* pName */
    3                               /* checkKind */
};

/* Function Definitions */
void addAineqConstr(const emlrtStack *sp, g_struct_T *obj, int32_T idx_local)
{
  emlrtStack st;
  int32_T i;
  int32_T i1;
  int32_T iAineq0;
  int32_T iAw0;
  int32_T idx;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &mj_emlrtRSI;
  obj->nWConstr[2]++;
  i = (obj->isActiveIdx[2] + idx_local) - 1;
  if ((i < 1) || (i > 15)) {
    emlrtDynamicBoundsCheckR2012b(i, 1, 15, &pe_emlrtBCI, &st);
  }
  obj->isActiveConstr[i - 1] = true;
  obj->nActiveConstr++;
  if ((obj->nActiveConstr < 1) || (obj->nActiveConstr > 15)) {
    emlrtDynamicBoundsCheckR2012b(obj->nActiveConstr, 1, 15, &pe_emlrtBCI, &st);
  }
  i = obj->nActiveConstr - 1;
  obj->Wid[i] = 3;
  obj->Wlocalidx[i] = idx_local;
  iAineq0 = ((idx_local - 1) << 3) + 1;
  iAw0 = (i << 3) + 1;
  i1 = obj->nVar;
  for (idx = 0; idx < i1; idx++) {
    int32_T i2;
    int32_T i3;
    i2 = iAineq0 + idx;
    if ((i2 < 1) || (i2 > 16)) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, 16, &se_emlrtBCI, (emlrtConstCTX)sp);
    }
    i3 = iAw0 + idx;
    if ((i3 < 1) || (i3 > 120)) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, 120, &te_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    obj->ATwset[i3 - 1] = obj->Aineq[i2 - 1];
  }
  if ((idx_local < 1) || (idx_local > 2)) {
    emlrtDynamicBoundsCheckR2012b(idx_local, 1, 2, &qe_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  if ((obj->nActiveConstr < 1) || (obj->nActiveConstr > 15)) {
    emlrtDynamicBoundsCheckR2012b(obj->nActiveConstr, 1, 15, &re_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  obj->bwset[i] = obj->bineq[idx_local - 1];
}

/* End of code generation (addAineqConstr.c) */
