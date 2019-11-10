rm Byte.a
g++ -c -g -Wall Byte.cpp Byte.hpp
ar cr Byte.a Byte.o
ranlib Byte.a
rm Byte.o Byte.hpp.gch
