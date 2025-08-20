/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * determine_target_location_fordemo.c
 *
 * Code generation for function 'determine_target_location_fordemo'
 *
 */

/* Include files */
#include "determine_target_location_fordemo.h"
#include "determine_target_location_fordemo_data.h"
#include "determine_target_location_fordemo_emxutil.h"
#include "determine_target_location_fordemo_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    6,                                   /* lineNo */
    "determine_target_location_fordemo", /* fcnName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m" /* pathName */
};

static emlrtRTEInfo emlrtRTEI = {
    4,                                   /* lineNo */
    13,                                  /* colNo */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m" /* pName */
};

static emlrtRTEInfo b_emlrtRTEI = {
    5,                                   /* lineNo */
    17,                                  /* colNo */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m" /* pName */
};

static emlrtDCInfo emlrtDCI = {
    13,                                  /* lineNo */
    39,                                  /* colNo */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    1                              /* checkKind */
};

static emlrtBCInfo emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    13,                                  /* lineNo */
    39,                                  /* colNo */
    "obj.waypoint",                      /* aName */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    0                              /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    14,                                  /* lineNo */
    35,                                  /* colNo */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    1                              /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    14,                                  /* lineNo */
    35,                                  /* colNo */
    "obj.wall",                          /* aName */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    13,                                  /* lineNo */
    19,                                  /* colNo */
    "tgt",                               /* aName */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    13,                                  /* lineNo */
    21,                                  /* colNo */
    "tgt",                               /* aName */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    14,                                  /* lineNo */
    19,                                  /* colNo */
    "lim",                               /* aName */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    14,                                  /* lineNo */
    21,                                  /* colNo */
    "lim",                               /* aName */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    0                              /* checkKind */
};

static emlrtRTEInfo c_emlrtRTEI = {
    13,                                                            /* lineNo */
    9,                                                             /* colNo */
    "sqrt",                                                        /* fName */
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elfun/sqrt.m" /* pName */
};

