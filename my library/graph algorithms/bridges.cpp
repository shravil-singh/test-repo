#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> ans;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto& a : connections) {
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }
        vector<int> tin(n, -1);
        vector<int> low(n, -1);
        vector<bool> vis(n, false);
        int timer = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, vis, tin, low, timer, adj);
            }
        }
        return ans;
    }
    void dfs(int node, int parent, vector<bool>& vis, vector<int>& tin, vector<int>& low, int& timer, vector<vector<int>>& adj) {
        vis[node] = true;
        tin[node] = low[node] = timer++;
        for (auto neighbour : adj[node]) {
            if (neighbour == parent) continue;
            if (!vis[neighbour]) {
                dfs(neighbour, node, vis, tin, low, timer, adj);
                low[node] = min(low[node], low[neighbour]);
                if (low[neighbour] > tin[node]) {
                    ans.push_back({node, neighbour});
                }
            } else {
                low[node] = min(low[node], tin[neighbour]);
            }
        }
    }
};
