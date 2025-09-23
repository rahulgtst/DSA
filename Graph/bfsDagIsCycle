#include <bits/stdc++.h>

using namespace std;

bool isCycle(int n, vector<int> list[], vector<int>& inDegree) {
	vector<int> topo;
	queue<int> q;

	for(int i = 0; i < n; i++) {
	    if(inDegree[i] == 0) q.push(i);
	}
	
	while(!q.empty()) {
		int node = q.front();
		q.pop();
		topo.push_back(node);
		for(int next: list[node]) {
			inDegree[next]--;
			if(inDegree[next] == 0) q.push(next);
		}
	}
	return topo.size() != n;
}

int main()
{
	// number of nodes, edges
	int n, m;
	cin >> n >> m;

	// Adjacency List
	vector<int> list[n];
	vector<int> inDegree(n, 0);

	// Input edges
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;  // edge from u to v with weight w
		inDegree[v]++;
		list[u].push_back(v);
	}

	bool isCycleExist = isCycle(n, list, inDegree);
	cout << (isCycleExist ? "Yes": "No") << endl;

	return 0;
}
