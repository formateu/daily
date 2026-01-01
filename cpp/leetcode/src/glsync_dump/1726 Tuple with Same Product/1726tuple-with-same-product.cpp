class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        std::unordered_map<int, int> products(nums.size() * (nums.size()-1)/2);

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                const int prod = nums[i] * nums[j];
                if (products.contains(prod)) {
                    ++products[prod];
                } else {
                    products.emplace(prod, 1);
                }
            }
        }

        int result = 0;
        for (const auto &[k, v] : products) {
            if (v > 1) {
                result += v *(v-1);
            }
        }

        return result*4;
    }
};