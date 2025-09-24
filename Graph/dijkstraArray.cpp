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
	}

	int src=0;
	vector<bool> visited(n, false);
	vector<int> dist(n, INT_MAX);
	dist[src] = 0;

	for(int i=0; i<n; i++) {
		int node = i;
		for(int j=0; j<n; j++) {
			if (!visited[j] && (node == -1 || dist[j] < dist[node])) {
				node = j;
			}
		}

		if (node == -1 || dist[node] == INT_MAX) break;
		visited[node] = true;
		if(dist[node] != INT_MAX) {
			for(auto it: list[node]) {
				if(dist[node]+it.second < dist[it.first]) {
					dist[it.first] = dist[node]+it.second;
				}
			}
		}
	}

	for (int d : dist) {
		if (d == INT_MAX) cout << "INF ";
		else cout << d << " ";
	}
	cout << endl;

	return 0;
};
