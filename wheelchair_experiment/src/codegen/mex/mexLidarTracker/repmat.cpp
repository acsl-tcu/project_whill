//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  repmat.cpp
//
//  Code generation for function 'repmat'
//


// Include files
#include "repmat.h"
#include "assertValidSizeArg.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo uk_emlrtRSI = { 71, // lineNo
  "repmat",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/repmat.m"// pathName
};

static emlrtRSInfo vk_emlrtRSI = { 69, // lineNo
  "repmat",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/repmat.m"// pathName
};

static emlrtRSInfo wk_emlrtRSI = { 66, // lineNo
  "repmat",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/repmat.m"// pathName
};

static emlrtRSInfo xk_emlrtRSI = { 64, // lineNo
  "repmat",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/repmat.m"// pathName
};

static emlrtRSInfo qgb_emlrtRSI = { 63,// lineNo
  "repmat",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/repmat.m"// pathName
};

static emlrtMCInfo c_emlrtMCI = { 47,  // lineNo
  5,                                   // colNo
  "repmat",                            // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/repmat.m"// pName
};

static emlrtRTEInfo qg_emlrtRTEI = { 59,// lineNo
  28,                                  // colNo
  "repmat",                            // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/repmat.m"// pName
};

static emlrtRSInfo glb_emlrtRSI = { 47,// lineNo
  "repmat",                            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/repmat.m"// pathName
};

// Function Declarations
static void error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location);

// Function Definitions
static void error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "error", true, location);
}

namespace coder
{
  void b_repmat(const emlrtStack *sp, const ::coder::array<boolean_T, 2U> &a,
                const real_T varargin_1[3], ::coder::array<boolean_T, 3U> &b)
  {
    emlrtStack b_st;
    emlrtStack st;
    real_T n;
    int32_T tile_size[3];
    int32_T exitg2;
    int32_T ibtile;
    int32_T k;
    int32_T ncols;
    int32_T nrows;
    int32_T ntilecols;
    boolean_T guard1 = false;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &yk_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    k = 0;
    guard1 = false;
    do {
      exitg2 = 0;
      if (k < 3) {
        if ((varargin_1[k] != muDoubleScalarFloor(varargin_1[k])) ||
            muDoubleScalarIsInf(varargin_1[k])) {
          guard1 = true;
          exitg2 = 1;
        } else {
          k++;
          guard1 = false;
        }
      } else {
        k = 0;
        exitg2 = 2;
      }
    } while (exitg2 == 0);

    if (exitg2 != 1) {
      boolean_T exitg1;
      exitg1 = false;
      while ((!exitg1) && (k < 3)) {
        if ((varargin_1[k] < -2.147483648E+9) || (varargin_1[k] > 2.147483647E+9))
        {
          guard1 = true;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (guard1) {
      emlrtErrorWithMessageIdR2018a(&st, &eb_emlrtRTEI,
        "Coder:toolbox:eml_assert_valid_size_arg_invalidSizeVector",
        "Coder:toolbox:eml_assert_valid_size_arg_invalidSizeVector", 4, 12,
        MIN_int32_T, 12, MAX_int32_T);
    }

    if (varargin_1[0] <= 0.0) {
      n = 0.0;
    } else {
      n = varargin_1[0];
    }

    if (varargin_1[1] <= 0.0) {
      n = 0.0;
    } else {
      n *= varargin_1[1];
    }

    if (varargin_1[2] <= 0.0) {
      n = 0.0;
    } else {
      n *= varargin_1[2];
    }

    if (!(n <= 2.147483647E+9)) {
      emlrtErrorWithMessageIdR2018a(&st, &db_emlrtRTEI, "Coder:MATLAB:pmaxsize",
        "Coder:MATLAB:pmaxsize", 0);
    }

    if (!(varargin_1[0] >= 0.0)) {
      emlrtNonNegativeCheckR2012b(varargin_1[0], &p_emlrtDCI, sp);
    }

    if (!(varargin_1[1] >= 0.0)) {
      emlrtNonNegativeCheckR2012b(varargin_1[1], &p_emlrtDCI, sp);
    }

    if (!(varargin_1[2] >= 0.0)) {
      emlrtNonNegativeCheckR2012b(varargin_1[2], &p_emlrtDCI, sp);
    }

    tile_size[0] = 1;
    tile_size[1] = 1;
    tile_size[2] = static_cast<int32_T>(varargin_1[2]);
    b.set_size(&qg_emlrtRTEI, sp, a.size(0), a.size(1), static_cast<int32_T>
               (varargin_1[2]));
    nrows = a.size(0);
    ncols = a.size(1);
    st.site = &qgb_emlrtRSI;
    ntilecols = 1;
    k = 3;
    if (static_cast<int32_T>(varargin_1[2]) == 1) {
      k = 2;
    }

    for (ibtile = 2; ibtile <= k; ibtile++) {
      ntilecols *= tile_size[ibtile - 1];
    }

    st.site = &xk_emlrtRSI;
    if ((1 <= ntilecols) && (ntilecols > 2147483646)) {
      b_st.site = &jc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (int32_T jtilecol = 0; jtilecol < ntilecols; jtilecol++) {
      ibtile = jtilecol * (nrows * ncols) - 1;
      st.site = &wk_emlrtRSI;
      if ((1 <= ncols) && (ncols > 2147483646)) {
        b_st.site = &jc_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (int32_T jcol = 0; jcol < ncols; jcol++) {
        int32_T iacol_tmp;
        int32_T ibmat;
        iacol_tmp = jcol * nrows;
        ibmat = ibtile + iacol_tmp;
        st.site = &vk_emlrtRSI;
        st.site = &uk_emlrtRSI;
        if ((1 <= nrows) && (nrows > 2147483646)) {
          b_st.site = &jc_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }

        for (k = 0; k < nrows; k++) {
          b[(ibmat + k) + 1] = a[iacol_tmp + k];
        }
      }
    }
  }

  void repmat(const emlrtStack *sp, const real_T a_data[], const int32_T a_size
              [2], const real_T varargin_1[2], real_T b_data[], int32_T b_size[2])
  {
    static const int32_T b_iv[2] = { 1, 15 };

    static const char_T u[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm',
      'a', 'x', 's', 'i', 'z', 'e' };

    emlrtStack st;
    const mxArray *m;
    const mxArray *y;
    int32_T ncols;
    int8_T outsize_idx_1;
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &yk_emlrtRSI;
    internal::assertValidSizeArg(&st, varargin_1);
    outsize_idx_1 = static_cast<int8_T>(a_size[1] * 3);
    if (outsize_idx_1 != a_size[1] * 3) {
      y = NULL;
      m = emlrtCreateCharArray(2, &b_iv[0]);
      emlrtInitCharArrayR2013a(sp, 15, m, &u[0]);
      emlrtAssign(&y, m);
      st.site = &glb_emlrtRSI;
      error(&st, y, &c_emlrtMCI);
    }

    b_size[0] = 1;
    b_size[1] = outsize_idx_1;
    ncols = a_size[1];
    for (int32_T jtilecol = 0; jtilecol < 3; jtilecol++) {
      int32_T ibtile;
      ibtile = jtilecol * ncols;
      for (int32_T jcol = 0; jcol < ncols; jcol++) {
        b_data[ibtile + jcol] = a_data[jcol];
      }
    }
  }
}

// End of code generation (repmat.cpp)
