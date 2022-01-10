
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        
    
        map<int,int> m;
        for(int i=0; i<nums.size(); i++)
        {
            m[nums[i]%k]++;
        }
        if(m[0]%2==1)
        return false;
        for(int i=1; i<k; i++)
        {
            if(m[i]!=m[k-i])
            {
                return false;
            }
        }
        return true;
        
    }
};


int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  