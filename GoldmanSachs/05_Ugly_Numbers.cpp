// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


class Solution{
public:	
	
	ull getNthUglyNo(int n) {

	    ull int c1=0,c2=0,c3=0;
	    vector<ull int> dp(n+1);
	    dp[0]=1;
	    for(ull int i=1; i<n; i++)
	    {
	        dp[i]=min({2*dp[c1],3*dp[c2],5*dp[c3]});
	        if(2*dp[c1]==dp[i])
	        c1++;
	        if(3*dp[c2]==dp[i])
	        c2++;
	        if(5*dp[c3]==dp[i])
	        c3++;
	        
	        
	    }
	    return dp[n-1];
	}
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
