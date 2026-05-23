class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ind = 0 ;
        int maxLength = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            int l = i, r = i ;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>maxLength){
                    ind = l ;
                    maxLength = r-l+1;
                }
                l--;
                r++;
                ans++;
            }

            // for even palindrome
            l = i, r = i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1 > maxLength){
                    ind = l ;
                    maxLength = r-l+1;
                }
                l--;
                r++;
                ans++;
            }
        }
        return ans;
    }
};
