class Solution {
public:
    int minMaxDifference(int num) {
        const auto numStr = std::to_string(num);
        const std::string bigStr = swapOne(numStr, '9');
        const std::string smStr = swapOne(numStr, '0');

        return std::stoi(bigStr) - std::stoi(smStr);
    }

    std::string swapOne(const std::string &str, char toSwap) {
        std::string result(str);
        char swapped{'\0'};
        for (int i = 0; i < result.size(); ++i) {
            if (!swapped) {
                if (result[i] != toSwap) {
                    swapped = result[i];
                    result[i] = toSwap;
                }
            } else {
                if (result[i] == swapped) {
                    result[i] = toSwap;
                }
            }
        }

        return result;
    }
};