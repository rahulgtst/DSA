#include <bits/stdc++.h>

using namespace std;

bool isCycle(int start, int parent, vector<int> list[], vector<bool>& visited) {
    visited[start] = true;
	for(int next: list[start]) {
		if(!visited[next]) {
			if(isCycle(next, start, list, visited)) return true;
		} else if (next != parent) {
			return true;
		}
	}
	return false;
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

	vector<bool> visited(n, false);
	bool isCycleExist = false;
	for(int i = 0; i < n; i++) {
		if(!visited[i]) {
			isCycleExist = isCycle(i, -1, list, visited);
			if(isCycleExist) break;
		}
	}
	
	cout << (isCycleExist ? "Yes" : "No") << endl;

	return 0;
}
