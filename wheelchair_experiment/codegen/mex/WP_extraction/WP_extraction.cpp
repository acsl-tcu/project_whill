//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// WP_extraction.cpp
//
// Code generation for function 'WP_extraction'
//

// Include files
#include "WP_extraction.h"
#include "WP_extraction_data.h"
#include "WP_extraction_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "inpolygon.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo emlrtRSI{
    14,              // lineNo
    "WP_extraction", // fcnName
    "C:\\Users\\kwgc1\\OneDrive - "
    "tcu.ac.jp\\jikki0914\\program\\WP_extraction.m" // pathName
};

static emlrtRSInfo b_emlrtRSI{
    15,              // lineNo
    "WP_extraction", // fcnName
    "C:\\Users\\kwgc1\\OneDrive - "
    "tcu.ac.jp\\jikki0914\\program\\WP_extraction.m" // pathName
};

static emlrtRSInfo c_emlrtRSI{
    26,          // lineNo
    "inpolygon", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m" // pathName
};

static emlrtRSInfo d_emlrtRSI{
    31,          // lineNo
    "inpolygon", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m" // pathName
};

static emlrtRSInfo e_emlrtRSI{
    32,          // lineNo
    "inpolygon", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m" // pathName
};

static emlrtRSInfo f_emlrtRSI{
    33,          // lineNo
    "inpolygon", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m" // pathName
};

static emlrtRSInfo g_emlrtRSI{
    35,          // lineNo
    "inpolygon", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m" // pathName
};

static emlrtRSInfo h_emlrtRSI{
    58,          // lineNo
    "inpolygon", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m" // pathName
};

static emlrtRSInfo i_emlrtRSI{
    234,          // lineNo
    "countLoops", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m" // pathName
};

static emlrtRSInfo j_emlrtRSI{
    239,          // lineNo
    "countLoops", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m" // pathName
};

static emlrtRSInfo k_emlrtRSI{
    251,          // lineNo
    "countLoops", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m" // pathName
};

static emlrtRSInfo n_emlrtRSI{
    317,          // lineNo
    "checkRange", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m" // pathName
};

static emlrtRSInfo o_emlrtRSI{
    320,          // lineNo
    "checkRange", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m" // pathName
};

static emlrtRSInfo p_emlrtRSI{
    194,                   // lineNo
    "computeScaleFactors", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m" // pathName
};

static emlrtRSInfo q_emlrtRSI{
    99,                // lineNo
    "scalarInpolygon", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m" // pathName
};

static emlrtRSInfo r_emlrtRSI{
    26,    // lineNo
    "cat", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m" // pathName
};

static emlrtRSInfo s_emlrtRSI{
    100,        // lineNo
    "cat_impl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m" // pathName
};

static emlrtRTEInfo emlrtRTEI{
    263,        // lineNo
    27,         // colNo
    "skipNaNs", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m" // pName
};

static emlrtRTEInfo b_emlrtRTEI{
    282,        // lineNo
    31,         // colNo
    "findLast", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m" // pName
};

static emlrtBCInfo emlrtBCI{
    1,               // iFirst
    21,              // iLast
    2,               // lineNo
    11,              // colNo
    "px",            // aName
    "WP_extraction", // fName
    "C:\\Users\\kwgc1\\OneDrive - "
    "tcu.ac.jp\\jikki0914\\program\\WP_extraction.m", // pName
    0                                                 // checkKind
};

static emlrtDCInfo emlrtDCI{
    2,               // lineNo
    11,              // colNo
    "WP_extraction", // fName
    "C:\\Users\\kwgc1\\OneDrive - "
    "tcu.ac.jp\\jikki0914\\program\\WP_extraction.m", // pName
    1                                                 // checkKind
};

static emlrtBCInfo b_emlrtBCI{
    1,               // iFirst
    1000,            // iLast
    2,               // lineNo
    11,              // colNo
    "px",            // aName
    "WP_extraction", // fName
    "C:\\Users\\kwgc1\\OneDrive - "
    "tcu.ac.jp\\jikki0914\\program\\WP_extraction.m", // pName
    0                                                 // checkKind
};

