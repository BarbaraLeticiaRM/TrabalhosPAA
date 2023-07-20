#include <bits/stdc++.h>
using namespace std;
#define N 9

bool viable(int sol[][N], int v, int i, int j)
{
    for(int x = 0; x < N; x++)
    {
        if(sol[i][x] == v)
            return false;
    }

    for(int x = 0; x < N; x++)
    {
        if(sol[x][j] == v) 
            return false;
    }

    int bloco_linha = i/3;
    int bloco_coluna = j/3;

    for(int ii = bloco_linha*3; ii < bloco_linha*3 + 3; ii++)
    {
        for(int jj = bloco_coluna*3; jj < bloco_coluna*3 + 3; jj++)
        {
            if(sol[ii][jj] == v)
                return false;
        }
    }

    return true;
}

bool incomplete(int sol[N][N], int& lin, int& col)
{
    for (lin = 0; lin < N; lin++)
        for (col = 0; col < N; col++)
            if (sol[lin][col] == 0)
                return true;
    return false;
}

bool backtracking(int sol[N][N])
{
    int lin, col;

    if (!incomplete(sol, lin, col))
        return true;

    for (int num = 1; num <= 9; num++)
    {
        if (viable(sol, num, lin, col))
        {
            sol[lin][col] = num;
            if (backtracking(sol))
                return true;

            sol[lin][col] = 0;
        }
    }

    return false;
}


int main()
{
    int sol[N][N] = {  { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
 
    
    if(backtracking(sol)){
        for(int i = 0; i < N; i++) 
        {
            for (int j = 0; j < N; j++)
            {
                cout << sol[i][j] << " ";
            }
            cout << endl;
            
        }
    }  
    
    return 0;
}


/*
bool complete(int sol[][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(sol[i][j]==0)
                return false;
        }
    }
    return true;
}

bool backtracking(int sol[][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if (sol[i][j] == 0)
            {
                for(int v = 1; v <= 9; v++)
                {
                    if(viable(sol, v, i, j))
                    {
                        sol[i][j] = v;
                        if(backtracking(sol))
                            return true;
                        sol[i][j] = 0; 
                        
                    }
                    
                }
            }
        }
    }
}
*/
