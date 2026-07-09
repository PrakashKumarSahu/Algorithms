#include <bits/stdc++.h>
using namespace std;

class BridgeFinder {
private:
    int n;
    int timer;

    vector<vector<pair<int, int>>> adj;
    vector<int> tin;
    vector<int> low;
    vector<int> visited;

    vector<pair<int, int>> bridges;

    void dfs(int node, int parentEdgeId) {
        visited[node] = 1;
        tin[node] = low[node] = timer++;

        for (auto [child, edgeId] : adj[node]) {
            if (edgeId == parentEdgeId) {
                continue;
            }

            if (visited[child]) {
                low[node] = min(low[node], tin[child]);
            } else {
                dfs(child, edgeId);

                low[node] = min(low[node], low[child]);

                if (low[child] > tin[node]) {
                    bridges.push_back({node, child});
                }
            }
        }
    }

public:
    BridgeFinder(int nodes) {
        n = nodes;
        timer = 0;

        adj.resize(n);
        tin.assign(n, -1);
        low.assign(n, -1);
        visited.assign(n, 0);
    }

    void addEdge(int u, int v, int edgeId) {
        adj[u].push_back({v, edgeId});
        adj[v].push_back({u, edgeId});
    }

    vector<pair<int, int>> findBridges() {
        timer = 0;
        bridges.clear();

        tin.assign(n, -1);
        low.assign(n, -1);
        visited.assign(n, 0);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, -1);
            }
        }

        return bridges;
    }

    void printBridges() {
        vector<pair<int, int>> result = findBridges();

        for (auto [u, v] : result) {
            cout << u << " " << v << endl;
        }
    }
};
