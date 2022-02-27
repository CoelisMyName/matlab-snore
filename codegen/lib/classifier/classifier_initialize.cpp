//
// File: classifier_initialize.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 23:26:59
//

// Include Files
#include "classifier_initialize.h"
#include "classifier_data.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void classifier_initialize()
{
    rt_InitInfAndNaN();
    isInitialized_classifier = true;
}

//
// File trailer for classifier_initialize.cpp
//
// [EOF]
//
