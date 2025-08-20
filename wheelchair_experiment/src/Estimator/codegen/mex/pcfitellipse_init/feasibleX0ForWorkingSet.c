/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * feasibleX0ForWorkingSet.c
 *
 * Code generation for function 'feasibleX0ForWorkingSet'
 *
 */

/* Include files */
#include "feasibleX0ForWorkingSet.h"
#include "computeQ_.h"
#include "eml_int_forloop_overflow_check.h"
#include "factorQR.h"
#include "maxConstraintViolation.h"
#include "pcfitellipse_init_data.h"
#include "pcfitellipse_init_internal_types.h"
#include "pcfitellipse_init_mexutil.h"
#include "rt_nonfinite.h"
#include "xgeqrf.h"
#include "blas.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ye_emlrtRSI = {
    1,                         /* lineNo */
    "feasibleX0ForWorkingSet", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\feasibleX0ForWorkingSet.p" /* pathName */
};

static emlrtRSInfo gf_emlrtRSI = {
    75,      /* lineNo */
    "xgemm", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemm."
    "m" /* pathName */
};

static emlrtRSInfo hf_emlrtRSI = {
    92,           /* lineNo */
    "xgemm_blas", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemm."
    "m" /* pathName */
};

static emlrtRSInfo if_emlrtRSI = {
    67,      /* lineNo */
    "xtrsm", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xtrsm."
    "m" /* pathName */
};

static emlrtRSInfo jf_emlrtRSI = {
    81,           /* lineNo */
    "xtrsm_blas", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xtrsm."
    "m" /* pathName */
};

static emlrtRSInfo kf_emlrtRSI = {
    1,              /* lineNo */
    "computeTallQ", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+"
    "QRManager\\computeTallQ.p" /* pathName */
};

