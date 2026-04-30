/*
    SyntaxSculptor
    byte_view.c
    4/29/26
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printBytes(const unsigned char *bytes, size_t size, const char* type_name) {
    printf("%s %p: ", type_name, (void *) bytes);

    for (size_t i = 0; i < size; i++) {
        printf("%02x ", bytes[i]);
    }

    printf("\n");
}

int isMachineLittleEndian() {
    int test_val = 0x1234;
    int first_byte = ((unsigned char *) &test_val)[0];
 
    return first_byte == 0x34;
}

void printStringBytes(const unsigned char* bytes) {
    printf("Bytes for string %s\n", bytes);
    printf("No null terminator:\n");
    printf("%p: ", (void *) bytes);

    for (size_t i = 0; i < strlen((const char*)bytes); i++) {
        printf("%02x ", bytes[i]);
    }

    printf("\nWith null terminator:\n");
    printf("%p: ", (void *) bytes);

    for (size_t i = 0; i < strlen((const char*)bytes) + 1; i++) {
        printf("%02x ", bytes[i]);
    }

    printf("\n");
}

int main() {
    printf("ByteView - C object sizes\n\n");

    // Byte Size Demo

    printf("char:   %lld bytes\n", sizeof(char));
    printf("short:  %lld bytes\n", sizeof(short));
    printf("int:    %lld bytes\n", sizeof(int));
    printf("float:  %lld bytes\n", sizeof(float));
    printf("double: %lld bytes\n", sizeof(double));
    printf("long:   %lld bytes\n", sizeof(long));
    printf("void*:  %lld bytes\n", sizeof(void*));

    // Byte Representation demo

    printf("\nByte representation\n\n");

    int i_val = 0x12345678;
    printBytes((unsigned char *) &i_val, sizeof(i_val), "int");

    float f_val = 1.5f;
    printBytes((unsigned char *) &f_val, sizeof(f_val), "float");

    long l_val = 0x12345678;
    printBytes((unsigned char*) &l_val, sizeof(l_val), "long");

    double d_val = 5.5;
    printBytes((unsigned char*) &d_val, sizeof(d_val), "double");

    int *p_val = &i_val;
    printBytes((unsigned char*) &p_val, sizeof(p_val), "pointer");

    printf("\n");
    const char *s_val = "Hello, World.";
    printStringBytes((const unsigned char*) s_val);

    printf("\n");

    if (isMachineLittleEndian()) {
        printf("Detected endian: little endian.\n");
    } else {
        printf("Detected endian: big endian\n");
    }

    // Bitwise Demo
    printf("\nBit operations demo\n");
    
    unsigned int x = 0x67;
    unsigned int y = 0x42;

    printf("%02x & %02x = %02u\n", x, y, x & y);
    printf("%02x | %02x = %02u\n", x, y, x | y);
    printf("%02x ^ %02x = %02u\n", x, y, x ^ y);
    printf("~%02x       = %02u\n", x, ~x & 0xff);
    printf("~%02x       = %02u\n", y, ~y & 0xff);

    // Shift demo
    printf("\nShift operations demo\n");

    printf("%u << 1 = %02x\n", x, x << 1);
    printf("%u << 2 = %02x\n", x, x << 2);
    printf("%u >> 1 = %02x\n", x, x >> 1);
    printf("%u >> 2 = %02x\n", x, x >> 2);

    return EXIT_SUCCESS;
}