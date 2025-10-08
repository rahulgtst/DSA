#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> shortestPath(int n, int src, vector<int> list[]) {
	vector<pair<int, int>> dist(n+1, {INT_MAX, -1});
	queue<int> q;
	dist[src].first = 0;
	q.push(src);

	while(!q.empty()) {
		int node = q.front();
		q.pop();
		for(int next: list[node]) {
			if(dist[node].first+1 < dist[next].first) {
				q.push(next);
				dist[next].first = dist[node].first+1;
				dist[next].second = node;
			}
		}
	}

	return dist;
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

	vector<pair<int, int>> distance = shortestPath(n, 1, list);

	if(distance[n].first == INT_MAX) {
		cout << "IMPOSSIBLE";
	} else {
		cout << distance[n].first+1 << endl;
		vector<int> path;
		for(int cur = n; cur != -1; cur = distance[cur].second)
			path.push_back(cur);

		reverse(path.begin(), path.end());

		for(int node : path)
			cout << node << " ";
	}

	return 0;
}