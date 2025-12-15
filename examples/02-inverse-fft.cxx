// Demonstration of Inverse FFT to recover original signal in C++.
// Must be compiled using a C++ compiler.
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <vector>


#define RFFT_IMPLEMENTATION
#include <rfft.hpp>

int main() {
  size_t n = 4;
  std::vector<std::complex<double>> original = {
      {1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}, {7.0, 8.0}};

  // Copy for processing
  std::vector<std::complex<double>> data = original;

  std::cout << "Original:\n";
  std::cout << std::fixed << std::setprecision(2);
  for (size_t i = 0; i < n; ++i) {
    std::cout << "  [" << i << "] " << original[i].real() << " + "
              << original[i].imag() << "i\n";
  }

  // Forward FFT
  fft_transform(data, false);

  std::cout << "\nAfter Forward FFT:\n";
  for (size_t i = 0; i < n; ++i) {
    std::cout << "  [" << i << "] " << data[i].real() << " + " << data[i].imag()
              << "i\n";
  }

  // Inverse FFT
  fft_transform(data, true);

  // Normalize (rfft does not normalize, so we divide by n)
  for (size_t i = 0; i < n; ++i) {
    data[i] /= static_cast<double>(n);
  }

  std::cout << "\nAfter Inverse FFT (and normalization):\n";
  for (size_t i = 0; i < n; ++i) {
    std::cout << "  [" << i << "] " << data[i].real() << " + " << data[i].imag()
              << "i\n";
  }

  // Check error
  double max_err = 0.0;
  for (size_t i = 0; i < n; ++i) {
    double err = std::abs(data[i] - original[i]);
    if (err > max_err)
      max_err = err;
  }
  std::cout << "\nMax reconstruction error: " << std::defaultfloat << max_err
            << "\n";

  return 0;
}
