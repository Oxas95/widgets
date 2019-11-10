#ifndef Byte_hpp
#define Byte_hpp

typedef enum {
	zero = 0,
	un = 1
} Byte;

Byte parseByte(int);
Byte parseByte(char);
int ByteToInt(Byte b);
char ByteToChar(Byte b);

#endif //Byte_hpp
