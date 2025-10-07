#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& visited, vector<int>& path) {
    visited[node] = 1;
    path.push_back(node);

    for (int next : adj[node]) {
        if (next == parent) continue; // skip the edge we came from
        if (!visited[next]) {
            if (dfs(next, node, adj, visited, path)) return true;
        } else if (visited[next] == 1) {
            // found a back edge -> cycle
            path.push_back(next);
            return true;
        }
    }

    path.pop_back();
    visited[node] = 2;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> visited(n + 1, 0);
    vector<int> path;

    bool found = false;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dfs(i, -1, adj, visited, path)) {
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // Extract the cycle portion from path
    int endNode = path.back();
    vector<int> cycle;
    cycle.push_back(endNode);
    for (int i = (int)path.size() - 2; i >= 0; i--) {
        cycle.push_back(path[i]);
        if (path[i] == endNode) break;
    }

    reverse(cycle.begin(), cycle.end());
    cout << cycle.size() << "\n";
    for (int v : cycle) cout << v << " ";
    cout << "\n";
}
