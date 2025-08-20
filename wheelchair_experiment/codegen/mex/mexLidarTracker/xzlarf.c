/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzlarf.c
 *
 * Code generation for function 'xzlarf'
 *
 */

/* Include files */
#include "xzlarf.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_mexutil.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo um_emlrtRSI = {
    121,      /* lineNo */
    "ilazlr", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzlarf.m" /* pathName */
};

static emlrtRSInfo en_emlrtRSI = {
    103,      /* lineNo */
    "ilazlc", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzlarf.m" /* pathName */
};

static emlrtRSInfo gn_emlrtRSI =
    {
        71,      /* lineNo */
        "xgemv", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgemv.m" /* pathName */
};

/* Function Definitions */
int32_T b_ilazlc(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[27],
                 int32_T ia0)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T j;
  boolean_T exitg2;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  j = n;
  exitg2 = false;
  while ((!exitg2) && (j > 0)) {
    int32_T colbottom;
    int32_T coltop;
    int32_T exitg1;
    coltop = ia0 + (j - 1) * 9;
    colbottom = (coltop + m) - 1;
    st.site = &en_emlrtRSI;
    if ((coltop <= colbottom) && (colbottom > 2147483646)) {
      b_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    do {
      exitg1 = 0;
      if (coltop <= colbottom) {
        if (A[coltop - 1] != 0.0) {
          exitg1 = 1;
        } else {
          coltop++;
        }
      } else {
        j--;
        exitg1 = 2;
      }
    } while (exitg1 == 0);
    if (exitg1 == 1) {
      exitg2 = true;
    }
  }
  return j;
}

