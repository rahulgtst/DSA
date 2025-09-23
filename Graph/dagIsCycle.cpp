#include <bits/stdc++.h>

using namespace std;

bool isCycle(int start, vector<int> list[], vector<bool>& visited, vector<bool>& dfsVisited) {
    visited[start] = true;
    dfsVisited[start] = true;
	for(int next: list[start]) {
		if(!visited[next]) {
			if(isCycle(next, list, visited, dfsVisited)) return true;
		} else if (dfsVisited[next]) {
			return true;
		}
	}
	dfsVisited[start]=false;
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
	}

	vector<bool> visited(n, false);
	vector<bool> dfsVisited(n, false);
	bool isCycleExist = false;
	for(int i = 0; i < n; i++) {
		if(!visited[i]) {
			isCycleExist = isCycle(i, list, visited, dfsVisited);
			if(isCycleExist) break;
		}
	}
	
	cout << (isCycleExist ? "Yes" : "No") << endl;

	return 0;
}
