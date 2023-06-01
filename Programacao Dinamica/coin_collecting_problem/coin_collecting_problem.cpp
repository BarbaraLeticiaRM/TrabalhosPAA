#include<bits/stdc++.h>
using namespace std;
#define R 3
#define C 3

int coinCollecting( vector<vector<int>>& CoinMatrix, int i, int j)
{
    if (i >= R || j >= C)
        return 0; 

    return CoinMatrix[i][j] + max(coinCollecting(CoinMatrix, i+1, j), coinCollecting(CoinMatrix, i, j+1));
}

int main() {

    int i = 0, j = 0;

    vector<vector<int>> CoinMatrix = { {1, 0, 1},
                                       {1, 0, 1},
                                       {1, 1, 1} };

    int maxCoins = coinCollecting(CoinMatrix, i, j); 
	cout << "Máximo de moedas: " << maxCoins << endl;
    return 0;
}