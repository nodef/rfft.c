// Basic demonstration of RFFT library.
// Must be compiled using GCC.
#include <complex.h>
#include <math.h>
#include <stdio.h>
#define RFFT_IMPLEMENTATION
#include <rfft.h>


int main() {
  // Define a small signal
  // A simple DC signal + a higher frequency component
  // Let's use 8 points (power of 2)
  size_t n = 8;
  double complex data[8] = {1.0 + 0.0 * I, 1.0 + 0.0 * I, 1.0 + 0.0 * I,
                            1.0 + 0.0 * I, 1.0 + 0.0 * I, 1.0 + 0.0 * I,
                            1.0 + 0.0 * I, 1.0 + 0.0 * I};

  printf("Input signal:\n");
  for (size_t i = 0; i < n; ++i) {
    printf("  [%zu] %.2f + %.2fi\n", i, creal(data[i]), cimag(data[i]));
  }

  // Perform FFT
  fft_transform(data, n, false);

  printf("\nFFT result:\n");
  for (size_t i = 0; i < n; ++i) {
    // We expect the DC component (index 0) to be 8.0 and others 0.0
    printf("  [%zu] %.2f + %.2fi\n", i, creal(data[i]), cimag(data[i]));
  }

  return 0;
}
