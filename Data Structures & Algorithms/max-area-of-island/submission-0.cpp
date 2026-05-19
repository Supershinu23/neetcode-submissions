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
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    ans = max(ans, dfs(i,j,vis, grid));
                }
            }
        }
        return ans;
    }
};
