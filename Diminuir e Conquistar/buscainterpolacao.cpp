#include <bits/stdc++.h>
using namespace std;
#define TAM 8

int interpolationSearch(int A[], int n, int y, int I, int F)
{
    if (n == 0) {
        return -1;
    }

    if (A[F] == A[I] || y < A[I] || y > A[F]) {
        return -1;
    }

    int x = I + ((y - A[I]) * (F - I) / (A[F] - A[I]));
 
    if (y == A[x]) {
        return x;
    }
        
    else if (y < A[x]) {
        return interpolationSearch(A, n, y, I, x - 1);
    }
        
    else {
        return interpolationSearch(A, n, y, x + 1, F);
    }
}
 
int main(void)
{
    int A[TAM] = {2, 5, 6, 8, 9, 10, 12, 17};
    int y =10;
 
    cout << "Posição: " << interpolationSearch(A, TAM, y, 0, TAM - 1) << endl;
 
    return 0;
}
