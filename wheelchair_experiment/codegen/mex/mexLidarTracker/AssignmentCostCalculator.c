/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * AssignmentCostCalculator.c
 *
 * Code generation for function 'AssignmentCostCalculator'
 *
 */

/* Include files */
#include "AssignmentCostCalculator.h"
#include "det.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_emxutil.h"
#include "mexLidarTracker_types.h"
#include "mrdivide_helper.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "trackingEKF.h"
#include "blas.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo hbb_emlrtRSI = {
    258,                                           /* lineNo */
    "AssignmentCostCalculator/validateInputsImpl", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m" /* pathName */
};

static emlrtRSInfo lbb_emlrtRSI = {
    290,                                        /* lineNo */
    "AssignmentCostCalculator/findPairsToCost", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m" /* pathName */
};

static emlrtRSInfo mbb_emlrtRSI = {
    292,                                        /* lineNo */
    "AssignmentCostCalculator/findPairsToCost", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m" /* pathName */
};

static emlrtRSInfo nbb_emlrtRSI = {
    293,                                        /* lineNo */
    "AssignmentCostCalculator/findPairsToCost", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m" /* pathName */
};

static emlrtRSInfo obb_emlrtRSI = {
    300,                                        /* lineNo */
    "AssignmentCostCalculator/findPairsToCost", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m" /* pathName */
};

static emlrtRSInfo pbb_emlrtRSI = {
    305,                                        /* lineNo */
    "AssignmentCostCalculator/findPairsToCost", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m" /* pathName */
};

static emlrtRSInfo qbb_emlrtRSI = {
    311,                                        /* lineNo */
    "AssignmentCostCalculator/findPairsToCost", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m" /* pathName */
};

static emlrtRSInfo rbb_emlrtRSI = {
    326,                                        /* lineNo */
    "AssignmentCostCalculator/findPairsToCost", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m" /* pathName */
};

static emlrtRSInfo sbb_emlrtRSI = {
    334,                                        /* lineNo */
    "AssignmentCostCalculator/findPairsToCost", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m" /* pathName */
};

static emlrtRSInfo tbb_emlrtRSI =
    {
        659,                  /* lineNo */
        "trackingEKF/models", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m" /* pathName */
};

static emlrtRSInfo ubb_emlrtRSI =
    {
        660,                  /* lineNo */
        "trackingEKF/models", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/"
        "trackingEKF.m" /* pathName */
};

static emlrtRSInfo xbb_emlrtRSI = {
    63,                               /* lineNo */
    "function_handle/parenReference", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/"
    "function_handle.m" /* pathName */
};

static emlrtRSInfo ecb_emlrtRSI = {
    173,      /* lineNo */
    "cvmeas", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/cvmeas.m" /* pathName
                                                                           */
};

static emlrtBCInfo ne_emlrtBCI = {
    -1,                                         /* iFirst */
    -1,                                         /* iLast */
    293,                                        /* lineNo */
    29,                                         /* colNo */
    "",                                         /* aName */
    "AssignmentCostCalculator/findPairsToCost", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m", /* pName */
    0                                                         /* checkKind */
};

static emlrtECInfo m_emlrtECI = {
    -1,       /* nDims */
    170,      /* lineNo */
    1,        /* colNo */
    "cvmeas", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/cvmeas.m" /* pName
                                                                           */
};

static emlrtECInfo n_emlrtECI = {
    -1,       /* nDims */
    169,      /* lineNo */
    1,        /* colNo */
    "cvmeas", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/cvmeas.m" /* pName
                                                                           */
};

static emlrtBCInfo oe_emlrtBCI = {
    -1,                                         /* iFirst */
    -1,                                         /* iLast */
    303,                                        /* lineNo */
    40,                                         /* colNo */
    "",                                         /* aName */
    "AssignmentCostCalculator/findPairsToCost", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m", /* pName */
    0                                                         /* checkKind */
};

