//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  jpdaEvents.cpp
//
//  Code generation for function 'jpdaEvents'
//


// Include files
#include "jpdaEvents.h"
#include "eml_int_forloop_overflow_check.h"
#include "factorial.h"
#include "find.h"
#include "mexLidarTracker_data.h"
#include "prod.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo pu_emlrtRSI = { 145,// lineNo
  "calcN",                             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m"// pathName
};

static emlrtRSInfo fgb_emlrtRSI = { 108,// lineNo
  "jpdaEvents",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m"// pathName
};

static emlrtRSInfo ggb_emlrtRSI = { 83,// lineNo
  "jpdaEvents",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m"// pathName
};

static emlrtRSInfo hgb_emlrtRSI = { 74,// lineNo
  "jpdaEvents",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m"// pathName
};

static emlrtRSInfo igb_emlrtRSI = { 73,// lineNo
  "jpdaEvents",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m"// pathName
};

static emlrtRSInfo jgb_emlrtRSI = { 70,// lineNo
  "jpdaEvents",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m"// pathName
};

static emlrtRSInfo kgb_emlrtRSI = { 69,// lineNo
  "jpdaEvents",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m"// pathName
};

static emlrtRSInfo lgb_emlrtRSI = { 65,// lineNo
  "jpdaEvents",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m"// pathName
};

static emlrtRSInfo mgb_emlrtRSI = { 62,// lineNo
  "jpdaEvents",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m"// pathName
};

static emlrtRSInfo ngb_emlrtRSI = { 52,// lineNo
  "jpdaEvents",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m"// pathName
};

static emlrtRSInfo sgb_emlrtRSI = { 13,// lineNo
  "any",                               // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/any.m"// pathName
};

static emlrtBCInfo cg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  137,                                 // lineNo
  20,                                  // colNo
  "",                                  // aName
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo dg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  137,                                 // lineNo
  18,                                  // colNo
  "",                                  // aName
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo eg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  119,                                 // lineNo
  31,                                  // colNo
  "",                                  // aName
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo fg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  83,                                  // lineNo
  29,                                  // colNo
  "",                                  // aName
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m",// pName
  0                                    // checkKind
};

static emlrtRTEInfo oc_emlrtRTEI = { 65,// lineNo
  23,                                  // colNo
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m"// pName
};

static emlrtBCInfo gg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  65,                                  // lineNo
  52,                                  // colNo
  "",                                  // aName
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m",// pName
  0                                    // checkKind
};

static emlrtRTEInfo pc_emlrtRTEI = { 62,// lineNo
  23,                                  // colNo
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m"// pName
};

static emlrtRTEInfo qc_emlrtRTEI = { 59,// lineNo
  23,                                  // colNo
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m"// pName
};

static emlrtRTEInfo rc_emlrtRTEI = { 12,// lineNo
  37,                                  // colNo
  "validatebinary",                    // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+valattr/validatebinary.m"// pName 
};

static emlrtRTEInfo sc_emlrtRTEI = { 13,// lineNo
  37,                                  // colNo
  "validatenonempty",                  // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+valattr/validatenonempty.m"// pName 
};

static emlrtBCInfo hg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  102,                                 // lineNo
  14,                                  // colNo
  "",                                  // aName
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ig_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  130,                                 // lineNo
  13,                                  // colNo
  "",                                  // aName
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo jg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  131,                                 // lineNo
  15,                                  // colNo
  "",                                  // aName
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo kg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  132,                                 // lineNo
  9,                                   // colNo
  "",                                  // aName
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo lg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  133,                                 // lineNo
  9,                                   // colNo
  "",                                  // aName
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo mg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  87,                                  // lineNo
  13,                                  // colNo
  "",                                  // aName
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ng_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  111,                                 // lineNo
  16,                                  // colNo
  "",                                  // aName
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo og_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  89,                                  // lineNo
  13,                                  // colNo
  "",                                  // aName
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo pg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  112,                                 // lineNo
  16,                                  // colNo
  "",                                  // aName
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo qg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  119,                                 // lineNo
  20,                                  // colNo
  "",                                  // aName
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo rg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  120,                                 // lineNo
  20,                                  // colNo
  "",                                  // aName
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m",// pName
  0                                    // checkKind
};

