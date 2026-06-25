class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> freq(26, 0);
        int flag = 0;
        int n = words.size();

        for (const string& w : words) {
            for (char c : w) {
                int i = c - 'a';
                if (freq[i] != 0) {
                    freq[i]++;
                    if (freq[i] % n == 0) {
                        flag++;
                    }
                } else {
                    freq[i]++;
                    if (freq[i] % n != 0) {
                        flag--;
                    }
                }
                freq[i] %= n;
            }
        }

        return flag == 0;
    }
};