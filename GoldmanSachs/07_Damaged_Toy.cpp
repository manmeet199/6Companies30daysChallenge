#include <bits/stdc++.h>
using namespace std;
int lastPosition(int n, int m, int k)
{
	int ans=(m+k-1)%n;
    if(ans==0)
    {
        return n;
    }
    return ans;
}

int main()
{
	int n = 5;
	int m = 8;
	int k = 2;
	cout << lastPosition(n, m, k);
	return 0;
}
