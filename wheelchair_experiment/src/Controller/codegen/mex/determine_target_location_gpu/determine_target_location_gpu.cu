//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// determine_target_location_gpu.cu
//
// Code generation for function 'determine_target_location_gpu'
//

// Include files
#include "determine_target_location_gpu.h"
#include "determine_target_location_gpu_data.h"
#include "determine_target_location_gpu_emxutil.h"
#include "determine_target_location_gpu_types.h"
#include "rt_nonfinite.h"
#include "MWCudaDimUtility.hpp"
#include "MWCudaMemoryFunctions.hpp"
#include "MWLaunchParametersUtilities.hpp"
#include <cstring>

// Variable Definitions
static emlrtRTEInfo emlrtRTEI{
    6,                               // lineNo
    25,                              // colNo
    "determine_target_location_gpu", // fName
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "10\xe5\x8f\xb7"
    "\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_07_02/"
    "capsuele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6"
    "\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/"
    "determine_target_location_gpu.m" // pName
};

static emlrtRTEInfo b_emlrtRTEI{
    60,                                                             // lineNo
    20,                                                             // colNo
    "dot",                                                          // fName
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/specfun/dot.m" // pName
};

static emlrtRTEInfo c_emlrtRTEI{
    6,                               // lineNo
    21,                              // colNo
    "determine_target_location_gpu", // fName
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "10\xe5\x8f\xb7"
    "\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_07_02/"
    "capsuele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6"
    "\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/"
    "determine_target_location_gpu.m" // pName
};

static emlrtRTEInfo d_emlrtRTEI{
    6,                               // lineNo
    31,                              // colNo
    "determine_target_location_gpu", // fName
    "/home/student/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c/"
    "10\xe5\x8f\xb7"
    "\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_07_02/"
    "capsuele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6"
    "\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/Controller/"
    "determine_target_location_gpu.m" // pName
};

// Function Declarations
static void binary_expand_op(real_T in1_data[], int32_T in1_size[2],
                             const struct0_T *in2,
                             const emxArray_boolean_T *in3,
                             const int32_T in4[2]);

static void checkCudaError(cudaError_t errorCode, const char_T *file,
                           int32_T b_line);

static uint64_T computeNumIters(int32_T ub, int32_T b_ub);

static uint64_T computeNumIters(int32_T ub, int32_T b_ub, int32_T c_ub);

static uint64_T computeNumIters(int32_T ub);

static __global__ void
f_determine_target_location_gpu(const struct0_T *obj, const int32_T b_obj,
                                int32_T obj_data[210000]);

static __global__ void
g_determine_target_location_gpu(const struct0_T *obj,
                                const int32_T obj_data[210000], const int32_T b,
                                real_T dv_data[420000]);

static void gpuEmxEnsureCapacity_boolean_T(const emxArray_boolean_T *cpu,
                                           emxArray_boolean_T *gpu,
                                           boolean_T needsCopy);

static void gpuEmxEnsureCapacity_real_T(const emxArray_real_T *cpu,
                                        emxArray_real_T *gpu,
                                        boolean_T needsCopy);

static void gpuEmxFree_boolean_T(emxArray_boolean_T *gpu);

static void gpuEmxFree_real_T(emxArray_real_T *gpu);

static void gpuEmxMemcpyCpuToGpu_real_T(emxArray_real_T *gpu,
                                        const emxArray_real_T *cpu);

static void gpuEmxMemcpyGpuToCpu_boolean_T(emxArray_boolean_T *cpu,
                                           emxArray_boolean_T *gpu);

static void gpuEmxMemcpyGpuToCpu_real_T(emxArray_real_T *cpu,
                                        emxArray_real_T *gpu);

static void gpuEmxReset_boolean_T(emxArray_boolean_T *gpu);

static void gpuEmxReset_real_T(emxArray_real_T *gpu);

static void gpuThrowError(uint32_T errorCode, const char_T *errorName,
                          const char_T *errorString, const char_T *file,
                          int32_T b_line);

static void gpuThrowError(const char_T *file, int32_T b_line);

static __global__ void h_determine_target_location_gpu(const struct0_T *obj,
                                                       const int32_T b,
                                                       real_T dv1_data[420000]);

static __global__ void
i_determine_target_location_gpu(const real_T dv_data[420000],
                                const real_T dv1_data[420000],
                                const int32_T obj, emxArray_real_T a);

static __global__ void j_determine_target_location_gpu(const real_T px_data[],
                                                       const int32_T px_size,
                                                       real_T dv_data[420000]);

