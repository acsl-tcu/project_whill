//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  SystemProp.cpp
//
//  Code generation for function 'SystemProp'
//


// Include files
#include "SystemProp.h"
#include "HelperBoundingBoxDetector.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace coder
{
  namespace matlab
  {
    namespace system
    {
      namespace coder
      {
        void SystemProp::matlabCodegenNotifyAnyProp(const
          HelperBoundingBoxDetector *obj)
        {
          obj->isLockedAndNotReleased();
        }
      }
    }
  }
}

// End of code generation (SystemProp.cpp)
