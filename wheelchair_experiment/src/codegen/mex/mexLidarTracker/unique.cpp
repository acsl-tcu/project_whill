//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  unique.cpp
//
//  Code generation for function 'unique'
//


// Include files
#include "unique.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <math.h>

// Variable Definitions
static emlrtRSInfo hn_emlrtRSI = { 158,// lineNo
  "unique_vector",                     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"// pathName
};

static emlrtRSInfo in_emlrtRSI = { 160,// lineNo
  "unique_vector",                     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"// pathName
};

static emlrtRSInfo jn_emlrtRSI = { 202,// lineNo
  "unique_vector",                     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"// pathName
};

static emlrtRSInfo kn_emlrtRSI = { 215,// lineNo
  "unique_vector",                     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"// pathName
};

static emlrtRSInfo ln_emlrtRSI = { 226,// lineNo
  "unique_vector",                     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"// pathName
};

static emlrtRSInfo mn_emlrtRSI = { 234,// lineNo
  "unique_vector",                     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"// pathName
};

static emlrtRSInfo nn_emlrtRSI = { 240,// lineNo
  "unique_vector",                     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"// pathName
};

static emlrtRSInfo on_emlrtRSI = { 145,// lineNo
  "sortIdx",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"// pathName 
};

static emlrtRSInfo ay_emlrtRSI = { 177,// lineNo
  "unique_vector",                     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"// pathName
};

static emlrtRSInfo by_emlrtRSI = { 195,// lineNo
  "unique_vector",                     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"// pathName
};

static emlrtRSInfo cy_emlrtRSI = { 40, // lineNo
  "safeEq",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/safeEq.m"// pathName 
};

static emlrtRTEInfo pb_emlrtRTEI = { 233,// lineNo
  1,                                   // colNo
  "unique_vector",                     // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"// pName
};

static emlrtRTEInfo sh_emlrtRTEI = { 158,// lineNo
  1,                                   // colNo
  "unique",                            // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"// pName
};

static emlrtRTEInfo uh_emlrtRTEI = { 159,// lineNo
  20,                                  // colNo
  "unique",                            // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"// pName
};

static emlrtRTEInfo vh_emlrtRTEI = { 234,// lineNo
  1,                                   // colNo
  "unique",                            // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"// pName
};

