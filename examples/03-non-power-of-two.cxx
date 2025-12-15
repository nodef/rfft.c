// Demonstration of FFT on a non-power-of-two size array in C++.
// Must be compiled using a C++ compiler.
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <vector>


#define RFFT_IMPLEMENTATION
#include <rfft.hpp>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
  // 5 is a prime number, so not a power of 2.
  size_t n = 5;
  std::vector<std::complex<double>> data(n);

  // Initialize with a sine wave
  for (size_t i = 0; i < n; ++i) {
    double t = (double)i / n;
    data[i] = std::sin(2 * M_PI * t); // Imaginary part is 0 by default
  }

  std::cout << "Input (Sine wave 1 cycle):\n";
  std::cout << std::fixed << std::setprecision(2);
  for (size_t i = 0; i < n; ++i) {
    std::cout << "  [" << i << "] " << data[i].real() << " + " << data[i].imag()
              << "i\n";
  }

  // Forward FFT
  fft_transform(data, false);

  std::cout << "\nFFT Result:\n";
  for (size_t i = 0; i < n; ++i) {
    std::cout << "  [" << i << "] " << data[i].real() << " + " << data[i].imag()
              << "i\n";
  }

  return 0;
}
