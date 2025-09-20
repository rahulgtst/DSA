#include <bits/stdc++.h>

using namespace std;

int main()
{
    // number of nodes, edges
    int n, m;
    cin >> n >> m;
    
    // Adjacency Matrix
    vector<vector<int>> matrix(n+1, vector<int>(n+1, 0));
    
    // Adjacency List
    vector<int> list[n+1];
    
    // Weighted Adjacency list
    vector<pair<int, int>> wlist[n+1];
    
    // Input edges
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;  // edge from u to v with weight w

        // For an unweighted graph: just store adjacency
        matrix[u][v] = 1;
        matrix[v][u] = 1; // if undirected

        list[u].push_back(v);
        list[v].push_back(u); // if undirected

        // For weighted graph
        wlist[u].push_back({v, w});
        wlist[v].push_back({u, w}); // if undirected
    }

    return 0;
}
