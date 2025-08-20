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
#include "pcfitellipse_init_data.h"
#include "pcfitellipse_init_internal_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo fh_emlrtRSI = {
    1,                /* lineNo */
    "addAineqConstr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\addAineqConstr.p" /* pathName */
};

static emlrtBCInfo md_emlrtBCI = {
    1,                /* iFirst */
    1,                /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "addAineqConstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\addAineqConstr.p", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo nd_emlrtBCI = {
    1,                /* iFirst */
    13,               /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "addAineqConstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\addAineqConstr.p", /* pName */
    3                               /* checkKind */
};

static emlrtBCInfo pd_emlrtBCI = {
    1,                /* iFirst */
    7,                /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "addAineqConstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\addAineqConstr.p", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo qd_emlrtBCI = {
    1,                /* iFirst */
    91,               /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "addAineqConstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\addAineqConstr.p", /* pName */
    3                               /* checkKind */
};

/* Function Definitions */
void addAineqConstr(const emlrtStack *sp, i_struct_T *obj, int32_T idx_local)
{
  emlrtStack st;
  int32_T i;
  int32_T i1;
  int32_T iAineq0;
  int32_T iAw0;
  int32_T idx;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &fh_emlrtRSI;
  obj->nWConstr[2]++;
  i = (obj->isActiveIdx[2] + idx_local) - 1;
  if ((i < 1) || (i > 13)) {
    emlrtDynamicBoundsCheckR2012b(i, 1, 13, &od_emlrtBCI, &st);
  }
  obj->isActiveConstr[i - 1] = true;
  obj->nActiveConstr++;
  if ((obj->nActiveConstr < 1) || (obj->nActiveConstr > 13)) {
    emlrtDynamicBoundsCheckR2012b(obj->nActiveConstr, 1, 13, &od_emlrtBCI, &st);
  }
  i = obj->nActiveConstr - 1;
  obj->Wid[i] = 3;
  obj->Wlocalidx[i] = idx_local;
  iAineq0 = 7 * (idx_local - 1) + 1;
  iAw0 = 7 * i + 1;
  i1 = obj->nVar - 1;
  for (idx = 0; idx <= i1; idx++) {
    int32_T i2;
    int32_T i3;
    i2 = iAineq0 + idx;
    if ((i2 < 1) || (i2 > 7)) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, 7, &pd_emlrtBCI, (emlrtConstCTX)sp);
    }
    i3 = iAw0 + idx;
    if ((i3 < 1) || (i3 > 91)) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, 91, &qd_emlrtBCI, (emlrtConstCTX)sp);
    }
    obj->ATwset[i3 - 1] = obj->Aineq[i2 - 1];
  }
  if ((idx_local < 1) || (idx_local > 1)) {
    emlrtDynamicBoundsCheckR2012b(idx_local, 1, 1, &md_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  if ((obj->nActiveConstr < 1) || (obj->nActiveConstr > 13)) {
    emlrtDynamicBoundsCheckR2012b(obj->nActiveConstr, 1, 13, &nd_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  obj->bwset[i] = obj->bineq;
}

/* End of code generation (addAineqConstr.c) */
