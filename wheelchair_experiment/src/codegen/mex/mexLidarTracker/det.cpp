//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  det.cpp
//
//  Code generation for function 'det'
//


// Include files
#include "det.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

// Variable Definitions
static emlrtRSInfo ae_emlrtRSI = { 21, // lineNo
  "det",                               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/matfun/det.m"// pathName
};

static emlrtRSInfo be_emlrtRSI = { 30, // lineNo
  "xgetrf",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"// pathName 
};

static emlrtRSInfo ce_emlrtRSI = { 36, // lineNo
  "xzgetrf",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzgetrf.m"// pathName 
};

static emlrtRSInfo de_emlrtRSI = { 50, // lineNo
  "xzgetrf",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzgetrf.m"// pathName 
};

static emlrtRSInfo ee_emlrtRSI = { 58, // lineNo
  "xzgetrf",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzgetrf.m"// pathName 
};

static emlrtRSInfo fe_emlrtRSI = { 23, // lineNo
  "ixamax",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+blas/ixamax.m"// pathName 
};

static emlrtRSInfo ge_emlrtRSI = { 24, // lineNo
  "ixamax",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+refblas/ixamax.m"// pathName 
};

static emlrtRSInfo he_emlrtRSI = { 45, // lineNo
  "xgeru",                             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+blas/xgeru.m"// pathName 
};

// Function Definitions
namespace coder
{
  real_T b_det(const emlrtStack *sp, const real_T x[16])
  {
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack d_st;
    emlrtStack e_st;
    emlrtStack f_st;
    emlrtStack g_st;
    emlrtStack h_st;
    emlrtStack st;
    real_T b_x[16];
    real_T y;
    int32_T jp1j;
    int32_T jy;
    int8_T ipiv[4];
    boolean_T isodd;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &ae_emlrtRSI;
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
    memcpy(&b_x[0], &x[0], 16U * sizeof(real_T));
    b_st.site = &be_emlrtRSI;
    ipiv[0] = 1;
    ipiv[1] = 2;
    ipiv[2] = 3;
    for (int32_T j = 0; j < 3; j++) {
      real_T smax;
      int32_T b_tmp;
      int32_T ix;
      int32_T k;
      int32_T n;
      b_tmp = j * 5;
      jp1j = b_tmp + 2;
      n = 4 - j;
      c_st.site = &ce_emlrtRSI;
      d_st.site = &fe_emlrtRSI;
      jy = 0;
      ix = b_tmp;
      smax = muDoubleScalarAbs(b_x[b_tmp]);
      e_st.site = &ge_emlrtRSI;
      for (k = 2; k <= n; k++) {
        real_T s;
        ix++;
        s = muDoubleScalarAbs(b_x[ix]);
        if (s > smax) {
          jy = k - 1;
          smax = s;
        }
      }

      if (b_x[b_tmp + jy] != 0.0) {
        if (jy != 0) {
          jy += j;
          ipiv[j] = static_cast<int8_T>(jy + 1);
          smax = b_x[j];
          b_x[j] = b_x[jy];
          b_x[jy] = smax;
          smax = b_x[j + 4];
          b_x[j + 4] = b_x[jy + 4];
          b_x[jy + 4] = smax;
          smax = b_x[j + 8];
          b_x[j + 8] = b_x[jy + 8];
          b_x[jy + 8] = smax;
          smax = b_x[j + 12];
          b_x[j + 12] = b_x[jy + 12];
          b_x[jy + 12] = smax;
        }

        k = (b_tmp - j) + 4;
        c_st.site = &de_emlrtRSI;
        for (jy = jp1j; jy <= k; jy++) {
          b_x[jy - 1] /= b_x[b_tmp];
        }
      }

      n = 2 - j;
      jy = b_tmp + 4;
      c_st.site = &ee_emlrtRSI;
      d_st.site = &he_emlrtRSI;
      e_st.site = &ie_emlrtRSI;
      f_st.site = &je_emlrtRSI;
      jp1j = b_tmp + 6;
      g_st.site = &le_emlrtRSI;
      for (int32_T b_j = 0; b_j <= n; b_j++) {
        smax = b_x[jy];
        if (b_x[jy] != 0.0) {
          ix = b_tmp + 1;
          k = (jp1j - j) + 2;
          g_st.site = &ke_emlrtRSI;
          if ((jp1j <= k) && (k > 2147483646)) {
            h_st.site = &jc_emlrtRSI;
            check_forloop_overflow_error(&h_st);
          }

          for (int32_T ijA = jp1j; ijA <= k; ijA++) {
            b_x[ijA - 1] += b_x[ix] * -smax;
            ix++;
          }
        }

        jy += 4;
        jp1j += 4;
      }
    }

    isodd = (ipiv[0] > 1);
    if (ipiv[1] > 2) {
      isodd = !isodd;
    }

    y = b_x[0] * b_x[5] * b_x[10] * b_x[15];
    if (ipiv[2] > 3) {
      isodd = !isodd;
    }

    if (isodd) {
      y = -y;
    }

    return y;
  }

