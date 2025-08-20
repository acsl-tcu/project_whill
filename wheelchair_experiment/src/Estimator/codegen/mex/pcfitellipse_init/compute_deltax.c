/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * compute_deltax.c
 *
 * Code generation for function 'compute_deltax'
 *
 */

/* Include files */
#include "compute_deltax.h"
#include "eml_int_forloop_overflow_check.h"
#include "factor.h"
#include "factor1.h"
#include "fullColLDL2_.h"
#include "ixamax.h"
#include "pcfitellipse_init_data.h"
#include "pcfitellipse_init_internal_types.h"
#include "pcfitellipse_init_mexutil.h"
#include "rt_nonfinite.h"
#include "solve.h"
#include "solve1.h"
#include "xgemm.h"
#include "xgemv.h"
#include "xpotrf.h"
#include "xtrsv.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo eg_emlrtRSI = {
    1,                /* lineNo */
    "compute_deltax", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\compute_deltax.p" /* pathName */
};

static emlrtRSInfo rg_emlrtRSI = {
    1,                         /* lineNo */
    "computeProjectedHessian", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\computeProjectedHessian.p" /* pathName */
};

static emlrtRSInfo yg_emlrtRSI = {
    1,                                     /* lineNo */
    "computeProjectedHessian_regularized", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+relaxed\\computeProjectedHessian_regular"
    "ized.p" /* pathName */
};

static emlrtRSInfo ah_emlrtRSI = {
    1,        /* lineNo */
    "factor", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\compute_deltax.p" /* pathName */
};

static emlrtRSInfo bh_emlrtRSI = {
    1,       /* lineNo */
    "solve", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\compute_deltax.p" /* pathName */
};

static emlrtBCInfo cd_emlrtBCI = {
    1,                /* iFirst */
    7,                /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "compute_deltax", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\compute_deltax.p", /* pName */
    3                                /* checkKind */
};

static emlrtBCInfo ed_emlrtBCI = {
    1,                /* iFirst */
    169,              /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "compute_deltax", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\compute_deltax.p", /* pName */
    0                                /* checkKind */
};

static emlrtBCInfo fd_emlrtBCI = {
    1,                /* iFirst */
    91,               /* iLast */
    1,                /* lineNo */
    1,                /* colNo */
    "",               /* aName */
    "compute_deltax", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "qpactiveset\\compute_deltax.p", /* pName */
    3                                /* checkKind */
};

static emlrtBCInfo gd_emlrtBCI = {
    1,                                     /* iFirst */
    13,                                    /* iLast */
    1,                                     /* lineNo */
    1,                                     /* colNo */
    "",                                    /* aName */
    "computeProjectedHessian_regularized", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+relaxed\\computeProjectedHessian_regular"
    "ized.p", /* pName */
    0         /* checkKind */
};

static emlrtBCInfo hd_emlrtBCI = {
    1,                                     /* iFirst */
    13,                                    /* iLast */
    1,                                     /* lineNo */
    1,                                     /* colNo */
    "",                                    /* aName */
    "computeProjectedHessian_regularized", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+relaxed\\computeProjectedHessian_regular"
    "ized.p", /* pName */
    3         /* checkKind */
};

static emlrtBCInfo id_emlrtBCI = {
    1,                                     /* iFirst */
    7,                                     /* iLast */
    1,                                     /* lineNo */
    1,                                     /* colNo */
    "",                                    /* aName */
    "computeProjectedHessian_regularized", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+"
    "step\\+relaxed\\computeProjectedHessian_regular"
    "ized.p", /* pName */
    3         /* checkKind */
};

