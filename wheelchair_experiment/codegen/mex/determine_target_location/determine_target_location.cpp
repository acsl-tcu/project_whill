//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  determine_target_location.cpp
//
//  Code generation for function 'determine_target_location'
//


// Include files
#include "determine_target_location.h"
#include "determine_target_location_data.h"
#include "determine_target_location_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo emlrtRSI = { 6,     // lineNo
  "determine_target_location",         // fcnName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m"// pathName 
};

static emlrtRTEInfo emlrtRTEI = { 4,   // lineNo
  13,                                  // colNo
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m"// pName 
};

static emlrtRTEInfo b_emlrtRTEI = { 5, // lineNo
  17,                                  // colNo
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m"// pName 
};

static emlrtDCInfo emlrtDCI = { 10,    // lineNo
  39,                                  // colNo
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo emlrtBCI = { -1,    // iFirst
  -1,                                  // iLast
  10,                                  // lineNo
  39,                                  // colNo
  "obj.waypoint",                      // aName
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo b_emlrtDCI = { 11,  // lineNo
  35,                                  // colNo
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo b_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  11,                                  // lineNo
  35,                                  // colNo
  "obj.wall",                          // aName
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo c_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  10,                                  // lineNo
  19,                                  // colNo
  "tgt",                               // aName
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo d_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  10,                                  // lineNo
  21,                                  // colNo
  "tgt",                               // aName
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo e_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  11,                                  // lineNo
  19,                                  // colNo
  "lim",                               // aName
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo f_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  11,                                  // lineNo
  21,                                  // colNo
  "lim",                               // aName
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo c_emlrtRTEI = { 13,// lineNo
  9,                                   // colNo
  "sqrt",                              // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elfun/sqrt.m"// pName
};

static emlrtDCInfo c_emlrtDCI = { 2,   // lineNo
  19,                                  // colNo
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo d_emlrtDCI = { 2,   // lineNo
  19,                                  // colNo
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  4                                    // checkKind
};

static emlrtDCInfo e_emlrtDCI = { 2,   // lineNo
  25,                                  // colNo
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo f_emlrtDCI = { 2,   // lineNo
  25,                                  // colNo
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  4                                    // checkKind
};

static emlrtDCInfo g_emlrtDCI = { 3,   // lineNo
  19,                                  // colNo
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo h_emlrtDCI = { 3,   // lineNo
  19,                                  // colNo
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  4                                    // checkKind
};

static emlrtDCInfo i_emlrtDCI = { 3,   // lineNo
  25,                                  // colNo
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo j_emlrtDCI = { 3,   // lineNo
  25,                                  // colNo
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  4                                    // checkKind
};

static emlrtDCInfo k_emlrtDCI = { 2,   // lineNo
  5,                                   // colNo
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo l_emlrtDCI = { 2,   // lineNo
  5,                                   // colNo
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  4                                    // checkKind
};

static emlrtDCInfo m_emlrtDCI = { 3,   // lineNo
  5,                                   // colNo
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo n_emlrtDCI = { 3,   // lineNo
  5,                                   // colNo
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  4                                    // checkKind
};

static emlrtBCInfo g_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  6,                                   // lineNo
  141,                                 // colNo
  "obj.abc",                           // aName
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo o_emlrtDCI = { 6,   // lineNo
  141,                                 // colNo
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo h_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  6,                                   // lineNo
  141,                                 // colNo
  "obj.target_n",                      // aName
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo i_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  6,                                   // lineNo
  174,                                 // colNo
  "obj.abc",                           // aName
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo p_emlrtDCI = { 6,   // lineNo
  174,                                 // colNo
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo j_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  6,                                   // lineNo
  174,                                 // colNo
  "obj.target_n",                      // aName
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo k_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  6,                                   // lineNo
  18,                                  // colNo
  "obj.abc",                           // aName
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo q_emlrtDCI = { 6,   // lineNo
  18,                                  // colNo
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo l_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  6,                                   // lineNo
  18,                                  // colNo
  "obj.target_n",                      // aName
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo m_emlrtBCI = { 1,   // iFirst
  21,                                  // iLast
  6,                                   // lineNo
  49,                                  // colNo
  "px",                                // aName
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo n_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  6,                                   // lineNo
  49,                                  // colNo
  "px",                                // aName
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo o_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  6,                                   // lineNo
  61,                                  // colNo
  "obj.abc",                           // aName
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo r_emlrtDCI = { 6,   // lineNo
  61,                                  // colNo
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo p_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  6,                                   // lineNo
  61,                                  // colNo
  "obj.target_n",                      // aName
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo q_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  6,                                   // lineNo
  92,                                  // colNo
  "px",                                // aName
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo r_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  6,                                   // lineNo
  104,                                 // colNo
  "obj.abc",                           // aName
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo s_emlrtDCI = { 6,   // lineNo
  104,                                 // colNo
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo s_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  6,                                   // lineNo
  104,                                 // colNo
  "obj.target_n",                      // aName
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo t_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  8,                                   // lineNo
  37,                                  // colNo
  "obj.target_n",                      // aName
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo u_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  8,                                   // lineNo
  17,                                  // colNo
  "obj.target_n",                      // aName
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo v_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  10,                                  // lineNo
  39,                                  // colNo
  "obj.target_n",                      // aName
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo w_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  11,                                  // lineNo
  35,                                  // colNo
  "obj.target_n",                      // aName
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo d_emlrtRTEI = { 2, // lineNo
  5,                                   // colNo
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m"// pName 
};

static emlrtRTEInfo e_emlrtRTEI = { 3, // lineNo
  5,                                   // colNo
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m"// pName 
};

static emlrtRTEInfo f_emlrtRTEI = { 14,// lineNo
  5,                                   // colNo
  "determine_target_location",         // fName
  "/home/ekawaguchi/デスクトップ/0307program/determine_target_location.m"// pName 
};

// Function Definitions
void determine_target_location(const emlrtStack *sp, struct0_T *obj, const coder::
  array<real_T, 3U> &px, coder::array<real_T, 3U> &tgt, coder::array<real_T, 3U>
  &lim, coder::array<real_T, 2U> &tgt_n)
{
  emlrtStack st;
  real_T b_d;
  real_T d;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  tgt.set_size(&d_emlrtRTEI, sp, 2, tgt.size(1), tgt.size(2));
  if (!(obj->K >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->K, &d_emlrtDCI, sp);
  }

  d = static_cast<int32_T>(muDoubleScalarFloor(obj->K));
  if (obj->K != d) {
    emlrtIntegerCheckR2012b(obj->K, &c_emlrtDCI, sp);
  }

  tgt.set_size(&d_emlrtRTEI, sp, tgt.size(0), static_cast<int32_T>(obj->K),
               tgt.size(2));
  if (!(obj->NP >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->NP, &f_emlrtDCI, sp);
  }

  b_d = static_cast<int32_T>(muDoubleScalarFloor(obj->NP));
  if (obj->NP != b_d) {
    emlrtIntegerCheckR2012b(obj->NP, &e_emlrtDCI, sp);
  }

  tgt.set_size(&d_emlrtRTEI, sp, tgt.size(0), tgt.size(1), static_cast<int32_T>
               (obj->NP));
  if (!(obj->K >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->K, &l_emlrtDCI, sp);
  }

  if (obj->K != d) {
    emlrtIntegerCheckR2012b(obj->K, &k_emlrtDCI, sp);
  }

  if (!(obj->NP >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->NP, &l_emlrtDCI, sp);
  }

  if (obj->NP != b_d) {
    emlrtIntegerCheckR2012b(obj->NP, &k_emlrtDCI, sp);
  }

  loop_ub = (static_cast<int32_T>(obj->K) << 1) * static_cast<int32_T>(obj->NP);
  for (i = 0; i < loop_ub; i++) {
    tgt[i] = 0.0;
  }

  lim.set_size(&e_emlrtRTEI, sp, 4, lim.size(1), lim.size(2));
  if (!(obj->K >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->K, &h_emlrtDCI, sp);
  }

  if (obj->K != d) {
    emlrtIntegerCheckR2012b(obj->K, &g_emlrtDCI, sp);
  }

  lim.set_size(&e_emlrtRTEI, sp, lim.size(0), static_cast<int32_T>(obj->K),
               lim.size(2));
  if (!(obj->NP >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->NP, &j_emlrtDCI, sp);
  }

  if (obj->NP != b_d) {
    emlrtIntegerCheckR2012b(obj->NP, &i_emlrtDCI, sp);
  }

  lim.set_size(&e_emlrtRTEI, sp, lim.size(0), lim.size(1), static_cast<int32_T>
               (obj->NP));
  if (!(obj->K >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->K, &n_emlrtDCI, sp);
  }

  if (obj->K != d) {
    emlrtIntegerCheckR2012b(obj->K, &m_emlrtDCI, sp);
  }

  if (!(obj->NP >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->NP, &n_emlrtDCI, sp);
  }

  if (obj->NP != b_d) {
    emlrtIntegerCheckR2012b(obj->NP, &m_emlrtDCI, sp);
  }

  loop_ub = (static_cast<int32_T>(obj->K) << 2) * static_cast<int32_T>(obj->NP);
  for (i = 0; i < loop_ub; i++) {
    lim[i] = 0.0;
  }

  i = static_cast<int32_T>(obj->NP);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, obj->NP, mxDOUBLE_CLASS,
    static_cast<int32_T>(obj->NP), &emlrtRTEI, sp);
  for (int32_T j = 0; j < i; j++) {
    loop_ub = static_cast<int32_T>(obj->K);
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, obj->K, mxDOUBLE_CLASS,
      static_cast<int32_T>(obj->K), &b_emlrtRTEI, sp);
    for (int32_T b_i = 0; b_i < loop_ub; b_i++) {
      real_T a;
      real_T d1;
      st.site = &emlrtRSI;
      if ((static_cast<int32_T>(j + 1U) < 1) || (static_cast<int32_T>(j + 1U) >
           obj->target_n.size(1))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j + 1U), 1,
          obj->target_n.size(1), &h_emlrtBCI, &st);
      }

      d = obj->target_n[b_i + 21 * j] - 1.0;
      if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
        emlrtIntegerCheckR2012b(d, &o_emlrtDCI, &st);
      }

      if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
           obj->abc.size[0])) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1, obj->abc.size
          [0], &g_emlrtBCI, &st);
      }

      a = obj->abc.data[static_cast<int32_T>(d) - 1];
      st.site = &emlrtRSI;
      if ((static_cast<int32_T>(j + 1U) < 1) || (static_cast<int32_T>(j + 1U) >
           obj->target_n.size(1))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j + 1U), 1,
          obj->target_n.size(1), &j_emlrtBCI, &st);
      }

      d = obj->target_n[b_i + 21 * j] - 1.0;
      if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
        emlrtIntegerCheckR2012b(d, &p_emlrtDCI, &st);
      }

      if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
           obj->abc.size[0])) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1, obj->abc.size
          [0], &i_emlrtBCI, &st);
      }

      b_d = obj->abc.data[(static_cast<int32_T>(d) + obj->abc.size[0]) - 1];
      st.site = &emlrtRSI;
      a = a * a + b_d * b_d;
      if (a < 0.0) {
        emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 4, "sqrt");
      }

      a = muDoubleScalarSqrt(a);
      if ((static_cast<int32_T>(j + 1U) < 1) || (static_cast<int32_T>(j + 1U) >
           obj->target_n.size(1))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j + 1U), 1,
          obj->target_n.size(1), &l_emlrtBCI, sp);
      }

      d = obj->target_n[b_i + 21 * j] - 1.0;
      if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
        emlrtIntegerCheckR2012b(d, &q_emlrtDCI, sp);
      }

      if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
           obj->abc.size[0])) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1, obj->abc.size
          [0], &k_emlrtBCI, sp);
      }

      if ((static_cast<int32_T>(b_i + 1U) < 1) || (static_cast<int32_T>(b_i + 1U)
           > 21)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_i + 1U), 1, 21,
          &m_emlrtBCI, sp);
      }

      if ((static_cast<int32_T>(j + 1U) < 1) || (static_cast<int32_T>(j + 1U) >
           px.size(2))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j + 1U), 1, px.size(2),
          &n_emlrtBCI, sp);
      }

      if ((static_cast<int32_T>(j + 1U) < 1) || (static_cast<int32_T>(j + 1U) >
           obj->target_n.size(1))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j + 1U), 1,
          obj->target_n.size(1), &p_emlrtBCI, sp);
      }

      b_d = obj->target_n[b_i + 21 * j] - 1.0;
      if (b_d != static_cast<int32_T>(muDoubleScalarFloor(b_d))) {
        emlrtIntegerCheckR2012b(b_d, &r_emlrtDCI, sp);
      }

      if ((static_cast<int32_T>(b_d) < 1) || (static_cast<int32_T>(b_d) >
           obj->abc.size[0])) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_d), 1,
          obj->abc.size[0], &o_emlrtBCI, sp);
      }

      if ((static_cast<int32_T>(j + 1U) < 1) || (static_cast<int32_T>(j + 1U) >
           px.size(2))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j + 1U), 1, px.size(2),
          &q_emlrtBCI, sp);
      }

      if ((static_cast<int32_T>(j + 1U) < 1) || (static_cast<int32_T>(j + 1U) >
           obj->target_n.size(1))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j + 1U), 1,
          obj->target_n.size(1), &s_emlrtBCI, sp);
      }

      d1 = obj->target_n[b_i + 21 * j] - 1.0;
      if (d1 != static_cast<int32_T>(muDoubleScalarFloor(d1))) {
        emlrtIntegerCheckR2012b(d1, &s_emlrtDCI, sp);
      }

      if ((static_cast<int32_T>(d1) < 1) || (static_cast<int32_T>(d1) >
           obj->abc.size[0])) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d1), 1, obj->
          abc.size[0], &r_emlrtBCI, sp);
      }

      b_d = ((obj->abc.data[static_cast<int32_T>(d) - 1] * px[3 * b_i + 63 * j]
              + obj->abc.data[(static_cast<int32_T>(b_d) + obj->abc.size[0]) - 1]
              * px[(3 * b_i + 63 * j) + 1]) + obj->abc.data[(static_cast<int32_T>
              (d1) + obj->abc.size[0] * 2) - 1]) / a;
      if ((b_d > -0.2) && (b_d < 0.2)) {
        if ((static_cast<int32_T>(j + 1U) < 1) || (static_cast<int32_T>(j + 1U) >
             obj->target_n.size(1))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j + 1U), 1,
            obj->target_n.size(1), &t_emlrtBCI, sp);
        }

        if ((static_cast<int32_T>(j + 1U) < 1) || (static_cast<int32_T>(j + 1U) >
             obj->target_n.size(1))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j + 1U), 1,
            obj->target_n.size(1), &u_emlrtBCI, sp);
        }

        obj->target_n[b_i + 21 * j] = obj->target_n[b_i + 21 * j] + 1.0;
      }

      if ((static_cast<int32_T>(j + 1U) < 1) || (static_cast<int32_T>(j + 1U) >
           obj->target_n.size(1))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j + 1U), 1,
          obj->target_n.size(1), &v_emlrtBCI, sp);
      }

      d = obj->target_n[b_i + 21 * j];
      if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
        emlrtIntegerCheckR2012b(d, &emlrtDCI, sp);
      }

      if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
           obj->waypoint.size[0])) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
          obj->waypoint.size[0], &emlrtBCI, sp);
      }

      if ((static_cast<int32_T>(b_i + 1U) < 1) || (static_cast<int32_T>(b_i + 1U)
           > tgt.size(1))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_i + 1U), 1,
          tgt.size(1), &c_emlrtBCI, sp);
      }

      if ((static_cast<int32_T>(j + 1U) < 1) || (static_cast<int32_T>(j + 1U) >
           tgt.size(2))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j + 1U), 1, tgt.size
          (2), &d_emlrtBCI, sp);
      }

      tgt[2 * b_i + 2 * tgt.size(1) * j] = obj->waypoint.data
        [static_cast<int32_T>(d) - 1];
      tgt[(2 * b_i + 2 * tgt.size(1) * j) + 1] = obj->waypoint.data[(
        static_cast<int32_T>(d) + obj->waypoint.size[0]) - 1];
      if ((static_cast<int32_T>(j + 1U) < 1) || (static_cast<int32_T>(j + 1U) >
           obj->target_n.size(1))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j + 1U), 1,
          obj->target_n.size(1), &w_emlrtBCI, sp);
      }

      d = obj->target_n[b_i + 21 * j];
      if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
        emlrtIntegerCheckR2012b(d, &b_emlrtDCI, sp);
      }

      if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
           obj->wall.size[0])) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1, obj->
          wall.size[0], &b_emlrtBCI, sp);
      }

      if ((static_cast<int32_T>(b_i + 1U) < 1) || (static_cast<int32_T>(b_i + 1U)
           > lim.size(1))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_i + 1U), 1,
          lim.size(1), &e_emlrtBCI, sp);
      }

      if ((static_cast<int32_T>(j + 1U) < 1) || (static_cast<int32_T>(j + 1U) >
           lim.size(2))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j + 1U), 1, lim.size
          (2), &f_emlrtBCI, sp);
      }

      lim[4 * b_i + 4 * lim.size(1) * j] = obj->wall.data[static_cast<int32_T>(d)
        - 1];
      lim[(4 * b_i + 4 * lim.size(1) * j) + 1] = obj->wall.data
        [(static_cast<int32_T>(d) + obj->wall.size[0]) - 1];
      lim[(4 * b_i + 4 * lim.size(1) * j) + 2] = obj->wall.data
        [(static_cast<int32_T>(d) + obj->wall.size[0] * 2) - 1];
      lim[(4 * b_i + 4 * lim.size(1) * j) + 3] = obj->wall.data
        [(static_cast<int32_T>(d) + obj->wall.size[0] * 3) - 1];
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  tgt_n.set_size(&f_emlrtRTEI, sp, 21, obj->target_n.size(1));
  loop_ub = obj->target_n.size(0) * obj->target_n.size(1);
  for (i = 0; i < loop_ub; i++) {
    tgt_n[i] = obj->target_n[i];
  }
}

// End of code generation (determine_target_location.cpp)
