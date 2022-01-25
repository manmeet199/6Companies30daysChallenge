#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isFeasible(vector<int>arr,int k,int mid)
    {
        int req=1;
        int sum=0;
        for(int i=0;i<arr.size();i++)
        {
            if(sum+arr[i] > mid)
            {
                req++;
                sum=arr[i];
            }
            else
            sum+=arr[i];
        }
        
        return req<=k;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        int n=weights.size();
        
        int low = *max_element(weights.begin(),weights.end());
        
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=weights[i];
        
        int high=sum;
        int ans=INT_MAX;
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            if(isFeasible(weights,days,mid))
            {
                ans=min(ans,mid);
                high=mid-1;
            }
            else
                low=mid+1;
        }
        
        return ans;
    }
};
