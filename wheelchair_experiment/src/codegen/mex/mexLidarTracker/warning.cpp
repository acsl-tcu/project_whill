//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  warning.cpp
//
//  Code generation for function 'warning'
//


// Include files
#include "warning.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtMCInfo emlrtMCI = { 14,    // lineNo
  25,                                  // colNo
  "warning",                           // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/coder/coder/lib/+coder/+internal/warning.m"// pName 
};

static emlrtMCInfo b_emlrtMCI = { 14,  // lineNo
  9,                                   // colNo
  "warning",                           // fName
  "/usr/local/MATLAB/R2020b/toolbox/shared/coder/coder/lib/+coder/+internal/warning.m"// pName 
};

static emlrtRSInfo flb_emlrtRSI = { 14,// lineNo
  "warning",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/coder/coder/lib/+coder/+internal/warning.m"// pathName 
};

// Function Declarations
static void b_feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location);
static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location);
static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location);

// Function Definitions
static void b_feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = b;
  pArrays[1] = c;
  emlrtCallMATLABR2012b(sp, 0, NULL, 2, &pArrays[0], "feval", true, location);
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  const mxArray *m;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  return emlrtCallMATLABR2012b(sp, 1, &m, 3, &pArrays[0], "feval", true,
    location);
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m, 2, &pArrays[0], "feval", true,
    location);
}

