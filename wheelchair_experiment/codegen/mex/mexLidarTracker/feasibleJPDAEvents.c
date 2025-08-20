/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * feasibleJPDAEvents.c
 *
 * Code generation for function 'feasibleJPDAEvents'
 *
 */

/* Include files */
#include "feasibleJPDAEvents.h"
#include "eml_int_forloop_overflow_check.h"
#include "find.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_emxutil.h"
#include "mexLidarTracker_types.h"
#include "numPotentialFeasibleEvents.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ax_emlrtRSI = {
    48,                   /* lineNo */
    "feasibleJPDAEvents", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleJPDAEvents.m" /* pathName */
};

static emlrtRSInfo bx_emlrtRSI = {
    50,                   /* lineNo */
    "feasibleJPDAEvents", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleJPDAEvents.m" /* pathName */
};

static emlrtRSInfo cx_emlrtRSI = {
    51,                   /* lineNo */
    "feasibleJPDAEvents", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleJPDAEvents.m" /* pathName */
};

static emlrtRSInfo dx_emlrtRSI = {
    60,                   /* lineNo */
    "feasibleJPDAEvents", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleJPDAEvents.m" /* pathName */
};

static emlrtRSInfo ex_emlrtRSI = {
    61,                   /* lineNo */
    "feasibleJPDAEvents", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleJPDAEvents.m" /* pathName */
};

static emlrtRSInfo fx_emlrtRSI = {
    63,                   /* lineNo */
    "feasibleJPDAEvents", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleJPDAEvents.m" /* pathName */
};

static emlrtRSInfo gx_emlrtRSI = {
    86,                   /* lineNo */
    "feasibleJPDAEvents", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleJPDAEvents.m" /* pathName */
};

static emlrtRSInfo jx_emlrtRSI = {
    64,       /* lineNo */
    "repmat", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/elmat/repmat.m" /* pathName
                                                                      */
};

