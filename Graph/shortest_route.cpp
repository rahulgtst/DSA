#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<pair<int,int>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); // directed edge
    }

    for(int k = 0; k < q; k++) {
        int a, b;
        cin >> a >> b;
        vector<long long> dist(n+1, LLONG_MAX);
        dist[a] = 0;

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({0, a});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;

            for (auto [v, w] : adj[node]) {
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << dist[b] == LLONG_MAX ? -1 : dist[b] << "\n";
    }

    return 0;
}
