#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> parent;
    vector<int> sz;
    vector<int> rank_;
    int components;

public:
    // Constructor
    DSU(int n) {
        parent.resize(n);
        sz.resize(n, 1);
        rank_.resize(n, 0);
        components = n;

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find parent / leader of a node
    // Uses path compression
    int find(int node) {
        if (parent[node] == node) {
            return node;
        }

        return parent[node] = find(parent[node]);
    }

    // Union by size
    bool uniteBySize(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) {
            return false;
        }

        if (sz[pu] < sz[pv]) {
            swap(pu, pv);
        }

        parent[pv] = pu;
        sz[pu] += sz[pv];
        components--;

        return true;
    }

    // Union by rank
    bool uniteByRank(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) {
            return false;
        }

        if (rank_[pu] < rank_[pv]) {
            parent[pu] = pv;
        } else if (rank_[pu] > rank_[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank_[pu]++;
        }

        components--;

        return true;
    }

    // Check whether two nodes are in the same component
    bool connected(int u, int v) {
        return find(u) == find(v);
    }

    // Get size of component containing node
    int size(int node) {
        int p = find(node);
        return sz[p];
    }

    // Get number of connected components
    int countComponents() {
        return components;
    }

    // Reset DSU with n nodes
    void reset(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        rank_.assign(n, 0);
        components = n;

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
};
