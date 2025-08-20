/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eml_setop.c
 *
 * Code generation for function 'eml_setop'
 *
 */

/* Include files */
#include "eml_setop.h"
#include "mexLidarTracker_emxutil.h"
#include "mexLidarTracker_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo mc_emlrtRTEI =
    {
        444,          /* lineNo */
        5,            /* colNo */
        "do_vectors", /* fName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/private/"
        "eml_setop.m" /* pName */
};

static emlrtRTEInfo nc_emlrtRTEI =
    {
        406,          /* lineNo */
        5,            /* colNo */
        "do_vectors", /* fName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/private/"
        "eml_setop.m" /* pName */
};

static emlrtRTEInfo oc_emlrtRTEI =
    {
        242,          /* lineNo */
        13,           /* colNo */
        "do_vectors", /* fName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/private/"
        "eml_setop.m" /* pName */
};

static emlrtRTEInfo pc_emlrtRTEI =
    {
        239,          /* lineNo */
        13,           /* colNo */
        "do_vectors", /* fName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/private/"
        "eml_setop.m" /* pName */
};

static emlrtRTEInfo gj_emlrtRTEI =
    {
        208,         /* lineNo */
        24,          /* colNo */
        "eml_setop", /* fName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/private/"
        "eml_setop.m" /* pName */
};

static emlrtRTEInfo hj_emlrtRTEI =
    {
        215,         /* lineNo */
        29,          /* colNo */
        "eml_setop", /* fName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/private/"
        "eml_setop.m" /* pName */
};

static emlrtRTEInfo ij_emlrtRTEI =
    {
        412,         /* lineNo */
        9,           /* colNo */
        "eml_setop", /* fName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/private/"
        "eml_setop.m" /* pName */
};

static emlrtRTEInfo jj_emlrtRTEI =
    {
        446,         /* lineNo */
        9,           /* colNo */
        "eml_setop", /* fName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/private/"
        "eml_setop.m" /* pName */
};

/* Function Definitions */
int32_T do_vectors(const emlrtStack *sp, const emxArray_uint32_T *a,
                   const uint32_T b[20], emxArray_uint32_T *c,
                   emxArray_int32_T *ia)
{
  int32_T b_ialast;
  int32_T iafirst;
  int32_T ialast;
  int32_T ib_size;
  int32_T iblast;
  int32_T na;
  int32_T nc;
  int32_T nia;
  int32_T *ia_data;
  const uint32_T *a_data;
  uint32_T *c_data;
  boolean_T exitg1;
  boolean_T y;
  a_data = a->data;
  na = a->size[1];
  iafirst = c->size[0] * c->size[1];
  c->size[0] = 1;
  c->size[1] = a->size[1];
  emxEnsureCapacity_uint32_T(sp, c, iafirst, &gj_emlrtRTEI);
  c_data = c->data;
  iafirst = ia->size[0];
  ia->size[0] = a->size[1];
  emxEnsureCapacity_int32_T(sp, ia, iafirst, &hj_emlrtRTEI);
  ia_data = ia->data;
  ib_size = 0;
  y = true;
  if ((a->size[1] != 0) && (a->size[1] != 1)) {
    nia = 0;
    exitg1 = false;
    while ((!exitg1) && (nia <= a->size[1] - 2)) {
      y = (a_data[nia] <= a_data[nia + 1]);
      if (!y) {
        exitg1 = true;
      } else {
        nia++;
      }
    }
  }
  if (!y) {
    emlrtErrorWithMessageIdR2018a(sp, &pc_emlrtRTEI,
                                  "Coder:toolbox:eml_setop_unsortedA",
                                  "Coder:toolbox:eml_setop_unsortedA", 0);
  }
  y = true;
  nia = 0;
  exitg1 = false;
  while ((!exitg1) && (nia < 19)) {
    y = (b[nia] <= b[nia + 1]);
    if (!y) {
      exitg1 = true;
    } else {
      nia++;
    }
  }
  if (!y) {
    emlrtErrorWithMessageIdR2018a(sp, &oc_emlrtRTEI,
                                  "Coder:toolbox:eml_setop_unsortedB",
                                  "Coder:toolbox:eml_setop_unsortedB", 0);
  }
  nc = 0;
  nia = 0;
  iafirst = 0;
  ialast = 0;
  iblast = 1;
  while ((ialast + 1 <= na) && (iblast <= 20)) {
    uint32_T ak;
    uint32_T bk;
    b_ialast = ialast + 1;
    ak = a_data[ialast];
    while ((b_ialast < a->size[1]) && (a_data[b_ialast] == ak)) {
      b_ialast++;
    }
    ialast = b_ialast - 1;
    bk = b[iblast - 1];
    while ((iblast < 20) && (b[iblast] == bk)) {
      iblast++;
    }
    if (ak == bk) {
      ialast = b_ialast;
      iafirst = b_ialast;
      iblast++;
    } else if (ak < bk) {
      nia = nc + 1;
      nc++;
      c_data[nia - 1] = ak;
      ia_data[nia - 1] = iafirst + 1;
      ialast = b_ialast;
      iafirst = b_ialast;
    } else {
      iblast++;
    }
  }
  while (ialast + 1 <= na) {
    b_ialast = ialast + 1;
    while ((b_ialast < a->size[1]) && (a_data[b_ialast] == a_data[ialast])) {
      b_ialast++;
    }
    nia = nc + 1;
    nc++;
    c_data[nia - 1] = a_data[ialast];
    ia_data[nia - 1] = iafirst + 1;
    ialast = b_ialast;
    iafirst = b_ialast;
  }
  if (a->size[1] > 0) {
    if (nia > a->size[1]) {
      emlrtErrorWithMessageIdR2018a(sp, &nc_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    if (nia < 1) {
      iafirst = 0;
    } else {
      iafirst = nia;
    }
    nia = ia->size[0];
    ia->size[0] = iafirst;
    emxEnsureCapacity_int32_T(sp, ia, nia, &ij_emlrtRTEI);
    if (nc > a->size[1]) {
      emlrtErrorWithMessageIdR2018a(sp, &mc_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    nia = c->size[0] * c->size[1];
    c->size[1] = iafirst;
    emxEnsureCapacity_uint32_T(sp, c, nia, &jj_emlrtRTEI);
  }
  return ib_size;
}

/* End of code generation (eml_setop.c) */
