#bin/bash

rm main
g++ src/main.cpp src/File/File.cpp -o main
./main 3DimMatrix.txt 2DimMatrix2.txt 
