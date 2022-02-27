//
// File: main.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Feb-2022 22:09:11
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
#include "aweight.h"
#include "cweight.h"
#include "rt_nonfinite.h"
#include "test_spl_initialize.h"
#include "test_spl_terminate.h"
#include "zweight.h"
#include "coder_array.h"

// Function Declarations
static coder::array<double, 1U> argInit_Unboundedx1_real_T();

static double argInit_real_T();

static void main_aweight();

static void main_cweight();

static void main_zweight();

// Function Definitions
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
static void main_aweight()
{
    coder::array<double, 1U> x;
    double f[8];
    double p[8];
    double s;
    // Initialize function 'aweight' input arguments.
    // Initialize function input argument 'x'.
    x = argInit_Unboundedx1_real_T();
    // Call the entry-point 'aweight'.
    aweight(x, p, f, &s);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_cweight()
{
    coder::array<double, 1U> x;
    double f[8];
    double p[8];
    double s;
    // Initialize function 'cweight' input arguments.
    // Initialize function input argument 'x'.
    x = argInit_Unboundedx1_real_T();
    // Call the entry-point 'cweight'.
    cweight(x, p, f, &s);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_zweight()
{
    coder::array<double, 1U> x;
    double f[8];
    double p[8];
    double s;
    // Initialize function 'zweight' input arguments.
    // Initialize function input argument 'x'.
    x = argInit_Unboundedx1_real_T();
    // Call the entry-point 'zweight'.
    zweight(x, p, f, &s);
}

//
// Arguments    : int argc
//                char **argv
// Return Type  : int
//
int main(int, char **)
{
    // Initialize the application.
    // You do not need to do this more than one time.
    test_spl_initialize();
    // Invoke the entry-point functions.
    // You can call entry-point functions multiple times.
    main_aweight();
    main_cweight();
    main_zweight();
    // Terminate the application.
    // You do not need to do this more than one time.
    test_spl_terminate();
    return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
