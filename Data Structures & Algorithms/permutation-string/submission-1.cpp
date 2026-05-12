class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        sort(s1.begin(), s1.end());
        set<char> s;
        for(int i=0;i<n1;i++){
            s.insert(s1[i]);
        }
        for(int i=0;i<=n2-n1;i++){
            if(s.find(s2[i])!=s.end()){
                string temp = s2.substr(i, n1);
                sort(temp.begin(), temp.end());
                if(s1==temp)return true;
            }
        }
        return false;
    }
};
