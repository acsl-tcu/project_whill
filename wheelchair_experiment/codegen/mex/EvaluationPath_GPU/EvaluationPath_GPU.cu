//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// EvaluationPath_GPU.cu
//
// Code generation for function 'EvaluationPath_GPU'
//

// Include files
#include "EvaluationPath_GPU.h"
#include "EvaluationPath_GPU_data.h"
#include "EvaluationPath_GPU_emxutil.h"
#include "EvaluationPath_GPU_types.h"
#include "rt_nonfinite.h"
#include "MWCudaDimUtility.hpp"
#include "MWLaunchParametersUtilities.hpp"
#include "rt_defines.h"
#include <cmath>
#include <cstring>

// Function Declarations
static __global__ void EvaluationPath_GPU_kernel1(const int32_T obj,
                                                  emxArray_real_T grade);

static __global__ void EvaluationPath_GPU_kernel10(const emxArray_real_T phaiR,
                                                   const real_T th,
                                                   const real_T r,
                                                   emxArray_real_T th_min);

static __global__ void EvaluationPath_GPU_kernel11(const real_T scale,
                                                   const real_T thg,
                                                   const int32_T i,
                                                   emxArray_real_T grade_temp);

static __global__ void
EvaluationPath_GPU_kernel12(const real_T scale,
                            const emxArray_real_T distance_obs, const int32_T i,
                            emxArray_boolean_T x);

static __global__ void EvaluationPath_GPU_kernel13(const int32_T i,
                                                   emxArray_real_T grade_temp);

static __global__ void
EvaluationPath_GPU_kernel14(const int32_T j, const int32_T i,
                            emxArray_boolean_T remove_sample,
                            emxArray_real_T grade_temp);

static __global__ void
EvaluationPath_GPU_kernel15(const emxArray_real_T grade_temp, const int32_T j,
                            const int32_T b_grade_temp,
                            const int32_T grade_dim0, emxArray_real_T grade);

static __global__ void EvaluationPath_GPU_kernel16(const emxArray_real_T grade,
                                                   const int32_T b_grade,
                                                   emxArray_real_T x);

static __global__ void EvaluationPath_GPU_kernel17(const int32_T vlen,
                                                   const emxArray_real_T x,
                                                   const int32_T npages,
                                                   const int32_T x_dim0,
                                                   emxArray_real_T FPMcost);

static __global__ void EvaluationPath_GPU_kernel18(const int32_T sz,
                                                   emxArray_real_T FPMcost);

static __global__ void EvaluationPath_GPU_kernel19(const real_T pu[42000],
                                                   real_T y[20000]);

static __global__ void
EvaluationPath_GPU_kernel2(const int32_T obj, emxArray_boolean_T remove_sample);

static __global__ void EvaluationPath_GPU_kernel20(const real_T y[20000],
                                                   real_T b_y[1000]);

static __global__ void EvaluationPath_GPU_kernel21(const struct0_T *obj,
                                                   const real_T pu[42000],
                                                   real_T a[20000]);

static __global__ void EvaluationPath_GPU_kernel22(const real_T a[20000],
                                                   real_T y[20000]);

static __global__ void EvaluationPath_GPU_kernel23(const real_T y[20000],
                                                   real_T b_y[1000]);

static __global__ void EvaluationPath_GPU_kernel24(const real_T pu[42000],
                                                   real_T a[20000]);

static __global__ void EvaluationPath_GPU_kernel25(const real_T a[20000],
                                                   real_T y[20000]);

static __global__ void EvaluationPath_GPU_kernel26(const real_T y[20000],
                                                   real_T dv[1000]);

static __global__ void EvaluationPath_GPU_kernel27(
    const struct0_T *obj, const real_T dv[1000], const real_T absxk,
    const real_T y[1000], const real_T scale, const real_T b_y[1000],
    const emxArray_real_T FPMcost, const int32_T b_iv, emxArray_real_T pw);

static __global__ void EvaluationPath_GPU_kernel3(const int32_T obj,
                                                  emxArray_real_T grade_temp);

static __global__ void
EvaluationPath_GPU_kernel4(const int32_T j, emxArray_boolean_T remove_sample);

static __global__ void
EvaluationPath_GPU_kernel5(const int32_T obj, emxArray_real_T th_min,
                           emxArray_real_T th_max, emxArray_real_T grade_obs,
                           emxArray_real_T a, emxArray_real_T phaiR,
                           emxArray_real_T PoQo, emxArray_real_T distance_obs);

static __global__ void EvaluationPath_GPU_kernel6(const real_T state[2],
                                                  const cell_wrap_0 preobs[22],
                                                  const int32_T i,
                                                  const int32_T npages,
                                                  emxArray_real_T distance_obs);

static __global__ void EvaluationPath_GPU_kernel7(const real_T state[2],
                                                  const cell_wrap_0 preobs[22],
                                                  const int32_T i, real_T x[2]);

static __global__ void EvaluationPath_GPU_kernel8(const real_T y,
                                                  const real_T scale,
                                                  const int32_T i,
                                                  emxArray_real_T PoQo);

static __global__ void
EvaluationPath_GPU_kernel9(const real_T r_obs, const real_T r_wheel,
                           const emxArray_real_T PoQo, const real_T ci,
                           const real_T x_re, emxArray_real_T a,
                           emxArray_real_T phaiR);

static void binary_expand_op(emxArray_real_T *pw,
                             const emxArray_real_T *FPMcost,
                             const real_T y[1000], const struct0_T *obj,
                             const real_T b_y[1000], const real_T dv[1000]);

static void gpuEmxEnsureCapacity_boolean_T(const emxArray_boolean_T *cpu,
                                           emxArray_boolean_T *gpu);

static void gpuEmxEnsureCapacity_real_T(const emxArray_real_T *cpu,
                                        emxArray_real_T *gpu);

static void gpuEmxFree_boolean_T(emxArray_boolean_T *gpu);

static void gpuEmxFree_real_T(emxArray_real_T *gpu);

static void gpuEmxMemcpyCpuToGpu_boolean_T(emxArray_boolean_T *gpu,
                                           const emxArray_boolean_T *cpu);

static void gpuEmxMemcpyCpuToGpu_real_T(emxArray_real_T *gpu,
                                        const emxArray_real_T *cpu);

static void gpuEmxMemcpyGpuToCpu_boolean_T(emxArray_boolean_T *cpu,
                                           emxArray_boolean_T *gpu);

static void gpuEmxMemcpyGpuToCpu_real_T(emxArray_real_T *cpu,
                                        emxArray_real_T *gpu);

static void gpuEmxReset_boolean_T(emxArray_boolean_T *gpu);

static void gpuEmxReset_real_T(emxArray_real_T *gpu);

static real_T rt_atan2d_snf(real_T u0, real_T u1);

// Function Definitions
static __global__ __launch_bounds__(1024, 1) void EvaluationPath_GPU_kernel1(
    const int32_T obj, emxArray_real_T grade)
{
  uint64_T loopEnd;
  uint64_T threadId;
  uint64_T threadStride;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  threadStride = mwGetTotalThreadsLaunched();
  loopEnd = static_cast<uint64_T>(obj);
  for (uint64_T idx{threadId}; idx <= loopEnd; idx += threadStride) {
    int32_T i;
    i = static_cast<int32_T>(idx);
    grade.data[i] = 0.0;
  }
}

static __global__ __launch_bounds__(32, 1) void EvaluationPath_GPU_kernel10(
    const emxArray_real_T phaiR, const real_T th, const real_T r,
    emxArray_real_T th_min)
{
  uint64_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    th_min.data[0] =
        atan2(sin((r - th) + phaiR.data[0]), cos((r - th) + phaiR.data[0]));
  }
}

static __global__ __launch_bounds__(32, 1) void EvaluationPath_GPU_kernel11(
    const real_T scale, const real_T thg, const int32_T i,
    emxArray_real_T grade_temp)
{
  uint64_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    grade_temp.data[i] = fmin(
        -0.38197186342054879 * fabs(atan2(sin(thg), cos(thg))) + 1.0, scale);
  }
}

static __global__ __launch_bounds__(1024, 1) void EvaluationPath_GPU_kernel12(
    const real_T scale, const emxArray_real_T distance_obs, const int32_T i,
    emxArray_boolean_T x)
{
  uint64_T loopEnd;
  uint64_T threadId;
  uint64_T threadStride;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  threadStride = mwGetTotalThreadsLaunched();
  loopEnd = static_cast<uint64_T>(i);
  for (uint64_T idx{threadId}; idx <= loopEnd; idx += threadStride) {
    int32_T b_i;
    b_i = static_cast<int32_T>(idx);
    x.data[b_i] = (distance_obs.data[b_i] < scale);
  }
}

