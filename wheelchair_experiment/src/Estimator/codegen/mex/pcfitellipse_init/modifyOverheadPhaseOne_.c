/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * modifyOverheadPhaseOne_.c
 *
 * Code generation for function 'modifyOverheadPhaseOne_'
 *
 */

/* Include files */
#include "modifyOverheadPhaseOne_.h"
#include "eml_int_forloop_overflow_check.h"
#include "pcfitellipse_init_data.h"
#include "pcfitellipse_init_internal_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo sc_emlrtRSI = {
    1,                         /* lineNo */
    "modifyOverheadPhaseOne_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\modifyOverheadPhaseOne_.p" /* pathName */
};

static emlrtBCInfo s_emlrtBCI = {
    1,                         /* iFirst */
    91,                        /* iLast */
    1,                         /* lineNo */
    1,                         /* colNo */
    "",                        /* aName */
    "modifyOverheadPhaseOne_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\modifyOverheadPhaseOne_.p", /* pName */
    3                                        /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = {
    1,                         /* iFirst */
    7,                         /* iLast */
    1,                         /* lineNo */
    1,                         /* colNo */
    "",                        /* aName */
    "modifyOverheadPhaseOne_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\modifyOverheadPhaseOne_.p", /* pName */
    3                                        /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = {
    1,                         /* iFirst */
    13,                        /* iLast */
    1,                         /* lineNo */
    1,                         /* colNo */
    "",                        /* aName */
    "modifyOverheadPhaseOne_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\modifyOverheadPhaseOne_.p", /* pName */
    3                                        /* checkKind */
};

/* Function Definitions */
void modifyOverheadPhaseOne_(const emlrtStack *sp, i_struct_T *obj)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T b;
  int32_T i;
  int32_T idx;
  int32_T idxStartIneq;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &sc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (obj->sizes[0] > 2147483646) {
    b_st.site = &hb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)obj->sizes[0];
  for (idx = 0; idx < i; idx++) {
    obj->ATwset[(obj->nVar + 7 * idx) - 1] = 0.0;
  }
  st.site = &sc_emlrtRSI;
  st.site = &sc_emlrtRSI;
  i = obj->nVar - 1;
  obj->Aineq[i] = -1.0;
  if ((obj->sizes[3] < 1) || (obj->sizes[3] > 7)) {
    emlrtDynamicBoundsCheckR2012b(obj->sizes[3], 1, 7, &t_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  obj->indexLB[obj->sizes[3] - 1] = obj->nVar;
  obj->lb[i] = 1.0E-5;
  idxStartIneq = obj->isActiveIdx[2];
  b = obj->nActiveConstr;
  st.site = &sc_emlrtRSI;
  if ((obj->isActiveIdx[2] <= obj->nActiveConstr) &&
      (obj->nActiveConstr > 2147483646)) {
    b_st.site = &hb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (idx = idxStartIneq; idx <= b; idx++) {
    i = obj->nVar + 7 * (idx - 1);
    if ((i < 1) || (i > 91)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 91, &s_emlrtBCI, (emlrtConstCTX)sp);
    }
    obj->ATwset[i - 1] = -1.0;
  }
  if (obj->nWConstr[4] > 0) {
    st.site = &sc_emlrtRSI;
    if (obj->sizesNormal[4] + 1 > 2147483646) {
      b_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    i = (uint8_T)(obj->sizesNormal[4] + 1);
    for (idx = 0; idx < i; idx++) {
      idxStartIneq = obj->isActiveIdx[4] + idx;
      if ((idxStartIneq < 1) || (idxStartIneq > 13)) {
        emlrtDynamicBoundsCheckR2012b(idxStartIneq, 1, 13, &u_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      obj->isActiveConstr[idxStartIneq - 1] = false;
    }
  }
  i = obj->isActiveIdx[4] - 1;
  if ((i < 1) || (i > 13)) {
    emlrtDynamicBoundsCheckR2012b(i, 1, 13, &u_emlrtBCI, (emlrtConstCTX)sp);
  }
  obj->isActiveConstr[i - 1] = false;
}

/* End of code generation (modifyOverheadPhaseOne_.c) */
