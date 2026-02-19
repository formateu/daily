class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        std::sort(seats.begin(), seats.end());
        std::sort(students.begin(), students.end());

        int numOfMoves = 0;
        for (int i = 0; i < seats.size(); ++i) {
            numOfMoves += abs(seats[i] - students[i]);
        }

        return numOfMoves;
    }
};