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
	int n, m, q;
	cin >> n >> m >> q;

	vector<vector<long long>> dist(n+1, vector<long long>(n+1, LLONG_MAX));

	// Input edges
	for(int i = 0; i < m; i++) {
		int u, v;
		long long w;
		cin >> u >> v >> w;

		dist[u][v] = min(dist[u][v], w);
		dist[v][u] = min(dist[v][u], w);
	}

	for(int i = 1; i <= n; i++) {
		dist[i][i] = 0;
	}

	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX) {
					dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
				}
			}
		}
	}

	while(q--) {
	    int a, b;
	    cin >> a >> b;
	    long long d = dist[a][b] == LLONG_MAX ? -1 : dist[a][b];
	    cout << d << "\n";
	}

	return 0;
};