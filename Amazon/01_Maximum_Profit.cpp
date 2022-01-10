#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int maxProfit(int k, int n, int a[]) {
        
         int dp[k+1][n];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=k;i++)
        {
            int maxi = INT_MIN;
            for(int j=1;j<n;j++)
            {
                maxi = max(maxi,dp[i-1][j-1]-a[j-1]);
                dp[i][j] = max(dp[i][j-1],maxi+a[j]);
            }
        }
        return dp[k][n-1];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
} 
