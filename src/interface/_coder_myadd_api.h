//
// File: _coder_myadd_api.h
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 28-Sep-2024 21:22:24
//

#ifndef _CODER_MYADD_API_H
#define _CODER_MYADD_API_H

// Include Files
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void myadd(real_T a[4], real_T b[4], real_T c[7]);

void myadd_api(const mxArray *const prhs[2], const mxArray **plhs);

void myadd_atexit();

void myadd_initialize();

void myadd_terminate();

void myadd_xil_shutdown();

void myadd_xil_terminate();

#endif
//
// File trailer for _coder_myadd_api.h
//
// [EOF]
//
