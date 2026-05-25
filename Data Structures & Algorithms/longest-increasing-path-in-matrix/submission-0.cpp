class Solution {
public:
    int func(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(i<0 || i>=matrix.size() || j<0 || j>=matrix[0].size()){
            return INT_MIN;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int maxi = INT_MIN ;
        if(i-1>=0 && matrix[i-1][j]>matrix[i][j]){
            maxi = max(maxi, func(i-1, j, matrix, dp));
        }
        if(i+1<matrix.size() && matrix[i+1][j]>matrix[i][j]){
            maxi = max(maxi, func(i+1, j, matrix, dp));
        }
        if(j-1>=0 && matrix[i][j-1]> matrix[i][j]){
            maxi = max(maxi, func(i, j-1, matrix, dp));
        }
        if(j+1<matrix[0].size() && matrix[i][j+1]>matrix[i][j]){
            maxi = max(maxi, func(i, j+1, matrix, dp));
        }
        return dp[i][j] = 1+ max(maxi, 0);
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        int m = matrix.size();
        int maxi = 0 ;
        vector<vector<int>> dp(m, vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]==-1){
                    maxi = max(maxi, func(i, j, matrix, dp));
                }
            }
        }
        return maxi;
    }
};
