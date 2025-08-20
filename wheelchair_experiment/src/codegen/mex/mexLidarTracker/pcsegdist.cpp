//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  pcsegdist.cpp
//
//  Code generation for function 'pcsegdist'
//


// Include files
#include "pcsegdist.h"
#include "mexLidarTracker_data.h"
#include "pointCloud.h"
#include "rt_nonfinite.h"
#include "unique.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo im_emlrtRSI = { 85, // lineNo
  "pcsegdist",                         // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m"// pathName
};

static emlrtRSInfo jm_emlrtRSI = { 105,// lineNo
  "pcsegdist",                         // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m"// pathName
};

static emlrtRSInfo km_emlrtRSI = { 107,// lineNo
  "pcsegdist",                         // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m"// pathName
};

static emlrtRSInfo lm_emlrtRSI = { 114,// lineNo
  "pcsegdist",                         // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m"// pathName
};

static emlrtRSInfo mm_emlrtRSI = { 139,// lineNo
  "pcsegdist",                         // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m"// pathName
};

static emlrtRSInfo nm_emlrtRSI = { 150,// lineNo
  "pcsegdist",                         // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m"// pathName
};

static emlrtRSInfo om_emlrtRSI = { 102,// lineNo
  "pcsegdist",                         // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m"// pathName
};

static emlrtBCInfo eb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  114,                                 // lineNo
  53,                                  // colNo
  "",                                  // aName
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo fb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  120,                                 // lineNo
  28,                                  // colNo
  "",                                  // aName
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo gb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  122,                                 // lineNo
  28,                                  // colNo
  "",                                  // aName
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m",// pName
  0                                    // checkKind
};

static emlrtRTEInfo nb_emlrtRTEI = { 143,// lineNo
  13,                                  // colNo
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m"// pName
};

static emlrtBCInfo hb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  144,                                 // lineNo
  29,                                  // colNo
  "",                                  // aName
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m",// pName
  0                                    // checkKind
};

static emlrtECInfo j_emlrtECI = { -1,  // nDims
  146,                                 // lineNo
  5,                                   // colNo
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m"// pName
};

static emlrtBCInfo ib_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  109,                                 // lineNo
  12,                                  // colNo
  "",                                  // aName
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo jb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  132,                                 // lineNo
  12,                                  // colNo
  "",                                  // aName
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo kb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  117,                                 // lineNo
  17,                                  // colNo
  "",                                  // aName
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo lb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  118,                                 // lineNo
  16,                                  // colNo
  "",                                  // aName
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo mb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  146,                                 // lineNo
  12,                                  // colNo
  "",                                  // aName
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo nb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  118,                                 // lineNo
  28,                                  // colNo
  "",                                  // aName
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ob_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  134,                                 // lineNo
  15,                                  // colNo
  "",                                  // aName
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo pb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  125,                                 // lineNo
  20,                                  // colNo
  "",                                  // aName
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo qb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  119,                                 // lineNo
  20,                                  // colNo
  "",                                  // aName
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo rb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  119,                                 // lineNo
  27,                                  // colNo
  "",                                  // aName
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo sb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  127,                                 // lineNo
  24,                                  // colNo
  "",                                  // aName
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo tb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  126,                                 // lineNo
  28,                                  // colNo
  "",                                  // aName
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ub_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  126,                                 // lineNo
  21,                                  // colNo
  "",                                  // aName
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo vb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  121,                                 // lineNo
  24,                                  // colNo
  "",                                  // aName
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo wb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  121,                                 // lineNo
  31,                                  // colNo
  "",                                  // aName
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo xb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  128,                                 // lineNo
  28,                                  // colNo
  "",                                  // aName
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo yb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  128,                                 // lineNo
  21,                                  // colNo
  "",                                  // aName
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ac_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  144,                                 // lineNo
  9,                                   // colNo
  "",                                  // aName
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo bc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  120,                                 // lineNo
  34,                                  // colNo
  "",                                  // aName
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo cc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  122,                                 // lineNo
  34,                                  // colNo
  "",                                  // aName
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo dc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  120,                                 // lineNo
  21,                                  // colNo
  "",                                  // aName
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ec_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  122,                                 // lineNo
  21,                                  // colNo
  "",                                  // aName
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m",// pName
  0                                    // checkKind
};

static emlrtRTEInfo dh_emlrtRTEI = { 98,// lineNo
  5,                                   // colNo
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m"// pName
};

static emlrtRTEInfo eh_emlrtRTEI = { 105,// lineNo
  5,                                   // colNo
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m"// pName
};

static emlrtRTEInfo fh_emlrtRTEI = { 1,// lineNo
  34,                                  // colNo
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m"// pName
};

