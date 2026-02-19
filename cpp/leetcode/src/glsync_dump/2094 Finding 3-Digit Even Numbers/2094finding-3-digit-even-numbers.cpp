class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        std::array<int, 900> nums;
        std::array<int, 10> globalFreq{}, localFreq;
        std::iota(nums.begin(), nums.end(), 100);
        std::vector<int> result;

        for (const auto &d: digits) {
            ++globalFreq[d];
        }

        for (const auto &num: nums) {
            const int t = num % 10;

            if (t % 2) {
                continue;
            }

            localFreq.fill(0);
            const int f = num / 100;
            const int s = (num % 100) / 10;
            ++localFreq[f];
            ++localFreq[s];
            ++localFreq[t];

            bool canCreate = true;
            for (int i = 0; i < 10; ++i) {
                if (localFreq[i] > globalFreq[i]) {
                    canCreate = false;
                    break;
                }
            }

            if (canCreate) {
                result.emplace_back(num);
            }
            
        }

        return result;
    }
};