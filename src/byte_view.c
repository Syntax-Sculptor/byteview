/*
    SyntaxSculptor
    byte_view.c
    4/29/26
*/

#include <stdlib.h>
#include <stdio.h>

int main() {
    printf("ByteView - C object sizes\n\n");

    printf("char:   %lld bytes\n", sizeof(char));
    printf("short:  %lld bytes\n", sizeof(short));
    printf("int:    %lld bytes\n", sizeof(int));
    printf("float:  %lld bytes\n", sizeof(float));
    printf("double: %lld bytes\n", sizeof(double));
    printf("long:   %lld bytes\n", sizeof(long));
    printf("void*:  %lld bytes\n", sizeof(void*));
}