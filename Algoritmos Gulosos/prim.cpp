#include <bits/stdc++.h>
using namespace std;

class Pair {
public:
    int v;
    int wt;

    Pair(int v, int wt) : v(v), wt(wt) {}

    int operator<(const Pair& other) const {
        return this->wt - other.wt; 
    }
};

int spanningTree(int V, int E, int edges[][3]) {
    vector<vector<Pair>> adj(V);
    for (int i = 0; i < V; i++) {
        adj[i] = vector<Pair>();
    }
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back(Pair(v, wt));
        adj[v].push_back(Pair(u, wt));
    }
    priority_queue<Pair> pq;
    pq.push(Pair(0, 0));
    vector<int> vis(V, 0);
    int s = 0;
    while (!pq.empty()) {
        Pair node = pq.top();
        pq.pop();
        int v = node.v;
        int wt = node.wt;
        if (vis[v] == 1)
            continue;
        s += wt;
        vis[v] = 1;
        for (const auto& it : adj[v]) {
            if (vis[it.v] == 0) {
                pq.push(Pair(it.v, it.wt));
            }
        }
    }
    return s;
}

int main() {
    int graph[][3] = {{0, 1, 5},
                      {1, 2, 3},
                      {0, 2, 1}};
    int V = 3;
    int E = 3;

    int minCost = spanningTree(V, E, graph);
    cout << "Custo mínimo da árvore geradora mínima: " << minCost << endl;

    return 0;
}
