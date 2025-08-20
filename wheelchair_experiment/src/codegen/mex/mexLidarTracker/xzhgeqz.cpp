//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  xzhgeqz.cpp
//
//  Code generation for function 'xzhgeqz'
//


// Include files
#include "xzhgeqz.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "xzlanhs.h"
#include "xzlartg.h"
#include "mwmathutil.h"
#include <string.h>

// Variable Definitions
static emlrtRSInfo fr_emlrtRSI = { 10, // lineNo
  "xzrot_rows",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzrot_rows.m"// pathName 
};

static emlrtRSInfo gr_emlrtRSI = { 10, // lineNo
  "xzrot_cols",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzrot_cols.m"// pathName 
};

static emlrtRSInfo hr_emlrtRSI = { 436,// lineNo
  "xzhgeqz",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzhgeqz.m"// pathName 
};

static emlrtRSInfo ir_emlrtRSI = { 424,// lineNo
  "xzhgeqz",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzhgeqz.m"// pathName 
};

static emlrtRSInfo jr_emlrtRSI = { 410,// lineNo
  "xzhgeqz",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzhgeqz.m"// pathName 
};

static emlrtRSInfo kr_emlrtRSI = { 401,// lineNo
  "xzhgeqz",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzhgeqz.m"// pathName 
};

static emlrtRSInfo lr_emlrtRSI = { 398,// lineNo
  "xzhgeqz",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzhgeqz.m"// pathName 
};

static emlrtRSInfo mr_emlrtRSI = { 391,// lineNo
  "xzhgeqz",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzhgeqz.m"// pathName 
};

static emlrtRSInfo nr_emlrtRSI = { 111,// lineNo
  "xzhgeqz",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzhgeqz.m"// pathName 
};

static emlrtRSInfo or_emlrtRSI = { 37, // lineNo
  "xzhgeqz",                           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+reflapack/xzhgeqz.m"// pathName 
};

