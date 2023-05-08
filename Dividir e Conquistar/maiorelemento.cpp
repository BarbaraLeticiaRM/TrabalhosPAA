#include <bits/stdc++.h>
using namespace std;
#define TAM 10

int maxVal (int vet[], int inicio, int fim)
{
    if(fim == inicio)
        return inicio;

    int meio = (inicio + fim)/2;
    int v1 = maxVal(vet, inicio, meio);
    int v2 = maxVal(vet, meio+1, fim);
        
    if (vet[v1] > vet[v2])
        return v1;  
    else 
        return v2;
    
}

int main()
{
    int v[TAM] = {3, 10, 18, 5, 35, 35, 35, 35, 35, 17};
    
    int max = maxVal(v, 0, TAM -1);

    cout << "Posição do maior valor: " << max << endl;
    return 0;

}
