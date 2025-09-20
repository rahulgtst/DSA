#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(int n, vector<int> list[]) {
    vector<int> result;
    vector<bool> visited(n+1, false);
    queue<int> q;
    
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            q.push(i);
            visited[i] = true;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                result.push_back(node);
                for(int next: list[node]) {
                    if(!visited[next]){
                        q.push(next);
                        visited[next] = true;
                    }
                }
            }
        }
    }
    
    return result;
}

int main()
{
    // number of nodes, edges
    int n, m;
    cin >> n >> m;
    
    // Adjacency List
    vector<int> list[n+1];
    
    // Weighted Adjacency list
    vector<pair<int, int>> wlist[n+1];
    
    // Input edges
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;  // edge from u to v with weight w

        list[u].push_back(v);
        list[v].push_back(u); // if undirected
    }
    
    vector<int> BFS = bfs(n, list);
    
    for(int node: BFS) {
        cout << node << " ";
    }
    
    cout << endl;

    return 0;
}
