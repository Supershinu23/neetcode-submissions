class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mpp;
        int n = s.size();
        int m = t.size();
        for(int i=0;i<m;i++){
            mpp[t[i]]++;
        }
        int cnt = 0 ;
        int l = 0 ;
        int r = 0 ;
        int minLength = INT_MAX;
        int ind = 0 ;
        while(r<n){
            if(mpp[s[r]] > 0)cnt++;
            mpp[s[r]]--;

            while(cnt>=t.size()){
                mpp[s[l]]++;
                if(mpp[s[l]]>0){
                    if(minLength> r-l+1){
                        minLength = r-l+1;
                        ind = l ;
                    }
                    cnt--;
                }
                l++;
            }
            r++;
        }
        if(minLength == INT_MAX) return "";
        return s.substr(ind, minLength);
    }
};