static emlrtRTEInfo gh_emlrtRTEI = { 134,// lineNo
  15,                                  // colNo
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m"// pName
};

static emlrtRTEInfo hh_emlrtRTEI = { 146,// lineNo
  12,                                  // colNo
  "pcsegdist",                         // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcsegdist.m"// pName
};

// Function Definitions
namespace coder
{
  void pcsegdist(const emlrtStack *sp, b_pointCloud *ptCloud, real_T minDistance,
                 ::coder::array<uint32_T, 1U> &labels, real32_T *numClusters)
  {
    b_pointCloud pc;
    b_pointCloud *b_pc;
    array<real_T, 1U> validIndices;
    array<int32_T, 1U> r1;
    array<int32_T, 1U> r2;
    array<int32_T, 1U> r3;
    array<uint32_T, 1U> L;
    array<uint32_T, 1U> ind;
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack st;
    real_T d;
    real_T newLabel;
    int32_T b_i;
    int32_T end;
    int32_T i;
    int32_T i1;
    int32_T k;
    int32_T labelsSize_idx_0;
    int32_T loop_ub;
    real32_T c_pc[3];
    uint32_T u;
    boolean_T b;
    boolean_T p;
    st.prev = sp;
    st.tls = sp->tls;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    emlrtHeapReferenceStackEnterFcnR2012b(sp);
    pc.matlabCodegenIsDeleted = true;
    st.site = &im_emlrtRSI;
    b_st.site = &yb_emlrtRSI;
    b = muDoubleScalarIsNaN(minDistance);
    p = !b;
    if (!p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &u_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:pcsegdist:expectedNonNaN", 3, 4, 11, "minDistance");
    }

    b_st.site = &yb_emlrtRSI;
    p = !(minDistance <= 0.0);
    if (!p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &y_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:pcsegdist:expectedPositive", 3, 4, 11, "minDistance");
    }

    b_st.site = &yb_emlrtRSI;
    p = ((!muDoubleScalarIsInf(minDistance)) && (!b));
    if (!p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:pcsegdist:expectedFinite", 3, 4, 11, "minDistance");
    }

    labelsSize_idx_0 = ptCloud->Location.size(0);
    labels.set_size(&dh_emlrtRTEI, sp, labelsSize_idx_0);
    for (i = 0; i < labelsSize_idx_0; i++) {
      labels[i] = 0U;
    }

    st.site = &om_emlrtRSI;
    ptCloud->removeInvalidPoints(&st, &pc, &b_pc, validIndices);
    st.site = &jm_emlrtRSI;
    d = pc.get_Count();
    L.set_size(&eh_emlrtRTEI, &st, static_cast<int32_T>(d));
    loop_ub = static_cast<int32_T>(d);
    for (i = 0; i < loop_ub; i++) {
      L[i] = 0U;
    }

    newLabel = 0.0;
    b_st.site = &km_emlrtRSI;
    d = pc.get_Count();
    i = static_cast<int32_T>(d);
    for (b_i = 0; b_i < i; b_i++) {
      if ((static_cast<int32_T>(b_i + 1U) < 1) || (static_cast<int32_T>(b_i + 1U)
           > L.size(0))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_i + 1U), 1, L.size
          (0), &ib_emlrtBCI, &st);
      }

