# rfft.h

Public domain single header fast Fourier transform for arbitrary array sizes,
in about 100 lines of C code, which should be straightforward to understand.
By [Grego](https://github.com/grego).

A C++ implementation using the stdlib `complex` and `vector` is also provided in `rfft.hpp`.

<br>

## Installation

Run:

```sh
$ npm i rfft.c
```

And then include `rfft.h` or `rfft.hpp` as follows:

```cxx
// main.c or main.cxx
#define RFFT_IMPLEMENTATION
#include <rfft.h>   // if using C, or
#include <rfft.hpp> // if using C++

int main() { /* ... */ }
```

Finally, compile while adding the path `node_modules/rfft.c` to your compiler's include paths.

```bash
$ gcc -I./node_modules/rfft.c main.c    # if using C, or
$ g++ -I./node_modules/rfft.c main.cxx  # if using C++
```

You may also use a simpler approach with the [cpoach](https://www.npmjs.com/package/cpoach.sh) tool, which automatically adds the necessary include paths of all the installed dependencies for your project.

```bash
$ cpoach gcc main.c    # if using C, or
$ cpoach g++ main.cxx  # if using C++
```

<br>

## Algorithms

The classic [Cooley-Turkey algorithm](https://en.wikipedia.org/wiki/Cooley%E2%80%93Tukey_FFT_algorithm)
is used in place (without additional allocations) for arrays of size `2^k`.

For more more general ones, [Bluestein algorithm](https://en.wikipedia.org/wiki/Chirp_Z-transform#Bluestein's_algorithm)
is used. It utilizes the binomial identity `2nk = n^2 + k^2 - (k - n)^2` to
express the Fourier transform as a convolution of two sequences,
which can be computed using the algorith for the power of 2 sizes.
It needs to allocate two auxillary array of size at most `4n + 3`.

The runnig time is always `O(n log(n))`. However, if the speed is crucial,
more optimized libraries like [FFTW](http://fftw.org/) are recommended.

<br>

## Inspiration

Inspired by [Project Nayuki](https://www.nayuki.io/page/free-small-fft-in-multiple-languages),
but written in a simpler and arguably more straightforward way.

<br>

## License

Public domain.

<br>
<br>


[![](https://raw.githubusercontent.com/qb40/designs/gh-pages/0/image/11.png)](https://wolfram77.github.io)<br>
[![SRC](https://img.shields.io/badge/src-repo-green?logo=Org)](https://github.com/grego/rfft.h)
[![ORG](https://img.shields.io/badge/org-nodef-green?logo=Org)](https://nodef.github.io)
![](https://ga-beacon.deno.dev/G-RC63DPBH3P:SH3Eq-NoQ9mwgYeHWxu7cw/github.com/nodef/rfft.c)
