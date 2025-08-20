//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  xzlarfg.cpp
//
//  Code generation for function 'xzlarfg'
//


// Include files
#include "xzlarfg.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "xscal.h"
#include "mwmathutil.h"

// Function Definitions
namespace coder
{
  namespace internal
  {
    namespace reflapack
    {
      real_T xzlarfg(const emlrtStack *sp, int32_T n, real_T *alpha1, real_T x[3])
      {
        emlrtStack b_st;
        emlrtStack st;
        real_T tau;
        real_T xnorm;
        st.prev = sp;
        st.tls = sp->tls;
        b_st.prev = &st;
        b_st.tls = st.tls;
        tau = 0.0;
        if (n > 0) {
          st.site = &wo_emlrtRSI;
          xnorm = blas::xnrm2(n - 1, x);
          if (xnorm != 0.0) {
            xnorm = muDoubleScalarHypot(*alpha1, xnorm);
            if (*alpha1 >= 0.0) {
              xnorm = -xnorm;
            }

            if (muDoubleScalarAbs(xnorm) < 1.0020841800044864E-292) {
              int32_T knt;
              knt = 0;
              do {
                knt++;
                st.site = &xo_emlrtRSI;
                blas::xscal(&st, n - 1, 9.9792015476736E+291, x);
                xnorm *= 9.9792015476736E+291;
                *alpha1 *= 9.9792015476736E+291;
              } while (!(muDoubleScalarAbs(xnorm) >= 1.0020841800044864E-292));

              st.site = &yo_emlrtRSI;
              xnorm = blas::xnrm2(n - 1, x);
              xnorm = muDoubleScalarHypot(*alpha1, xnorm);
              if (*alpha1 >= 0.0) {
                xnorm = -xnorm;
              }

              tau = (xnorm - *alpha1) / xnorm;
              st.site = &ap_emlrtRSI;
              blas::xscal(&st, n - 1, 1.0 / (*alpha1 - xnorm), x);
              st.site = &bp_emlrtRSI;
              if ((1 <= knt) && (knt > 2147483646)) {
                b_st.site = &jc_emlrtRSI;
                check_forloop_overflow_error(&b_st);
              }

              for (int32_T k = 0; k < knt; k++) {
                xnorm *= 1.0020841800044864E-292;
              }

              *alpha1 = xnorm;
            } else {
              tau = (xnorm - *alpha1) / xnorm;
              st.site = &cp_emlrtRSI;
              blas::xscal(&st, n - 1, 1.0 / (*alpha1 - xnorm), x);
              *alpha1 = xnorm;
            }
          }
        }

        return tau;
      }
    }
  }
}

// End of code generation (xzlarfg.cpp)
