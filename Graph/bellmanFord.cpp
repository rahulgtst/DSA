#include <bits/stdc++.h>

using namespace std;

struct edge {
	int u;
	int v;
	int w;
};

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

	int src=0;
	vector<int> dist(n, INT_MAX);
	dist[src] = 0;

	for(int i = 1; i < n; i++) {
		for(edge e: edges) {
			if(dist[e.u] != INT_MAX && dist[e.u]+e.w < dist[e.v]) {
				dist[e.v] = dist[e.u]+e.w;
			}
		}
	}

	bool isNegativeCycle = false;
	for(edge e: edges) {
		if(dist[e.u] != INT_MAX && dist[e.u]+e.w < dist[e.v]) {
			isNegativeCycle = true;
			break;
		}
	}

	for (int d : dist) {
		if (d == INT_MAX) cout << "INF ";
		else cout << d << " ";
	}
	cout << endl;

	return 0;
};