static emlrtBCInfo pe_emlrtBCI = {
    -1,                                         /* iFirst */
    -1,                                         /* iLast */
    341,                                        /* lineNo */
    61,                                         /* colNo */
    "",                                         /* aName */
    "AssignmentCostCalculator/findPairsToCost", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m", /* pName */
    0                                                         /* checkKind */
};

static emlrtBCInfo qe_emlrtBCI = {
    -1,                                         /* iFirst */
    -1,                                         /* iLast */
    341,                                        /* lineNo */
    59,                                         /* colNo */
    "",                                         /* aName */
    "AssignmentCostCalculator/findPairsToCost", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m", /* pName */
    0                                                         /* checkKind */
};

static emlrtBCInfo re_emlrtBCI = {
    -1,                                         /* iFirst */
    -1,                                         /* iLast */
    341,                                        /* lineNo */
    44,                                         /* colNo */
    "",                                         /* aName */
    "AssignmentCostCalculator/findPairsToCost", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m", /* pName */
    0                                                         /* checkKind */
};

static emlrtBCInfo se_emlrtBCI = {
    -1,                                         /* iFirst */
    -1,                                         /* iLast */
    341,                                        /* lineNo */
    42,                                         /* colNo */
    "",                                         /* aName */
    "AssignmentCostCalculator/findPairsToCost", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m", /* pName */
    0                                                         /* checkKind */
};

static emlrtECInfo o_emlrtECI = {
    -1,                                         /* nDims */
    335,                                        /* lineNo */
    21,                                         /* colNo */
    "AssignmentCostCalculator/findPairsToCost", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m" /* pName */
};

static emlrtBCInfo te_emlrtBCI = {
    -1,                                         /* iFirst */
    -1,                                         /* iLast */
    335,                                        /* lineNo */
    52,                                         /* colNo */
    "",                                         /* aName */
    "AssignmentCostCalculator/findPairsToCost", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m", /* pName */
    0                                                         /* checkKind */
};

static emlrtBCInfo ue_emlrtBCI = {
    -1,                                         /* iFirst */
    -1,                                         /* iLast */
    335,                                        /* lineNo */
    38,                                         /* colNo */
    "",                                         /* aName */
    "AssignmentCostCalculator/findPairsToCost", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m", /* pName */
    0                                                         /* checkKind */
};

static emlrtBCInfo ve_emlrtBCI = {
    -1,                                         /* iFirst */
    -1,                                         /* iLast */
    335,                                        /* lineNo */
    36,                                         /* colNo */
    "",                                         /* aName */
    "AssignmentCostCalculator/findPairsToCost", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m", /* pName */
    0                                                         /* checkKind */
};

static emlrtECInfo p_emlrtECI = {
    1,                                          /* nDims */
    334,                                        /* lineNo */
    37,                                         /* colNo */
    "AssignmentCostCalculator/findPairsToCost", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m" /* pName */
};

static emlrtBCInfo we_emlrtBCI = {
    -1,                                         /* iFirst */
    -1,                                         /* iLast */
    298,                                        /* lineNo */
    48,                                         /* colNo */
    "",                                         /* aName */
    "AssignmentCostCalculator/findPairsToCost", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m", /* pName */
    0                                                         /* checkKind */
};

static emlrtBCInfo xe_emlrtBCI = {
    -1,                                         /* iFirst */
    -1,                                         /* iLast */
    298,                                        /* lineNo */
    59,                                         /* colNo */
    "",                                         /* aName */
    "AssignmentCostCalculator/findPairsToCost", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m", /* pName */
    0                                                         /* checkKind */
};

static emlrtBCInfo ye_emlrtBCI = {
    -1,                                         /* iFirst */
    -1,                                         /* iLast */
    298,                                        /* lineNo */
    32,                                         /* colNo */
    "",                                         /* aName */
    "AssignmentCostCalculator/findPairsToCost", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m", /* pName */
    0                                                         /* checkKind */
};

