class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> firstIdx, lastIdx;
        int res = -1;

        for (int i = 0; i < s.size(); i++) {
            if (firstIdx.find(s[i]) == firstIdx.end()) {
                firstIdx[s[i]] = i;
            } else {
                lastIdx[s[i]] = i;
            }
        }

        for (auto& [c, idx] : lastIdx) {
            res = max(res, lastIdx[c] - firstIdx[c] - 1);
        }

        return res;
    }
};