//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  xzlartg.cpp
//
//  Code generation for function 'xzlartg'
//


// Include files
#include "xzlartg.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo br_emlrtRSI = { 67, // lineNo
  "xzlartg",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlartg.m"// pathName 
};

static emlrtRSInfo cr_emlrtRSI = { 93, // lineNo
  "xzlartg",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlartg.m"// pathName 
};

static emlrtRSInfo dr_emlrtRSI = { 102,// lineNo
  "xzlartg",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlartg.m"// pathName 
};

static emlrtRSInfo er_emlrtRSI = { 106,// lineNo
  "xzlartg",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlartg.m"// pathName 
};

// Function Definitions
namespace coder
{
  namespace internal
  {
    namespace reflapack
    {
      void xzlartg(const emlrtStack *sp, const creal_T f, const creal_T g,
                   real_T *cs, creal_T *sn)
      {
        emlrtStack b_st;
        emlrtStack st;
        real_T f2;
        real_T fs_im;
        real_T fs_re;
        real_T g2;
        real_T gs_im;
        real_T gs_re;
        real_T scale;
        real_T scale_tmp;
        int32_T count;
        int32_T rescaledir;
        boolean_T guard1 = false;
        st.prev = sp;
        st.tls = sp->tls;
        b_st.prev = &st;
        b_st.tls = st.tls;
        scale_tmp = muDoubleScalarAbs(f.re);
        f2 = muDoubleScalarAbs(f.im);
        if (f2 > scale_tmp) {
          scale_tmp = f2;
        }

        f2 = muDoubleScalarAbs(g.re);
        scale = muDoubleScalarAbs(g.im);
        if (scale > f2) {
          f2 = scale;
        }

        scale = scale_tmp;
        if (f2 > scale_tmp) {
          scale = f2;
        }

        fs_re = f.re;
        fs_im = f.im;
        gs_re = g.re;
        gs_im = g.im;
        count = 0;
        rescaledir = 0;
        guard1 = false;
        if (scale >= 7.4428285367870146E+137) {
          do {
            count++;
            fs_re *= 1.3435752215134178E-138;
            fs_im *= 1.3435752215134178E-138;
            gs_re *= 1.3435752215134178E-138;
            gs_im *= 1.3435752215134178E-138;
            scale *= 1.3435752215134178E-138;
          } while (!(scale < 7.4428285367870146E+137));

          rescaledir = 1;
          guard1 = true;
        } else if (scale <= 1.3435752215134178E-138) {
          if ((g.re == 0.0) && (g.im == 0.0)) {
            *cs = 1.0;
            sn->re = 0.0;
            sn->im = 0.0;
          } else {
            do {
              count++;
              fs_re *= 7.4428285367870146E+137;
              fs_im *= 7.4428285367870146E+137;
              gs_re *= 7.4428285367870146E+137;
              gs_im *= 7.4428285367870146E+137;
              scale *= 7.4428285367870146E+137;
            } while (!(scale > 1.3435752215134178E-138));

            rescaledir = -1;
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          f2 = fs_re * fs_re + fs_im * fs_im;
          g2 = gs_re * gs_re + gs_im * gs_im;
          scale = g2;
          if (1.0 > g2) {
            scale = 1.0;
          }

          if (f2 <= scale * 2.0041683600089728E-292) {
            if ((f.re == 0.0) && (f.im == 0.0)) {
              *cs = 0.0;
              g2 = muDoubleScalarHypot(gs_re, gs_im);
              sn->re = gs_re / g2;
              sn->im = -gs_im / g2;
            } else {
              real_T g2s;
              st.site = &br_emlrtRSI;
              if (g2 < 0.0) {
                emlrtErrorWithMessageIdR2018a(&st, &ob_emlrtRTEI,
                  "Coder:toolbox:ElFunDomainError",
                  "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
              }

              g2s = muDoubleScalarSqrt(g2);
              *cs = muDoubleScalarHypot(fs_re, fs_im) / g2s;
              if (scale_tmp > 1.0) {
                g2 = muDoubleScalarHypot(f.re, f.im);
                fs_re = f.re / g2;
                fs_im = f.im / g2;
              } else {
                f2 = 7.4428285367870146E+137 * f.re;
                scale = 7.4428285367870146E+137 * f.im;
                g2 = muDoubleScalarHypot(f2, scale);
                fs_re = f2 / g2;
                fs_im = scale / g2;
              }

              gs_re /= g2s;
              gs_im = -gs_im / g2s;
              sn->re = fs_re * gs_re - fs_im * gs_im;
              sn->im = fs_re * gs_im + fs_im * gs_re;
            }
          } else {
            st.site = &cr_emlrtRSI;
            scale = g2 / f2 + 1.0;
            if (scale < 0.0) {
              emlrtErrorWithMessageIdR2018a(&st, &ob_emlrtRTEI,
                "Coder:toolbox:ElFunDomainError",
                "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
            }

            scale = muDoubleScalarSqrt(scale);
            *cs = 1.0 / scale;
            g2 += f2;
            fs_re = scale * fs_re / g2;
            fs_im = scale * fs_im / g2;
            sn->re = fs_re * gs_re - fs_im * -gs_im;
            sn->im = fs_re * -gs_im + fs_im * gs_re;
            if (rescaledir > 0) {
              st.site = &dr_emlrtRSI;
              if ((1 <= count) && (count > 2147483646)) {
                b_st.site = &jc_emlrtRSI;
                check_forloop_overflow_error(&b_st);
              }
            } else {
              if (rescaledir < 0) {
                st.site = &er_emlrtRSI;
                if ((1 <= count) && (count > 2147483646)) {
                  b_st.site = &jc_emlrtRSI;
                  check_forloop_overflow_error(&b_st);
                }
              }
            }
          }
        }
      }

      void xzlartg(const emlrtStack *sp, const creal_T f, const creal_T g,
                   real_T *cs, creal_T *sn, creal_T *r)
      {
        emlrtStack b_st;
        emlrtStack st;
        real_T f2;
        real_T f2s;
        real_T fs_im;
        real_T fs_re;
        real_T gs_im;
        real_T gs_re;
        real_T scale;
        real_T scale_tmp;
        int32_T count;
        int32_T rescaledir;
        boolean_T guard1 = false;
        st.prev = sp;
        st.tls = sp->tls;
        b_st.prev = &st;
        b_st.tls = st.tls;
        scale_tmp = muDoubleScalarAbs(f.re);
        f2s = muDoubleScalarAbs(f.im);
        if (f2s > scale_tmp) {
          scale_tmp = f2s;
        }

        f2s = muDoubleScalarAbs(g.re);
        scale = muDoubleScalarAbs(g.im);
        if (scale > f2s) {
          f2s = scale;
        }

        scale = scale_tmp;
        if (f2s > scale_tmp) {
          scale = f2s;
        }

        fs_re = f.re;
        fs_im = f.im;
        gs_re = g.re;
        gs_im = g.im;
        count = 0;
        rescaledir = 0;
        guard1 = false;
        if (scale >= 7.4428285367870146E+137) {
          do {
            count++;
            fs_re *= 1.3435752215134178E-138;
            fs_im *= 1.3435752215134178E-138;
            gs_re *= 1.3435752215134178E-138;
            gs_im *= 1.3435752215134178E-138;
            scale *= 1.3435752215134178E-138;
          } while (!(scale < 7.4428285367870146E+137));

          rescaledir = 1;
          guard1 = true;
        } else if (scale <= 1.3435752215134178E-138) {
          if ((g.re == 0.0) && (g.im == 0.0)) {
            *cs = 1.0;
            sn->re = 0.0;
            sn->im = 0.0;
            *r = f;
          } else {
            do {
              count++;
              fs_re *= 7.4428285367870146E+137;
              fs_im *= 7.4428285367870146E+137;
              gs_re *= 7.4428285367870146E+137;
              gs_im *= 7.4428285367870146E+137;
              scale *= 7.4428285367870146E+137;
            } while (!(scale > 1.3435752215134178E-138));

            rescaledir = -1;
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          real_T g2;
          f2 = fs_re * fs_re + fs_im * fs_im;
          g2 = gs_re * gs_re + gs_im * gs_im;
          scale = g2;
          if (1.0 > g2) {
            scale = 1.0;
          }

          if (f2 <= scale * 2.0041683600089728E-292) {
            if ((f.re == 0.0) && (f.im == 0.0)) {
              *cs = 0.0;
              r->re = muDoubleScalarHypot(g.re, g.im);
              r->im = 0.0;
              f2 = muDoubleScalarHypot(gs_re, gs_im);
              sn->re = gs_re / f2;
              sn->im = -gs_im / f2;
            } else {
              st.site = &br_emlrtRSI;
              if (g2 < 0.0) {
                emlrtErrorWithMessageIdR2018a(&st, &ob_emlrtRTEI,
                  "Coder:toolbox:ElFunDomainError",
                  "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
              }

              g2 = muDoubleScalarSqrt(g2);
              *cs = muDoubleScalarHypot(fs_re, fs_im) / g2;
              if (scale_tmp > 1.0) {
                f2 = muDoubleScalarHypot(f.re, f.im);
                fs_re = f.re / f2;
                fs_im = f.im / f2;
              } else {
                scale = 7.4428285367870146E+137 * f.re;
                f2s = 7.4428285367870146E+137 * f.im;
                f2 = muDoubleScalarHypot(scale, f2s);
                fs_re = scale / f2;
                fs_im = f2s / f2;
              }

              gs_re /= g2;
              gs_im = -gs_im / g2;
              sn->re = fs_re * gs_re - fs_im * gs_im;
              sn->im = fs_re * gs_im + fs_im * gs_re;
              r->re = *cs * f.re + (sn->re * g.re - sn->im * g.im);
              r->im = *cs * f.im + (sn->re * g.im + sn->im * g.re);
            }
          } else {
            st.site = &cr_emlrtRSI;
            f2s = g2 / f2 + 1.0;
            if (f2s < 0.0) {
              emlrtErrorWithMessageIdR2018a(&st, &ob_emlrtRTEI,
                "Coder:toolbox:ElFunDomainError",
                "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
            }

            f2s = muDoubleScalarSqrt(f2s);
            r->re = f2s * fs_re;
            r->im = f2s * fs_im;
            *cs = 1.0 / f2s;
            f2 += g2;
            f2s = r->re / f2;
            scale = r->im / f2;
            sn->re = f2s * gs_re - scale * -gs_im;
            sn->im = f2s * -gs_im + scale * gs_re;
            if (rescaledir > 0) {
              st.site = &dr_emlrtRSI;
              if ((1 <= count) && (count > 2147483646)) {
                b_st.site = &jc_emlrtRSI;
                check_forloop_overflow_error(&b_st);
              }

              for (rescaledir = 0; rescaledir < count; rescaledir++) {
                r->re *= 7.4428285367870146E+137;
                r->im *= 7.4428285367870146E+137;
              }
            } else {
              if (rescaledir < 0) {
                st.site = &er_emlrtRSI;
                if ((1 <= count) && (count > 2147483646)) {
                  b_st.site = &jc_emlrtRSI;
                  check_forloop_overflow_error(&b_st);
                }

                for (rescaledir = 0; rescaledir < count; rescaledir++) {
                  r->re *= 1.3435752215134178E-138;
                  r->im *= 1.3435752215134178E-138;
                }
              }
            }
          }
        }
      }
    }
  }
}

// End of code generation (xzlartg.cpp)