static emlrtBCInfo xb_emlrtBCI = {
    -1,                   /* iFirst */
    -1,                   /* iLast */
    61,                   /* lineNo */
    100,                  /* colNo */
    "",                   /* aName */
    "feasibleJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleJPDAEvents.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = {
    -1,                   /* iFirst */
    -1,                   /* iLast */
    97,                   /* lineNo */
    32,                   /* colNo */
    "",                   /* aName */
    "feasibleJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleJPDAEvents.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo ac_emlrtBCI = {
    -1,                   /* iFirst */
    -1,                   /* iLast */
    115,                  /* lineNo */
    18,                   /* colNo */
    "",                   /* aName */
    "feasibleJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleJPDAEvents.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = {
    -1,                   /* iFirst */
    -1,                   /* iLast */
    115,                  /* lineNo */
    20,                   /* colNo */
    "",                   /* aName */
    "feasibleJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleJPDAEvents.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = {
    -1,                   /* iFirst */
    -1,                   /* iLast */
    80,                   /* lineNo */
    18,                   /* colNo */
    "",                   /* aName */
    "feasibleJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleJPDAEvents.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI = {
    -1,                   /* iFirst */
    -1,                   /* iLast */
    80,                   /* lineNo */
    20,                   /* colNo */
    "",                   /* aName */
    "feasibleJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleJPDAEvents.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = {
    -1,                   /* iFirst */
    -1,                   /* iLast */
    108,                  /* lineNo */
    15,                   /* colNo */
    "",                   /* aName */
    "feasibleJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleJPDAEvents.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = {
    -1,                   /* iFirst */
    -1,                   /* iLast */
    111,                  /* lineNo */
    11,                   /* colNo */
    "",                   /* aName */
    "feasibleJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleJPDAEvents.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = {
    -1,                   /* iFirst */
    -1,                   /* iLast */
    89,                   /* lineNo */
    19,                   /* colNo */
    "",                   /* aName */
    "feasibleJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleJPDAEvents.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = {
    -1,                   /* iFirst */
    -1,                   /* iLast */
    90,                   /* lineNo */
    19,                   /* colNo */
    "",                   /* aName */
    "feasibleJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleJPDAEvents.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = {
    -1,                   /* iFirst */
    -1,                   /* iLast */
    65,                   /* lineNo */
    17,                   /* colNo */
    "",                   /* aName */
    "feasibleJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleJPDAEvents.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = {
    -1,                   /* iFirst */
    -1,                   /* iLast */
    65,                   /* lineNo */
    19,                   /* colNo */
    "",                   /* aName */
    "feasibleJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleJPDAEvents.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo kc_emlrtBCI = {
    -1,                   /* iFirst */
    -1,                   /* iLast */
    67,                   /* lineNo */
    31,                   /* colNo */
    "",                   /* aName */
    "feasibleJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleJPDAEvents.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo lc_emlrtBCI = {
    -1,                   /* iFirst */
    -1,                   /* iLast */
    67,                   /* lineNo */
    17,                   /* colNo */
    "",                   /* aName */
    "feasibleJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleJPDAEvents.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo mc_emlrtBCI = {
    -1,                   /* iFirst */
    -1,                   /* iLast */
    67,                   /* lineNo */
    19,                   /* colNo */
    "",                   /* aName */
    "feasibleJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleJPDAEvents.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo nc_emlrtBCI = {
    -1,                   /* iFirst */
    -1,                   /* iLast */
    97,                   /* lineNo */
    25,                   /* colNo */
    "",                   /* aName */
    "feasibleJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleJPDAEvents.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo oc_emlrtBCI = {
    -1,                   /* iFirst */
    -1,                   /* iLast */
    97,                   /* lineNo */
    27,                   /* colNo */
    "",                   /* aName */
    "feasibleJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleJPDAEvents.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo pc_emlrtBCI = {
    -1,                   /* iFirst */
    -1,                   /* iLast */
    97,                   /* lineNo */
    34,                   /* colNo */
    "",                   /* aName */
    "feasibleJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleJPDAEvents.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo qc_emlrtBCI = {
    -1,                   /* iFirst */
    -1,                   /* iLast */
    98,                   /* lineNo */
    25,                   /* colNo */
    "",                   /* aName */
    "feasibleJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleJPDAEvents.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo rc_emlrtBCI = {
    -1,                   /* iFirst */
    -1,                   /* iLast */
    98,                   /* lineNo */
    32,                   /* colNo */
    "",                   /* aName */
    "feasibleJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleJPDAEvents.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = {
    -1,                   /* iFirst */
    -1,                   /* iLast */
    98,                   /* lineNo */
    41,                   /* colNo */
    "",                   /* aName */
    "feasibleJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleJPDAEvents.m", /* pName */
    0                                   /* checkKind */
};

static emlrtRTEInfo hi_emlrtRTEI = {
    1,                    /* lineNo */
    19,                   /* colNo */
    "feasibleJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleJPDAEvents.m" /* pName */
};

static emlrtRTEInfo ii_emlrtRTEI = {
    58,                   /* lineNo */
    1,                    /* colNo */
    "feasibleJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleJPDAEvents.m" /* pName */
};

static emlrtRTEInfo ji_emlrtRTEI = {
    115,                  /* lineNo */
    1,                    /* colNo */
    "feasibleJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleJPDAEvents.m" /* pName */
};

static emlrtRTEInfo ki_emlrtRTEI = {
    51,                   /* lineNo */
    1,                    /* colNo */
    "feasibleJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/feasibleJPDAEvents.m" /* pName */
};

