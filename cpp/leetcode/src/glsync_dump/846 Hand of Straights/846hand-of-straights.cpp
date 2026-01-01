class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize) {
            return false;
        }

        sort(hand.begin(), hand.end()); // nlogn
        int totalMarkedCnt = 0;

        while (totalMarkedCnt < hand.size()) {
            int curr = -1, ind = 0, marked = 0;
            for (int i = 0; i < hand.size(); ++i) {
                if (hand[i] != -1) {
                    curr = hand[i];
                    hand[i] = -1;
                    ind = i;
                    ++totalMarkedCnt;
                    ++marked;
                    break;
                }
            }

            for (int i = ind; i < hand.size(); ++i) {
                if (hand[i] == curr + 1) {
                    curr = hand[i];
                    hand[i] = -1;
                    ++totalMarkedCnt;
                    ++marked;
                }

                if (marked == groupSize) {
                    break;
                }
            }

            if (marked < groupSize) {
                return false;
            }

        }

        return true;
    }
};