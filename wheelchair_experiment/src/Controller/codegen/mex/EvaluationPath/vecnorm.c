/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * vecnorm.c
 *
 * Code generation for function 'vecnorm'
 *
 */

/* Include files */
#include "vecnorm.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
int32_T vecnorm(const real_T x_data[], const int32_T x_size[2], real_T y_data[])
{
  int32_T j;
  int32_T y_size;
  y_size = x_size[0];
  if (y_size - 1 >= 0) {
    memset(&y_data[0], 0, (uint32_T)y_size * sizeof(real_T));
  }
  for (j = 0; j < y_size; j++) {
    real_T absxk;
    real_T scale;
    real_T t;
    real_T yv;
    scale = 3.3121686421112381E-170;
    absxk = muDoubleScalarAbs(x_data[j]);
    if (absxk > 3.3121686421112381E-170) {
      yv = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      yv = t * t;
    }
    absxk = muDoubleScalarAbs(x_data[j + y_size]);
    if (absxk > scale) {
      t = scale / absxk;
      yv = yv * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      yv += t * t;
    }
    y_data[j] = scale * muDoubleScalarSqrt(yv);
  }
  return y_size;
}

/* End of code generation (vecnorm.c) */
