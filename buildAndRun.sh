#bin/bash

rm main
g++ src/main.cpp src/File/File.cpp src/Matrix/Matrix.cpp -o main
./main multiply 2DimMatrix.txt 2DimMatrix2.txt -s out.txt
# ./main multiplyN 2 2DimMatrix2.txt
# ./main add 2DimMatrix.txt 2DimMatrix2.txt 
# ./main subtract 2DimMatrix.txt 2DimMatrix2.txt 
# ./main transpose 2DimMatrix2.txt
# ./main inverse 2DimMatrix2.txt

# ./main multiply 3DimMatrix.txt 3DimMatrix2.txt 
# ./main multiplyN 2 3DimMatrix2.txt
# ./main add 3DimMatrix.txt 3DimMatrix2.txt 
# ./main subtract 3DimMatrix.txt 3DimMatrix2.txt 
# ./main transpose 3DimMatrix2.txt
# ./main inverse 3DimMatrix2.txt