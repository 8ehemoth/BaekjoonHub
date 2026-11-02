#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    
    // 저장 타입 long long
    // 내부 컨테이너 vector longlong
    // 비교 기준 greater longlong
    // pq.top 실행 시 가장 작은 값인 나옴
    
    // 모든 스코빌 값을 최소 힙에 넣기
    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    
    // 가장 작은 값이 K 이상이 될 때까지 반복
    while ((!pq.empty() && pq.top() < K)) {
        // 섞을 음식이 2개 미만이면 실행 안되게
        if (pq.size() < 2) {
            return -1;
        }
        
        long long first = pq.top();
        pq.pop();
        
        long long second = pq.top();
        pq.pop();
        
        long long mixed = first + second * 2;
        pq.push(mixed);
        
        answer++;
    }
    
    return answer;
}