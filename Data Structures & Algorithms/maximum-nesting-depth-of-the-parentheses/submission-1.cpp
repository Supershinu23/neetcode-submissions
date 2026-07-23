class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        stack<char> stack;

        for (char c : s) {
            if (c == '(') {
                stack.push(c);
                res = max(res, (int)stack.size());
            } else if (c == ')') {
                stack.pop();
            }
        }

        return res;
    }
};