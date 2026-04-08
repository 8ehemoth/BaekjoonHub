#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int A, B;
        scanf("%d %d", &A, &B);

        int g = gcd(A, B);
        int lcm = (A * B) / g;

        printf("%d\n", lcm);
    }

    return 0;
}