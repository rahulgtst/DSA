#include <bits/stdc++.h>

using namespace std;

bool bfs(int n, vector<int> list[]) {
    vector<int> color(n, -1);
    queue<int> q;
    
    for(int i = 0; i < n; i++) {
        if(color[i] == -1) {
            q.push(i);
            color[i] = 0;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(int next: list[node]) {
                    if(color[next] == -1){
                        q.push(next);
                        color[next] = 1 - color[node];
                    } else if(color[next] == color[node]){
                        return false;
                    }
                }
            }
        }
    }
    
    return true;
}

int main()
{
    // number of nodes, edges
    int n, m;
    cin >> n >> m;
    
    // Adjacency List
    vector<int> list[n];
    
    // Input edges
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;  // edge from u to v with weight w

        list[u].push_back(v);
        list[v].push_back(u); // if undirected
    }
    
    bool isBipartite = bfs(n, list);
    cout << (isBipartite ? "Bipartite": "Can't Bipartite") << endl;

    return 0;
}
