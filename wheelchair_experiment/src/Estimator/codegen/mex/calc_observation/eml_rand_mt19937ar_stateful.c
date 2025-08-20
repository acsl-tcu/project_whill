/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eml_rand_mt19937ar_stateful.c
 *
 * Code generation for function 'eml_rand_mt19937ar_stateful'
 *
 */

/* Include files */
#include "eml_rand_mt19937ar_stateful.h"
#include "calc_observation_data.h"
#include "eml_rand_mt19937ar.h"
#include "rt_nonfinite.h"
#include "omp.h"
#include <string.h>

/* Variable Definitions */
static uint32_T state[625];
#pragma omp threadprivate(state)

static boolean_T state_not_empty;
#pragma omp threadprivate(state_not_empty)

static uint32_T state_main[625];

static uint32_T (*state_ptr)[625];
#pragma omp threadprivate(state_ptr)

static emlrtRSInfo be_emlrtRSI = {
    23,                            /* lineNo */
    "eml_rand_mt19937ar_stateful", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/randfun/private/"
    "eml_rand_mt19937ar_stateful.m" /* pathName */
};

static emlrtRSInfo ce_emlrtRSI = {
    51,                   /* lineNo */
    "eml_rand_mt19937ar", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+randfun/"
    "eml_rand_mt19937ar.m" /* pathName */
};

static emlrtRTEInfo w_emlrtRTEI = {
    125,        /* lineNo */
    13,         /* colNo */
    "genrandu", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+randfun/"
    "eml_rand_mt19937ar.m" /* pName */
};

static emlrtRSInfo bm_emlrtRSI = {
    9,                             /* lineNo */
    "eml_rand_mt19937ar_stateful", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/randfun/private/"
    "eml_rand_mt19937ar_stateful.m" /* pathName */
};

