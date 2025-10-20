class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int result = 0;
        for (const auto &o: operations) {
            if (o == "++X" || o == "X++") {
                ++result;
            } else if (o == "--X" || o == "X--") {
                --result;
            }
        }

        return result;
    }
};