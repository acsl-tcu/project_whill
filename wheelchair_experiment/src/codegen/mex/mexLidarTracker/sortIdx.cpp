//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  sortIdx.cpp
//
//  Code generation for function 'sortIdx'
//


// Include files
#include "sortIdx.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo dh_emlrtRSI = { 499,// lineNo
  "merge_block",                       // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"// pathName 
};

static emlrtRSInfo fh_emlrtRSI = { 507,// lineNo
  "merge_block",                       // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"// pathName 
};

static emlrtRSInfo gh_emlrtRSI = { 514,// lineNo
  "merge_block",                       // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"// pathName 
};

static emlrtRSInfo hh_emlrtRSI = { 561,// lineNo
  "merge",                             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"// pathName 
};

static emlrtRSInfo ih_emlrtRSI = { 530,// lineNo
  "merge",                             // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"// pathName 
};

static emlrtRSInfo vbb_emlrtRSI = { 392,// lineNo
  "initialize_vector_sort",            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"// pathName 
};

static emlrtRSInfo wbb_emlrtRSI = { 420,// lineNo
  "initialize_vector_sort",            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"// pathName 
};

static emlrtRSInfo xbb_emlrtRSI = { 427,// lineNo
  "initialize_vector_sort",            // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"// pathName 
};

static emlrtRTEInfo ao_emlrtRTEI = { 56,// lineNo
  5,                                   // colNo
  "sortIdx",                           // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"// pName
};

// Function Declarations
namespace coder
{
  namespace internal
  {
    static void merge(const emlrtStack *sp, ::coder::array<int32_T, 1U> &idx, ::
                      coder::array<uint32_T, 1U> &x, int32_T offset, int32_T np,
                      int32_T nq, ::coder::array<int32_T, 1U> &iwork, ::coder::
                      array<uint32_T, 1U> &xwork);
    static void merge(const emlrtStack *sp, ::coder::array<int32_T, 2U> &idx, ::
                      coder::array<real_T, 2U> &x, int32_T offset, int32_T np,
                      int32_T nq, ::coder::array<int32_T, 1U> &iwork, ::coder::
                      array<real_T, 1U> &xwork);
    static void merge_block(const emlrtStack *sp, ::coder::array<int32_T, 2U>
      &idx, ::coder::array<real_T, 2U> &x, int32_T offset, int32_T n, int32_T
      preSortLevel, ::coder::array<int32_T, 1U> &iwork, ::coder::array<real_T,
      1U> &xwork);
    static void merge_pow2_block(::coder::array<int32_T, 2U> &idx, ::coder::
      array<real_T, 2U> &x, int32_T offset);
  }
}

// Function Definitions
namespace coder
{
  namespace internal
  {
    static void merge(const emlrtStack *sp, ::coder::array<int32_T, 1U> &idx, ::
                      coder::array<uint32_T, 1U> &x, int32_T offset, int32_T np,
                      int32_T nq, ::coder::array<int32_T, 1U> &iwork, ::coder::
                      array<uint32_T, 1U> &xwork)
    {
      emlrtStack b_st;
      emlrtStack st;
      st.prev = sp;
      st.tls = sp->tls;
      b_st.prev = &st;
      b_st.tls = st.tls;
      if (nq != 0) {
        int32_T iout;
        int32_T j;
        int32_T n_tmp;
        int32_T p;
        int32_T q;
        n_tmp = np + nq;
        st.site = &ih_emlrtRSI;
        if ((1 <= n_tmp) && (n_tmp > 2147483646)) {
          b_st.site = &jc_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }

        for (j = 0; j < n_tmp; j++) {
          iout = offset + j;
          iwork[j] = idx[iout];
          xwork[j] = x[iout];
        }

        p = 0;
        q = np;
        iout = offset - 1;
        int32_T exitg1;
        do {
          exitg1 = 0;
          iout++;
          if (xwork[p] <= xwork[q]) {
            idx[iout] = iwork[p];
            x[iout] = xwork[p];
            if (p + 1 < np) {
              p++;
            } else {
              exitg1 = 1;
            }
          } else {
            idx[iout] = iwork[q];
            x[iout] = xwork[q];
            if (q + 1 < n_tmp) {
              q++;
            } else {
              q = iout - p;
              st.site = &hh_emlrtRSI;
              if ((p + 1 <= np) && (np > 2147483646)) {
                b_st.site = &jc_emlrtRSI;
                check_forloop_overflow_error(&b_st);
              }

              for (j = p + 1; j <= np; j++) {
                iout = q + j;
                idx[iout] = iwork[j - 1];
                x[iout] = xwork[j - 1];
              }

              exitg1 = 1;
            }
          }
        } while (exitg1 == 0);
      }
    }