namespace coder
{
  namespace internal
  {
    void b_warning(const emlrtStack *sp)
    {
      static const int32_T b_iv[2] = { 1, 7 };

      static const int32_T b_iv1[2] = { 1, 7 };

      static const int32_T iv2[2] = { 1, 30 };

      static const char_T msgID[30] = { 'v', 'i', 's', 'i', 'o', 'n', ':', 'p',
        'o', 'i', 'n', 't', 'c', 'l', 'o', 'u', 'd', ':', 'n', 'o', 't', 'E',
        'n', 'o', 'u', 'g', 'h', 'P', 't', 's' };

      static const char_T b_u[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

      static const char_T u[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

      emlrtStack st;
      const mxArray *b_y;
      const mxArray *c_y;
      const mxArray *m;
      const mxArray *y;
      st.prev = sp;
      st.tls = sp->tls;
      y = NULL;
      m = emlrtCreateCharArray(2, &b_iv[0]);
      emlrtInitCharArrayR2013a(sp, 7, m, &u[0]);
      emlrtAssign(&y, m);
      b_y = NULL;
      m = emlrtCreateCharArray(2, &b_iv1[0]);
      emlrtInitCharArrayR2013a(sp, 7, m, &b_u[0]);
      emlrtAssign(&b_y, m);
      c_y = NULL;
      m = emlrtCreateCharArray(2, &iv2[0]);
      emlrtInitCharArrayR2013a(sp, 30, m, &msgID[0]);
      emlrtAssign(&c_y, m);
      st.site = &flb_emlrtRSI;
      b_feval(&st, y, feval(&st, b_y, c_y, &emlrtMCI), &b_emlrtMCI);
    }

    void c_warning(const emlrtStack *sp)
    {
      static const int32_T b_iv[2] = { 1, 7 };

      static const int32_T b_iv1[2] = { 1, 7 };

      static const int32_T iv2[2] = { 1, 34 };

      static const char_T msgID[34] = { 'v', 'i', 's', 'i', 'o', 'n', ':', 'p',
        'o', 'i', 'n', 't', 'c', 'l', 'o', 'u', 'd', ':', 'n', 'o', 't', 'E',
        'n', 'o', 'u', 'g', 'h', 'I', 'n', 'l', 'i', 'e', 'r', 's' };

      static const char_T b_u[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

      static const char_T u[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

      emlrtStack st;
      const mxArray *b_y;
      const mxArray *c_y;
      const mxArray *m;
      const mxArray *y;
      st.prev = sp;
      st.tls = sp->tls;
      y = NULL;
      m = emlrtCreateCharArray(2, &b_iv[0]);
      emlrtInitCharArrayR2013a(sp, 7, m, &u[0]);
      emlrtAssign(&y, m);
      b_y = NULL;
      m = emlrtCreateCharArray(2, &b_iv1[0]);
      emlrtInitCharArrayR2013a(sp, 7, m, &b_u[0]);
      emlrtAssign(&b_y, m);
      c_y = NULL;
      m = emlrtCreateCharArray(2, &iv2[0]);
      emlrtInitCharArrayR2013a(sp, 34, m, &msgID[0]);
      emlrtAssign(&c_y, m);
      st.site = &flb_emlrtRSI;
      b_feval(&st, y, feval(&st, b_y, c_y, &emlrtMCI), &b_emlrtMCI);
    }

    void d_warning(const emlrtStack *sp)
    {
      static const int32_T b_iv[2] = { 1, 7 };

      static const int32_T b_iv1[2] = { 1, 7 };

      static const int32_T iv2[2] = { 1, 26 };

      static const char_T msgID[26] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
        'o', 'l', 'b', 'o', 'x', ':', 's', 'c', 'h', 'u', 'r', '_', 'f', 'a',
        'i', 'l', 'e', 'd' };

      static const char_T b_u[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

      static const char_T u[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

      emlrtStack st;
      const mxArray *b_y;
      const mxArray *c_y;
      const mxArray *m;
      const mxArray *y;
      st.prev = sp;
      st.tls = sp->tls;
      y = NULL;
      m = emlrtCreateCharArray(2, &b_iv[0]);
      emlrtInitCharArrayR2013a(sp, 7, m, &u[0]);
      emlrtAssign(&y, m);
      b_y = NULL;
      m = emlrtCreateCharArray(2, &b_iv1[0]);
      emlrtInitCharArrayR2013a(sp, 7, m, &b_u[0]);
      emlrtAssign(&b_y, m);
      c_y = NULL;
      m = emlrtCreateCharArray(2, &iv2[0]);
      emlrtInitCharArrayR2013a(sp, 26, m, &msgID[0]);
      emlrtAssign(&c_y, m);
      st.site = &flb_emlrtRSI;
      b_feval(&st, y, feval(&st, b_y, c_y, &emlrtMCI), &b_emlrtMCI);
    }

    void e_warning(const emlrtStack *sp)
    {
      static const int32_T b_iv[2] = { 1, 7 };

      static const int32_T b_iv1[2] = { 1, 7 };

      static const int32_T iv2[2] = { 1, 24 };

      static const char_T msgID[24] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'e',
        'i', 'g', ':', 'N', 'o', 'C', 'o', 'n', 'v', 'e', 'r', 'g', 'e', 'n',
        'c', 'e' };

      static const char_T b_u[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

      static const char_T u[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

      emlrtStack st;
      const mxArray *b_y;
      const mxArray *c_y;
      const mxArray *m;
      const mxArray *y;
      st.prev = sp;
      st.tls = sp->tls;
      y = NULL;
      m = emlrtCreateCharArray(2, &b_iv[0]);
      emlrtInitCharArrayR2013a(sp, 7, m, &u[0]);
      emlrtAssign(&y, m);
      b_y = NULL;
      m = emlrtCreateCharArray(2, &b_iv1[0]);
      emlrtInitCharArrayR2013a(sp, 7, m, &b_u[0]);
      emlrtAssign(&b_y, m);
      c_y = NULL;
      m = emlrtCreateCharArray(2, &iv2[0]);
      emlrtInitCharArrayR2013a(sp, 24, m, &msgID[0]);
      emlrtAssign(&c_y, m);
      st.site = &flb_emlrtRSI;
      b_feval(&st, y, feval(&st, b_y, c_y, &emlrtMCI), &b_emlrtMCI);
    }

    void f_warning(const emlrtStack *sp)
    {
      static const int32_T b_iv[2] = { 1, 7 };

      static const int32_T b_iv1[2] = { 1, 7 };

      static const int32_T iv2[2] = { 1, 21 };

      static const char_T msgID[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's',
        'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a', 't', 'r', 'i', 'x' };

      static const char_T b_u[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

      static const char_T u[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

      emlrtStack st;
      const mxArray *b_y;
      const mxArray *c_y;
      const mxArray *m;
      const mxArray *y;
      st.prev = sp;
      st.tls = sp->tls;
      y = NULL;
      m = emlrtCreateCharArray(2, &b_iv[0]);
      emlrtInitCharArrayR2013a(sp, 7, m, &u[0]);
      emlrtAssign(&y, m);
      b_y = NULL;
      m = emlrtCreateCharArray(2, &b_iv1[0]);
      emlrtInitCharArrayR2013a(sp, 7, m, &b_u[0]);
      emlrtAssign(&b_y, m);
      c_y = NULL;
      m = emlrtCreateCharArray(2, &iv2[0]);
      emlrtInitCharArrayR2013a(sp, 21, m, &msgID[0]);
      emlrtAssign(&c_y, m);
      st.site = &flb_emlrtRSI;
      b_feval(&st, y, feval(&st, b_y, c_y, &emlrtMCI), &b_emlrtMCI);
    }

    void g_warning(const emlrtStack *sp)
    {
      static const int32_T b_iv[2] = { 1, 7 };

      static const int32_T b_iv1[2] = { 1, 7 };

      static const int32_T iv2[2] = { 1, 38 };

      static const int32_T iv3[2] = { 1, 12 };

      static const char_T msgID[38] = { 'f', 'u', 's', 'i', 'o', 'n', ':', 't',
        'r', 'a', 'c', 'k', 'e', 'r', 'J', 'P', 'D', 'A', ':', 'M', 'a', 'x',
        'N', 'u', 'm', 'T', 'r', 'a', 'c', 'k', 's', 'R', 'e', 'a', 'c', 'h',
        'e', 'd' };

      static const char_T varargin_1[12] = { 'M', 'a', 'x', 'N', 'u', 'm', 'T',
        'r', 'a', 'c', 'k', 's' };

      static const char_T b_u[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

      static const char_T u[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

      emlrtStack st;
      const mxArray *b_y;
      const mxArray *c_y;
      const mxArray *d_y;
      const mxArray *m;
      const mxArray *y;
      st.prev = sp;
      st.tls = sp->tls;
      y = NULL;
      m = emlrtCreateCharArray(2, &b_iv[0]);
      emlrtInitCharArrayR2013a(sp, 7, m, &u[0]);
      emlrtAssign(&y, m);
      b_y = NULL;
      m = emlrtCreateCharArray(2, &b_iv1[0]);
      emlrtInitCharArrayR2013a(sp, 7, m, &b_u[0]);
      emlrtAssign(&b_y, m);
      c_y = NULL;
      m = emlrtCreateCharArray(2, &iv2[0]);
      emlrtInitCharArrayR2013a(sp, 38, m, &msgID[0]);
      emlrtAssign(&c_y, m);
      d_y = NULL;
      m = emlrtCreateCharArray(2, &iv3[0]);
      emlrtInitCharArrayR2013a(sp, 12, m, &varargin_1[0]);
      emlrtAssign(&d_y, m);
      st.site = &flb_emlrtRSI;
      b_feval(&st, y, feval(&st, b_y, c_y, d_y, &emlrtMCI), &b_emlrtMCI);
    }

    void warning(const emlrtStack *sp)
    {
      static const int32_T b_iv[2] = { 1, 7 };

      static const int32_T b_iv1[2] = { 1, 7 };

      static const int32_T iv2[2] = { 1, 30 };

      static const char_T msgID[30] = { 'v', 'i', 's', 'i', 'o', 'n', ':', 'r',
        'a', 'n', 's', 'a', 'c', ':', 'm', 'a', 'x', 'T', 'r', 'i', 'a', 'l',
        's', 'R', 'e', 'a', 'c', 'h', 'e', 'd' };

      static const char_T b_u[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

      static const char_T u[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

      emlrtStack st;
      const mxArray *b_y;
      const mxArray *c_y;
      const mxArray *m;
      const mxArray *y;
      st.prev = sp;
      st.tls = sp->tls;
      y = NULL;
      m = emlrtCreateCharArray(2, &b_iv[0]);
      emlrtInitCharArrayR2013a(sp, 7, m, &u[0]);
      emlrtAssign(&y, m);
      b_y = NULL;
      m = emlrtCreateCharArray(2, &b_iv1[0]);
      emlrtInitCharArrayR2013a(sp, 7, m, &b_u[0]);
      emlrtAssign(&b_y, m);
      c_y = NULL;
      m = emlrtCreateCharArray(2, &iv2[0]);
      emlrtInitCharArrayR2013a(sp, 30, m, &msgID[0]);
      emlrtAssign(&c_y, m);
      st.site = &flb_emlrtRSI;
      b_feval(&st, y, feval(&st, b_y, c_y, &emlrtMCI), &b_emlrtMCI);
    }
  }
}

// End of code generation (warning.cpp)
