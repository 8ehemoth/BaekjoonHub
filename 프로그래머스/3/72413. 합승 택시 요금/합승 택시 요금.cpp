#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

vector<int> dijkstra(int start, int n, const vector<vector<pair<int, int>>>& graph) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        
        if (curCost > dist[curNode]) continue;
        
        for (const auto& next : graph[curNode]) {
            int nextNode = next.first;
            int weight = next.second;
            
            int newCost = curCost + weight;
            
            if (newCost < dist[nextNode]) {
                dist[nextNode] = newCost;
                pq.push({newCost, nextNode});
            }
        }
    }
    
    return dist;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    
    vector<vector<pair<int, int>>> graph(n + 1);
    
    for (const auto& fare : fares) {
        int u = fare[0];
        int v = fare[1];
        int cost = fare[2];
        
        graph[u].push_back({v, cost});
        graph[v].push_back({u, cost});
    }
    
    vector<int> distS = dijkstra(s, n, graph);
    vector<int> distA = dijkstra(a, n, graph);
    vector<int> distB = dijkstra(b, n, graph);
    
    for (int i = 1; i <= n; i++) {
        if (distS[i] == INF || distA[i] == INF || distB[i] == INF) continue;
        
        answer = min(answer, distS[i] + distA[i] + distB[i]);
    }
    
    return answer;
}