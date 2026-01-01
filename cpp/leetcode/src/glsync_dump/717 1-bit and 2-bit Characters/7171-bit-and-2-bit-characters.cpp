class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int start = 0;
        for (int i = 0; i < bits.size();) {
            start = i;
            if (bits[i] == 0) {
                ++i;
            } else {
                i += 2;
            }
        }

        return start == bits.size() -1;
    }
};