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

	vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

	// Input edges
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		dist[u][v] = min(dist[u][v], w);
	}

	for(int i = 0; i < n; i++) {
		dist[i][i] = 0;
	}

	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
					dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
				}
			}
		}
	}

	bool hasNegativeCycle = false;
	for (int i = 0; i < n; i++) {
		if (dist[i][i] < 0) {
			hasNegativeCycle = true;
			break;
		}
	}

	if (hasNegativeCycle) {
		cout << "Graph contains a negative cycle\n";
	} else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dist[i][j] == INT_MAX) cout << "INF ";
				else cout << dist[i][j] << " ";
			}
			cout << "\n";
		}
	}

	return 0;
};
