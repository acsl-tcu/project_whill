/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * repmat.c
 *
 * Code generation for function 'repmat'
 *
 */

/* Include files */
#include "repmat.h"
#include "calc_observation_emxutil.h"
#include "calc_observation_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo l_emlrtRSI = {
    34,       /* lineNo */
    "repmat", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elmat/repmat.m" /* pathName
                                                                      */
};

static emlrtDCInfo c_emlrtDCI = {
    37,       /* lineNo */
    14,       /* colNo */
    "repmat", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elmat/repmat.m", /* pName
                                                                       */
    4 /* checkKind */
};

static emlrtRTEInfo d_emlrtRTEI = {
    64,                   /* lineNo */
    15,                   /* colNo */
    "assertValidSizeArg", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "assertValidSizeArg.m" /* pName */
};

static emlrtRTEInfo e_emlrtRTEI = {
    58,                   /* lineNo */
    23,                   /* colNo */
    "assertValidSizeArg", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "assertValidSizeArg.m" /* pName */
};

static emlrtRTEInfo xb_emlrtRTEI = {
    59,       /* lineNo */
    9,        /* colNo */
    "repmat", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elmat/repmat.m" /* pName */
};

/* Function Definitions */
void repmat(const emlrtStack *sp, real_T varargin_1, emxArray_struct2_T *b)
{
  emlrtStack st;
  struct2_T s;
  struct2_T *b_data;
  real_T d;
  int32_T b_i;
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &l_emlrtRSI;
  if ((varargin_1 != muDoubleScalarFloor(varargin_1)) ||
      muDoubleScalarIsInf(varargin_1) || (varargin_1 < -2.147483648E+9) ||
      (varargin_1 > 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &e_emlrtRTEI, "Coder:MATLAB:NonIntegerInput",
        "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }
  if (varargin_1 <= 0.0) {
    d = 0.0;
  } else {
    d = varargin_1;
  }
  if (!(d <= 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&st, &d_emlrtRTEI, "Coder:MATLAB:pmaxsize",
                                  "Coder:MATLAB:pmaxsize", 0);
  }
  if (!(varargin_1 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(varargin_1, &c_emlrtDCI, (emlrtConstCTX)sp);
  }
  for (i = 0; i < 5; i++) {
    s.model[i] = 0.0;
  }
  memset(&s.inlierpoints[0], 0, 4000U * sizeof(real_T));
  s.ModelType = 0.0;
  i = (int32_T)varargin_1;
  b_i = b->size[0];
  b->size[0] = (int32_T)varargin_1;
  emxEnsureCapacity_struct2_T(sp, b, b_i, &xb_emlrtRTEI);
  b_data = b->data;
  for (b_i = 0; b_i < i; b_i++) {
    b_data[b_i] = s;
  }
}

/* End of code generation (repmat.c) */