    static void merge(const emlrtStack *sp, ::coder::array<int32_T, 2U> &idx, ::
                      coder::array<real_T, 2U> &x, int32_T offset, int32_T np,
                      int32_T nq, ::coder::array<int32_T, 1U> &iwork, ::coder::
                      array<real_T, 1U> &xwork)
    {
      emlrtStack b_st;
      emlrtStack st;
      st.prev = sp;
      st.tls = sp->tls;
      b_st.prev = &st;
      b_st.tls = st.tls;
      if (nq != 0) {
        int32_T iout;
        int32_T j;
        int32_T n_tmp;
        int32_T p;
        int32_T q;
        n_tmp = np + nq;
        st.site = &ih_emlrtRSI;
        if ((1 <= n_tmp) && (n_tmp > 2147483646)) {
          b_st.site = &jc_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }

        for (j = 0; j < n_tmp; j++) {
          iout = offset + j;
          iwork[j] = idx[iout];
          xwork[j] = x[iout];
        }

        p = 0;
        q = np;
        iout = offset - 1;
        int32_T exitg1;
        do {
          exitg1 = 0;
          iout++;
          if (xwork[p] <= xwork[q]) {
            idx[iout] = iwork[p];
            x[iout] = xwork[p];
            if (p + 1 < np) {
              p++;
            } else {
              exitg1 = 1;
            }
          } else {
            idx[iout] = iwork[q];
            x[iout] = xwork[q];
            if (q + 1 < n_tmp) {
              q++;
            } else {
              q = iout - p;
              st.site = &hh_emlrtRSI;
              if ((p + 1 <= np) && (np > 2147483646)) {
                b_st.site = &jc_emlrtRSI;
                check_forloop_overflow_error(&b_st);
              }

              for (j = p + 1; j <= np; j++) {
                iout = q + j;
                idx[iout] = iwork[j - 1];
                x[iout] = xwork[j - 1];
              }

              exitg1 = 1;
            }
          }
        } while (exitg1 == 0);
      }
    }

    static void merge_block(const emlrtStack *sp, ::coder::array<int32_T, 2U>
      &idx, ::coder::array<real_T, 2U> &x, int32_T offset, int32_T n, int32_T
      preSortLevel, ::coder::array<int32_T, 1U> &iwork, ::coder::array<real_T,
      1U> &xwork)
    {
      emlrtStack st;
      int32_T bLen;
      int32_T nPairs;
      st.prev = sp;
      st.tls = sp->tls;
      nPairs = n >> preSortLevel;
      bLen = 1 << preSortLevel;
      while (nPairs > 1) {
        int32_T nTail;
        int32_T tailOffset;
        if ((nPairs & 1) != 0) {
          nPairs--;
          tailOffset = bLen * nPairs;
          nTail = n - tailOffset;
          if (nTail > bLen) {
            st.site = &dh_emlrtRSI;
            merge(&st, idx, x, offset + tailOffset, bLen, nTail - bLen, iwork,
                  xwork);
          }
        }

        tailOffset = bLen << 1;
        nPairs >>= 1;
        for (nTail = 0; nTail < nPairs; nTail++) {
          st.site = &fh_emlrtRSI;
          merge(&st, idx, x, offset + nTail * tailOffset, bLen, bLen, iwork,
                xwork);
        }

        bLen = tailOffset;
      }

      if (n > bLen) {
        st.site = &gh_emlrtRSI;
        merge(&st, idx, x, offset, bLen, n - bLen, iwork, xwork);
      }
    }

