#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> lab(n, vector<char>(m));
    pair<int, int> start, end;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> lab[i][j];
            if (lab[i][j] == 'A') start = {i, j};
            if (lab[i][j] == 'B') end = {i, j};
        }
    }

    queue<pair<int, int>> q;
    q.push(start);
    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    dist[start.first][start.second] = 0;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && lab[nx][ny] != '#' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }

    if (dist[end.first][end.second] == -1) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    cout << dist[end.first][end.second] << "\n";

    string path;
    int x = end.first, y = end.second;
    while (make_pair(x, y) != start) {
        auto [px, py] = parent[x][y];
        if (px + 1 == x) path += 'D';
        else if (px - 1 == x) path += 'U';
        else if (py + 1 == y) path += 'R';
        else if (py - 1 == y) path += 'L';
        x = px; y = py;
    }

    reverse(path.begin(), path.end());
    cout << path << "\n";
}
