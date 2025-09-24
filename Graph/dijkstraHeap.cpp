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
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	vector<int> dist(n, INT_MAX);
	dist[src] = 0;

	pq.push({0, src});

	while(!pq.empty()) {
		auto [d, node] = pq.top();
		pq.pop();
		if (d > dist[node]) continue;

		for(auto it: list[node]) {
			if(dist[node]+it.second < dist[it.first]) {
				dist[it.first] = dist[node]+it.second;
				pq.push({dist[it.first], it.first});
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
