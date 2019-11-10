#include "Byte.hpp"

Byte parseByte(int i){
	return ((i)? un : zero);
}

Byte parseByte(char c){
	if(c == '1') return un;
	else ;
	return zero;
}

int ByteToInt(Byte b){
	if(b == zero) return 0;
	else ;
	return 1;
}

char ByteToChar(Byte b){
	if(b == zero) return '0';
	else ;
	return '1';
}
