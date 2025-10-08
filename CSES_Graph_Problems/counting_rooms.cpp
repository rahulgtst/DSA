#include<bits/stdc++.h>

using namespace std;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

bool isInLimit(int n, int m, int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < m);
}

void dfs(int n, int m, int x, int y, vector<vector<char>>& build) {
    build[x][y] = '#';
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(isInLimit(n, m, nx, ny) && build[nx][ny] == '.') {
            dfs(n, m, nx, ny, build);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> build(n, vector<char>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> build[i][j];
        }
    }
    
    int result = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(build[i][j] == '.') {
                result++;
                dfs(n, m, i, j, build);
            }
        }
    }
    
    cout << result << endl;
    
    return 0;
}