//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  msac.cpp
//
//  Code generation for function 'msac'
//


// Include files
#include "msac.h"
#include "all.h"
#include "combineVectorElements.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "pcfitplane.h"
#include "randperm.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <string.h>

// Variable Definitions
static emlrtRSInfo dj_emlrtRSI = { 67, // lineNo
  "msac",                              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"// pathName 
};

static emlrtRSInfo ej_emlrtRSI = { 71, // lineNo
  "msac",                              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"// pathName 
};

static emlrtRSInfo fj_emlrtRSI = { 74, // lineNo
  "msac",                              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"// pathName 
};

static emlrtRSInfo gj_emlrtRSI = { 78, // lineNo
  "msac",                              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"// pathName 
};

static emlrtRSInfo hj_emlrtRSI = { 86, // lineNo
  "msac",                              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"// pathName 
};

static emlrtRSInfo ij_emlrtRSI = { 87, // lineNo
  "msac",                              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"// pathName 
};

static emlrtRSInfo jj_emlrtRSI = { 98, // lineNo
  "msac",                              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"// pathName 
};

static emlrtRSInfo kj_emlrtRSI = { 99, // lineNo
  "msac",                              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"// pathName 
};

static emlrtRSInfo lj_emlrtRSI = { 118,// lineNo
  "msac",                              // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"// pathName 
};

static emlrtRSInfo rj_emlrtRSI = { 237,// lineNo
  "fitPlane",                          // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m"// pathName
};

static emlrtRSInfo sj_emlrtRSI = { 254,// lineNo
  "checkPlane",                        // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m"// pathName
};

static emlrtRSInfo vj_emlrtRSI = { 129,// lineNo
  "evaluateModel",                     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"// pathName 
};

static emlrtRSInfo wj_emlrtRSI = { 131,// lineNo
  "evaluateModel",                     // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"// pathName 
};

static emlrtRSInfo mk_emlrtRSI = { 11, // lineNo
  "computeLoopNumber",                 // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/computeLoopNumber.m"// pathName 
};

static emlrtRSInfo nk_emlrtRSI = { 18, // lineNo
  "computeLoopNumber",                 // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/computeLoopNumber.m"// pathName 
};

static emlrtRSInfo ok_emlrtRSI = { 19, // lineNo
  "computeLoopNumber",                 // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/computeLoopNumber.m"// pathName 
};

static emlrtRSInfo al_emlrtRSI = { 260,// lineNo
  "checkPerpendicularPlane",           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m"// pathName
};

static emlrtRSInfo bl_emlrtRSI = { 263,// lineNo
  "checkPerpendicularPlane",           // fcnName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m"// pathName
};

static emlrtBCInfo t_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  130,                                 // lineNo
  1,                                   // colNo
  "",                                  // aName
  "evaluateModel",                     // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo u_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  262,                                 // lineNo
  43,                                  // colNo
  "",                                  // aName
  "checkPerpendicularPlane",           // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo v_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  262,                                 // lineNo
  66,                                  // colNo
  "",                                  // aName
  "checkPerpendicularPlane",           // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo w_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  262,                                 // lineNo
  89,                                  // colNo
  "",                                  // aName
  "checkPerpendicularPlane",           // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/pcfitplane.m",// pName
  0                                    // checkKind
};

static emlrtRTEInfo gb_emlrtRTEI = { 14,// lineNo
  9,                                   // colNo
  "log10",                             // fName
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/elfun/log10.m"// pName
};

static emlrtBCInfo x_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  70,                                  // lineNo
  30,                                  // colNo
  "",                                  // aName
  "msac",                              // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo b_emlrtDCI = { 70,  // lineNo
  30,                                  // colNo
  "msac",                              // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m",// pName 
  1                                    // checkKind
};

static emlrtRTEInfo rg_emlrtRTEI = { 55,// lineNo
  1,                                   // colNo
  "msac",                              // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"// pName 
};

static emlrtRTEInfo sg_emlrtRTEI = { 84,// lineNo
  13,                                  // colNo
  "msac",                              // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"// pName 
};

