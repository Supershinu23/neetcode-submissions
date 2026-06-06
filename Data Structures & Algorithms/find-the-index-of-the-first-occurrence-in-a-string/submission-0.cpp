class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;

        long long base1 = 31, mod1 = 768258391;
        long long base2 = 37, mod2 = 685683731;

        int n = haystack.size(), m = needle.size();
        if (m > n) return -1;

        long long power1 = 1, power2 = 1;
        for (int i = 0; i < m; i++) {
            power1 = (power1 * base1) % mod1;
            power2 = (power2 * base2) % mod2;
        }

        long long needleHash1 = 0, needleHash2 = 0;
        long long haystackHash1 = 0, haystackHash2 = 0;

        for (int i = 0; i < m; i++) {
            needleHash1 = (needleHash1 * base1 + needle[i]) % mod1;
            needleHash2 = (needleHash2 * base2 + needle[i]) % mod2;
            haystackHash1 = (haystackHash1 * base1 + haystack[i]) % mod1;
            haystackHash2 = (haystackHash2 * base2 + haystack[i]) % mod2;
        }

        for (int i = 0; i <= n - m; i++) {
            if (haystackHash1 == needleHash1 && haystackHash2 == needleHash2) {
                return i;
            }

            if (i + m < n) {
                haystackHash1 = (haystackHash1 * base1 - haystack[i] * power1 + haystack[i + m]) % mod1;
                haystackHash2 = (haystackHash2 * base2 - haystack[i] * power2 + haystack[i + m]) % mod2;

                if (haystackHash1 < 0) haystackHash1 += mod1;
                if (haystackHash2 < 0) haystackHash2 += mod2;
            }
        }

        return -1;
    }
};