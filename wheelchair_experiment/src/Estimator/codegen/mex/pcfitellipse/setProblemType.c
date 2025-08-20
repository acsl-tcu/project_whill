/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * setProblemType.c
 *
 * Code generation for function 'setProblemType'
 *
 */

/* Include files */
#include "setProblemType.h"
#include "eml_int_forloop_overflow_check.h"
#include "modifyOverheadPhaseOne_.h"
#include "pcfitellipse_data.h"
#include "pcfitellipse_internal_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ad_emlrtRSI = {
    1,                /* lineNo */
    "setProblemType", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\setProblemType.p" /* pathName */
};

static emlrtRSInfo cd_emlrtRSI = {
    1,                            /* lineNo */
    "modifyOverheadRegularized_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\modifyOverheadRegularized_.p" /* pathName */
};

static emlrtBCInfo s_emlrtBCI = {
    1,                            /* iFirst */
    120,                          /* iLast */
    1,                            /* lineNo */
    1,                            /* colNo */
    "",                           /* aName */
    "modifyOverheadRegularized_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\modifyOverheadRegularized_.p", /* pName */
    3                                           /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = {
    1,                            /* iFirst */
    15,                           /* iLast */
    1,                            /* lineNo */
    1,                            /* colNo */
    "",                           /* aName */
    "modifyOverheadRegularized_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\modifyOverheadRegularized_.p", /* pName */
    3                                           /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = {
    1,                            /* iFirst */
    8,                            /* iLast */
    1,                            /* lineNo */
    1,                            /* colNo */
    "",                           /* aName */
    "modifyOverheadRegularized_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\modifyOverheadRegularized_.p", /* pName */
    3                                           /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = {
    1,                /* iFirst */
    15,               /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "setProblemType", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\setProblemType.p", /* pName */
    3                               /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = {
    1,                /* iFirst */
    15,               /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "setProblemType", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\setProblemType.p", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = {
    1,                            /* iFirst */
    15,                           /* iLast */
    1,                            /* lineNo */
    1,                            /* colNo */
    "",                           /* aName */
    "modifyOverheadRegularized_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\modifyOverheadRegularized_.p", /* pName */
    0                                           /* checkKind */
};

/* Function Definitions */
void setProblemType(const emlrtStack *sp, k_struct_T *obj, int32_T PROBLEM_TYPE)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T colOffsetATw;
  int32_T i;
  int32_T idx_col;
  int32_T idx_row;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  switch (PROBLEM_TYPE) {
  case 3: {
    obj->nVar = 5;
    obj->mConstr = obj->mConstrOrig;
    if (obj->nWConstr[4] > 0) {
      int32_T idxUpperExisting;
      idxUpperExisting = obj->isActiveIdx[4];
      st.site = &ad_emlrtRSI;
      if (obj->sizesNormal[4] > 2147483646) {
        b_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      i = (uint8_T)obj->sizesNormal[4];
      for (colOffsetATw = 0; colOffsetATw < i; colOffsetATw++) {
        int32_T a;
        int32_T i1;
        i1 = idxUpperExisting + colOffsetATw;
        if ((i1 < 1) || (i1 > 15)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, 15, &w_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        a = obj->isActiveIdxNormal[4] + colOffsetATw;
        if ((a < 1) || (a > 15)) {
          emlrtDynamicBoundsCheckR2012b(a, 1, 15, &v_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        obj->isActiveConstr[a - 1] = obj->isActiveConstr[i1 - 1];
        obj->isActiveConstr[i1 - 1] = false;
      }
    }
    for (i = 0; i < 5; i++) {
      obj->sizes[i] = obj->sizesNormal[i];
    }
    for (i = 0; i < 6; i++) {
      obj->isActiveIdx[i] = obj->isActiveIdxNormal[i];
    }
  } break;
  case 1:
    obj->nVar = 6;
    obj->mConstr = obj->mConstrOrig + 1;
    for (i = 0; i < 5; i++) {
      obj->sizes[i] = obj->sizesPhaseOne[i];
    }
    st.site = &ad_emlrtRSI;
    modifyOverheadPhaseOne_(&st, obj);
    for (i = 0; i < 6; i++) {
      obj->isActiveIdx[i] = obj->isActiveIdxPhaseOne[i];
    }
    break;
  case 2: {
    obj->nVar = 7;
    obj->mConstr = 14;
    for (i = 0; i < 5; i++) {
      obj->sizes[i] = obj->sizesRegularized[i];
    }
    if (obj->probType != 4) {
      int32_T a;
      int32_T b;
      int32_T i1;
      int32_T idxStartIneq;
      int32_T idxUpperExisting;
      st.site = &ad_emlrtRSI;
      b_st.site = &cd_emlrtRSI;
      if (obj->sizes[0] > 2147483646) {
        c_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      i = (uint8_T)obj->sizes[0];
      for (idx_col = 0; idx_col < i; idx_col++) {
        colOffsetATw = idx_col << 3;
        b_st.site = &cd_emlrtRSI;
        obj->ATwset[colOffsetATw + 5] = 0.0;
        obj->ATwset[colOffsetATw + 6] = 0.0;
      }
      b_st.site = &cd_emlrtRSI;
      for (idx_col = 0; idx_col < 2; idx_col++) {
        idxUpperExisting = (idx_col << 3) + 5;
        i = idx_col + 5;
        b_st.site = &cd_emlrtRSI;
        for (idx_row = 6; idx_row <= i; idx_row++) {
          obj->Aineq[idxUpperExisting] = 0.0;
        }
        obj->Aineq[idx_col + idxUpperExisting] = -1.0;
        i = idx_col + 7;
        b_st.site = &cd_emlrtRSI;
        for (idx_row = i; idx_row < 8; idx_row++) {
          obj->Aineq[idxUpperExisting + 1] = 0.0;
        }
      }
      b_st.site = &cd_emlrtRSI;
      idxUpperExisting = 5;
      a = obj->sizesNormal[3] + 1;
      b = obj->sizesRegularized[3];
      b_st.site = &cd_emlrtRSI;
      if ((obj->sizesNormal[3] + 1 <= obj->sizesRegularized[3]) &&
          (obj->sizesRegularized[3] > 2147483646)) {
        c_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (colOffsetATw = a; colOffsetATw <= b; colOffsetATw++) {
        idxUpperExisting++;
        if ((colOffsetATw < 1) || (colOffsetATw > 8)) {
          emlrtDynamicBoundsCheckR2012b(colOffsetATw, 1, 8, &u_emlrtBCI, &st);
        }
        obj->indexLB[colOffsetATw - 1] = idxUpperExisting;
      }
      if (obj->nWConstr[4] > 0) {
        b_st.site = &cd_emlrtRSI;
        if (obj->sizesRegularized[4] > 2147483646) {
          c_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }
        i = (uint8_T)obj->sizesRegularized[4];
        for (colOffsetATw = 0; colOffsetATw < i; colOffsetATw++) {
          i1 = obj->isActiveIdx[4] + colOffsetATw;
          if ((i1 < 1) || (i1 > 15)) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, 15, &x_emlrtBCI, &st);
          }
          a = (obj->isActiveIdxRegularized[4] + colOffsetATw) + 1;
          if ((a < 1) || (a > 15)) {
            emlrtDynamicBoundsCheckR2012b(a, 1, 15, &t_emlrtBCI, &st);
          }
          obj->isActiveConstr[a - 1] = obj->isActiveConstr[i1 - 1];
        }
      }
      a = obj->isActiveIdx[4];
      b = obj->isActiveIdxRegularized[4] - 1;
      b_st.site = &cd_emlrtRSI;
      if ((obj->isActiveIdx[4] <= obj->isActiveIdxRegularized[4] - 1) &&
          (obj->isActiveIdxRegularized[4] - 1 > 2147483646)) {
        c_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (colOffsetATw = a; colOffsetATw <= b; colOffsetATw++) {
        if ((colOffsetATw < 1) || (colOffsetATw > 15)) {
          emlrtDynamicBoundsCheckR2012b(colOffsetATw, 1, 15, &t_emlrtBCI, &st);
        }
        obj->isActiveConstr[colOffsetATw - 1] = false;
      }
      b_st.site = &cd_emlrtRSI;
      obj->lb[5] = 0.0;
      obj->lb[6] = 0.0;
      idxStartIneq = obj->isActiveIdx[2];
      b = obj->nActiveConstr;
      b_st.site = &cd_emlrtRSI;
      if ((obj->isActiveIdx[2] <= obj->nActiveConstr) &&
          (obj->nActiveConstr > 2147483646)) {
        c_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (idx_col = idxStartIneq; idx_col <= b; idx_col++) {
        colOffsetATw = (idx_col - 1) << 3;
        if ((idx_col < 1) || (idx_col > 15)) {
          emlrtDynamicBoundsCheckR2012b(idx_col, 1, 15, &x_emlrtBCI, &st);
        }
        if (obj->Wid[idx_col - 1] == 3) {
          a = obj->Wlocalidx[idx_col - 1];
          idxUpperExisting = a + 4;
          b_st.site = &cd_emlrtRSI;
          if (a + 4 > 2147483646) {
            c_st.site = &o_emlrtRSI;
            check_forloop_overflow_error(&c_st);
          }
          for (idx_row = 6; idx_row <= idxUpperExisting; idx_row++) {
            i = idx_row + colOffsetATw;
            if ((i < 1) || (i > 120)) {
              emlrtDynamicBoundsCheckR2012b(i, 1, 120, &s_emlrtBCI, &st);
            }
            obj->ATwset[i - 1] = 0.0;
          }
          i = (a + colOffsetATw) + 5;
          if ((i < 1) || (i > 120)) {
            emlrtDynamicBoundsCheckR2012b(i, 1, 120, &s_emlrtBCI, &st);
          }
          obj->ATwset[i - 1] = -1.0;
          i = a + 6;
          b_st.site = &cd_emlrtRSI;
          for (idx_row = i; idx_row < 8; idx_row++) {
            i1 = idx_row + colOffsetATw;
            if ((i1 < 1) || (i1 > 120)) {
              emlrtDynamicBoundsCheckR2012b(i1, 1, 120, &s_emlrtBCI, &st);
            }
            obj->ATwset[i1 - 1] = 0.0;
          }
        } else {
          b_st.site = &cd_emlrtRSI;
          if ((colOffsetATw + 6 < 1) || (colOffsetATw + 6 > 120)) {
            emlrtDynamicBoundsCheckR2012b(colOffsetATw + 6, 1, 120, &s_emlrtBCI,
                                          &st);
          }
          obj->ATwset[colOffsetATw + 5] = 0.0;
          if ((colOffsetATw + 7 < 1) || (colOffsetATw + 7 > 120)) {
            emlrtDynamicBoundsCheckR2012b(colOffsetATw + 7, 1, 120, &s_emlrtBCI,
                                          &st);
          }
          obj->ATwset[colOffsetATw + 6] = 0.0;
        }
      }
    }
    for (i = 0; i < 6; i++) {
      obj->isActiveIdx[i] = obj->isActiveIdxRegularized[i];
    }
  } break;
  default:
    obj->nVar = 8;
    obj->mConstr = 15;
    for (i = 0; i < 5; i++) {
      obj->sizes[i] = obj->sizesRegPhaseOne[i];
    }
    st.site = &ad_emlrtRSI;
    modifyOverheadPhaseOne_(&st, obj);
    for (i = 0; i < 6; i++) {
      obj->isActiveIdx[i] = obj->isActiveIdxRegPhaseOne[i];
    }
    break;
  }
  obj->probType = PROBLEM_TYPE;
}

/* End of code generation (setProblemType.c) */
