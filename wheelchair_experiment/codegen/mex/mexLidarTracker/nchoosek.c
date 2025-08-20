/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nchoosek.c
 *
 * Code generation for function 'nchoosek'
 *
 */

/* Include files */
#include "nchoosek.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo fw_emlrtRSI = {
    56,         /* lineNo */
    "nchoosek", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/specfun/nchoosek.m" /* pathName
                                                                          */
};

static emlrtRSInfo gw_emlrtRSI = {
    141,   /* lineNo */
    "nCk", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/specfun/nchoosek.m" /* pathName
                                                                          */
};

static emlrtRSInfo hw_emlrtRSI = {
    142,   /* lineNo */
    "nCk", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/specfun/nchoosek.m" /* pathName
                                                                          */
};

static emlrtRSInfo iw_emlrtRSI = {
    129,   /* lineNo */
    "nCk", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/specfun/nchoosek.m" /* pathName
                                                                          */
};

static emlrtRSInfo jw_emlrtRSI = {
    153,        /* lineNo */
    "nCkInt64", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/specfun/nchoosek.m" /* pathName
                                                                          */
};

static emlrtMCInfo d_emlrtMCI = {
    53,        /* lineNo */
    19,        /* colNo */
    "flt2str", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/flt2str.m" /* pName
                                                                           */
};

static emlrtRTEInfo cc_emlrtRTEI = {
    38,         /* lineNo */
    26,         /* colNo */
    "nchoosek", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/specfun/nchoosek.m" /* pName
                                                                          */
};

static emlrtRTEInfo dc_emlrtRTEI = {
    17,         /* lineNo */
    23,         /* colNo */
    "nchoosek", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/specfun/nchoosek.m" /* pName
                                                                          */
};

static emlrtRTEInfo lp_emlrtRTEI = {
    154,        /* lineNo */
    9,          /* colNo */
    "nCkInt64", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/specfun/nchoosek.m" /* pName
                                                                          */
};

static emlrtRTEInfo mp_emlrtRTEI = {
    155,        /* lineNo */
    13,         /* colNo */
    "nCkInt64", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/specfun/nchoosek.m" /* pName
                                                                          */
};

static emlrtRTEInfo np_emlrtRTEI = {
    161,        /* lineNo */
    9,          /* colNo */
    "nCkInt64", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/specfun/nchoosek.m" /* pName
                                                                          */
};

static emlrtRTEInfo op_emlrtRTEI =
    {
        102,      /* lineNo */
        9,        /* colNo */
        "intmod", /* fName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+scalar/"
        "mod.m" /* pName */
};

static emlrtRSInfo fqb_emlrtRSI = {
    53,        /* lineNo */
    "flt2str", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/flt2str.m" /* pathName
                                                                           */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               char_T y[23]);

static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *m1,
                                const mxArray *m2, emlrtMCInfo *location);

static void emlrt_marshallIn(const emlrtStack *sp,
                             const mxArray *a__output_of_sprintf_,
                             const char_T *identifier, char_T y[23]);

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[23]);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[23])
{
  k_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *m1,
                                const mxArray *m2, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m;
  pArrays[0] = m1;
  pArrays[1] = m2;
  return emlrtCallMATLABR2012b((emlrtConstCTX)sp, 1, &m, 2, &pArrays[0],
                               "sprintf", true, location);
}

static void emlrt_marshallIn(const emlrtStack *sp,
                             const mxArray *a__output_of_sprintf_,
                             const char_T *identifier, char_T y[23])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(a__output_of_sprintf_), &thisId, y);
  emlrtDestroyArray(&a__output_of_sprintf_);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[23])
{
  static const int32_T dims[2] = {1, 23};
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "char", false, 2U,
                          (const void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtConstCTX)sp, src, &ret[0], 23);
  emlrtDestroyArray(&src);
}

