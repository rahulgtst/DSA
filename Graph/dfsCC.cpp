#include <bits/stdc++.h>

using namespace std;

void dfsCC(int start, vector<int> list[], vector<bool>& visited) {
        visited[start] = true;
        for(int next: list[start]) {
            if(!visited[next]) dfsCC(next, list, visited);
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
    int result = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            result++;
            dfsCC(i, list, visited);
        }
    }
    
    cout << result << endl;

    return 0;
}