/* Function Definitions */
void compute_deltax(const emlrtStack *sp, const real_T H[25],
                    h_struct_T *solution, d_struct_T *memspace,
                    const e_struct_T *qrmanager, f_struct_T *cholmanager,
                    const struct_T *objective, boolean_T alwaysPositiveDef)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  int32_T A_maxDiag_idx;
  int32_T idx_col;
  int32_T idx_row;
  int32_T k;
  int32_T mNull_tmp;
  int32_T nVar;
  int32_T scalarLB;
  int32_T vectorUB;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  nVar = qrmanager->mrows - 1;
  mNull_tmp = qrmanager->mrows - qrmanager->ncols;
  if (mNull_tmp <= 0) {
    st.site = &eg_emlrtRSI;
    if (qrmanager->mrows > 2147483646) {
      b_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (A_maxDiag_idx = 0; A_maxDiag_idx <= nVar; A_maxDiag_idx++) {
      if ((A_maxDiag_idx + 1 < 1) || (A_maxDiag_idx + 1 > 7)) {
        emlrtDynamicBoundsCheckR2012b(A_maxDiag_idx + 1, 1, 7, &cd_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      solution->searchDir[A_maxDiag_idx] = 0.0;
    }
  } else {
    __m128d r;
    st.site = &eg_emlrtRSI;
    if (qrmanager->mrows > 2147483646) {
      b_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    scalarLB = ((nVar + 1) / 2) << 1;
    vectorUB = scalarLB - 2;
    for (A_maxDiag_idx = 0; A_maxDiag_idx <= vectorUB; A_maxDiag_idx += 2) {
      r = _mm_loadu_pd(&objective->grad[A_maxDiag_idx]);
      if ((A_maxDiag_idx + 1 < 1) || (A_maxDiag_idx + 1 > 7)) {
        emlrtDynamicBoundsCheckR2012b(A_maxDiag_idx + 1, 1, 7, &cd_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      _mm_storeu_pd(&solution->searchDir[A_maxDiag_idx],
                    _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    }
    for (A_maxDiag_idx = scalarLB; A_maxDiag_idx <= nVar; A_maxDiag_idx++) {
      if ((A_maxDiag_idx + 1 < 1) || (A_maxDiag_idx + 1 > 7)) {
        emlrtDynamicBoundsCheckR2012b(A_maxDiag_idx + 1, 1, 7, &cd_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      solution->searchDir[A_maxDiag_idx] = -objective->grad[A_maxDiag_idx];
    }
    if (qrmanager->ncols <= 0) {
      switch (objective->objtype) {
      case 5:
        break;
      case 3:
        st.site = &eg_emlrtRSI;
        if (alwaysPositiveDef) {
          b_st.site = &eg_emlrtRSI;
          factor(&b_st, cholmanager, H, qrmanager->mrows, qrmanager->mrows);
        } else {
          b_st.site = &eg_emlrtRSI;
          b_factor(&b_st, cholmanager, H, qrmanager->mrows, qrmanager->mrows);
        }
        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          st.site = &eg_emlrtRSI;
          if (alwaysPositiveDef) {
            b_st.site = &eg_emlrtRSI;
            solve(&b_st, cholmanager, solution->searchDir);
          } else {
            b_st.site = &eg_emlrtRSI;
            b_solve(&b_st, cholmanager, solution->searchDir);
          }
        }
        break;
      default: {
        if (alwaysPositiveDef) {
          st.site = &eg_emlrtRSI;
          b_st.site = &eg_emlrtRSI;
          factor(&b_st, cholmanager, H, objective->nvar, objective->nvar);
          if (cholmanager->info != 0) {
            solution->state = -6;
          } else {
            real_T c;
            int32_T nVars;
            st.site = &eg_emlrtRSI;
            b_st.site = &eg_emlrtRSI;
            solve(&b_st, cholmanager, solution->searchDir);
            st.site = &eg_emlrtRSI;
            c = 1.0 / objective->beta;
            A_maxDiag_idx = objective->nvar + 1;
            b_st.site = &rd_emlrtRSI;
            nVars = qrmanager->mrows;
            c_st.site = &sd_emlrtRSI;
            if ((A_maxDiag_idx <= nVars) && (nVars > 2147483646)) {
              d_st.site = &hb_emlrtRSI;
              check_forloop_overflow_error(&d_st);
            }
            scalarLB =
                ((((nVars - A_maxDiag_idx) + 1) / 2) << 1) + A_maxDiag_idx;
            vectorUB = scalarLB - 2;
            for (k = A_maxDiag_idx; k <= vectorUB; k += 2) {
              r = _mm_loadu_pd(&solution->searchDir[k - 1]);
              _mm_storeu_pd(&solution->searchDir[k - 1],
                            _mm_mul_pd(_mm_set1_pd(c), r));
            }
            for (k = scalarLB; k <= nVars; k++) {
              solution->searchDir[k - 1] *= c;
            }
          }
        }
      } break;
      }
    } else {
      int32_T nullStartIdx_tmp;
      nullStartIdx_tmp = 13 * qrmanager->ncols + 1;
      if (objective->objtype == 5) {
        st.site = &eg_emlrtRSI;
        if (mNull_tmp > 2147483646) {
          b_st.site = &hb_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }
        for (A_maxDiag_idx = 0; A_maxDiag_idx < mNull_tmp; A_maxDiag_idx++) {
          k = (nVar + 13 * (qrmanager->ncols + A_maxDiag_idx)) + 1;
          if ((k < 1) || (k > 169)) {
            emlrtDynamicBoundsCheckR2012b(k, 1, 169, &ed_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          if (A_maxDiag_idx + 1 > 91) {
            emlrtDynamicBoundsCheckR2012b(A_maxDiag_idx + 1, 1, 91,
                                          &fd_emlrtBCI, (emlrtConstCTX)sp);
          }
          memspace->workspace_double[A_maxDiag_idx] = -qrmanager->Q[k - 1];
        }
        st.site = &eg_emlrtRSI;
        d_xgemv(&st, qrmanager->mrows, mNull_tmp, qrmanager->Q,
                nullStartIdx_tmp, memspace->workspace_double,
                solution->searchDir);
      } else {
        int32_T nVars;
        if (objective->objtype == 3) {
          st.site = &eg_emlrtRSI;
          b_st.site = &rg_emlrtRSI;
          xgemm(&b_st, qrmanager->mrows, mNull_tmp, qrmanager->mrows, H,
                qrmanager->mrows, qrmanager->Q, nullStartIdx_tmp,
                memspace->workspace_double);
          b_st.site = &rg_emlrtRSI;
          b_xgemm(mNull_tmp, mNull_tmp, qrmanager->mrows, qrmanager->Q,
                  nullStartIdx_tmp, memspace->workspace_double,
                  cholmanager->FMat);
        } else if (alwaysPositiveDef) {
          A_maxDiag_idx = objective->nvar + 1;
          st.site = &eg_emlrtRSI;
          nVars = qrmanager->mrows;
          b_st.site = &yg_emlrtRSI;
          xgemm(&b_st, objective->nvar, mNull_tmp, objective->nvar, H,
                objective->nvar, qrmanager->Q, nullStartIdx_tmp,
                memspace->workspace_double);
          b_st.site = &yg_emlrtRSI;
          if (mNull_tmp > 2147483646) {
            c_st.site = &hb_emlrtRSI;
            check_forloop_overflow_error(&c_st);
          }
          scalarLB = ((((nVars - A_maxDiag_idx) + 1) / 2) << 1) + A_maxDiag_idx;
          vectorUB = scalarLB - 2;
          for (idx_col = 0; idx_col < mNull_tmp; idx_col++) {
            b_st.site = &yg_emlrtRSI;
            if ((A_maxDiag_idx <= nVars) && (nVars > 2147483646)) {
              c_st.site = &hb_emlrtRSI;
              check_forloop_overflow_error(&c_st);
            }
            for (idx_row = A_maxDiag_idx; idx_row <= vectorUB; idx_row += 2) {
              k = (idx_col + qrmanager->ncols) + 1;
              if ((k < 1) || (k > 13)) {
                emlrtDynamicBoundsCheckR2012b(k, 1, 13, &gd_emlrtBCI, &st);
              }
              r = _mm_loadu_pd(&qrmanager->Q[(idx_row + 13 * (k - 1)) - 1]);
              if ((idx_row < 1) || (idx_row > 13)) {
                emlrtDynamicBoundsCheckR2012b(idx_row, 1, 13, &hd_emlrtBCI,
                                              &st);
              }
              if (idx_col + 1 > 7) {
                emlrtDynamicBoundsCheckR2012b(idx_col + 1, 1, 7, &id_emlrtBCI,
                                              &st);
              }
              _mm_storeu_pd(
                  &memspace->workspace_double[(idx_row + 13 * idx_col) - 1],
                  _mm_mul_pd(_mm_set1_pd(objective->beta), r));
            }
            for (idx_row = scalarLB; idx_row <= nVars; idx_row++) {
              k = (idx_col + qrmanager->ncols) + 1;
              if ((k < 1) || (k > 13)) {
                emlrtDynamicBoundsCheckR2012b(k, 1, 13, &gd_emlrtBCI, &st);
              }
              if ((idx_row < 1) || (idx_row > 13)) {
                emlrtDynamicBoundsCheckR2012b(idx_row, 1, 13, &hd_emlrtBCI,
                                              &st);
              }
              if (idx_col + 1 > 7) {
                emlrtDynamicBoundsCheckR2012b(idx_col + 1, 1, 7, &id_emlrtBCI,
                                              &st);
              }
              memspace->workspace_double[(idx_row + 13 * idx_col) - 1] =
                  objective->beta * qrmanager->Q[(idx_row + 13 * (k - 1)) - 1];
            }
          }
          b_st.site = &yg_emlrtRSI;
          b_xgemm(mNull_tmp, mNull_tmp, qrmanager->mrows, qrmanager->Q,
                  nullStartIdx_tmp, memspace->workspace_double,
                  cholmanager->FMat);
        }
        st.site = &eg_emlrtRSI;
        if (alwaysPositiveDef) {
          b_st.site = &ah_emlrtRSI;
          cholmanager->ndims = mNull_tmp;
          c_st.site = &fg_emlrtRSI;
          cholmanager->info = xpotrf(&c_st, mNull_tmp, cholmanager->FMat);
        } else {
          b_st.site = &ah_emlrtRSI;
          cholmanager->ndims = mNull_tmp;
          c_st.site = &ig_emlrtRSI;
          A_maxDiag_idx = b_ixamax(&c_st, mNull_tmp, cholmanager->FMat) - 1;
          k = A_maxDiag_idx + 13 * A_maxDiag_idx;
          if ((k + 1 < 1) || (k + 1 > 169)) {
            emlrtDynamicBoundsCheckR2012b(k + 1, 1, 169, &dd_emlrtBCI, &b_st);
          }
          cholmanager->regTol_ = muDoubleScalarMax(
              muDoubleScalarAbs(cholmanager->FMat[k]) * 2.2204460492503131E-16,
              0.0);
          c_st.site = &ig_emlrtRSI;
          fullColLDL2_(&c_st, cholmanager, mNull_tmp);
          if (cholmanager->ConvexCheck) {
            c_st.site = &ig_emlrtRSI;
            if (mNull_tmp > 2147483646) {
              d_st.site = &hb_emlrtRSI;
              check_forloop_overflow_error(&d_st);
            }
            A_maxDiag_idx = 0;
            int32_T exitg1;
            do {
              exitg1 = 0;
              if (A_maxDiag_idx <= mNull_tmp - 1) {
                k = (A_maxDiag_idx + 13 * A_maxDiag_idx) + 1;
                if ((k < 1) || (k > 169)) {
                  emlrtDynamicBoundsCheckR2012b(k, 1, 169, &dd_emlrtBCI, &b_st);
                }
                if (cholmanager->FMat[k - 1] <= 0.0) {
                  cholmanager->info = -(A_maxDiag_idx + 1);
                  exitg1 = 1;
                } else {
                  A_maxDiag_idx++;
                }
              } else {
                cholmanager->ConvexCheck = false;
                exitg1 = 1;
              }
            } while (exitg1 == 0);
          }
        }
        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          real_T c;
          st.site = &eg_emlrtRSI;
          b_st.site = &kc_emlrtRSI;
          if (qrmanager->mrows != 0) {
            c_st.site = &td_emlrtRSI;
            if (mNull_tmp > 2147483646) {
              d_st.site = &hb_emlrtRSI;
              check_forloop_overflow_error(&d_st);
            }
            memset(&memspace->workspace_double[0], 0,
                   (uint32_T)mNull_tmp * sizeof(real_T));
            nVars = nullStartIdx_tmp + 13 * (mNull_tmp - 1);
            c_st.site = &lc_emlrtRSI;
            if ((nullStartIdx_tmp <= nVars) && (nVars > 2147483634)) {
              d_st.site = &hb_emlrtRSI;
              check_forloop_overflow_error(&d_st);
            }
            for (vectorUB = nullStartIdx_tmp; vectorUB <= nVars;
                 vectorUB += 13) {
              c = 0.0;
              A_maxDiag_idx = vectorUB + nVar;
              c_st.site = &mc_emlrtRSI;
              if ((vectorUB <= A_maxDiag_idx) && (A_maxDiag_idx > 2147483646)) {
                d_st.site = &hb_emlrtRSI;
                check_forloop_overflow_error(&d_st);
              }
              for (scalarLB = vectorUB; scalarLB <= A_maxDiag_idx; scalarLB++) {
                c += qrmanager->Q[scalarLB - 1] *
                     objective->grad[scalarLB - vectorUB];
              }
              k = div_nde_s32_floor(vectorUB - nullStartIdx_tmp, 13);
              memspace->workspace_double[k] -= c;
            }
          }
          st.site = &eg_emlrtRSI;
          if (alwaysPositiveDef) {
            b_st.site = &bh_emlrtRSI;
            c_st.site = &lg_emlrtRSI;
            A_maxDiag_idx = cholmanager->ndims;
            d_st.site = &de_emlrtRSI;
            if (cholmanager->ndims != 0) {
              e_st.site = &mg_emlrtRSI;
              if (cholmanager->ndims > 2147483646) {
                f_st.site = &hb_emlrtRSI;
                check_forloop_overflow_error(&f_st);
              }
              for (scalarLB = 0; scalarLB < A_maxDiag_idx; scalarLB++) {
                nVars = scalarLB * 13;
                c = memspace->workspace_double[scalarLB];
                e_st.site = &ng_emlrtRSI;
                if (scalarLB > 2147483646) {
                  f_st.site = &hb_emlrtRSI;
                  check_forloop_overflow_error(&f_st);
                }
                for (vectorUB = 0; vectorUB < scalarLB; vectorUB++) {
                  c -= cholmanager->FMat[nVars + vectorUB] *
                       memspace->workspace_double[vectorUB];
                }
                memspace->workspace_double[scalarLB] =
                    c / cholmanager->FMat[nVars + scalarLB];
              }
            }
            c_st.site = &lg_emlrtRSI;
            xtrsv(cholmanager->ndims, cholmanager->FMat,
                  memspace->workspace_double);
          } else {
            b_st.site = &bh_emlrtRSI;
            c_solve(&b_st, cholmanager, memspace->workspace_double);
          }
          st.site = &eg_emlrtRSI;
          d_xgemv(&st, qrmanager->mrows, mNull_tmp, qrmanager->Q,
                  nullStartIdx_tmp, memspace->workspace_double,
                  solution->searchDir);
        }
      }
    }
  }
}

/* End of code generation (compute_deltax.c) */
