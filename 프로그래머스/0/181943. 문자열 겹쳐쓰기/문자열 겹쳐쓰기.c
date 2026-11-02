#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* my_string, const char* overwrite_string, int s) {
    // my_string 길이 + 1(널문자) 만큼 메모리 할당
    char* answer = (char*)malloc(strlen(my_string) + 1);
    if (!answer) return NULL;

    // my_string을 answer로 복사
    strcpy(answer, my_string);

    // overwrite_string의 길이만큼 s 위치부터 덮어쓰기
    for (int i = 0; i < strlen(overwrite_string); i++) {
        answer[s + i] = overwrite_string[i];
    }

    return answer;
}
