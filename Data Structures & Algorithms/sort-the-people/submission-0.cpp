class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> arr;
        for (int i = 0; i < names.size(); i++) {
            arr.emplace_back(heights[i], names[i]);
        }

        sort(arr.begin(), arr.end(), [](auto& a, auto& b) {
            return a.first > b.first;
        });

        vector<string> res;
        for (auto& [_, name] : arr) {
            res.push_back(name);
        }

        return res;
    }
};