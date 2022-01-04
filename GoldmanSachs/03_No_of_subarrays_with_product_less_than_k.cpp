#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
      int ans=0;
      long long int p=1;
      int start=0,end=0;
      while(end<n)
      {
          p*=a[end];
          while(start<n && p>=k)
          {
              p/=a[start];
              start++;
          }
          if(p<k)
          ans+=end-start+1;
          end++;
      }
      return ans;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