static emlrtRTEInfo tg_emlrtRTEI = { 86,// lineNo
  34,                                  // colNo
  "msac",                              // fName
  "/usr/local/MATLAB/R2020b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"// pName 
};

// Function Definitions
namespace coder
{
  namespace vision
  {
    namespace internal
    {
      namespace ransac
      {
        void msac(const emlrtStack *sp, const ::coder::array<real32_T, 2U>
                  &allPoints, real_T params_maxDistance, const real_T
                  varargin_1_data[], real_T varargin_2, boolean_T *isFound,
                  real32_T bestModelParams_data[], int32_T bestModelParams_size
                  [2])
        {
          array<real32_T, 1U> dis;
          array<boolean_T, 1U> bestInliers;
          array<boolean_T, 1U> r;
          array<boolean_T, 1U> x;
          emlrtStack b_st;
          emlrtStack c_st;
          emlrtStack d_st;
          emlrtStack e_st;
          emlrtStack f_st;
          emlrtStack g_st;
          emlrtStack h_st;
          emlrtStack st;
          real_T indices_data[3];
          int32_T indices_size[2];
          int32_T modelParams_size[2];
          int32_T hi;
          int32_T idxTrial;
          int32_T loop_ub;
          int32_T numPts;
          int32_T numTrials;
          int32_T nz;
          int32_T skipTrials;
          real32_T samplePoints_data[9];
          real32_T modelParams_data[4];
          real32_T a_idx_0;
          real32_T angle;
          real32_T b_idx_2;
          real32_T bestDis;
          boolean_T isValidModel;
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
          f_st.prev = &e_st;
          f_st.tls = e_st.tls;
          g_st.prev = &f_st;
          g_st.tls = f_st.tls;
          h_st.prev = &g_st;
          h_st.tls = g_st.tls;
          emlrtHeapReferenceStackEnterFcnR2012b(sp);
          numPts = allPoints.size(0);
          idxTrial = 1;
          numTrials = 1000;
          bestDis = static_cast<real32_T>(params_maxDistance) *
            static_cast<real32_T>(allPoints.size(0));
          bestModelParams_size[0] = 0;
          bestModelParams_size[1] = 0;
          skipTrials = 0;
          bestInliers.set_size(&rg_emlrtRTEI, sp, allPoints.size(0));
          loop_ub = allPoints.size(0);
          for (hi = 0; hi < loop_ub; hi++) {
            bestInliers[hi] = false;
          }

          while ((idxTrial <= numTrials) && (skipTrials < 10000)) {
            real_T d;
            real_T d1;
            real_T d2;
            real32_T b_idx_0;
            real32_T normal_idx_0;
            real32_T normal_idx_1;
            st.site = &dj_emlrtRSI;
            randperm(&st, static_cast<real_T>(numPts), indices_data,
                     indices_size);
            d = indices_data[0];
            d1 = indices_data[1];
            d2 = indices_data[2];
            for (hi = 0; hi < 3; hi++) {
              if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                emlrtIntegerCheckR2012b(d, &b_emlrtDCI, sp);
              }

              if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                   allPoints.size(0))) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                  allPoints.size(0), &x_emlrtBCI, sp);
              }

              samplePoints_data[3 * hi] = allPoints[(static_cast<int32_T>(d) +
                allPoints.size(0) * hi) - 1];
              if (d1 != static_cast<int32_T>(muDoubleScalarFloor(d1))) {
                emlrtIntegerCheckR2012b(d1, &b_emlrtDCI, sp);
              }

