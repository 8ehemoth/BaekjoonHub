#include <stdio.h>
#define LEN_INPUT 21

int main(void) {
    char s1[LEN_INPUT];
    if(scanf("%20s", s1) != 1) return 0;
    
    for (int i = 0; s1[i] != '\0'; i++) {
        if ('a' <= s1[i] && s1[i] <= 'z') s1[i] = s1[i] - 'a' + 'A';
        else if ('A' <= s1[i] && s1[i] <= 'Z') s1[i] = s1[i] - 'A' + 'a';
    }
    
    printf("%s", s1);
    return 0;
}
