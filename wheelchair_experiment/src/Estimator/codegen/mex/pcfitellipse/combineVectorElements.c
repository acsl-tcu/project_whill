/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * combineVectorElements.c
 *
 * Code generation for function 'combineVectorElements'
 *
 */

/* Include files */
#include "combineVectorElements.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
int32_T combineVectorElements(const boolean_T x_data[], int32_T x_size)
{
  int32_T k;
  int32_T y;
  if (x_size == 0) {
    y = 0;
  } else {
    y = x_data[0];
    for (k = 2; k <= x_size; k++) {
      y += x_data[k - 1];
    }
  }
  return y;
}

/* End of code generation (combineVectorElements.c) */
