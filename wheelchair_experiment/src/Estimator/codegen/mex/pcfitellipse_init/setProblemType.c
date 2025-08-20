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
#include "pcfitellipse_init_data.h"
#include "pcfitellipse_init_internal_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo rc_emlrtRSI = {
    1,                /* lineNo */
    "setProblemType", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\setProblemType.p" /* pathName */
};

static emlrtRSInfo tc_emlrtRSI = {
    1,                            /* lineNo */
    "modifyOverheadRegularized_", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\modifyOverheadRegularized_.p" /* pathName */
};

static emlrtBCInfo m_emlrtBCI = {
    1,                            /* iFirst */
    91,                           /* iLast */
    1,                            /* lineNo */
    1,                            /* colNo */
    "",                           /* aName */
    "modifyOverheadRegularized_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\modifyOverheadRegularized_.p", /* pName */
    3                                           /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    1,                            /* iFirst */
    13,                           /* iLast */
    1,                            /* lineNo */
    1,                            /* colNo */
    "",                           /* aName */
    "modifyOverheadRegularized_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\modifyOverheadRegularized_.p", /* pName */
    3                                           /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    1,                            /* iFirst */
    7,                            /* iLast */
    1,                            /* lineNo */
    1,                            /* colNo */
    "",                           /* aName */
    "modifyOverheadRegularized_", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\modifyOverheadRegularized_.p", /* pName */
    3                                           /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    1,                /* iFirst */
    13,               /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "setProblemType", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\setProblemType.p", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    1,                /* iFirst */
    13,               /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "setProblemType", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "WorkingSet\\setProblemType.p", /* pName */
    3                               /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    1,                            /* iFirst */
    13,                           /* iLast */
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
void setProblemType(const emlrtStack *sp, i_struct_T *obj, int32_T PROBLEM_TYPE)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T i;
  int32_T idxStartIneq;
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
      st.site = &rc_emlrtRSI;
      if (obj->sizesNormal[4] > 2147483646) {
        b_st.site = &hb_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      i = (uint8_T)obj->sizesNormal[4];
      for (idxStartIneq = 0; idxStartIneq < i; idxStartIneq++) {
        int32_T a;
        int32_T idx_lb;
        a = obj->isActiveIdx[4] + idxStartIneq;
        if ((a < 1) || (a > 13)) {
          emlrtDynamicBoundsCheckR2012b(a, 1, 13, &p_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        idx_lb = obj->isActiveIdxNormal[4] + idxStartIneq;
        if ((idx_lb < 1) || (idx_lb > 13)) {
          emlrtDynamicBoundsCheckR2012b(idx_lb, 1, 13, &q_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        obj->isActiveConstr[idx_lb - 1] = obj->isActiveConstr[a - 1];
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
    for (i = 0; i < 6; i++) {
      obj->isActiveIdx[i] = obj->isActiveIdxPhaseOne[i];
    }
    st.site = &rc_emlrtRSI;
    modifyOverheadPhaseOne_(&st, obj);
    break;
  case 2: {
    obj->nVar = 6;
    obj->mConstr = 12;
    for (i = 0; i < 5; i++) {
      obj->sizes[i] = obj->sizesRegularized[i];
    }
    if (obj->probType != 4) {
      int32_T a;
      int32_T b;
      int32_T idx_lb;
      st.site = &rc_emlrtRSI;
      b_st.site = &tc_emlrtRSI;
      if (obj->sizes[0] > 2147483646) {
        c_st.site = &hb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      i = (uint8_T)obj->sizes[0];
      for (idx_col = 0; idx_col < i; idx_col++) {
        b_st.site = &tc_emlrtRSI;
        obj->ATwset[7 * idx_col + 5] = 0.0;
      }
      b_st.site = &tc_emlrtRSI;
      obj->Aineq[5] = -1.0;
      b_st.site = &tc_emlrtRSI;
      b_st.site = &tc_emlrtRSI;
      b_st.site = &tc_emlrtRSI;
      idx_lb = 5;
      a = obj->sizesNormal[3] + 1;
      b = obj->sizesRegularized[3];
      b_st.site = &tc_emlrtRSI;
      if ((obj->sizesNormal[3] + 1 <= obj->sizesRegularized[3]) &&
          (obj->sizesRegularized[3] > 2147483646)) {
        c_st.site = &hb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (idxStartIneq = a; idxStartIneq <= b; idxStartIneq++) {
        idx_lb++;
        if ((idxStartIneq < 1) || (idxStartIneq > 7)) {
          emlrtDynamicBoundsCheckR2012b(idxStartIneq, 1, 7, &o_emlrtBCI, &st);
        }
        obj->indexLB[idxStartIneq - 1] = idx_lb;
      }
      if (obj->nWConstr[4] > 0) {
        b_st.site = &tc_emlrtRSI;
        if (obj->sizesRegularized[4] > 2147483646) {
          c_st.site = &hb_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }
        i = (uint8_T)obj->sizesRegularized[4];
        for (idxStartIneq = 0; idxStartIneq < i; idxStartIneq++) {
          a = obj->isActiveIdx[4] + idxStartIneq;
          if ((a < 1) || (a > 13)) {
            emlrtDynamicBoundsCheckR2012b(a, 1, 13, &r_emlrtBCI, &st);
          }
          idx_lb = (obj->isActiveIdxRegularized[4] + idxStartIneq) + 1;
          if ((idx_lb < 1) || (idx_lb > 13)) {
            emlrtDynamicBoundsCheckR2012b(idx_lb, 1, 13, &n_emlrtBCI, &st);
          }
          obj->isActiveConstr[idx_lb - 1] = obj->isActiveConstr[a - 1];
        }
      }
      a = obj->isActiveIdx[4];
      b = obj->isActiveIdxRegularized[4] - 1;
      b_st.site = &tc_emlrtRSI;
      if ((obj->isActiveIdx[4] <= obj->isActiveIdxRegularized[4] - 1) &&
          (obj->isActiveIdxRegularized[4] - 1 > 2147483646)) {
        c_st.site = &hb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (idxStartIneq = a; idxStartIneq <= b; idxStartIneq++) {
        if ((idxStartIneq < 1) || (idxStartIneq > 13)) {
          emlrtDynamicBoundsCheckR2012b(idxStartIneq, 1, 13, &n_emlrtBCI, &st);
        }
        obj->isActiveConstr[idxStartIneq - 1] = false;
      }
      b_st.site = &tc_emlrtRSI;
      obj->lb[5] = 0.0;
      idxStartIneq = obj->isActiveIdx[2];
      b = obj->nActiveConstr;
      b_st.site = &tc_emlrtRSI;
      if ((obj->isActiveIdx[2] <= obj->nActiveConstr) &&
          (obj->nActiveConstr > 2147483646)) {
        c_st.site = &hb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (idx_col = idxStartIneq; idx_col <= b; idx_col++) {
        int32_T colOffsetATw;
        colOffsetATw = 7 * (idx_col - 1);
        if ((idx_col < 1) || (idx_col > 13)) {
          emlrtDynamicBoundsCheckR2012b(idx_col, 1, 13, &r_emlrtBCI, &st);
        }
        if (obj->Wid[idx_col - 1] == 3) {
          idx_lb = obj->Wlocalidx[idx_col - 1];
          a = idx_lb + 4;
          b_st.site = &tc_emlrtRSI;
          if (idx_lb + 4 > 2147483646) {
            c_st.site = &hb_emlrtRSI;
            check_forloop_overflow_error(&c_st);
          }
          for (idx_row = 6; idx_row <= a; idx_row++) {
            i = idx_row + colOffsetATw;
            if ((i < 1) || (i > 91)) {
              emlrtDynamicBoundsCheckR2012b(i, 1, 91, &m_emlrtBCI, &st);
            }
            obj->ATwset[i - 1] = 0.0;
          }
          i = (idx_lb + colOffsetATw) + 5;
          if ((i < 1) || (i > 91)) {
            emlrtDynamicBoundsCheckR2012b(i, 1, 91, &m_emlrtBCI, &st);
          }
          obj->ATwset[i - 1] = -1.0;
          i = idx_lb + 6;
          b_st.site = &tc_emlrtRSI;
          for (idx_row = i; idx_row < 7; idx_row++) {
            a = idx_row + colOffsetATw;
            if ((a < 1) || (a > 91)) {
              emlrtDynamicBoundsCheckR2012b(a, 1, 91, &m_emlrtBCI, &st);
            }
            obj->ATwset[a - 1] = 0.0;
          }
        } else {
          b_st.site = &tc_emlrtRSI;
          if ((colOffsetATw + 6 < 1) || (colOffsetATw + 6 > 91)) {
            emlrtDynamicBoundsCheckR2012b(colOffsetATw + 6, 1, 91, &m_emlrtBCI,
                                          &st);
          }
          obj->ATwset[colOffsetATw + 5] = 0.0;
        }
      }
    }
    for (i = 0; i < 6; i++) {
      obj->isActiveIdx[i] = obj->isActiveIdxRegularized[i];
    }
  } break;
  default:
    obj->nVar = 7;
    obj->mConstr = 13;
    for (i = 0; i < 5; i++) {
      obj->sizes[i] = obj->sizesRegPhaseOne[i];
    }
    for (i = 0; i < 6; i++) {
      obj->isActiveIdx[i] = obj->isActiveIdxRegPhaseOne[i];
    }
    st.site = &rc_emlrtRSI;
    modifyOverheadPhaseOne_(&st, obj);
    break;
  }
  obj->probType = PROBLEM_TYPE;
}

/* End of code generation (setProblemType.c) */
