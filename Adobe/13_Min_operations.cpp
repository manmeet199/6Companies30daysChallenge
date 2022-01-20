// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
   map<pair<int,int>,int> mp;
    void helper(vector<int> adj[],vector<int> &vis ,int i){
        vis[i] = 1;
        for(int j :  adj[i]){
            if(vis[j] == 0 and mp.find({i,j}) == mp.end()){
                helper(adj,vis,j);
            }
            else{
                continue;
            }
        }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<int> vis(V , 0);
        helper(adj,vis,c);
        vector<int> vis1(V , 0);
        mp[{c,d}] = 1;mp[{d,c}] = 1;
        helper(adj,vis1,c);
        for(int i = 0;i < V ; i ++){
            if(vis[i] != vis1[i])
                return 1;
        }
        return 0;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends