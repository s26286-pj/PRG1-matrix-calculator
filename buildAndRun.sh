#bin/bash

rm main
g++ src/main.cpp src/File/File.cpp src/Matrix/Matrix.cpp -o main
./main 3DimMatrix.txt 3DimMatrix2.txt 
