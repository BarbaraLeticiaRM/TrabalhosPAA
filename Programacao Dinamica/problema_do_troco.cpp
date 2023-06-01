#include<bits/stdc++.h>
using namespace std;
 
int changeMaking(int coin[], int n, int sum)
{
    int i, j, x, y;

    int dp[n+1][sum+1];
 
    for(j = 0; j <= sum; j++)
        dp[0][j] = INT_MAX;
 
    for(i = 1; i <= n; i++)
        dp[i][0]=0;
 
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= sum; j++)
        {
            if(j >= coin[i-1])
            {
                x = dp[i-1][j];
                y = 1 + dp[i][j-coin[i-1]];
                dp[i][j] = min(x,y);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
 
    }
    return dp[n][sum];
}
 
int main()
{
    int i;
    int n = 3;
    int sum = 6;

    int coin[n] = {1, 3, 4};
 
    cout << "O menor número de moedas para o troco é: " << changeMaking(coin, n, sum) << endl;

    return 0;
}