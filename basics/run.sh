qcc -O3 -Wall bump.c -o a.out -lm
./a.out > output.ppm 2>log
animate output.ppm
