/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fullColLDL2_.c
 *
 * Code generation for function 'fullColLDL2_'
 *
 */

/* Include files */
#include "fullColLDL2_.h"
#include "calc_observation_data.h"
#include "calc_observation_internal_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo qi_emlrtRSI = {
    1,              /* lineNo */
    "fullColLDL2_", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/"
    "+DynamicRegCholManager/fullColLDL2_.p" /* pathName */
};

static emlrtBCInfo fg_emlrtBCI = {
    1,              /* iFirst */
    225,            /* iLast */
    1,              /* lineNo */
    1,              /* colNo */
    "",             /* aName */
    "fullColLDL2_", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/optim/+optim/+coder/"
    "+DynamicRegCholManager/fullColLDL2_.p", /* pName */
    0                                        /* checkKind */
};

/* Function Definitions */
void fullColLDL2_(const emlrtStack *sp, k_struct_T *obj, int32_T NColsRemain)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T ijA;
  int32_T j;
  int32_T jA;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &qi_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  if (NColsRemain > 2147483646) {
    b_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (k = 0; k < NColsRemain; k++) {
    __m128d r;
    real_T alpha1;
    real_T y;
    int32_T LD_diagOffset;
    int32_T b;
    int32_T offset1;
    int32_T scalarLB;
    int32_T subMatrixDim;
    int32_T vectorUB;
    LD_diagOffset = k << 4;
    if ((LD_diagOffset + 1 < 1) || (LD_diagOffset + 1 > 225)) {
      emlrtDynamicBoundsCheckR2012b(LD_diagOffset + 1, 1, 225, &fg_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    alpha1 = -1.0 / obj->FMat[LD_diagOffset];
    subMatrixDim = (NColsRemain - k) - 1;
    offset1 = LD_diagOffset + 2;
    st.site = &qi_emlrtRSI;
    y = obj->workspace_;
    b_st.site = &cf_emlrtRSI;
    c_st.site = &df_emlrtRSI;
    if (subMatrixDim > 2147483646) {
      d_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (jA = 0; jA < subMatrixDim; jA++) {
      y = obj->FMat[(LD_diagOffset + jA) + 1];
    }
    obj->workspace_ = y;
    st.site = &qi_emlrtRSI;
    b_st.site = &jg_emlrtRSI;
    c_st.site = &kg_emlrtRSI;
    if (!(alpha1 == 0.0)) {
      jA = LD_diagOffset + 17;
      d_st.site = &lg_emlrtRSI;
      for (j = 0; j < subMatrixDim; j++) {
        if (y != 0.0) {
          real_T temp;
          temp = y * alpha1;
          b = (subMatrixDim + jA) - 1;
          d_st.site = &ri_emlrtRSI;
          if ((jA <= b) && (b > 2147483646)) {
            e_st.site = &u_emlrtRSI;
            check_forloop_overflow_error(&e_st);
          }
          scalarLB = ((b - jA) + 1) / 2 * 2 + jA;
          vectorUB = scalarLB - 2;
          for (ijA = jA; ijA <= vectorUB; ijA += 2) {
            r = _mm_loadu_pd(&obj->FMat[ijA - 1]);
            r = _mm_add_pd(r, _mm_set1_pd(y * temp));
            _mm_storeu_pd(&obj->FMat[ijA - 1], r);
          }
          for (ijA = scalarLB; ijA <= b; ijA++) {
            obj->FMat[ijA - 1] += y * temp;
          }
        }
        jA += 15;
      }
    }
    alpha1 = 1.0 / obj->FMat[LD_diagOffset];
    st.site = &qi_emlrtRSI;
    b_st.site = &gg_emlrtRSI;
    b = (LD_diagOffset + subMatrixDim) + 1;
    c_st.site = &hg_emlrtRSI;
    if ((LD_diagOffset + 2 <= b) && (b > 2147483646)) {
      d_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    scalarLB = ((b - offset1) + 1) / 2 * 2 + offset1;
    vectorUB = scalarLB - 2;
    for (jA = offset1; jA <= vectorUB; jA += 2) {
      r = _mm_loadu_pd(&obj->FMat[jA - 1]);
      r = _mm_mul_pd(_mm_set1_pd(alpha1), r);
      _mm_storeu_pd(&obj->FMat[jA - 1], r);
    }
    for (jA = scalarLB; jA <= b; jA++) {
      obj->FMat[jA - 1] *= alpha1;
    }
  }
  jA = ((NColsRemain - 1) << 4) + 1;
  if ((jA < 1) || (jA > 225)) {
    emlrtDynamicBoundsCheckR2012b(jA, 1, 225, &fg_emlrtBCI, (emlrtConstCTX)sp);
  }
}

/* End of code generation (fullColLDL2_.c) */
