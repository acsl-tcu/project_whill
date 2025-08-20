/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eml_rand.c
 *
 * Code generation for function 'eml_rand'
 *
 */

/* Include files */
#include "eml_rand.h"
#include "calc_observation_data.h"
#include "eml_rand_mt19937ar_stateful.h"
#include "rt_nonfinite.h"
#include "omp.h"
#include <string.h>

/* Variable Definitions */
static uint32_T method;
#pragma omp threadprivate(method)

static boolean_T method_not_empty;
#pragma omp threadprivate(method_not_empty)

static uint32_T method_main;

static emlrtRSInfo ae_emlrtRSI =
    {
        45,         /* lineNo */
        "eml_rand", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/randfun/private/"
        "eml_rand.m" /* pathName */
};

/* Function Definitions */
real_T eml_rand(const emlrtStack *sp)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ae_emlrtRSI;
  return eml_rand_mt19937ar_stateful(&st);
}

void eml_rand_init(const emlrtStack *sp)
{
  jmp_buf *volatile emlrtJBStack;
  int32_T eml_rand_init_numThreads;
  int32_T i;
  int32_T ub_loop;
  ub_loop = omp_get_max_threads();
  emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
  emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  eml_rand_init_numThreads = emlrtAllocRegionTLSs(
      sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for schedule(static) num_threads(eml_rand_init_numThreads)

  for (i = 1; i <= ub_loop; i++) {
    method = 7U;
    method_not_empty = true;
  }
  emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
  method_main = 7U;
  method_not_empty_main = true;
}

void eml_rand_swap(void)
{
  uint32_T method_tmp;
  boolean_T method_not_empty_tmp;
  method_tmp = method;
  method = method_main;
  method_main = method_tmp;
  method_not_empty_tmp = method_not_empty;
  method_not_empty = method_not_empty_main;
  method_not_empty_main = method_not_empty_tmp;
}

/* End of code generation (eml_rand.c) */
