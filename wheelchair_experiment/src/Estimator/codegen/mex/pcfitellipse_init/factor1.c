/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * factor1.c
 *
 * Code generation for function 'factor1'
 *
 */

/* Include files */
#include "factor1.h"
#include "eml_int_forloop_overflow_check.h"
#include "fullColLDL2_.h"
#include "ixamax.h"
#include "pcfitellipse_init_data.h"
#include "pcfitellipse_init_internal_types.h"
#include "rt_nonfinite.h"
#include "xcopy.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
void b_factor(const emlrtStack *sp, f_struct_T *obj, const real_T A[25],
              int32_T ndims, int32_T ldA)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T A_maxDiag_idx;
  int32_T idx;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  obj->ndims = ndims;
  st.site = &ig_emlrtRSI;
  if (ndims > 2147483646) {
    b_st.site = &hb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (idx = 0; idx < ndims; idx++) {
    st.site = &ig_emlrtRSI;
    e_xcopy(&st, ndims, A, ldA * idx + 1, obj->FMat, 13 * idx + 1);
  }
  st.site = &ig_emlrtRSI;
  A_maxDiag_idx = b_ixamax(&st, ndims, obj->FMat) - 1;
  A_maxDiag_idx += 13 * A_maxDiag_idx;
  if ((A_maxDiag_idx + 1 < 1) || (A_maxDiag_idx + 1 > 169)) {
    emlrtDynamicBoundsCheckR2012b(A_maxDiag_idx + 1, 1, 169, &dd_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  obj->regTol_ = muDoubleScalarMax(muDoubleScalarAbs(obj->FMat[A_maxDiag_idx]) *
                                       2.2204460492503131E-16,
                                   0.0);
  st.site = &ig_emlrtRSI;
  fullColLDL2_(&st, obj, ndims);
  if (obj->ConvexCheck) {
    st.site = &ig_emlrtRSI;
    idx = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (idx <= ndims - 1) {
        A_maxDiag_idx = (idx + 13 * idx) + 1;
        if ((A_maxDiag_idx < 1) || (A_maxDiag_idx > 169)) {
          emlrtDynamicBoundsCheckR2012b(A_maxDiag_idx, 1, 169, &dd_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (obj->FMat[A_maxDiag_idx - 1] <= 0.0) {
          obj->info = -(idx + 1);
          exitg1 = 1;
        } else {
          idx++;
        }
      } else {
        obj->ConvexCheck = false;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
}

/* End of code generation (factor1.c) */
