class Solution {
public:
    
    bool func(int i, int j, string word, int p, vector<vector<char>> &board, set<pair<int, int>> st){
        if(p==word.size())return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()){
            return false;
        }
        if(board[i][j]!=word[p])return false;
        if(st.find({i, j})!=st.end())return false;
        st.insert({i,j});
        bool res =  func(i-1, j, word, p+1, board, st) ||
                    func(i+1, j, word, p+1, board, st) ||
                    func(i, j+1, word, p+1, board, st) ||
                    func(i, j-1, word, p+1, board, st);
        st.erase({i,j});
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        set<pair<int, int>> st;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0] && func(i,j,word, 0, board, st))return true;
            }
        }
        return false;
    }
};
