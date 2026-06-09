class Solution {
public:
    int findLucky(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int streak = 0;

        for (int i = arr.size() - 1; i >= 0; i--) {
            streak++;
            if (i == 0 || arr[i] != arr[i - 1]) {
                if (arr[i] == streak) {
                    return arr[i];
                }
                streak = 0;
            }
        }
        return -1;
    }
};