static emlrtDCInfo c_emlrtDCI = {
    2,                                   /* lineNo */
    19,                                  /* colNo */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    1                              /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    2,                                   /* lineNo */
    19,                                  /* colNo */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    4                              /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    2,                                   /* lineNo */
    25,                                  /* colNo */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    1                              /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = {
    2,                                   /* lineNo */
    25,                                  /* colNo */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    4                              /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = {
    3,                                   /* lineNo */
    19,                                  /* colNo */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    1                              /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = {
    3,                                   /* lineNo */
    25,                                  /* colNo */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    1                              /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = {
    2,                                   /* lineNo */
    5,                                   /* colNo */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    1                              /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = {
    3,                                   /* lineNo */
    5,                                   /* colNo */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    1                              /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    6,                                   /* lineNo */
    149,                                 /* colNo */
    "obj.abc",                           /* aName */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    0                              /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = {
    6,                                   /* lineNo */
    149,                                 /* colNo */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    1                              /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    6,                                   /* lineNo */
    164,                                 /* colNo */
    "obj.target_n",                      /* aName */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    6,                                   /* lineNo */
    182,                                 /* colNo */
    "obj.abc",                           /* aName */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    0                              /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = {
    6,                                   /* lineNo */
    182,                                 /* colNo */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    1                              /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    6,                                   /* lineNo */
    26,                                  /* colNo */
    "obj.abc",                           /* aName */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    0                              /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = {
    6,                                   /* lineNo */
    26,                                  /* colNo */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    1                              /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    1,                                   /* iFirst */
    21,                                  /* iLast */
    6,                                   /* lineNo */
    54,                                  /* colNo */
    "px",                                /* aName */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    6,                                   /* lineNo */
    56,                                  /* colNo */
    "px",                                /* aName */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    6,                                   /* lineNo */
    69,                                  /* colNo */
    "obj.abc",                           /* aName */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    0                              /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = {
    6,                                   /* lineNo */
    69,                                  /* colNo */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    1                              /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    6,                                   /* lineNo */
    99,                                  /* colNo */
    "px",                                /* aName */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    6,                                   /* lineNo */
    112,                                 /* colNo */
    "obj.abc",                           /* aName */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    0                              /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = {
    6,                                   /* lineNo */
    112,                                 /* colNo */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    1                              /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    8,                                   /* lineNo */
    32,                                  /* colNo */
    "obj.target_n",                      /* aName */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    13,                                  /* lineNo */
    54,                                  /* colNo */
    "obj.target_n",                      /* aName */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    9,                                   /* lineNo */
    35,                                  /* colNo */
    "obj.target_n",                      /* aName */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m", /* pName */
    0                              /* checkKind */
};

static emlrtRTEInfo d_emlrtRTEI = {
    2,                                   /* lineNo */
    5,                                   /* colNo */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m" /* pName */
};

static emlrtRTEInfo e_emlrtRTEI = {
    3,                                   /* lineNo */
    5,                                   /* colNo */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m" /* pName */
};

static emlrtRTEInfo f_emlrtRTEI = {
    17,                                  /* lineNo */
    5,                                   /* colNo */
    "determine_target_location_fordemo", /* fName */
    "/home/student/"
    "\xe3\x83\x89\xe3\x82\xad\xe3\x83\xa5\xe3\x83\xa1\xe3\x83\xb3\xe3\x83\x88/"
    "TMaehara/kakuritu/src/Controller/determin"
    "e_target_location_fordemo.m" /* pName */
};

/* Function Definitions */
void determine_target_location_fordemo(const emlrtStack *sp, struct0_T *obj,
                                       const emxArray_real_T *px,
                                       real_T resetWPIdx, emxArray_real_T *tgt,
                                       emxArray_real_T *lim,
                                       emxArray_real_T *tgt_n)
{
  emlrtStack st;
  const real_T *px_data;
  real_T *lim_data;
  real_T *tgt_data;
  int32_T b_loop_ub_tmp;
  int32_T d_tmp;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T loop_ub_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  px_data = px->data;
  if (!(obj->K >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->K, &d_emlrtDCI, (emlrtConstCTX)sp);
  }
  i = (int32_T)muDoubleScalarFloor(obj->K);
  if (obj->K != i) {
    emlrtIntegerCheckR2012b(obj->K, &c_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (!(obj->NP >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->NP, &f_emlrtDCI, (emlrtConstCTX)sp);
  }
  d_tmp = (int32_T)muDoubleScalarFloor(obj->NP);
  if (obj->NP != d_tmp) {
    emlrtIntegerCheckR2012b(obj->NP, &e_emlrtDCI, (emlrtConstCTX)sp);
  }
  i1 = tgt->size[0] * tgt->size[1] * tgt->size[2];
  tgt->size[0] = 2;
  tgt->size[1] = (int32_T)obj->K;
  i2 = (int32_T)obj->NP;
  tgt->size[2] = (int32_T)obj->NP;
  emxEnsureCapacity_real_T(sp, tgt, i1, &d_emlrtRTEI);
  tgt_data = tgt->data;
  if (obj->K != i) {
    emlrtIntegerCheckR2012b(obj->K, &i_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (obj->NP != d_tmp) {
    emlrtIntegerCheckR2012b(obj->NP, &i_emlrtDCI, (emlrtConstCTX)sp);
  }
  loop_ub_tmp = (int32_T)obj->K;
  b_loop_ub_tmp = (int32_T)obj->NP;
  loop_ub = (loop_ub_tmp << 1) * b_loop_ub_tmp;
  for (i1 = 0; i1 < loop_ub; i1++) {
    tgt_data[i1] = 0.0;
  }
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(obj->K, &g_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (b_loop_ub_tmp != d_tmp) {
    emlrtIntegerCheckR2012b(obj->NP, &h_emlrtDCI, (emlrtConstCTX)sp);
  }
  i1 = lim->size[0] * lim->size[1] * lim->size[2];
  lim->size[0] = 4;
  lim->size[1] = loop_ub_tmp;
  lim->size[2] = b_loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, lim, i1, &e_emlrtRTEI);
  lim_data = lim->data;
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(obj->K, &j_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (b_loop_ub_tmp != d_tmp) {
    emlrtIntegerCheckR2012b(obj->NP, &j_emlrtDCI, (emlrtConstCTX)sp);
  }
  loop_ub = (loop_ub_tmp << 2) * b_loop_ub_tmp;
  for (i = 0; i < loop_ub; i++) {
    lim_data[i] = 0.0;
  }
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, obj->NP, mxDOUBLE_CLASS,
                                (int32_T)obj->NP, &emlrtRTEI,
                                (emlrtConstCTX)sp);
  for (b_loop_ub_tmp = 0; b_loop_ub_tmp < i2; b_loop_ub_tmp++) {
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, obj->K, mxDOUBLE_CLASS,
                                  (int32_T)obj->K, &b_emlrtRTEI,
                                  (emlrtConstCTX)sp);
    for (loop_ub = 0; loop_ub < loop_ub_tmp; loop_ub++) {
      real_T a_tmp;
      real_T b_a_tmp;
      real_T b_d;
      real_T d;
      real_T x;
      boolean_T b;
      st.site = &emlrtRSI;
      b = (((int32_T)((uint32_T)b_loop_ub_tmp + 1U) < 1) ||
           ((int32_T)((uint32_T)b_loop_ub_tmp + 1U) > obj->target_n->size[1]));
      if (b) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_loop_ub_tmp + 1U),
                                      1, obj->target_n->size[1], &h_emlrtBCI,
                                      &st);
      }
      i = loop_ub + 21 * b_loop_ub_tmp;
      d = obj->target_n->data[i];
      b_d = (int32_T)muDoubleScalarFloor(d - 1.0);
      if (d - 1.0 != b_d) {
        emlrtIntegerCheckR2012b(d - 1.0, &k_emlrtDCI, &st);
      }
      if (((int32_T)(d - 1.0) < 1) || ((int32_T)(d - 1.0) > obj->abc.size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(d - 1.0), 1, obj->abc.size[0],
                                      &g_emlrtBCI, &st);
      }
      a_tmp = obj->abc.data[(int32_T)(d - 1.0) - 1];
      st.site = &emlrtRSI;
      if (d - 1.0 != b_d) {
        emlrtIntegerCheckR2012b(d - 1.0, &l_emlrtDCI, &st);
      }
      if (((int32_T)(d - 1.0) < 1) || ((int32_T)(d - 1.0) > obj->abc.size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(d - 1.0), 1, obj->abc.size[0],
                                      &i_emlrtBCI, &st);
      }
      b_a_tmp = obj->abc.data[((int32_T)(d - 1.0) + obj->abc.size[0]) - 1];
      st.site = &emlrtRSI;
      x = a_tmp * a_tmp + b_a_tmp * b_a_tmp;
      if (x < 0.0) {
        emlrtErrorWithMessageIdR2018a(
            &st, &c_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
            "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
      }
      x = muDoubleScalarSqrt(x);
      if (d - 1.0 != b_d) {
        emlrtIntegerCheckR2012b(d - 1.0, &m_emlrtDCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)(d - 1.0) < 1) || ((int32_T)(d - 1.0) > obj->abc.size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(d - 1.0), 1, obj->abc.size[0],
                                      &j_emlrtBCI, (emlrtConstCTX)sp);
      }
      if ((int32_T)((uint32_T)loop_ub + 1U) > 21) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)loop_ub + 1U), 1, 21,
                                      &k_emlrtBCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)((uint32_T)b_loop_ub_tmp + 1U) < 1) ||
          ((int32_T)((uint32_T)b_loop_ub_tmp + 1U) > px->size[2])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_loop_ub_tmp + 1U),
                                      1, px->size[2], &l_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (d - 1.0 != b_d) {
        emlrtIntegerCheckR2012b(d - 1.0, &n_emlrtDCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)(d - 1.0) < 1) || ((int32_T)(d - 1.0) > obj->abc.size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(d - 1.0), 1, obj->abc.size[0],
                                      &m_emlrtBCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)((uint32_T)b_loop_ub_tmp + 1U) < 1) ||
          ((int32_T)((uint32_T)b_loop_ub_tmp + 1U) > px->size[2])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_loop_ub_tmp + 1U),
                                      1, px->size[2], &n_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (d - 1.0 != b_d) {
        emlrtIntegerCheckR2012b(d - 1.0, &o_emlrtDCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)(d - 1.0) < 1) || ((int32_T)(d - 1.0) > obj->abc.size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(d - 1.0), 1, obj->abc.size[0],
                                      &o_emlrtBCI, (emlrtConstCTX)sp);
      }
      d_tmp = 3 * loop_ub + 63 * b_loop_ub_tmp;
      b_d = ((a_tmp * px_data[d_tmp] + b_a_tmp * px_data[d_tmp + 1]) +
             obj->abc.data[((int32_T)(d - 1.0) + obj->abc.size[0] * 2) - 1]) /
            x;
      if ((b_d > -0.15) && (b_d < 0.15)) {
        if (((int32_T)((uint32_T)b_loop_ub_tmp + 1U) < 1) ||
            ((int32_T)((uint32_T)b_loop_ub_tmp + 1U) >
             obj->target_n->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_loop_ub_tmp + 1U),
                                        1, obj->target_n->size[1], &p_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        obj->target_n->data[i] = d + 1.0;
        b = (((int32_T)((uint32_T)b_loop_ub_tmp + 1U) < 1) ||
             ((int32_T)((uint32_T)b_loop_ub_tmp + 1U) >
              obj->target_n->size[1]));
        if (b) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_loop_ub_tmp + 1U),
                                        1, obj->target_n->size[1], &r_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (obj->waypoint.size[0] == 0) {
          i1 = 0;
        } else {
          i1 = muIntScalarMax_sint32(obj->waypoint.size[0], 2);
        }
        if (obj->target_n->data[i] == (real_T)i1 + 1.0) {
          obj->target_n->data[i] = resetWPIdx;
        }
      }
      b = (((int32_T)((uint32_T)b_loop_ub_tmp + 1U) < 1) ||
           ((int32_T)((uint32_T)b_loop_ub_tmp + 1U) > obj->target_n->size[1]));
      if (b) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_loop_ub_tmp + 1U),
                                      1, obj->target_n->size[1], &q_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      d = obj->target_n->data[i];
      b_d = (int32_T)muDoubleScalarFloor(d);
      if (d != b_d) {
        emlrtIntegerCheckR2012b(d, &emlrtDCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)d < 1) || ((int32_T)d > obj->waypoint.size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, obj->waypoint.size[0],
                                      &emlrtBCI, (emlrtConstCTX)sp);
      }
      if ((int32_T)((uint32_T)loop_ub + 1U) > tgt->size[1]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)loop_ub + 1U), 1,
                                      tgt->size[1], &c_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (((int32_T)((uint32_T)b_loop_ub_tmp + 1U) < 1) ||
          ((int32_T)((uint32_T)b_loop_ub_tmp + 1U) > tgt->size[2])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_loop_ub_tmp + 1U),
                                      1, tgt->size[2], &d_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      tgt_data[2 * loop_ub + 2 * tgt->size[1] * b_loop_ub_tmp] =
          obj->waypoint.data[(int32_T)d - 1];
      tgt_data[(2 * loop_ub + 2 * tgt->size[1] * b_loop_ub_tmp) + 1] =
          obj->waypoint.data[((int32_T)d + obj->waypoint.size[0]) - 1];
      if (d != b_d) {
        emlrtIntegerCheckR2012b(d, &b_emlrtDCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)d < 1) || ((int32_T)d > obj->wall.size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, obj->wall.size[0],
                                      &b_emlrtBCI, (emlrtConstCTX)sp);
      }
      if ((int32_T)((uint32_T)loop_ub + 1U) > lim->size[1]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)loop_ub + 1U), 1,
                                      lim->size[1], &e_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (((int32_T)((uint32_T)b_loop_ub_tmp + 1U) < 1) ||
          ((int32_T)((uint32_T)b_loop_ub_tmp + 1U) > lim->size[2])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_loop_ub_tmp + 1U),
                                      1, lim->size[2], &f_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      lim_data[4 * loop_ub + 4 * lim->size[1] * b_loop_ub_tmp] =
          obj->wall.data[(int32_T)d - 1];
      lim_data[(4 * loop_ub + 4 * lim->size[1] * b_loop_ub_tmp) + 1] =
          obj->wall.data[((int32_T)d + obj->wall.size[0]) - 1];
      lim_data[(4 * loop_ub + 4 * lim->size[1] * b_loop_ub_tmp) + 2] =
          obj->wall.data[((int32_T)d + obj->wall.size[0] * 2) - 1];
      lim_data[(4 * loop_ub + 4 * lim->size[1] * b_loop_ub_tmp) + 3] =
          obj->wall.data[((int32_T)d + obj->wall.size[0] * 3) - 1];
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  i = tgt_n->size[0] * tgt_n->size[1];
  tgt_n->size[0] = 21;
  tgt_n->size[1] = obj->target_n->size[1];
  emxEnsureCapacity_real_T(sp, tgt_n, i, &f_emlrtRTEI);
  tgt_data = tgt_n->data;
  loop_ub = 21 * obj->target_n->size[1];
  for (i = 0; i < loop_ub; i++) {
    tgt_data[i] = obj->target_n->data[i];
  }
}

/* End of code generation (determine_target_location_fordemo.c) */
