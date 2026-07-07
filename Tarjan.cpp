#include <bits/stdc++.h>
using namespace std;

class Tarjan {
public:
    int V, timer;
    vector<vector<int>> adj;
    vector<int> disc, low;
    vector<bool> inStack;
    stack<int> st;

    Tarjan(int vertices) {
        V = vertices;
        timer = 0;
        adj.resize(V);
        disc.assign(V, -1);
        low.assign(V, -1);
        inStack.assign(V, false);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void dfs(int node) {
        disc[node] = low[node] = timer++;
        st.push(node);
        inStack[node] = true;

        for (int neighbor : adj[node]) {
            if (disc[neighbor] == -1) {
                dfs(neighbor);
                low[node] = min(low[node], low[neighbor]);
            }
            else if (inStack[neighbor]) {
                low[node] = min(low[node], disc[neighbor]);
            }
        }

        // If node is head/root of SCC
        if (low[node] == disc[node]) {
            cout << "SCC: ";

            while (true) {
                int topNode = st.top();
                st.pop();
                inStack[topNode] = false;

                cout << topNode << " ";

                if (topNode == node) break;
            }

            cout << endl;
        }
    }

    void findSCCs() {
        for (int i = 0; i < V; i++) {
            if (disc[i] == -1) {
                dfs(i);
            }
        }
    }
};

int main() {
    Tarjan graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(1, 3);
    graph.addEdge(3, 4);

    graph.findSCCs();

    return 0;
}
