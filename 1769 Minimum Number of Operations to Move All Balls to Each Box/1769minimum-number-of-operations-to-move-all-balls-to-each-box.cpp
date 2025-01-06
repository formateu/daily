class Solution {
public:
    std::vector<int> minOperations(std::string boxes) {
        std::vector<int> result(boxes.size(), 0);
        int movesToLeft = 0, ballsLeft = boxes[0] == '1';
        for (std::size_t i = 1; i < boxes.size(); ++i) {
            movesToLeft += ballsLeft;
            result[i] = movesToLeft;
            if (boxes[i] == '1') {
                ++ballsLeft;
            }
        }

        int movesToRight = 0, ballsRight = boxes.back() == '1';
        for (int i = boxes.size() - 2; i >= 0; --i) {
            movesToRight += ballsRight;
            result[static_cast<std::vector<int>::size_type>(i)] += movesToRight;
            if (boxes[static_cast<std::string::size_type>(i)] == '1') {
                ++ballsRight;
            }
        }

        return result;
    }
};