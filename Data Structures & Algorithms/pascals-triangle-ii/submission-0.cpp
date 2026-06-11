class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res = {1};
        for (int i = 0; i < rowIndex; i++) {
            vector<int> nextRow(res.size() + 1, 0);
            for (int j = 0; j < res.size(); j++) {
                nextRow[j] += res[j];
                nextRow[j + 1] += res[j];
            }
            res = nextRow;
        }
        return res;
    }
};