real_T nchoosek(const emlrtStack *sp, real_T x, real_T k)
{
  static const int32_T b_iv[2] = {1, 7};
  static const int32_T b_iv1[2] = {1, 7};
  static const char_T rfmt[7] = {'%', '2', '3', '.', '1', '5', 'e'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *m;
  real_T r;
  real_T y;
  uint64_T u;
  uint64_T u1;
  int32_T j;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if ((!(k >= 0.0)) || (!(k == muDoubleScalarFloor(k)))) {
    emlrtErrorWithMessageIdR2018a(sp, &dc_emlrtRTEI,
                                  "MATLAB:nchoosek:InvalidArg2",
                                  "MATLAB:nchoosek:InvalidArg2", 0);
  }
  if (!(k <= x)) {
    emlrtErrorWithMessageIdR2018a(sp, &cc_emlrtRTEI,
                                  "MATLAB:nchoosek:KOutOfRange",
                                  "MATLAB:nchoosek:KOutOfRange", 0);
  }
  r = k;
  if (k > x - k) {
    r = x - k;
  }
  if (r == 0.0) {
    y = 1.0;
  } else if (r == 1.0) {
    y = x;
  } else {
    st.site = &fw_emlrtRSI;
    if (muDoubleScalarIsInf(x) ||
        (muDoubleScalarIsInf(r) || muDoubleScalarIsNaN(r))) {
      y = rtNaN;
    } else if (r > 1000.0) {
      y = rtInf;
    } else {
      real_T maxRelErr;
      int32_T i;
      maxRelErr = 0.0;
      y = x;
      i = (int32_T)(r - 1.0);
      for (j = 0; j < i; j++) {
        y *= ((x - ((real_T)j + 2.0)) + 1.0) / ((real_T)j + 2.0);
        if (!(y < 1.125899906842624E+15)) {
          maxRelErr += 4.4408920985006262E-16;
        }
        y = muDoubleScalarRound(y);
      }
      if ((maxRelErr != 0.0) && (y <= 3.6893488147419103E+19)) {
        uint64_T b_i;
        uint64_T b_k;
        uint64_T n;
        uint64_T yint;
        boolean_T exitg1;
        b_st.site = &iw_emlrtRSI;
        maxRelErr = muDoubleScalarRound(x);
        if (maxRelErr < 1.8446744073709552E+19) {
          n = (uint64_T)maxRelErr;
        } else {
          n = MAX_uint64_T;
        }
        maxRelErr = muDoubleScalarRound(r);
        if (maxRelErr < 1.8446744073709552E+19) {
          if (maxRelErr >= 0.0) {
            b_k = (uint64_T)maxRelErr;
          } else {
            b_k = 0UL;
          }
        } else {
          b_k = 0UL;
        }
        yint = 1UL;
        c_st.site = &jw_emlrtRSI;
        if (b_k > 18446744073709551614UL) {
          d_st.site = &mb_emlrtRSI;
          b_check_forloop_overflow_error(&d_st);
        }
        b_i = 1UL;
        exitg1 = false;
        while ((!exitg1) && (b_i <= b_k)) {
          if (b_i == 0UL) {
            emlrtDivisionByZeroErrorR2012b(&lp_emlrtRTEI, &b_st);
          } else {
            u = yint / b_i;
          }
          if (n == 0UL) {
            emlrtDivisionByZeroErrorR2012b(&mp_emlrtRTEI, &b_st);
          } else {
            u1 = MAX_uint64_T / n;
          }
          if (u >= u1) {
            yint = MAX_uint64_T;
            exitg1 = true;
          } else {
            if (b_i == 0UL) {
              emlrtDivisionByZeroErrorR2012b(&np_emlrtRTEI, &b_st);
            } else {
              if (b_i == 0UL) {
                emlrtDivisionByZeroErrorR2012b(&op_emlrtRTEI, &b_st);
              } else {
                u1 = yint / b_i;
              }
              u1 = (yint - u1 * b_i) * n / b_i;
            }
            yint = u * n + u1;
            n--;
            b_i++;
          }
        }
        y = (real_T)yint;
        maxRelErr = 0.0;
      }
      if (y > 9.007199254740992E+15) {
        maxRelErr = muDoubleScalarMax(maxRelErr, 2.2204460492503131E-16);
      }
      if ((maxRelErr != 0.0) &&
          ((!muDoubleScalarIsInf(y)) && (!muDoubleScalarIsNaN(y)))) {
        char_T b_str[23];
        char_T str[23];
        b_st.site = &hw_emlrtRSI;
        b_y = NULL;
        m = emlrtCreateCharArray(2, &b_iv[0]);
        emlrtInitCharArrayR2013a(&b_st, 7, m, &rfmt[0]);
        emlrtAssign(&b_y, m);
        c_y = NULL;
        m = emlrtCreateDoubleScalar(maxRelErr);
        emlrtAssign(&c_y, m);
        c_st.site = &fqb_emlrtRSI;
        emlrt_marshallIn(&c_st, b_sprintf(&c_st, b_y, c_y, &d_emlrtMCI),
                         "<output of sprintf>", str);
        b_st.site = &hw_emlrtRSI;
        d_y = NULL;
        m = emlrtCreateCharArray(2, &b_iv1[0]);
        emlrtInitCharArrayR2013a(&b_st, 7, m, &rfmt[0]);
        emlrtAssign(&d_y, m);
        e_y = NULL;
        m = emlrtCreateDoubleScalar(muDoubleScalarCeil(maxRelErr * y));
        emlrtAssign(&e_y, m);
        c_st.site = &fqb_emlrtRSI;
        emlrt_marshallIn(&c_st, b_sprintf(&c_st, d_y, e_y, &d_emlrtMCI),
                         "<output of sprintf>", b_str);
        b_st.site = &gw_emlrtRSI;
        c_warning(&b_st, str, b_str);
      }
    }
  }
  return y;
}

/* End of code generation (nchoosek.c) */