static emlrtBCInfo fc_emlrtBCI = {
    1,                         /* iFirst */
    13,                        /* iLast */
    1,                         /* lineNo */
    1,                         /* colNo */
    "",                        /* aName */
    "feasibleX0ForWorkingSet", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\feasibleX0ForWorkingSet.p", /* pName */
    3                                        /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = {
    1,                         /* iFirst */
    91,                        /* iLast */
    1,                         /* lineNo */
    1,                         /* colNo */
    "",                        /* aName */
    "feasibleX0ForWorkingSet", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\feasibleX0ForWorkingSet.p", /* pName */
    0                                        /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = {
    1,                         /* iFirst */
    169,                       /* iLast */
    1,                         /* lineNo */
    1,                         /* colNo */
    "",                        /* aName */
    "feasibleX0ForWorkingSet", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+"
    "initialize\\feasibleX0ForWorkingSet.p", /* pName */
    3                                        /* checkKind */
};

/* Function Definitions */
boolean_T feasibleX0ForWorkingSet(const emlrtStack *sp, real_T workspace[91],
                                  real_T xCurrent[7], i_struct_T *workingset,
                                  e_struct_T *qrmanager)
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T B[91];
  real_T beta1;
  real_T c;
  int32_T ia;
  int32_T iac;
  int32_T idx_row;
  int32_T k;
  int32_T mWConstr;
  int32_T nVar;
  int32_T offsetQR;
  char_T DIAGA1;
  char_T SIDE1;
  char_T TRANSA1;
  char_T UPLO1;
  boolean_T nonDegenerateWset;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  mWConstr = workingset->nActiveConstr;
  nVar = workingset->nVar;
  nonDegenerateWset = true;
  if (mWConstr != 0) {
    int32_T b_tmp;
    st.site = &ye_emlrtRSI;
    if (mWConstr > 2147483646) {
      b_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (offsetQR = 0; offsetQR < mWConstr; offsetQR++) {
      c = workingset->bwset[offsetQR];
      if ((offsetQR + 1 < 1) || (offsetQR + 1 > 13)) {
        emlrtDynamicBoundsCheckR2012b(offsetQR + 1, 1, 13, &fc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      workspace[offsetQR] = c;
      workspace[offsetQR + 13] = c;
    }
    st.site = &ye_emlrtRSI;
    b_st.site = &kc_emlrtRSI;
    if (mWConstr != 0) {
      b_tmp = 7 * (mWConstr - 1) + 1;
      c_st.site = &lc_emlrtRSI;
      if (b_tmp > 2147483640) {
        d_st.site = &hb_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (iac = 1; iac <= b_tmp; iac += 7) {
        c = 0.0;
        offsetQR = (iac + nVar) - 1;
        c_st.site = &mc_emlrtRSI;
        if ((iac <= offsetQR) && (offsetQR > 2147483646)) {
          d_st.site = &hb_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }
        for (ia = iac; ia <= offsetQR; ia++) {
          c += workingset->ATwset[ia - 1] * xCurrent[ia - iac];
        }
        k = div_nde_s32_floor(iac - 1, 7);
        workspace[k] -= c;
      }
    }
    if (mWConstr >= nVar) {
      st.site = &ye_emlrtRSI;
      k = (uint8_T)nVar;
      for (iac = 0; iac < k; iac++) {
        offsetQR = 13 * iac + 1;
        st.site = &ye_emlrtRSI;
        for (idx_row = 0; idx_row < mWConstr; idx_row++) {
          b_tmp = (iac + 7 * idx_row) + 1;
          if ((b_tmp < 1) || (b_tmp > 91)) {
            emlrtDynamicBoundsCheckR2012b(b_tmp, 1, 91, &gc_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          ia = idx_row + offsetQR;
          if ((ia < 1) || (ia > 169)) {
            emlrtDynamicBoundsCheckR2012b(ia, 1, 169, &hc_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          qrmanager->QR[ia - 1] = workingset->ATwset[b_tmp - 1];
        }
      }
      st.site = &ye_emlrtRSI;
      qrmanager->usedPivoting = false;
      qrmanager->mrows = mWConstr;
      qrmanager->ncols = nVar;
      b_st.site = &af_emlrtRSI;
      b_tmp = ((uint8_T)nVar >> 2) << 2;
      ia = b_tmp - 4;
      for (offsetQR = 0; offsetQR <= ia; offsetQR += 4) {
        _mm_storeu_si128(
            (__m128i *)&qrmanager->jpvt[offsetQR],
            _mm_add_epi32(
                _mm_add_epi32(_mm_set1_epi32(offsetQR),
                              _mm_loadu_si128((const __m128i *)&iv[0])),
                _mm_set1_epi32(1)));
      }
      for (offsetQR = b_tmp; offsetQR < k; offsetQR++) {
        qrmanager->jpvt[offsetQR] = offsetQR + 1;
      }
      qrmanager->minRowCol = muIntScalarMin_sint32(mWConstr, nVar);
      b_st.site = &af_emlrtRSI;
      xgeqrf(&b_st, qrmanager->QR, mWConstr, nVar, qrmanager->tau);
      st.site = &ye_emlrtRSI;
      b_st.site = &ae_emlrtRSI;
      computeQ_(&b_st, qrmanager, mWConstr);
      st.site = &ye_emlrtRSI;
      b_st.site = &gf_emlrtRSI;
      c_st.site = &hf_emlrtRSI;
      c = 1.0;
      memcpy(&B[0], &workspace[0], 91U * sizeof(real_T));
      beta1 = 0.0;
      DIAGA1 = 'N';
      TRANSA1 = 'T';
      m_t = (ptrdiff_t)nVar;
      n_t = (ptrdiff_t)2;
      k_t = (ptrdiff_t)mWConstr;
      lda_t = (ptrdiff_t)13;
      ldb_t = (ptrdiff_t)13;
      ldc_t = (ptrdiff_t)13;
      dgemm(&TRANSA1, &DIAGA1, &m_t, &n_t, &k_t, &c, &qrmanager->Q[0], &lda_t,
            &B[0], &ldb_t, &beta1, &workspace[0], &ldc_t);
      st.site = &ye_emlrtRSI;
      b_st.site = &if_emlrtRSI;
      c_st.site = &jf_emlrtRSI;
      c = 1.0;
      DIAGA1 = 'N';
      TRANSA1 = 'N';
      UPLO1 = 'U';
      SIDE1 = 'L';
      m_t = (ptrdiff_t)nVar;
      n_t = (ptrdiff_t)2;
      lda_t = (ptrdiff_t)13;
      ldb_t = (ptrdiff_t)13;
      dtrsm(&SIDE1, &UPLO1, &TRANSA1, &DIAGA1, &m_t, &n_t, &c,
            &qrmanager->QR[0], &lda_t, &workspace[0], &ldb_t);
    } else {
      st.site = &ye_emlrtRSI;
      factorQR(&st, qrmanager, workingset->ATwset, nVar, mWConstr);
      st.site = &ye_emlrtRSI;
      b_st.site = &kf_emlrtRSI;
      computeQ_(&b_st, qrmanager, qrmanager->minRowCol);
      st.site = &ye_emlrtRSI;
      if (mWConstr >= 1) {
        b_st.site = &if_emlrtRSI;
        c_st.site = &jf_emlrtRSI;
        c = 1.0;
        DIAGA1 = 'N';
        TRANSA1 = 'T';
        UPLO1 = 'U';
        SIDE1 = 'L';
        m_t = (ptrdiff_t)mWConstr;
        n_t = (ptrdiff_t)2;
        lda_t = (ptrdiff_t)13;
        ldb_t = (ptrdiff_t)13;
        dtrsm(&SIDE1, &UPLO1, &TRANSA1, &DIAGA1, &m_t, &n_t, &c,
              &qrmanager->QR[0], &lda_t, &workspace[0], &ldb_t);
      }
      st.site = &ye_emlrtRSI;
      if (mWConstr >= 1) {
        b_st.site = &gf_emlrtRSI;
        c_st.site = &hf_emlrtRSI;
        c = 1.0;
        memcpy(&B[0], &workspace[0], 91U * sizeof(real_T));
        beta1 = 0.0;
        DIAGA1 = 'N';
        TRANSA1 = 'N';
        m_t = (ptrdiff_t)nVar;
        n_t = (ptrdiff_t)2;
        k_t = (ptrdiff_t)mWConstr;
        lda_t = (ptrdiff_t)13;
        ldb_t = (ptrdiff_t)13;
        ldc_t = (ptrdiff_t)13;
        dgemm(&TRANSA1, &DIAGA1, &m_t, &n_t, &k_t, &c, &qrmanager->Q[0], &lda_t,
              &B[0], &ldb_t, &beta1, &workspace[0], &ldc_t);
      }
    }
    st.site = &ye_emlrtRSI;
    if (nVar > 2147483646) {
      b_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    offsetQR = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (offsetQR <= (uint8_T)nVar - 1) {
        if (muDoubleScalarIsInf(workspace[offsetQR]) ||
            muDoubleScalarIsNaN(workspace[offsetQR])) {
          nonDegenerateWset = false;
          exitg1 = 1;
        } else {
          c = workspace[offsetQR + 13];
          if (muDoubleScalarIsInf(c) || muDoubleScalarIsNaN(c)) {
            nonDegenerateWset = false;
            exitg1 = 1;
          } else {
            offsetQR++;
          }
        }
      } else {
        offsetQR = nVar - 1;
        b_tmp = (offsetQR + 1) / 2 * 2;
        ia = b_tmp - 2;
        for (k = 0; k <= ia; k += 2) {
          __m128d r;
          __m128d r1;
          r = _mm_loadu_pd(&workspace[k]);
          r1 = _mm_loadu_pd(&xCurrent[k]);
          r = _mm_add_pd(r, r1);
          _mm_storeu_pd(&workspace[k], r);
        }
        for (k = b_tmp; k <= offsetQR; k++) {
          workspace[k] += xCurrent[k];
        }
        st.site = &ye_emlrtRSI;
        c = maxConstraintViolation(&st, workingset, workspace);
        st.site = &ye_emlrtRSI;
        beta1 = b_maxConstraintViolation(&st, workingset, workspace);
        if ((c <= 2.2204460492503131E-16) || (c < beta1)) {
          st.site = &ye_emlrtRSI;
          b_st.site = &oc_emlrtRSI;
          c_st.site = &pc_emlrtRSI;
          k = (uint8_T)nVar;
          memcpy(&xCurrent[0], &workspace[0], (uint32_T)k * sizeof(real_T));
        } else {
          st.site = &ye_emlrtRSI;
          b_st.site = &oc_emlrtRSI;
          c_st.site = &pc_emlrtRSI;
          k = (uint8_T)nVar;
          memcpy(&xCurrent[0], &workspace[13], (uint32_T)k * sizeof(real_T));
        }
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return nonDegenerateWset;
}

/* End of code generation (feasibleX0ForWorkingSet.c) */
