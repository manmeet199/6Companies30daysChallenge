#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    int l=0,r=0;
        int minlen=INT_MAX;
        int sum=0;
        
        while(r<nums.size()){
            sum+=nums[r];
            
            while(l<=r && sum>=target){
                minlen=min(r-l+1,minlen);
                sum-=nums[l++];
            }
            r++;
        }
        
        return minlen==INT_MAX?0:minlen;
    }
        
};