// Function Definitions
namespace coder
{
  void unique_vector(const emlrtStack *sp, const ::coder::array<uint32_T, 1U> &a,
                     ::coder::array<uint32_T, 1U> &b)
  {
    array<int32_T, 1U> idx;
    array<int32_T, 1U> iwork;
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack d_st;
    emlrtStack st;
    int32_T b_iv[2];
    int32_T b_i;
    int32_T i;
    int32_T i2;
    int32_T k;
    int32_T n;
    int32_T na;
    int32_T qEnd;
    st.prev = sp;
    st.tls = sp->tls;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    d_st.prev = &c_st;
    d_st.tls = c_st.tls;
    emlrtHeapReferenceStackEnterFcnR2012b(sp);
    na = a.size(0);
    st.site = &hn_emlrtRSI;
    n = a.size(0) + 1;
    idx.set_size(&sh_emlrtRTEI, &st, a.size(0));
    i = a.size(0);
    for (b_i = 0; b_i < i; b_i++) {
      idx[b_i] = 0;
    }

    if (a.size(0) != 0) {
      b_st.site = &on_emlrtRSI;
      iwork.set_size(&th_emlrtRTEI, &b_st, a.size(0));
      i = a.size(0) - 1;
      c_st.site = &pn_emlrtRSI;
      if ((1 <= a.size(0) - 1) && (a.size(0) - 1 > 2147483645)) {
        d_st.site = &jc_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      for (k = 1; k <= i; k += 2) {
        if (a[k - 1] <= a[k]) {
          idx[k - 1] = k;
          idx[k] = k + 1;
        } else {
          idx[k - 1] = k + 1;
          idx[k] = k;
        }
      }

      if ((a.size(0) & 1) != 0) {
        idx[a.size(0) - 1] = a.size(0);
      }

      i = 2;
      while (i < n - 1) {
        int32_T j;
        i2 = i << 1;
        j = 1;
        for (int32_T pEnd = i + 1; pEnd < n; pEnd = qEnd + i) {
          int32_T kEnd;
          int32_T p;
          int32_T q;
          p = j;
          q = pEnd;
          qEnd = j + i2;
          if (qEnd > n) {
            qEnd = n;
          }

          k = 0;
          kEnd = qEnd - j;
          while (k + 1 <= kEnd) {
            int32_T i1;
            b_i = idx[q - 1];
            i1 = idx[p - 1];
            if (a[i1 - 1] <= a[b_i - 1]) {
              iwork[k] = i1;
              p++;
              if (p == pEnd) {
                while (q < qEnd) {
                  k++;
                  iwork[k] = idx[q - 1];
                  q++;
                }
              }
            } else {
              iwork[k] = b_i;
              q++;
              if (q == qEnd) {
                while (p < pEnd) {
                  k++;
                  iwork[k] = idx[p - 1];
                  p++;
                }
              }
            }

            k++;
          }

          c_st.site = &qn_emlrtRSI;
          for (k = 0; k < kEnd; k++) {
            idx[(j + k) - 1] = iwork[k];
          }

          j = qEnd;
        }

        i = i2;
      }
    }

    b.set_size(&uh_emlrtRTEI, sp, a.size(0));
    st.site = &in_emlrtRSI;
    if ((1 <= a.size(0)) && (a.size(0) > 2147483646)) {
      b_st.site = &jc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (k = 0; k < na; k++) {
      b[k] = a[idx[k] - 1];
    }

    i2 = 0;
    k = 0;
    while (k + 1 <= na) {
      uint32_T x;
      x = b[k];
      i = k;
      do {
        k++;
      } while (!((k + 1 > na) || (b[k] != x)));

      i2++;
      b[i2 - 1] = x;
      st.site = &jn_emlrtRSI;
      if ((i + 1 <= k) && (k > 2147483646)) {
        b_st.site = &jc_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
    }

    st.site = &ln_emlrtRSI;
    if (i2 > a.size(0)) {
      emlrtErrorWithMessageIdR2018a(sp, &pb_emlrtRTEI,
        "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
    }

    if (1 > i2) {
      b_i = 0;
    } else {
      b_i = i2;
    }

    b_iv[0] = 1;
    b_iv[1] = b_i;
    st.site = &mn_emlrtRSI;
    internal::indexShapeCheck(&st, b.size(0), b_iv);
    b.set_size(&vh_emlrtRTEI, sp, b_i);
    st.site = &nn_emlrtRSI;
    if ((1 <= i2) && (i2 > 2147483646)) {
      b_st.site = &jc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  }

  void unique_vector(const emlrtStack *sp, const ::coder::array<real_T, 2U> &a, ::
                     coder::array<real_T, 2U> &b)
  {
    array<int32_T, 2U> idx;
    array<int32_T, 1U> iwork;
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack d_st;
    emlrtStack st;
    real_T absx;
    int32_T b_i;
    int32_T exponent;
    int32_T i;
    int32_T i2;
    int32_T j;
    int32_T k;
    int32_T n;
    int32_T na;
    int32_T p;
    int32_T pEnd;
    int32_T q;
    int32_T qEnd;
    boolean_T exitg1;
    st.prev = sp;
    st.tls = sp->tls;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    d_st.prev = &c_st;
    d_st.tls = c_st.tls;
    emlrtHeapReferenceStackEnterFcnR2012b(sp);
    na = a.size(1);
    st.site = &hn_emlrtRSI;
    n = a.size(1) + 1;
    idx.set_size(&sh_emlrtRTEI, &st, 1, a.size(1));
    i = a.size(1);
    for (b_i = 0; b_i < i; b_i++) {
      idx[b_i] = 0;
    }

    if (a.size(1) != 0) {
      b_st.site = &on_emlrtRSI;
      iwork.set_size(&th_emlrtRTEI, &b_st, a.size(1));
      i = a.size(1) - 1;
      c_st.site = &pn_emlrtRSI;
      if ((1 <= a.size(1) - 1) && (a.size(1) - 1 > 2147483645)) {
        d_st.site = &jc_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      for (k = 1; k <= i; k += 2) {
        absx = a[k];
        if ((a[k - 1] <= absx) || muDoubleScalarIsNaN(absx)) {
          idx[k - 1] = k;
          idx[k] = k + 1;
        } else {
          idx[k - 1] = k + 1;
          idx[k] = k;
        }
      }

      if ((a.size(1) & 1) != 0) {
        idx[a.size(1) - 1] = a.size(1);
      }

      i = 2;
      while (i < n - 1) {
        i2 = i << 1;
        j = 1;
        for (pEnd = i + 1; pEnd < n; pEnd = qEnd + i) {
          int32_T kEnd;
          p = j;
          q = pEnd - 1;
          qEnd = j + i2;
          if (qEnd > n) {
            qEnd = n;
          }

          k = 0;
          kEnd = qEnd - j;
          while (k + 1 <= kEnd) {
            absx = a[idx[q] - 1];
            b_i = idx[p - 1];
            if ((a[b_i - 1] <= absx) || muDoubleScalarIsNaN(absx)) {
              iwork[k] = b_i;
              p++;
              if (p == pEnd) {
                while (q + 1 < qEnd) {
                  k++;
                  iwork[k] = idx[q];
                  q++;
                }
              }
            } else {
              iwork[k] = idx[q];
              q++;
              if (q + 1 == qEnd) {
                while (p < pEnd) {
                  k++;
                  iwork[k] = idx[p - 1];
                  p++;
                }
              }
            }

            k++;
          }

          c_st.site = &qn_emlrtRSI;
          for (k = 0; k < kEnd; k++) {
            idx[(j + k) - 1] = iwork[k];
          }

          j = qEnd;
        }

        i = i2;
      }
    }

    b.set_size(&uh_emlrtRTEI, sp, 1, a.size(1));
    st.site = &in_emlrtRSI;
    if ((1 <= a.size(1)) && (a.size(1) > 2147483646)) {
      b_st.site = &jc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (k = 0; k < na; k++) {
      b[k] = a[idx[k] - 1];
    }

    k = 0;
    while ((k + 1 <= na) && muDoubleScalarIsInf(b[k]) && (b[k] < 0.0)) {
      k++;
    }

    pEnd = k;
    k = a.size(1);
    while ((k >= 1) && muDoubleScalarIsNaN(b[k - 1])) {
      k--;
    }

    p = a.size(1) - k;
    exitg1 = false;
    while ((!exitg1) && (k >= 1)) {
      absx = b[k - 1];
      if (muDoubleScalarIsInf(absx) && (absx > 0.0)) {
        k--;
      } else {
        exitg1 = true;
      }
    }

    i = (a.size(1) - k) - p;
    q = 0;
    if (pEnd > 0) {
      q = 1;
      st.site = &ay_emlrtRSI;
      if (pEnd > 2147483646) {
        b_st.site = &jc_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
    }

    while (pEnd + 1 <= k) {
      real_T x;
      x = b[pEnd];
      i2 = pEnd;
      int32_T exitg2;
      do {
        exitg2 = 0;
        pEnd++;
        if (pEnd + 1 > k) {
          exitg2 = 1;
        } else {
          boolean_T b_p;
          st.site = &by_emlrtRSI;
          b_st.site = &cy_emlrtRSI;
          c_st.site = &yd_emlrtRSI;
          absx = muDoubleScalarAbs(x / 2.0);
          if ((!muDoubleScalarIsInf(absx)) && (!muDoubleScalarIsNaN(absx))) {
            if (absx <= 2.2250738585072014E-308) {
              absx = 4.94065645841247E-324;
            } else {
              frexp(absx, &exponent);
              absx = ldexp(1.0, exponent - 53);
            }
          } else {
            absx = rtNaN;
          }

          if ((muDoubleScalarAbs(x - b[pEnd]) < absx) || (muDoubleScalarIsInf
               (b[pEnd]) && muDoubleScalarIsInf(x) && ((b[pEnd] > 0.0) == (x >
                 0.0)))) {
            b_p = true;
          } else {
            b_p = false;
          }

          if (!b_p) {
            exitg2 = 1;
          }
        }
      } while (exitg2 == 0);

      q++;
      b[q - 1] = x;
      st.site = &jn_emlrtRSI;
      if ((i2 + 1 <= pEnd) && (pEnd > 2147483646)) {
        b_st.site = &jc_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
    }

    if (i > 0) {
      q++;
      b[q - 1] = b[k];
      st.site = &kn_emlrtRSI;
      if (i > 2147483646) {
        b_st.site = &jc_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
    }

    pEnd = k + i;
    st.site = &ln_emlrtRSI;
    if ((1 <= p) && (p > 2147483646)) {
      b_st.site = &jc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (j = 0; j < p; j++) {
      q++;
      b[q - 1] = b[pEnd + j];
    }

    if (q > a.size(1)) {
      emlrtErrorWithMessageIdR2018a(sp, &pb_emlrtRTEI,
        "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
    }

    if (1 > q) {
      b_i = 0;
    } else {
      b_i = q;
    }

    b.set_size(&vh_emlrtRTEI, sp, b.size(0), b_i);
    st.site = &nn_emlrtRSI;
    if ((1 <= q) && (q > 2147483646)) {
      b_st.site = &jc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  }
}

// End of code generation (unique.cpp)
