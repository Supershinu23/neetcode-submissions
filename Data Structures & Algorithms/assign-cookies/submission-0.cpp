class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        int res = 0;

        for (int i : g) {
            int minIdx = -1;
            for (int j = 0; j < s.size(); j++) {
                if (s[j] < i) continue;

                if (minIdx == -1 || s[minIdx] > s[j]) {
                    minIdx = j;
                }
            }

            if (minIdx != -1) {
                s[minIdx] = -1;
                res++;
            }
        }

        return res;
    }
};