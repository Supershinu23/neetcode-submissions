class Solution {
public:
    int maxScore(string s) {
        // res = Max of all (leftZeros + rightOnes)
        // res = Max of all (leftZeros + (totalOnes - leftOnes))
        // res = totalOnes (constant) + Max of all (leftZeros - leftOnes)

        int zeros = 0, ones = 0, res = INT_MIN;

        if (s[0] == '0') {
            zeros++;
        } else {
            ones++;
        }

        for (int i = 1; i < s.size(); i++) {
            res = max(res, zeros - ones);
            if (s[i] == '0') {
                zeros++;
            } else {
                ones++;
            }
        }

        return res + ones;
    }
};