#include <bits/stdc++.h>

using namespace std;

bool isCycle(int n, vector<int> list[]) {
    vector<bool> visited(n, false);
    queue<pair<int, int>> q; // node, parent
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            q.push({i, -1});
            visited[i] = true;
            while(!q.empty()){
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();
                for(int next: list[node]) {
                    if(!visited[next]){
                        q.push({next, node});
                        visited[next] = true;
                    } else if(next != parent){
                        return true;
                    }
                }
            }
        }
    }
    
    return false;
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
    
    bool isCycleExist = isCycle(n, list);
    cout << (isCycleExist ? "Yes": "No") << endl;

    return 0;
}
