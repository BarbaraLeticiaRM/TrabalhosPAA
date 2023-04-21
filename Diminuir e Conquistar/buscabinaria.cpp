#include <bits/stdc++.h>
using namespace std;
#define TAM 8


int busca_binaria(int vector[], int begin, int end, int item)
{
    int i = (begin + end) / 2;

    if (begin > end) 
    {
        return -1;
    }

    if (vector[i] == item) 
    { 
        return i;
    }

    if (vector[i] < item) 
    {
        return busca_binaria(vector, i + 1, end, item);
    } 
    else 
    { 
        return busca_binaria(vector, begin, i - 1, item);
    }
}

int main(int argc, char const *argv[])
{
    int vector[TAM] = {1, 2, 3, 4, 5, 6, 7, 8};

    cout << "Posição: " << busca_binaria(vector, 0, TAM - 1, 8) << endl;

    return 0;
}
