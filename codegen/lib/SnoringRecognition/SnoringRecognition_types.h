#ifndef SNORINGRECOGNITION_TYPES_H
#define SNORINGRECOGNITION_TYPES_H

#include "rtwtypes.h"

struct b_struct_T {
    double mu[4160];
    double sigm[4160];
    double c[32];
};

struct SnoringRecognitionStackData {
    struct {
        double win[40320];
        double z[40320];
    } f0;
    struct {
        double win[36162];
        double z[36162];
    } f1;
    struct {
        double win[17280];
    } f2;
    struct {
        double win[15435];
    } f3;
    struct {
        b_struct_T s[2];
        b_struct_T b_s[2];
    } f4;
};

#endif
