class Solution {
public:
    bool func(vector<vector<int>> &heights, int i, int j, vector<vector<int>> &vis){
        if(i>=heights.size()-1 || j>=heights[0].size()-1 ||
         vis[i][j]==2){
            vis[i][j]=2;
         return true;
         }
        if(vis[i][j]==1)return false;
        vis[i][j] = 1;
        bool flag = false;
        int arr1[] = {-1, 0, 0, 1};
        int arr2[] = {0, 1, -1, 0};
        for(int k=0;k<4;k++){
            if(i+arr1[k]>=0 && i+arr1[k]<heights.size()
            && j+arr2[k]>=0 && j+arr2[k]<heights[0].size() 
            && heights[i][j]>=heights[i+arr1[k]][j+arr2[k]]){
                flag = flag || func(heights, i+arr1[k], j+arr2[k], vis);
            }
        }
        if(flag)vis[i][j] = 2;
       

        return flag;
    }

    bool func1(vector<vector<int>> &heights, int i, int j, vector<vector<int>> &vis){
        if(i<=0 || j<=0 ||
         vis[i][j]==2){
            vis[i][j]=2;
         return true;
         }
        if(vis[i][j]==1)return false;
        vis[i][j] = 1;
        bool flag = false;
        int arr1[] = {-1, 0, 0, 1};
        int arr2[] = {0, 1, -1, 0};
        for(int k=0;k<4;k++){
            if(i+arr1[k]>=0 && i+arr1[k]<heights.size()
            && j+arr2[k]>=0 && j+arr2[k]<heights[0].size() 
            && heights[i][j]>=heights[i+arr1[k]][j+arr2[k]]){
                flag = flag || func1(heights, i+arr1[k], j+arr2[k], vis);
            }
        }
        if(flag)vis[i][j] = 2;

        return flag;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights[0].size();
        int m = heights.size();
        vector<vector<int>> ans ;
        vector<vector<int>> pacific(m, vector<int>(n,0));
        vector<vector<int>> atlantic(m, vector<int>(n,0));

        // for(int i=0;i<m;i++){
        //     pacific[i][0] = 2;
        //     atlantic[i][n-1] = 2;
        //     if(atlantic[i][0]==0){
        //         func(heights, i, 0, atlantic);
        //     }
        //     if(pacific[i][n-1]==0){
        //         func1(heights, i, n-1, pacific);
        //     }
        // }
        // for(int j=0;j<n;j++){
        //     pacific[0][j] = 2;
        //     atlantic[m-1][j] = 2;
        //     if(atlantic[0][j]==0){
        //         func(heights, 0, j, atlantic);
        //     }
        //     if(pacific[m-1][j]==0){
        //         func1(heights, m-1, j, pacific);
        //     }
        // }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(atlantic[i][j]==0){
                    func(heights, i, j, atlantic);
                }
                if(pacific[i][j]==0){
                func1(heights, i, j, pacific);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j = 0;j<n; j++){
                cout<<"for i: "<<i<<" and j: "<<j<<" pacific is: "<<pacific[i][j]<<" and atlantic: "<<atlantic[i][j]<<"\n";
                if(pacific[i][j]==2 && atlantic[i][j]==2){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
