//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  eig.cpp
//
//  Code generation for function 'eig'
//


// Include files
#include "eig.h"
#include "eigHermitianStandard.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "vAllOrAny.h"
#include "warning.h"
#include "xdhseqr.h"
#include "xnrm2.h"
#include "xscal.h"
#include "xzggbal.h"
#include "xzhgeqz.h"
#include "xzlarf.h"
#include "xzlartg.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <stddef.h>
#include <string.h>

// Variable Definitions
static emlrtRSInfo ko_emlrtRSI = { 93, // lineNo
  "eig",                               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/matfun/eig.m"// pathName
};

static emlrtRSInfo lo_emlrtRSI = { 139,// lineNo
  "eig",                               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/matfun/eig.m"// pathName
};

static emlrtRSInfo mo_emlrtRSI = { 147,// lineNo
  "eig",                               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/matfun/eig.m"// pathName
};

static emlrtRSInfo iq_emlrtRSI = { 59, // lineNo
  "eigStandard",                       // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/matfun/private/eigStandard.m"// pathName 
};

static emlrtRSInfo jq_emlrtRSI = { 53, // lineNo
  "eigStandard",                       // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/matfun/private/eigStandard.m"// pathName 
};

static emlrtRSInfo kq_emlrtRSI = { 29, // lineNo
  "xzgeev",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzgeev.m"// pathName 
};

static emlrtRSInfo lq_emlrtRSI = { 39, // lineNo
  "xzggev",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzggev.m"// pathName 
};

static emlrtRSInfo mq_emlrtRSI = { 84, // lineNo
  "xzggev",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzggev.m"// pathName 
};

static emlrtRSInfo nq_emlrtRSI = { 124,// lineNo
  "xzggev",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzggev.m"// pathName 
};

static emlrtRSInfo oq_emlrtRSI = { 125,// lineNo
  "xzggev",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzggev.m"// pathName 
};

static emlrtRSInfo xq_emlrtRSI = { 62, // lineNo
  "xzgghrd",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzgghrd.m"// pathName 
};

static emlrtRSInfo bt_emlrtRSI = { 44, // lineNo
  "eigStandard",                       // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/matfun/private/eigStandard.m"// pathName 
};

static emlrtRSInfo ct_emlrtRSI = { 38, // lineNo
  "xgeev",                             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+lapack/xgeev.m"// pathName 
};

static emlrtRSInfo dt_emlrtRSI = { 143,// lineNo
  "ceval_xgeev",                       // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+lapack/xgeev.m"// pathName 
};