/* Function Definitions */
void c_eml_rand_mt19937ar_stateful_i(const emlrtStack *sp)
{
  static uint32_T tmp[625];
  jmp_buf emlrtJBEnviron;
  jmp_buf *volatile emlrtJBStack;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T c_eml_rand_mt19937ar_stateful_i_numThreads;
  int32_T i;
  int32_T ub_loop;
  uint32_T u;
  boolean_T emlrtHadParallelError = false;
  b_st.prev = sp;
  b_st.tls = sp->tls;
  ub_loop = omp_get_max_threads();
  emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
  emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  c_eml_rand_mt19937ar_stateful_i_numThreads = emlrtAllocRegionTLSs(
      sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(                                              \
        c_eml_rand_mt19937ar_stateful_i_numThreads) private(emlrtJBEnviron,    \
                                                                c_st)          \
    firstprivate(st, emlrtHadParallelError)
  {
    if (setjmp(emlrtJBEnviron) == 0) {
      st.prev = sp;
      st.tls = emlrtAllocTLS((emlrtCTX)sp, omp_get_thread_num());
      st.site = NULL;
      emlrtSetJmpBuf(&st, &emlrtJBEnviron);
      c_st.prev = &st;
      c_st.tls = st.tls;
    } else {
      emlrtHadParallelError = true;
    }
#pragma omp for schedule(static)
    for (i = 1; i <= ub_loop; i++) {
      if (emlrtHadParallelError) {
        continue;
      }
      if (setjmp(emlrtJBEnviron) == 0) {
        state_not_empty = false;
        state_ptr = (uint32_T(*)[625])state;
        c_st.site = &bm_emlrtRSI;
        eml_rand_mt19937ar(&c_st, state);
        state_not_empty = true;
      } else {
        emlrtHadParallelError = true;
      }
    }
  }
  emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
  b_st.site = &bm_emlrtRSI;
  eml_rand_mt19937ar(&b_st, state_main);
  state_not_empty_main = true;
  for (i = 0; i < 625; i++) {
    u = state_main[i];
    tmp[i] = u;
    state_main[i] = state[i];
    state[i] = u;
  }
}

void c_eml_rand_mt19937ar_stateful_s(boolean_T aToMain)
{
  boolean_T state_not_empty_tmp;
  if (aToMain) {
    state_ptr = (uint32_T(*)[625])state_main;
  } else {
    state_ptr = (uint32_T(*)[625])state;
  }
  state_not_empty_tmp = state_not_empty;
  state_not_empty = state_not_empty_main;
  state_not_empty_main = state_not_empty_tmp;
}

real_T eml_rand_mt19937ar_stateful(const emlrtStack *sp)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T k;
  int32_T kk;
  uint32_T u[2];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  st.site = &be_emlrtRSI;
  b_st.site = &ce_emlrtRSI;
  /* ========================= COPYRIGHT NOTICE ============================ */
  /*  This is a uniform (0,1) pseudorandom number generator based on: */
  /*  */
  /*  A C-program for MT19937, with initialization improved 2002/1/26. */
  /*  Coded by Takuji Nishimura and Makoto Matsumoto. */
  /*  */
  /*  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura, */
  /*  All rights reserved. */
  /*  */
  /*  Redistribution and use in source and binary forms, with or without */
  /*  modification, are permitted provided that the following conditions */
  /*  are met: */
  /*  */
  /*    1. Redistributions of source code must retain the above copyright */
  /*       notice, this list of conditions and the following disclaimer. */
  /*  */
  /*    2. Redistributions in binary form must reproduce the above copyright */
  /*       notice, this list of conditions and the following disclaimer */
  /*       in the documentation and/or other materials provided with the */
  /*       distribution. */
  /*  */
  /*    3. The names of its contributors may not be used to endorse or */
  /*       promote products derived from this software without specific */
  /*       prior written permission. */
  /*  */
  /*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS */
  /*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT */
  /*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR */
  /*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT */
  /*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, */
  /*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT */
  /*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, */
  /*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY */
  /*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT */
  /*  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE */
  /*  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */
  /*  */
  /* =============================   END   ================================= */
  int32_T exitg1;
  do {
    exitg1 = 0;
    for (k = 0; k < 2; k++) {
      uint32_T mti;
      uint32_T y;
      mti = (*state_ptr)[624] + 1U;
      if (mti >= 625U) {
        for (kk = 0; kk < 227; kk++) {
          y = ((*state_ptr)[kk] & 2147483648U) |
              ((*state_ptr)[kk + 1] & 2147483647U);
          if ((y & 1U) == 0U) {
            y >>= 1U;
          } else {
            y = y >> 1U ^ 2567483615U;
          }
          (*state_ptr)[kk] = (*state_ptr)[kk + 397] ^ y;
        }
        for (kk = 0; kk < 396; kk++) {
          y = ((*state_ptr)[kk + 227] & 2147483648U) |
              ((*state_ptr)[kk + 228] & 2147483647U);
          if ((y & 1U) == 0U) {
            y >>= 1U;
          } else {
            y = y >> 1U ^ 2567483615U;
          }
          (*state_ptr)[kk + 227] = (*state_ptr)[kk] ^ y;
        }
        y = ((*state_ptr)[623] & 2147483648U) | ((*state_ptr)[0] & 2147483647U);
        if ((y & 1U) == 0U) {
          y >>= 1U;
        } else {
          y = y >> 1U ^ 2567483615U;
        }
        (*state_ptr)[623] = (*state_ptr)[396] ^ y;
        mti = 1U;
      }
      y = (*state_ptr)[(int32_T)mti - 1];
      (*state_ptr)[624] = mti;
      y ^= y >> 11U;
      y ^= y << 7U & 2636928640U;
      y ^= y << 15U & 4022730752U;
      u[k] = y ^ y >> 18U;
    }
    u[0] >>= 5U;
    u[1] >>= 6U;
    if ((u[0] == 0U) && (u[1] == 0U)) {
      boolean_T isvalid;
      if (((*state_ptr)[624] >= 1U) && ((*state_ptr)[624] < 625U)) {
        isvalid = true;
      } else {
        isvalid = false;
      }
      if (isvalid) {
        boolean_T exitg2;
        isvalid = false;
        k = 1;
        exitg2 = false;
        while ((!exitg2) && (k < 625)) {
          if ((*state_ptr)[k - 1] == 0U) {
            k++;
          } else {
            isvalid = true;
            exitg2 = true;
          }
        }
      }
      if (!isvalid) {
        emlrtErrorWithMessageIdR2018a(
            &b_st, &w_emlrtRTEI, "Coder:MATLAB:rand_invalidTwisterState",
            "Coder:MATLAB:rand_invalidTwisterState", 0);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return 1.1102230246251565E-16 * ((real_T)u[0] * 6.7108864E+7 + (real_T)u[1]);
}

/* End of code generation (eml_rand_mt19937ar_stateful.c) */
