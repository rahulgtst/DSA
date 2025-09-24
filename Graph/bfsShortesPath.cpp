#include <bits/stdc++.h>

using namespace std;

vector<int> shortestPath(int n, int src, vector<int> list[]) {
	vector<int> dist(n, INT_MAX);
	queue<int> q;
	dist[src] = 0;
	q.push(src);
	
	while(!q.empty()) {
		int node = q.front();
		q.pop();
		for(int next: list[node]) {
			if(dist[node]+1 < dist[next]) {
				q.push(next);
				dist[next] = dist[node]+1;
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
	vector<int> list[n];

	// Input edges
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;  // edge from u to v with weight w

		list[u].push_back(v);
		list[v].push_back(u); // if undirected
	}

	vector<int> distance = shortestPath(n, 0, list);

	for(int dist : distance) {
        if(dist == INT_MAX) cout << "INF ";
        else cout << dist << " ";
    }
    cout << endl;

	cout << endl;

	return 0;
}