              if ((static_cast<int32_T>(d1) < 1) || (static_cast<int32_T>(d1) >
                   allPoints.size(0))) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d1), 1,
                  allPoints.size(0), &x_emlrtBCI, sp);
              }

              samplePoints_data[3 * hi + 1] = allPoints[(static_cast<int32_T>(d1)
                + allPoints.size(0) * hi) - 1];
              if (d2 != static_cast<int32_T>(muDoubleScalarFloor(d2))) {
                emlrtIntegerCheckR2012b(d2, &b_emlrtDCI, sp);
              }

              if ((static_cast<int32_T>(d2) < 1) || (static_cast<int32_T>(d2) >
                   allPoints.size(0))) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d2), 1,
                  allPoints.size(0), &x_emlrtBCI, sp);
              }

              samplePoints_data[3 * hi + 2] = allPoints[(static_cast<int32_T>(d2)
                + allPoints.size(0) * hi) - 1];
            }

            real32_T a_idx_1;
            real32_T b_idx_1;
            st.site = &ej_emlrtRSI;
            a_idx_0 = samplePoints_data[1] - samplePoints_data[0];
            b_idx_0 = samplePoints_data[2] - samplePoints_data[0];
            a_idx_1 = samplePoints_data[4] - samplePoints_data[3];
            b_idx_1 = samplePoints_data[5] - samplePoints_data[3];
            angle = samplePoints_data[7] - samplePoints_data[6];
            b_idx_2 = samplePoints_data[8] - samplePoints_data[6];
            normal_idx_0 = a_idx_1 * b_idx_2 - angle * b_idx_1;
            normal_idx_1 = angle * b_idx_0 - a_idx_0 * b_idx_2;
            b_idx_0 = a_idx_0 * b_idx_1 - a_idx_1 * b_idx_0;
            angle = (normal_idx_0 * normal_idx_0 + normal_idx_1 * normal_idx_1)
              + b_idx_0 * b_idx_0;
            if (angle < 1.1920929E-7F) {
              modelParams_size[0] = 0;
              modelParams_size[1] = 0;
            } else {
              b_st.site = &rj_emlrtRSI;
              angle = muSingleScalarSqrt(angle);
              b_idx_2 = normal_idx_0 / angle;
              a_idx_0 = -samplePoints_data[0] * b_idx_2;
              normal_idx_0 = b_idx_2;
              b_idx_2 = normal_idx_1 / angle;
              a_idx_0 += -samplePoints_data[3] * b_idx_2;
              normal_idx_1 = b_idx_2;
              b_idx_2 = b_idx_0 / angle;
              a_idx_0 += -samplePoints_data[6] * b_idx_2;
              modelParams_size[0] = 1;
              modelParams_size[1] = 4;
              modelParams_data[0] = normal_idx_0;
              modelParams_data[1] = normal_idx_1;
              modelParams_data[2] = b_idx_2;
              modelParams_data[3] = a_idx_0;
            }

            st.site = &fj_emlrtRSI;
            b_st.site = &al_emlrtRSI;
            loop_ub = modelParams_size[0] * modelParams_size[1];
            x.set_size(&hg_emlrtRTEI, &b_st, loop_ub);
            for (hi = 0; hi < loop_ub; hi++) {
              x[hi] = muSingleScalarIsInf(modelParams_data[hi]);
            }

            r.set_size(&ig_emlrtRTEI, &b_st, loop_ub);
            for (hi = 0; hi < loop_ub; hi++) {
              r[hi] = muSingleScalarIsNaN(modelParams_data[hi]);
            }

            nz = x.size(0);
            for (hi = 0; hi < nz; hi++) {
              x[hi] = ((!x[hi]) && (!r[hi]));
            }

            c_st.site = &sj_emlrtRSI;
            isValidModel = all(&c_st, x);
            isValidModel = ((loop_ub == 4) && isValidModel);
            if (isValidModel) {
              if (1 > loop_ub) {
                emlrtDynamicBoundsCheckR2012b(1, 1, 0, &u_emlrtBCI, &st);
              }

              if (2 > loop_ub) {
                emlrtDynamicBoundsCheckR2012b(2, 1, loop_ub, &v_emlrtBCI, &st);
              }

              if (3 > loop_ub) {
                emlrtDynamicBoundsCheckR2012b(3, 1, loop_ub, &w_emlrtBCI, &st);
              }

              b_st.site = &bl_emlrtRSI;
              angle = muSingleScalarAbs(muSingleScalarAcos(muSingleScalarMin
                (1.0F, muSingleScalarMax(-1.0F, (static_cast<real32_T>
                (varargin_1_data[0]) * modelParams_data[0] +
                static_cast<real32_T>(varargin_1_data[1]) * modelParams_data[1])
                + static_cast<real32_T>(varargin_1_data[2]) * modelParams_data[2]))));
              angle = muSingleScalarMin(angle, 3.14159274F - angle);
              isValidModel = (angle < varargin_2);
            }

            if (isValidModel) {
              st.site = &gj_emlrtRSI;
              b_st.site = &vj_emlrtRSI;
              evalPlane(&b_st, modelParams_data, modelParams_size, allPoints,
                        dis);
              nz = dis.size(0);
              for (hi = 0; hi < nz; hi++) {
                if (dis[hi] > static_cast<real32_T>(params_maxDistance)) {
                  if ((hi + 1 < 1) || (hi + 1 > dis.size(0))) {
                    emlrtDynamicBoundsCheckR2012b(hi + 1, 1, dis.size(0),
                      &t_emlrtBCI, &st);
                  }

                  dis[hi] = static_cast<real32_T>(params_maxDistance);
                }
              }

              b_st.site = &wj_emlrtRSI;
              c_st.site = &fk_emlrtRSI;
              d_st.site = &xi_emlrtRSI;
              e_st.site = &gk_emlrtRSI;
              if (dis.size(0) == 0) {
                angle = 0.0F;
              } else {
                int32_T k;
                int32_T lastBlockLength;
                int32_T nblocks;
                f_st.site = &hk_emlrtRSI;
                if (dis.size(0) <= 1024) {
                  nz = dis.size(0);
                  lastBlockLength = 0;
                  nblocks = 1;
                } else {
                  nz = 1024;
                  nblocks = dis.size(0) / 1024;
                  lastBlockLength = dis.size(0) - (nblocks << 10);
                  if (lastBlockLength > 0) {
                    nblocks++;
                  } else {
                    lastBlockLength = 1024;
                  }
                }

                angle = dis[0];
                g_st.site = &ik_emlrtRSI;
                for (k = 2; k <= nz; k++) {
                  angle += dis[k - 1];
                }

                g_st.site = &jk_emlrtRSI;
                for (int32_T ib = 2; ib <= nblocks; ib++) {
                  nz = (ib - 1) << 10;
                  b_idx_2 = dis[nz];
                  if (ib == nblocks) {
                    hi = lastBlockLength;
                  } else {
                    hi = 1024;
                  }

                  g_st.site = &kk_emlrtRSI;
                  if ((2 <= hi) && (hi > 2147483646)) {
                    h_st.site = &jc_emlrtRSI;
                    check_forloop_overflow_error(&h_st);
                  }

                  for (k = 2; k <= hi; k++) {
                    b_idx_2 += dis[(nz + k) - 1];
                  }

                  angle += b_idx_2;
                }
              }

              if (angle < bestDis) {
                bestDis = angle;
                bestInliers.set_size(&sg_emlrtRTEI, sp, dis.size(0));
                nz = dis.size(0);
                for (hi = 0; hi < nz; hi++) {
                  bestInliers[hi] = (dis[hi] < static_cast<real32_T>
                                     (params_maxDistance));
                }

                bestModelParams_size[0] = modelParams_size[0];
                bestModelParams_size[1] = modelParams_size[1];
                if (0 <= loop_ub - 1) {
                  memcpy(&bestModelParams_data[0], &modelParams_data[0], loop_ub
                         * sizeof(real32_T));
                }

                st.site = &hj_emlrtRSI;
                x.set_size(&tg_emlrtRTEI, &st, dis.size(0));
                loop_ub = dis.size(0);
                for (hi = 0; hi < loop_ub; hi++) {
                  x[hi] = (dis[hi] < static_cast<real32_T>(params_maxDistance));
                }

                b_st.site = &wi_emlrtRSI;
                c_st.site = &xi_emlrtRSI;
                nz = combineVectorElements(&c_st, x);
                st.site = &ij_emlrtRSI;
                b_st.site = &mk_emlrtRSI;
                c_st.site = &pk_emlrtRSI;
                d_st.site = &qk_emlrtRSI;
                angle = muSingleScalarPower(static_cast<real32_T>(nz) /
                  static_cast<real32_T>(numPts), 3.0F);
                if (angle < 1.1920929E-7F) {
                  nz = MAX_int32_T;
                } else {
                  b_st.site = &nk_emlrtRSI;
                  b_st.site = &ok_emlrtRSI;
                  if (1.0F - angle < 0.0F) {
                    emlrtErrorWithMessageIdR2018a(&b_st, &gb_emlrtRTEI,
                      "Coder:toolbox:ElFunDomainError",
                      "Coder:toolbox:ElFunDomainError", 3, 4, 5, "log10");
                  }

                  angle = muSingleScalarCeil(-2.00000048F / muSingleScalarLog10
                    (1.0F - angle));
                  if (angle < 2.14748365E+9F) {
                    nz = static_cast<int32_T>(angle);
                  } else {
                    nz = 0;
                  }
                }

                numTrials = muIntScalarMin_sint32(numTrials, nz);
              }

              idxTrial++;
            } else {
              skipTrials++;
            }
          }

          st.site = &jj_emlrtRSI;
          b_st.site = &al_emlrtRSI;
          loop_ub = bestModelParams_size[0] * bestModelParams_size[1];
          x.set_size(&hg_emlrtRTEI, &b_st, loop_ub);
          for (hi = 0; hi < loop_ub; hi++) {
            x[hi] = muSingleScalarIsInf(bestModelParams_data[hi]);
          }

          r.set_size(&ig_emlrtRTEI, &b_st, loop_ub);
          for (hi = 0; hi < loop_ub; hi++) {
            r[hi] = muSingleScalarIsNaN(bestModelParams_data[hi]);
          }

          nz = x.size(0);
          for (hi = 0; hi < nz; hi++) {
            x[hi] = ((!x[hi]) && (!r[hi]));
          }

          c_st.site = &sj_emlrtRSI;
          isValidModel = all(&c_st, x);
          isValidModel = ((loop_ub == 4) && isValidModel);
          if (isValidModel) {
            if (1 > loop_ub) {
              emlrtDynamicBoundsCheckR2012b(1, 1, 0, &u_emlrtBCI, &st);
            }

            if (2 > loop_ub) {
              emlrtDynamicBoundsCheckR2012b(2, 1, loop_ub, &v_emlrtBCI, &st);
            }

            if (3 > loop_ub) {
              emlrtDynamicBoundsCheckR2012b(3, 1, loop_ub, &w_emlrtBCI, &st);
            }

            b_st.site = &bl_emlrtRSI;
            angle = muSingleScalarAbs(muSingleScalarAcos(muSingleScalarMin(1.0F,
              muSingleScalarMax(-1.0F, (static_cast<real32_T>(varargin_1_data[0])
              * bestModelParams_data[0] + static_cast<real32_T>(varargin_1_data
              [1]) * bestModelParams_data[1]) + static_cast<real32_T>
                                (varargin_1_data[2]) * bestModelParams_data[2]))));
            angle = muSingleScalarMin(angle, 3.14159274F - angle);
            isValidModel = (angle < varargin_2);
          }

          if (isValidModel && (bestInliers.size(0) != 0)) {
            st.site = &kj_emlrtRSI;
            b_st.site = &wi_emlrtRSI;
            c_st.site = &xi_emlrtRSI;
            nz = combineVectorElements(&c_st, bestInliers);
            if (nz >= 3) {
              *isFound = true;
            } else {
              *isFound = false;
            }
          } else {
            *isFound = false;
          }

          if ((*isFound) && (numTrials >= 1000)) {
            st.site = &lj_emlrtRSI;
            ::coder::internal::warning(&st);
          }

          emlrtHeapReferenceStackLeaveFcnR2012b(sp);
        }
      }
    }
  }
}

// End of code generation (msac.cpp)
