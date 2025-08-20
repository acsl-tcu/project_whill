/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Resampling.c
 *
 * Code generation for function 'Resampling'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "Resampling.h"
#include "rand.h"
#include "Resampling_emxutil.h"
#include "Resampling_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 6,     /* lineNo */
  "Resampling",                        /* fcnName */
  "E:\\users\\yamaguchi\\test\\test\\Resampling.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 7,   /* lineNo */
  "Resampling",                        /* fcnName */
  "E:\\users\\yamaguchi\\test\\test\\Resampling.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 13,  /* lineNo */
  "Resampling",                        /* fcnName */
  "E:\\users\\yamaguchi\\test\\test\\Resampling.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 28,  /* lineNo */
  "reshapeSizeChecks",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\reshapeSizeChecks.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 108, /* lineNo */
  "computeDimsData",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\reshapeSizeChecks.m"/* pathName */
};

static emlrtRTEInfo b_emlrtRTEI = { 6, /* lineNo */
  9,                                   /* colNo */
  "Resampling",                        /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Resampling.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 7, /* lineNo */
  9,                                   /* colNo */
  "Resampling",                        /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Resampling.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 14,/* lineNo */
  9,                                   /* colNo */
  "Resampling",                        /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Resampling.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 15,/* lineNo */
  9,                                   /* colNo */
  "Resampling",                        /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Resampling.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 21,/* lineNo */
  27,                                  /* colNo */
  "Resampling",                        /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Resampling.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 22,/* lineNo */
  27,                                  /* colNo */
  "Resampling",                        /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Resampling.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 1, /* lineNo */
  23,                                  /* colNo */
  "Resampling",                        /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Resampling.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 17,/* lineNo */
  16,                                  /* colNo */
  "Resampling",                        /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Resampling.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  32,                                  /* colNo */
  "ppx",                               /* aName */
  "Resampling",                        /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Resampling.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  38,                                  /* colNo */
  "ppx",                               /* aName */
  "Resampling",                        /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Resampling.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  47,                                  /* colNo */
  "ppx",                               /* aName */
  "Resampling",                        /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Resampling.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  51,                                  /* colNo */
  "ppx",                               /* aName */
  "Resampling",                        /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Resampling.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  18,                                  /* colNo */
  "px",                                /* aName */
  "Resampling",                        /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Resampling.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  22,                                  /* colNo */
  "px",                                /* aName */
  "Resampling",                        /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Resampling.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  21,                                  /* lineNo */
  13,                                  /* colNo */
  "Resampling",                        /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Resampling.m"/* pName */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  32,                                  /* colNo */
  "v",                                 /* aName */
  "Resampling",                        /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Resampling.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  36,                                  /* colNo */
  "v",                                 /* aName */
  "Resampling",                        /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Resampling.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  43,                                  /* colNo */
  "v",                                 /* aName */
  "Resampling",                        /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Resampling.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  47,                                  /* colNo */
  "v",                                 /* aName */
  "Resampling",                        /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Resampling.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  18,                                  /* colNo */
  "pv",                                /* aName */
  "Resampling",                        /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Resampling.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  22,                                  /* colNo */
  "pv",                                /* aName */
  "Resampling",                        /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Resampling.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo b_emlrtECI = { -1,  /* nDims */
  22,                                  /* lineNo */
  13,                                  /* colNo */
  "Resampling",                        /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Resampling.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 58,/* lineNo */
  23,                                  /* colNo */
  "reshapeSizeChecks",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\reshapeSizeChecks.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 56,/* lineNo */
  23,                                  /* colNo */
  "reshapeSizeChecks",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\reshapeSizeChecks.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 51,/* lineNo */
  13,                                  /* colNo */
  "reshapeSizeChecks",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\reshapeSizeChecks.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 55,/* lineNo */
  23,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 61,/* lineNo */
  15,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"/* pName */
};

static emlrtBCInfo m_emlrtBCI = { 1,   /* iFirst */
  1000,                                /* iLast */
  18,                                  /* lineNo */
  19,                                  /* colNo */
  "resampleID",                        /* aName */
  "Resampling",                        /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Resampling.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { 1,   /* iFirst */
  1000,                                /* iLast */
  18,                                  /* lineNo */
  34,                                  /* colNo */
  "wcum",                              /* aName */
  "Resampling",                        /* fName */
  "E:\\users\\yamaguchi\\test\\test\\Resampling.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void Resampling(const emlrtStack *sp, const struct0_T *obj, const real_T ppu
                [42000], real_T pw[1000], emxArray_real_T *px, emxArray_real_T
                *pv)
{
  real_T d0;
  real_T b_obj;
  int32_T i0;
  int32_T sz_idx_0;
  int32_T loop_ub;
  int32_T i1;
  int32_T i2;
  real_T b_ppu[21000];
  real_T varargin_2;
  real_T c_obj;
  int32_T b_sz_idx_0;
  int32_T ind;
  emxArray_real_T *v;
  real_T wcum[1000];
  int32_T k;
  real_T resampleID[1000];
  real_T d1;
  emxArray_real_T *ppx;
  emxArray_real_T *r5;
  int32_T ip;
  int32_T exitg1;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T i6;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /* RESAMPLING この関数の概要をここに記述 */
  /*    詳細説明をここに記述 */
  /*      if obj.Resamplingmode == "LVS" */
  st.site = &emlrtRSI;
  b_st.site = &d_emlrtRSI;
  c_st.site = &e_emlrtRSI;
  d0 = muDoubleScalarFloor(obj->NP);
  if ((obj->NP != d0) || muDoubleScalarIsInf(obj->NP) || (obj->NP <
       -2.147483648E+9) || (obj->NP > 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &m_emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", "Coder:MATLAB:NonIntegerInput", 4, 12,
      MIN_int32_T, 12, MAX_int32_T);
  }

  if (obj->NP <= 0.0) {
    b_obj = 0.0;
  } else {
    b_obj = obj->NP;
  }

  if (!(b_obj <= 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &n_emlrtRTEI, "Coder:MATLAB:pmaxsize",
      "Coder:MATLAB:pmaxsize", 0);
  }

  i0 = (int32_T)obj->NP;
  if (i0 > 0) {
    if (i0 == 0) {
      sz_idx_0 = MAX_int32_T;
    } else {
      sz_idx_0 = 21000 / i0;
    }
  } else {
    sz_idx_0 = 0;
  }

  if (i0 > 21000) {
    emlrtErrorWithMessageIdR2018a(&st, &l_emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (i0 < 0) {
    emlrtErrorWithMessageIdR2018a(&st, &k_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  loop_ub = sz_idx_0 * i0;
  if (loop_ub != 21000) {
    emlrtErrorWithMessageIdR2018a(&st, &j_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  for (i1 = 0; i1 < 1000; i1++) {
    for (i2 = 0; i2 < 21; i2++) {
      b_ppu[i2 + 21 * i1] = ppu[1 + ((i2 << 1) + 42 * i1)];
    }
  }

  i1 = px->size[0] * px->size[1];
  px->size[0] = sz_idx_0;
  px->size[1] = i0;
  emxEnsureCapacity_real_T(sp, px, i1, &b_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub; i1++) {
    px->data[i1] = b_ppu[i1];
  }

  st.site = &b_emlrtRSI;
  varargin_2 = obj->NP;
  b_st.site = &d_emlrtRSI;
  c_st.site = &e_emlrtRSI;
  if ((obj->NP != d0) || muDoubleScalarIsInf(obj->NP) || (obj->NP <
       -2.147483648E+9) || (obj->NP > 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &m_emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", "Coder:MATLAB:NonIntegerInput", 4, 12,
      MIN_int32_T, 12, MAX_int32_T);
  }

  if (obj->NP <= 0.0) {
    c_obj = 0.0;
  } else {
    c_obj = obj->NP;
  }

  if (!(c_obj <= 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &n_emlrtRTEI, "Coder:MATLAB:pmaxsize",
      "Coder:MATLAB:pmaxsize", 0);
  }

  if (i0 > 0) {
    if (i0 == 0) {
      b_sz_idx_0 = MAX_int32_T;
    } else {
      b_sz_idx_0 = 21000 / i0;
    }
  } else {
    b_sz_idx_0 = 0;
  }

  if (i0 > 21000) {
    emlrtErrorWithMessageIdR2018a(&st, &l_emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (i0 < 0) {
    emlrtErrorWithMessageIdR2018a(&st, &k_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  ind = b_sz_idx_0 * i0;
  if (ind != 21000) {
    emlrtErrorWithMessageIdR2018a(&st, &j_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  for (i1 = 0; i1 < 1000; i1++) {
    for (i2 = 0; i2 < 21; i2++) {
      b_ppu[i2 + 21 * i1] = ppu[(i2 << 1) + 42 * i1];
    }
  }

  emxInit_real_T(sp, &v, 2, &c_emlrtRTEI, true);
  i1 = v->size[0] * v->size[1];
  v->size[0] = b_sz_idx_0;
  v->size[1] = i0;
  emxEnsureCapacity_real_T(sp, v, i1, &c_emlrtRTEI);
  for (i1 = 0; i1 < ind; i1++) {
    v->data[i1] = b_ppu[i1];
  }

  /* px:パーティクル，pw:重み */
  /* リサンプリングを実施する関数 */
  /* アルゴリズムはLow Variance Sampling */
  memcpy(&wcum[0], &pw[0], 1000U * sizeof(real_T));
  for (k = 0; k < 999; k++) {
    wcum[k + 1] += wcum[k];
  }

  d0 = 1.0 / obj->NP;
  for (i1 = 0; i1 < 1000; i1++) {
    resampleID[i1] = pw[i1] * 0.0 + d0;
  }

  for (k = 0; k < 999; k++) {
    resampleID[k + 1] += resampleID[k];
  }

  /* 乱数を加える前のbase */
  st.site = &c_emlrtRSI;
  d1 = b_rand() / obj->NP;

  /* ルーレットを乱数分増やす */
  for (i1 = 0; i1 < 1000; i1++) {
    resampleID[i1] = (resampleID[i1] - d0) + d1;
    for (i2 = 0; i2 < 21; i2++) {
      b_ppu[i2 + 21 * i1] = ppu[1 + ((i2 << 1) + 42 * i1)];
    }
  }

  emxInit_real_T(sp, &ppx, 2, &d_emlrtRTEI, true);
  i1 = ppx->size[0] * ppx->size[1];
  ppx->size[0] = sz_idx_0;
  ppx->size[1] = i0;
  emxEnsureCapacity_real_T(sp, ppx, i1, &d_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub; i1++) {
    ppx->data[i1] = b_ppu[i1];
  }

  /* データ格納用 */
  for (i1 = 0; i1 < 1000; i1++) {
    for (i2 = 0; i2 < 21; i2++) {
      b_ppu[i2 + 21 * i1] = ppu[(i2 << 1) + 42 * i1];
    }
  }

  i1 = pv->size[0] * pv->size[1];
  pv->size[0] = b_sz_idx_0;
  pv->size[1] = i0;
  emxEnsureCapacity_real_T(sp, pv, i1, &e_emlrtRTEI);
  for (i1 = 0; i1 < ind; i1++) {
    pv->data[i1] = b_ppu[i1];
  }

  ind = 1;

  /* 新しいID */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, obj->NP, mxDOUBLE_CLASS, (int32_T)
    obj->NP, &i_emlrtRTEI, sp);
  emxInit_real_T(sp, &r5, 1, &h_emlrtRTEI, true);
  for (ip = 0; ip < i0; ip++) {
    do {
      exitg1 = 0;
      i1 = (int32_T)(1U + ip);
      if ((i1 < 1) || (i1 > 1000)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, 1000, &m_emlrtBCI, sp);
      }

      if (ind > 1000) {
        emlrtDynamicBoundsCheckR2012b(1001, 1, 1000, &n_emlrtBCI, sp);
      }

      if (resampleID[i1 - 1] > wcum[ind - 1]) {
        ind++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    if (2 > ppx->size[0]) {
      i1 = 0;
      i2 = 0;
    } else {
      if (2 > sz_idx_0) {
        emlrtDynamicBoundsCheckR2012b(2, 1, sz_idx_0, &emlrtBCI, sp);
      }

      i1 = 1;
      i2 = sz_idx_0;
    }

    if (1 > px->size[0]) {
      i4 = 0;
    } else {
      i3 = px->size[0];
      i4 = px->size[0];
      if ((i4 < 1) || (i4 > i3)) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &e_emlrtBCI, sp);
      }
    }

    i3 = px->size[1];
    i5 = 1 + ip;
    if ((i5 < 1) || (i5 > i3)) {
      emlrtDynamicBoundsCheckR2012b(i5, 1, i3, &f_emlrtBCI, sp);
    }

    if (sz_idx_0 < 1) {
      emlrtDynamicBoundsCheckR2012b(sz_idx_0, 1, sz_idx_0, &c_emlrtBCI, sp);
    }

    if (ind > i0) {
      emlrtDynamicBoundsCheckR2012b(ind, 1, i0, &d_emlrtBCI, sp);
    }

    i3 = (ind - 1) * sz_idx_0;
    i5 = (sz_idx_0 + i3) - 1;
    for (i6 = 0; i6 < 1000; i6++) {
      for (k = 0; k < 21; k++) {
        b_ppu[k + 21 * i6] = ppu[1 + ((k << 1) + 42 * i6)];
      }
    }

    if (ind > i0) {
      emlrtDynamicBoundsCheckR2012b(ind, 1, i0, &b_emlrtBCI, sp);
    }

    i6 = r5->size[0];
    loop_ub = i2 - i1;
    r5->size[0] = loop_ub + 1;
    emxEnsureCapacity_real_T(sp, r5, i6, &f_emlrtRTEI);
    for (i2 = 0; i2 < loop_ub; i2++) {
      r5->data[i2] = b_ppu[(i1 + i2) + i3];
    }

    r5->data[loop_ub] = ppu[1 + (((i5 % 21) << 1) + 42 * (i5 / 21))];
    emlrtSubAssignSizeCheckR2012b(&i4, 1, &(*(int32_T (*)[1])r5->size)[0], 1,
      &emlrtECI, sp);
    loop_ub = r5->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      px->data[i1 + px->size[0] * ip] = r5->data[i1];
    }

    /* LVSで選ばれたパーティクルに置き換え */
    if (2 > b_sz_idx_0) {
      i1 = 0;
      i2 = 0;
    } else {
      i1 = 1;
      i2 = v->size[0];
      if ((i2 < 1) || (i2 > b_sz_idx_0)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, b_sz_idx_0, &g_emlrtBCI, sp);
      }
    }

    if (1 > pv->size[0]) {
      i4 = 0;
    } else {
      i3 = pv->size[0];
      i4 = pv->size[0];
      if ((i4 < 1) || (i4 > i3)) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &k_emlrtBCI, sp);
      }
    }

    i3 = pv->size[1];
    i5 = 1 + ip;
    if ((i5 < 1) || (i5 > i3)) {
      emlrtDynamicBoundsCheckR2012b(i5, 1, i3, &l_emlrtBCI, sp);
    }

    if (b_sz_idx_0 < 1) {
      emlrtDynamicBoundsCheckR2012b(b_sz_idx_0, 1, b_sz_idx_0, &i_emlrtBCI, sp);
    }

    i3 = (int32_T)varargin_2;
    if (ind > i3) {
      emlrtDynamicBoundsCheckR2012b(ind, 1, i3, &j_emlrtBCI, sp);
    }

    i3 = (ind - 1) * b_sz_idx_0;
    i5 = (b_sz_idx_0 + i3) - 1;
    for (i6 = 0; i6 < 1000; i6++) {
      for (k = 0; k < 21; k++) {
        b_ppu[k + 21 * i6] = ppu[(k << 1) + 42 * i6];
      }
    }

    i6 = (int32_T)varargin_2;
    if (ind > i6) {
      emlrtDynamicBoundsCheckR2012b(ind, 1, i6, &h_emlrtBCI, sp);
    }

    i6 = r5->size[0];
    loop_ub = i2 - i1;
    r5->size[0] = loop_ub + 1;
    emxEnsureCapacity_real_T(sp, r5, i6, &g_emlrtRTEI);
    for (i2 = 0; i2 < loop_ub; i2++) {
      r5->data[i2] = b_ppu[(i1 + i2) + i3];
    }

    r5->data[loop_ub] = ppu[((i5 % 21) << 1) + 42 * (i5 / 21)];
    emlrtSubAssignSizeCheckR2012b(&i4, 1, &(*(int32_T (*)[1])r5->size)[0], 1,
      &b_emlrtECI, sp);
    loop_ub = r5->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      pv->data[i1 + pv->size[0] * ip] = r5->data[i1];
    }

    pw[ip] = d0;

    /* 尤度は初期化 */
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&r5);
  emxFree_real_T(&ppx);
  emxFree_real_T(&v);

  /*      elseif obj.Resamplingmode == "Date" */
  /*      end */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Resampling.c) */
