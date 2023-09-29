#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> articulationPoints(int n, vector<int> adj[]) {
        vector<int> tin(n, -1);
        vector<int> low(n, -1);
        vector<bool> vis(n, false);
        vector<bool> isArticulation(n, false);
        int timer = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, vis, tin, low, timer, adj, isArticulation);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (isArticulation[i]) {
                ans.push_back(i);
            }
        }
        if (ans.size() == 0) {
            ans.push_back(-1);
        }
        return ans;
    }
    void dfs(int node, int parent, vector<bool>& vis, vector<int>& tin, vector<int>& low, int& timer, vector<int> adj[], vector<bool>& isArticulation) {
        vis[node] = true;
        tin[node] = low[node] = timer++;
        int child = 0;
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (!vis[it]) {
                dfs(it, node, vis, tin, low, timer, adj, isArticulation);
                low[node] = min(low[node], low[it]);
                if (low[it] >= tin[node] and parent != -1) {
                    isArticulation[node] = true;
                }
                child++;
            } else {
                low[node] = min(low[node], tin[it]);
            }
        }
        if (parent == -1 and child > 1) {
            isArticulation[node] = 1;
        }
    }
};
