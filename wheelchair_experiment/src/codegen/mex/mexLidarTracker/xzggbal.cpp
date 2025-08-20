//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  xzggbal.cpp
//
//  Code generation for function 'xzggbal'
//


// Include files
#include "xzggbal.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtRSInfo pq_emlrtRSI = { 22, // lineNo
  "xzggbal",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzggbal.m"// pathName 
};

static emlrtRSInfo qq_emlrtRSI = { 26, // lineNo
  "xzggbal",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzggbal.m"// pathName 
};

static emlrtRSInfo rq_emlrtRSI = { 35, // lineNo
  "xzggbal",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzggbal.m"// pathName 
};

static emlrtRSInfo sq_emlrtRSI = { 39, // lineNo
  "xzggbal",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzggbal.m"// pathName 
};

static emlrtRSInfo tq_emlrtRSI = { 139,// lineNo
  "eml_zggbal_eigsearch_rows",         // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzggbal.m"// pathName 
};

static emlrtRSInfo uq_emlrtRSI = { 76, // lineNo
  "eml_zggbal_simtran",                // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzggbal.m"// pathName 
};

static emlrtRSInfo vq_emlrtRSI = { 101,// lineNo
  "eml_zggbal_eigsearch_cols",         // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzggbal.m"// pathName 
};

static emlrtRSInfo wq_emlrtRSI = { 105,// lineNo
  "eml_zggbal_eigsearch_cols",         // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzggbal.m"// pathName 
};

// Function Definitions
namespace coder
{
  namespace internal
  {
    namespace reflapack
    {
      void xzggbal(const emlrtStack *sp, creal_T A[9], int32_T *ilo, int32_T
                   *ihi, int32_T rscale[3])
      {
        emlrtStack b_st;
        emlrtStack c_st;
        emlrtStack st;
        real_T atmp_im;
        real_T atmp_re;
        int32_T A_tmp;
        int32_T exitg2;
        int32_T i;
        int32_T ii;
        int32_T j;
        int32_T jj;
        int32_T nzcount;
        boolean_T exitg3;
        boolean_T exitg4;
        boolean_T found;
        st.prev = sp;
        st.tls = sp->tls;
        b_st.prev = &st;
        b_st.tls = st.tls;
        c_st.prev = &b_st;
        c_st.tls = b_st.tls;
        rscale[0] = 1;
        rscale[1] = 1;
        rscale[2] = 1;
        *ilo = 1;
        *ihi = 3;
        do {
          exitg2 = 0;
          st.site = &pq_emlrtRSI;
          i = 0;
          j = 0;
          found = false;
          ii = *ihi;
          exitg3 = false;
          while ((!exitg3) && (ii > 0)) {
            nzcount = 0;
            i = ii;
            j = *ihi;
            b_st.site = &tq_emlrtRSI;
            if ((1 <= *ihi) && (*ihi > 2147483646)) {
              c_st.site = &jc_emlrtRSI;
              check_forloop_overflow_error(&c_st);
            }

            jj = 0;
            exitg4 = false;
            while ((!exitg4) && (jj <= *ihi - 1)) {
              A_tmp = (ii + 3 * jj) - 1;
              if ((A[A_tmp].re != 0.0) || (A[A_tmp].im != 0.0) || (ii == jj + 1))
              {
                if (nzcount == 0) {
                  j = jj + 1;
                  nzcount = 1;
                  jj++;
                } else {
                  nzcount = 2;
                  exitg4 = true;
                }
              } else {
                jj++;
              }
            }

            if (nzcount < 2) {
              found = true;
              exitg3 = true;
            } else {
              ii--;
            }
          }

          if (!found) {
            exitg2 = 2;
          } else {
            st.site = &qq_emlrtRSI;
            if (i != *ihi) {
              atmp_re = A[i - 1].re;
              atmp_im = A[i - 1].im;
              A[i - 1] = A[*ihi - 1];
              A[*ihi - 1].re = atmp_re;
              A[*ihi - 1].im = atmp_im;
              atmp_re = A[i + 2].re;
              atmp_im = A[i + 2].im;
              A[i + 2] = A[*ihi + 2];
              A[*ihi + 2].re = atmp_re;
              A[*ihi + 2].im = atmp_im;
              atmp_re = A[i + 5].re;
              atmp_im = A[i + 5].im;
              A[i + 5] = A[*ihi + 5];
              A[*ihi + 5].re = atmp_re;
              A[*ihi + 5].im = atmp_im;
            }

            if (j != *ihi) {
              b_st.site = &uq_emlrtRSI;
              if ((1 <= *ihi) && (*ihi > 2147483646)) {
                c_st.site = &jc_emlrtRSI;
                check_forloop_overflow_error(&c_st);
              }

              for (jj = 0; jj < *ihi; jj++) {
                nzcount = jj + 3 * (j - 1);
                atmp_re = A[nzcount].re;
                atmp_im = A[nzcount].im;
                ii = jj + 3 * (*ihi - 1);
                A[nzcount] = A[ii];
                A[ii].re = atmp_re;
                A[ii].im = atmp_im;
              }
            }

            rscale[*ihi - 1] = j;
            (*ihi)--;
            if (*ihi == 1) {
              rscale[0] = 1;
              exitg2 = 1;
            }
          }
        } while (exitg2 == 0);

        if (exitg2 != 1) {
          int32_T exitg1;
          do {
            exitg1 = 0;
            st.site = &rq_emlrtRSI;
            i = 0;
            j = 0;
            found = false;
            b_st.site = &vq_emlrtRSI;
            if ((*ilo <= *ihi) && (*ihi > 2147483646)) {
              c_st.site = &jc_emlrtRSI;
              check_forloop_overflow_error(&c_st);
            }

            jj = *ilo;
            exitg3 = false;
            while ((!exitg3) && (jj <= *ihi)) {
              nzcount = 0;
              i = *ihi;
              j = jj;
              b_st.site = &wq_emlrtRSI;
              ii = *ilo;
              exitg4 = false;
              while ((!exitg4) && (ii <= *ihi)) {
                A_tmp = (ii + 3 * (jj - 1)) - 1;
                if ((A[A_tmp].re != 0.0) || (A[A_tmp].im != 0.0) || (ii == jj))
                {
                  if (nzcount == 0) {
                    i = ii;
                    nzcount = 1;
                    ii++;
                  } else {
                    nzcount = 2;
                    exitg4 = true;
                  }
                } else {
                  ii++;
                }
              }

              if (nzcount < 2) {
                found = true;
                exitg3 = true;
              } else {
                jj++;
              }
            }

            if (!found) {
              exitg1 = 1;
            } else {
              st.site = &sq_emlrtRSI;
              if (i != *ilo) {
                for (jj = *ilo; jj < 4; jj++) {
                  ii = 3 * (jj - 1);
                  nzcount = (i + ii) - 1;
                  atmp_re = A[nzcount].re;
                  atmp_im = A[nzcount].im;
                  ii = (*ilo + ii) - 1;
                  A[nzcount] = A[ii];
                  A[ii].re = atmp_re;
                  A[ii].im = atmp_im;
                }
              }

              if (j != *ilo) {
                b_st.site = &uq_emlrtRSI;
                for (jj = 0; jj < *ihi; jj++) {
                  nzcount = jj + 3 * (j - 1);
                  atmp_re = A[nzcount].re;
                  atmp_im = A[nzcount].im;
                  ii = jj + 3 * (*ilo - 1);
                  A[nzcount] = A[ii];
                  A[ii].re = atmp_re;
                  A[ii].im = atmp_im;
                }
              }

              rscale[*ilo - 1] = j;
              (*ilo)++;
              if (*ilo == *ihi) {
                rscale[*ilo - 1] = *ilo;
                exitg1 = 1;
              }
            }
          } while (exitg1 == 0);
        }
      }
    }
  }
}

// End of code generation (xzggbal.cpp)
