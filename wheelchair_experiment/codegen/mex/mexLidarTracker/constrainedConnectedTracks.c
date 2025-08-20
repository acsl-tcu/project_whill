/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * constrainedConnectedTracks.c
 *
 * Code generation for function 'constrainedConnectedTracks'
 *
 */

/* Include files */
#include "constrainedConnectedTracks.h"
#include "colon.h"
#include "combineVectorElements.h"
#include "eml_int_forloop_overflow_check.h"
#include "maxuniquecounts.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_emxutil.h"
#include "mexLidarTracker_types.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ihb_emlrtRSI = {
    38,                           /* lineNo */
    "constrainedConnectedTracks", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "constrainedConnectedTracks.m" /* pathName */
};

static emlrtRSInfo jhb_emlrtRSI = {
    41,                           /* lineNo */
    "constrainedConnectedTracks", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "constrainedConnectedTracks.m" /* pathName */
};

static emlrtRSInfo khb_emlrtRSI = {
    42,                           /* lineNo */
    "constrainedConnectedTracks", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "constrainedConnectedTracks.m" /* pathName */
};

static emlrtRSInfo lhb_emlrtRSI = {
    51,                           /* lineNo */
    "constrainedConnectedTracks", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "constrainedConnectedTracks.m" /* pathName */
};

static emlrtRSInfo mhb_emlrtRSI = {
    26,                /* lineNo */
    "connectedTracks", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "connectedTracks.m" /* pathName */
};

static emlrtRSInfo nhb_emlrtRSI = {
    27,                /* lineNo */
    "connectedTracks", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "connectedTracks.m" /* pathName */
};

static emlrtRSInfo ohb_emlrtRSI = {
    29,                /* lineNo */
    "connectedTracks", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "connectedTracks.m" /* pathName */
};

static emlrtRSInfo phb_emlrtRSI = {
    30,                /* lineNo */
    "connectedTracks", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "connectedTracks.m" /* pathName */
};

static emlrtRSInfo qhb_emlrtRSI = {
    41,                /* lineNo */
    "connectedTracks", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "connectedTracks.m" /* pathName */
};

static emlrtRSInfo rhb_emlrtRSI = {
    42,                /* lineNo */
    "connectedTracks", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "connectedTracks.m" /* pathName */
};

static emlrtRSInfo shb_emlrtRSI = {
    45,                /* lineNo */
    "connectedTracks", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "connectedTracks.m" /* pathName */
};

static emlrtRSInfo thb_emlrtRSI = {
    60,                /* lineNo */
    "connectedTracks", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "connectedTracks.m" /* pathName */
};

static emlrtRSInfo uhb_emlrtRSI = {
    62,                /* lineNo */
    "connectedTracks", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "connectedTracks.m" /* pathName */
};

static emlrtRSInfo jib_emlrtRSI = {
    21,                              /* lineNo */
    "splitClustersUsingWeakestLink", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "splitClustersUsingWeakestLink.m" /* pathName */
};

static emlrtRSInfo kib_emlrtRSI = {
    20,                              /* lineNo */
    "splitClustersUsingWeakestLink", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "splitClustersUsingWeakestLink.m" /* pathName */
};

static emlrtECInfo jb_emlrtECI = {
    -1,                /* nDims */
    62,                /* lineNo */
    1,                 /* colNo */
    "connectedTracks", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "connectedTracks.m" /* pName */
};

static emlrtRTEInfo md_emlrtRTEI = {
    61,                /* lineNo */
    1,                 /* colNo */
    "connectedTracks", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "connectedTracks.m" /* pName */
};

static emlrtBCInfo mi_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    36,                /* lineNo */
    18,                /* colNo */
    "",                /* aName */
    "connectedTracks", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "connectedTracks.m", /* pName */
    0                    /* checkKind */
};

static emlrtBCInfo ni_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    31,                /* lineNo */
    18,                /* colNo */
    "",                /* aName */
    "connectedTracks", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "connectedTracks.m", /* pName */
    0                    /* checkKind */
};

static emlrtBCInfo oi_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    34,                /* lineNo */
    19,                /* colNo */
    "",                /* aName */
    "connectedTracks", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "connectedTracks.m", /* pName */
    0                    /* checkKind */
};

static emlrtBCInfo pi_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    39,                /* lineNo */
    35,                /* colNo */
    "",                /* aName */
    "connectedTracks", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "connectedTracks.m", /* pName */
    0                    /* checkKind */
};

