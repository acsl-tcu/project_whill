//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  ProcessConstructorArguments.cpp
//
//  Code generation for function 'ProcessConstructorArguments'
//


// Include files
#include "ProcessConstructorArguments.h"
#include "HelperBoundingBoxDetector.h"
#include "SystemProp.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
namespace coder
{
  namespace matlab
  {
    namespace system
    {
      namespace coder
      {
        void ProcessConstructorArguments::b_do(HelperBoundingBoxDetector *obj)
        {
          static const real_T varargin_12[9] = { 0.001, 0.0, 0.0, 0.0, 0.001,
            0.0, 0.0, 0.0, 0.001 };

          SystemProp::matlabCodegenNotifyAnyProp(obj);
          SystemProp::matlabCodegenNotifyAnyProp(obj);
          SystemProp::matlabCodegenNotifyAnyProp(obj);
          SystemProp::matlabCodegenNotifyAnyProp(obj);
          obj->SegmentationMinDistance = 0.2;
          SystemProp::matlabCodegenNotifyAnyProp(obj);
          obj->MinDetectionsPerCluster = 20.0;
          SystemProp::matlabCodegenNotifyAnyProp(obj);
          memcpy(&obj->MeasurementNoise[0], &varargin_12[0], 9U * sizeof(real_T));
          SystemProp::matlabCodegenNotifyAnyProp(obj);
          obj->GroundMaxDistance = 0.3;
        }
      }
    }
  }
}

// End of code generation (ProcessConstructorArguments.cpp)
