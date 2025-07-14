class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        std::sort(players.begin(), players.end());
        std::sort(trainers.begin(), trainers.end());

        int i = 0, j = 0, result = 0;
        while (i < players.size() && j < trainers.size()) {
            if (players[i] <= trainers[j]) {
                ++result;
                ++i;
                ++j;
            } else {
                ++j;
            }
        }

        return result;
    }
};