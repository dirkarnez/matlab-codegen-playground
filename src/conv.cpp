//
// File: conv.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 28-Sep-2024 21:22:24
//

// Include Files
#include "conv.h"
#include <emmintrin.h>

// Function Definitions
//
// Arguments    : const double A[4]
//                const double B[4]
//                double C[7]
// Return Type  : void
//
namespace coder {
void conv(const double A[4], const double B[4], double C[7])
{
  for (int k{0}; k < 7; k++) {
    C[k] = 0.0;
  }
  for (int k{0}; k < 4; k++) {
    __m128d r;
    __m128d r1;
    r = _mm_loadu_pd(&C[k]);
    r1 = _mm_set1_pd(B[k]);
    _mm_storeu_pd(&C[k], _mm_add_pd(r, _mm_mul_pd(r1, _mm_loadu_pd(&A[0]))));
    r = _mm_loadu_pd(&C[k + 2]);
    _mm_storeu_pd(&C[k + 2],
                  _mm_add_pd(r, _mm_mul_pd(r1, _mm_loadu_pd(&A[2]))));
  }
}

} // namespace coder

//
// File trailer for conv.cpp
//
// [EOF]
//
