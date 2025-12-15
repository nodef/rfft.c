// Demonstration of FFT on a non-power-of-two size array (using Bluestein's algorithm).
// Must be compiled using GCC.
#include <complex.h>
#include <math.h>
#include <stdio.h>
#define RFFT_IMPLEMENTATION
#include <rfft.h>


int main(void) {
  // 5 is a prime number, so not a power of 2.
  // This forces the library to use Bluestein's algorithm or similar fallback.
  size_t n = 5;
  double complex data[5];

  // Initialize with a sine wave
  for (size_t i = 0; i < n; ++i) {
    double t = (double)i / n;
    data[i] = sin(2 * M_PI * t) + 0.0 * I;
  }

  printf("Input (Sine wave 1 cycle):\n");
  for (size_t i = 0; i < n; ++i) {
    printf("  [%zu] %.2f + %.2fi\n", i, creal(data[i]), cimag(data[i]));
  }

  // Forward FFT
  fft_transform(data, n, false);

  printf("\nFFT Result:\n");
  for (size_t i = 0; i < n; ++i) {
    printf("  [%zu] %.2f + %.2fi\n", i, creal(data[i]), cimag(data[i]));
  }

  // We expect energy concentrated at index 1 and index n-1 (for real sine wave)
  // index 1 corresponds to frequency +1, index 4 corresponds to frequency -1

  return 0;
}
