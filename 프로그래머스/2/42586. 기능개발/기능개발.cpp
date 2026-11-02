#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    
    // 필요한 날짜 구하기
    for (int i = 0; i<progresses.size(); i++) {
        int remain = 100 - progresses[i];
        int day = (remain + speeds[i] - 1) / speeds[i];
        days.push_back(day);
        
    }
    
    int current = days[0];  // 현재 배포 기준 날짜
    int count = 1;  // 현재 배포에 포함된 기능 수
    
    for (int i = 1; i < days.size(); i++) {
        if (days[i] <= current) {
            count++;
        } else {
            answer.push_back(count);
            current = days[i];
            count = 1;
        }
        
    }
    
    answer.push_back(count);
    
    return answer;
}