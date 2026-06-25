class Solution {
public:
    int longestPalindrome(string s) {
        int mask1 = 0; // [a - z]
        int mask2 = 0; // [A - Z]
        int res = 0;

        for (char c : s) {
            if ('a' <= c && c <= 'z') {
                int bit = 1 << (c - 'a');
                if (mask1 & bit) {
                    res += 2;
                }
                mask1 ^= bit;
            } else {
                int bit = 1 << (c - 'A');
                if (mask2 & bit) {
                    res += 2;
                }
                mask2 ^= bit;
            }
        }

        return (mask1 || mask2) ? res + 1 : res;
    }
};