// Function Definitions
namespace coder
{
  void b_eig(const emlrtStack *sp, const real_T A[36], creal_T V[6])
  {
    static const int32_T b_iv[2] = { 6, 6 };

    static const char_T fname[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_',
      'd', 'g', 'e', 'e', 'v', 'x' };

    ptrdiff_t ihi_t;
    ptrdiff_t ilo_t;
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack d_st;
    emlrtStack e_st;
    emlrtStack f_st;
    emlrtStack g_st;
    emlrtStack h_st;
    emlrtStack i_st;
    emlrtStack j_st;
    emlrtStack k_st;
    emlrtStack st;
    real_T T[36];
    real_T scale[6];
    real_T wimag[6];
    real_T wreal[6];
    real_T tau[5];
    real_T abnrm;
    real_T rconde;
    real_T rcondv;
    real_T vleft;
    real_T vright;
    int32_T ia;
    int32_T j;
    int32_T knt;
    boolean_T p;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &ko_emlrtRSI;
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
    g_st.prev = &f_st;
    g_st.tls = f_st.tls;
    h_st.prev = &g_st;
    h_st.tls = g_st.tls;
    i_st.prev = &h_st;
    i_st.tls = h_st.tls;
    j_st.prev = &i_st;
    j_st.tls = i_st.tls;
    k_st.prev = &j_st;
    k_st.tls = j_st.tls;
    b_st.site = &gc_emlrtRSI;
    c_st.site = &hc_emlrtRSI;
    p = internal::flatVectorAllOrAny(A, b_iv);
    if (!p) {
      for (int32_T i = 0; i < 6; i++) {
        V[i].re = rtNaN;
        V[i].im = 0.0;
      }
    } else {
      int32_T exitg1;
      int32_T i;
      boolean_T exitg2;
      p = true;
      j = 0;
      exitg2 = false;
      while ((!exitg2) && (j < 6)) {
        i = 0;
        do {
          exitg1 = 0;
          if (i <= j) {
            if (!(A[i + 6 * j] == A[j + 6 * i])) {
              p = false;
              exitg1 = 1;
            } else {
              i++;
            }
          } else {
            j++;
            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }

      if (p) {
        int32_T b_i;
        st.site = &lo_emlrtRSI;
        b_st.site = &no_emlrtRSI;
        memcpy(&T[0], &A[0], 36U * sizeof(real_T));
        c_st.site = &oo_emlrtRSI;
        d_st.site = &gc_emlrtRSI;
        e_st.site = &hc_emlrtRSI;
        p = internal::flatVectorAllOrAny(A, b_iv);
        if (!p) {
          for (b_i = 0; b_i < 36; b_i++) {
            T[b_i] = rtNaN;
          }

          b_i = 2;
          for (j = 0; j < 5; j++) {
            if (b_i <= 6) {
              memset(&T[(j * 6 + b_i) + -1], 0, (7 - b_i) * sizeof(real_T));
            }

            b_i++;
          }
        } else {
          c_st.site = &po_emlrtRSI;
          d_st.site = &so_emlrtRSI;
          for (i = 0; i < 6; i++) {
            scale[i] = 0.0;
          }

          for (i = 0; i < 5; i++) {
            int32_T alpha1_tmp;
            int32_T ic0;
            int32_T im1n_tmp;
            int32_T in;
            int32_T jy;
            int32_T lastc;
            int32_T lastv;
            im1n_tmp = i * 6;
            in = (i + 1) * 6;
            alpha1_tmp = (i + 6 * i) + 1;
            vright = T[alpha1_tmp];
            b_i = i + 3;
            b_i = muIntScalarMin_sint32(b_i, 6) + im1n_tmp;
            e_st.site = &to_emlrtRSI;
            tau[i] = 0.0;
            f_st.site = &wo_emlrtRSI;
            vleft = internal::blas::b_xnrm2(&f_st, 4 - i, T, b_i);
            if (vleft != 0.0) {
              vleft = muDoubleScalarHypot(vright, vleft);
              if (vright >= 0.0) {
                vleft = -vleft;
              }

              if (muDoubleScalarAbs(vleft) < 1.0020841800044864E-292) {
                knt = 0;
                do {
                  knt++;
                  f_st.site = &xo_emlrtRSI;
                  internal::blas::b_xscal(&f_st, 4 - i, 9.9792015476736E+291, T,
                    b_i);
                  vleft *= 9.9792015476736E+291;
                  vright *= 9.9792015476736E+291;
                } while (!(muDoubleScalarAbs(vleft) >= 1.0020841800044864E-292));

                f_st.site = &yo_emlrtRSI;
                vleft = internal::blas::b_xnrm2(&f_st, 4 - i, T, b_i);
                vleft = muDoubleScalarHypot(vright, vleft);
                if (vright >= 0.0) {
                  vleft = -vleft;
                }

                tau[i] = (vleft - vright) / vleft;
                f_st.site = &ap_emlrtRSI;
                internal::blas::b_xscal(&f_st, 4 - i, 1.0 / (vright - vleft), T,
                  b_i);
                f_st.site = &bp_emlrtRSI;
                if ((1 <= knt) && (knt > 2147483646)) {
                  g_st.site = &jc_emlrtRSI;
                  check_forloop_overflow_error(&g_st);
                }

                for (b_i = 0; b_i < knt; b_i++) {
                  vleft *= 1.0020841800044864E-292;
                }

                vright = vleft;
              } else {
                tau[i] = (vleft - vright) / vleft;
                f_st.site = &cp_emlrtRSI;
                internal::blas::b_xscal(&f_st, 4 - i, 1.0 / (T[(i + 6 * i) + 1]
                  - vleft), T, b_i);
                vright = vleft;
              }
            }

            T[alpha1_tmp] = 1.0;
            jy = (i + im1n_tmp) + 1;
            ic0 = in + 1;
            e_st.site = &uo_emlrtRSI;
            if (tau[i] != 0.0) {
              lastv = 4 - i;
              b_i = (jy - i) + 4;
              while ((lastv + 1 > 0) && (T[b_i] == 0.0)) {
                lastv--;
                b_i--;
              }

              lastc = 6;
              exitg2 = false;
              while ((!exitg2) && (lastc > 0)) {
                knt = in + lastc;
                ia = knt;
                do {
                  exitg1 = 0;
                  if (ia <= knt + lastv * 6) {
                    if (T[ia - 1] != 0.0) {
                      exitg1 = 1;
                    } else {
                      ia += 6;
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
              int32_T ix;
              f_st.site = &dp_emlrtRSI;
              g_st.site = &fp_emlrtRSI;
              if (lastc != 0) {
                h_st.site = &hp_emlrtRSI;
                if (0 <= lastc - 1) {
                  memset(&scale[0], 0, lastc * sizeof(real_T));
                }

                ix = jy;
                b_i = (in + 6 * lastv) + 1;
                for (j = ic0; j <= b_i; j += 6) {
                  knt = 0;
                  b = (j + lastc) - 1;
                  h_st.site = &gp_emlrtRSI;
                  for (ia = j; ia <= b; ia++) {
                    scale[knt] += T[ia - 1] * T[ix];
                    knt++;
                  }

                  ix++;
                }
              }

              f_st.site = &ep_emlrtRSI;
              g_st.site = &ip_emlrtRSI;
              h_st.site = &ie_emlrtRSI;
              i_st.site = &je_emlrtRSI;
              if (!(-tau[i] == 0.0)) {
                knt = in;
                j_st.site = &le_emlrtRSI;
                for (j = 0; j <= lastv; j++) {
                  if (T[jy] != 0.0) {
                    vleft = T[jy] * -tau[i];
                    ix = 0;
                    b_i = knt + 1;
                    b = lastc + knt;
                    j_st.site = &ke_emlrtRSI;
                    if ((knt + 1 <= b) && (b > 2147483646)) {
                      k_st.site = &jc_emlrtRSI;
                      check_forloop_overflow_error(&k_st);
                    }

                    for (ic0 = b_i; ic0 <= b; ic0++) {
                      T[ic0 - 1] += scale[ix] * vleft;
                      ix++;
                    }
                  }

                  jy++;
                  knt += 6;
                }
              }
            }

            e_st.site = &vo_emlrtRSI;
            internal::reflapack::b_xzlarf(&e_st, 5 - i, 5 - i, (i + im1n_tmp) +
              2, tau[i], T, (i + in) + 2, scale);
            T[alpha1_tmp] = vright;
          }

          c_st.site = &qo_emlrtRSI;
          d_st.site = &op_emlrtRSI;
          e_st.site = &pp_emlrtRSI;
          knt = internal::reflapack::eml_dlahqr(&e_st, T);
          b_i = 4;
          for (j = 0; j < 3; j++) {
            if (b_i <= 6) {
              memset(&T[(j * 6 + b_i) + -1], 0, (7 - b_i) * sizeof(real_T));
            }

            b_i++;
          }

          if (knt != 0) {
            c_st.site = &ro_emlrtRSI;
            internal::d_warning(&c_st);
          }
        }

        for (b_i = 0; b_i < 6; b_i++) {
          scale[b_i] = T[b_i + 6 * b_i];
        }

        for (i = 0; i < 6; i++) {
          V[i].re = scale[i];
          V[i].im = 0.0;
        }
      } else {
        ptrdiff_t info_t;
        st.site = &mo_emlrtRSI;
        b_st.site = &bt_emlrtRSI;
        c_st.site = &ct_emlrtRSI;
        memcpy(&T[0], &A[0], 36U * sizeof(real_T));
        info_t = LAPACKE_dgeevx(102, 'B', 'N', 'N', 'N', (ptrdiff_t)6, &T[0],
          (ptrdiff_t)6, &wreal[0], &wimag[0], &vleft, (ptrdiff_t)1, &vright,
          (ptrdiff_t)1, &ilo_t, &ihi_t, &scale[0], &abnrm, &rconde, &rcondv);
        knt = (int32_T)info_t;
        d_st.site = &dt_emlrtRSI;
        if (knt < 0) {
          if (knt == -1010) {
            emlrtErrorWithMessageIdR2018a(&d_st, &ac_emlrtRTEI, "MATLAB:nomem",
              "MATLAB:nomem", 0);
          } else {
            emlrtErrorWithMessageIdR2018a(&d_st, &yb_emlrtRTEI,
              "Coder:toolbox:LAPACKCallErrorInfo",
              "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, fname, 12, knt);
          }
        }

        for (i = 0; i < 6; i++) {
          V[i].re = wreal[i];
          V[i].im = wimag[i];
        }

        if (knt != 0) {
          b_st.site = &iq_emlrtRSI;
          internal::e_warning(&b_st);
        }
      }
    }
  }

  void eig(const emlrtStack *sp, const real_T A[9], creal_T V[3])
  {
    static const int32_T b_iv[2] = { 3, 3 };

    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack d_st;
    emlrtStack e_st;
    emlrtStack st;
    creal_T At[9];
    creal_T beta1[3];
    creal_T s;
    real_T dv[3];
    real_T absxk;
    int32_T rscale[3];
    int32_T i;
    int32_T ihi;
    int32_T info;
    boolean_T ilascl;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &ko_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    d_st.prev = &c_st;
    d_st.tls = c_st.tls;
    e_st.prev = &d_st;
    e_st.tls = d_st.tls;
    b_st.site = &gc_emlrtRSI;
    c_st.site = &hc_emlrtRSI;
    ilascl = internal::flatVectorAllOrAny(A, b_iv);
    if (!ilascl) {
      V[0].re = rtNaN;
      V[0].im = 0.0;
      V[1].re = rtNaN;
      V[1].im = 0.0;
      V[2].re = rtNaN;
      V[2].im = 0.0;
    } else {
      int32_T jcol;
      boolean_T exitg2;
      ilascl = true;
      jcol = 0;
      exitg2 = false;
      while ((!exitg2) && (jcol < 3)) {
        int32_T exitg1;
        i = 0;
        do {
          exitg1 = 0;
          if (i <= jcol) {
            if (!(A[i + 3 * jcol] == A[jcol + 3 * i])) {
              ilascl = false;
              exitg1 = 1;
            } else {
              i++;
            }
          } else {
            jcol++;
            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }

      if (ilascl) {
        st.site = &lo_emlrtRSI;
        eigHermitianStandard(&st, A, dv);
        V[0].re = dv[0];
        V[0].im = 0.0;
        V[1].re = dv[1];
        V[1].im = 0.0;
        V[2].re = dv[2];
        V[2].im = 0.0;
      } else {
        real_T anrm;
        real_T cfrom1;
        real_T ctoc;
        real_T re;
        st.site = &mo_emlrtRSI;
        b_st.site = &jq_emlrtRSI;
        for (i = 0; i < 9; i++) {
          At[i].re = A[i];
          At[i].im = 0.0;
        }

        c_st.site = &kq_emlrtRSI;
        info = 0;
        d_st.site = &lq_emlrtRSI;
        anrm = 0.0;
        jcol = 0;
        exitg2 = false;
        while ((!exitg2) && (jcol < 9)) {
          absxk = muDoubleScalarHypot(At[jcol].re, At[jcol].im);
          if (muDoubleScalarIsNaN(absxk)) {
            anrm = rtNaN;
            exitg2 = true;
          } else {
            if (absxk > anrm) {
              anrm = absxk;
            }

            jcol++;
          }
        }

        if (muDoubleScalarIsInf(anrm) || muDoubleScalarIsNaN(anrm)) {
          V[0].re = rtNaN;
          V[0].im = 0.0;
          beta1[0].re = rtNaN;
          beta1[0].im = 0.0;
          V[1].re = rtNaN;
          V[1].im = 0.0;
          beta1[1].re = rtNaN;
          beta1[1].im = 0.0;
          V[2].re = rtNaN;
          V[2].im = 0.0;
          beta1[2].re = rtNaN;
          beta1[2].im = 0.0;
        } else {
          real_T anrmto;
          real_T cto1;
          boolean_T guard1 = false;
          boolean_T notdone;
          ilascl = false;
          anrmto = anrm;
          guard1 = false;
          if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
            anrmto = 6.7178761075670888E-139;
            ilascl = true;
            guard1 = true;
          } else {
            if (anrm > 1.4885657073574029E+138) {
              anrmto = 1.4885657073574029E+138;
              ilascl = true;
              guard1 = true;
            }
          }

          if (guard1) {
            absxk = anrm;
            ctoc = anrmto;
            notdone = true;
            while (notdone) {
              cfrom1 = absxk * 2.0041683600089728E-292;
              cto1 = ctoc / 4.9896007738368E+291;
              if ((cfrom1 > ctoc) && (ctoc != 0.0)) {
                re = 2.0041683600089728E-292;
                absxk = cfrom1;
              } else if (cto1 > absxk) {
                re = 4.9896007738368E+291;
                ctoc = cto1;
              } else {
                re = ctoc / absxk;
                notdone = false;
              }

              for (i = 0; i < 9; i++) {
                At[i].re *= re;
                At[i].im *= re;
              }
            }
          }

          d_st.site = &mq_emlrtRSI;
          internal::reflapack::xzggbal(&d_st, At, &i, &ihi, rscale);
          d_st.site = &nq_emlrtRSI;
          if (ihi >= i + 2) {
            jcol = i;
            while (jcol < 2) {
              e_st.site = &xq_emlrtRSI;
              internal::reflapack::xzlartg(&e_st, At[1], At[2], &absxk, &s, &At
                [1]);
              At[2].re = 0.0;
              At[2].im = 0.0;
              ctoc = s.re * At[5].re - s.im * At[5].im;
              cto1 = s.re * At[5].im + s.im * At[5].re;
              At[5].re = absxk * At[5].re - (s.re * At[4].re + s.im * At[4].im);
              At[5].im = absxk * At[5].im - (s.re * At[4].im - s.im * At[4].re);
              At[4].re = absxk * At[4].re + ctoc;
              At[4].im = absxk * At[4].im + cto1;
              re = absxk * At[8].re - (s.re * At[7].re + s.im * At[7].im);
              cfrom1 = absxk * At[8].im - (s.re * At[7].im - s.im * At[7].re);
              At[7].re = absxk * At[7].re + (s.re * At[8].re - s.im * At[8].im);
              At[7].im = absxk * At[7].im + (s.re * At[8].im + s.im * At[8].re);
              s.re = -s.re;
              s.im = -s.im;
              ctoc = s.re * At[3].re - s.im * At[3].im;
              cto1 = s.re * At[3].im + s.im * At[3].re;
              At[3].re = absxk * At[3].re - (s.re * At[6].re + s.im * At[6].im);
              At[3].im = absxk * At[3].im - (s.re * At[6].im - s.im * At[6].re);
              At[6].re = absxk * At[6].re + ctoc;
              At[6].im = absxk * At[6].im + cto1;
              ctoc = s.re * At[4].re - s.im * At[4].im;
              cto1 = s.re * At[4].im + s.im * At[4].re;
              At[4].re = absxk * At[4].re - (s.re * At[7].re + s.im * At[7].im);
              At[4].im = absxk * At[4].im - (s.re * At[7].im - s.im * At[7].re);
              At[7].re = absxk * At[7].re + ctoc;
              At[7].im = absxk * At[7].im + cto1;
              ctoc = s.re * At[5].re - s.im * At[5].im;
              cto1 = s.re * At[5].im + s.im * At[5].re;
              At[5].re = absxk * At[5].re - (s.re * re + s.im * cfrom1);
              At[5].im = absxk * At[5].im - (s.re * cfrom1 - s.im * re);
              At[8].re = absxk * re + ctoc;
              At[8].im = absxk * cfrom1 + cto1;
              jcol = 2;
            }
          }

          d_st.site = &oq_emlrtRSI;
          internal::reflapack::xzhgeqz(&d_st, At, i, ihi, &info, V, beta1);
          if ((info == 0) && ilascl) {
            notdone = true;
            while (notdone) {
              cfrom1 = anrmto * 2.0041683600089728E-292;
              cto1 = anrm / 4.9896007738368E+291;
              if ((cfrom1 > anrm) && (anrm != 0.0)) {
                re = 2.0041683600089728E-292;
                anrmto = cfrom1;
              } else if (cto1 > anrmto) {
                re = 4.9896007738368E+291;
                anrm = cto1;
              } else {
                re = anrm / anrmto;
                notdone = false;
              }

              V[0].re *= re;
              V[0].im *= re;
              V[1].re *= re;
              V[1].im *= re;
              V[2].re *= re;
              V[2].im *= re;
            }
          }
        }

        if (beta1[0].im == 0.0) {
          if (V[0].im == 0.0) {
            re = V[0].re / beta1[0].re;
            cfrom1 = 0.0;
          } else if (V[0].re == 0.0) {
            re = 0.0;
            cfrom1 = V[0].im / beta1[0].re;
          } else {
            re = V[0].re / beta1[0].re;
            cfrom1 = V[0].im / beta1[0].re;
          }
        } else if (beta1[0].re == 0.0) {
          if (V[0].re == 0.0) {
            re = V[0].im / beta1[0].im;
            cfrom1 = 0.0;
          } else if (V[0].im == 0.0) {
            re = 0.0;
            cfrom1 = -(V[0].re / beta1[0].im);
          } else {
            re = V[0].im / beta1[0].im;
            cfrom1 = -(V[0].re / beta1[0].im);
          }
        } else {
          cfrom1 = muDoubleScalarAbs(beta1[0].re);
          absxk = muDoubleScalarAbs(beta1[0].im);
          if (cfrom1 > absxk) {
            absxk = beta1[0].im / beta1[0].re;
            ctoc = beta1[0].re + absxk * beta1[0].im;
            re = (V[0].re + absxk * V[0].im) / ctoc;
            cfrom1 = (V[0].im - absxk * V[0].re) / ctoc;
          } else if (absxk == cfrom1) {
            if (beta1[0].re > 0.0) {
              absxk = 0.5;
            } else {
              absxk = -0.5;
            }

            if (beta1[0].im > 0.0) {
              ctoc = 0.5;
            } else {
              ctoc = -0.5;
            }

            re = (V[0].re * absxk + V[0].im * ctoc) / cfrom1;
            cfrom1 = (V[0].im * absxk - V[0].re * ctoc) / cfrom1;
          } else {
            absxk = beta1[0].re / beta1[0].im;
            ctoc = beta1[0].im + absxk * beta1[0].re;
            re = (absxk * V[0].re + V[0].im) / ctoc;
            cfrom1 = (absxk * V[0].im - V[0].re) / ctoc;
          }
        }

        V[0].re = re;
        V[0].im = cfrom1;
        if (beta1[1].im == 0.0) {
          if (V[1].im == 0.0) {
            re = V[1].re / beta1[1].re;
            cfrom1 = 0.0;
          } else if (V[1].re == 0.0) {
            re = 0.0;
            cfrom1 = V[1].im / beta1[1].re;
          } else {
            re = V[1].re / beta1[1].re;
            cfrom1 = V[1].im / beta1[1].re;
          }
        } else if (beta1[1].re == 0.0) {
          if (V[1].re == 0.0) {
            re = V[1].im / beta1[1].im;
            cfrom1 = 0.0;
          } else if (V[1].im == 0.0) {
            re = 0.0;
            cfrom1 = -(V[1].re / beta1[1].im);
          } else {
            re = V[1].im / beta1[1].im;
            cfrom1 = -(V[1].re / beta1[1].im);
          }
        } else {
          cfrom1 = muDoubleScalarAbs(beta1[1].re);
          absxk = muDoubleScalarAbs(beta1[1].im);
          if (cfrom1 > absxk) {
            absxk = beta1[1].im / beta1[1].re;
            ctoc = beta1[1].re + absxk * beta1[1].im;
            re = (V[1].re + absxk * V[1].im) / ctoc;
            cfrom1 = (V[1].im - absxk * V[1].re) / ctoc;
          } else if (absxk == cfrom1) {
            if (beta1[1].re > 0.0) {
              absxk = 0.5;
            } else {
              absxk = -0.5;
            }

            if (beta1[1].im > 0.0) {
              ctoc = 0.5;
            } else {
              ctoc = -0.5;
            }

            re = (V[1].re * absxk + V[1].im * ctoc) / cfrom1;
            cfrom1 = (V[1].im * absxk - V[1].re * ctoc) / cfrom1;
          } else {
            absxk = beta1[1].re / beta1[1].im;
            ctoc = beta1[1].im + absxk * beta1[1].re;
            re = (absxk * V[1].re + V[1].im) / ctoc;
            cfrom1 = (absxk * V[1].im - V[1].re) / ctoc;
          }
        }

        V[1].re = re;
        V[1].im = cfrom1;
        if (beta1[2].im == 0.0) {
          if (V[2].im == 0.0) {
            re = V[2].re / beta1[2].re;
            cfrom1 = 0.0;
          } else if (V[2].re == 0.0) {
            re = 0.0;
            cfrom1 = V[2].im / beta1[2].re;
          } else {
            re = V[2].re / beta1[2].re;
            cfrom1 = V[2].im / beta1[2].re;
          }
        } else if (beta1[2].re == 0.0) {
          if (V[2].re == 0.0) {
            re = V[2].im / beta1[2].im;
            cfrom1 = 0.0;
          } else if (V[2].im == 0.0) {
            re = 0.0;
            cfrom1 = -(V[2].re / beta1[2].im);
          } else {
            re = V[2].im / beta1[2].im;
            cfrom1 = -(V[2].re / beta1[2].im);
          }
        } else {
          cfrom1 = muDoubleScalarAbs(beta1[2].re);
          absxk = muDoubleScalarAbs(beta1[2].im);
          if (cfrom1 > absxk) {
            absxk = beta1[2].im / beta1[2].re;
            ctoc = beta1[2].re + absxk * beta1[2].im;
            re = (V[2].re + absxk * V[2].im) / ctoc;
            cfrom1 = (V[2].im - absxk * V[2].re) / ctoc;
          } else if (absxk == cfrom1) {
            if (beta1[2].re > 0.0) {
              absxk = 0.5;
            } else {
              absxk = -0.5;
            }

            if (beta1[2].im > 0.0) {
              ctoc = 0.5;
            } else {
              ctoc = -0.5;
            }

            re = (V[2].re * absxk + V[2].im * ctoc) / cfrom1;
            cfrom1 = (V[2].im * absxk - V[2].re * ctoc) / cfrom1;
          } else {
            absxk = beta1[2].re / beta1[2].im;
            ctoc = beta1[2].im + absxk * beta1[2].re;
            re = (absxk * V[2].re + V[2].im) / ctoc;
            cfrom1 = (absxk * V[2].im - V[2].re) / ctoc;
          }
        }

        V[2].re = re;
        V[2].im = cfrom1;
        if (info != 0) {
          b_st.site = &iq_emlrtRSI;
          internal::e_warning(&b_st);
        }
      }
    }
  }
}

// End of code generation (eig.cpp)
