#include <bits/stdc++.h>
using namespace std;
#define TAM 8

int interpolationSearch(int A[], int n, int y)
{
    // I - início do vetor
    // F - fim do vetor
    // x - meio 
    // y - elemento a ser buscado
    // n - tamanho do vetor

    if (n == 0) {
        return -1;
    }

    int I = 0, F = n - 1, x;
 
    while (A[F] != A[I] && y >= A[I] && y <= A[F])
    {
        x = I + ((y - A[I]) * (F - I) / (A[F] - A[I]));
 
        if (y == A[x]) {
            return x;
        }
        
        else if (y < A[x]) {
            F = x - 1;
        }
        
        else {
            I = x + 1;
        }
    }
 
    if (y == A[I]) {
        return I;
    }
 
    else {
        return -1;
    }
}
 
int main(void)
{
    int A[TAM] = {2, 5, 6, 8, 9, 10, 12, 17};
    int y =12;
 
    cout << "Posição: " << interpolationSearch(A, TAM, y) << endl;
 
    return 0;
}
