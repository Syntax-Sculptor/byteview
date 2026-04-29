/*
    SyntaxSculptor
    byte_view.c
    4/29/26
*/

#include <stdlib.h>
#include <stdio.h>

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

int main() {
    printf("ByteView - C object sizes\n\n");

    printf("char:   %lld bytes\n", sizeof(char));
    printf("short:  %lld bytes\n", sizeof(short));
    printf("int:    %lld bytes\n", sizeof(int));
    printf("float:  %lld bytes\n", sizeof(float));
    printf("double: %lld bytes\n", sizeof(double));
    printf("long:   %lld bytes\n", sizeof(long));
    printf("void*:  %lld bytes\n", sizeof(void*));

    printf("\nByte representation\n\n");

    int i_val = 0x12345678;
    printBytes((unsigned char *) &i_val, sizeof(i_val), "int");

    float f_val = 1.5f;
    printBytes((unsigned char *) &f_val, sizeof(f_val), "float");

    int *p_val = &i_val;
    printBytes((unsigned char*) &p_val, sizeof(p_val), "pointer");

    printf("\n");

    if (isMachineLittleEndian()) {
        printf("Detected endian: little endian");
    } else {
        printf("Detected endian: big endian");
    }
}