static emlrtBCInfo qi_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    62,                /* lineNo */
    1,                 /* colNo */
    "",                /* aName */
    "connectedTracks", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "connectedTracks.m", /* pName */
    0                    /* checkKind */
};

static emlrtBCInfo ri_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    43,                /* lineNo */
    22,                /* colNo */
    "",                /* aName */
    "connectedTracks", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "connectedTracks.m", /* pName */
    0                    /* checkKind */
};

static emlrtBCInfo si_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    43,                /* lineNo */
    26,                /* colNo */
    "",                /* aName */
    "connectedTracks", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "connectedTracks.m", /* pName */
    0                    /* checkKind */
};

static emlrtBCInfo ti_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    43,                /* lineNo */
    51,                /* colNo */
    "",                /* aName */
    "connectedTracks", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "connectedTracks.m", /* pName */
    0                    /* checkKind */
};

static emlrtBCInfo ui_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    44,                /* lineNo */
    31,                /* colNo */
    "",                /* aName */
    "connectedTracks", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "connectedTracks.m", /* pName */
    0                    /* checkKind */
};

static emlrtBCInfo vi_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    46,                /* lineNo */
    30,                /* colNo */
    "",                /* aName */
    "connectedTracks", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "connectedTracks.m", /* pName */
    0                    /* checkKind */
};

static emlrtBCInfo wi_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    46,                /* lineNo */
    34,                /* colNo */
    "",                /* aName */
    "connectedTracks", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "connectedTracks.m", /* pName */
    0                    /* checkKind */
};

static emlrtBCInfo xi_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    46,                /* lineNo */
    56,                /* colNo */
    "",                /* aName */
    "connectedTracks", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "connectedTracks.m", /* pName */
    0                    /* checkKind */
};

static emlrtBCInfo yi_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    47,                /* lineNo */
    39,                /* colNo */
    "",                /* aName */
    "connectedTracks", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "connectedTracks.m", /* pName */
    0                    /* checkKind */
};

static emlrtBCInfo aj_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    49,                /* lineNo */
    38,                /* colNo */
    "",                /* aName */
    "connectedTracks", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "connectedTracks.m", /* pName */
    0                    /* checkKind */
};

static emlrtRTEInfo ko_emlrtRTEI = {
    59,                /* lineNo */
    1,                 /* colNo */
    "connectedTracks", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "connectedTracks.m" /* pName */
};

static emlrtRTEInfo lo_emlrtRTEI = {
    1,                            /* lineNo */
    113,                          /* colNo */
    "constrainedConnectedTracks", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "constrainedConnectedTracks.m" /* pName */
};

static emlrtRTEInfo mo_emlrtRTEI = {
    62,                /* lineNo */
    1,                 /* colNo */
    "connectedTracks", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "connectedTracks.m" /* pName */
};

static emlrtRTEInfo no_emlrtRTEI = {
    27,                /* lineNo */
    13,                /* colNo */
    "connectedTracks", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "connectedTracks.m" /* pName */
};

