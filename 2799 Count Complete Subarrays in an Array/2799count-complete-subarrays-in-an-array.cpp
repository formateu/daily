class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        std::array<int, 2001> freq{0};
        int unique = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (freq[nums[i]] == 0) {
                ++unique;
            }
            ++freq[nums[i]];
        }

        if (unique == nums.size()) {
            return 1;
        }

        int uniqueWindow = 0;
        freq.fill(0);

        for (int i = 0; i < unique; ++i) {
            if (freq[nums[i]] == 0) {
                ++uniqueWindow;
            }
            ++freq[nums[i]];
        }

        int result = 0;

        for (int i = 0, j = unique; i < nums.size();) {
            if (uniqueWindow < unique && j == nums.size()) {
                break;
            } else if (uniqueWindow == unique) {
                result += 1 + nums.size() - j;
                if (freq[nums[i]] == 1) {
                    --uniqueWindow;
                }

                --freq[nums[i]];
                ++i;
            } else {
                while (uniqueWindow < unique && j < nums.size()) {
                    if (freq[nums[j]] == 0) {
                        ++uniqueWindow;
                    }
                    ++freq[nums[j]];
                    ++j;
                }
            }
        }

        return result;
    }
};