    static void merge_pow2_block(::coder::array<int32_T, 2U> &idx, ::coder::
      array<real_T, 2U> &x, int32_T offset)
    {
      real_T xwork[256];
      int32_T iwork[256];
      int32_T iout;
      for (int32_T b = 0; b < 6; b++) {
        int32_T bLen;
        int32_T bLen2;
        int32_T nPairs;
        bLen = 1 << (b + 2);
        bLen2 = bLen << 1;
        nPairs = 256 >> (b + 3);
        for (int32_T k = 0; k < nPairs; k++) {
          int32_T blockOffset;
          int32_T j;
          int32_T p;
          int32_T q;
          blockOffset = offset + k * bLen2;
          for (j = 0; j < bLen2; j++) {
            iout = blockOffset + j;
            iwork[j] = idx[iout];
            xwork[j] = x[iout];
          }

          p = 0;
          q = bLen;
          iout = blockOffset - 1;
          int32_T exitg1;
          do {
            exitg1 = 0;
            iout++;
            if (xwork[p] <= xwork[q]) {
              idx[iout] = iwork[p];
              x[iout] = xwork[p];
              if (p + 1 < bLen) {
                p++;
              } else {
                exitg1 = 1;
              }
            } else {
              idx[iout] = iwork[q];
              x[iout] = xwork[q];
              if (q + 1 < bLen2) {
                q++;
              } else {
                iout -= p;
                for (j = p + 1; j <= bLen; j++) {
                  q = iout + j;
                  idx[q] = iwork[j - 1];
                  x[q] = xwork[j - 1];
                }

                exitg1 = 1;
              }
            }
          } while (exitg1 == 0);
        }
      }
    }

    void merge_block(const emlrtStack *sp, ::coder::array<int32_T, 1U> &idx, ::
                     coder::array<uint32_T, 1U> &x, int32_T offset, int32_T n,
                     int32_T preSortLevel, ::coder::array<int32_T, 1U> &iwork, ::
                     coder::array<uint32_T, 1U> &xwork)
    {
      emlrtStack st;
      int32_T bLen;
      int32_T nPairs;
      st.prev = sp;
      st.tls = sp->tls;
      nPairs = n >> preSortLevel;
      bLen = 1 << preSortLevel;
      while (nPairs > 1) {
        int32_T nTail;
        int32_T tailOffset;
        if ((nPairs & 1) != 0) {
          nPairs--;
          tailOffset = bLen * nPairs;
          nTail = n - tailOffset;
          if (nTail > bLen) {
            st.site = &dh_emlrtRSI;
            merge(&st, idx, x, offset + tailOffset, bLen, nTail - bLen, iwork,
                  xwork);
          }
        }

        tailOffset = bLen << 1;
        nPairs >>= 1;
        for (nTail = 0; nTail < nPairs; nTail++) {
          st.site = &fh_emlrtRSI;
          merge(&st, idx, x, offset + nTail * tailOffset, bLen, bLen, iwork,
                xwork);
        }

        bLen = tailOffset;
      }

      if (n > bLen) {
        st.site = &gh_emlrtRSI;
        merge(&st, idx, x, offset, bLen, n - bLen, iwork, xwork);
      }
    }

    void merge_pow2_block(::coder::array<int32_T, 1U> &idx, ::coder::array<
                          uint32_T, 1U> &x, int32_T offset)
    {
      int32_T iwork[256];
      int32_T iout;
      uint32_T xwork[256];
      for (int32_T b = 0; b < 6; b++) {
        int32_T bLen;
        int32_T bLen2;
        int32_T nPairs;
        bLen = 1 << (b + 2);
        bLen2 = bLen << 1;
        nPairs = 256 >> (b + 3);
        for (int32_T k = 0; k < nPairs; k++) {
          int32_T blockOffset;
          int32_T j;
          int32_T p;
          int32_T q;
          blockOffset = offset + k * bLen2;
          for (j = 0; j < bLen2; j++) {
            iout = blockOffset + j;
            iwork[j] = idx[iout];
            xwork[j] = x[iout];
          }

          p = 0;
          q = bLen;
          iout = blockOffset - 1;
          int32_T exitg1;
          do {
            exitg1 = 0;
            iout++;
            if (xwork[p] <= xwork[q]) {
              idx[iout] = iwork[p];
              x[iout] = xwork[p];
              if (p + 1 < bLen) {
                p++;
              } else {
                exitg1 = 1;
              }
            } else {
              idx[iout] = iwork[q];
              x[iout] = xwork[q];
              if (q + 1 < bLen2) {
                q++;
              } else {
                iout -= p;
                for (j = p + 1; j <= bLen; j++) {
                  q = iout + j;
                  idx[q] = iwork[j - 1];
                  x[q] = xwork[j - 1];
                }

                exitg1 = 1;
              }
            }
          } while (exitg1 == 0);
        }
      }
    }

