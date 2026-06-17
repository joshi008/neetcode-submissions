class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int i,j,count=0;

        for(i=0;i<grid.size();i++) {
            for(j=0;j<grid[0].size();j++) {
                if(grid[i][j]=='1') {
                    // cout<<i<<" "<<j<<endl;
                    count++;
                    queue<pair<int,int>> q;
                    q.push({i,j});

                    while(!q.empty()) {
                        int x,y;
                        x = q.front().first;
                        y = q.front().second;
                        // cout<<"q: "<<x<<" "<<y<<endl;
                        q.pop();
                        grid[x][y] = '2';

                        if(x-1>=0 && grid[x-1][y]=='1') {
                            q.push({x-1,y});
                        }
                        if(y-1>=0 && grid[x][y-1]=='1') {
                            q.push({x,y-1});
                        }
                        if(x+1<grid.size() && grid[x+1][y]=='1') {
                            q.push({x+1,y});
                        }
                        if(y+1<grid[0].size() && grid[x][y+1]=='1') {
                            q.push({x,y+1});
                        }
                    }
                }
            }
        }

        return count;
    }
};
