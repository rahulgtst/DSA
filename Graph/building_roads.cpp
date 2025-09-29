#include<bits/stdc++.h>

using namespace std;

void dfs(int node, vector<bool>& visited, vector<int> list[]) {
    visited[node] = true;
	for(int next: list[node]) {
		if(!visited[next]) {
			dfs(next, visited, list);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> list[n+1];
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		list[u].push_back(v);
		list[v].push_back(u);
	}

	vector<pair<int, int>> newRoads;
	vector<bool> visited(n+1, false);
	int prev = -1;
	for(int i = 1; i <= n; i++) {
		if(!visited[i]) {
		    if(prev != -1) {
		        newRoads.push_back({prev, i});
		    }
		    prev = i;
			dfs(i, visited, list);
		}
	}

	cout << newRoads.size() << endl;
	for(auto road: newRoads) {
	    cout << road.first << " " << road.second << endl;
	}

	return 0;
}