  real_T det(const emlrtStack *sp, const real_T x[9])
  {
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack d_st;
    emlrtStack e_st;
    emlrtStack f_st;
    emlrtStack g_st;
    emlrtStack h_st;
    emlrtStack st;
    real_T b_x[9];
    real_T y;
    int32_T jp1j;
    int32_T jy;
    int8_T ipiv[3];
    boolean_T isodd;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &ae_emlrtRSI;
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
    memcpy(&b_x[0], &x[0], 9U * sizeof(real_T));
    b_st.site = &be_emlrtRSI;
    ipiv[0] = 1;
    ipiv[1] = 2;
    for (int32_T j = 0; j < 2; j++) {
      real_T smax;
      int32_T b_tmp;
      int32_T ix;
      int32_T k;
      int32_T n;
      b_tmp = j << 2;
      jp1j = b_tmp + 2;
      n = 3 - j;
      c_st.site = &ce_emlrtRSI;
      d_st.site = &fe_emlrtRSI;
      jy = 0;
      ix = b_tmp;
      smax = muDoubleScalarAbs(b_x[b_tmp]);
      e_st.site = &ge_emlrtRSI;
      for (k = 2; k <= n; k++) {
        real_T s;
        ix++;
        s = muDoubleScalarAbs(b_x[ix]);
        if (s > smax) {
          jy = k - 1;
          smax = s;
        }
      }

      if (b_x[b_tmp + jy] != 0.0) {
        if (jy != 0) {
          jy += j;
          ipiv[j] = static_cast<int8_T>(jy + 1);
          smax = b_x[j];
          b_x[j] = b_x[jy];
          b_x[jy] = smax;
          smax = b_x[j + 3];
          b_x[j + 3] = b_x[jy + 3];
          b_x[jy + 3] = smax;
          smax = b_x[j + 6];
          b_x[j + 6] = b_x[jy + 6];
          b_x[jy + 6] = smax;
        }

        k = (b_tmp - j) + 3;
        c_st.site = &de_emlrtRSI;
        for (jy = jp1j; jy <= k; jy++) {
          b_x[jy - 1] /= b_x[b_tmp];
        }
      }

      n = 1 - j;
      jy = b_tmp + 3;
      c_st.site = &ee_emlrtRSI;
      d_st.site = &he_emlrtRSI;
      e_st.site = &ie_emlrtRSI;
      f_st.site = &je_emlrtRSI;
      jp1j = b_tmp + 5;
      g_st.site = &le_emlrtRSI;
      for (int32_T b_j = 0; b_j <= n; b_j++) {
        smax = b_x[jy];
        if (b_x[jy] != 0.0) {
          ix = b_tmp + 1;
          k = (jp1j - j) + 1;
          g_st.site = &ke_emlrtRSI;
          if ((jp1j <= k) && (k > 2147483646)) {
            h_st.site = &jc_emlrtRSI;
            check_forloop_overflow_error(&h_st);
          }

          for (int32_T ijA = jp1j; ijA <= k; ijA++) {
            b_x[ijA - 1] += b_x[ix] * -smax;
            ix++;
          }
        }

        jy += 3;
        jp1j += 3;
      }
    }

    isodd = (ipiv[0] > 1);
    y = b_x[0] * b_x[4] * b_x[8];
    if (ipiv[1] > 2) {
      isodd = !isodd;
    }

    if (isodd) {
      y = -y;
    }

    return y;
  }
}

// End of code generation (det.cpp)
