#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// babbling_len은 배열 babbling의 길이입니다.
int solution(const char* babbling[], size_t babbling_len) {
    int answer = 0;

    const char* test[4] = {"aya", "ye", "woo", "ma"};

    for (size_t i = 0; i < babbling_len; i++) {
        size_t pos = 0;

        while (babbling[i][pos] != '\0') {
            bool found = false;

            for (size_t j = 0; j < 4; j++) {
                size_t len = strlen(test[j]);

                if (strncmp(babbling[i] + pos, test[j], len) == 0) {
                    pos += len;
                    found = true;
                    break;
                }
            }

            if (found == false) {
                break;
            }
        }

        if (babbling[i][pos] == '\0') {
            answer++;
        }
    }

    return answer;
}