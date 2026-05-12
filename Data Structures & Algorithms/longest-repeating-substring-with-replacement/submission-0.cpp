class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> m ;
        int l =0 ;
        int n = s.size();
        int r = 0 ;
        int maxLength  = INT_MIN;
        int ans = 0 ;
        while(r<n){
            m[s[r]]++;
            maxLength = max(maxLength,m[s[r]]);
            while(l<n &&(r-l+1)-maxLength>k){
                m[s[l]]--;
                if(m[s[l]]==0){
                    m.erase(m[s[l]]);
                }
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};
