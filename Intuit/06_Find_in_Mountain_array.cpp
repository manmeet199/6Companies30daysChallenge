 #include <bits/stdc++.h>
using namespace std;
 int peakIndex(MountainArray &arr) {
        int start = 0;
        int end = arr.length() - 1;
        
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(arr.get(mid) > arr.get(mid + 1))
                end = mid;
            else
                start = mid + 1;
        }
        
        return end;
        
    }
    
    int orderAgnosticBS(MountainArray &arr, int target, int start, int end) {
        
        bool rev = arr.get(start) > arr.get(end);
        
        while(start <= end) {
            int mid = start + (end - start) / 2;
            
            int ele = arr.get(mid);
            if (ele == target)
                return mid;
            else if (ele < target) {
                if(rev)
                    end = mid - 1;
                else
                    start = mid + 1;
            } else if (ele > target) {
                if(rev)
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        
        return -1;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // first find the peak
        int peak = peakIndex(mountainArr);
        
        // then search b/w first index and peak
        int ans = orderAgnosticBS(mountainArr, target, 0, peak);
    
        if(ans == -1)
            // if element not found, search in second half (from peak + 1 to last index)
            ans = orderAgnosticBS(mountainArr, target, peak + 1, mountainArr.length() - 1);
        
        return ans;
        
    }