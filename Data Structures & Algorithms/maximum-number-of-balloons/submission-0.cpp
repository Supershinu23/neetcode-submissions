class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> countText;
        for (char c : text) {
            countText[c]++;
        }

        unordered_map<char, int> balloon = {{'b', 1}, {'a', 1},
                                            {'l', 2}, {'o', 2}, {'n', 1}};

        int res = text.length();
        for (auto& entry : balloon) {
            res = min(res, countText[entry.first] / entry.second);
        }
        return res;
    }
};