static emlrtRTEInfo si_emlrtRTEI = { 83,// lineNo
  5,                                   // colNo
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m"// pName
};

static emlrtRTEInfo ti_emlrtRTEI = { 85,// lineNo
  20,                                  // colNo
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m"// pName
};

static emlrtRTEInfo pl_emlrtRTEI = { 62,// lineNo
  27,                                  // colNo
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m"// pName
};

static emlrtRTEInfo ql_emlrtRTEI = { 65,// lineNo
  31,                                  // colNo
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m"// pName
};

static emlrtRTEInfo rl_emlrtRTEI = { 65,// lineNo
  27,                                  // colNo
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m"// pName
};

static emlrtRTEInfo sl_emlrtRTEI = { 305,// lineNo
  14,                                  // colNo
  "cat",                               // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/cat.m"// pName
};

static emlrtRTEInfo tl_emlrtRTEI = { 79,// lineNo
  1,                                   // colNo
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m"// pName
};

static emlrtRTEInfo ul_emlrtRTEI = { 81,// lineNo
  1,                                   // colNo
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m"// pName
};

static emlrtRTEInfo vl_emlrtRTEI = { 83,// lineNo
  12,                                  // colNo
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m"// pName
};

static emlrtRTEInfo wl_emlrtRTEI = { 137,// lineNo
  1,                                   // colNo
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m"// pName
};

static emlrtRTEInfo xl_emlrtRTEI = { 108,// lineNo
  20,                                  // colNo
  "jpdaEvents",                        // fName
  "/usr/local/MATLAB/R2020b/toolbox/fusion/fusion/jpdaEvents.m"// pName
};

