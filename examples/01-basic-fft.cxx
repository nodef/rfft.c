// Basic demonstration of RFFT library in C++.
// Must be compiled using a C++ compiler (e.g., g++).
#include <complex>
#include <iomanip>
#include <iostream>
#include <vector>


#define RFFT_IMPLEMENTATION
#include <rfft.hpp>

int main() {
  // Define a small signal
  // Let's use 8 points (power of 2)
  size_t n = 8;
  std::vector<std::complex<double>> data = {{1.0, 0.0}, {1.0, 0.0}, {1.0, 0.0},
                                            {1.0, 0.0}, {1.0, 0.0}, {1.0, 0.0},
                                            {1.0, 0.0}, {1.0, 0.0}};

  std::cout << "Input signal:\n";
  std::cout << std::fixed << std::setprecision(2);
  for (size_t i = 0; i < n; ++i) {
    std::cout << "  [" << i << "] " << data[i].real() << " + " << data[i].imag()
              << "i\n";
  }

  // Perform FFT
  // In C++, the function is overloaded or namespaced?
  // rfft.hpp defines: void fft_transform(std::vector<std::complex<double>>&
  // vec, bool inverse); It is in the global namespace based on the file content
  // viewed earlier.
  fft_transform(data, false);

  std::cout << "\nFFT result:\n";
  for (size_t i = 0; i < n; ++i) {
    // We expect the DC component (index 0) to be 8.0 and others 0.0
    std::cout << "  [" << i << "] " << data[i].real() << " + " << data[i].imag()
              << "i\n";
  }

  return 0;
}
