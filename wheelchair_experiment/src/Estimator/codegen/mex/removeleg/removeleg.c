/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * removeleg.c
 *
 * Code generation for function 'removeleg'
 *
 */

/* Include files */
#include "removeleg.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtBCInfo emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    17,          /* lineNo */
    23,          /* colNo */
    "point",     /* aName */
    "removeleg", /* fName */
    "C:\\Users\\student\\OneDrive - "
    "\xe6\x9d\xb1\xe4\xba\xac\xe9\x83\xbd\xe5\xb8\x82\xe5\xa4\xa7\xe5\xad\xa6 "
    "Tokyo City University\\g"
    "raduation\\realTimeEstNew\\src\\Estimator\\removeleg.m", /* pName */
    0                                                         /* checkKind */
};

/* Function Definitions */
void removeleg(const emlrtStack *sp, const real32_T point_data[],
               const int32_T point_size[2], real32_T savePoint_data[],
               int32_T savePoint_size[2])
{
  int32_T i;
  int32_T loop_ub;
  int32_T partialTrueCount;
  int32_T tmp_size;
  int32_T trueCount;
  int16_T b_tmp_data[1000];
  boolean_T tmp_data[1000];
  /*  N = size(point,1); */
  /*  j = 1; */
  /*  %インデックス計算でfor文を消せるので高速化できるかも */
  /*  for i = 1:N */
  /*      if point(i,3) > 0.6 */
  /*          savePoint(j,:) = point(i,:); */
  /*          j = j + 1; */
  /*      end */
  /*  end */
  /*  for文消してみたけど計算時間増加した */
  /*  i = 1:N; */
  /*  savePoint(i,:) = (point(i,3)>0.6).*point(i,:); */
  /*  ind = find(isempty(savePoint)); */
  /*  savePoint_ind = all(ind,2); */
  /*  savePoint(savePoint_ind,:) = [];     */
  tmp_size = point_size[0];
  loop_ub = point_size[0];
  for (partialTrueCount = 0; partialTrueCount < loop_ub; partialTrueCount++) {
    tmp_data[partialTrueCount] =
        (point_data[partialTrueCount + point_size[0] * 2] > 0.6);
  }
  loop_ub = point_size[0] - 1;
  trueCount = 0;
  partialTrueCount = 0;
  for (i = 0; i <= loop_ub; i++) {
    if (tmp_data[i]) {
      trueCount++;
      b_tmp_data[partialTrueCount] = (int16_T)i;
      partialTrueCount++;
    }
  }
  savePoint_size[0] = trueCount;
  savePoint_size[1] = 3;
  for (partialTrueCount = 0; partialTrueCount < 3; partialTrueCount++) {
    for (loop_ub = 0; loop_ub < trueCount; loop_ub++) {
      int16_T b_i;
      b_i = b_tmp_data[loop_ub];
      if (b_i > tmp_size - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, tmp_size - 1, &emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      savePoint_data[loop_ub + trueCount * partialTrueCount] =
          point_data[b_i + point_size[0] * partialTrueCount];
    }
  }
}

/* End of code generation (removeleg.c) */
