#include <bits/stdc++.h>

using namespace std;

void dfs(int start, vector<int> list[], vector<bool>& visited, stack<int>& finish) {
	visited[start] = true;
	for(int next: list[start]) {
	    if(!visited[next]) dfs(next, list, visited, finish);
	}
	finish.push(start);
}

void revDFS(int start, vector<int> list[], vector<bool>& visited, vector<int>& result) {

	visited[start] = true;
	result.push_back(start);
	for(int next: list[start]) {
		if(!visited[next]) revDFS(next, list, visited, result);
	}
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
	stack<int> finish;
	for(int i = 0; i < n; i++) {
		if(!visited[i]) {
			dfs(i, list, visited, finish);
		}
	}

	vector<int>revList[n];
	fill(visited.begin(), visited.end(), false);
	for(int i = 0; i < n; i++) {
		for(int node: list[i]) {
			revList[node].push_back(i);
		}
	}

	vector<vector<int>> result;
	while(!finish.empty()) {
		int node = finish.top();
		finish.pop();

		if(!visited[node]) {
			vector<int> scc;
			revDFS(node, revList, visited, scc);
			result.push_back(scc);
		}
	}



	for(auto scc: result) {
		cout << "SCC Node contains: ";
		for(int node: scc) {
			cout << node << ", ";
		}
		cout << endl;
	}

	cout << endl;

	return 0;
}
