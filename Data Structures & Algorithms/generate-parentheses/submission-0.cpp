class Solution {
public:
    vector<string> ans ;
    void func(int n, string &temp, stack<char> &st, int k){
        if(temp.size()==2*k){
            ans.push_back(temp);
            return ;
        }
        if(st.empty() || n!=0){
            st.push('(');
            temp+='(';
            func(n-1, temp, st, k);
            temp.pop_back();
            st.pop();
        }

        if(!st.empty()){
            st.pop();
            temp+=')';
            func(n, temp, st, k);
            temp.pop_back();
            st.push('(');
        }
    }
    vector<string> generateParenthesis(int n) {
        string temp ="";
        stack<char> st;
        func(n, temp, st, n);
        return ans;

    }
};
