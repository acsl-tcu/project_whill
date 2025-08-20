//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  pointCloud.h
//
//  Code generation for function 'pointCloud'
//


#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Definitions
namespace coder
{
  class pointCloud
  {
  };

  class b_pointCloud
  {
   public:
    b_pointCloud *init(const emlrtStack *sp, const ::coder::array<real32_T, 2U>
                       &varargin_1);
    void set_Color(const emlrtStack *sp, const ::coder::array<uint8_T, 2U>
                   &value);
    void set_Normal(const emlrtStack *sp, const ::coder::array<real32_T, 2U>
                    &value);
    void set_Intensity(const emlrtStack *sp, const ::coder::array<real32_T, 2U>
                       &value);
    void set_RangeData(const emlrtStack *sp, const ::coder::array<real32_T, 2U>
                       &value);
    real_T get_Count() const;
    void surfaceNormalImpl(const emlrtStack *sp, ::coder::array<real32_T, 2U>
      &normals);
    b_pointCloud *init(const emlrtStack *sp, const ::coder::array<real32_T, 2U>
                       &varargin_1, const ::coder::array<uint8_T, 2U>
                       &varargin_3, const ::coder::array<real32_T, 2U>
                       &varargin_5, const ::coder::array<real32_T, 2U>
                       &varargin_7);
    b_pointCloud *b_select(const emlrtStack *sp, const ::coder::array<real_T, 1U>
      &varargin_1, b_pointCloud *iobj_0) const;
    void subsetImpl(const emlrtStack *sp, const ::coder::array<real_T, 1U>
                    &indices, ::coder::array<real32_T, 2U> &loc, ::coder::array<
                    uint8_T, 2U> &c, ::coder::array<real32_T, 2U> &nv, ::coder::
                    array<real32_T, 2U> &intensity, ::coder::array<real32_T, 2U>
                    &r) const;
    void findPointsInROI(const emlrtStack *sp, const real_T varargin_1[6], ::
                         coder::array<uint32_T, 1U> &indices);
    b_pointCloud *b_select(const emlrtStack *sp, const ::coder::array<real_T, 2U>
      &varargin_1, b_pointCloud *iobj_0) const;
    void subsetImpl(const emlrtStack *sp, const ::coder::array<real_T, 2U>
                    &indices, ::coder::array<real32_T, 2U> &loc, ::coder::array<
                    uint8_T, 2U> &c, ::coder::array<real32_T, 2U> &nv, ::coder::
                    array<real32_T, 2U> &intensity, ::coder::array<real32_T, 2U>
                    &r) const;
    void removeInvalidPoints(const emlrtStack *sp, b_pointCloud *iobj_0,
      b_pointCloud **ptCloudOut, ::coder::array<real_T, 1U> &indicesOut) const;
    void extractValidPoints(const emlrtStack *sp, ::coder::array<real32_T, 2U>
      &location, ::coder::array<uint8_T, 2U> &color, ::coder::array<real32_T, 2U>
      &normals, ::coder::array<real32_T, 2U> &intensity, ::coder::array<real32_T,
      2U> &rangeData, ::coder::array<boolean_T, 1U> &indices) const;
    void b_subsetImpl(const emlrtStack *sp, const ::coder::array<boolean_T, 1U>
                      &indices, ::coder::array<real32_T, 2U> &loc, ::coder::
                      array<uint8_T, 2U> &c, ::coder::array<real32_T, 2U> &nv, ::
                      coder::array<real32_T, 2U> &intensity, ::coder::array<
                      real32_T, 2U> &r) const;
    void findNeighborsInRadius(const emlrtStack *sp, const real32_T varargin_1[3],
      real32_T varargin_2, ::coder::array<uint32_T, 1U> &indices);
    void matlabCodegenDestructor();
    ~b_pointCloud();
    b_pointCloud();
   protected:
    void buildKdtree(const emlrtStack *sp);
   public:
    boolean_T matlabCodegenIsDeleted;
    array<real32_T, 2U> Location;
    array<uint8_T, 2U> Color;
    array<real32_T, 2U> Normal;
    array<real32_T, 2U> Intensity;
    array<real32_T, 2U> RangeData;
   protected:
    void* Kdtree;
    void* LocationHandle;
    boolean_T HasKdtreeConstructed;
    boolean_T HasLocationHandleAllocated;
  };
}

// End of code generation (pointCloud.h)
