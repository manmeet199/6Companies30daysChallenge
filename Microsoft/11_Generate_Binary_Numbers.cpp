// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
	// Your code here
queue<string> res;
	res.push("1");
	
	vector<string> ans;
	for(int i = 0; i < N; ++i) {
	    
	    string str= res.front();
        res.pop();
	    res.push(str + "0");
	    res.push(str + "1");
	    ans.push_back(str);
	}
	return ans;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends