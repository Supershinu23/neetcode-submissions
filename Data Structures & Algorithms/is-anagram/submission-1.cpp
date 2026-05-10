class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())return false;
        // unordered_map<char, int> m1, m2;
        // for(int i=0; i< s.size(); i++){
        //     m1[s[i]]++;
        // }

        // for(int j=0;j<t.size();j++){
        //     m2[t[j]]++;
        // }
        // for(auto it: m1){
        //     if(m2[it.first] != it.second)return false;
        // }

        vector<int> count(26, 0);
        for(int i=0;i<s.length();i++){
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }

        for(int i=0;i<26;i++){
            if(count[i]!=0)return false;
        }
        return true;
    }
};
