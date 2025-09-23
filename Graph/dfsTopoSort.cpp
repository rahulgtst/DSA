#include <bits/stdc++.h>

using namespace std;

void topoSort(int start, vector<int> list[], vector<bool>& visited, stack<int>& st) {
    visited[start] = true;
	for(int next: list[start]) {
		if(!visited[next]) {
			topoSort(next, list, visited, st);
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
	vector<int> list[n];

	// Input edges
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;  // edge from u to v with weight w

		list[u].push_back(v);
	}

	vector<bool> visited(n, false);
	stack<int> st;
	vector<int> topo;
	for(int i = 0; i < n; i++) {
		if(!visited[i]) {
			topoSort(i, list, visited, st);
		}
	}
	
	while(!st.empty()) {
	    topo.push_back(st.top());
	    st.pop();
	}
	
	for(int node: topo) {
	    cout << node << ' ';
	}

	return 0;
}
