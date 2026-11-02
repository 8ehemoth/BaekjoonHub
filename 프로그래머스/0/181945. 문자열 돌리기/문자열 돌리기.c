#include <stdio.h>
#define LEN_INPUT 11

int main(void) {
    char s1[LEN_INPUT];
    if (scanf("%10s", s1) != 1) return 0;
    
    for (int i =0; s1[i] != '\0'; i++) {
        printf("%c\n", s1[i]);
    }
    return 0;
}
