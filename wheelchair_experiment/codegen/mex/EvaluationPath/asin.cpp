//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  asin.cpp
//
//  Code generation for function 'asin'
//


// Include files
#include "asin.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "mwmathutil.h"

// Function Definitions
namespace coder
{
  void b_asin(creal_T *x)
  {
    creal_T u;
    creal_T v;
    real_T ci;
    if ((x->im == 0.0) && (!(muDoubleScalarAbs(x->re) > 1.0))) {
      x->re = muDoubleScalarAsin(x->re);
      x->im = 0.0;
    } else {
      real_T absim;
      real_T absre;
      real_T b_absre;
      real_T sai;
      real_T sar;
      real_T sbi;
      real_T sbr;
      real_T t1;
      real_T t2;
      real_T tmp;
      boolean_T xneg;
      v.re = x->re + 1.0;
      v.im = x->im;
      internal::scalar::b_sqrt(&v);
      u.re = 1.0 - x->re;
      u.im = 0.0 - x->im;
      internal::scalar::b_sqrt(&u);
      if ((u.im == 0.0) && (v.im == 0.0)) {
        tmp = u.re * v.re;
      } else {
        t1 = u.re * v.re;
        t2 = u.im * v.im;
        tmp = t1 - t2;
        if ((muDoubleScalarIsInf(tmp) || muDoubleScalarIsNaN(tmp)) &&
            (!muDoubleScalarIsNaN(u.re)) && (!muDoubleScalarIsNaN(u.im)) &&
            (!muDoubleScalarIsNaN(v.re)) && (!muDoubleScalarIsNaN(v.im))) {
          absre = muDoubleScalarAbs(u.re);
          absim = muDoubleScalarAbs(u.im);
          if (absre > absim) {
            if (u.re < 0.0) {
              sar = -1.0;
            } else {
              sar = 1.0;
            }

            sai = u.im / absre;
          } else if (absim > absre) {
            sar = u.re / absim;
            if (u.im < 0.0) {
              sai = -1.0;
            } else {
              sai = 1.0;
            }

            absre = absim;
          } else {
            if (u.re < 0.0) {
              sar = -1.0;
            } else {
              sar = 1.0;
            }

            if (u.im < 0.0) {
              sai = -1.0;
            } else {
              sai = 1.0;
            }
          }

          b_absre = muDoubleScalarAbs(v.re);
          absim = muDoubleScalarAbs(v.im);
          if (b_absre > absim) {
            if (v.re < 0.0) {
              sbr = -1.0;
            } else {
              sbr = 1.0;
            }

            sbi = v.im / b_absre;
          } else if (absim > b_absre) {
            sbr = v.re / absim;
            if (v.im < 0.0) {
              sbi = -1.0;
            } else {
              sbi = 1.0;
            }

            b_absre = absim;
          } else {
            if (v.re < 0.0) {
              sbr = -1.0;
            } else {
              sbr = 1.0;
            }

            if (v.im < 0.0) {
              sbi = -1.0;
            } else {
              sbi = 1.0;
            }
          }

          if ((!muDoubleScalarIsInf(absre)) && (!muDoubleScalarIsNaN(absre)) &&
              ((!muDoubleScalarIsInf(b_absre)) && (!muDoubleScalarIsNaN(b_absre))))
          {
            xneg = true;
          } else {
            xneg = false;
          }

          if (muDoubleScalarIsNaN(tmp) || (muDoubleScalarIsInf(tmp) && xneg)) {
            tmp = sar * sbr - sai * sbi;
            if (tmp != 0.0) {
              tmp = tmp * absre * b_absre;
            } else {
              if ((muDoubleScalarIsInf(absre) && ((v.re == 0.0) || (v.im == 0.0)))
                  || (muDoubleScalarIsInf(b_absre) && ((u.re == 0.0) || (u.im ==
                     0.0)))) {
                if (muDoubleScalarIsNaN(t1)) {
                  t1 = 0.0;
                }

                if (muDoubleScalarIsNaN(t2)) {
                  t2 = 0.0;
                }

                tmp = t1 - t2;
              }
            }
          }
        }
      }

      if ((-u.im == 0.0) && (v.im == 0.0)) {
        ci = 0.0;
      } else {
        t1 = u.re * v.im;
        t2 = -u.im * v.re;
        ci = t1 + t2;
        if ((muDoubleScalarIsInf(ci) || muDoubleScalarIsNaN(ci)) &&
            (!muDoubleScalarIsNaN(u.re)) && (!muDoubleScalarIsNaN(-u.im)) &&
            (!muDoubleScalarIsNaN(v.re)) && (!muDoubleScalarIsNaN(v.im))) {
          absre = muDoubleScalarAbs(u.re);
          absim = muDoubleScalarAbs(-u.im);
          if (absre > absim) {
            if (u.re < 0.0) {
              sar = -1.0;
            } else {
              sar = 1.0;
            }

            sai = -u.im / absre;
          } else if (absim > absre) {
            sar = u.re / absim;
            if (-u.im < 0.0) {
              sai = -1.0;
            } else {
              sai = 1.0;
            }

            absre = absim;
          } else {
            if (u.re < 0.0) {
              sar = -1.0;
            } else {
              sar = 1.0;
            }

            if (-u.im < 0.0) {
              sai = -1.0;
            } else {
              sai = 1.0;
            }
          }

          b_absre = muDoubleScalarAbs(v.re);
          absim = muDoubleScalarAbs(v.im);
          if (b_absre > absim) {
            if (v.re < 0.0) {
              sbr = -1.0;
            } else {
              sbr = 1.0;
            }

            sbi = v.im / b_absre;
          } else if (absim > b_absre) {
            sbr = v.re / absim;
            if (v.im < 0.0) {
              sbi = -1.0;
            } else {
              sbi = 1.0;
            }

            b_absre = absim;
          } else {
            if (v.re < 0.0) {
              sbr = -1.0;
            } else {
              sbr = 1.0;
            }

            if (v.im < 0.0) {
              sbi = -1.0;
            } else {
              sbi = 1.0;
            }
          }

          if ((!muDoubleScalarIsInf(absre)) && (!muDoubleScalarIsNaN(absre)) &&
              ((!muDoubleScalarIsInf(b_absre)) && (!muDoubleScalarIsNaN(b_absre))))
          {
            xneg = true;
          } else {
            xneg = false;
          }

          if (muDoubleScalarIsNaN(ci) || (muDoubleScalarIsInf(ci) && xneg)) {
            ci = sar * sbi + sai * sbr;
            if (ci != 0.0) {
              ci = ci * absre * b_absre;
            } else {
              if ((muDoubleScalarIsInf(absre) && ((v.re == 0.0) || (v.im == 0.0)))
                  || (muDoubleScalarIsInf(b_absre) && ((u.re == 0.0) || (-u.im ==
                     0.0)))) {
                if (muDoubleScalarIsNaN(t1)) {
                  t1 = 0.0;
                }

                if (muDoubleScalarIsNaN(t2)) {
                  t2 = 0.0;
                }

                ci = t1 + t2;
              }
            }
          }
        }
      }

      xneg = (ci < 0.0);
      if (xneg) {
        ci = -ci;
      }

      if (ci >= 2.68435456E+8) {
        ci = muDoubleScalarLog(ci) + 0.69314718055994529;
      } else if (ci > 2.0) {
        ci = muDoubleScalarLog(2.0 * ci + 1.0 / (muDoubleScalarSqrt(ci * ci +
          1.0) + ci));
      } else {
        t1 = ci * ci;
        ci += t1 / (muDoubleScalarSqrt(t1 + 1.0) + 1.0);
        t1 = muDoubleScalarAbs(ci);
        if ((t1 > 4.503599627370496E+15) || (muDoubleScalarIsInf(ci) ||
             muDoubleScalarIsNaN(ci))) {
          ci++;
          ci = muDoubleScalarLog(ci);
        } else {
          if (!(t1 < 2.2204460492503131E-16)) {
            ci = muDoubleScalarLog(ci + 1.0) * (ci / ((ci + 1.0) - 1.0));
          }
        }
      }

      if (xneg) {
        ci = -ci;
      }

      x->re = muDoubleScalarAtan2(x->re, tmp);
      x->im = ci;
    }
  }
}

// End of code generation (asin.cpp)
