/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ismember.c
 *
 * Code generation for function 'ismember'
 *
 */

/* Include files */
#include "ismember.h"
#include "Faster_processingPcloud_data.h"
#include "Faster_processingPcloud_emxutil.h"
#include "Faster_processingPcloud_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "mwmathutil.h"
#include "omp.h"

/* Variable Definitions */
static emlrtRSInfo wi_emlrtRSI = {
    162,        /* lineNo */
    "isMember", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/ismember.m" /* pathName
                                                                      */
};

static emlrtRSInfo xi_emlrtRSI = {
    163,        /* lineNo */
    "isMember", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/ismember.m" /* pathName
                                                                      */
};

static emlrtRSInfo yi_emlrtRSI = {
    173,        /* lineNo */
    "isMember", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/ismember.m" /* pathName
                                                                      */
};

static emlrtRSInfo aj_emlrtRSI = {
    180,        /* lineNo */
    "isMember", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/ismember.m" /* pathName
                                                                      */
};

static emlrtRSInfo bj_emlrtRSI = {
    183,        /* lineNo */
    "isMember", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/ismember.m" /* pathName
                                                                      */
};

static emlrtRSInfo cj_emlrtRSI = {
    202,        /* lineNo */
    "isMember", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/ismember.m" /* pathName
                                                                      */
};

static emlrtRSInfo gj_emlrtRSI = {
    37,     /* lineNo */
    "sort", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/sort.m" /* pathName
                                                                      */
};

static emlrtRTEInfo xe_emlrtRTEI = {
    120,        /* lineNo */
    1,          /* colNo */
    "ismember", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/ismember.m" /* pName */
};

static emlrtRTEInfo ye_emlrtRTEI = {
    37,     /* lineNo */
    6,      /* colNo */
    "sort", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/sort.m" /* pName */
};

static emlrtRTEInfo af_emlrtRTEI = {
    129,        /* lineNo */
    10,         /* colNo */
    "ismember", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/ismember.m" /* pName */
};

static emlrtRTEInfo bf_emlrtRTEI = {
    115,        /* lineNo */
    21,         /* colNo */
    "ismember", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/ops/ismember.m" /* pName */
};

/* Function Declarations */
static int32_T b_bsearchni(int32_T k, const emxArray_uint32_T *x,
                           const emxArray_real_T *s);

static int32_T bsearchni(int32_T k, const emxArray_uint32_T *x,
                         const emxArray_real_T *s);

/* Function Definitions */
static int32_T b_bsearchni(int32_T k, const emxArray_uint32_T *x,
                           const emxArray_real_T *s)
{
  const real_T *s_data;
  int32_T idx;
  int32_T ihi;
  int32_T ilo;
  const uint32_T *x_data;
  uint32_T b_x;
  boolean_T exitg1;
  s_data = s->data;
  x_data = x->data;
  b_x = x_data[k - 1];
  ihi = s->size[1];
  idx = 0;
  ilo = 1;
  exitg1 = false;
  while ((!exitg1) && (ihi >= ilo)) {
    int32_T imid;
    imid = ((ilo >> 1) + (ihi >> 1)) - 1;
    if ((((uint32_T)ilo & 1U) == 1U) && (((uint32_T)ihi & 1U) == 1U)) {
      imid++;
    }
    if (b_x == s_data[imid]) {
      idx = imid + 1;
      exitg1 = true;
    } else if (muDoubleScalarIsNaN(s_data[imid]) || (b_x < s_data[imid])) {
      ihi = imid;
    } else {
      ilo = imid + 2;
    }
  }
  if (idx > 0) {
    idx--;
    while ((idx > 0) && (b_x == s_data[idx - 1])) {
      idx--;
    }
    idx++;
  }
  return idx;
}

static int32_T bsearchni(int32_T k, const emxArray_uint32_T *x,
                         const emxArray_real_T *s)
{
  const real_T *s_data;
  int32_T idx;
  int32_T ihi;
  int32_T ilo;
  const uint32_T *x_data;
  uint32_T b_x;
  boolean_T exitg1;
  s_data = s->data;
  x_data = x->data;
  b_x = x_data[k - 1];
  ihi = s->size[0];
  idx = 0;
  ilo = 1;
  exitg1 = false;
  while ((!exitg1) && (ihi >= ilo)) {
    int32_T imid;
    imid = ((ilo >> 1) + (ihi >> 1)) - 1;
    if ((((uint32_T)ilo & 1U) == 1U) && (((uint32_T)ihi & 1U) == 1U)) {
      imid++;
    }
    if (b_x == s_data[imid]) {
      idx = imid + 1;
      exitg1 = true;
    } else if (muDoubleScalarIsNaN(s_data[imid]) || (b_x < s_data[imid])) {
      ihi = imid;
    } else {
      ilo = imid + 2;
    }
  }
  if (idx > 0) {
    idx--;
    while ((idx > 0) && (b_x == s_data[idx - 1])) {
      idx--;
    }
    idx++;
  }
  return idx;
}

