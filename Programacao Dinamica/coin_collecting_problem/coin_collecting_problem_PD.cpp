#include<bits/stdc++.h>
using namespace std;

int coinCollecting(int r, int c, vector<vector<int>>& CoinMatrix) {
    vector<vector<int>> MaxCoin(r + 1, vector<int>(c + 1, 0));

    for (int i = 1; i <= r; i++) 
	{
        for (int j = 1; j <= c; j++) 
		{
            MaxCoin[i][j] = max(MaxCoin[i - 1][j], MaxCoin[i][j - 1]) + CoinMatrix[i - 1][j - 1];
        }
    }

    return  MaxCoin[r][c];
}

int main() {
    int rows = 3; 
    int cols = 3; 

    vector<vector<int>> CoinMatrix = { {1, 0, 1},
                                       {1, 0, 1},
                                       {1, 1, 1} };

    int maxCoins = coinCollecting(rows, cols, CoinMatrix); 
	cout << "Máximo de moedas: " << maxCoins << endl;
    return 0;
}