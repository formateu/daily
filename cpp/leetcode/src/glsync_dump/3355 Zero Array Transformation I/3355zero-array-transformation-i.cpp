class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        std::vector<int> diff(nums.size() + 1, 0);
        for (const auto &q: queries) {
            const auto q1 = q.front();
            const auto q2 = q.back();
            ++diff[q1];
            --diff[q2+1];
        }

        int d = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (diff[i]) {
                d += diff[i];
            }

            if (d < nums[i]) {
                return false;
            }
        }

        return true;
    }
};