static emlrtBCInfo af_emlrtBCI = {
    -1,                                         /* iFirst */
    -1,                                         /* iLast */
    303,                                        /* lineNo */
    51,                                         /* colNo */
    "",                                         /* aName */
    "AssignmentCostCalculator/findPairsToCost", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m", /* pName */
    0                                                         /* checkKind */
};

static emlrtBCInfo bf_emlrtBCI = {
    -1,                                         /* iFirst */
    -1,                                         /* iLast */
    303,                                        /* lineNo */
    53,                                         /* colNo */
    "",                                         /* aName */
    "AssignmentCostCalculator/findPairsToCost", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m", /* pName */
    0                                                         /* checkKind */
};

static emlrtRTEInfo lk_emlrtRTEI = {
    281,                        /* lineNo */
    17,                         /* colNo */
    "AssignmentCostCalculator", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m" /* pName */
};

static emlrtRTEInfo mk_emlrtRTEI = {
    296,                        /* lineNo */
    30,                         /* colNo */
    "AssignmentCostCalculator", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m" /* pName */
};

static emlrtRTEInfo ok_emlrtRTEI = {
    341,                        /* lineNo */
    13,                         /* colNo */
    "AssignmentCostCalculator", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m" /* pName */
};

static emlrtRTEInfo qk_emlrtRTEI = {
    277,                        /* lineNo */
    17,                         /* colNo */
    "AssignmentCostCalculator", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m" /* pName */
};

static emlrtRTEInfo rk_emlrtRTEI = {
    296,                        /* lineNo */
    13,                         /* colNo */
    "AssignmentCostCalculator", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m" /* pName */
};

static emlrtRTEInfo sk_emlrtRTEI = {
    270,                        /* lineNo */
    32,                         /* colNo */
    "AssignmentCostCalculator", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/fusionlib/+matlabshared/"
    "+tracking/+internal/+fusion/AssignmentCostCalculator.m" /* pName */
};

/* Function Declarations */
static void times(real_T in1_data[], int32_T in1_size[2],
                  const real_T in2_data[], const int32_T in2_size[2]);

/* Function Definitions */
static void times(real_T in1_data[], int32_T in1_size[2],
                  const real_T in2_data[], const int32_T in2_size[2])
{
  real_T b_in1_data[90];
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  if (in2_size[0] == 1) {
    loop_ub = in1_size[0];
  } else {
    loop_ub = in2_size[0];
  }
  stride_0_0 = (in1_size[0] != 1);
  stride_1_0 = (in2_size[0] != 1);
  for (i = 0; i < 3; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + loop_ub * i] =
          in1_data[i1 * stride_0_0 + in1_size[0] * i] *
          in2_data[i1 * stride_1_0 + in2_size[0] * i];
    }
  }
  in1_size[0] = loop_ub;
  in1_size[1] = 3;
  for (i = 0; i < 3; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1_size[0] * i] = b_in1_data[i1 + loop_ub * i];
    }
  }
}

