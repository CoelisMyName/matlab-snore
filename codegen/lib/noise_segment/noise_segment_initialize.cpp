//
// File: noise_segment_initialize.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 23:44:15
//

// Include Files
#include "noise_segment_initialize.h"
#include "noise_segment_data.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void noise_segment_initialize()
{
    rt_InitInfAndNaN();
    isInitialized_noise_segment = true;
}

//
// File trailer for noise_segment_initialize.cpp
//
// [EOF]
//