/* Function Definitions */
int32_T constrainedConnectedTracks(const emlrtStack *sp,
                                   const emxArray_boolean_T *connMatrix,
                                   emxArray_int32_T *clustRows,
                                   int32_T clustCols_data[],
                                   int32_T clustCols_size[2],
                                   int32_T *currentMaxRowsPerCluster,
                                   int32_T *currentMaxColumnsPerCluster)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_boolean_T *unassignedDetCluster;
  emxArray_int32_T b_clustCols_data;
  emxArray_int32_T c_clustCols_data;
  emxArray_int32_T *r;
  emxArray_int32_T *r2;
  int32_T colStackSize;
  int32_T currentCol;
  int32_T i;
  int32_T k;
  int32_T loop_ub;
  int32_T m;
  int32_T n;
  int32_T nClusters;
  int32_T nxout;
  int32_T track;
  int32_T *clustRows_data;
  int32_T *r1;
  int32_T *r3;
  int8_T colStack_data[31];
  const boolean_T *connMatrix_data;
  boolean_T *unassignedDetCluster_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  connMatrix_data = connMatrix->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &ihb_emlrtRSI;
  m = connMatrix->size[0];
  n = connMatrix->size[1] - 1;
  b_st.site = &mhb_emlrtRSI;
  repmat(&b_st, connMatrix->size[0], clustRows);
  clustRows_data = clustRows->data;
  emxInit_int32_T(&st, &r, 2, &no_emlrtRTEI);
  b_st.site = &nhb_emlrtRSI;
  repmat(&b_st, connMatrix->size[1], r);
  r1 = r->data;
  clustCols_size[0] = 1;
  clustCols_size[1] = r->size[1];
  loop_ub = r->size[1];
  for (i = 0; i < loop_ub; i++) {
    clustCols_data[i] = r1[i];
  }
  int8_T tile_size_idx_1;
  nClusters = 0;
  b_st.site = &ohb_emlrtRSI;
  c_st.site = &ib_emlrtRSI;
  tile_size_idx_1 = (int8_T)connMatrix->size[1];
  nxout = tile_size_idx_1;
  loop_ub = tile_size_idx_1;
  if (nxout - 1 >= 0) {
    memset(&colStack_data[0], 1, (uint32_T)nxout * sizeof(int8_T));
  }
  b_st.site = &phb_emlrtRSI;
  for (track = 0; track <= n; track++) {
    i = clustCols_size[1];
    if (track + 1 > i) {
      emlrtDynamicBoundsCheckR2012b(track + 1, 1, i, &ni_emlrtBCI, &st);
    }
    if (clustCols_data[track] == 0) {
      nClusters++;
      if (track + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(track + 1, 1, i, &oi_emlrtBCI, &st);
      }
      clustCols_data[track] = nClusters;
      colStackSize = 1;
      if (loop_ub < 1) {
        emlrtDynamicBoundsCheckR2012b(1, 1, loop_ub, &mi_emlrtBCI, &st);
      }
      colStack_data[0] = (int8_T)(track + 1);
      while (colStackSize > 0) {
        if (colStackSize > loop_ub) {
          emlrtDynamicBoundsCheckR2012b(colStackSize, 1, loop_ub, &pi_emlrtBCI,
                                        &st);
        }
        currentCol = colStack_data[colStackSize - 1];
        colStackSize--;
        b_st.site = &qhb_emlrtRSI;
        c_st.site = &vhb_emlrtRSI;
        c_st.site = &whb_emlrtRSI;
        nxout = loop_ub - 1;
        for (k = loop_ub; k <= nxout; k++) {
          colStack_data[k - 1] = colStack_data[k];
        }
        if (loop_ub - 1 < 1) {
          loop_ub = 0;
        } else {
          loop_ub--;
        }
        b_st.site = &rhb_emlrtRSI;
        if (m > 2147483646) {
          c_st.site = &mb_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }
        for (nxout = 0; nxout < m; nxout++) {
          i = connMatrix->size[0];
          if (nxout + 1 > i) {
            emlrtDynamicBoundsCheckR2012b(nxout + 1, 1, i, &ri_emlrtBCI, &st);
          }
          i = connMatrix->size[1];
          if (currentCol > i) {
            emlrtDynamicBoundsCheckR2012b(currentCol, 1, i, &si_emlrtBCI, &st);
          }
          if (connMatrix_data[nxout + connMatrix->size[0] * (currentCol - 1)]) {
            if (nxout + 1 > clustRows->size[1]) {
              emlrtDynamicBoundsCheckR2012b(nxout + 1, 1, clustRows->size[1],
                                            &ti_emlrtBCI, &st);
            }
            if (clustRows_data[nxout] == 0) {
              if (nxout + 1 > clustRows->size[1]) {
                emlrtDynamicBoundsCheckR2012b(nxout + 1, 1, clustRows->size[1],
                                              &ui_emlrtBCI, &st);
              }
              clustRows_data[nxout] = nClusters;
              b_st.site = &shb_emlrtRSI;
              for (k = 0; k <= n; k++) {
                i = connMatrix->size[0];
                if (nxout + 1 > i) {
                  emlrtDynamicBoundsCheckR2012b(nxout + 1, 1, i, &vi_emlrtBCI,
                                                &st);
                }
                i = connMatrix->size[1];
                if (k + 1 > i) {
                  emlrtDynamicBoundsCheckR2012b(k + 1, 1, i, &wi_emlrtBCI, &st);
                }
                if (connMatrix_data[nxout + connMatrix->size[0] * k]) {
                  i = clustCols_size[1];
                  if (k + 1 > i) {
                    emlrtDynamicBoundsCheckR2012b(k + 1, 1, i, &xi_emlrtBCI,
                                                  &st);
                  }
                  if (clustCols_data[k] == 0) {
                    i = clustCols_size[1];
                    if (k + 1 > i) {
                      emlrtDynamicBoundsCheckR2012b(k + 1, 1, i, &yi_emlrtBCI,
                                                    &st);
                    }
                    clustCols_data[k] = nClusters;
                    colStackSize++;
                    if (colStackSize > loop_ub) {
                      emlrtDynamicBoundsCheckR2012b(colStackSize, 1, loop_ub,
                                                    &aj_emlrtBCI, &st);
                    }
                    colStack_data[colStackSize - 1] = (int8_T)(k + 1);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  emxInit_boolean_T(&st, &unassignedDetCluster, 2, &ko_emlrtRTEI, true);
  i = unassignedDetCluster->size[0] * unassignedDetCluster->size[1];
  unassignedDetCluster->size[0] = 1;
  unassignedDetCluster->size[1] = clustRows->size[1];
  emxEnsureCapacity_boolean_T(&st, unassignedDetCluster, i, &ko_emlrtRTEI);
  unassignedDetCluster_data = unassignedDetCluster->data;
  loop_ub = clustRows->size[1];
  for (i = 0; i < loop_ub; i++) {
    unassignedDetCluster_data[i] = (clustRows_data[i] == 0);
  }
  b_st.site = &thb_emlrtRSI;
  c_st.site = &uh_emlrtRSI;
  d_st.site = &vh_emlrtRSI;
  currentCol = combineVectorElements(&d_st, unassignedDetCluster);
  if (currentCol > clustRows->size[1]) {
    emlrtErrorWithMessageIdR2018a(&st, &md_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  colStackSize = unassignedDetCluster->size[1] - 1;
  nxout = 0;
  for (m = 0; m <= colStackSize; m++) {
    if (unassignedDetCluster_data[m]) {
      nxout++;
    }
  }
  emxInit_int32_T(&st, &r2, 2, &mo_emlrtRTEI);
  i = r2->size[0] * r2->size[1];
  r2->size[0] = 1;
  r2->size[1] = nxout;
  emxEnsureCapacity_int32_T(&st, r2, i, &lo_emlrtRTEI);
  r3 = r2->data;
  nxout = 0;
  for (m = 0; m <= colStackSize; m++) {
    if (unassignedDetCluster_data[m]) {
      r3[nxout] = m;
      nxout++;
    }
  }
  emxFree_boolean_T(&st, &unassignedDetCluster);
  b_st.site = &uhb_emlrtRSI;
  c_st.site = &yab_emlrtRSI;
  d_st.site = &abb_emlrtRSI;
  eml_integer_colon_dispatcher(&d_st, currentCol, r);
  r1 = r->data;
  if (r2->size[1] != r->size[1]) {
    emlrtSubAssignSizeCheck1dR2017a(r2->size[1], r->size[1], &jb_emlrtECI, &st);
  }
  loop_ub = r->size[1];
  for (i = 0; i < loop_ub; i++) {
    if (r3[i] > clustRows->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(r3[i], 0, clustRows->size[1] - 1,
                                    &qi_emlrtBCI, &st);
    }
    clustRows_data[r3[i]] = r1[i] + nClusters;
  }
  emxFree_int32_T(&st, &r);
  emxFree_int32_T(&st, &r2);
  st.site = &jhb_emlrtRSI;
  *currentMaxRowsPerCluster = maxuniquecounts(&st, clustRows);
  b_clustCols_data.data = &clustCols_data[0];
  b_clustCols_data.size = &clustCols_size[0];
  b_clustCols_data.allocatedSize = -1;
  b_clustCols_data.numDimensions = 2;
  b_clustCols_data.canFreeData = false;
  st.site = &khb_emlrtRSI;
  *currentMaxColumnsPerCluster = maxuniquecounts(&st, &b_clustCols_data);
  st.site = &lhb_emlrtRSI;
  b_st.site = &kib_emlrtRSI;
  maxuniquecounts(&b_st, clustRows);
  c_clustCols_data.data = &clustCols_data[0];
  c_clustCols_data.size = &clustCols_size[0];
  c_clustCols_data.allocatedSize = -1;
  c_clustCols_data.numDimensions = 2;
  c_clustCols_data.canFreeData = false;
  b_st.site = &jib_emlrtRSI;
  maxuniquecounts(&b_st, &c_clustCols_data);
  nClusters += currentCol;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return nClusters;
}

/* End of code generation (constrainedConnectedTracks.c) */
