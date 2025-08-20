//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  xzsvdc.cpp
//
//  Code generation for function 'xzsvdc'
//


// Include files
#include "xzsvdc.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"
#include "xrot.h"
#include "xscal.h"
#include "xswap.h"
#include "blas.h"
#include "mwmathutil.h"
#include <string.h>

// Variable Definitions
static emlrtRSInfo nc_emlrtRSI = { 407,// lineNo
  "xzsvdc",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"// pathName 
};

static emlrtRSInfo oc_emlrtRSI = { 394,// lineNo
  "xzsvdc",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"// pathName 
};

static emlrtRSInfo pc_emlrtRSI = { 391,// lineNo
  "xzsvdc",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"// pathName 
};

static emlrtRSInfo qc_emlrtRSI = { 380,// lineNo
  "xzsvdc",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"// pathName 
};

static emlrtRSInfo rc_emlrtRSI = { 353,// lineNo
  "xzsvdc",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"// pathName 
};

static emlrtRSInfo sc_emlrtRSI = { 351,// lineNo
  "xzsvdc",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"// pathName 
};

static emlrtRSInfo tc_emlrtRSI = { 334,// lineNo
  "xzsvdc",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"// pathName 
};

static emlrtRSInfo uc_emlrtRSI = { 120,// lineNo
  "xzsvdc",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"// pathName 
};

static emlrtRSInfo vc_emlrtRSI = { 114,// lineNo
  "xzsvdc",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"// pathName 
};

static emlrtRSInfo wc_emlrtRSI = { 94, // lineNo
  "xzsvdc",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"// pathName 
};

static emlrtRSInfo xc_emlrtRSI = { 82, // lineNo
  "xzsvdc",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"// pathName 
};

static emlrtRSInfo yc_emlrtRSI = { 77, // lineNo
  "xzsvdc",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"// pathName 
};

static emlrtRSInfo cd_emlrtRSI = { 21, // lineNo
  "scaleVectorByRecip",                // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/scaleVectorByRecip.m"// pathName 
};

static emlrtRSInfo du_emlrtRSI = { 428,// lineNo
  "xzsvdc",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"// pathName 
};

static emlrtRSInfo eu_emlrtRSI = { 251,// lineNo
  "xzsvdc",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"// pathName 
};

static emlrtRSInfo fu_emlrtRSI = { 240,// lineNo
  "xzsvdc",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"// pathName 
};

static emlrtRSInfo gu_emlrtRSI = { 215,// lineNo
  "xzsvdc",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"// pathName 
};

static emlrtRSInfo hu_emlrtRSI = { 194,// lineNo
  "xzsvdc",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"// pathName 
};

static emlrtRSInfo iu_emlrtRSI = { 184,// lineNo
  "xzsvdc",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"// pathName 
};

static emlrtRTEInfo m_emlrtRTEI = { 269,// lineNo
  13,                                  // colNo
  "xzsvdc",                            // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"// pName 
};

