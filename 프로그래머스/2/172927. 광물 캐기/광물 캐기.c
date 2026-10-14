#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// picks_len은 배열 picks의 길이입니다.
// minerals_len은 배열 minerals의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.

int dfs(int group, int group_count, int cost[][3], int dia, int iron, int stone) {
    
    // 1. 모든 묶음을 처리했면 종료
    if (group == group_count){
        return 0;
    }
    
    // 곡괭이별 선택 비교 코드
    int minimum = 1000000000;
    int fatigue;
    
    
    // 3. 다이아 곡괭이
    if (dia > 0) {
        fatigue = cost[group][0] + dfs(group+1, group_count, cost, dia-1, iron, stone);
        if (fatigue < minimum) {
            minimum = fatigue;
        }
    }
    
    // 4. 철 곡괭이
    if (iron > 0) {
        fatigue = cost[group][1] + dfs(group+1, group_count, cost, dia, iron-1, stone);
        if (fatigue < minimum) {
            minimum = fatigue;
        } 
    }
    
    // 5. 돌 곡괭이
    if (stone > 0) {
        fatigue = cost[group][2] + dfs(group+1, group_count, cost, dia, iron, stone-1);
        if (fatigue < minimum) {
            minimum = fatigue;
        } 
    }
    
    return minimum;
}

int solution(int picks[], size_t picks_len, const char* minerals[], size_t minerals_len) {
    int answer = 0;
    
    int pick_count = picks[0] + picks[1] + picks[2];
    int mine_count = (int)minerals_len;
    
    if (mine_count > pick_count * 5) {
        mine_count = pick_count * 5;
    }
    
    int cost[10][3] = {0};
    
    for (int i = 0; i< mine_count; i++){
        int group = i/ 5;
        
        if (strcmp(minerals[i], "diamond") == 0){
            cost[group][0] += 1;
            cost[group][1] += 5;
            cost[group][2] += 25;
        }
        
        else if (strcmp(minerals[i], "iron") == 0){
            cost[group][0] += 1;
            cost[group][1] += 1;
            cost[group][2] += 5;
        }
        
        else {
            cost[group][0] += 1;
            cost[group][1] += 1;
            cost[group][2] += 1;
        }
    }
    
    int group_count = (mine_count + 4)/5;
    
    answer = dfs(0, group_count, cost, picks[0], picks[1], picks[2]);
    
    return answer;
}