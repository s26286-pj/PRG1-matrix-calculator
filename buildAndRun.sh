#bin/bash

rm main
g++ src/main.cpp src/File/File.cpp src/Matrix/Matrix.cpp -o main
./main 2DimMatrix.txt 2DimMatrix.txt 
