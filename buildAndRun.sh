#bin/bash

rm main
g++ src/main.cpp src/File/File.cpp src/Matrix/Matrix.cpp -o main
./main 4DimMatrix.txt 2DimMatrix2.txt 
