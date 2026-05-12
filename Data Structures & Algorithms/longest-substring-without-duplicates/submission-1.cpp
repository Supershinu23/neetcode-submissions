class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0 ;
        int r = 0 ;
        unordered_map<char, int> m;
        int ans = 0 ;
        while(r<n){
            while(l< n && m.find(s[r]) != m.end()){
                m.erase(s[l]);
                l++;
            }
            ans = max(ans, r-l+1);
            m[s[r]] = r ;
            r++;
        }
        return ans;
    }
};
