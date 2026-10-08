class Solution {
public:
    vector<vector<int>>dir={{+1,0},{-1,0},{0,1},{0,-1}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>indeg(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(auto it:dir)
                {
                    int x_new=i+it[0];
                    int y_new=j+it[1];
                    if(x_new>=0 && x_new<n && y_new>=0 && y_new<m && matrix[x_new][y_new]<matrix[i][j])
                    {
                        indeg[i][j]++;
                    }
                }
            }
        }
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(indeg[i][j]==0)
                {
                    q.push({i,j});
                }
            }
        }
        int level=0;
        while(!q.empty())
        {
            int x=q.size();
            level++;
            for(int i=0;i<x;i++)
            {
                auto [a,b]=q.front();
                q.pop();
                for(auto it:dir)
                {
                    int x_new=a+it[0];
                    int y_new=b+it[1];
                    if(x_new>=0 && x_new<n && y_new>=0 && y_new<m && matrix[x_new][y_new]>matrix[a][b])
                    {
                        indeg[x_new][y_new]--;
                        if(indeg[x_new][y_new]==0)
                        {
                            q.push({x_new,y_new});
                        }
                    }

                }
            }
        }
        return level;
    }
};