      if (L[b_i] == 0U) {
        i1 = pc.Location.size(0);
        if ((static_cast<int32_T>(b_i + 1U) < 1) || (static_cast<int32_T>(b_i +
              1U) > i1)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_i + 1U), 1, i1,
            &eb_emlrtBCI, &st);
        }

        c_pc[0] = pc.Location[b_i];
        c_pc[1] = pc.Location[b_i + pc.Location.size(0)];
        c_pc[2] = pc.Location[b_i + pc.Location.size(0) * 2];
        b_st.site = &lm_emlrtRSI;
        pc.findNeighborsInRadius(&b_st, c_pc, static_cast<real32_T>(minDistance),
          ind);
        i1 = ind.size(0);
        for (k = 0; k < i1; k++) {
          int32_T c_i;
          uint32_T b_L;
          uint32_T j;
          boolean_T guard1 = false;
          if ((k + 1 < 1) || (k + 1 > ind.size(0))) {
            emlrtDynamicBoundsCheckR2012b(k + 1, 1, ind.size(0), &kb_emlrtBCI,
              &st);
          }

          j = ind[k];
          if ((static_cast<int32_T>(ind[k]) < 1) || (static_cast<int32_T>(ind[k])
               > L.size(0))) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(ind[k]), 1,
              L.size(0), &lb_emlrtBCI, &st);
          }

          c_i = static_cast<int32_T>(ind[k]) - 1;
          b_L = L[c_i];
          guard1 = false;
          if (b_L > 0U) {
            if ((static_cast<int32_T>(b_i + 1U) < 1) || (static_cast<int32_T>
                 (b_i + 1U) > L.size(0))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_i + 1U), 1,
                L.size(0), &nb_emlrtBCI, &st);
            }

            if (L[b_i] > 0U) {
              if ((static_cast<int32_T>(ind[k]) < 1) || (static_cast<int32_T>
                   (ind[k]) > L.size(0))) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(ind[k]), 1,
                  L.size(0), &qb_emlrtBCI, &st);
              }

              if ((static_cast<int32_T>(b_i + 1U) < 1) || (static_cast<int32_T>
                   (b_i + 1U) > L.size(0))) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_i + 1U), 1,
                  L.size(0), &rb_emlrtBCI, &st);
              }

              if (b_L > L[b_i]) {
                if ((static_cast<int32_T>(ind[k]) < 1) || (static_cast<int32_T>
                     (ind[k]) > L.size(0))) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(ind[k]), 1,
                    L.size(0), &fb_emlrtBCI, &st);
                }

                end = L.size(0) - 1;
                loop_ub = 0;
                for (c_i = 0; c_i <= end; c_i++) {
                  if (L[c_i] == L[static_cast<int32_T>(j) - 1]) {
                    loop_ub++;
                  }
                }

                r3.set_size(&fh_emlrtRTEI, &st, loop_ub);
                loop_ub = 0;
                for (c_i = 0; c_i <= end; c_i++) {
                  if (L[c_i] == L[static_cast<int32_T>(j) - 1]) {
                    r3[loop_ub] = c_i + 1;
                    loop_ub++;
                  }
                }

                if ((static_cast<int32_T>(b_i + 1U) < 1) || (static_cast<int32_T>
                     (b_i + 1U) > L.size(0))) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_i + 1U),
                    1, L.size(0), &bc_emlrtBCI, &st);
                }

                b_L = L[b_i];
                end = L.size(0);
                loop_ub = r3.size(0);
                for (c_i = 0; c_i < loop_ub; c_i++) {
                  if ((r3[c_i] < 1) || (r3[c_i] > end)) {
                    emlrtDynamicBoundsCheckR2012b(r3[c_i], 1, end, &dc_emlrtBCI,
                      &st);
                  }

                  L[r3[c_i] - 1] = b_L;
                }
              } else {
                if ((static_cast<int32_T>(ind[k]) < 1) || (static_cast<int32_T>
                     (ind[k]) > L.size(0))) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(ind[k]), 1,
                    L.size(0), &vb_emlrtBCI, &st);
                }

                if ((static_cast<int32_T>(b_i + 1U) < 1) || (static_cast<int32_T>
                     (b_i + 1U) > L.size(0))) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_i + 1U),
                    1, L.size(0), &wb_emlrtBCI, &st);
                }

                if (b_L < L[b_i]) {
                  c_i = b_i + 1;
                  if ((c_i < 1) || (c_i > L.size(0))) {
                    emlrtDynamicBoundsCheckR2012b(c_i, 1, L.size(0),
                      &gb_emlrtBCI, &st);
                  }

                  end = L.size(0) - 1;
                  loop_ub = 0;
                  for (c_i = 0; c_i <= end; c_i++) {
                    if (L[c_i] == L[b_i]) {
                      loop_ub++;
                    }
                  }

                  r1.set_size(&fh_emlrtRTEI, &st, loop_ub);
                  loop_ub = 0;
                  for (c_i = 0; c_i <= end; c_i++) {
                    if (L[c_i] == L[b_i]) {
                      r1[loop_ub] = c_i + 1;
                      loop_ub++;
                    }
                  }

                  if ((static_cast<int32_T>(ind[k]) < 1) || (static_cast<int32_T>
                       (ind[k]) > L.size(0))) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(ind[k]),
                      1, L.size(0), &cc_emlrtBCI, &st);
                  }

                  end = L.size(0);
                  loop_ub = r1.size(0);
                  for (c_i = 0; c_i < loop_ub; c_i++) {
                    if ((r1[c_i] < 1) || (r1[c_i] > end)) {
                      emlrtDynamicBoundsCheckR2012b(r1[c_i], 1, end,
                        &ec_emlrtBCI, &st);
                    }

                    L[r1[c_i] - 1] = b_L;
                  }
                }
              }
            } else {
              guard1 = true;
            }
          } else {
            guard1 = true;
          }

          if (guard1) {
            if ((static_cast<int32_T>(ind[k]) < 1) || (static_cast<int32_T>
                 (ind[k]) > L.size(0))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(ind[k]), 1,
                L.size(0), &pb_emlrtBCI, &st);
            }

            if (b_L > 0U) {
              if ((static_cast<int32_T>(ind[k]) < 1) || (static_cast<int32_T>
                   (ind[k]) > L.size(0))) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(ind[k]), 1,
                  L.size(0), &tb_emlrtBCI, &st);
              }

              if ((static_cast<int32_T>(b_i + 1U) < 1) || (static_cast<int32_T>
                   (b_i + 1U) > L.size(0))) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_i + 1U), 1,
                  L.size(0), &ub_emlrtBCI, &st);
              }

              L[b_i] = b_L;
            } else {
              if ((static_cast<int32_T>(b_i + 1U) < 1) || (static_cast<int32_T>
                   (b_i + 1U) > L.size(0))) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_i + 1U), 1,
                  L.size(0), &sb_emlrtBCI, &st);
              }

              if (L[b_i] > 0U) {
                if ((static_cast<int32_T>(b_i + 1U) < 1) || (static_cast<int32_T>
                     (b_i + 1U) > L.size(0))) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_i + 1U),
                    1, L.size(0), &xb_emlrtBCI, &st);
                }

                if ((static_cast<int32_T>(ind[k]) < 1) || (static_cast<int32_T>
                     (ind[k]) > L.size(0))) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(ind[k]), 1,
                    L.size(0), &yb_emlrtBCI, &st);
                }

                L[c_i] = L[b_i];
              }
            }
          }
        }

        if ((static_cast<int32_T>(b_i + 1U) < 1) || (static_cast<int32_T>(b_i +
              1U) > L.size(0))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_i + 1U), 1,
            L.size(0), &jb_emlrtBCI, &st);
        }

        if (L[b_i] == 0U) {
          newLabel++;
          r2.set_size(&gh_emlrtRTEI, &st, ind.size(0));
          loop_ub = ind.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            if ((static_cast<int32_T>(ind[i1]) < 1) || (static_cast<int32_T>
                 (ind[i1]) > L.size(0))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(ind[i1]), 1,
                L.size(0), &ob_emlrtBCI, &st);
            }

            r2[i1] = static_cast<int32_T>(ind[i1]);
          }

          loop_ub = r2.size(0);
          if (0 <= loop_ub - 1) {
            if (newLabel < 4.294967296E+9) {
              u = static_cast<uint32_T>(newLabel);
            } else {
              u = MAX_uint32_T;
            }
          }

          for (i1 = 0; i1 < loop_ub; i1++) {
            L[r2[i1] - 1] = u;
          }
        }
      }
    }

    b_st.site = &mm_emlrtRSI;
    c_st.site = &gn_emlrtRSI;
    unique_vector(&c_st, L, ind);
    *numClusters = static_cast<real32_T>(ind.size(0));
    i = static_cast<int32_T>(static_cast<real32_T>(ind.size(0)));
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, static_cast<real_T>
      (static_cast<real32_T>(ind.size(0))), mxSINGLE_CLASS, static_cast<int32_T>
      (static_cast<real32_T>(ind.size(0))), &nb_emlrtRTEI, &st);
    for (k = 0; k < i; k++) {
      if ((static_cast<int32_T>(static_cast<real32_T>(k) + 1.0F) < 1) || (
           static_cast<int32_T>(static_cast<real32_T>(k) + 1.0F) > ind.size(0)))
      {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(static_cast<real32_T>
          (k) + 1.0F), 1, ind.size(0), &hb_emlrtBCI, &st);
      }

      end = L.size(0);
      for (b_i = 0; b_i < end; b_i++) {
        if (L[b_i] == ind[static_cast<int32_T>(static_cast<real32_T>(k) + 1.0F)
            - 1]) {
          if ((b_i + 1 < 1) || (b_i + 1 > L.size(0))) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, L.size(0), &ac_emlrtBCI,
              &st);
          }

          L[b_i] = static_cast<uint32_T>(static_cast<real32_T>(k) + 1.0F);
        }
      }
    }

    r1.set_size(&hh_emlrtRTEI, &st, validIndices.size(0));
    loop_ub = validIndices.size(0);
    for (i = 0; i < loop_ub; i++) {
      i1 = static_cast<int32_T>(validIndices[i]);
      if ((i1 < 1) || (i1 > labelsSize_idx_0)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, labelsSize_idx_0, &mb_emlrtBCI, &st);
      }

      r1[i] = i1;
    }

    if (r1.size(0) != L.size(0)) {
      emlrtSubAssignSizeCheck1dR2017a(r1.size(0), L.size(0), &j_emlrtECI, &st);
    }

    loop_ub = L.size(0);
    for (i = 0; i < loop_ub; i++) {
      labels[r1[i] - 1] = L[i];
    }

    b_st.site = &nm_emlrtRSI;
    pc.matlabCodegenDestructor();
    emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  }
}

// End of code generation (pcsegdist.cpp)
