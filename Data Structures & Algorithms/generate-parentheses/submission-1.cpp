class Solution {
public:
    vector<string> ans ;
    void func(int count, string &temp, int k, int used){
        if(temp.size()==2*k){
            ans.push_back(temp);
            return ;
        }
        if(count<k && used != 0){
            count++;
            temp+='(';
            func(count, temp, k, used-1);
            temp.pop_back();
            count--;
        }

        if(count>=1){
            count--;
            temp+=')';
            func(count, temp, k, used);
            temp.pop_back();
            count++;
        }
    }
    vector<string> generateParenthesis(int n) {
        string temp ="";
        func(0, temp, n, n);
        return ans;

    }
};