// Function Definitions
void WP_extraction(const emlrtStack *sp, const struct0_T *obj,
                   const real_T px[63000], real_T i, real_T j,
                   real_T WPtemp_data[], int32_T WPtemp_size[2])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T scale[4];
  real_T xv[4];
  real_T yv[4];
  real_T maxxv;
  real_T maxyv;
  real_T minxv;
  real_T minyv;
  real_T xrange;
  real_T xv_tmp;
  real_T yrange;
  int32_T first[4];
  int32_T last[4];
  int32_T b_i;
  int32_T k;
  int32_T kfirst;
  int32_T nloops;
  int8_T tmp_data[15];
  int8_T dquad;
  boolean_T in[15];
  boolean_T exitg1;
  boolean_T isnanxv;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  kfirst =
      3 * (static_cast<int32_T>(i) - 1) + 63 * (static_cast<int32_T>(j) - 1);
  xrange = px[kfirst + 2];
  xv_tmp = muDoubleScalarCos(xrange);
  yrange = muDoubleScalarSin(xrange);
  if (i != static_cast<int32_T>(muDoubleScalarFloor(i))) {
    emlrtIntegerCheckR2012b(i, &emlrtDCI, (emlrtCTX)sp);
  }
  if ((static_cast<int32_T>(i) < 1) || (static_cast<int32_T>(i) > 21)) {
    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(i), 1, 21, &emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (j != static_cast<int32_T>(muDoubleScalarFloor(j))) {
    emlrtIntegerCheckR2012b(j, &emlrtDCI, (emlrtCTX)sp);
  }
  if ((static_cast<int32_T>(j) < 1) || (static_cast<int32_T>(j) > 1000)) {
    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j), 1, 1000, &b_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  xv[0] = px[kfirst] + 5.0 * yrange;
  xv[1] =
      (px[kfirst] + 5.0 * muDoubleScalarSin(px[kfirst + 2])) + 10.0 * xv_tmp;
  xrange = px[kfirst] - 5.0 * muDoubleScalarSin(px[kfirst + 2]);
  xv[2] = xrange + 10.0 * muDoubleScalarCos(px[kfirst + 2]);
  xv[3] = xrange;
  xrange = px[kfirst + 1];
  yv[0] = xrange + 5.0 * xv_tmp;
  yv[1] = (px[kfirst + 1] + 5.0 * muDoubleScalarCos(px[kfirst + 2])) +
          10.0 * yrange;
  xrange -= 5.0 * muDoubleScalarCos(px[kfirst + 2]);
  yv[2] = xrange + 10.0 * muDoubleScalarSin(px[kfirst + 2]);
  yv[3] = xrange;
  st.site = &emlrtRSI;
  for (b_i = 0; b_i < 15; b_i++) {
    in[b_i] = false;
  }
  b_st.site = &c_emlrtRSI;
  nloops = -1;
  first[0] = 0;
  last[0] = 0;
  first[1] = 0;
  last[1] = 0;
  first[2] = 0;
  last[2] = 0;
  first[3] = 0;
  last[3] = 0;
  c_st.site = &i_emlrtRSI;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k + 1 <= 4)) {
    isnanxv = muDoubleScalarIsNaN(xv[k]);
    if (isnanxv != muDoubleScalarIsNaN(yv[k])) {
      emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                    "MATLAB:inpolygon:InvalidLoopDef",
                                    "MATLAB:inpolygon:InvalidLoopDef", 0);
    }
    if (!isnanxv) {
      exitg1 = true;
    } else {
      k++;
    }
  }
  while (k + 1 <= 4) {
    nloops++;
    kfirst = k;
    first[nloops] = k + 1;
    c_st.site = &j_emlrtRSI;
    exitg1 = false;
    while ((!exitg1) && (k + 1 < 4)) {
      boolean_T isnanyv;
      k++;
      isnanxv = muDoubleScalarIsNaN(xv[k]);
      isnanyv = muDoubleScalarIsNaN(yv[k]);
      if (isnanxv || isnanyv) {
        if (isnanxv != isnanyv) {
          emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
                                        "MATLAB:inpolygon:InvalidLoopDef",
                                        "MATLAB:inpolygon:InvalidLoopDef", 0);
        }
        k--;
        exitg1 = true;
      }
    }
    if ((xv[k] == xv[kfirst]) && (yv[k] == yv[kfirst])) {
      last[nloops] = k;
    } else {
      last[nloops] = k + 1;
    }
    k += 2;
    c_st.site = &k_emlrtRSI;
    exitg1 = false;
    while ((!exitg1) && (k + 1 <= 4)) {
      isnanxv = muDoubleScalarIsNaN(xv[k]);
      if (isnanxv != muDoubleScalarIsNaN(yv[k])) {
        emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                      "MATLAB:inpolygon:InvalidLoopDef",
                                      "MATLAB:inpolygon:InvalidLoopDef", 0);
      }
      if (!isnanxv) {
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (nloops + 1 != 0) {
    int32_T b_j;
    b_st.site = &d_emlrtRSI;
    coder::computeRange(&b_st, xv, nloops + 1, first, last, &minxv, &maxxv);
    b_st.site = &e_emlrtRSI;
    coder::computeRange(&b_st, yv, nloops + 1, first, last, &minyv, &maxyv);
    b_st.site = &f_emlrtRSI;
    xrange = maxxv - minxv;
    yrange = maxyv - minyv;
    if ((!(xrange >= 1.0E-15)) || (!(yrange >= 1.0E-15))) {
      c_st.site = &n_emlrtRSI;
      coder::internal::warning(&c_st);
    }
    if ((!(xrange <= 1.0E+150)) || (!(yrange <= 1.0E+150))) {
      c_st.site = &o_emlrtRSI;
      coder::internal::b_warning(&c_st);
    }
    b_st.site = &g_emlrtRSI;
    scale[0] = 0.0;
    scale[1] = 0.0;
    scale[2] = 0.0;
    scale[3] = 0.0;
    for (b_j = 0; b_j <= nloops; b_j++) {
      kfirst = first[b_j];
      b_i = last[b_j];
      k = b_i - 1;
      c_st.site = &p_emlrtRSI;
      if ((kfirst <= b_i - 1) && (b_i - 1 > 2147483646)) {
        d_st.site = &m_emlrtRSI;
        coder::check_forloop_overflow_error(&d_st);
      }
      for (b_i = kfirst; b_i <= k; b_i++) {
        xv_tmp = muDoubleScalarAbs(0.5 * (xv[b_i - 1] + xv[b_i]));
        xrange = muDoubleScalarAbs(0.5 * (yv[b_i - 1] + yv[b_i]));
        if ((xv_tmp > 1.0) && (xrange > 1.0)) {
          xv_tmp *= xrange;
        } else if ((xrange > xv_tmp) || muDoubleScalarIsNaN(xv_tmp)) {
          xv_tmp = xrange;
        }
        scale[b_i - 1] = xv_tmp * 6.6613381477509392E-16;
      }
      b_i = first[b_j];
      kfirst = last[b_j];
      xv_tmp = muDoubleScalarAbs(0.5 * (xv[kfirst - 1] + xv[b_i - 1]));
      xrange = muDoubleScalarAbs(0.5 * (yv[kfirst - 1] + yv[b_i - 1]));
      if ((xv_tmp > 1.0) && (xrange > 1.0)) {
        xv_tmp *= xrange;
      } else if ((xrange > xv_tmp) || muDoubleScalarIsNaN(xv_tmp)) {
        xv_tmp = xrange;
      }
      scale[kfirst - 1] = xv_tmp * 6.6613381477509392E-16;
    }
    for (b_j = 0; b_j < 15; b_j++) {
      b_st.site = &h_emlrtRSI;
      xv_tmp = obj->waypoint[b_j];
      xrange = obj->waypoint[b_j + 15];
      in[b_j] = false;
      if ((xv_tmp >= minxv) && (xv_tmp <= maxxv) && (xrange >= minyv) &&
          (xrange <= maxyv)) {
        int8_T sdq;
        sdq = 0;
        k = 0;
        int32_T exitg3;
        do {
          exitg3 = 0;
          if (k <= nloops) {
            real_T xv2;
            real_T yv2;
            real_T yvFirst;
            int32_T exitg2;
            int8_T quad2;
            int8_T quadFirst;
            yrange = xv[first[k] - 1] - xv_tmp;
            yvFirst = yv[first[k] - 1] - xrange;
            if (yrange > 0.0) {
              if (yvFirst > 0.0) {
                quadFirst = 0;
              } else {
                quadFirst = 3;
              }
            } else if (yvFirst > 0.0) {
              quadFirst = 1;
            } else {
              quadFirst = 2;
            }
            xv2 = yrange;
            yv2 = yvFirst;
            quad2 = quadFirst;
            c_st.site = &q_emlrtRSI;
            if ((first[k] <= last[k] - 1) && (last[k] - 1 > 2147483646)) {
              d_st.site = &m_emlrtRSI;
              coder::check_forloop_overflow_error(&d_st);
            }
            b_i = first[k];
            do {
              exitg2 = 0;
              if (b_i <= last[k] - 1) {
                real_T xv1;
                real_T yv1;
                int8_T quad1;
                xv1 = xv2;
                yv1 = yv2;
                xv2 = xv[b_i] - xv_tmp;
                yv2 = yv[b_i] - xrange;
                quad1 = quad2;
                if (xv2 > 0.0) {
                  if (yv2 > 0.0) {
                    quad2 = 0;
                  } else {
                    quad2 = 3;
                  }
                } else if (yv2 > 0.0) {
                  quad2 = 1;
                } else {
                  quad2 = 2;
                }
                coder::contrib(xv1, yv1, xv2, yv2, quad1, quad2, scale[b_i - 1],
                               &dquad, &isnanxv);
                if (isnanxv) {
                  in[b_j] = true;
                  exitg2 = 1;
                } else {
                  sdq = static_cast<int8_T>(sdq + dquad);
                  b_i++;
                }
              } else {
                coder::contrib(xv2, yv2, yrange, yvFirst, quad2, quadFirst,
                               scale[last[k] - 1], &dquad, &isnanxv);
                exitg2 = 2;
              }
            } while (exitg2 == 0);
            if (exitg2 == 1) {
              exitg3 = 1;
            } else if (isnanxv) {
              in[b_j] = true;
              exitg3 = 1;
            } else {
              sdq = static_cast<int8_T>(sdq + dquad);
              k++;
            }
          } else {
            in[b_j] = (sdq != 0);
            exitg3 = 1;
          }
        } while (exitg3 == 0);
      }
    }
  }
  k = 0;
  kfirst = 0;
  for (b_i = 0; b_i < 15; b_i++) {
    if (in[b_i]) {
      k++;
      tmp_data[kfirst] = static_cast<int8_T>(b_i + 1);
      kfirst++;
    }
  }
  st.site = &b_emlrtRSI;
  b_st.site = &r_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  WPtemp_size[0] = k;
  WPtemp_size[1] = 2;
  for (b_i = 0; b_i < k; b_i++) {
    WPtemp_data[b_i] = obj->waypoint[tmp_data[b_i] - 1];
  }
  for (b_i = 0; b_i < k; b_i++) {
    WPtemp_data[b_i + k] = obj->waypoint[tmp_data[b_i] + 14];
  }
}

// End of code generation (WP_extraction.cpp)
