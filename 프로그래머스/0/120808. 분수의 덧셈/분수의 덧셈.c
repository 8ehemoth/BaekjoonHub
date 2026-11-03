#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int numer1, int denom1, int numer2, int denom2) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(1);
    
    // 1. 통분한 뒤 분자 더하기
    int numer = numer1 * denom2 + numer2 * denom1;
    int denom = denom1 * denom2;
    
    // 2. 분자와 분모의 최대공약수를 찾기
    int gcd = 1;
    int min = (numer < denom) ? numer : denom;
    
    for (int i = 2; i <= min; i++) {
        if (numer % i == 0 && denom % i == 0) {
            gcd = i;
        }
    }
    
    // 3. 최대공약수로 나누어 기약분수 만들기
    numer /= gcd;
    denom /= gcd;
    
    answer[0] = numer; 
    answer[1] = denom; 
    
    return answer;
}