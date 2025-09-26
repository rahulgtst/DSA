#include <bits/stdc++.h>

using namespace std;

int main()
{
	// number of nodes, edges
	int n, m;
	cin >> n >> m;

	// Adjacency List
	vector<pair<int, int>> list[n];

	// Input edges
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		list[u].push_back({v, w});
		list[v].push_back({u, w});
	}
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int>parent(n, -1), key(n, INT_MAX);
    vector<bool> mst(n, false);
    key[0] = 0;
    int cost = 0;
    pq.push({0, 0});
    
	while(!pq.empty()) {
	    int u = pq.top().second;
	    int wt = pq.top().first;
	    pq.pop();
	    
	    if(mst[u]) continue;
	    if (parent[u] != -1) cost += wt;
	    mst[u] = true;
	    
	    for(auto it: list[u]) {
	        int v = it.first;
	        int w = it.second;
	        if(mst[v] == false && key[v] > w) {
	            key[v] = w;
	            parent[v] = u;
	            pq.push({key[v], v});
	        }
	    }
	}
	
	cout << "Cost of MST: "<< cost << endl;
	
	for(int i = 0; i < n; i++) {
	    cout << "Parent of " << i << " = " << parent[i] << endl;
	}

	return 0;
};
