class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;

        unordered_map<char, int> m ;
        for(int i=0;i<s.size();i++){
            m[s[i]] = i ;
        }

        int l =0 ;
        while(l<s.size()){
            int r = m[s[l]];
            int i = l ;
            while(i<r){
                r = max(m[s[i]], r);
                i++;
            }
            ans.push_back(r-l+1);
            l = r+1;
        }
        return ans;
    }
};
