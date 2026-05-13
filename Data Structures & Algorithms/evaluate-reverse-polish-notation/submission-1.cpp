class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s ;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i] == "+" || tokens[i] == "*" || tokens[i] == "-" || tokens[i] == "/"){
                int n2 = s.top();s.pop();
                int n1 = s.top();s.pop();
                int res;
                if(tokens[i]=="+"){
                    res = n1+n2;
                }else if(tokens[i]=="-"){
                    res = n1-n2;
                }else if(tokens[i] == "*"){
                    res = n1 * n2;
                }else{
                    res = n1/n2;
                }
                s.push(res);
            }else{
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};
