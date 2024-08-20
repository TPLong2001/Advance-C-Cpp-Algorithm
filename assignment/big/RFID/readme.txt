gcc -IHeader -c Source/main.c -o Source/main.o
gcc -IHeader -c Source/app.c -o Source/app.o
gcc -IHeader -c Source/binarySearch.c -o Source/binarySearch.o
gcc Source/main.o Source/app.o Source/binarySearch.o -o main


hoặc makefile => sài lệnh: mingw32-make

g++ -IHeader -Wall -Wextra   -c -o Source/app.o Source/app.c
g++ -IHeader -Wall -Wextra   -c -o Source/main.o Source/main.c
g++ -IHeader -Wall -Wextra   -c -o Source/binarySearch.o Source/binarySearch.c
g++ -o main Source/app.o Source/main.o Source/binarySearch.o


clear file.o => sài lệnh: mingw32-make clean
rm -f Source/*.o main