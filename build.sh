#!/usr/bin/env bash
# Fetch the latest version of the library
fetch() {
if [ -f rfft.h ] && [ -f rfft.hpp ]; then return; fi
URL="https://github.com/grego/rfft.h/archive/refs/heads/master.zip"
ZIP="${URL##*/}"
DIR="rfft.h-master"
mkdir -p .build
cd .build

# Download the release
if [ ! -f "$ZIP" ]; then
  echo "Downloading $ZIP from $URL ..."
  curl -L "$URL" -o "$ZIP"
  echo ""
fi

# Unzip the release
if [ ! -d "$DIR" ]; then
  echo "Unzipping $ZIP to .build/$DIR ..."
  cp "$ZIP" "$ZIP.bak"
  unzip -q "$ZIP"
  rm "$ZIP"
  mv "$ZIP.bak" "$ZIP"
  echo ""
fi
cd ..

# Copy the libs to the package directory
echo "Copying libs ..."
cp -f .build/"$DIR"/rfft.h   rfft.h
cp -f .build/"$DIR"/rfft.hpp rfft.hpp
echo ""
}


# Test the project
test() {
echo "Running 01-basic-fft.c ..."
gcc -I. -o 01.exe examples/01-basic-fft.c          && ./01 && echo -e "\n"
echo "Running 01-basic-fft.cxx ..."
g++ -I. -o 01.exe examples/01-basic-fft.cxx        && ./01 && echo -e "\n"
echo "Running 02-inverse-fft.c ..."
gcc -I. -o 02.exe examples/02-inverse-fft.c        && ./02 && echo -e "\n"
echo "Running 02-inverse-fft.cxx ..."
g++ -I. -o 02.exe examples/02-inverse-fft.cxx      && ./02 && echo -e "\n"
echo "Running 03-non-power-of-two.c ..."
gcc -I. -o 03.exe examples/03-non-power-of-two.c   && ./03 && echo -e "\n"
echo "Running 03-non-power-of-two.cxx ..."
g++ -I. -o 03.exe examples/03-non-power-of-two.cxx && ./03 && echo -e "\n"
}


# Main script
if [[ "$1" == "test" ]]; then test
elif [[ "$1" == "fetch" ]]; then fetch
else echo "Usage: $0 {fetch|test}"; fi
