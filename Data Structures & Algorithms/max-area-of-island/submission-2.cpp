class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> grid){
        if(i<0 || j< 0 || i>=grid.size() || j>=grid[0].size()
        || vis[i][j]==1 || grid[i][j]==0){
            return 0; 
        }
        vis[i][j] = 1;
        int ans  = 1;
        int arr1[] = {-1, 0, 0, 1};
        int arr2[] = {0, 1, -1, 0};

        for(int k=0;k<4;k++){
            ans+=dfs(i+arr1[k], j+arr2[k], vis, grid);
        }
        return ans;
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int> (n, 0));
        int ans = 0 ;
        /*dfs--------->
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    ans = max(ans, dfs(i,j,vis, grid));
                }
            }
        }
        */

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && vis[i][j]==0){
                    queue<pair<int, int>> q;
                    q.push({i,j});
                    vis[i][j] = 1;
                    int temp = 0 ;
                    while(!q.empty()){
                        pair<int, int> p = q.front();
                        q.pop();
                        
                        temp++;
                        int arr1[] = {-1, 0, 0, 1};
                        int arr2[] = {0, 1, -1, 0};
                        for(int k=0;k<4;k++){
                            if(p.first+arr1[k]>=0 && p.first+arr1[k]<m 
                            && p.second+arr2[k]>=0 && p.second+arr2[k]<n
                            && grid[p.first+arr1[k]][p.second+arr2[k]]==1 
                            && vis[p.first+arr1[k]][p.second+arr2[k]]==0){
                                vis[p.first+arr1[k]][p.second+arr2[k]] = 1;
                                q.push({p.first+arr1[k], p.second+arr2[k]});
                            }
                        }
                    }
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};