static __global__ __launch_bounds__(32, 1) void EvaluationPath_GPU_kernel13(
    const int32_T i, emxArray_real_T grade_temp)
{
  uint64_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    grade_temp.data[i] = -100.0;
  }
}

static __global__ __launch_bounds__(32, 1) void EvaluationPath_GPU_kernel14(
    const int32_T j, const int32_T i, emxArray_boolean_T remove_sample,
    emxArray_real_T grade_temp)
{
  uint64_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    // 壁面の考慮
    grade_temp.data[i] = 0.0;
    remove_sample.data[j] = true;
  }
}

static __global__ __launch_bounds__(1024, 1) void EvaluationPath_GPU_kernel15(
    const emxArray_real_T grade_temp, const int32_T j,
    const int32_T b_grade_temp, const int32_T grade_dim0, emxArray_real_T grade)
{
  uint64_T loopEnd;
  uint64_T threadId;
  uint64_T threadStride;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  threadStride = mwGetTotalThreadsLaunched();
  loopEnd = static_cast<uint64_T>(b_grade_temp);
  for (uint64_T idx{threadId}; idx <= loopEnd; idx += threadStride) {
    int32_T i;
    i = static_cast<int32_T>(idx);
    grade.data[i + grade_dim0 * j] = grade_temp.data[i];
  }
}

static __global__ __launch_bounds__(1024, 1) void EvaluationPath_GPU_kernel16(
    const emxArray_real_T grade, const int32_T b_grade, emxArray_real_T x)
{
  uint64_T loopEnd;
  uint64_T threadId;
  uint64_T threadStride;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  threadStride = mwGetTotalThreadsLaunched();
  loopEnd = static_cast<uint64_T>(b_grade);
  for (uint64_T idx{threadId}; idx <= loopEnd; idx += threadStride) {
    int32_T i;
    i = static_cast<int32_T>(idx);
    x.data[i] = 1.0 - grade.data[i];
  }
}

static __global__ __launch_bounds__(1024, 1) void EvaluationPath_GPU_kernel17(
    const int32_T vlen, const emxArray_real_T x, const int32_T npages,
    const int32_T x_dim0, emxArray_real_T FPMcost)
{
  uint64_T loopEnd;
  uint64_T threadId;
  uint64_T threadStride;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  threadStride = mwGetTotalThreadsLaunched();
  loopEnd = static_cast<uint64_T>(npages - 1);
  for (uint64_T idx{threadId}; idx <= loopEnd; idx += threadStride) {
    int32_T i;
    int32_T xpageoffset;
    i = static_cast<int32_T>(idx);
    xpageoffset = i * x_dim0;
    FPMcost.data[i] = x.data[xpageoffset];
    for (int32_T k{0}; k <= vlen - 2; k++) {
      FPMcost.data[i] += x.data[(xpageoffset + k) + 1];
    }
  }
}

static __global__ __launch_bounds__(1024, 1) void EvaluationPath_GPU_kernel18(
    const int32_T sz, emxArray_real_T FPMcost)
{
  uint64_T loopEnd;
  uint64_T threadId;
  uint64_T threadStride;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  threadStride = mwGetTotalThreadsLaunched();
  loopEnd = static_cast<uint64_T>(sz);
  for (uint64_T idx{threadId}; idx <= loopEnd; idx += threadStride) {
    int32_T i;
    i = static_cast<int32_T>(idx);
    FPMcost.data[i] = 0.0;
  }
}

static __global__ __launch_bounds__(512, 1) void EvaluationPath_GPU_kernel19(
    const real_T pu[42000], real_T y[20000])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 20000) {
    y[k] = pu[(((k % 20) << 1) + 42 * (k / 20)) + 1] *
           pu[(((k % 20) << 1) + 42 * (k / 20)) + 1];
  }
}

static __global__ __launch_bounds__(1024, 1) void EvaluationPath_GPU_kernel2(
    const int32_T obj, emxArray_boolean_T remove_sample)
{
  uint64_T loopEnd;
  uint64_T threadId;
  uint64_T threadStride;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  threadStride = mwGetTotalThreadsLaunched();
  loopEnd = static_cast<uint64_T>(obj);
  for (uint64_T idx{threadId}; idx <= loopEnd; idx += threadStride) {
    int32_T i;
    i = static_cast<int32_T>(idx);
    remove_sample.data[i] = false;
  }
}

static __global__ __launch_bounds__(512, 1) void EvaluationPath_GPU_kernel20(
    const real_T y[20000], real_T b_y[1000])
{
  uint64_T threadId;
  int32_T i;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  i = static_cast<int32_T>(threadId);
  if (i < 1000) {
    real_T t;
    int32_T xpageoffset;
    xpageoffset = i * 20;
    t = y[xpageoffset];
    for (int32_T k{0}; k < 19; k++) {
      t += y[(xpageoffset + k) + 1];
    }
    b_y[i] = t;
  }
}

static __global__ __launch_bounds__(512, 1) void EvaluationPath_GPU_kernel21(
    const struct0_T *obj, const real_T pu[42000], real_T a[20000])
{
  uint64_T threadId;
  int32_T i;
  int32_T xpageoffset;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  xpageoffset = static_cast<int32_T>(threadId % 20ULL);
  i = static_cast<int32_T>((threadId - static_cast<uint64_T>(xpageoffset)) /
                           20ULL);
  if ((static_cast<int32_T>(i < 1000)) &&
      (static_cast<int32_T>(xpageoffset < 20))) {
    a[xpageoffset + 20 * i] = pu[(xpageoffset << 1) + 42 * i] - obj->Vref;
  }
}

static __global__ __launch_bounds__(512, 1) void EvaluationPath_GPU_kernel22(
    const real_T a[20000], real_T y[20000])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 20000) {
    real_T t;
    t = a[k];
    y[k] = t * t;
  }
}

static __global__ __launch_bounds__(512, 1) void EvaluationPath_GPU_kernel23(
    const real_T y[20000], real_T b_y[1000])
{
  uint64_T threadId;
  int32_T i;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  i = static_cast<int32_T>(threadId);
  if (i < 1000) {
    real_T t;
    int32_T xpageoffset;
    xpageoffset = i * 20;
    t = y[xpageoffset];
    for (int32_T k{0}; k < 19; k++) {
      t += y[(xpageoffset + k) + 1];
    }
    b_y[i] = t;
  }
}

static __global__ __launch_bounds__(512, 1) void EvaluationPath_GPU_kernel24(
    const real_T pu[42000], real_T a[20000])
{
  uint64_T threadId;
  int32_T i;
  int32_T xpageoffset;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  xpageoffset = static_cast<int32_T>(threadId % 20ULL);
  i = static_cast<int32_T>((threadId - static_cast<uint64_T>(xpageoffset)) /
                           20ULL);
  if ((static_cast<int32_T>(i < 1000)) &&
      (static_cast<int32_T>(xpageoffset < 20))) {
    a[xpageoffset + 20 * i] =
        pu[(xpageoffset << 1) + 42 * i] * pu[((xpageoffset << 1) + 42 * i) + 1];
  }
}

static __global__ __launch_bounds__(512, 1) void EvaluationPath_GPU_kernel25(
    const real_T a[20000], real_T y[20000])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 20000) {
    real_T t;
    t = a[k];
    y[k] = t * t;
  }
}

static __global__ __launch_bounds__(512, 1) void EvaluationPath_GPU_kernel26(
    const real_T y[20000], real_T dv[1000])
{
  uint64_T threadId;
  int32_T i;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  i = static_cast<int32_T>(threadId);
  if (i < 1000) {
    real_T t;
    int32_T xpageoffset;
    xpageoffset = i * 20;
    t = y[xpageoffset];
    for (int32_T k{0}; k < 19; k++) {
      t += y[(xpageoffset + k) + 1];
    }
    dv[i] = t;
  }
}

static __global__ __launch_bounds__(1024, 1) void EvaluationPath_GPU_kernel27(
    const struct0_T *obj, const real_T dv[1000], const real_T absxk,
    const real_T y[1000], const real_T scale, const real_T b_y[1000],
    const emxArray_real_T FPMcost, const int32_T b_iv, emxArray_real_T pw)
{
  uint64_T loopEnd;
  uint64_T threadId;
  uint64_T threadStride;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  threadStride = mwGetTotalThreadsLaunched();
  loopEnd = static_cast<uint64_T>(b_iv);
  for (uint64_T idx{threadId}; idx <= loopEnd; idx += threadStride) {
    int32_T i;
    i = static_cast<int32_T>(idx);
    pw.data[i] =
        (FPMcost.data[i] + (b_y[i] * scale + y[i] * absxk)) + dv[i] * obj->W;
  }
}

