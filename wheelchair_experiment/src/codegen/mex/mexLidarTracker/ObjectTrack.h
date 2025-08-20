//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  ObjectTrack.h
//
//  Code generation for function 'ObjectTrack'
//


#pragma once

// Include files
#include "rtwtypes.h"
#include "trackingEKF.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Declarations
namespace coder
{
  class trackHistoryLogic;
}

struct struct1_T;
namespace coder
{
  class objectDetection;
}

// Type Definitions
namespace coder
{
  namespace matlabshared
  {
    namespace tracking
    {
      namespace internal
      {
        namespace fusion
        {
          class ObjectTrack
          {
           public:
            ObjectTrack *init(trackingEKF *varargin_4, real_T varargin_10,
                              trackHistoryLogic *varargin_12);
            void set_Filter(trackingEKF *value);
            void setDependentFilterValues(const trackingEKF *filter);
            void set_TrackLogic(trackHistoryLogic *value);
            void nullify(const emlrtStack *sp);
            ObjectTrack *copy(const emlrtStack *sp, ObjectTrack *iobj_0,
                              trackHistoryLogic *iobj_1, trackingEKF *iobj_2);
            ObjectTrack *init(uint32_T varargin_2, uint32_T varargin_4, real_T
                              varargin_6, trackingEKF *varargin_8, real_T
                              varargin_10, trackHistoryLogic *varargin_12);
            void copyPrivateProperties(const emlrtStack *sp, ObjectTrack
              *newTrack);
            boolean_T checkPromotion() const;
            void get_State(real_T state[6]) const;
            void get_StateCovariance(real_T covariance[36]);
            void trackToStruct(const emlrtStack *sp, struct1_T *trackStruct);
            boolean_T get_IsCoasted() const;
            void get_ObjectAttributes(const emlrtStack *sp, int32_T value_size[2])
              const;
            void predict(const emlrtStack *sp, real_T b_time);
            void distance(const emlrtStack *sp, const ::coder::array<
                          objectDetection, 2U> &detections, const ::coder::array<
                          real_T, 2U> &sensorDetections, ::coder::array<real_T,
                          2U> &cost);
            void correctjpda(const emlrtStack *sp, const ::coder::array<
                             objectDetection, 2U> &detections, const ::coder::
                             array<real_T, 1U> &posterior);
            void setObjectAttributes(const emlrtStack *sp, real_T sensorIndex);
            void set_IsCoasted();
            void correctjpda(const emlrtStack *sp, const objectDetection
                             detections[1]);
            void updateNotAssociated(const emlrtStack *sp);
            boolean_T checkDeletion(const emlrtStack *sp) const;
            uint32_T BranchID;
            uint32_T TrackID;
            real_T Time;
            trackHistoryLogic *TrackLogic;
            boolean_T IsConfirmed;
            real_T ObjectClassID;
            real_T UpdateTime;
            trackingEKF *Filter;
            uint8_T pMotionModel;
            uint32_T pAge;
            boolean_T pIsCoasted;
            trackingEKF *pDistanceFilter;
            trackingEKF _pobj0;
           private:
            boolean_T pUsedObjectAttributes[20];
          };
        }
      }
    }
  }
}

// End of code generation (ObjectTrack.h)
