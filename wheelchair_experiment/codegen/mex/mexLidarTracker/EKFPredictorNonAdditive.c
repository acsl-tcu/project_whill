/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EKFPredictorNonAdditive.c
 *
 * Code generation for function 'EKFPredictorNonAdditive'
 *
 */

/* Include files */
#include "EKFPredictorNonAdditive.h"
#include "constvel.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "validateattributes.h"
#include "xgemv.h"
#include "xgerc.h"
#include "xnrm2.h"
#include "xscal.h"
#include "xzlarf.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo udb_emlrtRSI = {
    64,                                /* lineNo */
    "EKFPredictorNonAdditive/predict", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/EKFPredictorNonAdditive.m" /* pathName */
};

static emlrtRSInfo vdb_emlrtRSI = {
    66,                                /* lineNo */
    "EKFPredictorNonAdditive/predict", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/EKFPredictorNonAdditive.m" /* pathName */
};

static emlrtRSInfo wdb_emlrtRSI = {
    67,                                /* lineNo */
    "EKFPredictorNonAdditive/predict", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/EKFPredictorNonAdditive.m" /* pathName */
};

static emlrtRSInfo xdb_emlrtRSI = {
    102,                                          /* lineNo */
    "EKFPredictorNonAdditive/predictionMatrices", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/EKFPredictorNonAdditive.m" /* pathName */
};