static __global__ __launch_bounds__(1024, 1) void EvaluationPath_GPU_kernel3(
    const int32_T obj, emxArray_real_T grade_temp)
{
  uint64_T loopEnd;
  uint64_T threadId;
  uint64_T threadStride;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  threadStride = mwGetTotalThreadsLaunched();
  loopEnd = static_cast<uint64_T>(obj);
  for (uint64_T idx{threadId}; idx <= loopEnd; idx += threadStride) {
    int32_T i;
    i = static_cast<int32_T>(idx);
    grade_temp.data[i] = 0.0;
  }
}

static __global__ __launch_bounds__(32, 1) void EvaluationPath_GPU_kernel4(
    const int32_T j, emxArray_boolean_T remove_sample)
{
  uint64_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    remove_sample.data[j] = false;
  }
}

static __global__ __launch_bounds__(1024, 1) void EvaluationPath_GPU_kernel5(
    const int32_T obj, emxArray_real_T th_min, emxArray_real_T th_max,
    emxArray_real_T grade_obs, emxArray_real_T a, emxArray_real_T phaiR,
    emxArray_real_T PoQo, emxArray_real_T distance_obs)
{
  uint64_T loopEnd;
  uint64_T threadId;
  uint64_T threadStride;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  threadStride = mwGetTotalThreadsLaunched();
  loopEnd = static_cast<uint64_T>(obj);
  for (uint64_T idx{threadId}; idx <= loopEnd; idx += threadStride) {
    int32_T i;
    i = static_cast<int32_T>(idx);
    distance_obs.data[i] = 0.0;
    PoQo.data[i] = 0.0;
    phaiR.data[i] = 0.0;
    a.data[i] = 0.0;
    grade_obs.data[i] = 1.0;
    th_max.data[i] = 0.0;
    th_min.data[i] = 0.0;
  }
}

static __global__ __launch_bounds__(1024, 1) void EvaluationPath_GPU_kernel6(
    const real_T state[2], const cell_wrap_0 preobs[22], const int32_T i,
    const int32_T npages, emxArray_real_T distance_obs)
{
  uint64_T loopEnd;
  uint64_T threadId;
  uint64_T threadStride;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  threadStride = mwGetTotalThreadsLaunched();
  loopEnd = static_cast<uint64_T>(npages);
  for (uint64_T idx{threadId}; idx <= loopEnd; idx += threadStride) {
    real_T absxk;
    real_T scale;
    real_T t;
    real_T y;
    int32_T b_i;
    b_i = static_cast<int32_T>(idx);
    scale = 3.3121686421112381E-170;
    absxk = fabs(preobs[i + 1].f1[0] - state[0]);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }
    absxk = fabs(preobs[i + 1].f1[1] - state[1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    distance_obs.data[b_i] = scale * sqrt(y);
  }
}

static __global__ __launch_bounds__(32, 1) void EvaluationPath_GPU_kernel7(
    const real_T state[2], const cell_wrap_0 preobs[22], const int32_T i,
    real_T x[2])
{
  uint64_T threadId;
  int32_T b_i;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  b_i = static_cast<int32_T>(threadId);
  if (b_i < 2) {
    //          tho(i,1) = atan2((obs{i,1}(1,2) - y),(obs{i,1}(1,1) - x)) - th;
    //          PoQo(i,1) = norm(obs{i,1} - [x y]);
    x[b_i] = preobs[i + 2].f1[b_i] - state[b_i];
  }
}

static __global__ __launch_bounds__(32, 1) void EvaluationPath_GPU_kernel8(
    const real_T y, const real_T scale, const int32_T i, emxArray_real_T PoQo)
{
  uint64_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    PoQo.data[i] = scale * sqrt(y);
  }
}

static __global__ __launch_bounds__(32, 1) void EvaluationPath_GPU_kernel9(
    const real_T r_obs, const real_T r_wheel, const emxArray_real_T PoQo,
    const real_T ci, const real_T x_re, emxArray_real_T a,
    emxArray_real_T phaiR)
{
  uint64_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    phaiR.data[0] = hypot(x_re, ci);
    a.data[0] = (2.5 - PoQo.data[0]) / (2.5 - (r_wheel + r_obs));
  }
}

