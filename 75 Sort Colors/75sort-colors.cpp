class Solution {
public:
    void sortColors(vector<int>& nums) {
        std::array<int, 3> colorCount{};
        for (const auto &num : nums) {
            ++colorCount[num];
        }

        for (int i = 0, ind = 0; i < colorCount.size(); ++i) {
            for (int j = 0; j < colorCount[i]; ++j) {
                nums[ind++] = i;
            }
        }
    }
};