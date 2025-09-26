#include <bits/stdc++.h>

using namespace std;

void bridges(int start, int parent, int& timer, vector<int>& list[], vector<int>& t, vector<int>& l, vector<bool>& visited) {
	visited[start] = true;
	t[start] = l[start] = timer++;

	for(int next: list[start]) {
		if(next == parent) continue;
		if(!visited[next]) {
			bridges(next, timer, list, t, l, visited);
			l[start] = min(l[next], l[start]);
			if(l[next] > t[start]) {
				cout << "Bridges: " << start << " -> " << next << endl;
			}
		} else {
			l[start] = min(l[start], t[next]);
		}
	}
}

void articulation(int start, int parent, int& timer, vector<int>& list[], vector<int>& t, vector<int>& l, vector<bool>& visited, vector<bool>& result) {
	visited[start] = true;
	t[start] = l[start] = timer++;
	int children = 0;
	for(int next: list[start]) {
		if(next == parent) continue;
		if(!visited[next]) {
			children++;
			articulation(next, timer, list, t, l, visited, result);
			l[start] = min(l[next], l[start]);
			if(l[next] >= t[start] && parent != -1) {
				result[start] = true;
			}
		} else {
			l[start] = min(l[start], t[next]);
		}
	}
	if(parent == -1 && children > 1) result[start] = true;
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
		cin >> u >> v;

		list[u].push_back(v);
		list[v].push_back(u);
	}

	vector<int>t(n, -1), l(n, -1);
	vector<bool> visited(n, false);
	int timer = 0;

	for(int i = 0; i < n; i++) {
		if(!visited[i]) {
			bridges(i, -1, timer, list, t, l, visited);
		}
	}

	fill(visited.begin(), visited.end(), false);
	vector<bool> result(n, false);
	timer = 0;
	for(int i = 0; i < n; i++) {
		if(!visited[i]) articulation(i, -1, timer, list, t, l, visited, result);
	}

	for(int i = 0; i < n; i++) {
		if(result[i]) cout << "Articulation Point: " << i << endl;
	}


	return 0;
};
