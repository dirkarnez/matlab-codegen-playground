//
// File: myadd.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 28-Sep-2024 21:22:24
//

// Include Files
#include "myadd.h"
#include "conv.h"

// Function Definitions
//
// Arguments    : const double a[4]
//                const double b[4]
//                double c[7]
// Return Type  : void
//
void myadd(const double a[4], const double b[4], double c[7])
{
  //  c = a + b;
  //       u = [-1 2 3 -2 0 1 2];
  //        v = [2 4 -1 1];
  coder::conv(a, b, c);
}

//
// File trailer for myadd.cpp
//
// [EOF]
//
