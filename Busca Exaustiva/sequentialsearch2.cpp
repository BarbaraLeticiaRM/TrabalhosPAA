#include <bits/stdc++.h>
using namespace std; 

int SequentialSearch2(int A[], int n, int K)
{
    int i = 0; 
    while(A[i] != K)
    {
        i++;
        if (i >= n)
        {
            return -1;
        }
    }
    return i;

}

//Execução:
int main()
{
    int n, K;
    cout << "Tamanho do vetor: "; 
    cin >> n;
    int * A = new int[n];
    
    cout << "Elementos do vetor: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cout << "Chave: "; 
    cin >> K;

    int found = SequentialSearch2(A, n, K);
    cout << "Indice: " << found << endl;


    return 0;
}
