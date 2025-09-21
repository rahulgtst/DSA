#include <bits/stdc++.h>

using namespace std;

bool dfsBipartite(int start, vector<int> list[], vector<int>& color) {
	for(int next: list[start]) {
		if(color[next] == -1) {
			color[next] = 1 - color[start];
			if(!dfsBipartite(next, list, color)) return false;
		} else if (color[next] == color[start]) {
			return false;
		}
	}
	return true;
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

	vector<int> color(n, -1);
	int result = 0;
	bool isBipartite = true;
	for(int i = 0; i < n; i++) {
		if(color[i] == -1) {
			color[i] = 0;
			isBipartite = isBipartite && dfsBipartite(i, list, color);
		}
	}
	
	cout << (isBipartite ? "Bipartite": "Can't Bipartite") << endl;

	return 0;
}
