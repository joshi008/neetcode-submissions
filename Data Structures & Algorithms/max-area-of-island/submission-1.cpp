class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int i,j,count=0,maxCount=0;

        for(i=0;i<grid.size();i++) {
            for(j=0;j<grid[0].size();j++) {
                if(grid[i][j]==1) {
                    // cout<<i<<" "<<j<<endl;
                    count = 0;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j] = 2;

                    while(!q.empty()) {
                        int x,y;
                        x = q.front().first;
                        y = q.front().second;
                        // cout<<"q: "<<x<<" "<<y<<endl;
                        q.pop();
                        count++;

                        if(x-1>=0 && grid[x-1][y]==1) {
                            q.push({x-1,y});
                            grid[x-1][y] = 2;
                        }
                        if(y-1>=0 && grid[x][y-1]==1) {
                            q.push({x,y-1});
                            grid[x][y-1]= 2;
                        }
                        if(x+1<grid.size() && grid[x+1][y]==1) {
                            q.push({x+1,y});
                            grid[x+1][y] = 2;
                        }
                        if(y+1<grid[0].size() && grid[x][y+1]==1) {
                            q.push({x,y+1});
                            grid[x][y+1] = 2;
                        }
                    }

                    maxCount = max(count, maxCount);
                }
            }
        }

        return maxCount;
    }
};
