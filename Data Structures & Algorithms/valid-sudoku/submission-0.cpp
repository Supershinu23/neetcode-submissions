class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            vector<bool> vec(9, false);
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                if(vec[board[i][j]-'1'])return false;
                vec[board[i][j]-'1']=true;
            }
        }
        cout<<" after row check";
        for(int i=0;i<9;i++){
            vector<bool> vec(9, false);
            for(int j=0;j<9;j++){
                if(board[j][i]=='.')continue;
                if(vec[board[j][i]-'1'])return false;
                vec[board[j][i]-'1']=true;
            }
        }
        cout<<" after col check";

        for(int i=0;i<9;i++){
            vector<bool> vec(9,false);
            for(int j=0;j<9;j++){
                int row = j/3 + 3*(i/3);
                int col = j%3 + 3*(i%3);
                if(board[row][col]=='.')continue;
                if(vec[board[row][col] - '1'])return false;
                vec[board[row][col] - '1'] = true ;
            }
        }
        return true;
    }
};
