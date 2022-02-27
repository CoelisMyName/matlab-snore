//
// File: main.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 23:44:15
//

/*************************************************************************/
/* This automatically generated example C++ main file shows how to call  */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

// Include Files
#include "main.h"
#include "noise_segment.h"
#include "noise_segment_terminate.h"
#include "rt_nonfinite.h"
#include "vad.h"
#include "coder_array.h"

// Function Declarations
static coder::array<long long, 1U> argInit_Unboundedx1_int64_T();

static coder::array<double, 1U> argInit_Unboundedx1_real_T();

static long long argInit_int64_T();

static double argInit_real_T();

static void main_noise_segment();

static void main_vad();

// Function Definitions
//
// Arguments    : void
// Return Type  : coder::array<long long, 1U>
//
static coder::array<long long, 1U> argInit_Unboundedx1_int64_T()
{
    coder::array<long long, 1U> result;
    // Set the size of the array.
    // Change this size to the value that the application requires.
    result.set_size(2);
    // Loop over the array to initialize each element.
    for (int idx0 = 0; idx0 < result.size(0); idx0++) {
        // Set the value of the array element.
        // Change this value to the value that the application requires.
        result[idx0] = argInit_int64_T();
    }
    return result;
}

//
// Arguments    : void
// Return Type  : coder::array<double, 1U>
//
static coder::array<double, 1U> argInit_Unboundedx1_real_T()
{
    coder::array<double, 1U> result;
    // Set the size of the array.
    // Change this size to the value that the application requires.
    result.set_size(2);
    // Loop over the array to initialize each element.
    for (int idx0 = 0; idx0 < result.size(0); idx0++) {
        // Set the value of the array element.
        // Change this value to the value that the application requires.
        result[idx0] = argInit_real_T();
    }
    return result;
}

//
// Arguments    : void
// Return Type  : long long
//
static long long argInit_int64_T()
{
    return 0LL;
}

//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
    return 0.0;
}

//
// Arguments    : void
// Return Type  : void
//
static void main_noise_segment()
{
    coder::array<long long, 1U> w_starts_tmp;
    double fs_tmp;
    double olength;
    double ostart;
    // Initialize function 'noise_segment' input arguments.
    // Initialize function input argument 'w_starts'.
    w_starts_tmp = argInit_Unboundedx1_int64_T();
    // Initialize function input argument 'w_ends'.
    fs_tmp = argInit_real_T();
    // Call the entry-point 'noise_segment'.
    noise_segment(w_starts_tmp, w_starts_tmp, fs_tmp, fs_tmp, fs_tmp, &ostart,
                  &olength);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_vad()
{
    coder::array<double, 1U> x;
    coder::array<long long, 2U> w_ends;
    coder::array<long long, 2U> w_starts;
    // Initialize function 'vad' input arguments.
    // Initialize function input argument 'x'.
    x = argInit_Unboundedx1_real_T();
    // Call the entry-point 'vad'.
    vad(x, argInit_real_T(), w_starts, w_ends);
}

//
// Arguments    : int argc
//                char **argv
// Return Type  : int
//
int main(int, char **)
{
    // The initialize function is being called automatically from your
    // entry-point function. So, a call to initialize is not included here.
    // Invoke the entry-point functions.
    // You can call entry-point functions multiple times.
    main_noise_segment();
    main_vad();
    // Terminate the application.
    // You do not need to do this more than one time.
    noise_segment_terminate();
    return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
