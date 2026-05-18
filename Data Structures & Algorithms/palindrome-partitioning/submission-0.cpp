class Solution {
public:
    bool ispalindrome(string s, int l, int r){
        while(r>l){
            if(s[l]!=s[r])return false;
            l++;
            r--;
        }
        return true;
    }

    void func(string s, int i,
              vector<string>& vec,
              vector<vector<string>>& ans){

        if(i == s.size()){
            ans.push_back(vec);
            return;
        }

        for(int j=i;j<s.size();j++){
            if(ispalindrome(s,i,j)){
                vec.push_back(s.substr(i, j-i+1));
                func(s, j+1, vec, ans);
                vec.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<string> vec;
        vector<vector<string>> ans;

        func(s, 0, vec, ans);

        return ans;
    }
};