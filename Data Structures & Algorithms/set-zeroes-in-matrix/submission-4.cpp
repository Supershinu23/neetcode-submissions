class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        int m = matrix.size();

        bool isRow = false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    if(i==0)isRow = true;
                    matrix[0][j] = 0 ;
                    if(i!=0)matrix[i][0] = 0 ;
                }
            }
        }
        int temp = matrix[0][0];
        for(int i=1;i<n;i++){
            if(matrix[0][i]==0){
                for(int j=0;j<m;j++){
                    matrix[j][i] = 0 ;
                }
            }
        }
        if(isRow)matrix[0][0] = 0 ;
        else matrix[0][0] = 1;

        for(int i=0;i<m;i++){
            if(matrix[i][0]==0){
                for(int j=0;j<n;j++){
                    matrix[i][j]=0;
                }
            }
        }
        cout<<temp;
        if(temp==0){
            for(int i=0;i<m;i++){
                matrix[i][0] = 0 ;
            }
        }
    }
};