// Function Definitions
namespace coder
{
  namespace internal
  {
    namespace reflapack
    {
      void xzhgeqz(const emlrtStack *sp, const creal_T A[9], int32_T ilo,
                   int32_T ihi, int32_T *info, creal_T alpha1[3], creal_T beta1
                   [3])
      {
        emlrtStack b_st;
        emlrtStack c_st;
        emlrtStack st;
        creal_T b_A[9];
        creal_T b_ascale;
        creal_T ctemp;
        creal_T shift;
        real_T anorm;
        real_T ascale;
        real_T b_atol;
        real_T eshift_im;
        real_T eshift_re;
        real_T temp;
        int32_T ilast;
        int32_T j;
        int32_T jp1;
        boolean_T failed;
        boolean_T guard1 = false;
        boolean_T guard2 = false;
        st.prev = sp;
        st.tls = sp->tls;
        b_st.prev = &st;
        b_st.tls = st.tls;
        c_st.prev = &b_st;
        c_st.tls = b_st.tls;
        memcpy(&b_A[0], &A[0], 9U * sizeof(creal_T));
        *info = 0;
        alpha1[0].re = 0.0;
        alpha1[0].im = 0.0;
        beta1[0].re = 1.0;
        beta1[0].im = 0.0;
        alpha1[1].re = 0.0;
        alpha1[1].im = 0.0;
        beta1[1].re = 1.0;
        beta1[1].im = 0.0;
        alpha1[2].re = 0.0;
        alpha1[2].im = 0.0;
        beta1[2].re = 1.0;
        beta1[2].im = 0.0;
        eshift_re = 0.0;
        eshift_im = 0.0;
        ctemp.re = 0.0;
        ctemp.im = 0.0;
        st.site = &or_emlrtRSI;
        anorm = xzlanhs(&st, A, ilo, ihi);
        temp = 2.2204460492503131E-16 * anorm;
        b_atol = 2.2250738585072014E-308;
        if (temp > 2.2250738585072014E-308) {
          b_atol = temp;
        }

        temp = 2.2250738585072014E-308;
        if (anorm > 2.2250738585072014E-308) {
          temp = anorm;
        }

        ascale = 1.0 / temp;
        failed = true;
        jp1 = ihi + 1;
        for (j = jp1; j < 4; j++) {
          alpha1[j - 1] = A[(j + 3 * (j - 1)) - 1];
        }

        guard1 = false;
        guard2 = false;
        if (ihi >= ilo) {
          int32_T ifirst;
          int32_T iiter;
          int32_T ilastm;
          int32_T ilastm1;
          int32_T istart;
          int32_T jiter;
          int32_T maxit;
          boolean_T goto60;
          boolean_T goto70;
          boolean_T goto90;
          ifirst = ilo;
          istart = ilo;
          ilast = ihi - 1;
          ilastm1 = ihi - 2;
          ilastm = ihi;
          iiter = 0;
          maxit = 30 * ((ihi - ilo) + 1);
          goto60 = false;
          goto70 = false;
          goto90 = false;
          st.site = &nr_emlrtRSI;
          if ((1 <= maxit) && (maxit > 2147483646)) {
            b_st.site = &jc_emlrtRSI;
            check_forloop_overflow_error(&b_st);
          }

          jiter = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (jiter <= maxit - 1) {
              boolean_T b_guard1 = false;
              boolean_T exitg2;
              b_guard1 = false;
              if (ilast + 1 == ilo) {
                goto60 = true;
                b_guard1 = true;
              } else {
                jp1 = ilast + 3 * ilastm1;
                if (muDoubleScalarAbs(b_A[jp1].re) + muDoubleScalarAbs(b_A[jp1].
                     im) <= b_atol) {
                  b_A[jp1].re = 0.0;
                  b_A[jp1].im = 0.0;
                  goto60 = true;
                  b_guard1 = true;
                } else {
                  boolean_T guard3 = false;
                  j = ilastm1;
                  guard3 = false;
                  exitg2 = false;
                  while ((!exitg2) && (j + 1 >= ilo)) {
                    if (j + 1 == ilo) {
                      guard3 = true;
                      exitg2 = true;
                    } else {
                      jp1 = j + 3 * (j - 1);
                      if (muDoubleScalarAbs(b_A[jp1].re) + muDoubleScalarAbs
                          (b_A[jp1].im) <= b_atol) {
                        b_A[jp1].re = 0.0;
                        b_A[jp1].im = 0.0;
                        guard3 = true;
                        exitg2 = true;
                      } else {
                        j--;
                        guard3 = false;
                      }
                    }
                  }

                  if (guard3) {
                    ifirst = j + 1;
                    goto70 = true;
                  }

                  if (goto70) {
                    b_guard1 = true;
                  } else {
                    alpha1[0].re = rtNaN;
                    alpha1[0].im = 0.0;
                    beta1[0].re = rtNaN;
                    beta1[0].im = 0.0;
                    alpha1[1].re = rtNaN;
                    alpha1[1].im = 0.0;
                    beta1[1].re = rtNaN;
                    beta1[1].im = 0.0;
                    alpha1[2].re = rtNaN;
                    alpha1[2].im = 0.0;
                    beta1[2].re = rtNaN;
                    beta1[2].im = 0.0;
                    *info = 1;
                    exitg1 = 1;
                  }
                }
              }

              if (b_guard1) {
                if (goto60) {
                  goto60 = false;
                  alpha1[ilast] = b_A[ilast + 3 * ilast];
                  ilast = ilastm1;
                  ilastm1--;
                  if (ilast + 1 < ilo) {
                    failed = false;
                    guard2 = true;
                    exitg1 = 1;
                  } else {
                    iiter = 0;
                    eshift_re = 0.0;
                    eshift_im = 0.0;
                    ilastm = ilast + 1;
                    jiter++;
                  }
                } else {
                  if (goto70) {
                    real_T ad22_im;
                    real_T ad22_re;
                    real_T tempr;
                    int32_T ctemp_tmp;
                    goto70 = false;
                    iiter++;
                    if (iiter - iiter / 10 * 10 != 0) {
                      real_T ai;
                      real_T ascale_im;
                      real_T ascale_re;
                      real_T b_ascale_re;
                      real_T t1_im;
                      real_T t1_im_tmp;
                      real_T t1_re;
                      jp1 = ilastm1 + 3 * ilastm1;
                      anorm = ascale * b_A[jp1].re;
                      temp = ascale * b_A[jp1].im;
                      jp1 = ilast + 3 * ilast;
                      tempr = ascale * b_A[jp1].re;
                      ai = ascale * b_A[jp1].im;
                      if (temp == 0.0) {
                        shift.re = anorm / 0.57735026918962584;
                        shift.im = 0.0;
                      } else if (anorm == 0.0) {
                        shift.re = 0.0;
                        shift.im = temp / 0.57735026918962584;
                      } else {
                        shift.re = anorm / 0.57735026918962584;
                        shift.im = temp / 0.57735026918962584;
                      }

                      if (ai == 0.0) {
                        ad22_re = tempr / 0.57735026918962584;
                        ad22_im = 0.0;
                      } else if (tempr == 0.0) {
                        ad22_re = 0.0;
                        ad22_im = ai / 0.57735026918962584;
                      } else {
                        ad22_re = tempr / 0.57735026918962584;
                        ad22_im = ai / 0.57735026918962584;
                      }

                      t1_re = 0.5 * (shift.re + ad22_re);
                      t1_im = 0.5 * (shift.im + ad22_im);
                      t1_im_tmp = t1_re * t1_im;
                      jp1 = ilastm1 + 3 * ilast;
                      anorm = ascale * b_A[jp1].re;
                      temp = ascale * b_A[jp1].im;
                      jp1 = ilast + 3 * ilastm1;
                      tempr = ascale * b_A[jp1].re;
                      ai = ascale * b_A[jp1].im;
                      if (temp == 0.0) {
                        ascale_re = anorm / 0.57735026918962584;
                        ascale_im = 0.0;
                      } else if (anorm == 0.0) {
                        ascale_re = 0.0;
                        ascale_im = temp / 0.57735026918962584;
                      } else {
                        ascale_re = anorm / 0.57735026918962584;
                        ascale_im = temp / 0.57735026918962584;
                      }

                      if (ai == 0.0) {
                        b_ascale_re = tempr / 0.57735026918962584;
                        anorm = 0.0;
                      } else if (tempr == 0.0) {
                        b_ascale_re = 0.0;
                        anorm = ai / 0.57735026918962584;
                      } else {
                        b_ascale_re = tempr / 0.57735026918962584;
                        anorm = ai / 0.57735026918962584;
                      }

                      temp = shift.re * ad22_re - shift.im * ad22_im;
                      tempr = shift.re * ad22_im + shift.im * ad22_re;
                      shift.re = ((t1_re * t1_re - t1_im * t1_im) + (ascale_re *
                        b_ascale_re - ascale_im * anorm)) - temp;
                      shift.im = ((t1_im_tmp + t1_im_tmp) + (ascale_re * anorm +
                        ascale_im * b_ascale_re)) - tempr;
                      b_sqrt(&shift);
                      if ((t1_re - ad22_re) * shift.re + (t1_im - ad22_im) *
                          shift.im <= 0.0) {
                        shift.re += t1_re;
                        shift.im += t1_im;
                      } else {
                        shift.re = t1_re - shift.re;
                        shift.im = t1_im - shift.im;
                      }
                    } else {
                      real_T ascale_im;
                      real_T ascale_re;
                      jp1 = ilast + 3 * ilastm1;
                      anorm = ascale * b_A[jp1].re;
                      temp = ascale * b_A[jp1].im;
                      if (temp == 0.0) {
                        ascale_re = anorm / 0.57735026918962584;
                        ascale_im = 0.0;
                      } else if (anorm == 0.0) {
                        ascale_re = 0.0;
                        ascale_im = temp / 0.57735026918962584;
                      } else {
                        ascale_re = anorm / 0.57735026918962584;
                        ascale_im = temp / 0.57735026918962584;
                      }

                      eshift_re += ascale_re;
                      eshift_im += ascale_im;
                      shift.re = eshift_re;
                      shift.im = eshift_im;
                    }

                    j = ilastm1;
                    jp1 = ilastm1 + 1;
                    exitg2 = false;
                    while ((!exitg2) && (j + 1 > ifirst)) {
                      istart = j + 1;
                      ctemp_tmp = j + 3 * j;
                      ctemp.re = ascale * b_A[ctemp_tmp].re - shift.re *
                        0.57735026918962584;
                      ctemp.im = ascale * b_A[ctemp_tmp].im - shift.im *
                        0.57735026918962584;
                      temp = muDoubleScalarAbs(ctemp.re) + muDoubleScalarAbs
                        (ctemp.im);
                      jp1 += 3 * j;
                      anorm = ascale * (muDoubleScalarAbs(b_A[jp1].re) +
                                        muDoubleScalarAbs(b_A[jp1].im));
                      tempr = temp;
                      if (anorm > temp) {
                        tempr = anorm;
                      }

                      if ((tempr < 1.0) && (tempr != 0.0)) {
                        temp /= tempr;
                        anorm /= tempr;
                      }

                      jp1 = j + 3 * (j - 1);
                      if ((muDoubleScalarAbs(b_A[jp1].re) + muDoubleScalarAbs
                           (b_A[jp1].im)) * anorm <= temp * b_atol) {
                        goto90 = true;
                        exitg2 = true;
                      } else {
                        jp1 = j;
                        j--;
                      }
                    }

                    if (!goto90) {
                      istart = ifirst;
                      ctemp_tmp = (ifirst + 3 * (ifirst - 1)) - 1;
                      ctemp.re = ascale * b_A[ctemp_tmp].re - shift.re *
                        0.57735026918962584;
                      ctemp.im = ascale * b_A[ctemp_tmp].im - shift.im *
                        0.57735026918962584;
                    }

                    goto90 = false;
                    jp1 = istart + 3 * (istart - 1);
                    b_ascale.re = ascale * b_A[jp1].re;
                    b_ascale.im = ascale * b_A[jp1].im;
                    st.site = &mr_emlrtRSI;
                    xzlartg(&st, ctemp, b_ascale, &anorm, &shift);
                    j = istart;
                    jp1 = istart - 2;
                    while (j < ilast + 1) {
                      int32_T shift_re_tmp;
                      if (j > istart) {
                        ctemp_tmp = j + 3 * jp1;
                        st.site = &lr_emlrtRSI;
                        xzlartg(&st, b_A[3 * jp1 + 1], b_A[ctemp_tmp], &anorm,
                                &shift, &b_A[3 * jp1 + 1]);
                        b_A[ctemp_tmp].re = 0.0;
                        b_A[ctemp_tmp].im = 0.0;
                      }

                      st.site = &kr_emlrtRSI;
                      b_st.site = &fr_emlrtRSI;
                      if ((j <= ilastm) && (ilastm > 2147483646)) {
                        c_st.site = &jc_emlrtRSI;
                        check_forloop_overflow_error(&c_st);
                      }

                      for (jp1 = j; jp1 <= ilastm; jp1++) {
                        shift_re_tmp = j + 3 * (jp1 - 1);
                        ad22_re = anorm * b_A[shift_re_tmp - 1].re + (shift.re *
                          b_A[shift_re_tmp].re - shift.im * b_A[shift_re_tmp].im);
                        ad22_im = anorm * b_A[shift_re_tmp - 1].im + (shift.re *
                          b_A[shift_re_tmp].im + shift.im * b_A[shift_re_tmp].re);
                        temp = b_A[shift_re_tmp - 1].re;
                        b_A[shift_re_tmp].re = anorm * b_A[shift_re_tmp].re -
                          (shift.re * b_A[shift_re_tmp - 1].re + shift.im *
                           b_A[shift_re_tmp - 1].im);
                        b_A[shift_re_tmp].im = anorm * b_A[shift_re_tmp].im -
                          (shift.re * b_A[shift_re_tmp - 1].im - shift.im * temp);
                        b_A[shift_re_tmp - 1].re = ad22_re;
                        b_A[shift_re_tmp - 1].im = ad22_im;
                      }

                      shift.re = -shift.re;
                      shift.im = -shift.im;
                      jp1 = j + 2;
                      if (ilast + 1 < j + 2) {
                        jp1 = ilast + 1;
                      }

                      st.site = &jr_emlrtRSI;
                      b_st.site = &gr_emlrtRSI;
                      if ((ifirst <= jp1) && (jp1 > 2147483646)) {
                        c_st.site = &jc_emlrtRSI;
                        check_forloop_overflow_error(&c_st);
                      }

                      for (int32_T i = ifirst; i <= jp1; i++) {
                        shift_re_tmp = (i + 3 * (j - 1)) - 1;
                        ctemp_tmp = (i + 3 * j) - 1;
                        ad22_re = anorm * b_A[ctemp_tmp].re + (shift.re *
                          b_A[shift_re_tmp].re - shift.im * b_A[shift_re_tmp].im);
                        ad22_im = anorm * b_A[ctemp_tmp].im + (shift.re *
                          b_A[shift_re_tmp].im + shift.im * b_A[shift_re_tmp].re);
                        temp = b_A[ctemp_tmp].re;
                        b_A[shift_re_tmp].re = anorm * b_A[shift_re_tmp].re -
                          (shift.re * b_A[ctemp_tmp].re + shift.im *
                           b_A[ctemp_tmp].im);
                        b_A[shift_re_tmp].im = anorm * b_A[shift_re_tmp].im -
                          (shift.re * b_A[ctemp_tmp].im - shift.im * temp);
                        b_A[ctemp_tmp].re = ad22_re;
                        b_A[ctemp_tmp].im = ad22_im;
                      }

                      jp1 = j - 1;
                      j++;
                    }
                  }

                  jiter++;
                }
              }
            } else {
              guard2 = true;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        } else {
          guard1 = true;
        }

        if (guard2) {
          if (failed) {
            *info = ilast + 1;
            st.site = &ir_emlrtRSI;
            if ((1 <= ilast + 1) && (ilast + 1 > 2147483646)) {
              b_st.site = &jc_emlrtRSI;
              check_forloop_overflow_error(&b_st);
            }

            for (jp1 = 0; jp1 <= ilast; jp1++) {
              alpha1[jp1].re = rtNaN;
              alpha1[jp1].im = 0.0;
              beta1[jp1].re = rtNaN;
              beta1[jp1].im = 0.0;
            }
          } else {
            guard1 = true;
          }
        }

        if (guard1) {
          st.site = &hr_emlrtRSI;
          if ((1 <= ilo - 1) && (ilo - 1 > 2147483646)) {
            b_st.site = &jc_emlrtRSI;
            check_forloop_overflow_error(&b_st);
          }

          for (j = 0; j <= ilo - 2; j++) {
            alpha1[j] = b_A[j + 3 * j];
          }
        }
      }
    }
  }
}

// End of code generation (xzhgeqz.cpp)
