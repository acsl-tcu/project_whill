//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  AssignmentCostCalculator.h
//
//  Code generation for function 'AssignmentCostCalculator'
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

// Type Declarations
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
          class ObjectTrack;
        }
      }
    }
  }

  class objectDetection;
}

// Type Definitions
struct cell_wrap_3
{
  uint32_T f1[8];
};

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
          class AssignmentCostCalculator
          {
           public:
            AssignmentCostCalculator *init();
            void step(const emlrtStack *sp, ObjectTrack *varargin_1[30], const ::
                      coder::array<objectDetection, 2U> &varargin_2, real_T
                      varargin_3, const ::coder::array<real_T, 2U> &varargin_4, ::
                      coder::array<real_T, 2U> &varargout_1);
            void setupAndReset(const emlrtStack *sp, ObjectTrack * const
                               varargin_1[30], const ::coder::array<
                               objectDetection, 2U> &varargin_2, real_T
                               varargin_3, const ::coder::array<real_T, 2U>
                               &varargin_4);
            void setup(const emlrtStack *sp, ObjectTrack * const varargin_1[30],
                       const ::coder::array<objectDetection, 2U> &varargin_2,
                       real_T varargin_3, const ::coder::array<real_T, 2U>
                       &varargin_4);
            static void findPairsToCost(const emlrtStack *sp, ObjectTrack
              *tracks[30], const ::coder::array<objectDetection, 2U> &detections,
              real_T numLiveTracks, const ::coder::array<real_T, 2U> &detIndices,
              ::coder::array<boolean_T, 2U> &toCalculate);
           protected:
            static void validateInputsImpl(const emlrtStack *sp, real_T
              numLiveTracks, const ::coder::array<real_T, 2U> &detIndices);
           private:
            int32_T isInitialized;
            cell_wrap_3 inputVarSize[4];
          };
        }
      }
    }
  }
}

// End of code generation (AssignmentCostCalculator.h)