/* Function Definitions */
void feasibleJPDAEvents(const emlrtStack *sp,
                        const emxArray_boolean_T *validationMatrix,
                        emxArray_boolean_T *outFJE)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_boolean_T c_validationMatrix_data;
  emxArray_boolean_T d_validationMatrix_data;
  emxArray_boolean_T *FJE;
  emxArray_boolean_T *a;
  emxArray_int32_T *ii;
  emxArray_uint32_T *Xjs;
  int32_T validationMatrix_size[2];
  int32_T iacol_tmp;
  int32_T ibmat;
  int32_T ibtile;
  int32_T in_size_idx_0;
  int32_T jcol;
  int32_T k;
  int32_T loop_ub;
  int32_T nPotentials;
  int32_T nrows;
  int32_T numMeas;
  int32_T numTrks_tmp;
  int32_T sizes_idx_1;
  int32_T *ii_data;
  uint32_T X_data[64];
  uint32_T L;
  uint32_T Xj;
  uint32_T j;
  uint32_T *Xjs_data;
  int8_T input_sizes_idx_1;
  boolean_T b_validationMatrix_data[32];
  const boolean_T *validationMatrix_data;
  boolean_T empty_non_axis_sizes;
  boolean_T *FJE_data;
  boolean_T *outFJE_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  validationMatrix_data = validationMatrix->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  in_size_idx_0 = validationMatrix->size[0];
  numMeas = validationMatrix->size[0];
  numTrks_tmp = validationMatrix->size[1] - 1;
  st.site = &ax_emlrtRSI;
  nPotentials = numPotentialFeasibleEvents(&st, validationMatrix,
                                           validationMatrix->size[0],
                                           validationMatrix->size[1] - 1);
  st.site = &bx_emlrtRSI;
  b_st.site = &hx_emlrtRSI;
  if (validationMatrix->size[0] != 0) {
    nrows = validationMatrix->size[0];
  } else {
    nrows = 0;
  }
  c_st.site = &ix_emlrtRSI;
  if ((validationMatrix->size[0] != nrows) &&
      (validationMatrix->size[0] != 0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  if ((validationMatrix->size[0] != nrows) &&
      ((validationMatrix->size[0] != 0) &&
       (validationMatrix->size[1] - 1 != 0))) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  empty_non_axis_sizes = (nrows == 0);
  if (empty_non_axis_sizes || (validationMatrix->size[0] != 0)) {
    input_sizes_idx_1 = 1;
  } else {
    input_sizes_idx_1 = 0;
  }
  if (empty_non_axis_sizes || ((validationMatrix->size[0] != 0) &&
                               (validationMatrix->size[1] - 1 != 0))) {
    sizes_idx_1 = validationMatrix->size[1] - 1;
  } else {
    sizes_idx_1 = 0;
  }
  st.site = &cx_emlrtRSI;
  emxInit_boolean_T(&st, &a, 2, &hi_emlrtRTEI, true);
  jcol = a->size[0] * a->size[1];
  a->size[0] = nrows;
  a->size[1] = input_sizes_idx_1 + sizes_idx_1;
  emxEnsureCapacity_boolean_T(&st, a, jcol, &hi_emlrtRTEI);
  outFJE_data = a->data;
  loop_ub = input_sizes_idx_1;
  for (jcol = 0; jcol < loop_ub; jcol++) {
    for (ibtile = 0; ibtile < nrows; ibtile++) {
      outFJE_data[ibtile] = true;
    }
  }
  for (jcol = 0; jcol < sizes_idx_1; jcol++) {
    for (ibtile = 0; ibtile < nrows; ibtile++) {
      outFJE_data[ibtile + a->size[0] * (jcol + input_sizes_idx_1)] = false;
    }
  }
  b_st.site = &ib_emlrtRSI;
  if (nPotentials < 0) {
    emlrtNonNegativeCheckR2012b(nPotentials, &g_emlrtDCI, &st);
  }
  emxInit_boolean_T(&st, &FJE, 3, &ki_emlrtRTEI, true);
  jcol = FJE->size[0] * FJE->size[1] * FJE->size[2];
  FJE->size[0] = a->size[0];
  FJE->size[1] = a->size[1];
  FJE->size[2] = nPotentials;
  emxEnsureCapacity_boolean_T(&st, FJE, jcol, &ud_emlrtRTEI);
  FJE_data = FJE->data;
  nrows = a->size[0];
  sizes_idx_1 = a->size[1];
  b_st.site = &jx_emlrtRSI;
  if (nPotentials > 2147483646) {
    c_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (loop_ub = 0; loop_ub < nPotentials; loop_ub++) {
    ibtile = loop_ub * (nrows * sizes_idx_1) - 1;
    b_st.site = &jb_emlrtRSI;
    for (jcol = 0; jcol < sizes_idx_1; jcol++) {
      iacol_tmp = jcol * nrows;
      ibmat = ibtile + iacol_tmp;
      b_st.site = &lb_emlrtRSI;
      if (nrows > 2147483646) {
        c_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (k = 0; k < nrows; k++) {
        FJE_data[(ibmat + k) + 1] = outFJE_data[iacol_tmp + k];
      }
    }
  }
  emxFree_boolean_T(&st, &a);
  Xj = 0U;
  ibmat = muIntScalarMin_sint32(numTrks_tmp, in_size_idx_0);
  in_size_idx_0 = ibmat + 1;
  loop_ub = (ibmat + 1) << 1;
  if (loop_ub - 1 >= 0) {
    memset(&X_data[0], 0, (uint32_T)loop_ub * sizeof(uint32_T));
  }
  emxInit_uint32_T(sp, &Xjs, 2, &ii_emlrtRTEI, true);
  jcol = Xjs->size[0] * Xjs->size[1];
  Xjs->size[0] = validationMatrix->size[0];
  Xjs->size[1] = validationMatrix->size[1];
  emxEnsureCapacity_uint32_T(sp, Xjs, jcol, &ii_emlrtRTEI);
  Xjs_data = Xjs->data;
  loop_ub = validationMatrix->size[0] * validationMatrix->size[1];
  for (jcol = 0; jcol < loop_ub; jcol++) {
    Xjs_data[jcol] = 0U;
  }
  st.site = &dx_emlrtRSI;
  if (validationMatrix->size[0] > 2147483646) {
    b_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  loop_ub = validationMatrix->size[1];
  emxInit_int32_T(sp, &ii, 2, &qe_emlrtRTEI);
  for (nPotentials = 0; nPotentials < numMeas; nPotentials++) {
    int32_T z_data[32];
    st.site = &ex_emlrtRSI;
    if (nPotentials + 1 > validationMatrix->size[0]) {
      emlrtDynamicBoundsCheckR2012b(
          nPotentials + 1, 1, validationMatrix->size[0], &xb_emlrtBCI, &st);
    }
    b_st.site = &kx_emlrtRSI;
    validationMatrix_size[0] = 1;
    validationMatrix_size[1] = validationMatrix->size[1];
    for (jcol = 0; jcol < loop_ub; jcol++) {
      b_validationMatrix_data[jcol] =
          validationMatrix_data[nPotentials + validationMatrix->size[0] * jcol];
    }
    c_validationMatrix_data.data = &b_validationMatrix_data[0];
    c_validationMatrix_data.size = &validationMatrix_size[0];
    c_validationMatrix_data.allocatedSize = 32;
    c_validationMatrix_data.numDimensions = 2;
    c_validationMatrix_data.canFreeData = false;
    c_st.site = &cg_emlrtRSI;
    b_eml_find(&c_st, &c_validationMatrix_data, ii);
    ii_data = ii->data;
    ibtile = ii->size[1];
    iacol_tmp = ii->size[1];
    nrows = (ii->size[1] / 4) << 2;
    sizes_idx_1 = nrows - 4;
    for (jcol = 0; jcol <= sizes_idx_1; jcol += 4) {
      __m128i r;
      r = _mm_loadu_si128((const __m128i *)&ii_data[jcol]);
      _mm_storeu_si128((__m128i *)&z_data[jcol],
                       _mm_sub_epi32(r, _mm_set1_epi32(1)));
    }
    for (jcol = nrows; jcol < iacol_tmp; jcol++) {
      z_data[jcol] = ii_data[jcol] - 1;
    }
    for (k = 0; k <= numTrks_tmp; k++) {
      st.site = &fx_emlrtRSI;
      validationMatrix_size[0] = 1;
      validationMatrix_size[1] = ibtile;
      for (jcol = 0; jcol < ibtile; jcol++) {
        b_validationMatrix_data[jcol] = (z_data[jcol] > k);
      }
      d_validationMatrix_data.data = &b_validationMatrix_data[0];
      d_validationMatrix_data.size = &validationMatrix_size[0];
      d_validationMatrix_data.allocatedSize = 32;
      d_validationMatrix_data.numDimensions = 2;
      d_validationMatrix_data.canFreeData = false;
      b_st.site = &cg_emlrtRSI;
      b_eml_find(&b_st, &d_validationMatrix_data, ii);
      ii_data = ii->data;
      if (ii->size[1] == 0) {
        if (nPotentials + 1 > Xjs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(nPotentials + 1, 1, Xjs->size[0],
                                        &ic_emlrtBCI, (emlrtConstCTX)sp);
        }
        if (k + 1 > Xjs->size[1]) {
          emlrtDynamicBoundsCheckR2012b(k + 1, 1, Xjs->size[1], &jc_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        Xjs_data[nPotentials + Xjs->size[0] * k] = 0U;
      } else {
        if ((ii_data[0] < 1) || (ii_data[0] > ibtile)) {
          emlrtDynamicBoundsCheckR2012b(ii_data[0], 1, ibtile, &kc_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (nPotentials + 1 > Xjs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(nPotentials + 1, 1, Xjs->size[0],
                                        &lc_emlrtBCI, (emlrtConstCTX)sp);
        }
        if (k + 1 > Xjs->size[1]) {
          emlrtDynamicBoundsCheckR2012b(k + 1, 1, Xjs->size[1], &mc_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        jcol = z_data[ii_data[0] - 1];
        if (jcol < 0) {
          jcol = 0;
        }
        Xjs_data[nPotentials + Xjs->size[0] * k] = (uint32_T)jcol;
      }
    }
  }
  emxFree_int32_T(sp, &ii);
  L = 0U;
  j = 1U;
  sizes_idx_1 = 1;
  while (j <= (uint32_T)numMeas) {
    while ((L < (uint32_T)ibmat) && (j <= (uint32_T)numMeas)) {
      uint32_T qY;
      if (((int32_T)j < 1) || ((int32_T)j > Xjs->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)j, 1, Xjs->size[0], &cc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      qY = Xj + 1U;
      if (Xj + 1U < Xj) {
        qY = MAX_uint32_T;
      }
      if (((int32_T)qY < 1) || ((int32_T)qY > Xjs->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)qY, 1, Xjs->size[1],
                                      &dc_emlrtBCI, (emlrtConstCTX)sp);
      }
      Xj = Xjs_data[((int32_T)j + Xjs->size[0] * ((int32_T)qY - 1)) - 1];
      if (Xj == 0U) {
        Xj = 0U;
        j++;
      } else {
        boolean_T x_data[32];
        boolean_T exitg1;
        st.site = &gx_emlrtRSI;
        for (jcol = 0; jcol < in_size_idx_0; jcol++) {
          x_data[jcol] = (X_data[(jcol + ibmat) + 1] == Xj);
        }
        b_st.site = &lx_emlrtRSI;
        empty_non_axis_sizes = false;
        nrows = 1;
        exitg1 = false;
        while ((!exitg1) && (nrows <= ibmat + 1)) {
          if (x_data[nrows - 1]) {
            empty_non_axis_sizes = true;
            exitg1 = true;
          } else {
            nrows++;
          }
        }
        if (!empty_non_axis_sizes) {
          L++;
          if (((int32_T)L < 1) || ((int32_T)L > ibmat + 1)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)L, 1, ibmat + 1,
                                          &gc_emlrtBCI, (emlrtConstCTX)sp);
          }
          X_data[(int32_T)L - 1] = j;
          if (((int32_T)L < 1) || ((int32_T)L > ibmat + 1)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)L, 1, ibmat + 1,
                                          &hc_emlrtBCI, (emlrtConstCTX)sp);
          }
          X_data[(int32_T)L + ibmat] = Xj;
          j++;
          sizes_idx_1++;
          jcol = (int32_T)L;
          for (k = 0; k < jcol; k++) {
            if (FJE->size[1] < 1) {
              emlrtDynamicBoundsCheckR2012b(1, 1, FJE->size[1], &yb_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            if (((int32_T)((uint32_T)k + 1U) < 1) ||
                ((int32_T)((uint32_T)k + 1U) > ibmat + 1)) {
              emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)k + 1U), 1,
                                            ibmat + 1, &oc_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            ibtile = (int32_T)X_data[k];
            if ((ibtile < 1) || (ibtile > FJE->size[0])) {
              emlrtDynamicBoundsCheckR2012b(ibtile, 1, FJE->size[0],
                                            &nc_emlrtBCI, (emlrtConstCTX)sp);
            }
            if ((sizes_idx_1 < 1) || (sizes_idx_1 > FJE->size[2])) {
              emlrtDynamicBoundsCheckR2012b(sizes_idx_1, 1, FJE->size[2],
                                            &pc_emlrtBCI, (emlrtConstCTX)sp);
            }
            FJE_data[(ibtile +
                      FJE->size[0] * FJE->size[1] * (sizes_idx_1 - 1)) -
                     1] = false;
            if (ibtile > FJE->size[0]) {
              emlrtDynamicBoundsCheckR2012b(ibtile, 1, FJE->size[0],
                                            &qc_emlrtBCI, (emlrtConstCTX)sp);
            }
            Xj = X_data[(k + ibmat) + 1];
            qY = Xj + 1U;
            if (Xj + 1U < Xj) {
              qY = MAX_uint32_T;
            }
            if (((int32_T)qY < 1) || ((int32_T)qY > FJE->size[1])) {
              emlrtDynamicBoundsCheckR2012b((int32_T)qY, 1, FJE->size[1],
                                            &rc_emlrtBCI, (emlrtConstCTX)sp);
            }
            if (sizes_idx_1 > FJE->size[2]) {
              emlrtDynamicBoundsCheckR2012b(sizes_idx_1, 1, FJE->size[2],
                                            &sc_emlrtBCI, (emlrtConstCTX)sp);
            }
            FJE_data[((ibtile + FJE->size[0] * ((int32_T)qY - 1)) +
                      FJE->size[0] * FJE->size[1] * (sizes_idx_1 - 1)) -
                     1] = true;
          }
          Xj = 0U;
        }
      }
    }
    if (L >= 1U) {
      if (((int32_T)L < 1) || ((int32_T)L > ibmat + 1)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)L, 1, ibmat + 1, &ec_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      j = X_data[(int32_T)L - 1];
      nrows = (int32_T)L + ibmat;
      Xj = X_data[nrows];
      X_data[(int32_T)L - 1] = 0U;
      if (((int32_T)L < 1) || ((int32_T)L > ibmat + 1)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)L, 1, ibmat + 1, &fc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      X_data[nrows] = 0U;
      L--;
    }
  }
  emxFree_uint32_T(sp, &Xjs);
  if (sizes_idx_1 < 1) {
    sizes_idx_1 = 0;
  } else {
    if (FJE->size[2] < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, FJE->size[2], &ac_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (sizes_idx_1 > FJE->size[2]) {
      emlrtDynamicBoundsCheckR2012b(sizes_idx_1, 1, FJE->size[2], &bc_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
  }
  jcol = outFJE->size[0] * outFJE->size[1] * outFJE->size[2];
  outFJE->size[0] = FJE->size[0];
  outFJE->size[1] = FJE->size[1];
  outFJE->size[2] = sizes_idx_1;
  emxEnsureCapacity_boolean_T(sp, outFJE, jcol, &ji_emlrtRTEI);
  outFJE_data = outFJE->data;
  for (jcol = 0; jcol < sizes_idx_1; jcol++) {
    loop_ub = FJE->size[1];
    for (ibtile = 0; ibtile < loop_ub; ibtile++) {
      iacol_tmp = FJE->size[0];
      for (nrows = 0; nrows < iacol_tmp; nrows++) {
        outFJE_data[(nrows + outFJE->size[0] * ibtile) +
                    outFJE->size[0] * outFJE->size[1] * jcol] =
            FJE_data[(nrows + FJE->size[0] * ibtile) +
                     FJE->size[0] * FJE->size[1] * jcol];
      }
    }
  }
  emxFree_boolean_T(sp, &FJE);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (feasibleJPDAEvents.c) */
