/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eml_rand_mt19937ar.c
 *
 * Code generation for function 'eml_rand_mt19937ar'
 *
 */

/* Include files */
#include "eml_rand_mt19937ar.h"
#include "calc_observation.h"
#include "rt_nonfinite.h"
#include "omp.h"
#include <string.h>

/* Function Definitions */
void eml_rand_mt19937ar(const emlrtStack *sp, uint32_T b_state[625])
{
  int32_T mti;
  if (emlrtIsInParallelRegion((emlrtCTX)sp)) {
    uint32_T r;
    mti = getThreadID();
    if (mti > 2147483646) {
      mti = MAX_int32_T;
    } else {
      mti++;
    }
    if (mti < 0) {
      mti = 0;
    }
    r = (uint32_T)mti;
    b_state[0] = (uint32_T)mti;
    for (mti = 0; mti < 623; mti++) {
      r = ((r ^ r >> 30U) * 1812433253U + (uint32_T)mti) + 1U;
      b_state[mti + 1] = r;
    }
    b_state[624] = 624U;
  } else {
    uint32_T r;
    r = 5489U;
    b_state[0] = 5489U;
    for (mti = 0; mti < 623; mti++) {
      r = ((r ^ r >> 30U) * 1812433253U + (uint32_T)mti) + 1U;
      b_state[mti + 1] = r;
    }
    b_state[624] = 624U;
  }
}

/* End of code generation (eml_rand_mt19937ar.c) */
