#include <bits/stdc++.h>

using namespace std;

void topoSort(int start, vector<pair<int, int>> list[], vector<bool>& visited, stack<int>& st) {
	visited[start] = true;
	for(auto next: list[start]) {
		if(!visited[next.first]) {
			topoSort(next.first, list, visited, st);
		}
	}
	st.push(start);
}

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

	vector<bool> visited(n, false);
	stack<int> st;
	for(int i = 0; i < n; i++) {
		if(!visited[i]) {
			topoSort(i, list, visited, st);
		}
	}

	int src=0;
	vector<int> dist(n, INT_MAX);
	dist[src] = 0;

	while(!st.empty()) {
		int node = st.top();
		st.pop();
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
