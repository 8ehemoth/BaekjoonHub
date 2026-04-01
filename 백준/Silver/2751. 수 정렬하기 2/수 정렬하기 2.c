#include <stdio.h>

int main(void) {
    int N, x;
    static char arr[2000001] = {0};

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        arr[x + 1000000] = 1;
    }

    for (int i = 0; i <= 2000000; i++) {
        if (arr[i]) {
            printf("%d\n", i - 1000000);
        }
    }

    return 0;
}