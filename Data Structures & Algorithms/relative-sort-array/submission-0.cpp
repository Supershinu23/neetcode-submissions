class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> arr2Set(arr2.begin(), arr2.end());
        unordered_map<int, int> count;
        vector<int> end;

        for (int num : arr1) {
            if (!arr2Set.count(num)) end.push_back(num);
            count[num]++;
        }

        sort(end.begin(), end.end());
        vector<int> res;

        for (int num : arr2) {
            for (int i = 0; i < count[num]; i++) {
                res.push_back(num);
            }
        }

        res.insert(res.end(), end.begin(), end.end());
        return res;
    }
};