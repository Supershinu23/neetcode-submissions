class Solution {
public:
    bool checkValidString(string s) {
        stack<pair<char, int>> st1 ;
        stack<pair<char, int>> st2 ;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')st1.push({s[i], i});
            if(s[i]=='*')st2.push({s[i], i});
            if(s[i]==')'){
                if(!st1.empty()){
                    st1.pop();
                }else if(!st2.empty()){
                    st2.pop();
                }else{
                    return false;
                }
            }
        }

        while(!st1.empty()){
            if(st2.empty())return false;
            pair<char, int> p1 = st1.top();
            pair<char, int> p2 = st2.top();
            if(p2.second < p1.second)return false;
            st1.pop();
            st2.pop();
        }
        return true;
    }
};
