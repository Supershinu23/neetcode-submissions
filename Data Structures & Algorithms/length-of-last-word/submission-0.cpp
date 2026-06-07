class Solution {
public:
    int lengthOfLastWord(string s) {
        s.erase(s.find_last_not_of(' ') + 1);
        return s.substr(s.find_last_of(' ') + 1).length();
    }
};