void isMember(const emlrtStack *sp, const emxArray_uint32_T *a,
              const emxArray_real_T *s, emxArray_boolean_T *tf)
{
  jmp_buf *volatile emlrtJBStack;
  emlrtStack b_st;
  emlrtStack st;
  emxArray_int32_T *mk_emlrtRSI;
  emxArray_real_T *ss;
  const real_T *s_data;
  real_T *ss_data;
  int32_T isMember_numThreads;
  int32_T k;
  int32_T n;
  int32_T na_tmp;
  int32_T ns_tmp;
  int32_T pmax;
  int32_T pmin;
  const uint32_T *a_data;
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T *tf_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  s_data = s->data;
  a_data = a->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  na_tmp = a->size[0];
  ns_tmp = s->size[1];
  pmax = tf->size[0];
  tf->size[0] = a->size[0];
  emxEnsureCapacity_boolean_T(sp, tf, pmax, &xe_emlrtRTEI);
  tf_data = tf->data;
  for (pmax = 0; pmax < na_tmp; pmax++) {
    tf_data[pmax] = false;
  }
  emxInit_real_T(sp, &ss, 1, &af_emlrtRTEI);
  emxInit_int32_T(sp, &mk_emlrtRSI, 1, &bf_emlrtRTEI);
  guard1 = false;
  if (s->size[1] <= 4) {
    guard1 = true;
  } else {
    pmax = 31;
    pmin = 0;
    exitg1 = false;
    while ((!exitg1) && (pmax - pmin > 1)) {
      int32_T p;
      int32_T pow2p;
      p = (pmin + pmax) >> 1;
      pow2p = 1 << p;
      if (pow2p == ns_tmp) {
        pmax = p;
        exitg1 = true;
      } else if (pow2p > ns_tmp) {
        pmax = p;
      } else {
        pmin = p;
      }
    }
    if (a->size[0] <= pmax + 4) {
      guard1 = true;
    } else {
      boolean_T y;
      st.site = &yi_emlrtRSI;
      y = true;
      pmax = 0;
      exitg1 = false;
      while ((!exitg1) && (pmax <= s->size[1] - 2)) {
        real_T v_idx_1;
        v_idx_1 = s_data[pmax + 1];
        if ((s_data[pmax] <= v_idx_1) || muDoubleScalarIsNaN(v_idx_1)) {
          pmax++;
        } else {
          y = false;
          exitg1 = true;
        }
      }
      if (!y) {
        st.site = &aj_emlrtRSI;
        pmax = ss->size[0];
        ss->size[0] = s->size[1];
        emxEnsureCapacity_real_T(&st, ss, pmax, &ye_emlrtRTEI);
        ss_data = ss->data;
        for (pmax = 0; pmax < ns_tmp; pmax++) {
          ss_data[pmax] = s_data[pmax];
        }
        b_st.site = &gj_emlrtRSI;
        sort(&b_st, ss, mk_emlrtRSI);
        st.site = &bj_emlrtRSI;
        if (a->size[0] > 2147483646) {
          b_st.site = &ab_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }
        pmax = a->size[0];
        emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
        emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
        isMember_numThreads =
            emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(),
                                 omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(isMember_numThreads) private(n)

        for (k = 0; k < pmax; k++) {
          n = bsearchni(k + 1, a, ss);
          if (n > 0) {
            tf_data[k] = true;
          }
        }
        emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
        emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
      } else {
        st.site = &cj_emlrtRSI;
        if (a->size[0] > 2147483646) {
          b_st.site = &ab_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }
        pmax = a->size[0];
        emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
        emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
        isMember_numThreads =
            emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(),
                                 omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(isMember_numThreads) private(n)

        for (k = 0; k < pmax; k++) {
          n = b_bsearchni(k + 1, a, s);
          if (n > 0) {
            tf_data[k] = true;
          }
        }
        emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
        emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
      }
    }
  }
  if (guard1) {
    st.site = &wi_emlrtRSI;
    if (a->size[0] > 2147483646) {
      b_st.site = &ab_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (pmin = 0; pmin < na_tmp; pmin++) {
      st.site = &xi_emlrtRSI;
      if (ns_tmp > 2147483646) {
        b_st.site = &ab_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      pmax = 0;
      exitg1 = false;
      while ((!exitg1) && (pmax <= ns_tmp - 1)) {
        if (a_data[pmin] == s_data[pmax]) {
          tf_data[pmin] = true;
          exitg1 = true;
        } else {
          pmax++;
        }
      }
    }
  }
  emxFree_int32_T(sp, &mk_emlrtRSI);
  emxFree_real_T(sp, &ss);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (ismember.c) */
