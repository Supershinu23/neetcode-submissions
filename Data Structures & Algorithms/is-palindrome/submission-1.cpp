class Solution {
public:
    bool isPalindrome(string t) {
        string s = "";
        for(int i=0;i<t.length();i++){
            if((t[i]>='a' && t[i]<='z') || (t[i]>='A' && t[i]<='Z') || (t[i]>='0' && t[i]<='9')){
                s+=tolower(t[i]);
            }
        }
        int n  = s.length();
        
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1])return false;
        }
        return true;
    }
};