// Function Definitions
namespace coder
{
  namespace internal
  {
    namespace reflapack
    {
      void b_xzsvdc(const emlrtStack *sp, real_T A[9], real_T U[9], real_T S[3],
                    real_T V[9])
      {
        emlrtStack b_st;
        emlrtStack st;
        real_T e[3];
        real_T s[3];
        real_T work[3];
        real_T b;
        real_T f;
        real_T nrm;
        real_T rt;
        real_T scale;
        real_T snorm;
        real_T sqds;
        int32_T jj;
        int32_T m;
        int32_T q;
        int32_T qjj;
        int32_T qp1;
        int32_T qq;
        boolean_T apply_transform;
        boolean_T exitg1;
        st.prev = sp;
        st.tls = sp->tls;
        b_st.prev = &st;
        b_st.tls = st.tls;
        e[0] = 0.0;
        work[0] = 0.0;
        e[1] = 0.0;
        work[1] = 0.0;
        e[2] = 0.0;
        work[2] = 0.0;
        memset(&U[0], 0, 9U * sizeof(real_T));
        memset(&V[0], 0, 9U * sizeof(real_T));
        apply_transform = false;
        st.site = &yc_emlrtRSI;
        nrm = blas::xnrm2(&st, 3, A, 1);
        if (nrm > 0.0) {
          apply_transform = true;
          if (A[0] < 0.0) {
            rt = -nrm;
            s[0] = -nrm;
          } else {
            rt = nrm;
            s[0] = nrm;
          }

          st.site = &xc_emlrtRSI;
          if (muDoubleScalarAbs(rt) >= 1.0020841800044864E-292) {
            b_st.site = &cd_emlrtRSI;
            blas::xscal(&b_st, 3, 1.0 / rt, A, 1);
          } else {
            for (qp1 = 1; qp1 < 4; qp1++) {
              A[qp1 - 1] /= s[0];
            }
          }

          A[0]++;
          s[0] = -s[0];
        } else {
          s[0] = 0.0;
        }

        for (jj = 2; jj < 4; jj++) {
          qjj = 3 * (jj - 1);
          if (apply_transform) {
            st.site = &wc_emlrtRSI;
            nrm = blas::xdotc(&st, 3, A, 1, A, qjj + 1);
            nrm = -(nrm / A[0]);
            blas::xaxpy(3, nrm, 1, A, qjj + 1);
          }

          e[jj - 1] = A[qjj];
        }

        for (jj = 1; jj < 4; jj++) {
          U[jj - 1] = A[jj - 1];
        }

        st.site = &vc_emlrtRSI;
        nrm = blas::xnrm2(&st, e, 2);
        if (nrm == 0.0) {
          e[0] = 0.0;
        } else {
          if (e[1] < 0.0) {
            e[0] = -nrm;
          } else {
            e[0] = nrm;
          }

          st.site = &uc_emlrtRSI;
          f = e[0];
          if (muDoubleScalarAbs(e[0]) >= 1.0020841800044864E-292) {
            b_st.site = &cd_emlrtRSI;
            blas::xscal(&b_st, 1.0 / e[0], e, 2);
          } else {
            for (qp1 = 2; qp1 < 4; qp1++) {
              e[qp1 - 1] /= f;
            }
          }

          e[1]++;
          e[0] = -e[0];
          for (jj = 2; jj < 4; jj++) {
            work[jj - 1] = 0.0;
          }

          for (jj = 2; jj < 4; jj++) {
            blas::xaxpy(2, e[jj - 1], A, 3 * (jj - 1) + 2, work, 2);
          }

          for (jj = 2; jj < 4; jj++) {
            blas::b_xaxpy(2, -e[jj - 1] / e[1], work, 2, A, 3 * (jj - 1) + 2);
          }
        }

        for (jj = 2; jj < 4; jj++) {
          V[jj - 1] = e[jj - 1];
        }

        apply_transform = false;
        st.site = &yc_emlrtRSI;
        nrm = blas::xnrm2(&st, 2, A, 5);
        if (nrm > 0.0) {
          apply_transform = true;
          if (A[4] < 0.0) {
            rt = -nrm;
            s[1] = -nrm;
          } else {
            rt = nrm;
            s[1] = nrm;
          }

          st.site = &xc_emlrtRSI;
          if (muDoubleScalarAbs(rt) >= 1.0020841800044864E-292) {
            b_st.site = &cd_emlrtRSI;
            blas::xscal(&b_st, 2, 1.0 / rt, A, 5);
          } else {
            for (qp1 = 5; qp1 < 7; qp1++) {
              A[qp1 - 1] /= s[1];
            }
          }

          A[4]++;
          s[1] = -s[1];
        } else {
          s[1] = 0.0;
        }

        for (jj = 3; jj < 4; jj++) {
          if (apply_transform) {
            st.site = &wc_emlrtRSI;
            nrm = blas::xdotc(&st, 2, A, 5, A, 8);
            nrm = -(nrm / A[4]);
            blas::xaxpy(2, nrm, 5, A, 8);
          }
        }

        for (jj = 2; jj < 4; jj++) {
          U[jj + 2] = A[jj + 2];
        }

        m = 1;
        s[2] = A[8];
        e[1] = A[7];
        e[2] = 0.0;
        U[6] = 0.0;
        U[7] = 0.0;
        U[8] = 1.0;
        for (q = 1; q >= 0; q--) {
          qp1 = q + 2;
          qq = q + 3 * q;
          if (s[q] != 0.0) {
            for (jj = qp1; jj < 4; jj++) {
              qjj = (q + 3 * (jj - 1)) + 1;
              st.site = &iu_emlrtRSI;
              nrm = blas::xdotc(&st, 3 - q, U, qq + 1, U, qjj);
              nrm = -(nrm / U[qq]);
              blas::xaxpy(3 - q, nrm, qq + 1, U, qjj);
            }

            for (jj = q + 1; jj < 4; jj++) {
              qjj = (jj + 3 * q) - 1;
              U[qjj] = -U[qjj];
            }

            U[qq]++;
            st.site = &hu_emlrtRSI;
            if (0 <= q - 1) {
              U[3 * q] = 0.0;
            }
          } else {
            U[3 * q] = 0.0;
            U[3 * q + 1] = 0.0;
            U[3 * q + 2] = 0.0;
            U[qq] = 1.0;
          }
        }

        for (q = 2; q >= 0; q--) {
          if ((q + 1 <= 1) && (e[0] != 0.0)) {
            st.site = &gu_emlrtRSI;
            nrm = blas::xdotc(&st, 2, V, 2, V, 5);
            nrm = -(nrm / V[1]);
            blas::xaxpy(2, nrm, 2, V, 5);
            st.site = &gu_emlrtRSI;
            nrm = blas::xdotc(&st, 2, V, 2, V, 8);
            nrm = -(nrm / V[1]);
            blas::xaxpy(2, nrm, 2, V, 8);
          }

          V[3 * q] = 0.0;
          V[3 * q + 1] = 0.0;
          V[3 * q + 2] = 0.0;
          V[q + 3 * q] = 1.0;
        }

        if (s[0] != 0.0) {
          rt = muDoubleScalarAbs(s[0]);
          nrm = s[0] / rt;
          s[0] = rt;
          e[0] /= nrm;
          st.site = &fu_emlrtRSI;
          blas::c_xscal(&st, nrm, U, 1);
        }

        if (e[0] != 0.0) {
          rt = muDoubleScalarAbs(e[0]);
          nrm = rt / e[0];
          e[0] = rt;
          s[1] *= nrm;
          st.site = &eu_emlrtRSI;
          blas::c_xscal(&st, nrm, V, 4);
        }

        if (s[1] != 0.0) {
          rt = muDoubleScalarAbs(s[1]);
          nrm = s[1] / rt;
          s[1] = rt;
          e[1] = A[7] / nrm;
          st.site = &fu_emlrtRSI;
          blas::c_xscal(&st, nrm, U, 4);
        }

        if (e[1] != 0.0) {
          rt = muDoubleScalarAbs(e[1]);
          nrm = rt / e[1];
          e[1] = rt;
          s[2] = A[8] * nrm;
          st.site = &eu_emlrtRSI;
          blas::c_xscal(&st, nrm, V, 7);
        }

        if (s[2] != 0.0) {
          rt = muDoubleScalarAbs(s[2]);
          nrm = s[2] / rt;
          s[2] = rt;
          st.site = &fu_emlrtRSI;
          blas::c_xscal(&st, nrm, U, 7);
        }

        qq = 0;
        snorm = muDoubleScalarMax(muDoubleScalarMax(muDoubleScalarMax(s[0], e[0]),
          muDoubleScalarMax(s[1], e[1])), muDoubleScalarMax(s[2], 0.0));
        exitg1 = false;
        while ((!exitg1) && (m + 2 > 0)) {
          if (qq >= 75) {
            emlrtErrorWithMessageIdR2018a(sp, &m_emlrtRTEI,
              "Coder:MATLAB:svd_NoConvergence", "Coder:MATLAB:svd_NoConvergence",
              0);
          } else {
            jj = m;
            int32_T exitg2;
            do {
              exitg2 = 0;
              q = jj + 1;
              if (jj + 1 == 0) {
                exitg2 = 1;
              } else {
                nrm = muDoubleScalarAbs(e[jj]);
                if ((nrm <= 2.2204460492503131E-16 * (muDoubleScalarAbs(s[jj]) +
                      muDoubleScalarAbs(s[jj + 1]))) || (nrm <=
                     1.0020841800044864E-292) || ((qq > 20) && (nrm <=
                      2.2204460492503131E-16 * snorm))) {
                  e[jj] = 0.0;
                  exitg2 = 1;
                } else {
                  jj--;
                }
              }
            } while (exitg2 == 0);

            if (jj + 1 == m + 1) {
              qjj = 4;
            } else {
              boolean_T exitg3;
              qp1 = m + 2;
              qjj = m + 2;
              exitg3 = false;
              while ((!exitg3) && (qjj >= jj + 1)) {
                qp1 = qjj;
                if (qjj == jj + 1) {
                  exitg3 = true;
                } else {
                  nrm = 0.0;
                  if (qjj < m + 2) {
                    nrm = muDoubleScalarAbs(e[qjj - 1]);
                  }

                  if (qjj > jj + 2) {
                    nrm += muDoubleScalarAbs(e[qjj - 2]);
                  }

                  rt = muDoubleScalarAbs(s[qjj - 1]);
                  if ((rt <= 2.2204460492503131E-16 * nrm) || (rt <=
                       1.0020841800044864E-292)) {
                    s[qjj - 1] = 0.0;
                    exitg3 = true;
                  } else {
                    qjj--;
                  }
                }
              }

              if (qp1 == jj + 1) {
                qjj = 3;
              } else if (qp1 == m + 2) {
                qjj = 1;
              } else {
                qjj = 2;
                q = qp1;
              }
            }

            switch (qjj) {
             case 1:
              f = e[m];
              e[m] = 0.0;
              qjj = m + 1;
              for (qp1 = qjj; qp1 >= q + 1; qp1--) {
                st.site = &tc_emlrtRSI;
                sqds = 0.0;
                scale = 0.0;
                drotg(&s[qp1 - 1], &f, &sqds, &scale);
                if (qp1 > q + 1) {
                  f = -scale * e[0];
                  e[0] *= sqds;
                }

                blas::b_xrot(V, 3 * (qp1 - 1) + 1, 3 * (m + 1) + 1, sqds, scale);
              }
              break;

             case 2:
              f = e[q - 1];
              e[q - 1] = 0.0;
              st.site = &sc_emlrtRSI;
              for (qp1 = q + 1; qp1 <= m + 2; qp1++) {
                st.site = &rc_emlrtRSI;
                sqds = 0.0;
                scale = 0.0;
                drotg(&s[qp1 - 1], &f, &sqds, &scale);
                nrm = e[qp1 - 1];
                f = -scale * nrm;
                e[qp1 - 1] = nrm * sqds;
                blas::b_xrot(U, 3 * (qp1 - 1) + 1, 3 * (q - 1) + 1, sqds, scale);
              }
              break;

             case 3:
              qjj = m + 1;
              nrm = s[m + 1];
              scale = muDoubleScalarMax(muDoubleScalarMax(muDoubleScalarMax
                (muDoubleScalarMax(muDoubleScalarAbs(nrm), muDoubleScalarAbs(s[m])),
                 muDoubleScalarAbs(e[m])), muDoubleScalarAbs(s[q])),
                muDoubleScalarAbs(e[q]));
              f = nrm / scale;
              nrm = s[m] / scale;
              rt = e[m] / scale;
              sqds = s[q] / scale;
              b = ((nrm + f) * (nrm - f) + rt * rt) / 2.0;
              nrm = f * rt;
              nrm *= nrm;
              if ((b != 0.0) || (nrm != 0.0)) {
                rt = b * b + nrm;
                st.site = &qc_emlrtRSI;
                if (rt < 0.0) {
                  emlrtErrorWithMessageIdR2018a(&st, &ob_emlrtRTEI,
                    "Coder:toolbox:ElFunDomainError",
                    "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
                }

                rt = muDoubleScalarSqrt(rt);
                if (b < 0.0) {
                  rt = -rt;
                }

                rt = nrm / (b + rt);
              } else {
                rt = 0.0;
              }

              f = (sqds + f) * (sqds - f) + rt;
              nrm = sqds * (e[q] / scale);
              st.site = &pc_emlrtRSI;
              for (qp1 = q + 1; qp1 <= qjj; qp1++) {
                st.site = &oc_emlrtRSI;
                sqds = 0.0;
                scale = 0.0;
                drotg(&f, &nrm, &sqds, &scale);
                if (qp1 > q + 1) {
                  e[0] = f;
                }

                nrm = e[qp1 - 1];
                rt = s[qp1 - 1];
                f = sqds * rt + scale * nrm;
                e[qp1 - 1] = sqds * nrm - scale * rt;
                rt = s[qp1];
                b = scale * rt;
                rt *= sqds;
                blas::b_xrot(V, 3 * (qp1 - 1) + 1, 3 * qp1 + 1, sqds, scale);
                st.site = &nc_emlrtRSI;
                sqds = 0.0;
                scale = 0.0;
                drotg(&f, &b, &sqds, &scale);
                s[qp1 - 1] = f;
                f = sqds * e[qp1 - 1] + scale * rt;
                rt = -scale * e[qp1 - 1] + sqds * rt;
                s[qp1] = rt;
                nrm = scale * e[qp1];
                e[qp1] *= sqds;
                blas::b_xrot(U, 3 * (qp1 - 1) + 1, 3 * qp1 + 1, sqds, scale);
              }

              e[m] = f;
              qq++;
              break;

             default:
              if (s[q] < 0.0) {
                s[q] = -s[q];
                st.site = &du_emlrtRSI;
                blas::c_xscal(&st, -1.0, V, 3 * q + 1);
              }

              qp1 = q + 1;
              while ((q + 1 < 3) && (s[q] < s[qp1])) {
                rt = s[q];
                s[q] = s[qp1];
                s[qp1] = rt;
                blas::b_xswap(V, 3 * q + 1, 3 * (q + 1) + 1);
                blas::b_xswap(U, 3 * q + 1, 3 * (q + 1) + 1);
                q = qp1;
                qp1++;
              }

              qq = 0;
              m--;
              break;
            }
          }
        }

        S[0] = s[0];
        S[1] = s[1];
        S[2] = s[2];
      }

      void xzsvdc(const emlrtStack *sp, real_T A[9], real_T S[3])
      {
        emlrtStack b_st;
        emlrtStack st;
        real_T e[3];
        real_T s[3];
        real_T work[3];
        real_T b;
        real_T nrm;
        real_T r;
        real_T scale;
        real_T sm;
        real_T sn;
        real_T snorm;
        real_T sqds;
        int32_T ii;
        int32_T iter;
        int32_T m;
        int32_T qjj;
        int32_T qs;
        boolean_T apply_transform;
        boolean_T exitg1;
        st.prev = sp;
        st.tls = sp->tls;
        b_st.prev = &st;
        b_st.tls = st.tls;
        e[0] = 0.0;
        work[0] = 0.0;
        e[1] = 0.0;
        work[1] = 0.0;
        e[2] = 0.0;
        work[2] = 0.0;
        apply_transform = false;
        st.site = &yc_emlrtRSI;
        nrm = blas::xnrm2(&st, 3, A, 1);
        if (nrm > 0.0) {
          apply_transform = true;
          if (A[0] < 0.0) {
            sqds = -nrm;
            s[0] = -nrm;
          } else {
            sqds = nrm;
            s[0] = nrm;
          }

          st.site = &xc_emlrtRSI;
          if (muDoubleScalarAbs(sqds) >= 1.0020841800044864E-292) {
            b_st.site = &cd_emlrtRSI;
            blas::xscal(&b_st, 3, 1.0 / sqds, A, 1);
          } else {
            for (qs = 1; qs < 4; qs++) {
              A[qs - 1] /= s[0];
            }
          }

          A[0]++;
          s[0] = -s[0];
        } else {
          s[0] = 0.0;
        }

        for (qs = 2; qs < 4; qs++) {
          qjj = 3 * (qs - 1);
          if (apply_transform) {
            st.site = &wc_emlrtRSI;
            nrm = blas::xdotc(&st, 3, A, 1, A, qjj + 1);
            nrm = -(nrm / A[0]);
            blas::xaxpy(3, nrm, 1, A, qjj + 1);
          }

          e[qs - 1] = A[qjj];
        }

        st.site = &vc_emlrtRSI;
        nrm = blas::xnrm2(&st, e, 2);
        if (nrm == 0.0) {
          e[0] = 0.0;
        } else {
          if (e[1] < 0.0) {
            e[0] = -nrm;
          } else {
            e[0] = nrm;
          }

          st.site = &uc_emlrtRSI;
          sm = e[0];
          if (muDoubleScalarAbs(e[0]) >= 1.0020841800044864E-292) {
            b_st.site = &cd_emlrtRSI;
            blas::xscal(&b_st, 1.0 / e[0], e, 2);
          } else {
            for (qs = 2; qs < 4; qs++) {
              e[qs - 1] /= sm;
            }
          }

          e[1]++;
          e[0] = -e[0];
          for (ii = 2; ii < 4; ii++) {
            work[ii - 1] = 0.0;
          }

          for (qs = 2; qs < 4; qs++) {
            blas::xaxpy(2, e[qs - 1], A, 3 * (qs - 1) + 2, work, 2);
          }

          for (qs = 2; qs < 4; qs++) {
            blas::b_xaxpy(2, -e[qs - 1] / e[1], work, 2, A, 3 * (qs - 1) + 2);
          }
        }

        apply_transform = false;
        st.site = &yc_emlrtRSI;
        nrm = blas::xnrm2(&st, 2, A, 5);
        if (nrm > 0.0) {
          apply_transform = true;
          if (A[4] < 0.0) {
            sqds = -nrm;
            s[1] = -nrm;
          } else {
            sqds = nrm;
            s[1] = nrm;
          }

          st.site = &xc_emlrtRSI;
          if (muDoubleScalarAbs(sqds) >= 1.0020841800044864E-292) {
            b_st.site = &cd_emlrtRSI;
            blas::xscal(&b_st, 2, 1.0 / sqds, A, 5);
          } else {
            for (qs = 5; qs < 7; qs++) {
              A[qs - 1] /= s[1];
            }
          }

          A[4]++;
          s[1] = -s[1];
        } else {
          s[1] = 0.0;
        }

        for (qs = 3; qs < 4; qs++) {
          if (apply_transform) {
            st.site = &wc_emlrtRSI;
            nrm = blas::xdotc(&st, 2, A, 5, A, 8);
            nrm = -(nrm / A[4]);
            blas::xaxpy(2, nrm, 5, A, 8);
          }
        }

        m = 1;
        s[2] = A[8];
        e[1] = A[7];
        e[2] = 0.0;
        iter = 0;
        sqds = s[0];
        if (s[0] != 0.0) {
          nrm = muDoubleScalarAbs(s[0]);
          r = s[0] / nrm;
          sqds = nrm;
          s[0] = nrm;
          e[0] /= r;
        }

        if (e[0] != 0.0) {
          nrm = muDoubleScalarAbs(e[0]);
          r = nrm / e[0];
          e[0] = nrm;
          s[1] *= r;
        }

        snorm = muDoubleScalarMax(muDoubleScalarAbs(sqds), e[0]);
        sqds = s[1];
        if (s[1] != 0.0) {
          nrm = muDoubleScalarAbs(s[1]);
          r = s[1] / nrm;
          sqds = nrm;
          s[1] = nrm;
          e[1] = A[7] / r;
        }

        if (e[1] != 0.0) {
          nrm = muDoubleScalarAbs(e[1]);
          r = nrm / e[1];
          e[1] = nrm;
          s[2] = A[8] * r;
        }

        snorm = muDoubleScalarMax(snorm, muDoubleScalarMax(muDoubleScalarAbs
          (sqds), e[1]));
        sqds = s[2];
        if (s[2] != 0.0) {
          nrm = muDoubleScalarAbs(s[2]);
          sqds = nrm;
          s[2] = nrm;
        }

        snorm = muDoubleScalarMax(snorm, muDoubleScalarMax(muDoubleScalarAbs
          (sqds), 0.0));
        exitg1 = false;
        while ((!exitg1) && (m + 2 > 0)) {
          if (iter >= 75) {
            emlrtErrorWithMessageIdR2018a(sp, &m_emlrtRTEI,
              "Coder:MATLAB:svd_NoConvergence", "Coder:MATLAB:svd_NoConvergence",
              0);
          } else {
            int32_T q;
            ii = m;
            int32_T exitg2;
            do {
              exitg2 = 0;
              q = ii + 1;
              if (ii + 1 == 0) {
                exitg2 = 1;
              } else {
                nrm = muDoubleScalarAbs(e[ii]);
                if ((nrm <= 2.2204460492503131E-16 * (muDoubleScalarAbs(s[ii]) +
                      muDoubleScalarAbs(s[ii + 1]))) || (nrm <=
                     1.0020841800044864E-292) || ((iter > 20) && (nrm <=
                      2.2204460492503131E-16 * snorm))) {
                  e[ii] = 0.0;
                  exitg2 = 1;
                } else {
                  ii--;
                }
              }
            } while (exitg2 == 0);

            if (ii + 1 == m + 1) {
              qjj = 4;
            } else {
              boolean_T exitg3;
              qs = m + 2;
              qjj = m + 2;
              exitg3 = false;
              while ((!exitg3) && (qjj >= ii + 1)) {
                qs = qjj;
                if (qjj == ii + 1) {
                  exitg3 = true;
                } else {
                  nrm = 0.0;
                  if (qjj < m + 2) {
                    nrm = muDoubleScalarAbs(e[qjj - 1]);
                  }

                  if (qjj > ii + 2) {
                    nrm += muDoubleScalarAbs(e[qjj - 2]);
                  }

                  r = muDoubleScalarAbs(s[qjj - 1]);
                  if ((r <= 2.2204460492503131E-16 * nrm) || (r <=
                       1.0020841800044864E-292)) {
                    s[qjj - 1] = 0.0;
                    exitg3 = true;
                  } else {
                    qjj--;
                  }
                }
              }

              if (qs == ii + 1) {
                qjj = 3;
              } else if (qs == m + 2) {
                qjj = 1;
              } else {
                qjj = 2;
                q = qs;
              }
            }

            switch (qjj) {
             case 1:
              r = e[m];
              e[m] = 0.0;
              qjj = m + 1;
              for (qs = qjj; qs >= q + 1; qs--) {
                st.site = &tc_emlrtRSI;
                scale = 0.0;
                sn = 0.0;
                drotg(&s[qs - 1], &r, &scale, &sn);
                if (qs > q + 1) {
                  r = -sn * e[0];
                  e[0] *= scale;
                }
              }
              break;

             case 2:
              r = e[q - 1];
              e[q - 1] = 0.0;
              st.site = &sc_emlrtRSI;
              for (qs = q + 1; qs <= m + 2; qs++) {
                st.site = &rc_emlrtRSI;
                scale = 0.0;
                sn = 0.0;
                drotg(&s[qs - 1], &r, &scale, &sn);
                nrm = e[qs - 1];
                r = -sn * nrm;
                e[qs - 1] = nrm * scale;
              }
              break;

             case 3:
              qjj = m + 1;
              nrm = s[m + 1];
              scale = muDoubleScalarMax(muDoubleScalarMax(muDoubleScalarMax
                (muDoubleScalarMax(muDoubleScalarAbs(nrm), muDoubleScalarAbs(s[m])),
                 muDoubleScalarAbs(e[m])), muDoubleScalarAbs(s[q])),
                muDoubleScalarAbs(e[q]));
              sm = nrm / scale;
              nrm = s[m] / scale;
              r = e[m] / scale;
              sqds = s[q] / scale;
              b = ((nrm + sm) * (nrm - sm) + r * r) / 2.0;
              nrm = sm * r;
              nrm *= nrm;
              if ((b != 0.0) || (nrm != 0.0)) {
                r = b * b + nrm;
                st.site = &qc_emlrtRSI;
                if (r < 0.0) {
                  emlrtErrorWithMessageIdR2018a(&st, &ob_emlrtRTEI,
                    "Coder:toolbox:ElFunDomainError",
                    "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
                }

                r = muDoubleScalarSqrt(r);
                if (b < 0.0) {
                  r = -r;
                }

                r = nrm / (b + r);
              } else {
                r = 0.0;
              }

              r += (sqds + sm) * (sqds - sm);
              nrm = sqds * (e[q] / scale);
              st.site = &pc_emlrtRSI;
              for (qs = q + 1; qs <= qjj; qs++) {
                st.site = &oc_emlrtRSI;
                scale = 0.0;
                sn = 0.0;
                drotg(&r, &nrm, &scale, &sn);
                if (qs > q + 1) {
                  e[0] = r;
                }

                nrm = e[qs - 1];
                r = s[qs - 1];
                sm = scale * r + sn * nrm;
                e[qs - 1] = scale * nrm - sn * r;
                sqds = s[qs];
                b = sn * sqds;
                sqds *= scale;
                st.site = &nc_emlrtRSI;
                scale = 0.0;
                sn = 0.0;
                drotg(&sm, &b, &scale, &sn);
                s[qs - 1] = sm;
                r = scale * e[qs - 1] + sn * sqds;
                sqds = -sn * e[qs - 1] + scale * sqds;
                s[qs] = sqds;
                nrm = sn * e[qs];
                e[qs] *= scale;
              }

              e[m] = r;
              iter++;
              break;

             default:
              if (s[q] < 0.0) {
                s[q] = -s[q];
              }

              qjj = q + 1;
              while ((q + 1 < 3) && (s[q] < s[qjj])) {
                nrm = s[q];
                s[q] = s[qjj];
                s[qjj] = nrm;
                q = qjj;
                qjj++;
              }

              iter = 0;
              m--;
              break;
            }
          }
        }

        S[0] = s[0];
        S[1] = s[1];
        S[2] = s[2];
      }

      void xzsvdc(const emlrtStack *sp, real_T A[36], real_T U[36], real_T S[6],
                  real_T V[36])
      {
        emlrtStack b_st;
        emlrtStack st;
        real_T e[6];
        real_T s[6];
        real_T work[6];
        real_T b;
        real_T nrm;
        real_T rt;
        real_T scale;
        real_T sm;
        real_T sn;
        real_T snorm;
        real_T sqds;
        int32_T i;
        int32_T k;
        int32_T m;
        int32_T q;
        int32_T qp1;
        int32_T qp1jj;
        int32_T qq;
        boolean_T exitg1;
        st.prev = sp;
        st.tls = sp->tls;
        b_st.prev = &st;
        b_st.tls = st.tls;
        for (i = 0; i < 6; i++) {
          s[i] = 0.0;
          e[i] = 0.0;
          work[i] = 0.0;
        }

        memset(&U[0], 0, 36U * sizeof(real_T));
        memset(&V[0], 0, 36U * sizeof(real_T));
        for (q = 0; q < 5; q++) {
          boolean_T apply_transform;
          qp1 = q + 2;
          qp1jj = q + 6 * q;
          qq = qp1jj + 1;
          apply_transform = false;
          st.site = &yc_emlrtRSI;
          nrm = blas::b_xnrm2(&st, 6 - q, A, qp1jj + 1);
          if (nrm > 0.0) {
            apply_transform = true;
            if (A[qp1jj] < 0.0) {
              sqds = -nrm;
              s[q] = -nrm;
            } else {
              sqds = nrm;
              s[q] = nrm;
            }

            st.site = &xc_emlrtRSI;
            if (muDoubleScalarAbs(sqds) >= 1.0020841800044864E-292) {
              b_st.site = &cd_emlrtRSI;
              blas::b_xscal(&b_st, 6 - q, 1.0 / sqds, A, qp1jj + 1);
            } else {
              i = (qp1jj - q) + 6;
              for (k = qq; k <= i; k++) {
                A[k - 1] /= s[q];
              }
            }

            A[qp1jj]++;
            s[q] = -s[q];
          } else {
            s[q] = 0.0;
          }

          for (k = qp1; k < 7; k++) {
            i = q + 6 * (k - 1);
            if (apply_transform) {
              st.site = &wc_emlrtRSI;
              nrm = blas::b_xdotc(&st, 6 - q, A, qp1jj + 1, A, i + 1);
              nrm = -(nrm / A[qp1jj]);
              blas::b_xaxpy(6 - q, nrm, qp1jj + 1, A, i + 1);
            }

            e[k - 1] = A[i];
          }

          for (k = q + 1; k < 7; k++) {
            i = (k + 6 * q) - 1;
            U[i] = A[i];
          }

          if (q + 1 <= 4) {
            st.site = &vc_emlrtRSI;
            nrm = blas::c_xnrm2(&st, 5 - q, e, q + 2);
            if (nrm == 0.0) {
              e[q] = 0.0;
            } else {
              if (e[q + 1] < 0.0) {
                e[q] = -nrm;
              } else {
                e[q] = nrm;
              }

              st.site = &uc_emlrtRSI;
              sm = e[q];
              if (muDoubleScalarAbs(e[q]) >= 1.0020841800044864E-292) {
                b_st.site = &cd_emlrtRSI;
                blas::c_xscal(&b_st, 5 - q, 1.0 / e[q], e, q + 2);
              } else {
                for (k = qp1; k < 7; k++) {
                  e[k - 1] /= sm;
                }
              }

              e[q + 1]++;
              e[q] = -e[q];
              for (k = qp1; k < 7; k++) {
                work[k - 1] = 0.0;
              }

              for (k = qp1; k < 7; k++) {
                blas::c_xaxpy(5 - q, e[k - 1], A, (q + 6 * (k - 1)) + 2, work, q
                              + 2);
              }

              for (k = qp1; k < 7; k++) {
                blas::d_xaxpy(5 - q, -e[k - 1] / e[q + 1], work, q + 2, A, (q +
                  6 * (k - 1)) + 2);
              }
            }

            for (k = qp1; k < 7; k++) {
              V[(k + 6 * q) - 1] = e[k - 1];
            }
          }
        }

        m = 4;
        s[5] = A[35];
        e[4] = A[34];
        e[5] = 0.0;
        for (k = 0; k < 6; k++) {
          U[k + 30] = 0.0;
        }

        U[35] = 1.0;
        for (q = 4; q >= 0; q--) {
          qp1 = q + 2;
          qq = q + 6 * q;
          if (s[q] != 0.0) {
            for (k = qp1; k < 7; k++) {
              i = (q + 6 * (k - 1)) + 1;
              st.site = &iu_emlrtRSI;
              nrm = blas::b_xdotc(&st, 6 - q, U, qq + 1, U, i);
              nrm = -(nrm / U[qq]);
              blas::b_xaxpy(6 - q, nrm, qq + 1, U, i);
            }

            for (k = q + 1; k < 7; k++) {
              i = (k + 6 * q) - 1;
              U[i] = -U[i];
            }

            U[qq]++;
            st.site = &hu_emlrtRSI;
            for (k = 0; k < q; k++) {
              U[k + 6 * q] = 0.0;
            }
          } else {
            for (k = 0; k < 6; k++) {
              U[k + 6 * q] = 0.0;
            }

            U[qq] = 1.0;
          }
        }

        for (q = 5; q >= 0; q--) {
          if ((q + 1 <= 4) && (e[q] != 0.0)) {
            qp1 = q + 2;
            i = (q + 6 * q) + 2;
            for (k = qp1; k < 7; k++) {
              qp1jj = (q + 6 * (k - 1)) + 2;
              st.site = &gu_emlrtRSI;
              nrm = blas::b_xdotc(&st, 5 - q, V, i, V, qp1jj);
              nrm = -(nrm / V[i - 1]);
              blas::b_xaxpy(5 - q, nrm, i, V, qp1jj);
            }
          }

          for (k = 0; k < 6; k++) {
            V[k + 6 * q] = 0.0;
          }

          V[q + 6 * q] = 1.0;
        }

        for (q = 0; q < 6; q++) {
          sqds = s[q];
          if (sqds != 0.0) {
            rt = muDoubleScalarAbs(sqds);
            nrm = sqds / rt;
            s[q] = rt;
            if (q + 1 < 6) {
              e[q] /= nrm;
            }

            st.site = &fu_emlrtRSI;
            blas::b_xscal(&st, nrm, U, 6 * q + 1);
          }

          if ((q + 1 < 6) && (e[q] != 0.0)) {
            rt = muDoubleScalarAbs(e[q]);
            nrm = rt / e[q];
            e[q] = rt;
            s[q + 1] *= nrm;
            st.site = &eu_emlrtRSI;
            blas::b_xscal(&st, nrm, V, 6 * (q + 1) + 1);
          }
        }

        qq = 0;
        snorm = 0.0;
        for (k = 0; k < 6; k++) {
          snorm = muDoubleScalarMax(snorm, muDoubleScalarMax(muDoubleScalarAbs
            (s[k]), muDoubleScalarAbs(e[k])));
        }

        exitg1 = false;
        while ((!exitg1) && (m + 2 > 0)) {
          if (qq >= 75) {
            emlrtErrorWithMessageIdR2018a(sp, &m_emlrtRTEI,
              "Coder:MATLAB:svd_NoConvergence", "Coder:MATLAB:svd_NoConvergence",
              0);
          } else {
            k = m;
            int32_T exitg2;
            do {
              exitg2 = 0;
              q = k + 1;
              if (k + 1 == 0) {
                exitg2 = 1;
              } else {
                nrm = muDoubleScalarAbs(e[k]);
                if ((nrm <= 2.2204460492503131E-16 * (muDoubleScalarAbs(s[k]) +
                      muDoubleScalarAbs(s[k + 1]))) || (nrm <=
                     1.0020841800044864E-292) || ((qq > 20) && (nrm <=
                      2.2204460492503131E-16 * snorm))) {
                  e[k] = 0.0;
                  exitg2 = 1;
                } else {
                  k--;
                }
              }
            } while (exitg2 == 0);

            if (k + 1 == m + 1) {
              i = 4;
            } else {
              boolean_T exitg3;
              qp1jj = m + 2;
              i = m + 2;
              exitg3 = false;
              while ((!exitg3) && (i >= k + 1)) {
                qp1jj = i;
                if (i == k + 1) {
                  exitg3 = true;
                } else {
                  nrm = 0.0;
                  if (i < m + 2) {
                    nrm = muDoubleScalarAbs(e[i - 1]);
                  }

                  if (i > k + 2) {
                    nrm += muDoubleScalarAbs(e[i - 2]);
                  }

                  rt = muDoubleScalarAbs(s[i - 1]);
                  if ((rt <= 2.2204460492503131E-16 * nrm) || (rt <=
                       1.0020841800044864E-292)) {
                    s[i - 1] = 0.0;
                    exitg3 = true;
                  } else {
                    i--;
                  }
                }
              }

              if (qp1jj == k + 1) {
                i = 3;
              } else if (qp1jj == m + 2) {
                i = 1;
              } else {
                i = 2;
                q = qp1jj;
              }
            }

            switch (i) {
             case 1:
              rt = e[m];
              e[m] = 0.0;
              i = m + 1;
              for (k = i; k >= q + 1; k--) {
                st.site = &tc_emlrtRSI;
                scale = 0.0;
                sn = 0.0;
                drotg(&s[k - 1], &rt, &scale, &sn);
                if (k > q + 1) {
                  nrm = e[k - 2];
                  rt = -sn * nrm;
                  e[k - 2] = nrm * scale;
                }

                blas::xrot(V, 6 * (k - 1) + 1, 6 * (m + 1) + 1, scale, sn);
              }
              break;

             case 2:
              rt = e[q - 1];
              e[q - 1] = 0.0;
              st.site = &sc_emlrtRSI;
              for (k = q + 1; k <= m + 2; k++) {
                st.site = &rc_emlrtRSI;
                scale = 0.0;
                sn = 0.0;
                drotg(&s[k - 1], &rt, &scale, &sn);
                nrm = e[k - 1];
                rt = -sn * nrm;
                e[k - 1] = nrm * scale;
                blas::xrot(U, 6 * (k - 1) + 1, 6 * (q - 1) + 1, scale, sn);
              }
              break;

             case 3:
              i = m + 1;
              nrm = s[m + 1];
              scale = muDoubleScalarMax(muDoubleScalarMax(muDoubleScalarMax
                (muDoubleScalarMax(muDoubleScalarAbs(nrm), muDoubleScalarAbs(s[m])),
                 muDoubleScalarAbs(e[m])), muDoubleScalarAbs(s[q])),
                muDoubleScalarAbs(e[q]));
              sm = nrm / scale;
              nrm = s[m] / scale;
              rt = e[m] / scale;
              sqds = s[q] / scale;
              b = ((nrm + sm) * (nrm - sm) + rt * rt) / 2.0;
              nrm = sm * rt;
              nrm *= nrm;
              if ((b != 0.0) || (nrm != 0.0)) {
                rt = b * b + nrm;
                st.site = &qc_emlrtRSI;
                if (rt < 0.0) {
                  emlrtErrorWithMessageIdR2018a(&st, &ob_emlrtRTEI,
                    "Coder:toolbox:ElFunDomainError",
                    "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
                }

                rt = muDoubleScalarSqrt(rt);
                if (b < 0.0) {
                  rt = -rt;
                }

                rt = nrm / (b + rt);
              } else {
                rt = 0.0;
              }

              rt += (sqds + sm) * (sqds - sm);
              nrm = sqds * (e[q] / scale);
              st.site = &pc_emlrtRSI;
              for (k = q + 1; k <= i; k++) {
                st.site = &oc_emlrtRSI;
                scale = 0.0;
                sn = 0.0;
                drotg(&rt, &nrm, &scale, &sn);
                if (k > q + 1) {
                  e[k - 2] = rt;
                }

                nrm = e[k - 1];
                rt = s[k - 1];
                sm = scale * rt + sn * nrm;
                e[k - 1] = scale * nrm - sn * rt;
                sqds = s[k];
                b = sn * sqds;
                sqds *= scale;
                blas::xrot(V, 6 * (k - 1) + 1, 6 * k + 1, scale, sn);
                st.site = &nc_emlrtRSI;
                scale = 0.0;
                sn = 0.0;
                drotg(&sm, &b, &scale, &sn);
                s[k - 1] = sm;
                rt = scale * e[k - 1] + sn * sqds;
                sqds = -sn * e[k - 1] + scale * sqds;
                s[k] = sqds;
                nrm = sn * e[k];
                e[k] *= scale;
                blas::xrot(U, 6 * (k - 1) + 1, 6 * k + 1, scale, sn);
              }

              e[m] = rt;
              qq++;
              break;

             default:
              if (s[q] < 0.0) {
                s[q] = -s[q];
                st.site = &du_emlrtRSI;
                blas::b_xscal(&st, -1.0, V, 6 * q + 1);
              }

              qp1 = q + 1;
              while ((q + 1 < 6) && (s[q] < s[qp1])) {
                rt = s[q];
                s[q] = s[qp1];
                s[qp1] = rt;
                blas::xswap(V, 6 * q + 1, 6 * (q + 1) + 1);
                blas::xswap(U, 6 * q + 1, 6 * (q + 1) + 1);
                q = qp1;
                qp1++;
              }

              qq = 0;
              m--;
              break;
            }
          }
        }

        for (k = 0; k < 6; k++) {
          S[k] = s[k];
        }
      }
    }
  }
}

// End of code generation (xzsvdc.cpp)