    void sortIdx(const emlrtStack *sp, ::coder::array<real_T, 2U> &x, ::coder::
                 array<int32_T, 2U> &idx)
    {
      array<real_T, 1U> xwork;
      array<int32_T, 1U> iwork;
      emlrtStack b_st;
      emlrtStack c_st;
      emlrtStack d_st;
      emlrtStack st;
      real_T x4[4];
      int32_T idx4[4];
      int32_T ib;
      int32_T quartetOffset;
      int8_T perm[4];
      st.prev = sp;
      st.tls = sp->tls;
      b_st.prev = &st;
      b_st.tls = st.tls;
      c_st.prev = &b_st;
      c_st.tls = b_st.tls;
      d_st.prev = &c_st;
      d_st.tls = c_st.tls;
      emlrtHeapReferenceStackEnterFcnR2012b(sp);
      idx.set_size(&ao_emlrtRTEI, sp, 1, x.size(1));
      ib = x.size(1);
      for (quartetOffset = 0; quartetOffset < ib; quartetOffset++) {
        idx[quartetOffset] = 0;
      }

      if (x.size(1) != 0) {
        int32_T b_n;
        int32_T i1;
        int32_T i3;
        int32_T i4;
        int32_T k;
        int32_T n;
        int32_T nNaNs;
        st.site = &qg_emlrtRSI;
        n = x.size(1);
        b_st.site = &rg_emlrtRSI;
        b_n = x.size(1);
        x4[0] = 0.0;
        idx4[0] = 0;
        x4[1] = 0.0;
        idx4[1] = 0;
        x4[2] = 0.0;
        idx4[2] = 0;
        x4[3] = 0.0;
        idx4[3] = 0;
        ib = x.size(1);
        iwork.set_size(&xn_emlrtRTEI, &b_st, ib);
        for (quartetOffset = 0; quartetOffset < ib; quartetOffset++) {
          iwork[quartetOffset] = 0;
        }

        ib = x.size(1);
        xwork.set_size(&yn_emlrtRTEI, &b_st, ib);
        for (quartetOffset = 0; quartetOffset < ib; quartetOffset++) {
          xwork[quartetOffset] = 0.0;
        }

        nNaNs = 0;
        ib = -1;
        c_st.site = &vbb_emlrtRSI;
        if ((1 <= x.size(1)) && (x.size(1) > 2147483646)) {
          d_st.site = &jc_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }

        for (k = 0; k < b_n; k++) {
          if (muDoubleScalarIsNaN(x[k])) {
            i3 = (b_n - nNaNs) - 1;
            idx[i3] = k + 1;
            xwork[i3] = x[k];
            nNaNs++;
          } else {
            ib++;
            idx4[ib] = k + 1;
            x4[ib] = x[k];
            if (ib + 1 == 4) {
              real_T d;
              real_T d1;
              quartetOffset = k - nNaNs;
              if (x4[0] <= x4[1]) {
                i1 = 1;
                ib = 2;
              } else {
                i1 = 2;
                ib = 1;
              }

              if (x4[2] <= x4[3]) {
                i3 = 3;
                i4 = 4;
              } else {
                i3 = 4;
                i4 = 3;
              }

              d = x4[i1 - 1];
              d1 = x4[i3 - 1];
              if (d <= d1) {
                d = x4[ib - 1];
                if (d <= d1) {
                  perm[0] = static_cast<int8_T>(i1);
                  perm[1] = static_cast<int8_T>(ib);
                  perm[2] = static_cast<int8_T>(i3);
                  perm[3] = static_cast<int8_T>(i4);
                } else if (d <= x4[i4 - 1]) {
                  perm[0] = static_cast<int8_T>(i1);
                  perm[1] = static_cast<int8_T>(i3);
                  perm[2] = static_cast<int8_T>(ib);
                  perm[3] = static_cast<int8_T>(i4);
                } else {
                  perm[0] = static_cast<int8_T>(i1);
                  perm[1] = static_cast<int8_T>(i3);
                  perm[2] = static_cast<int8_T>(i4);
                  perm[3] = static_cast<int8_T>(ib);
                }
              } else {
                d1 = x4[i4 - 1];
                if (d <= d1) {
                  if (x4[ib - 1] <= d1) {
                    perm[0] = static_cast<int8_T>(i3);
                    perm[1] = static_cast<int8_T>(i1);
                    perm[2] = static_cast<int8_T>(ib);
                    perm[3] = static_cast<int8_T>(i4);
                  } else {
                    perm[0] = static_cast<int8_T>(i3);
                    perm[1] = static_cast<int8_T>(i1);
                    perm[2] = static_cast<int8_T>(i4);
                    perm[3] = static_cast<int8_T>(ib);
                  }
                } else {
                  perm[0] = static_cast<int8_T>(i3);
                  perm[1] = static_cast<int8_T>(i4);
                  perm[2] = static_cast<int8_T>(i1);
                  perm[3] = static_cast<int8_T>(ib);
                }
              }

              idx[quartetOffset - 3] = idx4[perm[0] - 1];
              idx[quartetOffset - 2] = idx4[perm[1] - 1];
              idx[quartetOffset - 1] = idx4[perm[2] - 1];
              idx[quartetOffset] = idx4[perm[3] - 1];
              x[quartetOffset - 3] = x4[perm[0] - 1];
              x[quartetOffset - 2] = x4[perm[1] - 1];
              x[quartetOffset - 1] = x4[perm[2] - 1];
              x[quartetOffset] = x4[perm[3] - 1];
              ib = -1;
            }
          }
        }

        i4 = (b_n - nNaNs) - 1;
        if (ib + 1 > 0) {
          perm[1] = 0;
          perm[2] = 0;
          perm[3] = 0;
          if (ib + 1 == 1) {
            perm[0] = 1;
          } else if (ib + 1 == 2) {
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

          c_st.site = &wbb_emlrtRSI;
          if (ib + 1 > 2147483646) {
            d_st.site = &jc_emlrtRSI;
            check_forloop_overflow_error(&d_st);
          }

          for (k = 0; k <= ib; k++) {
            i3 = perm[k] - 1;
            quartetOffset = (i4 - ib) + k;
            idx[quartetOffset] = idx4[i3];
            x[quartetOffset] = x4[i3];
          }
        }

        ib = (nNaNs >> 1) + 1;
        c_st.site = &xbb_emlrtRSI;
        for (k = 0; k <= ib - 2; k++) {
          quartetOffset = (i4 + k) + 1;
          i1 = idx[quartetOffset];
          i3 = (b_n - k) - 1;
          idx[quartetOffset] = idx[i3];
          idx[i3] = i1;
          x[quartetOffset] = xwork[i3];
          x[i3] = xwork[quartetOffset];
        }

        if ((nNaNs & 1) != 0) {
          quartetOffset = i4 + ib;
          x[quartetOffset] = xwork[quartetOffset];
        }

        i1 = n - nNaNs;
        ib = 2;
        if (i1 > 1) {
          if (n >= 256) {
            quartetOffset = i1 >> 8;
            if (quartetOffset > 0) {
              b_st.site = &sg_emlrtRSI;
              for (ib = 0; ib < quartetOffset; ib++) {
                b_st.site = &tg_emlrtRSI;
                merge_pow2_block(idx, x, ib << 8);
              }

              ib = quartetOffset << 8;
              quartetOffset = i1 - ib;
              if (quartetOffset > 0) {
                b_st.site = &ug_emlrtRSI;
                merge_block(&b_st, idx, x, ib, quartetOffset, 2, iwork, xwork);
              }

              ib = 8;
            }
          }

          b_st.site = &vg_emlrtRSI;
          merge_block(&b_st, idx, x, 0, i1, ib, iwork, xwork);
        }
      }

      emlrtHeapReferenceStackLeaveFcnR2012b(sp);
    }
  }
}

// End of code generation (sortIdx.cpp)
