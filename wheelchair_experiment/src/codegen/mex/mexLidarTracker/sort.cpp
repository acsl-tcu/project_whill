//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  sort.cpp
//
//  Code generation for function 'sort'
//


// Include files
#include "sort.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "sortIdx.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo jg_emlrtRSI = { 76, // lineNo
  "sort",                              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sort.m"// pathName
};

static emlrtRSInfo kg_emlrtRSI = { 79, // lineNo
  "sort",                              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sort.m"// pathName
};

static emlrtRSInfo lg_emlrtRSI = { 81, // lineNo
  "sort",                              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sort.m"// pathName
};

static emlrtRSInfo mg_emlrtRSI = { 84, // lineNo
  "sort",                              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sort.m"// pathName
};

static emlrtRSInfo ng_emlrtRSI = { 87, // lineNo
  "sort",                              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sort.m"// pathName
};

static emlrtRSInfo og_emlrtRSI = { 90, // lineNo
  "sort",                              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sort.m"// pathName
};

static emlrtRSInfo pg_emlrtRSI = { 50, // lineNo
  "prodsize",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/shared/coder/coder/+coder/+internal/prodsize.m"// pathName 
};

static emlrtRSInfo wg_emlrtRSI = { 443,// lineNo
  "initialize_vector_sort",            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"// pathName 
};

static emlrtRSInfo xg_emlrtRSI = { 468,// lineNo
  "initialize_vector_sort",            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"// pathName 
};

static emlrtRSInfo yg_emlrtRSI = { 473,// lineNo
  "initialize_vector_sort",            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"// pathName 
};

static emlrtRSInfo ubb_emlrtRSI = { 72,// lineNo
  "sort",                              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sort.m"// pathName
};

static emlrtRTEInfo vn_emlrtRTEI = { 56,// lineNo
  24,                                  // colNo
  "sort",                              // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sort.m"// pName
};

static emlrtRTEInfo wn_emlrtRTEI = { 61,// lineNo
  5,                                   // colNo
  "sortIdx",                           // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"// pName
};

