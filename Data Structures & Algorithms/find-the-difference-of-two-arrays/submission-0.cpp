class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        return {helper(nums1, nums2), helper(nums2, nums1)};
    }

private:
    vector<int> helper(vector<int>& A, vector<int>& B) {
        vector<int> res;
        int n = A.size(), m = B.size(), j = 0, prev = INT_MIN;

        for (int num : A) {
            if (num == prev) continue;
            while (j < m && B[j] < num) j++;
            if (j == m || B[j] != num) res.push_back(num);
            prev = num;
        }

        return res;
    }
};