static void binary_expand_op(emxArray_real_T *pw,
                             const emxArray_real_T *FPMcost,
                             const real_T y[1000], const struct0_T *obj,
                             const real_T b_y[1000], const real_T dv[1000])
{
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T aux_2_1;
  int32_T b_unnamed_idx_1;
  int32_T i;
  int32_T stride_0_1;
  int32_T stride_1_1;
  int32_T stride_2_1;
  int32_T unnamed_idx_1;
  unnamed_idx_1 = static_cast<int32_T>(obj->NP);
  b_unnamed_idx_1 = static_cast<int32_T>(obj->NP);
  i = pw->size[0] * pw->size[1];
  pw->size[0] = 1;
  if (static_cast<int32_T>(obj->NP) == 1) {
    pw->size[1] = FPMcost->size[1];
  } else {
    pw->size[1] = static_cast<int32_T>(obj->NP);
  }
  emxEnsureCapacity_real_T(pw, i);
  stride_0_1 = (FPMcost->size[1] != 1);
  stride_1_1 = (static_cast<int32_T>(obj->NP) != 1);
  stride_2_1 = (static_cast<int32_T>(obj->NP) != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  aux_2_1 = 0;
  if (b_unnamed_idx_1 == 1) {
    if (unnamed_idx_1 == 1) {
      b_unnamed_idx_1 = FPMcost->size[1];
    } else {
      b_unnamed_idx_1 = unnamed_idx_1;
    }
  }
  for (i = 0; i < b_unnamed_idx_1; i++) {
    pw->data[i] = (FPMcost->data[aux_0_1] +
                   (y[aux_1_1] * obj->R[1] + b_y[aux_1_1] * obj->R[0])) +
                  dv[aux_2_1] * obj->W;
    aux_2_1 += stride_2_1;
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

static void gpuEmxEnsureCapacity_boolean_T(const emxArray_boolean_T *cpu,
                                           emxArray_boolean_T *gpu)
{
  boolean_T *newData;
  if (gpu->data == 0) {
    newData = 0ULL;
    cudaMalloc(&newData, cpu->allocatedSize * sizeof(boolean_T));
    gpu->numDimensions = cpu->numDimensions;
    gpu->size = (int32_T *)emlrtCallocMex(
        static_cast<uint32_T>(gpu->numDimensions), sizeof(int32_T));
    for (int32_T i{0}; i < cpu->numDimensions; i++) {
      gpu->size[i] = cpu->size[i];
    }
    gpu->allocatedSize = cpu->allocatedSize;
    gpu->canFreeData = true;
    gpu->data = newData;
  } else {
    int32_T actualSizeCpu;
    int32_T actualSizeGpu;
    actualSizeCpu = 1;
    actualSizeGpu = 1;
    for (int32_T i{0}; i < cpu->numDimensions; i++) {
      actualSizeGpu *= gpu->size[i];
      actualSizeCpu *= cpu->size[i];
      gpu->size[i] = cpu->size[i];
    }
    if (gpu->allocatedSize < actualSizeCpu) {
      newData = 0ULL;
      cudaMalloc(&newData, cpu->allocatedSize * sizeof(boolean_T));
      cudaMemcpy(newData, gpu->data, actualSizeGpu * sizeof(boolean_T),
                 cudaMemcpyDeviceToDevice);
      gpu->allocatedSize = cpu->allocatedSize;
      if (gpu->canFreeData) {
        cudaFree(gpu->data);
      }
      gpu->canFreeData = true;
      gpu->data = newData;
    }
  }
}

static void gpuEmxEnsureCapacity_real_T(const emxArray_real_T *cpu,
                                        emxArray_real_T *gpu)
{
  real_T *newData;
  if (gpu->data == 0) {
    newData = 0ULL;
    cudaMalloc(&newData, cpu->allocatedSize * sizeof(real_T));
    gpu->numDimensions = cpu->numDimensions;
    gpu->size = (int32_T *)emlrtCallocMex(
        static_cast<uint32_T>(gpu->numDimensions), sizeof(int32_T));
    for (int32_T i{0}; i < cpu->numDimensions; i++) {
      gpu->size[i] = cpu->size[i];
    }
    gpu->allocatedSize = cpu->allocatedSize;
    gpu->canFreeData = true;
    gpu->data = newData;
  } else {
    int32_T actualSizeCpu;
    int32_T actualSizeGpu;
    actualSizeCpu = 1;
    actualSizeGpu = 1;
    for (int32_T i{0}; i < cpu->numDimensions; i++) {
      actualSizeGpu *= gpu->size[i];
      actualSizeCpu *= cpu->size[i];
      gpu->size[i] = cpu->size[i];
    }
    if (gpu->allocatedSize < actualSizeCpu) {
      newData = 0ULL;
      cudaMalloc(&newData, cpu->allocatedSize * sizeof(real_T));
      cudaMemcpy(newData, gpu->data, actualSizeGpu * sizeof(real_T),
                 cudaMemcpyDeviceToDevice);
      gpu->allocatedSize = cpu->allocatedSize;
      if (gpu->canFreeData) {
        cudaFree(gpu->data);
      }
      gpu->canFreeData = true;
      gpu->data = newData;
    }
  }
}

static void gpuEmxFree_boolean_T(emxArray_boolean_T *gpu)
{
  if (gpu->data != (void *)4207599121ULL) {
    cudaFree(gpu->data);
  }
  emlrtFreeMex(gpu->size);
}

static void gpuEmxFree_real_T(emxArray_real_T *gpu)
{
  if (gpu->data != (void *)4207599121ULL) {
    cudaFree(gpu->data);
  }
  emlrtFreeMex(gpu->size);
}

static void gpuEmxMemcpyCpuToGpu_boolean_T(emxArray_boolean_T *gpu,
                                           const emxArray_boolean_T *cpu)
{
  int32_T actualSize;
  int32_T i;
  if (gpu->numDimensions < cpu->numDimensions) {
    gpu->numDimensions = cpu->numDimensions;
    emlrtFreeMex(gpu->size);
    gpu->size = (int32_T *)emlrtCallocMex(
        static_cast<uint32_T>(gpu->numDimensions), sizeof(int32_T));
  } else {
    gpu->numDimensions = cpu->numDimensions;
  }
  actualSize = 1;
  for (i = 0; i < cpu->numDimensions; i++) {
    actualSize *= cpu->size[i];
    gpu->size[i] = cpu->size[i];
  }
  if (gpu->allocatedSize < actualSize) {
    if (gpu->canFreeData) {
      cudaFree(gpu->data);
    }
    i = cpu->allocatedSize;
    if (i < actualSize) {
      i = actualSize;
    }
    gpu->allocatedSize = i;
    gpu->canFreeData = true;
    cudaMalloc(&gpu->data, gpu->allocatedSize * sizeof(boolean_T));
  }
  cudaMemcpy(gpu->data, cpu->data, actualSize * sizeof(boolean_T),
             cudaMemcpyHostToDevice);
}

static void gpuEmxMemcpyCpuToGpu_real_T(emxArray_real_T *gpu,
                                        const emxArray_real_T *cpu)
{
  int32_T actualSize;
  int32_T i;
  if (gpu->numDimensions < cpu->numDimensions) {
    gpu->numDimensions = cpu->numDimensions;
    emlrtFreeMex(gpu->size);
    gpu->size = (int32_T *)emlrtCallocMex(
        static_cast<uint32_T>(gpu->numDimensions), sizeof(int32_T));
  } else {
    gpu->numDimensions = cpu->numDimensions;
  }
  actualSize = 1;
  for (i = 0; i < cpu->numDimensions; i++) {
    actualSize *= cpu->size[i];
    gpu->size[i] = cpu->size[i];
  }
  if (gpu->allocatedSize < actualSize) {
    if (gpu->canFreeData) {
      cudaFree(gpu->data);
    }
    i = cpu->allocatedSize;
    if (i < actualSize) {
      i = actualSize;
    }
    gpu->allocatedSize = i;
    gpu->canFreeData = true;
    cudaMalloc(&gpu->data, gpu->allocatedSize * sizeof(real_T));
  }
  cudaMemcpy(gpu->data, cpu->data, actualSize * sizeof(real_T),
             cudaMemcpyHostToDevice);
}

static void gpuEmxMemcpyGpuToCpu_boolean_T(emxArray_boolean_T *cpu,
                                           emxArray_boolean_T *gpu)
{
  int32_T actualSize;
  actualSize = 1;
  for (int32_T i{0}; i < cpu->numDimensions; i++) {
    actualSize *= cpu->size[i];
    gpu->size[i] = cpu->size[i];
  }
  cudaMemcpy(cpu->data, gpu->data, actualSize * sizeof(boolean_T),
             cudaMemcpyDeviceToHost);
}

static void gpuEmxMemcpyGpuToCpu_real_T(emxArray_real_T *cpu,
                                        emxArray_real_T *gpu)
{
  int32_T actualSize;
  actualSize = 1;
  for (int32_T i{0}; i < cpu->numDimensions; i++) {
    actualSize *= cpu->size[i];
    gpu->size[i] = cpu->size[i];
  }
  cudaMemcpy(cpu->data, gpu->data, actualSize * sizeof(real_T),
             cudaMemcpyDeviceToHost);
}

static void gpuEmxReset_boolean_T(emxArray_boolean_T *gpu)
{
  std::memset(gpu, 0, sizeof(emxArray_boolean_T));
}

static void gpuEmxReset_real_T(emxArray_real_T *gpu)
{
  std::memset(gpu, 0, sizeof(emxArray_real_T));
}

static real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = rtNaN;
  } else if (std::isinf(u0) && std::isinf(u1)) {
    int32_T b;
    int32_T c;
    if (u1 > 0.0) {
      b = 1;
    } else {
      b = -1;
    }
    if (u0 > 0.0) {
      c = 1;
    } else {
      c = -1;
    }
    y = std::atan2(static_cast<real_T>(c), static_cast<real_T>(b));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = std::atan2(u0, u1);
  }
  return y;
}

void EvaluationPath_GPU(const struct0_T *obj, const real_T px[63000],
                        const real_T pu[42000], const cell_wrap_0 preobs[22],
                        emxArray_real_T *pw, emxArray_boolean_T *remove_sample)
{
  cell_wrap_0(*gpu_preobs)[22];
  dim3 block;
  dim3 grid;
  emxArray_boolean_T c_gpu_x;
  emxArray_boolean_T gpu_remove_sample;
  emxArray_boolean_T *x;
  emxArray_real_T b_gpu_a;
  emxArray_real_T gpu_FPMcost;
  emxArray_real_T gpu_PoQo;
  emxArray_real_T gpu_distance_obs;
  emxArray_real_T gpu_grade;
  emxArray_real_T gpu_grade_obs;
  emxArray_real_T gpu_grade_temp;
  emxArray_real_T gpu_phaiR;
  emxArray_real_T gpu_pw;
  emxArray_real_T gpu_th_max;
  emxArray_real_T gpu_th_min;
  emxArray_real_T gpu_x;
  emxArray_real_T *FPMcost;
  emxArray_real_T *PoQo;
  emxArray_real_T *a;
  emxArray_real_T *b_x;
  emxArray_real_T *distance_obs;
  emxArray_real_T *grade;
  emxArray_real_T *grade_obs;
  emxArray_real_T *grade_temp;
  emxArray_real_T *phaiR;
  emxArray_real_T *th_max;
  emxArray_real_T *th_min;
  struct0_T *gpu_obj;
  real_T(*gpu_pu)[42000];
  real_T(*gpu_a)[20000];
  real_T(*gpu_y)[20000];
  real_T b_y[1000];
  real_T dv[1000];
  real_T y[1000];
  real_T(*b_gpu_y)[1000];
  real_T(*c_gpu_y)[1000];
  real_T(*gpu_dv)[1000];
  real_T c_x[2];
  real_T state[2];
  real_T(*b_gpu_x)[2];
  real_T(*gpu_state)[2];
  real_T absxk;
  real_T scale;
  int32_T b_iv[2];
  int32_T b_i;
  int32_T b_obj;
  int32_T i;
  int32_T npages;
  int32_T vlen;
  uint32_T sz[2];
  boolean_T FPMcost_dirtyOnGpu;
  boolean_T PoQo_dirtyOnGpu;
  boolean_T a_dirtyOnGpu;
  boolean_T grade_obs_dirtyOnCpu;
  boolean_T grade_obs_dirtyOnGpu;
  boolean_T phaiR_dirtyOnGpu;
  boolean_T preobs_dirtyOnCpu;
  boolean_T pw_dirtyOnGpu;
  boolean_T remove_sample_dirtyOnCpu;
  boolean_T remove_sample_dirtyOnGpu;
  boolean_T th_max_dirtyOnCpu;
  boolean_T th_max_dirtyOnGpu;
  boolean_T th_min_dirtyOnGpu;
  boolean_T x_dirtyOnGpu;
  boolean_T xneg;
  gpuEmxReset_boolean_T(&c_gpu_x);
  cudaMalloc(&b_gpu_x, 16ULL);
  cudaMalloc(&gpu_preobs, 352ULL);
  cudaMalloc(&gpu_state, 16ULL);
  gpuEmxReset_real_T(&gpu_pw);
  gpuEmxReset_real_T(&gpu_distance_obs);
  gpuEmxReset_real_T(&gpu_PoQo);
  gpuEmxReset_real_T(&gpu_phaiR);
  gpuEmxReset_real_T(&b_gpu_a);
  gpuEmxReset_real_T(&gpu_grade_obs);
  gpuEmxReset_real_T(&gpu_th_max);
  gpuEmxReset_real_T(&gpu_th_min);
  cudaMalloc(&gpu_dv, 8000ULL);
  cudaMalloc(&c_gpu_y, 8000ULL);
  cudaMalloc(&gpu_a, 160000ULL);
  cudaMalloc(&gpu_obj, 1008072ULL);
  cudaMalloc(&b_gpu_y, 8000ULL);
  cudaMalloc(&gpu_y, 160000ULL);
  cudaMalloc(&gpu_pu, 336000ULL);
  gpuEmxReset_real_T(&gpu_FPMcost);
  gpuEmxReset_real_T(&gpu_x);
  gpuEmxReset_real_T(&gpu_grade_temp);
  gpuEmxReset_boolean_T(&gpu_remove_sample);
  gpuEmxReset_real_T(&gpu_grade);
  x_dirtyOnGpu = false;
  PoQo_dirtyOnGpu = false;
  phaiR_dirtyOnGpu = false;
  a_dirtyOnGpu = false;
  grade_obs_dirtyOnGpu = false;
  th_max_dirtyOnGpu = false;
  th_min_dirtyOnGpu = false;
  FPMcost_dirtyOnGpu = false;
  grade_obs_dirtyOnCpu = false;
  th_max_dirtyOnCpu = false;
  preobs_dirtyOnCpu = true;
  pw_dirtyOnGpu = false;
  remove_sample_dirtyOnGpu = false;
  remove_sample_dirtyOnCpu = true;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInit_real_T(&grade, 2, true);
  // EVALUATIONPATH この関数の概要をここに記述
  //    詳細説明をここに記述
  i = grade->size[0] * grade->size[1];
  grade->size[0] = static_cast<int32_T>(obj->K - 1.0);
  grade->size[1] = static_cast<int32_T>(obj->NP);
  emxEnsureCapacity_real_T(grade, i);
  gpuEmxEnsureCapacity_real_T(grade, &gpu_grade);
  b_obj =
      static_cast<int32_T>(obj->K - 1.0) * static_cast<int32_T>(obj->NP) - 1;
  xneg = mwGetLaunchParameters1D(static_cast<real_T>(b_obj + 1LL), &grid,
                                 &block, 1024U, 65535U);
  if (xneg) {
    EvaluationPath_GPU_kernel1<<<grid, block>>>(b_obj, gpu_grade);
  }
  i = remove_sample->size[0] * remove_sample->size[1];
  remove_sample->size[0] = 1;
  remove_sample->size[1] = static_cast<int32_T>(obj->NP);
  emxEnsureCapacity_boolean_T(remove_sample, i);
  xneg = mwGetLaunchParameters1D(
      static_cast<real_T>((static_cast<int32_T>(obj->NP) - 1) + 1LL), &grid,
      &block, 1024U, 65535U);
  if (xneg) {
    gpuEmxMemcpyCpuToGpu_boolean_T(&gpu_remove_sample, remove_sample);
    EvaluationPath_GPU_kernel2<<<grid, block>>>(
        static_cast<int32_T>(obj->NP) - 1, gpu_remove_sample);
    remove_sample_dirtyOnCpu = false;
    remove_sample_dirtyOnGpu = true;
  }
  //      ticBytes(gcp);
  b_i = static_cast<int32_T>(obj->NP);
  emxInit_real_T(&grade_temp, 1, true);
  emxInit_real_T(&distance_obs, 1, true);
  emxInit_real_T(&PoQo, 1, true);
  emxInit_real_T(&phaiR, 1, true);
  emxInit_real_T(&a, 1, true);
  emxInit_real_T(&grade_obs, 1, true);
  emxInit_real_T(&th_max, 1, true);
  emxInit_real_T(&th_min, 1, true);
  emxInit_boolean_T(&x, 1, true);
  for (int32_T j{0}; j < b_i; j++) {
    i = grade_temp->size[0];
    grade_temp->size[0] = static_cast<int32_T>(obj->K - 1.0);
    emxEnsureCapacity_real_T(grade_temp, i);
    gpuEmxEnsureCapacity_real_T(grade_temp, &gpu_grade_temp);
    xneg = mwGetLaunchParameters1D(
        static_cast<real_T>((static_cast<int32_T>(obj->K - 1.0) - 1) + 1LL),
        &grid, &block, 1024U, 65535U);
    if (xneg) {
      EvaluationPath_GPU_kernel3<<<grid, block>>>(
          static_cast<int32_T>(obj->K - 1.0) - 1, gpu_grade_temp);
    }
    if (remove_sample_dirtyOnCpu) {
      gpuEmxMemcpyCpuToGpu_boolean_T(&gpu_remove_sample, remove_sample);
    }
    EvaluationPath_GPU_kernel4<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>(
        j, gpu_remove_sample);
    remove_sample_dirtyOnCpu = false;
    remove_sample_dirtyOnGpu = true;
    b_obj = static_cast<int32_T>(obj->K - 1.0);
    for (int32_T c_i{0}; c_i < b_obj; c_i++) {
      real_T r;
      real_T r_obs;
      real_T r_wheel;
      real_T th;
      real_T thg;
      boolean_T exitg1;
      boolean_T state_dirtyOnCpu;
      //  			[~,grade(i,j)] =
      //  FPM_2_6(obj,px(1,i+1,j),px(2,i+1,j),px(3,i+1,j),preobs{i+2,1},preobs{i+1,1});
      th = px[(3 * (c_i + 1) + 63 * j) + 2];
      // goal = obj.goal;
      r_wheel = obj->r_wheel;
      r_obs = obj->r_obs;
      //     eps = 1.0;
      //      Q = [1:-0.1:0.1];
      i = distance_obs->size[0];
      distance_obs->size[0] = static_cast<int32_T>(obj->ObsNum);
      emxEnsureCapacity_real_T(distance_obs, i);
      gpuEmxEnsureCapacity_real_T(distance_obs, &gpu_distance_obs);
      i = PoQo->size[0];
      PoQo->size[0] = static_cast<int32_T>(obj->ObsNum);
      emxEnsureCapacity_real_T(PoQo, i);
      gpuEmxEnsureCapacity_real_T(PoQo, &gpu_PoQo);
      i = phaiR->size[0];
      phaiR->size[0] = static_cast<int32_T>(obj->ObsNum);
      emxEnsureCapacity_real_T(phaiR, i);
      gpuEmxEnsureCapacity_real_T(phaiR, &gpu_phaiR);
      i = a->size[0];
      a->size[0] = static_cast<int32_T>(obj->ObsNum);
      emxEnsureCapacity_real_T(a, i);
      gpuEmxEnsureCapacity_real_T(a, &b_gpu_a);
      i = grade_obs->size[0];
      grade_obs->size[0] = static_cast<int32_T>(obj->ObsNum);
      emxEnsureCapacity_real_T(grade_obs, i);
      if (!grade_obs_dirtyOnCpu) {
        gpuEmxEnsureCapacity_real_T(grade_obs, &gpu_grade_obs);
      }
      i = th_max->size[0];
      th_max->size[0] = static_cast<int32_T>(obj->ObsNum);
      emxEnsureCapacity_real_T(th_max, i);
      if (!th_max_dirtyOnCpu) {
        gpuEmxEnsureCapacity_real_T(th_max, &gpu_th_max);
      }
      i = th_min->size[0];
      th_min->size[0] = static_cast<int32_T>(obj->ObsNum);
      emxEnsureCapacity_real_T(th_min, i);
      gpuEmxEnsureCapacity_real_T(th_min, &gpu_th_min);
      xneg = mwGetLaunchParameters1D(
          static_cast<real_T>((static_cast<int32_T>(obj->ObsNum) - 1) + 1LL),
          &grid, &block, 1024U, 65535U);
      if (xneg) {
        if (th_max_dirtyOnCpu) {
          gpuEmxMemcpyCpuToGpu_real_T(&gpu_th_max, th_max);
        }
        if (grade_obs_dirtyOnCpu) {
          gpuEmxMemcpyCpuToGpu_real_T(&gpu_grade_obs, grade_obs);
        }
        EvaluationPath_GPU_kernel5<<<grid, block>>>(
            static_cast<int32_T>(obj->ObsNum) - 1, gpu_th_min, gpu_th_max,
            gpu_grade_obs, b_gpu_a, gpu_phaiR, gpu_PoQo, gpu_distance_obs);
        a_dirtyOnGpu = true;
        PoQo_dirtyOnGpu = true;
        th_min_dirtyOnGpu = true;
        phaiR_dirtyOnGpu = true;
        grade_obs_dirtyOnCpu = false;
        grade_obs_dirtyOnGpu = true;
        th_max_dirtyOnCpu = false;
        th_max_dirtyOnGpu = true;
      }
      //      OBS_NOW = cell2mat(obs_now);
      //      OBS = cell2mat(obs);
      state[0] = px[3 * (c_i + 1) + 63 * j];
      state[1] = px[(3 * (c_i + 1) + 63 * j) + 1];
      state_dirtyOnCpu = true;
      //  PMFのプロットする際にコメント外す
      //      resolution = 0.1;%PMFの分解能[deg]
      //      GRADE_TRGT = zeros(1,360/resolution);
      //      GRADE_OBS = ones(1,360/resolution);
      //      GRADE_obs = ones(obsnum,360/resolution);
      //      GRADE_ANGL = [-pi + resolution*pi/180:resolution*pi/180:pi];
      //      distance = norm(goal-[x y]);
      //      tic
      //      distance_obs = sqrt(sum((OBS_NOW - state).^2,2));
      //      distance_obs = vecnorm(OBS_NOW-state,2,2);
      //      toc
      //      tic
      xneg = mwGetLaunchParameters1D(
          static_cast<real_T>((static_cast<int32_T>(obj->ObsNum) - 1) + 1LL),
          &grid, &block, 1024U, 65535U);
      if (xneg) {
        cudaMemcpy(*gpu_state, state, 16ULL, cudaMemcpyHostToDevice);
        state_dirtyOnCpu = false;
        if (preobs_dirtyOnCpu) {
          cudaMemcpy(*gpu_preobs, preobs, 352ULL, cudaMemcpyHostToDevice);
        }
        preobs_dirtyOnCpu = false;
        EvaluationPath_GPU_kernel6<<<grid, block>>>(
            *gpu_state, *gpu_preobs, c_i, static_cast<int32_T>(obj->ObsNum) - 1,
            gpu_distance_obs);
      }
      //      toc
      //      tic
      //      for i = 1:obsnum
      //          distance_obs(i,1) = norm(obs_now{i,1} - [x y]);
      //      end
      //     toc
      //      if distance < eps
      //          g_a = distance / eps;
      //          g_b = eta * g_a;
      //      end
      scale = px[(3 * (c_i + 1) + 63 * j) + 1];
      absxk = px[3 * (c_i + 1) + 63 * j];
      thg = rt_atan2d_snf(obj->target[(((c_i + 1) << 1) + 42 * j) + 1] - scale,
                          obj->target[((c_i + 1) << 1) + 42 * j] - absxk) -
            px[(3 * (c_i + 1) + 63 * j) + 2];
      r = rt_atan2d_snf(preobs[c_i + 2].f1[1] - scale,
                        preobs[c_i + 2].f1[0] - absxk);
      //      PoQo = sqrt(sum((OBS - state).^2,2));
      //      PoQo = vecnorm(OBS-state,2,2);
      //      phaiR = abs(asin((r_wheel + r_obs)./PoQo));
      //      a = (alpha - PoQo)/(alpha - (r_wheel + r_obs));
      npages = static_cast<int32_T>(obj->ObsNum);
      for (i = 0; i < npages; i++) {
        real_T c_y;
        real_T ci;
        real_T t;
        real_T x_re;
        //          tho(i,1) = atan2((obs{i,1}(1,2) - y),(obs{i,1}(1,1) - x)) -
        //          th; PoQo(i,1) = norm(obs{i,1} - [x y]);
        if (state_dirtyOnCpu) {
          cudaMemcpy(*gpu_state, state, 16ULL, cudaMemcpyHostToDevice);
        }
        state_dirtyOnCpu = false;
        if (preobs_dirtyOnCpu) {
          cudaMemcpy(*gpu_preobs, preobs, 352ULL, cudaMemcpyHostToDevice);
        }
        preobs_dirtyOnCpu = false;
        EvaluationPath_GPU_kernel7<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>(
            *gpu_state, *gpu_preobs, c_i, *b_gpu_x);
        scale = 3.3121686421112381E-170;
        cudaMemcpy(c_x, *b_gpu_x, 16ULL, cudaMemcpyDeviceToHost);
        absxk = std::abs(c_x[0]);
        if (absxk > 3.3121686421112381E-170) {
          c_y = 1.0;
          scale = absxk;
        } else {
          t = absxk / 3.3121686421112381E-170;
          c_y = t * t;
        }
        absxk = std::abs(c_x[1]);
        if (absxk > scale) {
          t = scale / absxk;
          c_y = c_y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          c_y += t * t;
        }
        EvaluationPath_GPU_kernel8<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>(
            c_y, scale, i, gpu_PoQo);
        gpuEmxMemcpyGpuToCpu_real_T(PoQo, &gpu_PoQo);
        PoQo_dirtyOnGpu = false;
        x_re = (r_wheel + r_obs) / PoQo->data[0];
        if (!(std::abs(x_re) > 1.0)) {
          x_re = std::asin(x_re);
          ci = 0.0;
        } else {
          real_T b_yi;
          real_T b_yr;
          real_T sbi;
          real_T scaleB;
          real_T tmp;
          real_T yi;
          real_T yr;
          if (x_re + 1.0 < 0.0) {
            yr = 0.0;
            yi = std::sqrt(-(x_re + 1.0));
          } else {
            yr = std::sqrt(x_re + 1.0);
            yi = 0.0;
          }
          if (1.0 - x_re < 0.0) {
            b_yr = 0.0;
            b_yi = std::sqrt(-(1.0 - x_re));
          } else {
            b_yr = std::sqrt(1.0 - x_re);
            b_yi = 0.0;
          }
          if ((b_yi == 0.0) && (yi == 0.0)) {
            tmp = b_yr * yr;
          } else {
            tmp = b_yr * yr - b_yi * yi;
            if ((std::isinf(tmp) || std::isnan(tmp)) && (!std::isnan(b_yr)) &&
                (!std::isnan(yr))) {
              if (b_yr > b_yi) {
                absxk = 1.0;
                c_y = b_yi / b_yr;
                scale = b_yr;
              } else if (b_yi > b_yr) {
                absxk = b_yr / b_yi;
                c_y = 1.0;
                scale = b_yi;
              } else {
                absxk = 1.0;
                c_y = 1.0;
                scale = b_yr;
              }
              if (yr > yi) {
                t = 1.0;
                sbi = yi / yr;
                scaleB = yr;
              } else if (yi > yr) {
                t = yr / yi;
                sbi = 1.0;
                scaleB = yi;
              } else {
                t = 1.0;
                sbi = 1.0;
                scaleB = yr;
              }
              if ((!std::isinf(scale)) && (!std::isnan(scale)) &&
                  ((!std::isinf(scaleB)) && (!std::isnan(scaleB)))) {
                xneg = true;
              } else {
                xneg = false;
              }
              if (std::isnan(tmp) || (std::isinf(tmp) && xneg)) {
                tmp = absxk * t - c_y * sbi;
                if (tmp != 0.0) {
                  tmp = tmp * scale * scaleB;
                } else if ((std::isinf(scale) &&
                            ((yr == 0.0) || (yi == 0.0))) ||
                           (std::isinf(scaleB) &&
                            ((b_yr == 0.0) || (b_yi == 0.0)))) {
                  scale = b_yr * yr;
                  absxk = b_yi * yi;
                  if (std::isnan(scale)) {
                    scale = 0.0;
                  }
                  if (std::isnan(absxk)) {
                    absxk = 0.0;
                  }
                  tmp = scale - absxk;
                }
              }
            }
          }
          if ((-b_yi == 0.0) && (yi == 0.0)) {
            ci = 0.0;
          } else {
            ci = b_yr * yi + -b_yi * yr;
            if ((std::isinf(ci) || std::isnan(ci)) && (!std::isnan(b_yr)) &&
                (!std::isnan(yr))) {
              scale = std::abs(-b_yi);
              if (b_yr > scale) {
                absxk = 1.0;
                c_y = -b_yi / b_yr;
                scale = b_yr;
              } else if (scale > b_yr) {
                absxk = b_yr / scale;
                if (-b_yi < 0.0) {
                  c_y = -1.0;
                } else {
                  c_y = 1.0;
                }
              } else {
                absxk = 1.0;
                if (-b_yi < 0.0) {
                  c_y = -1.0;
                } else {
                  c_y = 1.0;
                }
                scale = b_yr;
              }
              if (yr > yi) {
                t = 1.0;
                sbi = yi / yr;
                scaleB = yr;
              } else if (yi > yr) {
                t = yr / yi;
                sbi = 1.0;
                scaleB = yi;
              } else {
                t = 1.0;
                sbi = 1.0;
                scaleB = yr;
              }
              if ((!std::isinf(scale)) && (!std::isnan(scale)) &&
                  ((!std::isinf(scaleB)) && (!std::isnan(scaleB)))) {
                xneg = true;
              } else {
                xneg = false;
              }
              if (std::isnan(ci) || (std::isinf(ci) && xneg)) {
                ci = absxk * sbi + c_y * t;
                if (ci != 0.0) {
                  ci = ci * scale * scaleB;
                } else if ((std::isinf(scale) &&
                            ((yr == 0.0) || (yi == 0.0))) ||
                           (std::isinf(scaleB) &&
                            ((b_yr == 0.0) || (-b_yi == 0.0)))) {
                  absxk = b_yr * yi;
                  scale = -b_yi * yr;
                  if (std::isnan(absxk)) {
                    absxk = 0.0;
                  }
                  if (std::isnan(scale)) {
                    scale = 0.0;
                  }
                  ci = absxk + scale;
                }
              }
            }
          }
          xneg = (ci < 0.0);
          if (xneg) {
            ci = -ci;
          }
          if (ci >= 2.68435456E+8) {
            ci = std::log(ci) + 0.69314718055994529;
          } else if (ci > 2.0) {
            ci = std::log(2.0 * ci + 1.0 / (std::sqrt(ci * ci + 1.0) + ci));
          } else {
            t = ci * ci;
            ci += t / (std::sqrt(t + 1.0) + 1.0);
            scale = std::abs(ci);
            if ((scale > 4.503599627370496E+15) ||
                (std::isinf(ci) || std::isnan(ci))) {
              ci++;
              ci = std::log(ci);
            } else if (!(scale < 2.2204460492503131E-16)) {
              ci = std::log(ci + 1.0) * (ci / ((ci + 1.0) - 1.0));
            }
          }
          if (xneg) {
            ci = -ci;
          }
          x_re = rt_atan2d_snf(x_re, tmp);
        }
        EvaluationPath_GPU_kernel9<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>(
            r_obs, r_wheel, gpu_PoQo, ci, x_re, b_gpu_a, gpu_phaiR);
        a_dirtyOnGpu = true;
        phaiR_dirtyOnGpu = true;
      }
      //      grade_trgt = ((g_a-g_b)/pi)*(pi-abs(thg))+g_b;
      npages = static_cast<int32_T>(obj->ObsNum);
      if (0 <= static_cast<int32_T>(obj->ObsNum) - 1) {
        EvaluationPath_GPU_kernel10<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>(
            gpu_phaiR, th, r, gpu_th_min);
        th_min_dirtyOnGpu = true;
      }
      for (i = 0; i < npages; i++) {
        //          grade_obs(i,1) = 1.0;
        //          if tho(i,1) - phaiR(i,1) <= 0.0 && 0.0 <= tho(i,1) +
        //          phaiR(i,1)
        if (th_max_dirtyOnGpu) {
          gpuEmxMemcpyGpuToCpu_real_T(th_max, &gpu_th_max);
        }
        if (phaiR_dirtyOnGpu) {
          gpuEmxMemcpyGpuToCpu_real_T(phaiR, &gpu_phaiR);
        }
        phaiR_dirtyOnGpu = false;
        th_max->data[i] = rt_atan2d_snf(std::sin((r - th) - phaiR->data[0]),
                                        std::cos((r - th) - phaiR->data[0]));
        th_max_dirtyOnGpu = false;
        th_max_dirtyOnCpu = true;
        //          th_max_local(i,1) = tho(i,1) - phaiR(i,1);
        //          th_min_local(i,1) = tho(i,1) + phaiR(i,1);
        if (th_max->data[0] <= 0.0) {
          if (th_min_dirtyOnGpu) {
            gpuEmxMemcpyGpuToCpu_real_T(th_min, &gpu_th_min);
          }
          th_min_dirtyOnGpu = false;
          if (0.0 <= th_min->data[0]) {
            if (PoQo_dirtyOnGpu) {
              gpuEmxMemcpyGpuToCpu_real_T(PoQo, &gpu_PoQo);
            }
            PoQo_dirtyOnGpu = false;
            if (PoQo->data[0] < 2.5) {
              if (grade_obs_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(grade_obs, &gpu_grade_obs);
              }
              if (a_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(a, &b_gpu_a);
              }
              a_dirtyOnGpu = false;
              grade_obs->data[0] = 1.0 - a->data[0];
              grade_obs_dirtyOnGpu = false;
              grade_obs_dirtyOnCpu = true;
              //
            } else {
              if (grade_obs_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(grade_obs, &gpu_grade_obs);
              }
              grade_obs->data[0] = 1.0;
              grade_obs_dirtyOnGpu = false;
              grade_obs_dirtyOnCpu = true;
            }
          }
        }
      }
      vlen = grade_obs->size[0];
      if (grade_obs_dirtyOnGpu) {
        gpuEmxMemcpyGpuToCpu_real_T(grade_obs, &gpu_grade_obs);
      }
      grade_obs_dirtyOnGpu = false;
      scale = grade_obs->data[0];
      for (i = 0; i <= vlen - 2; i++) {
        if (std::isnan(grade_obs->data[i + 1])) {
          xneg = false;
        } else if (std::isnan(scale)) {
          xneg = true;
        } else {
          xneg = (scale > grade_obs->data[i + 1]);
        }
        if (xneg) {
          scale = grade_obs->data[i + 1];
        }
      }
      EvaluationPath_GPU_kernel11<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>(
          scale, thg, c_i, gpu_grade_temp);
      //      phai = -pi + resolution*pi/180;
      //      for j = 1:360/resolution
      //          phaierror = atan2(sin(thg - phai),cos(thg - phai));
      //          GRADE_TRGT(1,j) = -((g_a - g_b)/pi)*abs(phaierror) + g_a;
      //          for i = 1:obsnum
      //              if th_min_local(i,1) > pi || th_max_local(i,1) < -pi
      //                  if or(th_max(i,1) <= phai && phai <= pi,th_min(i,1) >=
      //                  phai && phai >= -pi)
      //                      if PoQo(i,1) < alpha
      //                          GRADE_obs(i,j) = 1 - a(i,1);
      //                      end
      //                  end
      //              else
      //                  if th_max(i,1) <= phai && phai <= th_min(i,1)
      //                      if PoQo(i,1) < alpha
      //                          GRADE_obs(i,j) = 1 - a(i,1);
      //                      end
      //                  end
      //              end
      //          end
      //          phai = phai + resolution*pi/180;
      //      end
      //      GRADE_OBS = min(GRADE_obs,[],1);
      //      Grade = max(min([GRADE_TRGT;GRADE_OBS],[],1));
      i = distance_obs->size[0] - 1;
      npages = x->size[0];
      x->size[0] = distance_obs->size[0];
      emxEnsureCapacity_boolean_T(x, npages);
      gpuEmxEnsureCapacity_boolean_T(x, &c_gpu_x);
      xneg = mwGetLaunchParameters1D(static_cast<real_T>(i + 1LL), &grid,
                                     &block, 1024U, 65535U);
      if (xneg) {
        EvaluationPath_GPU_kernel12<<<grid, block>>>(
            obj->r_wheel + obj->r_obs, gpu_distance_obs, i, c_gpu_x);
        x_dirtyOnGpu = true;
      }
      xneg = false;
      npages = 1;
      exitg1 = false;
      while ((!exitg1) && (npages <= x->size[0])) {
        if (x_dirtyOnGpu) {
          gpuEmxMemcpyGpuToCpu_boolean_T(x, &c_gpu_x);
        }
        x_dirtyOnGpu = false;
        if (x->data[npages - 1]) {
          xneg = true;
          exitg1 = true;
        } else {
          npages++;
        }
      }
      if (xneg) {
        EvaluationPath_GPU_kernel13<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>(
            c_i, gpu_grade_temp);
      }
      scale = px[3 * (c_i + 1) + 63 * j];
      if ((scale < obj->limit[((c_i + 1) << 2) + 84 * j]) ||
          (scale > obj->limit[(((c_i + 1) << 2) + 84 * j) + 1]) ||
          (px[(3 * (c_i + 1) + 63 * j) + 1] <
           obj->limit[(((c_i + 1) << 2) + 84 * j) + 2]) ||
          (px[(3 * (c_i + 1) + 63 * j) + 1] >
           obj->limit[(((c_i + 1) << 2) + 84 * j) + 3])) {
        // 壁面の考慮
        EvaluationPath_GPU_kernel14<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>(
            j, c_i, gpu_remove_sample, gpu_grade_temp);
      }
    }
    b_obj = grade_temp->size[0] - 1;
    npages = grade->size[0];
    xneg = mwGetLaunchParameters1D(static_cast<real_T>(b_obj + 1LL), &grid,
                                   &block, 1024U, 65535U);
    if (xneg) {
      EvaluationPath_GPU_kernel15<<<grid, block>>>(gpu_grade_temp, j, b_obj,
                                                   npages, gpu_grade);
    }
  }
  emxFree_boolean_T(&x);
  emxFree_real_T(&th_min);
  emxFree_real_T(&th_max);
  emxFree_real_T(&grade_obs);
  emxFree_real_T(&a);
  emxFree_real_T(&phaiR);
  emxFree_real_T(&PoQo);
  emxFree_real_T(&distance_obs);
  emxFree_real_T(&grade_temp);
  emxInit_real_T(&b_x, 2, true);
  //      tocBytes(gcp);
  i = b_x->size[0] * b_x->size[1];
  b_x->size[0] = grade->size[0];
  b_x->size[1] = grade->size[1];
  emxEnsureCapacity_real_T(b_x, i);
  gpuEmxEnsureCapacity_real_T(b_x, &gpu_x);
  b_obj = grade->size[0] * grade->size[1] - 1;
  xneg = mwGetLaunchParameters1D(static_cast<real_T>(b_obj + 1LL), &grid,
                                 &block, 1024U, 65535U);
  if (xneg) {
    EvaluationPath_GPU_kernel16<<<grid, block>>>(gpu_grade, b_obj, gpu_x);
  }
  emxFree_real_T(&grade);
  vlen = b_x->size[0];
  emxInit_real_T(&FPMcost, 2, true);
  if ((b_x->size[0] == 0) || (b_x->size[1] == 0)) {
    for (i = 0; i < 2; i++) {
      sz[i] = static_cast<uint32_T>(b_x->size[i]);
    }
    i = FPMcost->size[0] * FPMcost->size[1];
    FPMcost->size[0] = 1;
    FPMcost->size[1] = static_cast<int32_T>(sz[1]);
    emxEnsureCapacity_real_T(FPMcost, i);
    gpuEmxEnsureCapacity_real_T(FPMcost, &gpu_FPMcost);
    xneg = mwGetLaunchParameters1D(
        static_cast<real_T>((static_cast<int32_T>(sz[1]) - 1) + 1LL), &grid,
        &block, 1024U, 65535U);
    if (xneg) {
      EvaluationPath_GPU_kernel18<<<grid, block>>>(
          static_cast<int32_T>(sz[1]) - 1, gpu_FPMcost);
      FPMcost_dirtyOnGpu = true;
    }
  } else {
    npages = b_x->size[1];
    i = FPMcost->size[0] * FPMcost->size[1];
    FPMcost->size[0] = 1;
    FPMcost->size[1] = b_x->size[1];
    emxEnsureCapacity_real_T(FPMcost, i);
    gpuEmxEnsureCapacity_real_T(FPMcost, &gpu_FPMcost);
    b_obj = b_x->size[0];
    xneg = mwGetLaunchParameters1D(static_cast<real_T>((npages - 1) + 1LL),
                                   &grid, &block, 1024U, 65535U);
    if (xneg) {
      EvaluationPath_GPU_kernel17<<<grid, block>>>(vlen, gpu_x, npages, b_obj,
                                                   gpu_FPMcost);
      FPMcost_dirtyOnGpu = true;
    }
  }
  emxFree_real_T(&b_x);
  cudaMemcpy(*gpu_pu, pu, 336000ULL, cudaMemcpyHostToDevice);
  EvaluationPath_GPU_kernel19<<<dim3(40U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
      *gpu_pu, *gpu_y);
  EvaluationPath_GPU_kernel20<<<dim3(2U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
      *gpu_y, *b_gpu_y);
  cudaMemcpy(gpu_obj, obj, 1008072ULL, cudaMemcpyHostToDevice);
  EvaluationPath_GPU_kernel21<<<dim3(40U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
      gpu_obj, *gpu_pu, *gpu_a);
  EvaluationPath_GPU_kernel22<<<dim3(40U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
      *gpu_a, *gpu_y);
  EvaluationPath_GPU_kernel23<<<dim3(2U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
      *gpu_y, *c_gpu_y);
  EvaluationPath_GPU_kernel24<<<dim3(40U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
      *gpu_pu, *gpu_a);
  EvaluationPath_GPU_kernel25<<<dim3(40U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
      *gpu_a, *gpu_y);
  EvaluationPath_GPU_kernel26<<<dim3(2U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
      *gpu_y, *gpu_dv);
  if (FPMcost->size[1] == 1) {
    b_obj = static_cast<int32_T>(obj->NP);
  } else {
    b_obj = FPMcost->size[1];
  }
  if ((FPMcost->size[1] == static_cast<int32_T>(obj->NP)) &&
      (b_obj == static_cast<int32_T>(obj->NP))) {
    scale = obj->R[1];
    absxk = obj->R[0];
    b_iv[1] = static_cast<int32_T>(obj->NP);
    i = pw->size[0] * pw->size[1];
    pw->size[0] = 1;
    pw->size[1] = static_cast<int32_T>(obj->NP);
    emxEnsureCapacity_real_T(pw, i);
    xneg = mwGetLaunchParameters1D(
        static_cast<real_T>((static_cast<int32_T>(obj->NP) - 1) + 1LL), &grid,
        &block, 1024U, 65535U);
    if (xneg) {
      gpuEmxMemcpyCpuToGpu_real_T(&gpu_pw, pw);
      EvaluationPath_GPU_kernel27<<<grid, block>>>(
          gpu_obj, *gpu_dv, absxk, *c_gpu_y, scale, *b_gpu_y, gpu_FPMcost,
          b_iv[1] - 1, gpu_pw);
      pw_dirtyOnGpu = true;
    }
  } else {
    if (FPMcost_dirtyOnGpu) {
      gpuEmxMemcpyGpuToCpu_real_T(FPMcost, &gpu_FPMcost);
    }
    cudaMemcpy(y, *b_gpu_y, 8000ULL, cudaMemcpyDeviceToHost);
    cudaMemcpy(b_y, *c_gpu_y, 8000ULL, cudaMemcpyDeviceToHost);
    cudaMemcpy(dv, *gpu_dv, 8000ULL, cudaMemcpyDeviceToHost);
    binary_expand_op(pw, FPMcost, y, obj, b_y, dv);
  }
  emxFree_real_T(&FPMcost);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  if (pw_dirtyOnGpu) {
    gpuEmxMemcpyGpuToCpu_real_T(pw, &gpu_pw);
  }
  if (remove_sample_dirtyOnGpu) {
    gpuEmxMemcpyGpuToCpu_boolean_T(remove_sample, &gpu_remove_sample);
  }
  gpuEmxFree_real_T(&gpu_grade);
  gpuEmxFree_boolean_T(&gpu_remove_sample);
  gpuEmxFree_real_T(&gpu_grade_temp);
  gpuEmxFree_real_T(&gpu_x);
  gpuEmxFree_real_T(&gpu_FPMcost);
  cudaFree(*gpu_pu);
  cudaFree(*gpu_y);
  cudaFree(*b_gpu_y);
  cudaFree(gpu_obj);
  cudaFree(*gpu_a);
  cudaFree(*c_gpu_y);
  cudaFree(*gpu_dv);
  gpuEmxFree_real_T(&gpu_th_min);
  gpuEmxFree_real_T(&gpu_th_max);
  gpuEmxFree_real_T(&gpu_grade_obs);
  gpuEmxFree_real_T(&b_gpu_a);
  gpuEmxFree_real_T(&gpu_phaiR);
  gpuEmxFree_real_T(&gpu_PoQo);
  gpuEmxFree_real_T(&gpu_distance_obs);
  gpuEmxFree_real_T(&gpu_pw);
  cudaFree(*gpu_state);
  cudaFree(*gpu_preobs);
  cudaFree(*b_gpu_x);
  gpuEmxFree_boolean_T(&c_gpu_x);
}

// End of code generation (EvaluationPath_GPU.cu)