void c_AssignmentCostCalculator_find(
    const emlrtStack *sp, d_matlabshared_tracking_interna *tracks[30],
    const emxArray_objectDetection *detections, int32_T numLiveTracks,
    const emxArray_uint32_T *detIndices, emxArray_boolean_T *toCalculate)
{
  static const real_T A[9] = {1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0};
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_boolean_T *allToCalculate;
  emxArray_int32_T *iidx;
  emxArray_real_T *detectionTimes;
  const objectDetection *detections_data;
  trackingEKF *obj;
  real_T allStates_data[180];
  real_T b_allStates_data[180];
  real_T a_data[90];
  real_T lclRect_data[90];
  real_T tgtpos_data[90];
  real_T y_data[30];
  real_T alpha1;
  real_T beta1;
  real_T lastTrackTime;
  real_T *detectionTimes_data;
  int32_T a_size[2];
  int32_T allStates_size[2];
  int32_T b_allStates_size[2];
  int32_T b_iv[2];
  int32_T diffs_size[2];
  int32_T acoef;
  int32_T b_i;
  int32_T b_k;
  int32_T i;
  int32_T i1;
  int32_T k;
  int32_T loop_ub;
  int32_T y_size;
  int32_T *iidx_data;
  const uint32_T *detIndices_data;
  char_T TRANSA1;
  char_T TRANSB1;
  boolean_T *allToCalculate_data;
  boolean_T *toCalculate_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  detIndices_data = detIndices->data;
  detections_data = detections->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_boolean_T(sp, &allToCalculate, 2, &qk_emlrtRTEI, true);
  i = allToCalculate->size[0] * allToCalculate->size[1];
  allToCalculate->size[0] = numLiveTracks;
  allToCalculate->size[1] = detIndices->size[1];
  emxEnsureCapacity_boolean_T(sp, allToCalculate, i, &lk_emlrtRTEI);
  allToCalculate_data = allToCalculate->data;
  loop_ub = numLiveTracks * detIndices->size[1];
  for (i = 0; i < loop_ub; i++) {
    allToCalculate_data[i] = true;
  }
  lastTrackTime = tracks[0]->UpdateTime;
  st.site = &lbb_emlrtRSI;
  b_st.site = &gy_emlrtRSI;
  allStates_size[0] = 6;
  allStates_size[1] = numLiveTracks;
  st.site = &mbb_emlrtRSI;
  if (numLiveTracks > 2147483646) {
    b_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)numLiveTracks;
  for (acoef = 0; acoef < i; acoef++) {
    st.site = &nbb_emlrtRSI;
    b_st.site = &gy_emlrtRSI;
    obj = tracks[acoef]->Filter;
    if (acoef + 1 > numLiveTracks) {
      emlrtDynamicBoundsCheckR2012b(acoef + 1, 1, numLiveTracks, &ne_emlrtBCI,
                                    &b_st);
    }
    for (i1 = 0; i1 < 6; i1++) {
      allStates_data[i1 + 6 * acoef] = obj->pState[i1];
    }
  }
  emxInit_real_T(sp, &detectionTimes, 2, &rk_emlrtRTEI, true);
  i = detectionTimes->size[0] * detectionTimes->size[1];
  detectionTimes->size[0] = 1;
  detectionTimes->size[1] = detIndices->size[1];
  emxEnsureCapacity_real_T(sp, detectionTimes, i, &mk_emlrtRTEI);
  detectionTimes_data = detectionTimes->data;
  i = detIndices->size[1];
  for (b_i = 0; b_i < i; b_i++) {
    i1 = detections->size[0] * detections->size[1] - 1;
    if (b_i + 1 > detIndices->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, detIndices->size[1],
                                    &xe_emlrtBCI, (emlrtConstCTX)sp);
    }
    acoef = (int32_T)detIndices_data[b_i] - 1;
    if ((acoef < 0) || (acoef > i1)) {
      emlrtDynamicBoundsCheckR2012b(acoef, 0, i1, &we_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (b_i + 1 > detectionTimes->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, detectionTimes->size[1],
                                    &ye_emlrtBCI, (emlrtConstCTX)sp);
    }
    detectionTimes_data[b_i] = detections_data[acoef].Time;
  }
  st.site = &obb_emlrtRSI;
  emxInit_int32_T(&st, &iidx, 2, &sk_emlrtRTEI);
  b_st.site = &sx_emlrtRSI;
  e_sort(&b_st, detectionTimes, iidx);
  iidx_data = iidx->data;
  i = detectionTimes->size[0] * detectionTimes->size[1];
  detectionTimes->size[0] = 1;
  detectionTimes->size[1] = iidx->size[1];
  emxEnsureCapacity_real_T(&st, detectionTimes, i, &nk_emlrtRTEI);
  detectionTimes_data = detectionTimes->data;
  loop_ub = iidx->size[1];
  for (i = 0; i < loop_ub; i++) {
    detectionTimes_data[i] = iidx_data[i];
  }
  emxFree_int32_T(&st, &iidx);
  i = detIndices->size[1];
  if (i - 1 >= 0) {
    b_allStates_size[0] = 6;
    diffs_size[1] = 3;
  }
  for (b_i = 0; b_i < i; b_i++) {
    __m128d r;
    __m128d r1;
    int32_T vectorUB;
    boolean_T tmp_data[30];
    boolean_T exitg1;
    boolean_T p;
    i1 = detections->size[0] * detections->size[1];
    if (b_i + 1 > detectionTimes->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, detectionTimes->size[1],
                                    &bf_emlrtBCI, (emlrtConstCTX)sp);
    }
    acoef = (int32_T)detectionTimes_data[b_i];
    if ((acoef < 1) || (acoef > detIndices->size[1])) {
      emlrtDynamicBoundsCheckR2012b(acoef, 1, detIndices->size[1], &af_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    acoef = (int32_T)detIndices_data[acoef - 1] - 1;
    if ((acoef < 0) || (acoef > i1 - 1)) {
      emlrtDynamicBoundsCheckR2012b(acoef, 0, i1 - 1, &oe_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    st.site = &pbb_emlrtRSI;
    b_st.site = &tbb_emlrtRSI;
    b_st.site = &ubb_emlrtRSI;
    st.site = &qbb_emlrtRSI;
    alpha1 = detectionTimes_data[b_i];
    b_allStates_size[1] = allStates_size[1];
    loop_ub = allStates_size[0] * allStates_size[1] - 1;
    if (loop_ub >= 0) {
      memcpy(&b_allStates_data[0], &allStates_data[0],
             (uint32_T)(loop_ub + 1) * sizeof(real_T));
    }
    b_st.site = &xbb_emlrtRSI;
    trackingEKF_models_anonFcn1(
        &b_st, b_allStates_data, b_allStates_size,
        detections_data[(int32_T)detIndices_data[(int32_T)alpha1 - 1] - 1]
                .Time -
            lastTrackTime,
        allStates_data, allStates_size);
    lastTrackTime =
        detections_data[(int32_T)detIndices_data[(int32_T)alpha1 - 1] - 1].Time;
    st.site = &rbb_emlrtRSI;
    b_st.site = &dcb_emlrtRSI;
    c_st.site = &jc_emlrtRSI;
    p = true;
    i1 = 6 * allStates_size[1];
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= i1 - 1)) {
      if ((!muDoubleScalarIsInf(allStates_data[k])) &&
          (!muDoubleScalarIsNaN(allStates_data[k]))) {
        k++;
      } else {
        p = false;
        exitg1 = true;
      }
    }
    if (!p) {
      emlrtErrorWithMessageIdR2018a(
          &c_st, &h_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
          "MATLAB:cvmeas:expectedFinite", 3, 4, 22, "input number 1, state,");
    }
    acoef = 3 * allStates_size[1];
    if (acoef - 1 >= 0) {
      memset(&tgtpos_data[0], 0, (uint32_T)acoef * sizeof(real_T));
    }
    b_iv[0] = 3;
    loop_ub = allStates_size[1];
    b_iv[1] = allStates_size[1];
    a_size[0] = 3;
    a_size[1] = allStates_size[1];
    emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &a_size[0], 2, &n_emlrtECI, &st);
    for (i1 = 0; i1 < loop_ub; i1++) {
      tgtpos_data[3 * i1] = allStates_data[6 * i1];
      tgtpos_data[3 * i1 + 1] = allStates_data[6 * i1 + 2];
      tgtpos_data[3 * i1 + 2] = allStates_data[6 * i1 + 4];
    }
    b_iv[0] = 3;
    b_iv[1] = allStates_size[1];
    a_size[0] = 3;
    a_size[1] = allStates_size[1];
    emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &a_size[0], 2, &m_emlrtECI, &st);
    b_st.site = &ecb_emlrtRSI;
    if (allStates_size[1] == 0) {
      loop_ub = 0;
    } else {
      TRANSB1 = 'N';
      TRANSA1 = 'T';
      alpha1 = 1.0;
      beta1 = 0.0;
      m_t = (ptrdiff_t)3;
      n_t = (ptrdiff_t)allStates_size[1];
      k_t = (ptrdiff_t)3;
      lda_t = (ptrdiff_t)3;
      ldb_t = (ptrdiff_t)3;
      ldc_t = (ptrdiff_t)3;
      loop_ub = allStates_size[1];
      dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, (real_T *)&A[0],
            &lda_t, &tgtpos_data[0], &ldb_t, &beta1, &lclRect_data[0], &ldc_t);
    }
    for (i1 = 0; i1 < 3; i1++) {
      for (acoef = 0; acoef < loop_ub; acoef++) {
        a_data[acoef + loop_ub * i1] = lclRect_data[i1 + 3 * acoef];
      }
    }
    diffs_size[0] = loop_ub;
    if (loop_ub != 0) {
      acoef = (loop_ub != 1);
      i1 = loop_ub - 1;
      for (k = 0; k < 3; k++) {
        for (b_k = 0; b_k <= i1; b_k++) {
          tgtpos_data[b_k + loop_ub * k] =
              a_data[acoef * b_k + loop_ub * k] -
              detections_data[(int32_T)detIndices_data
                                  [(int32_T)detectionTimes_data[b_i] - 1] -
                              1]
                  .Measurement[k];
        }
      }
    }
    st.site = &sbb_emlrtRSI;
    b_st.site = &gcb_emlrtRSI;
    mrdiv(&b_st, tgtpos_data, diffs_size,
          detections_data
              [(int32_T)detIndices_data[(int32_T)detectionTimes_data[b_i] - 1] -
               1]
                  .pMeasurementNoise,
          a_data, a_size);
    if ((a_size[0] != loop_ub) && ((a_size[0] != 1) && (loop_ub != 1))) {
      emlrtDimSizeImpxCheckR2021b(a_size[0], loop_ub, &p_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    st.site = &sbb_emlrtRSI;
    if (a_size[0] == loop_ub) {
      loop_ub = a_size[0] * 3;
      b_k = (loop_ub / 2) << 1;
      vectorUB = b_k - 2;
      for (i1 = 0; i1 <= vectorUB; i1 += 2) {
        r = _mm_loadu_pd(&a_data[i1]);
        r1 = _mm_loadu_pd(&tgtpos_data[i1]);
        _mm_storeu_pd(&a_data[i1], _mm_mul_pd(r, r1));
      }
      for (i1 = b_k; i1 < loop_ub; i1++) {
        a_data[i1] *= tgtpos_data[i1];
      }
    } else {
      times(a_data, a_size, tgtpos_data, diffs_size);
    }
    b_st.site = &vi_emlrtRSI;
    i1 = a_size[0];
    if (a_size[0] == 0) {
      y_size = 0;
    } else {
      y_size = a_size[0];
      memcpy(&y_data[0], &a_data[0], (uint32_T)i1 * sizeof(real_T));
      b_k = (i1 / 2) << 1;
      vectorUB = b_k - 2;
      for (k = 0; k < 2; k++) {
        acoef = (k + 1) * i1;
        for (loop_ub = 0; loop_ub <= vectorUB; loop_ub += 2) {
          r = _mm_loadu_pd(&y_data[loop_ub]);
          r1 = _mm_loadu_pd(&a_data[acoef + loop_ub]);
          _mm_storeu_pd(&y_data[loop_ub], _mm_add_pd(r, r1));
        }
        for (loop_ub = b_k; loop_ub < i1; loop_ub++) {
          y_data[loop_ub] += a_data[acoef + loop_ub];
        }
      }
    }
    st.site = &sbb_emlrtRSI;
    b_st.site = &sbb_emlrtRSI;
    alpha1 = det(
        &b_st,
        detections_data
            [(int32_T)detIndices_data[(int32_T)detectionTimes_data[b_i] - 1] -
             1]
                .pMeasurementNoise);
    if (alpha1 < 0.0) {
      emlrtErrorWithMessageIdR2018a(
          &st, &ec_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 3, "log");
    }
    alpha1 = muDoubleScalarLog(alpha1);
    if (numLiveTracks < 1) {
      loop_ub = 0;
    } else {
      if (allToCalculate->size[0] < 1) {
        emlrtDynamicBoundsCheckR2012b(1, 1, allToCalculate->size[0],
                                      &ve_emlrtBCI, (emlrtConstCTX)sp);
      }
      if (numLiveTracks > allToCalculate->size[0]) {
        emlrtDynamicBoundsCheckR2012b(numLiveTracks, 1, allToCalculate->size[0],
                                      &ue_emlrtBCI, (emlrtConstCTX)sp);
      }
      loop_ub = numLiveTracks;
    }
    if (b_i + 1 > allToCalculate->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, allToCalculate->size[1],
                                    &te_emlrtBCI, (emlrtConstCTX)sp);
    }
    for (i1 = 0; i1 < y_size; i1++) {
      tmp_data[i1] = (y_data[i1] + alpha1 < 500.0);
    }
    emlrtSubAssignSizeCheckR2012b(&loop_ub, 1, &y_size, 1, &o_emlrtECI,
                                  (emlrtCTX)sp);
    for (i1 = 0; i1 < loop_ub; i1++) {
      allToCalculate_data[i1 + allToCalculate->size[0] * b_i] = tmp_data[i1];
    }
  }
  emxFree_real_T(sp, &detectionTimes);
  if (numLiveTracks < 1) {
    loop_ub = 0;
  } else {
    if (allToCalculate->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, allToCalculate->size[0], &se_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (numLiveTracks > allToCalculate->size[0]) {
      emlrtDynamicBoundsCheckR2012b(numLiveTracks, 1, allToCalculate->size[0],
                                    &re_emlrtBCI, (emlrtConstCTX)sp);
    }
    loop_ub = numLiveTracks;
  }
  if (detIndices->size[1] < 1) {
    acoef = 0;
  } else {
    if (allToCalculate->size[1] < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, allToCalculate->size[1], &qe_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (detIndices->size[1] > allToCalculate->size[1]) {
      emlrtDynamicBoundsCheckR2012b(detIndices->size[1], 1,
                                    allToCalculate->size[1], &pe_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    acoef = detIndices->size[1];
  }
  i = toCalculate->size[0] * toCalculate->size[1];
  toCalculate->size[0] = loop_ub;
  toCalculate->size[1] = acoef;
  emxEnsureCapacity_boolean_T(sp, toCalculate, i, &ok_emlrtRTEI);
  toCalculate_data = toCalculate->data;
  for (i = 0; i < acoef; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      toCalculate_data[i1 + toCalculate->size[0] * i] =
          allToCalculate_data[i1 + allToCalculate->size[0] * i];
    }
  }
  emxFree_boolean_T(sp, &allToCalculate);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void c_AssignmentCostCalculator_vali(const emlrtStack *sp,
                                     int32_T numLiveTracks)
{
  emlrtStack b_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ey_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &jc_emlrtRSI;
  if (numLiveTracks < 0) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &ib_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonnegative",
        "MATLAB:AssignmentCostCalculator:expectedNonnegative", 3, 4, 13,
        "numLiveTracks");
  }
  st.site = &hbb_emlrtRSI;
}

/* End of code generation (AssignmentCostCalculator.c) */
