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

static SnoringRecognitionStackData SnoringRecognitionStackDataGlobal;

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

static coder::array<double, 2U> argInit_Unboundedx17_real_T()
{
    coder::array<double, 2U> result;

    result.set_size(2, 17);

    for (int idx0 = 0; idx0 < result.size(0); idx0++) {
        for (int idx1 = 0; idx1 < 17; idx1++) {

            result[idx0 + result.size(0) * idx1] = argInit_real_T();
        }
    }
    return result;
}

static coder::array<long long, 1U> argInit_Unboundedx1_int64_T()
{
    coder::array<long long, 1U> result;

    result.set_size(2);

    for (int idx0 = 0; idx0 < result.size(0); idx0++) {

        result[idx0] = argInit_int64_T();
    }
    return result;
}

static coder::array<double, 1U> argInit_Unboundedx1_real_T()
{
    coder::array<double, 1U> result;

    result.set_size(2);

    for (int idx0 = 0; idx0 < result.size(0); idx0++) {

        result[idx0] = argInit_real_T();
    }
    return result;
}

static coder::array<double, 2U> argInit_Unboundedx20_real_T()
{
    coder::array<double, 2U> result;

    result.set_size(2, 20);

    for (int idx0 = 0; idx0 < result.size(0); idx0++) {
        for (int idx1 = 0; idx1 < 20; idx1++) {

            result[idx0 + result.size(0) * idx1] = argInit_real_T();
        }
    }
    return result;
}

static coder::array<double, 2U> argInit_Unboundedx39_real_T()
{
    coder::array<double, 2U> result;

    result.set_size(2, 39);

    for (int idx0 = 0; idx0 < result.size(0); idx0++) {
        for (int idx1 = 0; idx1 < 39; idx1++) {

            result[idx0 + result.size(0) * idx1] = argInit_real_T();
        }
    }
    return result;
}

static long long argInit_int64_T()
{
    return 0LL;
}

static double argInit_real_T()
{
    return 0.0;
}

static void main_aweight()
{
    coder::array<double, 1U> x;
    double f[8];
    double p[8];
    double s;

    x = argInit_Unboundedx1_real_T();

    aweight(x, p, f, &s);
}

static void main_bark_feat()
{
    coder::array<double, 1U> sig;
    double barkee[17];

    sig = argInit_Unboundedx1_real_T();

    bark_feat(sig, argInit_real_T(), barkee);
}

static void main_cep_feat()
{
    coder::array<double, 1U> sig;
    double cep_data[39];
    int cep_size[2];

    sig = argInit_Unboundedx1_real_T();

    cep_feat(sig, argInit_real_T(), cep_data, cep_size);
}

static void main_classifier()
{
    coder::array<double, 1U> predict_label;
    coder::array<double, 1U> x;
    coder::array<long long, 1U> w_starts_tmp;

    x = argInit_Unboundedx1_real_T();

    w_starts_tmp = argInit_Unboundedx1_int64_T();

    classifier(x, argInit_real_T(), w_starts_tmp, w_starts_tmp, predict_label);
}

static void main_cweight()
{
    coder::array<double, 1U> x;
    double f[8];
    double p[8];
    double s;

    x = argInit_Unboundedx1_real_T();

    cweight(x, p, f, &s);
}

static void main_fmt_feat()
{
    coder::array<double, 1U> sig;
    double Formant1;
    double Formant2;
    double Formant3;

    sig = argInit_Unboundedx1_real_T();

    fmt_feat(sig, argInit_real_T(), &Formant1, &Formant2, &Formant3);
}

static void main_gtcc_feat()
{
    coder::array<double, 2U> GTCCmean;
    coder::array<double, 1U> sig;

    sig = argInit_Unboundedx1_real_T();

    gtcc_feat(&SnoringRecognitionStackDataGlobal, sig, argInit_real_T(),
              GTCCmean);
}

static void main_mfcc_feat()
{
    coder::array<double, 2U> MFCC_feature;
    coder::array<double, 1U> sig;

    sig = argInit_Unboundedx1_real_T();

    mfcc_feat(sig, argInit_real_T(), MFCC_feature);
}

static void main_noise_segment()
{
    coder::array<long long, 1U> starts_tmp;
    double fs_tmp;
    double olength;
    double ostart;

    starts_tmp = argInit_Unboundedx1_int64_T();

    fs_tmp = argInit_real_T();

    noise_segment(starts_tmp, starts_tmp, fs_tmp, fs_tmp, fs_tmp, &ostart,
                  &olength);
}

static void main_patient_classifier()
{
    coder::array<double, 2U> BARKEE;
    coder::array<double, 2U> GTCCmean;
    coder::array<double, 2U> MFCC_feature_tmp;
    coder::array<double, 1U> period_mean_tmp;
    double label_OSA;

    MFCC_feature_tmp = argInit_Unboundedx39_real_T();

    BARKEE = argInit_Unboundedx17_real_T();

    period_mean_tmp = argInit_Unboundedx1_real_T();

    GTCCmean = argInit_Unboundedx20_real_T();

    label_OSA = patient_classifier(
        &SnoringRecognitionStackDataGlobal, MFCC_feature_tmp, BARKEE,
        period_mean_tmp, period_mean_tmp, period_mean_tmp, period_mean_tmp,
        MFCC_feature_tmp, period_mean_tmp, period_mean_tmp, period_mean_tmp,
        GTCCmean, period_mean_tmp, period_mean_tmp, period_mean_tmp,
        period_mean_tmp, period_mean_tmp, period_mean_tmp, period_mean_tmp,
        period_mean_tmp);
}

static void main_pitch_feat()
{
    coder::array<double, 1U> sig;
    double period_max;
    double period_mean;
    double period_min;
    double period_var;

    sig = argInit_Unboundedx1_real_T();

    pitch_feat(sig, argInit_real_T(), &period_mean, &period_max, &period_min,
               &period_var);
}

static void main_pr800_feat()
{
    coder::array<double, 1U> sig;
    double PR800_max;
    double PR800_mean;
    double PR800_min;
    double PR800_var;

    sig = argInit_Unboundedx1_real_T();

    pr800_feat(sig, argInit_real_T(), &PR800_mean, &PR800_max, &PR800_min,
               &PR800_var);
}

static void main_se_feat()
{
    coder::array<double, 1U> sig;
    double SE_max;
    double SE_mean;
    double SE_min;
    double SE_var;

    sig = argInit_Unboundedx1_real_T();

    se_feat(sig, argInit_real_T(), &SE_mean, &SE_max, &SE_min, &SE_var);
}

static void main_vad()
{
    coder::array<double, 1U> x;
    coder::array<long long, 1U> w_ends;
    coder::array<long long, 1U> w_starts;

    x = argInit_Unboundedx1_real_T();

    vad(x, argInit_real_T(), w_starts, w_ends);
}

static void main_zweight()
{
    coder::array<double, 1U> x;
    double f[8];
    double p[8];
    double s;

    x = argInit_Unboundedx1_real_T();

    zweight(x, p, f, &s);
}

int main(int, char **)
{

    SnoringRecognition_initialize();

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

    SnoringRecognition_terminate();
    return 0;
}
