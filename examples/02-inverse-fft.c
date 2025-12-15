// Demonstration of Inverse FFT to recover original signal.
// Must be compiled using GCC.
#include <complex.h>
#include <math.h>
#include <stdio.h>
#define RFFT_IMPLEMENTATION
#include <rfft.h>


int main(void) {
  size_t n = 4;
  double complex original[4] = {1.0 + 2.0 * I, 3.0 + 4.0 * I, 5.0 + 6.0 * I,
                                7.0 + 8.0 * I};

  // Copy for processing
  double complex data[4];
  for (size_t i = 0; i < n; ++i)
    data[i] = original[i];

  printf("Original:\n");
  for (size_t i = 0; i < n; ++i) {
    printf("  [%zu] %.2f + %.2fi\n", i, creal(original[i]), cimag(original[i]));
  }

  // Forward FFT
  fft_transform(data, n, false);

  printf("\nAfter Forward FFT:\n");
  for (size_t i = 0; i < n; ++i) {
    printf("  [%zu] %.2f + %.2fi\n", i, creal(data[i]), cimag(data[i]));
  }

  // Inverse FFT
  fft_transform(data, n, true);

  // Normalize (rfft does not normalize, so we divide by n)
  for (size_t i = 0; i < n; ++i)
    data[i] /= n;

  printf("\nAfter Inverse FFT (and normalization):\n");
  for (size_t i = 0; i < n; ++i) {
    printf("  [%zu] %.2f + %.2fi\n", i, creal(data[i]), cimag(data[i]));
  }

  // Check error
  double max_err = 0.0;
  for (size_t i = 0; i < n; ++i) {
    double err = cabs(data[i] - original[i]);
    if (err > max_err)
      max_err = err;
  }
  printf("\nMax reconstruction error: %g\n", max_err);

  return 0;
}
