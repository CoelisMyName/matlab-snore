//
// File: main.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 27-Feb-2022 11:31:05
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
#include "SnoringRecognition_initialize.h"
#include "SnoringRecognition_terminate.h"
#include "SnoringRecognition_types.h"
#include "aweight.h"
#include "bark_feat.h"
#include "cep_feat.h"
#include "classifier.h"
#include "cweight.h"
#include "fmt_feat.h"
#include "gtcc_feat.h"
#include "mfcc_feat.h"
#include "noise_segment.h"
#include "patient_classifier.h"
#include "pitch_feat.h"
#include "pr800_feat.h"
#include "rt_nonfinite.h"
#include "se_feat.h"
#include "vad.h"
#include "zweight.h"
#include "coder_array.h"

// Variable Definitions
static SnoringRecognitionStackData SnoringRecognitionStackDataGlobal;

// Function Declarations
static coder::array<double, 2U> argInit_Unboundedx17_real_T();

static coder::array<long long, 1U> argInit_Unboundedx1_int64_T();

static coder::array<double, 1U> argInit_Unboundedx1_real_T();

static coder::array<double, 2U> argInit_Unboundedx20_real_T();

static coder::array<double, 2U> argInit_Unboundedx39_real_T();

static long long argInit_int64_T();

static double argInit_real_T();

static void main_aweight();

static void main_bark_feat();

static void main_cep_feat();

static void main_classifier();

static void main_cweight();

static void main_fmt_feat();

static void main_gtcc_feat();

static void main_mfcc_feat();

static void main_noise_segment();

static void main_patient_classifier();

static void main_pitch_feat();

static void main_pr800_feat();

static void main_se_feat();

static void main_vad();

static void main_zweight();

// Function Definitions
//
// Arguments    : void
// Return Type  : coder::array<double, 2U>
//
static coder::array<double, 2U> argInit_Unboundedx17_real_T()
{
    coder::array<double, 2U> result;
    // Set the size of the array.
    // Change this size to the value that the application requires.
    result.set_size(2, 17);
    // Loop over the array to initialize each element.
    for (int idx0 = 0; idx0 < result.size(0); idx0++) {
        for (int idx1 = 0; idx1 < 17; idx1++) {
            // Set the value of the array element.
            // Change this value to the value that the application requires.
            result[idx0 + result.size(0) * idx1] = argInit_real_T();
        }
    }
    return result;
}

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
// Return Type  : coder::array<double, 2U>
//
static coder::array<double, 2U> argInit_Unboundedx20_real_T()
{
    coder::array<double, 2U> result;
    // Set the size of the array.
    // Change this size to the value that the application requires.
    result.set_size(2, 20);
    // Loop over the array to initialize each element.
    for (int idx0 = 0; idx0 < result.size(0); idx0++) {
        for (int idx1 = 0; idx1 < 20; idx1++) {
            // Set the value of the array element.
            // Change this value to the value that the application requires.
            result[idx0 + result.size(0) * idx1] = argInit_real_T();
        }
    }
    return result;
}