static __global__ void
k_determine_target_location_gpu(const real_T dv1_data[420000],
                                const real_T dv_data[420000], const int32_T b,
                                emxArray_real_T b_b);

static __global__ void l_determine_target_location_gpu(const emxArray_real_T c,
                                                       const int32_T b_c,
                                                       emxArray_boolean_T a);

static __global__ void m_determine_target_location_gpu(
    const int32_T npages, const emxArray_boolean_T a, const struct0_T *obj,
    const int32_T b_obj, real_T tgt_n_data[]);

// Function Definitions
static void binary_expand_op(real_T in1_data[], int32_T in1_size[2],
                             const struct0_T *in2,
                             const emxArray_boolean_T *in3,
                             const int32_T in4[2])
{
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T aux_2_1;
  int32_T b_in2;
  int32_T i;
  int32_T in4_idx_0;
  int32_T in4_idx_1;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  int32_T stride_2_1;
  in4_idx_0 = in4[0];
  in4_idx_1 = in4[1];
  b_in2 = in2->waypoint.size[0];
  in1_size[0] = 21;
  if (in2->target_n.size[1] == 1) {
    i = in4_idx_1;
  } else {
    i = in2->target_n.size[1];
  }
  if (i == 1) {
    in1_size[1] = in2->target_n.size[1];
  } else if (in2->target_n.size[1] == 1) {
    in1_size[1] = in4_idx_1;
  } else {
    in1_size[1] = in2->target_n.size[1];
  }
  stride_0_1 = (in2->target_n.size[1] != 1);
  stride_1_0 = (in4_idx_0 != 1);
  stride_1_1 = (in4_idx_1 != 1);
  stride_2_1 = (in2->target_n.size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  aux_2_1 = 0;
  if (in2->target_n.size[1] == 1) {
    i = in4_idx_1;
  } else {
    i = in2->target_n.size[1];
  }
  if (i == 1) {
    in4_idx_1 = in2->target_n.size[1];
  } else if (in2->target_n.size[1] != 1) {
    in4_idx_1 = in2->target_n.size[1];
  }
  for (i = 0; i < in4_idx_1; i++) {
    for (int32_T i1{0}; i1 < 21; i1++) {
      in1_data[i1 + 21 * i] =
          in2->target_n.data[i1 + 21 * aux_0_1] +
          static_cast<real_T>(
              in3->data[i1 * stride_1_0 + in4_idx_0 * aux_1_1] &&
              (in2->target_n.data[i1 + 21 * aux_2_1] != b_in2));
    }
    aux_2_1 += stride_2_1;
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

static void checkCudaError(cudaError_t errorCode, const char_T *file,
                           int32_T b_line)
{
  if (errorCode != cudaSuccess) {
    gpuThrowError(errorCode, cudaGetErrorName(errorCode),
                  cudaGetErrorString(errorCode), file, b_line);
  }
}

static uint64_T computeNumIters(int32_T ub, int32_T b_ub)
{
  uint64_T n;
  uint64_T numIters;
  boolean_T overflow;
  overflow = false;
  n = 0UL;
  if (ub >= 0) {
    n = static_cast<uint64_T>(ub + 1);
  }
  numIters = n;
  n = 0UL;
  if (b_ub >= 0) {
    n = static_cast<uint64_T>(b_ub + 1);
    overflow = (numIters > MAX_uint64_T / static_cast<uint64_T>(b_ub + 1));
  }
  numIters *= n;
  if (overflow) {
    gpuThrowError(__FILE__, __LINE__);
  }
  return numIters;
}

static uint64_T computeNumIters(int32_T ub, int32_T b_ub, int32_T c_ub)
{
  uint64_T n;
  uint64_T numIters;
  boolean_T overflow;
  overflow = false;
  n = 0UL;
  if (ub >= 0) {
    n = static_cast<uint64_T>(ub + 1);
  }
  numIters = n;
  n = 0UL;
  if (b_ub >= 0) {
    n = static_cast<uint64_T>(b_ub + 1);
    overflow = (numIters > MAX_uint64_T / static_cast<uint64_T>(b_ub + 1));
  }
  numIters *= n;
  n = 0UL;
  if (c_ub >= 0) {
    n = static_cast<uint64_T>(c_ub + 1);
    overflow = ((numIters > MAX_uint64_T / static_cast<uint64_T>(c_ub + 1)) ||
                overflow);
  }
  numIters *= n;
  if (overflow) {
    gpuThrowError(__FILE__, __LINE__);
  }
  return numIters;
}

static uint64_T computeNumIters(int32_T ub)
{
  uint64_T numIters;
  numIters = 0UL;
  if (ub >= 0) {
    numIters = static_cast<uint64_T>(ub + 1);
  }
  return numIters;
}

static __global__
    __launch_bounds__(1024, 1) void f_determine_target_location_gpu(
        const struct0_T *obj, const int32_T b_obj, int32_T obj_data[210000])
{
  uint64_T gStride;
  uint64_T gThreadId;
  uint64_T loopEnd;
  gThreadId = mwGetGlobalThreadIndex();
  gStride = mwGetTotalThreadsLaunched();
  loopEnd = static_cast<uint64_T>(b_obj);
  for (uint64_T idx{gThreadId}; idx <= loopEnd; idx += gStride) {
    int32_T i;
    i = static_cast<int32_T>(idx);
    obj_data[i] = static_cast<int32_T>(obj->target_n.data[i] - 1.0);
  }
}

static __global__
    __launch_bounds__(1024, 1) void g_determine_target_location_gpu(
        const struct0_T *obj, const int32_T obj_data[210000], const int32_T b,
        real_T dv_data[420000])
{
  uint64_T gStride;
  uint64_T gThreadId;
  uint64_T loopEnd;
  gThreadId = mwGetGlobalThreadIndex();
  gStride = mwGetTotalThreadsLaunched();
  loopEnd = (static_cast<uint64_T>(b) + 1UL) * 2UL - 1UL;
  for (uint64_T idx{gThreadId}; idx <= loopEnd; idx += gStride) {
    int32_T i;
    int32_T i1;
    i1 = static_cast<int32_T>(idx % 2UL);
    i = static_cast<int32_T>((idx - static_cast<uint64_T>(i1)) / 2UL);
    dv_data[i1 + 2 * i] =
        obj->waypoint.data[(obj_data[i] + obj->waypoint.size[0] * i1) - 1];
  }
}

static void gpuEmxEnsureCapacity_boolean_T(const emxArray_boolean_T *cpu,
                                           emxArray_boolean_T *gpu,
                                           boolean_T needsCopy)
{
  int32_T i;
  int32_T totalSizeCpu;
  int32_T totalSizeGpu;
  boolean_T *newData;
  if (gpu->numDimensions == 0) {
    gpu->numDimensions = cpu->numDimensions;
    gpu->size = static_cast<int32_T *>(emlrtCallocMex(
        static_cast<uint32_T>(gpu->numDimensions), sizeof(int32_T)));
  }
  totalSizeCpu = 1;
  totalSizeGpu = 1;
  for (i = 0; i < cpu->numDimensions; i++) {
    totalSizeGpu *= gpu->size[i];
    totalSizeCpu *= cpu->size[i];
    gpu->size[i] = cpu->size[i];
  }
  if (((totalSizeCpu == 0) && (cpu->allocatedSize > 0)) ||
      (gpu->allocatedSize < totalSizeCpu)) {
    i = cpu->allocatedSize;
    if (i < totalSizeCpu) {
      i = totalSizeCpu;
    }
    checkCudaError(
        mwCudaMalloc(&newData, static_cast<uint32_T>(i) * sizeof(boolean_T)),
        __FILE__, __LINE__);
    needsCopy = (needsCopy && (totalSizeGpu > 0));
    if (needsCopy) {
      checkCudaError(
          cudaMemcpy(newData, gpu->data,
                     static_cast<uint32_T>(totalSizeGpu) * sizeof(boolean_T),
                     cudaMemcpyDeviceToDevice),
          __FILE__, __LINE__);
    }
    if (gpu->canFreeData) {
      checkCudaError(mwCudaFree(gpu->data), __FILE__, __LINE__);
    }
    gpu->data = newData;
    gpu->allocatedSize = i;
    gpu->canFreeData = true;
  }
}

static void gpuEmxEnsureCapacity_real_T(const emxArray_real_T *cpu,
                                        emxArray_real_T *gpu,
                                        boolean_T needsCopy)
{
  real_T *newData;
  int32_T i;
  int32_T totalSizeCpu;
  int32_T totalSizeGpu;
  if (gpu->numDimensions == 0) {
    gpu->numDimensions = cpu->numDimensions;
    gpu->size = static_cast<int32_T *>(emlrtCallocMex(
        static_cast<uint32_T>(gpu->numDimensions), sizeof(int32_T)));
  }
  totalSizeCpu = 1;
  totalSizeGpu = 1;
  for (i = 0; i < cpu->numDimensions; i++) {
    totalSizeGpu *= gpu->size[i];
    totalSizeCpu *= cpu->size[i];
    gpu->size[i] = cpu->size[i];
  }
  if (((totalSizeCpu == 0) && (cpu->allocatedSize > 0)) ||
      (gpu->allocatedSize < totalSizeCpu)) {
    i = cpu->allocatedSize;
    if (i < totalSizeCpu) {
      i = totalSizeCpu;
    }
    checkCudaError(
        mwCudaMalloc(&newData, static_cast<uint32_T>(i) * sizeof(real_T)),
        __FILE__, __LINE__);
    needsCopy = (needsCopy && (totalSizeGpu > 0));
    if (needsCopy) {
      checkCudaError(
          cudaMemcpy(newData, gpu->data,
                     static_cast<uint32_T>(totalSizeGpu) * sizeof(real_T),
                     cudaMemcpyDeviceToDevice),
          __FILE__, __LINE__);
    }
    if (gpu->canFreeData) {
      checkCudaError(mwCudaFree(gpu->data), __FILE__, __LINE__);
    }
    gpu->data = newData;
    gpu->allocatedSize = i;
    gpu->canFreeData = true;
  }
}

static void gpuEmxFree_boolean_T(emxArray_boolean_T *gpu)
{
  if (gpu->data && gpu->canFreeData && (gpu->data != (void *)4207599121UL)) {
    checkCudaError(mwCudaFree(gpu->data), __FILE__, __LINE__);
  }
  emlrtFreeMex(gpu->size);
}

static void gpuEmxFree_real_T(emxArray_real_T *gpu)
{
  if (gpu->data && gpu->canFreeData && (gpu->data != (void *)4207599121UL)) {
    checkCudaError(mwCudaFree(gpu->data), __FILE__, __LINE__);
  }
  emlrtFreeMex(gpu->size);
}

static void gpuEmxMemcpyCpuToGpu_real_T(emxArray_real_T *gpu,
                                        const emxArray_real_T *cpu)
{
  int32_T actualSize;
  actualSize = 1;
  for (int32_T i{0}; i < cpu->numDimensions; i++) {
    actualSize *= cpu->size[i];
  }
  if (cpu->data) {
    checkCudaError(
        cudaMemcpy(gpu->data, cpu->data,
                   static_cast<uint32_T>(actualSize) * sizeof(real_T),
                   cudaMemcpyHostToDevice),
        __FILE__, __LINE__);
  }
}

static void gpuEmxMemcpyGpuToCpu_boolean_T(emxArray_boolean_T *cpu,
                                           emxArray_boolean_T *gpu)
{
  int32_T actualSize;
  actualSize = 1;
  for (int32_T i{0}; i < cpu->numDimensions; i++) {
    actualSize *= cpu->size[i];
  }
  if (gpu->data) {
    checkCudaError(
        cudaMemcpy(cpu->data, gpu->data,
                   static_cast<uint32_T>(actualSize) * sizeof(boolean_T),
                   cudaMemcpyDeviceToHost),
        __FILE__, __LINE__);
  }
}

static void gpuEmxMemcpyGpuToCpu_real_T(emxArray_real_T *cpu,
                                        emxArray_real_T *gpu)
{
  int32_T actualSize;
  actualSize = 1;
  for (int32_T i{0}; i < cpu->numDimensions; i++) {
    actualSize *= cpu->size[i];
  }
  if (gpu->data) {
    checkCudaError(
        cudaMemcpy(cpu->data, gpu->data,
                   static_cast<uint32_T>(actualSize) * sizeof(real_T),
                   cudaMemcpyDeviceToHost),
        __FILE__, __LINE__);
  }
}

static void gpuEmxReset_boolean_T(emxArray_boolean_T *gpu)
{
  std::memset(gpu, 0, sizeof(emxArray_boolean_T));
}

static void gpuEmxReset_real_T(emxArray_real_T *gpu)
{
  std::memset(gpu, 0, sizeof(emxArray_real_T));
}

static void gpuThrowError(const char_T *file, int32_T b_line)
{
  emlrtRTEInfo rtInfo;
  rtInfo.lineNo = b_line;
  rtInfo.colNo = 0;
  rtInfo.fName = "";
  rtInfo.pName = file;
  emlrtCUDAError(
      0U, (char_T *)"_",
      (char_T
           *)"Unable to launch kernel. Loop nest contains too many iterations.",
      &rtInfo, emlrtRootTLSGlobal);
}

static void gpuThrowError(uint32_T errorCode, const char_T *errorName,
                          const char_T *errorString, const char_T *file,
                          int32_T b_line)
{
  emlrtRTEInfo rtInfo;
  rtInfo.lineNo = b_line;
  rtInfo.colNo = 0;
  rtInfo.fName = "";
  rtInfo.pName = file;
  emlrtCUDAError(errorCode, (char_T *)errorName, (char_T *)errorString, &rtInfo,
                 emlrtRootTLSGlobal);
}

static __global__
    __launch_bounds__(1024, 1) void h_determine_target_location_gpu(
        const struct0_T *obj, const int32_T b, real_T dv1_data[420000])
{
  uint64_T gStride;
  uint64_T gThreadId;
  uint64_T loopEnd;
  gThreadId = mwGetGlobalThreadIndex();
  gStride = mwGetTotalThreadsLaunched();
  loopEnd = (static_cast<uint64_T>(b) + 1UL) * 2UL - 1UL;
  for (uint64_T idx{gThreadId}; idx <= loopEnd; idx += gStride) {
    int32_T i;
    int32_T i1;
    i1 = static_cast<int32_T>(idx % 2UL);
    i = static_cast<int32_T>((idx - static_cast<uint64_T>(i1)) / 2UL);
    dv1_data[i1 + 2 * i] =
        obj->waypoint.data[(static_cast<int32_T>(obj->target_n.data[i]) +
                            obj->waypoint.size[0] * i1) -
                           1];
  }
}

static __global__ __launch_bounds__(
    1024, 1) void i_determine_target_location_gpu(const real_T dv_data[420000],
                                                  const real_T dv1_data[420000],
                                                  const int32_T obj,
                                                  emxArray_real_T a)
{
  uint64_T gStride;
  uint64_T gThreadId;
  uint64_T loopEnd;
  gThreadId = mwGetGlobalThreadIndex();
  gStride = mwGetTotalThreadsLaunched();
  loopEnd = static_cast<uint64_T>(obj);
  for (uint64_T idx{gThreadId}; idx <= loopEnd; idx += gStride) {
    int32_T i;
    i = static_cast<int32_T>(idx);
    a.data[i] = dv1_data[i] - dv_data[i];
  }
}

static __global__
    __launch_bounds__(1024, 1) void j_determine_target_location_gpu(
        const real_T px_data[], const int32_T px_size, real_T dv_data[420000])
{
  uint64_T gStride;
  uint64_T gThreadId;
  uint64_T loopEnd;
  gThreadId = mwGetGlobalThreadIndex();
  gStride = mwGetTotalThreadsLaunched();
  loopEnd = (static_cast<uint64_T>(px_size) + 1UL) * 21UL * 2UL - 1UL;
  for (uint64_T idx{gThreadId}; idx <= loopEnd; idx += gStride) {
    uint64_T tmpIndex;
    int32_T i;
    int32_T i1;
    int32_T i2;
    i2 = static_cast<int32_T>(idx % 2UL);
    tmpIndex = (idx - static_cast<uint64_T>(i2)) / 2UL;
    i1 = static_cast<int32_T>(tmpIndex % 21UL);
    tmpIndex = (tmpIndex - static_cast<uint64_T>(i1)) / 21UL;
    i = static_cast<int32_T>(tmpIndex);
    dv_data[(i2 + 2 * i1) + 42 * i] = px_data[(i2 + 3 * i1) + 63 * i];
  }
}

static __global__ __launch_bounds__(
    1024, 1) void k_determine_target_location_gpu(const real_T dv1_data[420000],
                                                  const real_T dv_data[420000],
                                                  const int32_T b,
                                                  emxArray_real_T b_b)
{
  uint64_T gStride;
  uint64_T gThreadId;
  uint64_T loopEnd;
  gThreadId = mwGetGlobalThreadIndex();
  gStride = mwGetTotalThreadsLaunched();
  loopEnd = static_cast<uint64_T>(b);
  for (uint64_T idx{gThreadId}; idx <= loopEnd; idx += gStride) {
    int32_T i;
    i = static_cast<int32_T>(idx);
    b_b.data[i] = dv_data[i] - dv1_data[i];
  }
}

static __global__
    __launch_bounds__(1024, 1) void l_determine_target_location_gpu(
        const emxArray_real_T c, const int32_T b_c, emxArray_boolean_T a)
{
  uint64_T gStride;
  uint64_T gThreadId;
  uint64_T loopEnd;
  gThreadId = mwGetGlobalThreadIndex();
  gStride = mwGetTotalThreadsLaunched();
  loopEnd = static_cast<uint64_T>(b_c);
  for (uint64_T idx{gThreadId}; idx <= loopEnd; idx += gStride) {
    int32_T i;
    i = static_cast<int32_T>(idx);
    a.data[i] = (c.data[i] >= 0.0);
  }
}

static __global__
    __launch_bounds__(1024, 1) void m_determine_target_location_gpu(
        const int32_T npages, const emxArray_boolean_T a, const struct0_T *obj,
        const int32_T b_obj, real_T tgt_n_data[])
{
  uint64_T gStride;
  uint64_T gThreadId;
  uint64_T loopEnd;
  gThreadId = mwGetGlobalThreadIndex();
  gStride = mwGetTotalThreadsLaunched();
  loopEnd = static_cast<uint64_T>(b_obj);
  for (uint64_T idx{gThreadId}; idx <= loopEnd; idx += gStride) {
    real_T d;
    int32_T i;
    i = static_cast<int32_T>(idx);
    d = obj->target_n.data[i];
    tgt_n_data[i] = d + static_cast<real_T>(a.data[i] &&
                                            (d != static_cast<real_T>(npages)));
  }
}

void determine_target_location_gpu(const struct0_T *cpu_obj,
                                   const real_T cpu_px_data[],
                                   const int32_T px_size[3],
                                   real_T cpu_tgt_n_data[],
                                   int32_T tgt_n_size[2])
{
  dim3 block;
  dim3 grid;
  emxArray_boolean_T b_gpu_a;
  emxArray_boolean_T *b_cpu_a;
  emxArray_real_T gpu_a;
  emxArray_real_T gpu_b;
  emxArray_real_T gpu_c;
  emxArray_real_T *cpu_a;
  emxArray_real_T *cpu_b;
  emxArray_real_T *cpu_c;
  struct0_T *gpu_obj;
  real_T(*gpu_dv1_data)[420000];
  real_T(*gpu_dv_data)[420000];
  real_T *gpu_px_data;
  real_T *gpu_tgt_n_data;
  uint64_T numIters;
  int32_T(*gpu_obj_data)[210000];
  int32_T szb[2];
  int32_T i2;
  int32_T npages;
  boolean_T a_outdatedOnCpu;
  boolean_T b_outdatedOnCpu;
  boolean_T c_outdatedOnGpu;
  boolean_T validLaunchParams;
  gpuEmxReset_boolean_T(&b_gpu_a);
  gpuEmxReset_real_T(&gpu_c);
  gpuEmxReset_real_T(&gpu_b);
  gpuEmxReset_real_T(&gpu_a);
  checkCudaError(mwCudaMalloc(&gpu_dv1_data, 3360000UL), __FILE__, __LINE__);
  checkCudaError(mwCudaMalloc(&gpu_dv_data, 3360000UL), __FILE__, __LINE__);
  checkCudaError(mwCudaMalloc(&gpu_obj_data, 840000UL), __FILE__, __LINE__);
  checkCudaError(mwCudaMalloc(&gpu_tgt_n_data, 8820000U * sizeof(real_T)),
                 __FILE__, __LINE__);
  checkCudaError(mwCudaMalloc(&gpu_px_data, 630000U * sizeof(real_T)), __FILE__,
                 __LINE__);
  checkCudaError(mwCudaMalloc(&gpu_obj, 1680832UL), __FILE__, __LINE__);
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  //  waypointの更新
  i2 = 21 * cpu_obj->target_n.size[1] - 1;
  mwGetLaunchParameters1D(computeNumIters(i2), &grid, &block, 2147483647U);
  checkCudaError(
      cudaMemcpy(gpu_obj, cpu_obj, 1680832UL, cudaMemcpyHostToDevice), __FILE__,
      __LINE__);
  validLaunchParams = mwValidateLaunchParameters(grid, block);
  if (validLaunchParams) {
    f_determine_target_location_gpu<<<grid, block>>>(gpu_obj, i2,
                                                     *gpu_obj_data);
  }
  i2 = 21 * cpu_obj->target_n.size[1];
  numIters = computeNumIters(i2 - 1, 1);
  mwGetLaunchParameters1D(numIters, &grid, &block, 2147483647U);
  validLaunchParams = mwValidateLaunchParameters(grid, block);
  if (validLaunchParams) {
    g_determine_target_location_gpu<<<grid, block>>>(gpu_obj, *gpu_obj_data,
                                                     i2 - 1, *gpu_dv_data);
  }
  i2 = 21 * cpu_obj->target_n.size[1];
  numIters = computeNumIters(i2 - 1, 1);
  mwGetLaunchParameters1D(numIters, &grid, &block, 2147483647U);
  validLaunchParams = mwValidateLaunchParameters(grid, block);
  if (validLaunchParams) {
    h_determine_target_location_gpu<<<grid, block>>>(gpu_obj, i2 - 1,
                                                     *gpu_dv1_data);
  }
  emxInit_real_T(&cpu_a, 4, &emlrtRTEI, true);
  npages = cpu_a->size[0] * cpu_a->size[1] * cpu_a->size[2] * cpu_a->size[3];
  cpu_a->size[0] = 1;
  cpu_a->size[1] = 2;
  cpu_a->size[2] = static_cast<int32_T>(cpu_obj->K);
  cpu_a->size[3] = static_cast<int32_T>(cpu_obj->NP);
  emxEnsureCapacity_real_T(cpu_a, npages, &emlrtRTEI);
  i2 =
      2 * static_cast<int32_T>(cpu_obj->K) * static_cast<int32_T>(cpu_obj->NP) -
      1;
  mwGetLaunchParameters1D(computeNumIters(i2), &grid, &block, 2147483647U);
  gpuEmxEnsureCapacity_real_T(cpu_a, &gpu_a, true);
  validLaunchParams = mwValidateLaunchParameters(grid, block);
  if (validLaunchParams) {
    i_determine_target_location_gpu<<<grid, block>>>(*gpu_dv_data,
                                                     *gpu_dv1_data, i2, gpu_a);
  }
  a_outdatedOnCpu = true;
  emxInit_real_T(&cpu_b, 4, &d_emlrtRTEI, true);
  numIters = computeNumIters(px_size[2] - 1, 20, 1);
  mwGetLaunchParameters1D(numIters, &grid, &block, 2147483647U);
  checkCudaError(
      cudaMemcpy(gpu_px_data, cpu_px_data,
                 static_cast<uint32_T>(3 * (21 * px_size[2])) * sizeof(real_T),
                 cudaMemcpyHostToDevice),
      __FILE__, __LINE__);
  validLaunchParams = mwValidateLaunchParameters(grid, block);
  if (validLaunchParams) {
    j_determine_target_location_gpu<<<grid, block>>>(
        gpu_px_data, px_size[2] - 1, *gpu_dv_data);
  }
  npages = cpu_b->size[0] * cpu_b->size[1] * cpu_b->size[2] * cpu_b->size[3];
  cpu_b->size[0] = 1;
  cpu_b->size[1] = 2;
  cpu_b->size[2] = static_cast<int32_T>(cpu_obj->K);
  cpu_b->size[3] = static_cast<int32_T>(cpu_obj->NP);
  emxEnsureCapacity_real_T(cpu_b, npages, &d_emlrtRTEI);
  i2 =
      2 * static_cast<int32_T>(cpu_obj->K) * static_cast<int32_T>(cpu_obj->NP) -
      1;
  mwGetLaunchParameters1D(computeNumIters(i2), &grid, &block, 2147483647U);
  gpuEmxEnsureCapacity_real_T(cpu_b, &gpu_b, true);
  validLaunchParams = mwValidateLaunchParameters(grid, block);
  if (validLaunchParams) {
    k_determine_target_location_gpu<<<grid, block>>>(*gpu_dv1_data,
                                                     *gpu_dv_data, i2, gpu_b);
  }
  b_outdatedOnCpu = true;
  emxInit_real_T(&cpu_c, 4, &c_emlrtRTEI, true);
  c_outdatedOnGpu = false;
  npages = cpu_c->size[0] * cpu_c->size[1] * cpu_c->size[2] * cpu_c->size[3];
  cpu_c->size[0] = 1;
  cpu_c->size[1] = 1;
  cpu_c->size[2] = cpu_a->size[2];
  cpu_c->size[3] = cpu_a->size[3];
  emxEnsureCapacity_real_T(cpu_c, npages, &b_emlrtRTEI);
  npages = cpu_a->size[2] * cpu_a->size[3];
  i2 = 1;
  for (int32_T px_size_idx_2{0}; px_size_idx_2 < npages; px_size_idx_2++) {
    int32_T i1;
    i1 = i2 - 1;
    i2 += 2;
    if (a_outdatedOnCpu) {
      gpuEmxMemcpyGpuToCpu_real_T(cpu_a, &gpu_a);
    }
    a_outdatedOnCpu = false;
    if (b_outdatedOnCpu) {
      gpuEmxMemcpyGpuToCpu_real_T(cpu_b, &gpu_b);
    }
    b_outdatedOnCpu = false;
    cpu_c->data[px_size_idx_2] = cpu_a->data[i1] * cpu_b->data[i1] +
                                 cpu_a->data[i1 + 1] * cpu_b->data[i1 + 1];
    c_outdatedOnGpu = true;
  }
  emxFree_real_T(&cpu_b);
  emxFree_real_T(&cpu_a);
  emxInit_boolean_T(&b_cpu_a, 4, &c_emlrtRTEI, true);
  npages =
      b_cpu_a->size[0] * b_cpu_a->size[1] * b_cpu_a->size[2] * b_cpu_a->size[3];
  b_cpu_a->size[0] = 1;
  b_cpu_a->size[1] = 1;
  b_cpu_a->size[2] = cpu_c->size[2];
  b_cpu_a->size[3] = cpu_c->size[3];
  emxEnsureCapacity_boolean_T(b_cpu_a, npages, &c_emlrtRTEI);
  i2 = cpu_c->size[2] * cpu_c->size[3] - 1;
  mwGetLaunchParameters1D(computeNumIters(i2), &grid, &block, 2147483647U);
  gpuEmxEnsureCapacity_real_T(cpu_c, &gpu_c, !c_outdatedOnGpu);
  gpuEmxEnsureCapacity_boolean_T(b_cpu_a, &b_gpu_a, true);
  if (c_outdatedOnGpu) {
    gpuEmxMemcpyCpuToGpu_real_T(&gpu_c, cpu_c);
  }
  validLaunchParams = mwValidateLaunchParameters(grid, block);
  if (validLaunchParams) {
    l_determine_target_location_gpu<<<grid, block>>>(gpu_c, i2, b_gpu_a);
  }
  emxFree_real_T(&cpu_c);
  szb[0] = 1;
  szb[1] = 1;
  a_outdatedOnCpu = (b_cpu_a->size[2] == 1);
  if ((!a_outdatedOnCpu) || (b_cpu_a->size[3] != 1)) {
    a_outdatedOnCpu = false;
  }
  if (!a_outdatedOnCpu) {
    npages = 0;
    if (b_cpu_a->size[2] != 1) {
      npages = 1;
      szb[0] = b_cpu_a->size[2];
    }
    if (b_cpu_a->size[3] != 1) {
      szb[npages] = b_cpu_a->size[3];
    }
  }
  if (szb[1] == 1) {
    i2 = cpu_obj->target_n.size[1];
  } else {
    i2 = szb[1];
  }
  if ((szb[0] == 21) && (szb[1] == cpu_obj->target_n.size[1]) &&
      (cpu_obj->target_n.size[1] == i2)) {
    tgt_n_size[0] = 21;
    tgt_n_size[1] = cpu_obj->target_n.size[1];
    i2 = 21 * cpu_obj->target_n.size[1] - 1;
    mwGetLaunchParameters1D(computeNumIters(i2), &grid, &block, 2147483647U);
    validLaunchParams = mwValidateLaunchParameters(grid, block);
    if (validLaunchParams) {
      m_determine_target_location_gpu<<<grid, block>>>(
          cpu_obj->waypoint.size[0], b_gpu_a, gpu_obj, i2, gpu_tgt_n_data);
    }
    a_outdatedOnCpu = true;
  } else {
    gpuEmxMemcpyGpuToCpu_boolean_T(b_cpu_a, &b_gpu_a);
    binary_expand_op(cpu_tgt_n_data, tgt_n_size, cpu_obj, b_cpu_a, szb);
    a_outdatedOnCpu = false;
  }
  emxFree_boolean_T(&b_cpu_a);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  if (a_outdatedOnCpu) {
    checkCudaError(
        cudaMemcpy(cpu_tgt_n_data, gpu_tgt_n_data,
                   static_cast<uint32_T>(21 * tgt_n_size[1]) * sizeof(real_T),
                   cudaMemcpyDeviceToHost),
        __FILE__, __LINE__);
  }
  checkCudaError(mwCudaFree(gpu_obj), __FILE__, __LINE__);
  checkCudaError(mwCudaFree(gpu_px_data), __FILE__, __LINE__);
  checkCudaError(mwCudaFree(gpu_tgt_n_data), __FILE__, __LINE__);
  checkCudaError(mwCudaFree(*gpu_obj_data), __FILE__, __LINE__);
  checkCudaError(mwCudaFree(*gpu_dv_data), __FILE__, __LINE__);
  checkCudaError(mwCudaFree(*gpu_dv1_data), __FILE__, __LINE__);
  gpuEmxFree_real_T(&gpu_a);
  gpuEmxFree_real_T(&gpu_b);
  gpuEmxFree_real_T(&gpu_c);
  gpuEmxFree_boolean_T(&b_gpu_a);
}

// End of code generation (determine_target_location_gpu.cu)
