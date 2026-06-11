class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool allowedArr[26] = {};
        for (char c : allowed) {
            allowedArr[c - 'a'] = true;
        }

        int res = words.size();
        for (const string& w : words) {
            for (char c : w) {
                if (!allowedArr[c - 'a']) {
                    res--;
                    break;
                }
            }
        }

        return res;
    }
};