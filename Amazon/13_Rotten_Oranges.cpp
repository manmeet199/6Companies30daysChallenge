class Solution {
public:
    
   
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty())
        return 0;
      int m=grid.size();
        int n=grid[0].size();
        int days=0, tot=0, cnt=0;
        queue<pair<int,int>> rotten; 
       for(int i=0; i<m; i++)
           for(int j=0; j<n; j++)
           {
               if(grid[i][j]!=0)
                   tot++;
               if(grid[i][j]==2)
                   rotten.push({i,j});
              
               
           }
        int dx[]={0,-1,0,1};
            int dy[]={1,0,-1,0};
        while(!rotten.empty())
        {
            int k=rotten.size();
            cnt+=k;
            while(k--)
            {
                int x=rotten.front().first;
                int y=rotten.front().second;
                rotten.pop();
                for(int i=0; i<4; i++)
                {
                    int nextx=x+dx[i];
                    int nexty=y+dy[i];
                    if(nextx<0 || nexty<0 || nextx>=m || nexty>=n || grid[nextx][nexty]!=1)
                        continue;
                    grid[nextx][nexty]=2;
                    rotten.push({nextx,nexty});
                }
            }
            if(!rotten.empty())
                days++;
        }
        return (tot==cnt)?days:-1;
    }
};