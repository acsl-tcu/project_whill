//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  xzlarf.cpp
//
//  Code generation for function 'xzlarf'
//


// Include files
#include "xzlarf.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include <string.h>

// Variable Definitions
static emlrtRSInfo mp_emlrtRSI = { 103,// lineNo
  "ilazlc",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlarf.m"// pathName 
};

// Function Definitions
namespace coder
{
  namespace internal
  {
    namespace reflapack
    {
      int32_T b_ilazlc(const emlrtStack *sp, int32_T m, int32_T n, const real_T
                       A[27], int32_T ia0)
      {
        emlrtStack b_st;
        emlrtStack st;
        int32_T j;
        boolean_T exitg2;
        st.prev = sp;
        st.tls = sp->tls;
        b_st.prev = &st;
        b_st.tls = st.tls;
        j = n;
        exitg2 = false;
        while ((!exitg2) && (j > 0)) {
          int32_T colbottom;
          int32_T coltop;
          int32_T exitg1;
          coltop = ia0 + (j - 1) * 9;
          colbottom = (coltop + m) - 1;
          st.site = &mp_emlrtRSI;
          if ((coltop <= colbottom) && (colbottom > 2147483646)) {
            b_st.site = &jc_emlrtRSI;
            check_forloop_overflow_error(&b_st);
          }

          do {
            exitg1 = 0;
            if (coltop <= colbottom) {
              if (A[coltop - 1] != 0.0) {
                exitg1 = 1;
              } else {
                coltop++;
              }
            } else {
              j--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }

        return j;
      }

      void b_xzlarf(const emlrtStack *sp, int32_T m, int32_T n, int32_T iv0,
                    real_T tau, real_T C[36], int32_T ic0, real_T work[6])
      {
        emlrtStack b_st;
        emlrtStack c_st;
        emlrtStack d_st;
        emlrtStack e_st;
        emlrtStack f_st;
        emlrtStack st;
        real_T c;
        int32_T colbottom;
        int32_T i;
        int32_T iac;
        int32_T lastc;
        int32_T lastv;
        st.prev = sp;
        st.tls = sp->tls;
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
        if (tau != 0.0) {
          boolean_T exitg2;
          lastv = m - 1;
          i = iv0 + m;
          while ((lastv + 1 > 0) && (C[i - 2] == 0.0)) {
            lastv--;
            i--;
          }

          st.site = &lp_emlrtRSI;
          lastc = n;
          exitg2 = false;
          while ((!exitg2) && (lastc > 0)) {
            int32_T exitg1;
            i = ic0 + (lastc - 1) * 6;
            colbottom = i + lastv;
            b_st.site = &mp_emlrtRSI;
            if ((i <= colbottom) && (colbottom > 2147483646)) {
              c_st.site = &jc_emlrtRSI;
              check_forloop_overflow_error(&c_st);
            }

            do {
              exitg1 = 0;
              if (i <= colbottom) {
                if (C[i - 1] != 0.0) {
                  exitg1 = 1;
                } else {
                  i++;
                }
              } else {
                lastc--;
                exitg1 = 2;
              }
            } while (exitg1 == 0);

            if (exitg1 == 1) {
              exitg2 = true;
            }
          }
        } else {
          lastv = -1;
          lastc = 0;
        }

        if (lastv + 1 > 0) {
          int32_T b;
          int32_T ia;
          int32_T ix;
          st.site = &kp_emlrtRSI;
          b_st.site = &fp_emlrtRSI;
          if (lastc != 0) {
            c_st.site = &hp_emlrtRSI;
            if ((1 <= lastc) && (lastc > 2147483646)) {
              d_st.site = &jc_emlrtRSI;
              check_forloop_overflow_error(&d_st);
            }

            if (0 <= lastc - 1) {
              memset(&work[0], 0, lastc * sizeof(real_T));
            }

            i = 0;
            colbottom = ic0 + 6 * (lastc - 1);
            for (iac = ic0; iac <= colbottom; iac += 6) {
              ix = iv0;
              c = 0.0;
              b = iac + lastv;
              c_st.site = &np_emlrtRSI;
              if ((iac <= b) && (b > 2147483646)) {
                d_st.site = &jc_emlrtRSI;
                check_forloop_overflow_error(&d_st);
              }

              for (ia = iac; ia <= b; ia++) {
                c += C[ia - 1] * C[ix - 1];
                ix++;
              }

              work[i] += c;
              i++;
            }
          }

          st.site = &jp_emlrtRSI;
          b_st.site = &ip_emlrtRSI;
          c_st.site = &ie_emlrtRSI;
          d_st.site = &je_emlrtRSI;
          if (!(-tau == 0.0)) {
            i = ic0;
            colbottom = 0;
            e_st.site = &le_emlrtRSI;
            for (iac = 0; iac < lastc; iac++) {
              if (work[colbottom] != 0.0) {
                c = work[colbottom] * -tau;
                ix = iv0;
                b = lastv + i;
                e_st.site = &ke_emlrtRSI;
                if ((i <= b) && (b > 2147483646)) {
                  f_st.site = &jc_emlrtRSI;
                  check_forloop_overflow_error(&f_st);
                }

                for (ia = i; ia <= b; ia++) {
                  C[ia - 1] += C[ix - 1] * c;
                  ix++;
                }
              }

              colbottom++;
              i += 6;
            }
          }
        }
      }

      int32_T ilazlc(const emlrtStack *sp, int32_T m, int32_T n, const real_T A
                     [54], int32_T ia0)
      {
        emlrtStack b_st;
        emlrtStack st;
        int32_T j;
        boolean_T exitg2;
        st.prev = sp;
        st.tls = sp->tls;
        b_st.prev = &st;
        b_st.tls = st.tls;
        j = n;
        exitg2 = false;
        while ((!exitg2) && (j > 0)) {
          int32_T colbottom;
          int32_T coltop;
          int32_T exitg1;
          coltop = ia0 + (j - 1) * 9;
          colbottom = (coltop + m) - 1;
          st.site = &mp_emlrtRSI;
          if ((coltop <= colbottom) && (colbottom > 2147483646)) {
            b_st.site = &jc_emlrtRSI;
            check_forloop_overflow_error(&b_st);
          }

          do {
            exitg1 = 0;
            if (coltop <= colbottom) {
              if (A[coltop - 1] != 0.0) {
                exitg1 = 1;
              } else {
                coltop++;
              }
            } else {
              j--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }

        return j;
      }

      void xzlarf(const emlrtStack *sp, int32_T m, int32_T n, int32_T iv0,
                  real_T tau, real_T C[9], int32_T ic0, real_T work[3])
      {
        emlrtStack b_st;
        emlrtStack c_st;
        emlrtStack d_st;
        emlrtStack e_st;
        emlrtStack f_st;
        emlrtStack st;
        real_T c;
        int32_T colbottom;
        int32_T i;
        int32_T iac;
        int32_T lastc;
        int32_T lastv;
        st.prev = sp;
        st.tls = sp->tls;
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
        if (tau != 0.0) {
          boolean_T exitg2;
          lastv = m - 1;
          i = iv0 + m;
          while ((lastv + 1 > 0) && (C[i - 2] == 0.0)) {
            lastv--;
            i--;
          }

          st.site = &lp_emlrtRSI;
          lastc = n;
          exitg2 = false;
          while ((!exitg2) && (lastc > 0)) {
            int32_T exitg1;
            i = ic0 + (lastc - 1) * 3;
            colbottom = i + lastv;
            b_st.site = &mp_emlrtRSI;
            if ((i <= colbottom) && (colbottom > 2147483646)) {
              c_st.site = &jc_emlrtRSI;
              check_forloop_overflow_error(&c_st);
            }

            do {
              exitg1 = 0;
              if (i <= colbottom) {
                if (C[i - 1] != 0.0) {
                  exitg1 = 1;
                } else {
                  i++;
                }
              } else {
                lastc--;
                exitg1 = 2;
              }
            } while (exitg1 == 0);

            if (exitg1 == 1) {
              exitg2 = true;
            }
          }
        } else {
          lastv = -1;
          lastc = 0;
        }

        if (lastv + 1 > 0) {
          int32_T b;
          int32_T ia;
          int32_T ix;
          st.site = &kp_emlrtRSI;
          b_st.site = &fp_emlrtRSI;
          if (lastc != 0) {
            c_st.site = &hp_emlrtRSI;
            if ((1 <= lastc) && (lastc > 2147483646)) {
              d_st.site = &jc_emlrtRSI;
              check_forloop_overflow_error(&d_st);
            }

            if (0 <= lastc - 1) {
              memset(&work[0], 0, lastc * sizeof(real_T));
            }

            i = 0;
            colbottom = ic0 + 3 * (lastc - 1);
            for (iac = ic0; iac <= colbottom; iac += 3) {
              ix = iv0;
              c = 0.0;
              b = iac + lastv;
              c_st.site = &np_emlrtRSI;
              if ((iac <= b) && (b > 2147483646)) {
                d_st.site = &jc_emlrtRSI;
                check_forloop_overflow_error(&d_st);
              }

              for (ia = iac; ia <= b; ia++) {
                c += C[ia - 1] * C[ix - 1];
                ix++;
              }

              work[i] += c;
              i++;
            }
          }

          st.site = &jp_emlrtRSI;
          b_st.site = &ip_emlrtRSI;
          c_st.site = &ie_emlrtRSI;
          d_st.site = &je_emlrtRSI;
          if (!(-tau == 0.0)) {
            i = ic0;
            colbottom = 0;
            e_st.site = &le_emlrtRSI;
            for (iac = 0; iac < lastc; iac++) {
              if (work[colbottom] != 0.0) {
                c = work[colbottom] * -tau;
                ix = iv0;
                b = lastv + i;
                e_st.site = &ke_emlrtRSI;
                if ((i <= b) && (b > 2147483646)) {
                  f_st.site = &jc_emlrtRSI;
                  check_forloop_overflow_error(&f_st);
                }

                for (ia = i; ia <= b; ia++) {
                  C[ia - 1] += C[ix - 1] * c;
                  ix++;
                }
              }

              colbottom++;
              i += 3;
            }
          }
        }
      }
    }
  }
}

// End of code generation (xzlarf.cpp)