// Function Definitions
namespace coder
{
  void jpdaEvents(const emlrtStack *sp, const ::coder::array<real_T, 2U>
                  &validationMatrix, ::coder::array<boolean_T, 3U> &outFJE)
  {
    array<real_T, 2U> c_validationMatrix;
    array<real_T, 2U> z;
    array<real_T, 1U> b_validationMatrix;
    array<int32_T, 2U> ii;
    array<uint32_T, 2U> X;
    array<uint32_T, 2U> Xjs;
    array<boolean_T, 3U> FJE;
    array<boolean_T, 2U> r;
    array<boolean_T, 2U> x;
    array<boolean_T, 1U> b_x;
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack d_st;
    emlrtStack st;
    real_T dv[3];
    real_T d;
    real_T d1;
    real_T d2;
    real_T d3;
    real_T n1;
    real_T nFJE;
    int32_T i;
    int32_T i1;
    int32_T i2;
    int32_T k;
    int32_T loop_ub;
    int32_T nM;
    int32_T nT;
    int32_T numMeas;
    uint32_T L;
    uint32_T Xj;
    uint32_T j;
    uint32_T q0;
    boolean_T exitg1;
    boolean_T p;
    st.prev = sp;
    st.tls = sp->tls;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    d_st.prev = &c_st;
    d_st.tls = c_st.tls;
    emlrtHeapReferenceStackEnterFcnR2012b(sp);
    st.site = &ngb_emlrtRSI;
    b_st.site = &yb_emlrtRSI;
    p = true;
    i = validationMatrix.size(0) * validationMatrix.size(1);
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= i - 1)) {
      if ((validationMatrix[k] == 0.0) || (validationMatrix[k] == 1.0)) {
        k++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &rc_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedBinary",
        "MATLAB:jpdaEvents:expectedBinary", 3, 4, 16, "validationMatrix");
    }

    b_st.site = &yb_emlrtRSI;
    if ((validationMatrix.size(0) == 0) || (validationMatrix.size(1) == 0)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &sc_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonempty",
        "MATLAB:jpdaEvents:expectedNonempty", 3, 4, 16, "validationMatrix");
    }

    numMeas = validationMatrix.size(0);
    if (validationMatrix.size(1) <= 1) {
      emlrtErrorWithMessageIdR2018a(sp, &qc_emlrtRTEI,
        "fusion:jpdaEvents:expectedMoreColumns",
        "fusion:jpdaEvents:expectedMoreColumns", 0);
    }

    loop_ub = validationMatrix.size(0);
    b_validationMatrix.set_size(&pl_emlrtRTEI, sp, validationMatrix.size(0));
    for (i = 0; i < loop_ub; i++) {
      b_validationMatrix[i] = validationMatrix[i];
    }

    st.site = &mgb_emlrtRSI;
    if (!(sum(&st, b_validationMatrix) == validationMatrix.size(0))) {
      emlrtErrorWithMessageIdR2018a(sp, &pc_emlrtRTEI,
        "fusion:jpdaEvents:expectedAllOnes", "fusion:jpdaEvents:expectedAllOnes",
        0);
    }

    if (validationMatrix.size(1) < 1) {
      emlrtDynamicBoundsCheckR2012b(validationMatrix.size(1), 1,
        validationMatrix.size(1), &gg_emlrtBCI, sp);
    }

    st.site = &lgb_emlrtRSI;
    loop_ub = validationMatrix.size(0);
    nM = validationMatrix.size(1) - 2;
    c_validationMatrix.set_size(&ql_emlrtRTEI, &st, validationMatrix.size(0),
      validationMatrix.size(1) - 1);
    for (i = 0; i <= nM; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        c_validationMatrix[i1 + c_validationMatrix.size(0) * i] =
          validationMatrix[i1 + validationMatrix.size(0) * (i + 1)];
      }
    }

    b_st.site = &lgb_emlrtRSI;
    sum(&b_st, c_validationMatrix, z);
    x.set_size(&rl_emlrtRTEI, &st, 1, z.size(1));
    loop_ub = z.size(0) * z.size(1);
    for (i = 0; i < loop_ub; i++) {
      x[i] = (z[i] > 0.0);
    }

    b_st.site = &tj_emlrtRSI;
    p = true;
    c_st.site = &uj_emlrtRSI;
    if ((1 <= x.size(1)) && (x.size(1) > 2147483646)) {
      d_st.site = &jc_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    nT = 1;
    exitg1 = false;
    while ((!exitg1) && (nT <= x.size(1))) {
      if (!x[nT - 1]) {
        p = false;
        exitg1 = true;
      } else {
        nT++;
      }
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(sp, &oc_emlrtRTEI,
        "fusion:jpdaEvents:expectedNonzeroColumn",
        "fusion:jpdaEvents:expectedNonzeroColumn", 0);
    }

    st.site = &kgb_emlrtRSI;
    n1 = 1.0;
    if (validationMatrix.size(0) > validationMatrix.size(1)) {
      nT = validationMatrix.size(1);
    } else {
      nT = validationMatrix.size(0);
    }

    if (validationMatrix.size(0) < validationMatrix.size(1)) {
      nM = validationMatrix.size(1);
    } else {
      nM = validationMatrix.size(0);
    }

    for (k = 0; k < nT; k++) {
      nFJE = nT;
      b_st.site = &pu_emlrtRSI;
      factorial(&b_st, &nFJE);
      d = nT - k;
      b_st.site = &pu_emlrtRSI;
      factorial(&b_st, &d);
      d1 = nM;
      b_st.site = &pu_emlrtRSI;
      factorial(&b_st, &d1);
      d2 = static_cast<real_T>(nM - nT) + static_cast<real_T>(k);
      b_st.site = &pu_emlrtRSI;
      factorial(&b_st, &d2);
      d3 = k;
      b_st.site = &pu_emlrtRSI;
      factorial(&b_st, &d3);
      n1 += nFJE / d * d1 / d2 / d3;
    }

    st.site = &jgb_emlrtRSI;
    sum(&st, validationMatrix, b_validationMatrix);
    st.site = &jgb_emlrtRSI;
    nFJE = prod(&st, b_validationMatrix);
    st.site = &igb_emlrtRSI;
    b_st.site = &aeb_emlrtRSI;
    nT = validationMatrix.size(0);
    c_st.site = &beb_emlrtRSI;
    r.set_size(&sl_emlrtRTEI, sp, validationMatrix.size(0),
               validationMatrix.size(1));
    for (i = 0; i < 1; i++) {
      for (i1 = 0; i1 < nT; i1++) {
        r[i1] = true;
      }
    }

    loop_ub = validationMatrix.size(1) - 1;
    for (i = 0; i < loop_ub; i++) {
      for (i1 = 0; i1 < nT; i1++) {
        r[i1 + r.size(0) * (i + 1)] = false;
      }
    }

    dv[0] = 1.0;
    dv[1] = 1.0;
    dv[2] = muDoubleScalarMin(n1, nFJE);
    st.site = &hgb_emlrtRSI;
    b_repmat(&st, r, dv, FJE);
    Xj = 0U;
    nT = static_cast<int32_T>(muDoubleScalarMin(static_cast<real_T>
      (validationMatrix.size(1)) - 1.0, static_cast<real_T>
      (validationMatrix.size(0)))) + 1;
    X.set_size(&tl_emlrtRTEI, sp, nT, 2);
    loop_ub = nT << 1;
    for (i = 0; i < loop_ub; i++) {
      X[i] = 0U;
    }

    Xjs.set_size(&ul_emlrtRTEI, sp, validationMatrix.size(0),
                 validationMatrix.size(1));
    loop_ub = validationMatrix.size(0) * validationMatrix.size(1);
    for (i = 0; i < loop_ub; i++) {
      Xjs[i] = 0U;
    }

    i = validationMatrix.size(0);
    for (nT = 0; nT < i; nT++) {
      st.site = &ggb_emlrtRSI;
      i1 = nT + 1;
      if ((i1 < 1) || (i1 > validationMatrix.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, validationMatrix.size(0),
          &fg_emlrtBCI, &st);
      }

      loop_ub = validationMatrix.size(1);
      x.set_size(&vl_emlrtRTEI, &st, 1, validationMatrix.size(1));
      for (i1 = 0; i1 < loop_ub; i1++) {
        x[i1] = (validationMatrix[nT + validationMatrix.size(0) * i1] != 0.0);
      }

      b_st.site = &jf_emlrtRSI;
      b_eml_find(&b_st, x, ii);
      z.set_size(&si_emlrtRTEI, sp, 1, ii.size(1));
      loop_ub = ii.size(0) * ii.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        z[i1] = static_cast<real_T>(ii[i1]) - 1.0;
      }

      i1 = validationMatrix.size(1);
      for (k = 0; k < i1; k++) {
        st.site = &su_emlrtRSI;
        x.set_size(&ti_emlrtRTEI, &st, 1, z.size(1));
        loop_ub = z.size(0) * z.size(1);
        for (i2 = 0; i2 < loop_ub; i2++) {
          x[i2] = (z[i2] > k);
        }

        b_st.site = &jf_emlrtRSI;
        b_eml_find(&b_st, x, ii);
        if (ii.size(1) == 0) {
          if ((nT + 1 < 1) || (nT + 1 > Xjs.size(0))) {
            emlrtDynamicBoundsCheckR2012b(nT + 1, 1, Xjs.size(0), &mg_emlrtBCI,
              sp);
          }

          if ((k + 1 < 1) || (k + 1 > Xjs.size(1))) {
            emlrtDynamicBoundsCheckR2012b(k + 1, 1, Xjs.size(1), &mg_emlrtBCI,
              sp);
          }

          Xjs[nT + Xjs.size(0) * k] = 0U;
        } else {
          if ((ii[0] < 1) || (ii[0] > z.size(1))) {
            emlrtDynamicBoundsCheckR2012b(ii[0], 1, z.size(1), &cd_emlrtBCI, sp);
          }

          if ((nT + 1 < 1) || (nT + 1 > Xjs.size(0))) {
            emlrtDynamicBoundsCheckR2012b(nT + 1, 1, Xjs.size(0), &og_emlrtBCI,
              sp);
          }

          if ((k + 1 < 1) || (k + 1 > Xjs.size(1))) {
            emlrtDynamicBoundsCheckR2012b(k + 1, 1, Xjs.size(1), &og_emlrtBCI,
              sp);
          }

          nFJE = muDoubleScalarRound(z[ii[0] - 1]);
          if (nFJE < 4.294967296E+9) {
            if (nFJE >= 0.0) {
              q0 = static_cast<uint32_T>(nFJE);
            } else {
              q0 = 0U;
            }
          } else if (nFJE >= 4.294967296E+9) {
            q0 = MAX_uint32_T;
          } else {
            q0 = 0U;
          }

          Xjs[nT + Xjs.size(0) * k] = q0;
        }
      }
    }

    L = 0U;
    j = 1U;
    nFJE = 1.0;
    while (j <= static_cast<uint32_T>(numMeas)) {
      while ((static_cast<int32_T>(L) < static_cast<int32_T>(muDoubleScalarMin(
                static_cast<real_T>(validationMatrix.size(1)) - 1.0,
                static_cast<real_T>(numMeas)))) && (j <= static_cast<uint32_T>
              (numMeas))) {
        uint32_T qY;
        if ((static_cast<int32_T>(j) < 1) || (static_cast<int32_T>(j) > Xjs.size
             (0))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j), 1, Xjs.size(0),
            &hg_emlrtBCI, sp);
        }

        qY = Xj + 1U;
        if (Xj + 1U < Xj) {
          qY = MAX_uint32_T;
        }

        if ((static_cast<int32_T>(qY) < 1) || (static_cast<int32_T>(qY) >
             Xjs.size(1))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(qY), 1, Xjs.size(1),
            &hg_emlrtBCI, sp);
        }

        Xj = Xjs[(static_cast<int32_T>(j) + Xjs.size(0) * (static_cast<int32_T>
                   (qY) - 1)) - 1];
        if (Xj == 0U) {
          Xj = 0U;
          j++;
        } else {
          st.site = &fgb_emlrtRSI;
          loop_ub = X.size(0);
          b_x.set_size(&xl_emlrtRTEI, &st, X.size(0));
          for (i = 0; i < loop_ub; i++) {
            b_x[i] = (X[i + X.size(0)] == Xj);
          }

          b_st.site = &sgb_emlrtRSI;
          p = false;
          c_st.site = &uj_emlrtRSI;
          if (b_x.size(0) > 2147483646) {
            d_st.site = &jc_emlrtRSI;
            check_forloop_overflow_error(&d_st);
          }

          nT = 1;
          exitg1 = false;
          while ((!exitg1) && (nT <= b_x.size(0))) {
            if (!b_x[nT - 1]) {
              nT++;
            } else {
              p = true;
              exitg1 = true;
            }
          }

          if (!p) {
            L++;
            if ((static_cast<int32_T>(L) < 1) || (static_cast<int32_T>(L) >
                 X.size(0))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(L), 1, X.size(0),
                &ng_emlrtBCI, sp);
            }

            X[static_cast<int32_T>(L) - 1] = j;
            if ((static_cast<int32_T>(L) < 1) || (static_cast<int32_T>(L) >
                 X.size(0))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(L), 1, X.size(0),
                &pg_emlrtBCI, sp);
            }

            X[(static_cast<int32_T>(L) + X.size(0)) - 1] = Xj;
            j++;
            nFJE++;
            i = static_cast<int32_T>(L);
            for (k = 0; k < i; k++) {
              if (1 > FJE.size(1)) {
                emlrtDynamicBoundsCheckR2012b(1, 1, FJE.size(1), &eg_emlrtBCI,
                  sp);
              }

              if ((static_cast<int32_T>(k + 1U) < 1) || (static_cast<int32_T>(k
                    + 1U) > X.size(0))) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(k + 1U), 1,
                  X.size(0), &qg_emlrtBCI, sp);
              }

              i1 = static_cast<int32_T>(X[k]);
              if ((i1 < 1) || (i1 > FJE.size(0))) {
                emlrtDynamicBoundsCheckR2012b(i1, 1, FJE.size(0), &qg_emlrtBCI,
                  sp);
              }

              if ((static_cast<int32_T>(nFJE) < 1) || (static_cast<int32_T>(nFJE)
                   > FJE.size(2))) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nFJE), 1,
                  FJE.size(2), &qg_emlrtBCI, sp);
              }

              FJE[(i1 + FJE.size(0) * FJE.size(1) * (static_cast<int32_T>(nFJE)
                    - 1)) - 1] = false;
              if ((static_cast<int32_T>(k + 1U) < 1) || (static_cast<int32_T>(k
                    + 1U) > X.size(0))) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(k + 1U), 1,
                  X.size(0), &rg_emlrtBCI, sp);
              }

              i1 = static_cast<int32_T>(X[k]);
              if ((i1 < 1) || (i1 > FJE.size(0))) {
                emlrtDynamicBoundsCheckR2012b(i1, 1, FJE.size(0), &rg_emlrtBCI,
                  sp);
              }

              if ((static_cast<int32_T>(k + 1U) < 1) || (static_cast<int32_T>(k
                    + 1U) > X.size(0))) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(k + 1U), 1,
                  X.size(0), &rg_emlrtBCI, sp);
              }

              q0 = X[k + X.size(0)];
              qY = q0 + 1U;
              if (q0 + 1U < q0) {
                qY = MAX_uint32_T;
              }

              if ((static_cast<int32_T>(qY) < 1) || (static_cast<int32_T>(qY) >
                   FJE.size(1))) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(qY), 1,
                  FJE.size(1), &rg_emlrtBCI, sp);
              }

              if ((static_cast<int32_T>(nFJE) < 1) || (static_cast<int32_T>(nFJE)
                   > FJE.size(2))) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nFJE), 1,
                  FJE.size(2), &rg_emlrtBCI, sp);
              }

              FJE[((i1 + FJE.size(0) * (static_cast<int32_T>(qY) - 1)) +
                   FJE.size(0) * FJE.size(1) * (static_cast<int32_T>(nFJE) - 1))
                - 1] = true;
            }

            Xj = 0U;
          }
        }
      }

      if (static_cast<int32_T>(L) >= 1) {
        if ((static_cast<int32_T>(L) < 1) || (static_cast<int32_T>(L) > X.size(0)))
        {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(L), 1, X.size(0),
            &ig_emlrtBCI, sp);
        }

        j = X[static_cast<int32_T>(L) - 1];
        if ((static_cast<int32_T>(L) < 1) || (static_cast<int32_T>(L) > X.size(0)))
        {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(L), 1, X.size(0),
            &jg_emlrtBCI, sp);
        }

        Xj = X[(static_cast<int32_T>(L) + X.size(0)) - 1];
        if ((static_cast<int32_T>(L) < 1) || (static_cast<int32_T>(L) > X.size(0)))
        {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(L), 1, X.size(0),
            &kg_emlrtBCI, sp);
        }

        X[static_cast<int32_T>(L) - 1] = 0U;
        if ((static_cast<int32_T>(L) < 1) || (static_cast<int32_T>(L) > X.size(0)))
        {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(L), 1, X.size(0),
            &lg_emlrtBCI, sp);
        }

        X[(static_cast<int32_T>(L) + X.size(0)) - 1] = 0U;
        L--;
      }
    }

    if (1 > FJE.size(2)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, FJE.size(2), &dg_emlrtBCI, sp);
    }

    if ((static_cast<int32_T>(nFJE) < 1) || (static_cast<int32_T>(nFJE) >
         FJE.size(2))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nFJE), 1, FJE.size(2),
        &cg_emlrtBCI, sp);
    }

    loop_ub = FJE.size(0);
    nM = FJE.size(1);
    nT = static_cast<int32_T>(nFJE);
    outFJE.set_size(&wl_emlrtRTEI, sp, FJE.size(0), FJE.size(1),
                    static_cast<int32_T>(nFJE));
    for (i = 0; i < nT; i++) {
      for (i1 = 0; i1 < nM; i1++) {
        for (i2 = 0; i2 < loop_ub; i2++) {
          outFJE[(i2 + outFJE.size(0) * i1) + outFJE.size(0) * outFJE.size(1) *
            i] = FJE[(i2 + FJE.size(0) * i1) + FJE.size(0) * FJE.size(1) * i];
        }
      }
    }

    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  }
}

// End of code generation (jpdaEvents.cpp)
