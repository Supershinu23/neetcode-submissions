class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(int i=0;i<s.size();i++){
            if((s[i]>='A' && s[i]<='Z') ||(s[i]>='a' && s[i]<='z') || 
            (s[i]>='0' && s[i]<='9')){
                temp += tolower(s[i]);
            }
        }

        int n = temp.size();
        for(int i=0;i<n/2;i++){
            if(temp[i]!= temp[n-i-1])return false;
        }
        return true;
    }
};
