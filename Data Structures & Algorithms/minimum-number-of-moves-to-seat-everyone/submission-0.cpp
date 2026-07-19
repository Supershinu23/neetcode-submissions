class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int max_index = 0;
        for (int s : seats) max_index = max(max_index, s);
        for (int s : students) max_index = max(max_index, s);
        max_index++;

        vector<int> count_seats(max_index, 0);
        vector<int> count_students(max_index, 0);

        for (int seat : seats) count_seats[seat]++;
        for (int student : students) count_students[student]++;

        int i = 0, j = 0, res = 0, remain = seats.size();
        while (remain > 0) {
            if (count_seats[i] == 0) {
                i++;
                continue;
            }
            if (count_students[j] == 0) {
                j++;
                continue;
            }
            res += abs(i - j);
            count_seats[i]--;
            count_students[j]--;
            remain--;
        }
        return res;
    }
};