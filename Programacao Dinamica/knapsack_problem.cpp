#include<bits/stdc++.h>
using namespace std;

vector<int> Weights; 
vector<int> Values;
vector<vector<int>> F; // Tabela de memória

int MFKnapsack(int n, int W) 
{
    if (F[n][W] < 0) 
    {
        if (W < Weights[n]) 
        {
            F[n][W] = MFKnapsack(n - 1, W);
        } 
        else 
        {
            int value1 = MFKnapsack(n - 1, W);
            int value2 = Values[n] + MFKnapsack(n - 1, W - Weights[n]);
            F[n][W] = max(value1, value2);
        }
    }
    return F[n][W];
}

int main() {
    int n = 5; // número de itens
    int W = 50; // capacidade da mochila 

    Weights = {40, 30, 20, 10, 20 }; 
    Values = {840, 600, 400, 100, 300}; 

    F.assign(n + 1, vector<int>(W + 1, -1));

    // Casos base
    for (int i = 0; i <= n; i++) 
    {
        F[i][0] = 0;
    }

    for (int j = 0; j <= W; j++) 
    {
        F[0][j] = 0;
    }

    int result = MFKnapsack(n, W);
    cout << "Valor ótimo: " << result << endl;

    return 0;
}