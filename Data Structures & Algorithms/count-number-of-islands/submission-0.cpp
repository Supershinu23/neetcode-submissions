class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>&vis, vector<vector<char>> &grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || vis[i][j]==1 ||
        grid[i][j]=='0'){
            return;
        }
        vis[i][j]=1;
        int arr1[] = {-1,0,0,1};
        int arr2[] = {0, -1, 1, 0};

        for(int k=0;k<4;k++){
            dfs(i+arr1[k], j+arr2[k], vis, grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0 ;
        for(int i=0;i<grid.size();i++){
            for(int j =0; j<grid[0].size();j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    ans++;
                    dfs(i,j, vis, grid);
                }
            }
        }
        return ans;
    }
};
