//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  trackerJPDA.h
//
//  Code generation for function 'trackerJPDA'
//


#pragma once

// Include files
#include "AssignmentCostCalculator.h"
#include "ObjectTrack.h"
#include "objectDetection.h"
#include "rtwtypes.h"
#include "trackHistoryLogic.h"
#include "trackingEKF.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Declarations
struct struct1_T;
struct struct_T;

// Type Definitions
struct b_struct_T
{
  uint32_T SensorIndex;
  real_T TimeStamp;
};

namespace coder
{
  class trackerJPDA
  {
   public:
    trackerJPDA *init(const emlrtStack *sp);
    void step(const emlrtStack *sp, const ::coder::array<objectDetection, 2U>
              &varargin_1, real_T varargin_2, const real_T varargin_3_data[],
              const int32_T varargin_3_size[2], struct1_T varargout_1_data[],
              int32_T varargout_1_size[1], struct1_T varargout_2_data[], int32_T
              varargout_2_size[1], ::coder::array<struct1_T, 2U> &varargout_3);
    void setupAndReset(const emlrtStack *sp, const ::coder::array<
                       objectDetection, 2U> &varargin_1, real_T varargin_2,
                       const int32_T varargin_3_size[2]);
    void setup(const emlrtStack *sp, const ::coder::array<objectDetection, 2U>
               &varargin_1, real_T varargin_2, const int32_T varargin_3_size[2]);
    void checkTunableProps();
    static void connectedTracks(const emlrtStack *sp, const ::coder::array<
      real_T, 2U> &A, ::coder::array<real_T, 2U> &clustDets, ::coder::array<
      real_T, 2U> &clustTracks, real_T *numClusters);
    void matlabCodegenDestructor();
    void release();
    void releaseWrapper();
    ~trackerJPDA();
    trackerJPDA();
   protected:
    void validateInputsImpl(const emlrtStack *sp, real_T varargin_1) const;
    void trackDetectability(const emlrtStack *sp, const real_T varargin_2_data[],
      const int32_T varargin_2_size[2]);
    void clusterAssignUpdate(const emlrtStack *sp, ::coder::array<real_T, 2U>
      &unassignedDets, ::coder::array<real_T, 2U> &trueUnassignedTrackId, ::
      coder::array<struct_T, 2U> &clusterInfo);
    void validateClusterDetectionsTime(const emlrtStack *sp, const ::coder::
      array<real_T, 2U> &detIndices) const;
    void findTracksByIDs(const emlrtStack *sp, const ::coder::array<uint32_T, 2U>
                         &trackIDs, ::coder::array<uint32_T, 2U> &indices) const;
    void calcEventProbabilities(const emlrtStack *sp, const ::coder::array<
      boolean_T, 3U> &FJE, const ::coder::array<real_T, 2U> &lhoodMatrix, const ::
      coder::array<real_T, 2U> &clusterDetectionId, const ::coder::array<
      uint32_T, 2U> &clusterTrackId, ::coder::array<real_T, 2U> &eventProb)
      const;
    static void associationProbabilities(const emlrtStack *sp, const ::coder::
      array<boolean_T, 3U> &FJE, const ::coder::array<real_T, 2U> &FJEprobs,
      const ::coder::array<real_T, 2U> &clusterDetectionId, const ::coder::array<
      uint32_T, 2U> &clusterTrackId, ::coder::array<real_T, 2U> &posterior);
    void initializeTracks(const emlrtStack *sp, ::coder::array<real_T, 2U>
                          &OverallUnassigned, uint32_T initTrIDs_data[], int32_T
                          initTrIDs_size[2]);
    void deleteOldTracks(const emlrtStack *sp, uint32_T delTrIDs_data[], int32_T
                         delTrIDs_size[2]);
    void formatTrackOutputs(const emlrtStack *sp, struct1_T varargout_1_data[],
      int32_T varargout_1_size[1], struct1_T varargout_2_data[], int32_T
      varargout_2_size[1], ::coder::array<struct1_T, 2U> &varargout_3);
    void jpdaClusterUpdate(const emlrtStack *sp, const ::coder::array<struct_T,
      2U> &preClusters, ::coder::array<boolean_T, 2U> &isUnassignedDetection, ::
      coder::array<struct_T, 2U> &clusterInfo);
   public:
    boolean_T matlabCodegenIsDeleted;
    matlabshared::tracking::internal::fusion::ObjectTrack *pTracksList[30];
    trackingEKF _pobj0[31];
    trackHistoryLogic _pobj1[30];
    matlabshared::tracking::internal::fusion::ObjectTrack _pobj2[30];
    trackHistoryLogic _pobj3;
   protected:
    real_T pNumLiveTracks;
    uint32_T pTrackIDs[30];
    boolean_T pConfirmedTracks[30];
    trackHistoryLogic *pLogic;
    objectDetection pSampleDetection;
    trackingEKF *pDistFilter;
    array<objectDetection, 2U> pDetections;
    array<real_T, 2U> pCostMatrix;
    array<real_T, 2U> pOriginatingSensor;
    array<real_T, 2U> pDetectionTimes;
    uint32_T pLastTrackID;
    real_T pLastTimeStamp;
   private:
    int32_T isInitialized;
    boolean_T isSetupComplete;
    boolean_T TunablePropsChanged;
    cell_wrap_3 inputVarSize[3];
    boolean_T pWasDetectable[30];
    real_T pTrackDetectionProbability[30];
    b_struct_T pClusterTypeDef;
    matlabshared::tracking::internal::fusion::AssignmentCostCalculator
      cCostCalculator;
  };
}

// End of code generation (trackerJPDA.h)
