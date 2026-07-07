#include <bits/stdc++.h>
using namespace std;

class Kosaraju {
public:
    int V;
    vector<vector<int>> adj, rev;
    vector<bool> visited;
    stack<int> st;

    Kosaraju(int vertices) {
        V = vertices;
        adj.resize(V);
        rev.resize(V);
        visited.resize(V, false);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        rev[v].push_back(u); // reverse graph
    }

    void dfs1(int node) {
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs1(neighbor);
            }
        }

        st.push(node); // store by finish time
    }

    void dfs2(int node, vector<int>& component) {
        visited[node] = true;
        component.push_back(node);

        for (int neighbor : rev[node]) {
            if (!visited[neighbor]) {
                dfs2(neighbor, component);
            }
        }
    }

    void findSCCs() {
        // Step 1: DFS on original graph
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs1(i);
            }
        }

        // Step 2: Mark all unvisited again
        fill(visited.begin(), visited.end(), false);

        // Step 3: DFS on reversed graph
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (!visited[node]) {
                vector<int> component;
                dfs2(node, component);

                cout << "SCC: ";
                for (int x : component) {
                    cout << x << " ";
                }
                cout << endl;
            }
        }
    }
};

int main() {
    Kosaraju graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(1, 3);
    graph.addEdge(3, 4);

    graph.findSCCs();

    return 0;
}
