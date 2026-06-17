class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> counts(grid.size(), vector<int> (grid[0].size(), 0));
        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));

        queue<pair<int,int>> q;
        int i,j,k,p;

        for(i=0;i<grid.size();i++) {
            for(j=0;j<grid[0].size();j++) {
                if(grid[i][j]==2) {
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();
            
            if(x-1>=0) {
                if(!visited[x-1][y] && grid[x-1][y]==1) {
                    q.push({x-1,y});
                    counts[x-1][y] = counts[x][y] + 1;
                    visited[x-1][y] = true;
                }
            }
            if(y-1>=0) {
                if(!visited[x][y-1] && grid[x][y-1]==1) {
                    q.push({x,y-1});
                    counts[x][y-1] = counts[x][y] + 1;
                    visited[x][y-1] = true;
                }
            }
            if(x+1<grid.size()) {
                if(!visited[x+1][y] && grid[x+1][y]==1) {
                    q.push({x+1,y});
                    counts[x+1][y] = counts[x][y] + 1;
                    visited[x+1][y] = true;
                }
            }
            if(y+1<grid[0].size()) {
                if(!visited[x][y+1] && grid[x][y+1]==1) {
                    q.push({x,y+1});
                    counts[x][y+1] = counts[x][y] + 1;
                    visited[x][y+1] = true;
                }
            }
        }
        int ans=0;
        for(i=0;i<grid.size();i++) {
            for(j=0;j<grid[0].size();j++) {
                if(grid[i][j]==1 && visited[i][j]==false) {
                    return -1;
                } else {
                    ans = max(ans, counts[i][j]);
                }
            }
        }

        return ans;
    }
};
