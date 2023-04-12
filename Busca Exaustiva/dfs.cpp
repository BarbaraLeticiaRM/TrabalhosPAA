#include <bits/stdc++.h>
using namespace std;

void DFS(int v, map<int, list<int>>& adj, map<int, bool>& visitados)
{
    visitados[v] = true;
    cout << v << " ";

    list<int>::iterator it;
    for (it = adj[v].begin(); it != adj[v].end(); ++it)
        if (!visitados[*it])
            DFS(*it, adj, visitados); 
}

int main()
{
    map<int, bool> visitados; 
    map<int, list<int>> adj;
    
    // adicionando nós e vizinhos
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(1);
    adj[2].push_back(4);
    adj[3].push_back(1);
    adj[4].push_back(2);

    DFS(2, adj, visitados);

    return 0; 
}