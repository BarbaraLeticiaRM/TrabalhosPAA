#include <bits/stdc++.h>
using namespace std;

// Função para calcular o custo total de uma rota
int calcularCustoTotal(const vector<vector<int>>& grafo, const vector<int>& rota) {
    int custoTotal = 0;
    int n = rota.size();
    
    for (int i = 0; i < n - 1; i++) {
        int cidadeAtual = rota[i];
        int proximaCidade = rota[i + 1];
        custoTotal += grafo[cidadeAtual][proximaCidade];
    }
    
    // Considera o custo de voltar para a cidade inicial
    int cidadeInicial = rota[0];
    int ultimaCidade = rota[n - 1];
    custoTotal += grafo[ultimaCidade][cidadeInicial];
    
    return custoTotal;
}

// Função para encontrar a rota de menor custo usando força bruta
vector<int> encontrarMenorRota(const vector<vector<int>>& grafo) {
    int n = grafo.size();
    
    // Cria um vetor com as cidades
    vector<int> cidades;
    for (int i = 0; i < n; i++) {
        cidades.push_back(i);
    }
    
    // Armazena a rota de menor custo
    vector<int> menorRota;
    int menorCusto = INT_MAX;
    
    // Gera todas as permutações possíveis das cidades
    do {
        int custoAtual = calcularCustoTotal(grafo, cidades);
        
        // Atualiza a rota de menor custo
        if (custoAtual < menorCusto) {
            menorCusto = custoAtual;
            menorRota = cidades;
        }
        
    } while (next_permutation(cidades.begin(), cidades.end()));
    
    return menorRota;
}

// Função para imprimir a rota
void imprimirRota(const vector<int>& rota) {
    for (int cidade : rota) {
        cout << cidade << " ";
    }
    cout << endl;
}

int main() {
    // Exemplo de grafo completo com 4 cidades (0, 1, 2, 3)
    vector<vector<int>> grafo = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    
    vector<int> menorRota = encontrarMenorRota(grafo);
    
    cout << "Menor rota: ";
    imprimirRota(menorRota);
    
    cout << "Custo total: " << calcularCustoTotal(grafo, menorRota) << endl;
    
    return 0;
}
