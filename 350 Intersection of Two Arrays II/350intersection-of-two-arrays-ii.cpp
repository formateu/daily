class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nums1S, nums2S;
        nums1S.reserve(nums1.size());
        nums2S.reserve(nums2.size());

        for (const auto num: nums1) {
            if (nums1S.contains(num)) {
                ++nums1S[num];
            } else {
                nums1S.emplace(num, 1);
            }
        }

        for (const auto num: nums2) {
            if (nums2S.contains(num)) {
                ++nums2S[num];
            } else {
                nums2S.emplace(num, 1);
            }
        }


        vector<int> result;
        result.reserve(min(nums1.size(), nums2.size()));

        for (const auto& [numKey, occurences]: nums1S) {
            if (nums2S.contains(numKey)) {
                for (int i = 0; i < min(occurences, nums2S[numKey]); ++i) {
                    result.emplace_back(numKey);
                }
            }
        }


        return result;
    }
};