void b_xzlarf(const emlrtStack *sp, int32_T m, int32_T n, int32_T iv0,
              real_T tau, real_T C[36], int32_T ic0, real_T work[6])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  int32_T colbottom;
  int32_T i;
  int32_T iac;
  int32_T lastc;
  int32_T lastv;
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
  if (tau != 0.0) {
    boolean_T exitg2;
    lastv = m - 1;
    i = iv0 + m;
    while ((lastv + 1 > 0) && (C[i - 2] == 0.0)) {
      lastv--;
      i--;
    }
    st.site = &dn_emlrtRSI;
    lastc = n;
    exitg2 = false;
    while ((!exitg2) && (lastc > 0)) {
      int32_T exitg1;
      i = ic0 + (lastc - 1) * 6;
      colbottom = i + lastv;
      b_st.site = &en_emlrtRSI;
      if ((i <= colbottom) && (colbottom > 2147483646)) {
        c_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      do {
        exitg1 = 0;
        if (i <= colbottom) {
          if (C[i - 1] != 0.0) {
            exitg1 = 1;
          } else {
            i++;
          }
        } else {
          lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);
      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    lastv = -1;
    lastc = 0;
  }
  if (lastv + 1 > 0) {
    real_T c;
    int32_T b_i;
    st.site = &cn_emlrtRSI;
    b_st.site = &vm_emlrtRSI;
    if (lastc != 0) {
      c_st.site = &ym_emlrtRSI;
      if (lastc > 2147483646) {
        d_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      b_i = (uint8_T)lastc;
      memset(&work[0], 0, (uint32_T)b_i * sizeof(real_T));
      b_i = ic0 + 6 * (lastc - 1);
      for (iac = ic0; iac <= b_i; iac += 6) {
        c = 0.0;
        colbottom = iac + lastv;
        c_st.site = &fn_emlrtRSI;
        if ((iac <= colbottom) && (colbottom > 2147483646)) {
          d_st.site = &mb_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }
        for (i = iac; i <= colbottom; i++) {
          c += C[i - 1] * C[((iv0 + i) - iac) - 1];
        }
        i = div_nde_s32_floor(iac - ic0, 6);
        work[i] += c;
      }
    }
    st.site = &bn_emlrtRSI;
    b_st.site = &an_emlrtRSI;
    c_st.site = &le_emlrtRSI;
    d_st.site = &me_emlrtRSI;
    if (!(-tau == 0.0)) {
      i = ic0;
      e_st.site = &oe_emlrtRSI;
      b_i = (uint8_T)lastc;
      for (lastc = 0; lastc < b_i; lastc++) {
        c = work[lastc];
        if (c != 0.0) {
          c *= -tau;
          colbottom = lastv + i;
          e_st.site = &ne_emlrtRSI;
          if ((i <= colbottom) && (colbottom > 2147483646)) {
            f_st.site = &mb_emlrtRSI;
            check_forloop_overflow_error(&f_st);
          }
          for (iac = i; iac <= colbottom; iac++) {
            C[iac - 1] += C[((iv0 + iac) - i) - 1] * c;
          }
        }
        i += 6;
      }
    }
  }
}

int32_T ilazlc(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[54],
               int32_T ia0)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T j;
  boolean_T exitg2;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  j = n;
  exitg2 = false;
  while ((!exitg2) && (j > 0)) {
    int32_T colbottom;
    int32_T coltop;
    int32_T exitg1;
    coltop = ia0 + (j - 1) * 9;
    colbottom = (coltop + m) - 1;
    st.site = &en_emlrtRSI;
    if ((coltop <= colbottom) && (colbottom > 2147483646)) {
      b_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    do {
      exitg1 = 0;
      if (coltop <= colbottom) {
        if (A[coltop - 1] != 0.0) {
          exitg1 = 1;
        } else {
          coltop++;
        }
      } else {
        j--;
        exitg1 = 2;
      }
    } while (exitg1 == 0);
    if (exitg1 == 1) {
      exitg2 = true;
    }
  }
  return j;
}

int32_T ilazlr(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[9],
               int32_T ia0)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T i;
  boolean_T exitg2;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  i = m;
  exitg2 = false;
  while ((!exitg2) && (i > 0)) {
    int32_T exitg1;
    int32_T rowleft;
    int32_T rowright;
    rowleft = (ia0 + i) - 1;
    rowright = rowleft + (n - 1) * 3;
    st.site = &um_emlrtRSI;
    if ((rowleft <= rowright) && (rowright > 2147483644)) {
      b_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    do {
      exitg1 = 0;
      if (rowleft <= rowright) {
        if (A[rowleft - 1] != 0.0) {
          exitg1 = 1;
        } else {
          rowleft += 3;
        }
      } else {
        i--;
        exitg1 = 2;
      }
    } while (exitg1 == 0);
    if (exitg1 == 1) {
      exitg2 = true;
    }
  }
  return i;
}

void xzlarf(const emlrtStack *sp, int32_T m, int32_T n, int32_T iv0, real_T tau,
            real_T C[9], int32_T ic0, real_T work[3])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  int32_T colbottom;
  int32_T i;
  int32_T iac;
  int32_T lastc;
  int32_T lastv;
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
  if (tau != 0.0) {
    boolean_T exitg2;
    lastv = m - 1;
    i = iv0 + m;
    while ((lastv + 1 > 0) && (C[i - 2] == 0.0)) {
      lastv--;
      i--;
    }
    st.site = &dn_emlrtRSI;
    lastc = n;
    exitg2 = false;
    while ((!exitg2) && (lastc > 0)) {
      int32_T exitg1;
      i = ic0 + (lastc - 1) * 3;
      colbottom = i + lastv;
      b_st.site = &en_emlrtRSI;
      if ((i <= colbottom) && (colbottom > 2147483646)) {
        c_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      do {
        exitg1 = 0;
        if (i <= colbottom) {
          if (C[i - 1] != 0.0) {
            exitg1 = 1;
          } else {
            i++;
          }
        } else {
          lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);
      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    lastv = -1;
    lastc = 0;
  }
  if (lastv + 1 > 0) {
    real_T c;
    int32_T b;
    st.site = &cn_emlrtRSI;
    b_st.site = &vm_emlrtRSI;
    if (lastc != 0) {
      c_st.site = &ym_emlrtRSI;
      if (lastc > 2147483646) {
        d_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      colbottom = (uint8_T)lastc;
      memset(&work[0], 0, (uint32_T)colbottom * sizeof(real_T));
      b = ic0 + 3 * (lastc - 1);
      c_st.site = &gn_emlrtRSI;
      if ((ic0 <= b) && (b > 2147483644)) {
        d_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (iac = ic0; iac <= b; iac += 3) {
        c = 0.0;
        i = iac + lastv;
        c_st.site = &fn_emlrtRSI;
        if ((iac <= i) && (i > 2147483646)) {
          d_st.site = &mb_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }
        for (colbottom = iac; colbottom <= i; colbottom++) {
          c += C[colbottom - 1] * C[((iv0 + colbottom) - iac) - 1];
        }
        colbottom = div_nde_s32_floor(iac - ic0, 3);
        work[colbottom] += c;
      }
    }
    st.site = &bn_emlrtRSI;
    b_st.site = &an_emlrtRSI;
    c_st.site = &le_emlrtRSI;
    d_st.site = &me_emlrtRSI;
    if (!(-tau == 0.0)) {
      i = ic0;
      e_st.site = &oe_emlrtRSI;
      colbottom = (uint8_T)lastc;
      for (lastc = 0; lastc < colbottom; lastc++) {
        c = work[lastc];
        if (c != 0.0) {
          c *= -tau;
          b = lastv + i;
          e_st.site = &ne_emlrtRSI;
          if ((i <= b) && (b > 2147483646)) {
            f_st.site = &mb_emlrtRSI;
            check_forloop_overflow_error(&f_st);
          }
          for (iac = i; iac <= b; iac++) {
            C[iac - 1] += C[((iv0 + iac) - i) - 1] * c;
          }
        }
        i += 3;
      }
    }
  }
}

/* End of code generation (xzlarf.c) */
