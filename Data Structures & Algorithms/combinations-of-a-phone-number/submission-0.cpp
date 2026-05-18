class Solution {
public:
    string number(char c){
        if(c =='2')return "abc";
        if(c =='3')return "def";
        if(c =='4')return "ghi";
        if(c =='5')return "jkl";
        if(c =='6')return "mno";
        if(c =='7')return "pqrs";
        if(c =='8')return "tuv";
        return "wxyz";
    }
    void func(string digits, int i, string temp, vector<string> &ans){
        if(i==digits.size()){
            ans.push_back(temp);
            return;
        }
        string s = number(digits[i]);
        for(int j=0;j<s.size();j++){
            temp+=s[j];
            func(digits, i+1, temp, ans);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0)return ans;
        func(digits, 0, "", ans);
        return ans;
    }
};
