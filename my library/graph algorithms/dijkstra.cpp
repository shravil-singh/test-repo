#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> iPair
;
class Graph {
	public:
	vector<vector<pair<int, int>>> adj;
	int N;
	Graph(int n, vector<vector<int>>& edges) {
		adj.resize(n);
		N = n;
		for (auto& e : edges) {
			e[0]--;
			e[1]--;
			adj[e[0]].push_back(make_pair(e[1], e[2]));
			adj[e[1]].push_back(make_pair(e[0], e[2]));
		}
	}
	int shortest_path(int src, int second, int x) {
		priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
		vector<int> dist(N, INT_MAX);
		pq.push(make_pair(0, src));
		dist[src] = 0;
		vector<bool> vis(N, false);
		while (!pq.empty()) {
			int u = pq.top().second;
			pq.pop();
			vis[u] = true;
			for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
				int v = (*i).first;
				int weight = (*i).second;

				if (dist[v] > dist[u] + weight and vis[v] == false) {
					dist[v] = dist[u] + weight;
					pq.push(make_pair(dist[v], v));
				}
			}
		}
		return dist[second] == INT_MAX ? -1 : dist[second];
	}
};