//
// Arguments    : void
// Return Type  : coder::array<double, 2U>
//
static coder::array<double, 2U> argInit_Unboundedx39_real_T()
{
    coder::array<double, 2U> result;
    // Set the size of the array.
    // Change this size to the value that the application requires.
    result.set_size(2, 39);
    // Loop over the array to initialize each element.
    for (int idx0 = 0; idx0 < result.size(0); idx0++) {
        for (int idx1 = 0; idx1 < 39; idx1++) {
            // Set the value of the array element.
            // Change this value to the value that the application requires.
            result[idx0 + result.size(0) * idx1] = argInit_real_T();
        }
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
static void main_bark_feat()
{
    coder::array<double, 1U> sig;
    double barkee[17];
    // Initialize function 'bark_feat' input arguments.
    // Initialize function input argument 'sig'.
    sig = argInit_Unboundedx1_real_T();
    // Call the entry-point 'bark_feat'.
    bark_feat(sig, argInit_real_T(), barkee);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_cep_feat()
{
    coder::array<double, 1U> sig;
    double cep_data[39];
    int cep_size[2];
    // Initialize function 'cep_feat' input arguments.
    // Initialize function input argument 'sig'.
    sig = argInit_Unboundedx1_real_T();
    // Call the entry-point 'cep_feat'.
    cep_feat(sig, argInit_real_T(), cep_data, cep_size);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_classifier()
{
    coder::array<double, 1U> predict_label;
    coder::array<double, 1U> x;
    coder::array<long long, 1U> w_starts_tmp;
    // Initialize function 'classifier' input arguments.
    // Initialize function input argument 'x'.
    x = argInit_Unboundedx1_real_T();
    // Initialize function input argument 'w_starts'.
    w_starts_tmp = argInit_Unboundedx1_int64_T();
    // Initialize function input argument 'w_ends'.
    // Call the entry-point 'classifier'.
    classifier(x, argInit_real_T(), w_starts_tmp, w_starts_tmp, predict_label);
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
static void main_fmt_feat()
{
    coder::array<double, 1U> sig;
    double Formant1;
    double Formant2;
    double Formant3;
    // Initialize function 'fmt_feat' input arguments.
    // Initialize function input argument 'sig'.
    sig = argInit_Unboundedx1_real_T();
    // Call the entry-point 'fmt_feat'.
    fmt_feat(sig, argInit_real_T(), &Formant1, &Formant2, &Formant3);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_gtcc_feat()
{
    coder::array<double, 2U> GTCCmean;
    coder::array<double, 1U> sig;
    // Initialize function 'gtcc_feat' input arguments.
    // Initialize function input argument 'sig'.
    sig = argInit_Unboundedx1_real_T();
    // Call the entry-point 'gtcc_feat'.
    gtcc_feat(&SnoringRecognitionStackDataGlobal, sig, argInit_real_T(),
              GTCCmean);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_mfcc_feat()
{
    coder::array<double, 2U> MFCC_feature;
    coder::array<double, 1U> sig;
    // Initialize function 'mfcc_feat' input arguments.
    // Initialize function input argument 'sig'.
    sig = argInit_Unboundedx1_real_T();
    // Call the entry-point 'mfcc_feat'.
    mfcc_feat(sig, argInit_real_T(), MFCC_feature);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_noise_segment()
{
    coder::array<long long, 1U> starts_tmp;
    double fs_tmp;
    double olength;
    double ostart;
    // Initialize function 'noise_segment' input arguments.
    // Initialize function input argument 'starts'.
    starts_tmp = argInit_Unboundedx1_int64_T();
    // Initialize function input argument 'ends'.
    fs_tmp = argInit_real_T();
    // Call the entry-point 'noise_segment'.
    noise_segment(starts_tmp, starts_tmp, fs_tmp, fs_tmp, fs_tmp, &ostart,
                  &olength);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_patient_classifier()
{
    coder::array<double, 2U> BARKEE;
    coder::array<double, 2U> GTCCmean;
    coder::array<double, 2U> MFCC_feature_tmp;
    coder::array<double, 1U> period_mean_tmp;
    double label_OSA;
    // Initialize function 'patient_classifier' input arguments.
    // Initialize function input argument 'MFCC_feature'.
    MFCC_feature_tmp = argInit_Unboundedx39_real_T();
    // Initialize function input argument 'BARKEE'.
    BARKEE = argInit_Unboundedx17_real_T();
    // Initialize function input argument 'period_mean'.
    period_mean_tmp = argInit_Unboundedx1_real_T();
    // Initialize function input argument 'period_max'.
    // Initialize function input argument 'period_min'.
    // Initialize function input argument 'period_var'.
    // Initialize function input argument 'cep'.
    // Initialize function input argument 'Formant1'.
    // Initialize function input argument 'Formant2'.
    // Initialize function input argument 'Formant3'.
    // Initialize function input argument 'GTCCmean'.
    GTCCmean = argInit_Unboundedx20_real_T();
    // Initialize function input argument 'PR800mean'.
    // Initialize function input argument 'PR800max'.
    // Initialize function input argument 'PR800min'.
    // Initialize function input argument 'PR800var'.
    // Initialize function input argument 'SE_mean'.
    // Initialize function input argument 'SE_max'.
    // Initialize function input argument 'SE_min'.
    // Initialize function input argument 'SE_var'.
    // Call the entry-point 'patient_classifier'.
    label_OSA = patient_classifier(
        &SnoringRecognitionStackDataGlobal, MFCC_feature_tmp, BARKEE,
        period_mean_tmp, period_mean_tmp, period_mean_tmp, period_mean_tmp,
        MFCC_feature_tmp, period_mean_tmp, period_mean_tmp, period_mean_tmp,
        GTCCmean, period_mean_tmp, period_mean_tmp, period_mean_tmp,
        period_mean_tmp, period_mean_tmp, period_mean_tmp, period_mean_tmp,
        period_mean_tmp);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_pitch_feat()
{
    coder::array<double, 1U> sig;
    double period_max;
    double period_mean;
    double period_min;
    double period_var;
    // Initialize function 'pitch_feat' input arguments.
    // Initialize function input argument 'sig'.
    sig = argInit_Unboundedx1_real_T();
    // Call the entry-point 'pitch_feat'.
    pitch_feat(sig, argInit_real_T(), &period_mean, &period_min, &period_max,
               &period_var);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_pr800_feat()
{
    coder::array<double, 1U> sig;
    double PR800_max;
    double PR800_mean;
    double PR800_min;
    double PR800_var;
    // Initialize function 'pr800_feat' input arguments.
    // Initialize function input argument 'sig'.
    sig = argInit_Unboundedx1_real_T();
    // Call the entry-point 'pr800_feat'.
    pr800_feat(sig, argInit_real_T(), &PR800_mean, &PR800_max, &PR800_min,
               &PR800_var);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_se_feat()
{
    coder::array<double, 1U> sig;
    double SE_max;
    double SE_mean;
    double SE_min;
    double SE_var;
    // Initialize function 'se_feat' input arguments.
    // Initialize function input argument 'sig'.
    sig = argInit_Unboundedx1_real_T();
    // Call the entry-point 'se_feat'.
    se_feat(sig, argInit_real_T(), &SE_mean, &SE_max, &SE_min, &SE_var);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_vad()
{
    coder::array<double, 1U> x;
    coder::array<long long, 1U> w_ends;
    coder::array<long long, 1U> w_starts;
    // Initialize function 'vad' input arguments.
    // Initialize function input argument 'x'.
    x = argInit_Unboundedx1_real_T();
    // Call the entry-point 'vad'.
    vad(x, argInit_real_T(), w_starts, w_ends);
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
    SnoringRecognition_initialize();
    // Invoke the entry-point functions.
    // You can call entry-point functions multiple times.
    main_aweight();
    main_bark_feat();
    main_cep_feat();
    main_classifier();
    main_cweight();
    main_fmt_feat();
    main_gtcc_feat();
    main_mfcc_feat();
    main_noise_segment();
    main_patient_classifier();
    main_pitch_feat();
    main_pr800_feat();
    main_se_feat();
    main_vad();
    main_zweight();
    // Terminate the application.
    // You do not need to do this more than one time.
    SnoringRecognition_terminate();
    return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
