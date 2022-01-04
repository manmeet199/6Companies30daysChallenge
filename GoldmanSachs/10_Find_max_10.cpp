#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    void largest(int arr[],int n,int k)
    {
        vector<int> ans;
        priority_queue<int> pq;
        for(int i=0;i<n;i++)
            pq.push(arr[i]);
        for(int i=0;i<k;i++)
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        for(auto i:ans)
            cout<<i<<" ";
    }
};

