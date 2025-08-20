//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  cholPSD.cpp
//
//  Code generation for function 'cholPSD'
//


// Include files
#include "cholPSD.h"
#include "chol.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "svdPSD.h"
#include "vAllOrAny.h"
#include "xdotc.h"
#include "xzsvdc.h"
#include "blas.h"
#include "mwmathutil.h"
#include <stddef.h>
#include <string.h>

// Variable Definitions
static emlrtRSInfo ft_emlrtRSI = { 18, // lineNo
  "cholPSD",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/tracking/trackinglib/+matlabshared/+tracking/+internal/cholPSD.m"// pathName 
};

static emlrtRSInfo ot_emlrtRSI = { 19, // lineNo
  "xzpotrf",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzpotrf.m"// pathName 
};

static emlrtRSInfo pt_emlrtRSI = { 42, // lineNo
  "zpotrfU",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzpotrf.m"// pathName 
};

static emlrtRSInfo vt_emlrtRSI = { 34, // lineNo
  "chol",                              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/matfun/chol.m"// pathName
};

static emlrtRSInfo wt_emlrtRSI = { 16, // lineNo
  "xpotrf",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+lapack/xpotrf.m"// pathName 
};

static emlrtRTEInfo bc_emlrtRTEI = { 80,// lineNo
  23,                                  // colNo
  "cholesky",                          // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/matfun/chol.m"// pName
};

// Function Definitions
namespace coder
{
  namespace matlabshared
  {
    namespace tracking
    {
      namespace internal
      {
        void b_cholPSD(const emlrtStack *sp, const real_T A[9], real_T value[9])
        {
          ptrdiff_t incx_t;
          ptrdiff_t incy_t;
          ptrdiff_t lda_t;
          ptrdiff_t m_t;
          ptrdiff_t n_t;
          emlrtStack b_st;
          emlrtStack c_st;
          emlrtStack d_st;
          emlrtStack e_st;
          emlrtStack f_st;
          emlrtStack st;
          real_T B_data[36];
          real_T b_A[9];
          real_T alpha1;
          real_T beta1;
          int32_T B_size[2];
          int32_T idxAjj_tmp;
          int32_T info;
          char_T TRANSA;
          st.prev = sp;
          st.tls = sp->tls;
          st.site = &et_emlrtRSI;
          b_st.prev = &st;
          b_st.tls = st.tls;
          c_st.prev = &b_st;
          c_st.tls = b_st.tls;
          d_st.prev = &c_st;
          d_st.tls = c_st.tls;
          e_st.prev = &d_st;
          e_st.tls = d_st.tls;
          f_st.prev = &e_st;
          f_st.tls = e_st.tls;
          B_size[0] = 3;
          B_size[1] = 3;
          memcpy(&B_data[0], &A[0], 9U * sizeof(real_T));
          b_st.site = &ht_emlrtRSI;
          info = cholesky(&b_st, B_data, B_size);
          if (info == 0) {
            int32_T idxA1j;
            int32_T j;
            boolean_T exitg1;
            st.site = &ft_emlrtRSI;
            memcpy(&b_A[0], &A[0], 9U * sizeof(real_T));
            b_st.site = &vt_emlrtRSI;
            c_st.site = &kt_emlrtRSI;
            d_st.site = &wt_emlrtRSI;
            e_st.site = &ot_emlrtRSI;
            info = -2;
            j = 0;
            exitg1 = false;
            while ((!exitg1) && (j < 3)) {
              real_T ssq;
              idxA1j = j * 3 + 1;
              idxAjj_tmp = (idxA1j + j) - 1;
              f_st.site = &pt_emlrtRSI;
              ssq = ::coder::internal::blas::xdotc(&f_st, j, b_A, idxA1j, b_A,
                idxA1j);
              ssq = b_A[idxAjj_tmp] - ssq;
              if (ssq > 0.0) {
                ssq = muDoubleScalarSqrt(ssq);
                b_A[idxAjj_tmp] = ssq;
                if (j + 1 < 3) {
                  int32_T idxAjjp1;
                  idxAjjp1 = idxAjj_tmp + 4;
                  if (j >= 1) {
                    alpha1 = -1.0;
                    beta1 = 1.0;
                    TRANSA = 'T';
                    m_t = (ptrdiff_t)j;
                    n_t = (ptrdiff_t)(2 - j);
                    lda_t = (ptrdiff_t)3;
                    incx_t = (ptrdiff_t)1;
                    incy_t = (ptrdiff_t)3;
                    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &b_A[idxA1j + 2], &lda_t,
                          &b_A[idxA1j - 1], &incx_t, &beta1, &b_A[idxAjj_tmp + 3],
                          &incy_t);
                  }

                  ssq = 1.0 / ssq;
                  idxA1j = (idxAjj_tmp + 3 * (1 - j)) + 4;
                  for (idxAjj_tmp = idxAjjp1; idxAjj_tmp <= idxA1j; idxAjj_tmp +=
                       3) {
                    b_A[idxAjj_tmp - 1] *= ssq;
                  }
                }

                j++;
              } else {
                b_A[idxAjj_tmp] = ssq;
                info = j - 1;
                exitg1 = true;
              }
            }

            if (info + 2 != 0) {
              emlrtErrorWithMessageIdR2018a(&b_st, &bc_emlrtRTEI,
                "Coder:MATLAB:posdef", "Coder:MATLAB:posdef", 0);
            }

            c_st.site = &jt_emlrtRSI;
            for (j = 0; j < 3; j++) {
              idxA1j = j + 2;
              c_st.site = &it_emlrtRSI;
              if (idxA1j <= 3) {
                memset(&b_A[(j * 3 + idxA1j) + -1], 0, (4 - idxA1j) * sizeof
                       (real_T));
              }
            }

            for (idxA1j = 0; idxA1j < 3; idxA1j++) {
              value[3 * idxA1j] = b_A[idxA1j];
              value[3 * idxA1j + 1] = b_A[idxA1j + 3];
              value[3 * idxA1j + 2] = b_A[idxA1j + 6];
            }
          } else {
            st.site = &gt_emlrtRSI;
            svdPSD(&st, A, value);
          }
        }

