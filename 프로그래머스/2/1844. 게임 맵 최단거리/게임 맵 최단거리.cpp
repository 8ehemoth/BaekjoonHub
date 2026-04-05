#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    // 2차원 벡터 크기 잡는 방법임.
    int n = maps.size();
    int m = maps[0].size();
    
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    q.push({0, 0});
    visited[0][0] = true;
    
    // 격자 BFS에서 공식처럼 쓰이는 방향 배열
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            // 맵밖으로 안 나가게 범위체크 
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            
            // 벽 체크
            if (maps[nx][ny] == 0) continue;
            
            // 방문 안 한 길인지 체크
            if (!visited[nx][ny]) {
                visited[nx][ny] = true;
                maps[nx][ny] = maps[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    if (!visited[n - 1][m - 1]) {
        answer = -1;
    } else {
        answer = maps[n - 1][m - 1];
    }
    
    return answer;
}