#include <bits/stdc++.h>

using namespace std;

struct edge {
	int u;
	int v;
	int w;
};

int findParent(int node, vector<int>& parent) {
    if(node != parent[node]) parent[node] = findParent(parent[node], parent);
    return parent[node];
}

void unionSets(int u, int v, vector<int>& rank, vector<int>& parent) {
    if(rank[u] < rank[v]) parent[u] = v;
    else if(rank[u] > rank[v]) parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++; // only increase when ranks are equal
    }
}

int main()
{
	// number of nodes, edges
	int n, m;
	cin >> n >> m;

	// Adjacency List
	vector<edge> edges;

	// Input edges
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		edges.push_back({u, v, w});
	}
    
    sort(edges.begin(), edges.end(), [](edge a, edge b) {
        return a.w < b.w;
    });
    vector<int>parent(n), rank(n);
    vector<pair<int, int>> mst;
    for(int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    int cost = 0;
    
	for(int i = 0; i < edges.size(); i++) {
	    int u = edges[i].u;
	    int v = edges[i].v;
	    int w = edges[i].w;
	    if(findParent(u, parent) != findParent(v, parent)) {
	        cost += w;
	        unionSets(u, v, rank, parent);
	        mst.push_back({u, v});
	    }
	}
	
	cout << "Cost of MST: "<< cost << endl;

	return 0;
};
