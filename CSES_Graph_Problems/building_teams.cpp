#include <bits/stdc++.h>

using namespace std;

void teams(int n, vector<int> list[]) {
    vector<int> colors(n+1, -1);
    queue<int> q;
    
    for(int i = 1; i <= n; i++) {
        if(colors[i] == -1) {
            q.push(i);
            colors[i] = 1;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(int next: list[node]) {
                    if(colors[next] == -1){
                        q.push(next);
                        colors[next] = (colors[node] == 1) ? 2 : 1;
                    } else if(colors[next] == colors[node]){
                        cout << "IMPOSSIBLE";
                        return;
                    }
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++) cout << colors[i] << " ";
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

	teams(n, list);

	return 0;
}