// Function Definitions
namespace coder
{
  namespace internal
  {
    void sort(const emlrtStack *sp, ::coder::array<uint32_T, 1U> &x)
    {
      array<int32_T, 1U> hlb_emlrtRSI;
      array<int32_T, 1U> iwork;
      array<uint32_T, 1U> vwork;
      array<uint32_T, 1U> xwork;
      emlrtStack b_st;
      emlrtStack c_st;
      emlrtStack d_st;
      emlrtStack e_st;
      emlrtStack st;
      int32_T idx4[4];
      int32_T dim;
      int32_T i;
      int32_T i3;
      int32_T vlen;
      int32_T vstride;
      uint32_T x4[4];
      int8_T perm[4];
      st.prev = sp;
      st.tls = sp->tls;
      b_st.prev = &st;
      b_st.tls = st.tls;
      c_st.prev = &b_st;
      c_st.tls = b_st.tls;
      d_st.prev = &c_st;
      d_st.tls = c_st.tls;
      e_st.prev = &d_st;
      e_st.tls = d_st.tls;
      emlrtHeapReferenceStackEnterFcnR2012b(sp);
      dim = 0;
      if (x.size(0) != 1) {
        dim = -1;
      }

      if (dim + 2 <= 1) {
        i = x.size(0);
      } else {
        i = 1;
      }

      vlen = i - 1;
      vwork.set_size(&vn_emlrtRTEI, sp, i);
      st.site = &jg_emlrtRSI;
      vstride = 1;
      b_st.site = &pg_emlrtRSI;
      for (i3 = 0; i3 <= dim; i3++) {
        vstride *= x.size(0);
      }

      st.site = &kg_emlrtRSI;
      st.site = &lg_emlrtRSI;
      if ((1 <= vstride) && (vstride > 2147483646)) {
        b_st.site = &jc_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (int32_T j = 0; j < vstride; j++) {
        int32_T b_i;
        st.site = &mg_emlrtRSI;
        if ((1 <= i) && (i > 2147483646)) {
          b_st.site = &jc_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }

        for (i3 = 0; i3 <= vlen; i3++) {
          vwork[i3] = x[j + i3 * vstride];
        }

        st.site = &ng_emlrtRSI;
        emlrtHeapReferenceStackEnterFcnR2012b(&st);
        dim = vwork.size(0);
        hlb_emlrtRSI.set_size(&wn_emlrtRTEI, &st, dim);
        for (b_i = 0; b_i < dim; b_i++) {
          hlb_emlrtRSI[b_i] = 0;
        }

        if (vwork.size(0) != 0) {
          int32_T b_n;
          int32_T i1;
          int32_T i2;
          int32_T n;
          b_st.site = &qg_emlrtRSI;
          n = vwork.size(0);
          c_st.site = &rg_emlrtRSI;
          b_n = vwork.size(0) - 1;
          x4[0] = 0U;
          idx4[0] = 0;
          x4[1] = 0U;
          idx4[1] = 0;
          x4[2] = 0U;
          idx4[2] = 0;
          x4[3] = 0U;
          idx4[3] = 0;
          iwork.set_size(&xn_emlrtRTEI, &c_st, dim);
          for (b_i = 0; b_i < dim; b_i++) {
            iwork[b_i] = 0;
          }

          dim = vwork.size(0);
          xwork.set_size(&yn_emlrtRTEI, &c_st, dim);
          for (b_i = 0; b_i < dim; b_i++) {
            xwork[b_i] = 0U;
          }

          dim = vwork.size(0) >> 2;
          d_st.site = &wg_emlrtRSI;
          for (int32_T b_j = 0; b_j < dim; b_j++) {
            int32_T i4;
            uint32_T b_x4_tmp;
            uint32_T c_x4_tmp;
            uint32_T x4_tmp;
            b_i = b_j << 2;
            idx4[0] = b_i + 1;
            idx4[1] = b_i + 2;
            idx4[2] = b_i + 3;
            idx4[3] = b_i + 4;
            x4[0] = vwork[b_i];
            x4_tmp = vwork[b_i + 1];
            x4[1] = x4_tmp;
            b_x4_tmp = vwork[b_i + 2];
            x4[2] = b_x4_tmp;
            c_x4_tmp = vwork[b_i + 3];
            x4[3] = c_x4_tmp;
            if (vwork[b_i] <= x4_tmp) {
              i1 = 1;
              i2 = 2;
            } else {
              i1 = 2;
              i2 = 1;
            }

            if (b_x4_tmp <= c_x4_tmp) {
              i3 = 3;
              i4 = 4;
            } else {
              i3 = 4;
              i4 = 3;
            }

            x4_tmp = x4[i1 - 1];
            b_x4_tmp = x4[i3 - 1];
            if (x4_tmp <= b_x4_tmp) {
              x4_tmp = x4[i2 - 1];
              if (x4_tmp <= b_x4_tmp) {
                perm[0] = static_cast<int8_T>(i1);
                perm[1] = static_cast<int8_T>(i2);
                perm[2] = static_cast<int8_T>(i3);
                perm[3] = static_cast<int8_T>(i4);
              } else if (x4_tmp <= x4[i4 - 1]) {
                perm[0] = static_cast<int8_T>(i1);
                perm[1] = static_cast<int8_T>(i3);
                perm[2] = static_cast<int8_T>(i2);
                perm[3] = static_cast<int8_T>(i4);
              } else {
                perm[0] = static_cast<int8_T>(i1);
                perm[1] = static_cast<int8_T>(i3);
                perm[2] = static_cast<int8_T>(i4);
                perm[3] = static_cast<int8_T>(i2);
              }
            } else {
              b_x4_tmp = x4[i4 - 1];
              if (x4_tmp <= b_x4_tmp) {
                if (x4[i2 - 1] <= b_x4_tmp) {
                  perm[0] = static_cast<int8_T>(i3);
                  perm[1] = static_cast<int8_T>(i1);
                  perm[2] = static_cast<int8_T>(i2);
                  perm[3] = static_cast<int8_T>(i4);
                } else {
                  perm[0] = static_cast<int8_T>(i3);
                  perm[1] = static_cast<int8_T>(i1);
                  perm[2] = static_cast<int8_T>(i4);
                  perm[3] = static_cast<int8_T>(i2);
                }
              } else {
                perm[0] = static_cast<int8_T>(i3);
                perm[1] = static_cast<int8_T>(i4);
                perm[2] = static_cast<int8_T>(i1);
                perm[3] = static_cast<int8_T>(i2);
              }
            }

            hlb_emlrtRSI[b_i] = idx4[perm[0] - 1];
            hlb_emlrtRSI[b_i + 1] = idx4[perm[1] - 1];
            hlb_emlrtRSI[b_i + 2] = idx4[perm[2] - 1];
            hlb_emlrtRSI[b_i + 3] = idx4[perm[3] - 1];
            vwork[b_i] = x4[perm[0] - 1];
            vwork[b_i + 1] = x4[perm[1] - 1];
            vwork[b_i + 2] = x4[perm[2] - 1];
            vwork[b_i + 3] = x4[perm[3] - 1];
          }

          i2 = dim << 2;
          i1 = (b_n - i2) + 1;
          if (i1 > 0) {
            d_st.site = &xg_emlrtRSI;
            if (i1 > 2147483646) {
              e_st.site = &jc_emlrtRSI;
              check_forloop_overflow_error(&e_st);
            }

            for (i3 = 0; i3 < i1; i3++) {
              dim = i2 + i3;
              idx4[i3] = dim + 1;
              x4[i3] = vwork[dim];
            }

            perm[1] = 0;
            perm[2] = 0;
            perm[3] = 0;
            if (i1 == 1) {
              perm[0] = 1;
            } else if (i1 == 2) {
              if (x4[0] <= x4[1]) {
                perm[0] = 1;
                perm[1] = 2;
              } else {
                perm[0] = 2;
                perm[1] = 1;
              }
            } else if (x4[0] <= x4[1]) {
              if (x4[1] <= x4[2]) {
                perm[0] = 1;
                perm[1] = 2;
                perm[2] = 3;
              } else if (x4[0] <= x4[2]) {
                perm[0] = 1;
                perm[1] = 3;
                perm[2] = 2;
              } else {
                perm[0] = 3;
                perm[1] = 1;
                perm[2] = 2;
              }
            } else if (x4[0] <= x4[2]) {
              perm[0] = 2;
              perm[1] = 1;
              perm[2] = 3;
            } else if (x4[1] <= x4[2]) {
              perm[0] = 2;
              perm[1] = 3;
              perm[2] = 1;
            } else {
              perm[0] = 3;
              perm[1] = 2;
              perm[2] = 1;
            }

            d_st.site = &yg_emlrtRSI;
            for (i3 = 0; i3 < i1; i3++) {
              dim = perm[i3] - 1;
              b_i = i2 + i3;
              hlb_emlrtRSI[b_i] = idx4[dim];
              vwork[b_i] = x4[dim];
            }
          }

          dim = 2;
          if (n > 1) {
            if (n >= 256) {
              dim = n >> 8;
              c_st.site = &sg_emlrtRSI;
              for (b_i = 0; b_i < dim; b_i++) {
                c_st.site = &tg_emlrtRSI;
                merge_pow2_block(hlb_emlrtRSI, vwork, b_i << 8);
              }

              dim <<= 8;
              b_i = n - dim;
              if (b_i > 0) {
                c_st.site = &ug_emlrtRSI;
                merge_block(&c_st, hlb_emlrtRSI, vwork, dim, b_i, 2, iwork,
                            xwork);
              }

              dim = 8;
            }

            c_st.site = &vg_emlrtRSI;
            merge_block(&c_st, hlb_emlrtRSI, vwork, 0, n, dim, iwork, xwork);
          }
        }

        emlrtHeapReferenceStackLeaveFcnR2012b(sp);
        st.site = &og_emlrtRSI;
        for (i3 = 0; i3 <= vlen; i3++) {
          x[j + i3 * vstride] = vwork[i3];
        }
      }

      emlrtHeapReferenceStackLeaveFcnR2012b(sp);
    }

    void sort(const emlrtStack *sp, ::coder::array<real_T, 2U> &x, ::coder::
              array<int32_T, 2U> &idx)
    {
      emlrtStack st;
      st.prev = sp;
      st.tls = sp->tls;
      st.site = &ubb_emlrtRSI;
      sortIdx(&st, x, idx);
    }
  }
}

// End of code generation (sort.cpp)
