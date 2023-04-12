#include <bits/stdc++.h>
using namespace std;

void BFS(int v, map<int, list<int>>& adj, map<int, bool>& visitados)
{
    queue<int> q;
    visitados[v] = true;
    q.push(v); 

    while(!q.empty())
    {
        int no = q.front();
        q.pop();
        cout << no << " ";

        for(int vizinho:adj[no])
        {
            if(!visitados[vizinho])
            {
                visitados[vizinho] = true; 
                q.push(vizinho);
            }
        }

    }
}

int main()
{
    map<int, bool> visitados; 
    map<int, list<int>> adj;
    
    // adicionando nós e vizinhos
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(3);

    //preenchendo o vetor de visitados com false para todos os vértices
    for (auto it = adj.begin(); it != adj.end(); it++) {
        visitados[it->first] = false;
    }

    BFS(2, adj, visitados);

    return 0; 
}