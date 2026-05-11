class Solution {
public:
    bool isValid(char c){
        if((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9'))return true;
        return false;
    }
    bool isPalindrome(string s) {
        int n = s.size();
        int l =0 ;
        int r = n-1;
        while(l<r){
            if(!isValid(s[l])){
                l++;
                continue;
            }
            if(!isValid(s[r])){
                r--;
                continue;
            }
            if(tolower(s[l])!=tolower(s[r]))return false;
            l++;
            r--;
        }
        return true;
    }
};
