#include <bits/stdc++.h>

using namespace std;

void dfs(int start, vector<int> list[], vector<int>& result, vector<bool>& visited) {
    if(!visited[start]) {
        visited[start] = true;
        result.push_back(start);
        for(int next: list[start]) {
            dfs(next, list, result, visited);
        }
    }
}

int main()
{
    // number of nodes, edges
    int n, m;
    cin >> n >> m;
    
    // Adjacency List
    vector<int> list[n+1];
    
    // Input edges
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;  // edge from u to v with weight w

        list[u].push_back(v);
        list[v].push_back(u); // if undirected
    }
    
    vector<bool> visited(n+1, false);
    vector<int> DFS;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs(i, list, DFS, visited);
        }
    }
    
    for(int node: DFS) {
        cout << node << " ";
    }
    
    cout << endl;

    return 0;
}
