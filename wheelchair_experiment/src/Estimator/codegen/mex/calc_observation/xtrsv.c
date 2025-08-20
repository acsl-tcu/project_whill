/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xtrsv.c
 *
 * Code generation for function 'xtrsv'
 *
 */

/* Include files */
#include "xtrsv.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void xtrsv(int32_T n, const real_T A[225], real_T x[120])
{
  int32_T i;
  int32_T j;
  if (n != 0) {
    for (j = n; j >= 1; j--) {
      int32_T jjA;
      jjA = (j + (j - 1) * 15) - 1;
      x[j - 1] /= A[jjA];
      for (i = 0; i <= j - 2; i++) {
        int32_T ix;
        ix = (j - i) - 2;
        x[ix] -= x[j - 1] * A[(jjA - i) - 1];
      }
    }
  }
}

/* End of code generation (xtrsv.c) */
