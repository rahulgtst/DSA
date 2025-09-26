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
    
    vector<int>parent(n, -1), key(n, INT_MAX);
    vector<bool> mst(n, false);
    key[0] = 0;
    int cost = 0;
    
	for(int i = 0; i < n-1; i++) {
	    int mini = INT_MAX;
	    int u;
	    for(int j = 0; j < n; j++) {
	        if(mst[j] == false && key[j] < mini) {
	            mini = key[j];
	            u = j;
	        }
	    }
	    if (parent[u] != -1) cost += key[u];
	    mst[u] = true;
	    
	    for(auto it: list[u]) {
	        int v = it.first;
	        int w = it.second;
	        if(mst[v] == false && key[v] > w) {
	            key[v] = w;
	            parent[v] = u;
	        }
	    }
	}
	
	cout << "Cost of MST: "<< cost << endl;
	
	for(int i = 0; i < n; i++) {
	    cout << "Parent of " << i << " = " << parent[i] << endl;
	}

	return 0;
};