/* Function Definitions */
void EKFPredictorNonAdditive_predict(const emlrtStack *sp, const real_T Qs[9],
                                     real_T x[6], real_T S[36],
                                     real_T varargin_1, real_T dFdx[36])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack st;
  real_T M[54];
  real_T y[36];
  real_T b_dFdw[18];
  real_T dFdw[18];
  real_T tau[6];
  real_T work[6];
  real_T B_idx_0;
  real_T atmp;
  real_T d;
  int32_T aoffset;
  int32_T coffset;
  int32_T i;
  int32_T ii;
  int32_T j;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &udb_emlrtRSI;
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
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  b_st.site = &xdb_emlrtRSI;
  c_st.site = &rdb_emlrtRSI;
  b_validateattributes(&c_st, x);
  c_st.site = &sdb_emlrtRSI;
  d_st.site = &jc_emlrtRSI;
  if (muDoubleScalarIsInf(varargin_1) || muDoubleScalarIsNaN(varargin_1)) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &h_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:constveljac:expectedFinite", 3, 4, 19, "input number 3, dt,");
  }
  c_st.site = &tdb_emlrtRSI;
  d_st.site = &pi_emlrtRSI;
  e_st.site = &qi_emlrtRSI;
  B_idx_0 = varargin_1 * varargin_1 / 2.0;
  memset(&dFdx[0], 0, 36U * sizeof(real_T));
  dFdx[0] = 1.0;
  dFdx[14] = 1.0;
  dFdx[28] = 1.0;
  dFdx[1] = 0.0;
  dFdx[15] = 0.0;
  dFdx[29] = 0.0;
  dFdx[6] = varargin_1;
  dFdx[20] = varargin_1;
  dFdx[34] = varargin_1;
  dFdx[7] = 1.0;
  dFdx[21] = 1.0;
  dFdx[35] = 1.0;
  memset(&dFdw[0], 0, 18U * sizeof(real_T));
  dFdw[0] = B_idx_0;
  dFdw[8] = B_idx_0;
  dFdw[16] = B_idx_0;
  dFdw[1] = varargin_1;
  dFdw[9] = varargin_1;
  dFdw[17] = varargin_1;
  st.site = &vdb_emlrtRSI;
  constvel(&st, x, varargin_1);
  st.site = &wdb_emlrtRSI;
  b_st.site = &ydb_emlrtRSI;
  c_st.site = &ef_emlrtRSI;
  d_st.site = &beb_emlrtRSI;
  e_st.site = &gf_emlrtRSI;
  for (j = 0; j < 6; j++) {
    coffset = j * 6;
    for (i = 0; i < 6; i++) {
      aoffset = i * 6;
      B_idx_0 = 0.0;
      f_st.site = &ceb_emlrtRSI;
      for (k = 0; k < 6; k++) {
        B_idx_0 += S[aoffset + k] * dFdx[k * 6 + j];
      }
      y[coffset + i] = B_idx_0;
    }
  }
  for (aoffset = 0; aoffset < 3; aoffset++) {
    d = Qs[3 * aoffset];
    B_idx_0 = Qs[3 * aoffset + 1];
    atmp = Qs[3 * aoffset + 2];
    for (coffset = 0; coffset < 6; coffset++) {
      b_dFdw[aoffset + 3 * coffset] =
          (dFdw[coffset] * d + dFdw[coffset + 6] * B_idx_0) +
          dFdw[coffset + 12] * atmp;
    }
  }
  for (aoffset = 0; aoffset < 6; aoffset++) {
    for (coffset = 0; coffset < 6; coffset++) {
      M[coffset + 9 * aoffset] = y[coffset + 6 * aoffset];
    }
    M[9 * aoffset + 6] = b_dFdw[3 * aoffset];
    M[9 * aoffset + 7] = b_dFdw[3 * aoffset + 1];
    M[9 * aoffset + 8] = b_dFdw[3 * aoffset + 2];
  }
  b_st.site = &aeb_emlrtRSI;
  c_st.site = &deb_emlrtRSI;
  d_st.site = &eeb_emlrtRSI;
  e_st.site = &feb_emlrtRSI;
  f_st.site = &ieb_emlrtRSI;
  g_st.site = &jeb_emlrtRSI;
  for (i = 0; i < 6; i++) {
    work[i] = 0.0;
  }
  h_st.site = &meb_emlrtRSI;
  for (i = 0; i < 6; i++) {
    ii = i * 9 + i;
    atmp = M[ii];
    h_st.site = &leb_emlrtRSI;
    tau[i] = 0.0;
    i_st.site = &gm_emlrtRSI;
    B_idx_0 = f_xnrm2(&i_st, 8 - i, M, ii + 2);
    if (B_idx_0 != 0.0) {
      d = M[ii];
      B_idx_0 = muDoubleScalarHypot(d, B_idx_0);
      if (d >= 0.0) {
        B_idx_0 = -B_idx_0;
      }
      if (muDoubleScalarAbs(B_idx_0) < 1.0020841800044864E-292) {
        coffset = 0;
        do {
          coffset++;
          i_st.site = &fm_emlrtRSI;
          i_xscal(&i_st, 8 - i, 9.9792015476736E+291, M, ii + 2);
          B_idx_0 *= 9.9792015476736E+291;
          atmp *= 9.9792015476736E+291;
        } while ((muDoubleScalarAbs(B_idx_0) < 1.0020841800044864E-292) &&
                 (coffset < 20));
        i_st.site = &em_emlrtRSI;
        B_idx_0 = f_xnrm2(&i_st, 8 - i, M, ii + 2);
        B_idx_0 = muDoubleScalarHypot(atmp, B_idx_0);
        if (atmp >= 0.0) {
          B_idx_0 = -B_idx_0;
        }
        tau[i] = (B_idx_0 - atmp) / B_idx_0;
        i_st.site = &dm_emlrtRSI;
        i_xscal(&i_st, 8 - i, 1.0 / (atmp - B_idx_0), M, ii + 2);
        for (k = 0; k < coffset; k++) {
          B_idx_0 *= 1.0020841800044864E-292;
        }
        atmp = B_idx_0;
      } else {
        tau[i] = (B_idx_0 - d) / B_idx_0;
        i_st.site = &bm_emlrtRSI;
        i_xscal(&i_st, 8 - i, 1.0 / (M[ii] - B_idx_0), M, ii + 2);
        atmp = B_idx_0;
      }
    }
    M[ii] = atmp;
    if (i + 1 < 6) {
      M[ii] = 1.0;
      h_st.site = &keb_emlrtRSI;
      if (tau[i] != 0.0) {
        aoffset = 9 - i;
        coffset = (ii - i) + 8;
        while ((aoffset > 0) && (M[coffset] == 0.0)) {
          aoffset--;
          coffset--;
        }
        i_st.site = &dn_emlrtRSI;
        coffset = ilazlc(&i_st, aoffset, 5 - i, M, ii + 10);
      } else {
        aoffset = 0;
        coffset = 0;
      }
      if (aoffset > 0) {
        i_st.site = &cn_emlrtRSI;
        b_xgemv(&i_st, aoffset, coffset, M, ii + 10, M, ii + 1, work);
        i_st.site = &bn_emlrtRSI;
        b_xgerc(&i_st, aoffset, coffset, -tau[i], ii + 1, work, M, ii + 10);
      }
      M[ii] = atmp;
    }
  }
  for (j = 0; j < 6; j++) {
    e_st.site = &geb_emlrtRSI;
    for (i = 0; i <= j; i++) {
      y[i + 6 * j] = M[i + 9 * j];
    }
    aoffset = j + 2;
    if (aoffset <= 6) {
      memset(&y[(j * 6 + aoffset) + -1], 0,
             (uint32_T)(-aoffset + 7) * sizeof(real_T));
    }
  }
  e_st.site = &heb_emlrtRSI;
  f_st.site = &neb_emlrtRSI;
  g_st.site = &oeb_emlrtRSI;
  h_st.site = &seb_emlrtRSI;
  for (i = 0; i < 6; i++) {
    work[i] = 0.0;
  }
  for (i = 5; i >= 0; i--) {
    ii = i + i * 9;
    if (i + 1 < 6) {
      M[ii] = 1.0;
      h_st.site = &reb_emlrtRSI;
      if (tau[i] != 0.0) {
        aoffset = 9 - i;
        coffset = ii - i;
        while ((aoffset > 0) && (M[coffset + 8] == 0.0)) {
          aoffset--;
          coffset--;
        }
        i_st.site = &dn_emlrtRSI;
        coffset = ilazlc(&i_st, aoffset, 5 - i, M, ii + 10);
      } else {
        aoffset = 0;
        coffset = 0;
      }
      if (aoffset > 0) {
        i_st.site = &cn_emlrtRSI;
        b_xgemv(&i_st, aoffset, coffset, M, ii + 10, M, ii + 1, work);
        i_st.site = &bn_emlrtRSI;
        b_xgerc(&i_st, aoffset, coffset, -tau[i], ii + 1, work, M, ii + 10);
      }
    }
    d = tau[i];
    h_st.site = &qeb_emlrtRSI;
    i_xscal(&h_st, 8 - i, -d, M, ii + 2);
    M[ii] = 1.0 - d;
    h_st.site = &peb_emlrtRSI;
    for (j = 0; j < i; j++) {
      M[(ii - j) - 1] = 0.0;
    }
  }
  for (aoffset = 0; aoffset < 6; aoffset++) {
    for (coffset = 0; coffset < 6; coffset++) {
      S[coffset + 6 * aoffset] = y[aoffset + 6 * coffset];
    }
  }
}

/* End of code generation (EKFPredictorNonAdditive.c) */
