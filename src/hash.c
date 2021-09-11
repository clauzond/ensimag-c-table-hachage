#include <stdlib.h>
#include <stdint.h>

#include <stdio.h>

uint32_t hash(const char* str) {
    uint32_t hash = 5381;
    uint32_t i = 0;
    char c = str[i];
    while (c != '\0') {
        hash = hash * 33 + c;
        i++;
        c = str[i];
    }
    return hash;
}

void test(void) {
    const char* a = "Colonel Moutarde";
    const char* b = "Caporal Ketchup";
    const char* c = "Sergent Mayo";

    printf("%u\n", hash(a)%10);
    printf("%u\n", hash(b)%10);
    printf("%u\n", hash(c)%10);
}

int main(void) {
    test();
    return EXIT_SUCCESS;
}