        void cholPSD(const emlrtStack *sp, const real_T A[36], real_T value[36])
        {
          static const int32_T b_iv[2] = { 6, 6 };

          ptrdiff_t incx_t;
          ptrdiff_t incy_t;
          ptrdiff_t lda_t;
          ptrdiff_t m_t;
          ptrdiff_t n_t;
          emlrtStack b_st;
          emlrtStack c_st;
          emlrtStack d_st;
          emlrtStack e_st;
          emlrtStack f_st;
          emlrtStack st;
          real_T B_data[36];
          real_T Ss[36];
          real_T V[36];
          real_T s[6];
          real_T alpha1;
          real_T beta1;
          real_T ssq;
          int32_T B_size[2];
          int32_T info;
          int32_T k;
          char_T TRANSA;
          st.prev = sp;
          st.tls = sp->tls;
          st.site = &et_emlrtRSI;
          b_st.prev = &st;
          b_st.tls = st.tls;
          c_st.prev = &b_st;
          c_st.tls = b_st.tls;
          d_st.prev = &c_st;
          d_st.tls = c_st.tls;
          e_st.prev = &d_st;
          e_st.tls = d_st.tls;
          f_st.prev = &e_st;
          f_st.tls = e_st.tls;
          B_size[0] = 6;
          B_size[1] = 6;
          memcpy(&B_data[0], &A[0], 36U * sizeof(real_T));
          b_st.site = &ht_emlrtRSI;
          info = cholesky(&b_st, B_data, B_size);
          if (info == 0) {
            int32_T i;
            int32_T j;
            boolean_T exitg1;
            st.site = &ft_emlrtRSI;
            memcpy(&Ss[0], &A[0], 36U * sizeof(real_T));
            b_st.site = &vt_emlrtRSI;
            c_st.site = &kt_emlrtRSI;
            d_st.site = &wt_emlrtRSI;
            e_st.site = &ot_emlrtRSI;
            info = -2;
            j = 0;
            exitg1 = false;
            while ((!exitg1) && (j < 6)) {
              i = j * 6 + 1;
              k = (i + j) - 1;
              f_st.site = &pt_emlrtRSI;
              ssq = ::coder::internal::blas::b_xdotc(&f_st, j, Ss, i, Ss, i);
              ssq = Ss[k] - ssq;
              if (ssq > 0.0) {
                ssq = muDoubleScalarSqrt(ssq);
                Ss[k] = ssq;
                if (j + 1 < 6) {
                  int32_T idxAjjp1;
                  idxAjjp1 = k + 7;
                  if (j >= 1) {
                    alpha1 = -1.0;
                    beta1 = 1.0;
                    TRANSA = 'T';
                    m_t = (ptrdiff_t)j;
                    n_t = (ptrdiff_t)(5 - j);
                    lda_t = (ptrdiff_t)6;
                    incx_t = (ptrdiff_t)1;
                    incy_t = (ptrdiff_t)6;
                    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &Ss[i + 5], &lda_t,
                          &Ss[i - 1], &incx_t, &beta1, &Ss[k + 6], &incy_t);
                  }

                  ssq = 1.0 / ssq;
                  i = (k + 6 * (4 - j)) + 7;
                  for (k = idxAjjp1; k <= i; k += 6) {
                    Ss[k - 1] *= ssq;
                  }
                }

                j++;
              } else {
                Ss[k] = ssq;
                info = j - 1;
                exitg1 = true;
              }
            }

            if (info + 2 != 0) {
              emlrtErrorWithMessageIdR2018a(&b_st, &bc_emlrtRTEI,
                "Coder:MATLAB:posdef", "Coder:MATLAB:posdef", 0);
            }

            c_st.site = &jt_emlrtRSI;
            for (j = 0; j < 6; j++) {
              i = j + 2;
              c_st.site = &it_emlrtRSI;
              if (i <= 6) {
                memset(&Ss[(j * 6 + i) + -1], 0, (7 - i) * sizeof(real_T));
              }
            }

            for (i = 0; i < 6; i++) {
              for (k = 0; k < 6; k++) {
                value[k + 6 * i] = Ss[i + 6 * k];
              }
            }
          } else {
            int32_T i;
            boolean_T p;
            st.site = &gt_emlrtRSI;
            b_st.site = &xt_emlrtRSI;
            c_st.site = &ec_emlrtRSI;
            d_st.site = &gc_emlrtRSI;
            e_st.site = &hc_emlrtRSI;
            p = ::coder::internal::flatVectorAllOrAny(A, b_iv);
            if (p) {
              c_st.site = &au_emlrtRSI;
              d_st.site = &cu_emlrtRSI;
              e_st.site = &lc_emlrtRSI;
              memcpy(&B_data[0], &A[0], 36U * sizeof(real_T));
              f_st.site = &mc_emlrtRSI;
              ::coder::internal::reflapack::xzsvdc(&f_st, B_data, Ss, s, V);
            } else {
              c_st.site = &bu_emlrtRSI;
              d_st.site = &cu_emlrtRSI;
              e_st.site = &lc_emlrtRSI;
              memset(&B_data[0], 0, 36U * sizeof(real_T));
              f_st.site = &mc_emlrtRSI;
              ::coder::internal::reflapack::xzsvdc(&f_st, B_data, Ss, s, V);
              for (i = 0; i < 6; i++) {
                s[i] = rtNaN;
              }

              for (i = 0; i < 36; i++) {
                V[i] = rtNaN;
              }
            }

            memset(&Ss[0], 0, 36U * sizeof(real_T));
            for (k = 0; k < 6; k++) {
              Ss[k + 6 * k] = s[k];
            }

            b_st.site = &yt_emlrtRSI;
            p = false;
            for (k = 0; k < 36; k++) {
              if (p || (Ss[k] < 0.0)) {
                p = true;
              }
            }

            if (p) {
              emlrtErrorWithMessageIdR2018a(&b_st, &ob_emlrtRTEI,
                "Coder:toolbox:ElFunDomainError",
                "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
            }

            for (k = 0; k < 36; k++) {
              Ss[k] = muDoubleScalarSqrt(Ss[k]);
            }

            for (i = 0; i < 6; i++) {
              for (k = 0; k < 6; k++) {
                ssq = 0.0;
                for (info = 0; info < 6; info++) {
                  ssq += V[i + 6 * info] * Ss[info + 6 * k];
                }

                value[i + 6 * k] = ssq;
              }
            }
          }
        }
      }
    }
  }
}

// End of code generation (cholPSD.cpp)
