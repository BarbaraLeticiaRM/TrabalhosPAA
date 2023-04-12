#include <bits/stdc++.h>
using namespace std; 

void SelectionSort(int A[], int n)
{
    int min, aux; 
    for(int i = 0; i < n-1; i++)
    {
        min = i;
        for(int j = i+1; j<n; j++)
        {
            if(A[j] < A[min])
            {
                min = j;
            }
        }
        if (i != min)
        {
            aux = A[i];
            A[i] = A[min];
            A[min] = aux;
        }
    }
}

//Execução do código:
int main()
{
    int n;
    cout << "Tamanho do vetor: "; 
    cin >> n;
    int * A = new int[n];
    
    cout << "Elementos do vetor: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    SelectionSort(A, n);

    cout << "Vetor ordenado: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    
    return 0;
}
