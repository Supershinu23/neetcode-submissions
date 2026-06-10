class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        for (auto& [key, cnt] : count) {
            if (cnt % 2 == 1) {
                return false;
            }
        }

        return true;
    }
};